#include <deque>
using namespace std;

struct max_que
{
    void insert(int x)
    {
        while (!m_que.empty() && x > m_que.back())
        {
            m_que.pop_back();
        }
        m_que.emplace_back(x);
    }

    void pop(int x)
    {
        if (m_que.front() == x)
        {
            m_que.pop_front();
        }
    }

    int get()
    {
        return m_que.front();
    }
    
    deque<int> m_que;
};