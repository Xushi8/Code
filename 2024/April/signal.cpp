#include <csignal>
#include <iostream>
#include <thread>
using namespace std;

void func(int)
{
	cout << "killed" << endl;
}

int main()
{
	signal(SIGINT, func);
	while (1)
	{
		this_thread::sleep_for(100ms);
    }
}