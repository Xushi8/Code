// 2023/04/16 21:19:04
#include <bits/stdc++.h>
#include <mutex>
#include <thread>
using namespace std;

const int NUM_THREADS = 4;
const int MAX_NUM = 1000000;
const int MAX_COUNT = 100000000;

mutex mtx;
ofstream fout("result.txt");

void write_numbers(int thread_num, int start_num, int end_num) {
    vector<int> nums;
    nums.reserve(end_num - start_num);
    for (int i = start_num; i < end_num; i++) {
        nums.push_back(i);
    }

    mtx.lock();
    for (int i = 0; i < nums.size(); i++) {
        fout << nums[i] << endl;
    }
    mtx.unlock();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int nums_per_thread = MAX_COUNT / NUM_THREADS;
    thread t[NUM_THREADS];
    int start_num = 0, end_num = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        start_num = i * nums_per_thread;
        if (i != NUM_THREADS - 1) {
            end_num = start_num + nums_per_thread;
        }
        else {
            end_num = MAX_COUNT;
        }
        t[i] = thread(&write_numbers, i, start_num, end_num);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        t[i].join();
    }

    fout.close();
    
    cout << flush;
    system("pause");
    return 0;
}



