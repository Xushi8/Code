#include <iostream>
#include <memory>
using namespace std;

struct A
{
	int val;
	A(int val_)
	{
		val = val_;
	}

	~A()
	{
		cout << "A destroyed!\n";
	}
};

void func()
{
}

int main()
{

	return 0;
}