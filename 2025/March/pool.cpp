#include <future>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <vector>
#include <queue>
#include <functional>
#include <fmt/format.h>
using fmt::print;

struct pool
{
    pool(pool&& that) noexcept = delete;

    pool(size_t num = std::thread::hardware_concurrency())
    {
        m_workers.reserve(num);
        for (size_t i = 0; i < num; i++)
        {
            m_workers.emplace_back([this]
                {
                    while (1)
                    {
                        std::function<void()> task;
                        {
                            std::unique_lock lock(m_mtx);
                            m_cv.wait(lock, [this]
                                { return m_is_stop || !m_tasks.empty(); });
                            if (m_is_stop && m_tasks.empty())
                                return;
                            task = std::move(m_tasks.front());
                            m_tasks.pop();
                        }

                        task();
                    } });
        }
    }

    template <typename Func, typename... Ts>
    void post(Func&& func, Ts&&... ts)
    {
        auto task = std::make_shared<std::packaged_task<void()>>(std::bind(std::forward<Func>(func), std::forward<Ts>(ts)...));
        {
            std::scoped_lock lock(m_mtx);
            m_tasks.emplace([task]
                { (*task)(); });
        }
        m_cv.notify_one();
    }

    ~pool() noexcept
    {
        {
            std::scoped_lock lock(m_mtx);
            m_is_stop = true;
        }
        m_cv.notify_all();

        for (auto& worker : m_workers)
        {
            worker.join();
        }
    }

private:
    std::vector<std::jthread> m_workers;
    std::queue<std::function<void()>> m_tasks;

    std::condition_variable m_cv;
    std::mutex m_mtx;

    bool m_is_stop{};
};

int main()
{
    pool p;

    for (size_t i = 0; i < 100; i++)
    {
        p.post([i]
            { print("{}\n", i); });
    }
}