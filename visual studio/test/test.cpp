#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int num[10] = { 6,5,9,1,2,8,7,3,4,0 };
	sort(num, num + 10, greater<int>());
	for (int i = 0; i < 10; i++) {
		cout << num[i] << " ";
	}//Êä³ö½á¹û:9 8 7 6 5 4 3 2 1 0

	return 0;

}
