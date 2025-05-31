#include <atomic>
#include <chrono>
#include <iostream>
#include <tbb/parallel_for.h>
#include <tbb/tbb.h>

int main()
{
    std::atomic_int counter{0};
    const int iterations = 1000000;

    auto start = std::chrono::high_resolution_clock::now();

    // for (int i = 0; i < iterations; ++i)
    // {
    //     counter.fetch_add(1, std::memory_order_seq_cst);
    // }

    tbb::task_arena arena{8};
    arena.execute([&]
        {
            tbb::parallel_for(tbb::blocked_range<size_t>(0, iterations),
                [&counter](tbb::blocked_range<size_t> const& r)
                {
                    for (size_t i = r.begin(); i != r.end(); i++)
                    {
                        counter++;
                    }
                });
        });

    auto end = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration<double, std::nano>(end - start).count() / iterations;

    std::cout << "Average time per fetch_add: " << duration << " ns\n";
}
