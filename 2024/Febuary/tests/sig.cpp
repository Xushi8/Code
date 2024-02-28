#include <iostream>
#include <signal.h>
#include <thread>
using namespace std;

void ctrl_c_is_pressed(int signo)
{
	cout << "小朋友，你是否有很多问号？" << endl;
}

int main()
{
	signal(SIGINT, ctrl_c_is_pressed);
	while (true)
		this_thread::sleep_for(chrono::nanoseconds(1));
	return 0;
}
