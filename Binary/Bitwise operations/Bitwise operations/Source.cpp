#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	unsigned char startBool = 15;
	bitset<4> originalNumber = startBool;
	cout << originalNumber << endl;

	bitset<4> mask = 1 << 3;
	//mask = ####1###
	originalNumber = originalNumber & ~mask;
	cout << originalNumber << endl;

	//mask = ####0###
	originalNumber = originalNumber | mask;
	cout << originalNumber << endl;



	system("pause");
	return 0;
}