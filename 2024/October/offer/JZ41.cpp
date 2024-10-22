#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, less<>> q1;
    priority_queue<int, vector<int>, greater<>> q2;

    auto insert = [&](int val)
    {
        if (q1.empty() || val <= q1.top())
        {
            q1.emplace(val);
        }
        else
        {
            q2.emplace(val);
        }
        while (q1.size() >= q2.size() + 2)
        {
            q2.emplace(q1.top());
            q1.pop();
        }

        while (q1.size() < q2.size())
        {
            q1.emplace(q2.top());
            q2.pop();
        }
    };
}