#include <ctime>
#include <iostream>
using namespace std;
int ChangeBit(int num, int bit_n, bool bit)
{
	bool a = (1 & (num >> (bit_n - 1)) ? 1 : 0);
	unsigned int y = 4294967295;
	if (a != bit && bit == 1)
		num = (1 << (bit_n - 1)) | num;
	unsigned int j = 1;
	if (a != bit && bit == 0)
		num = (y - (j << (bit_n - 1))) & num;
	return num;
}
int main()
{
	while (true) {
		int order;
		unsigned int mask;
		short int number;
		int r;
		int ma;
		int bit;
		int numberbit;
		bool _continue;
		_continue = true;
		int changebit;
		const int massivelen = 2;
		cout << "Please, print number of the exercise from 1 to 4(0 - close programm)" << endl;
		if (!(cin >> number && number >= 0 && number <= 4))
		{
			cout << "error, you have run out of limits" << endl;
			return -1;
		}
		switch (number)
		{
		case 0:
			break;
		case 1:
			cout <<
				"int: " << sizeof(int) << endl <<
				"short int: " << sizeof(short int) << endl <<
				"float: " << sizeof(float) << endl <<
				"double: " << sizeof(double) << endl <<
				"long double: " << sizeof(long double) << endl <<
				"char: " << sizeof(char) << endl <<
				"bool: " << sizeof(bool) << endl;
			break;
		case 2:
			int a;
			cout << "write a number from -2147483648 to 2147483647" << endl;
			if (!(cin >> a && a >= -2147483648 && a <= 2147483648))
			{
				cout << "error, you have run out of limits" << endl;
				return -1;
			}
			order = sizeof(int) * 8 - 1;
			mask = 1 << order;
			for (int i = 1; i <= order + 1; i++) {
				cout << ((a & mask) ? 1 : 0);
				mask >>= 1;
				if (i % 8 == 0 || i == 1)
					cout << " ";
			}
			cout << endl;
			cout << "Do you want to change a bit? (1 - yes, 0 - no)" << endl;
			if (!(cin >> changebit && changebit >= 0 && changebit <= 1))
			{
				cout << "error, you have run out of limits" << endl;
				return -1;
			}
			if (changebit == 1) {
				while (true) {
					cout << "print a number of bit from 1 to " << sizeof(int) * 8 << endl;
					if (!(cin >> numberbit && numberbit >= 0 && numberbit <= sizeof(int) * 8))
					{
						cout << "error, you have run out of limits" << endl;
						return -1;
					}
					srand(time(0));
					r = (rand() % sizeof(int) * 8);
					ma = 1 << r;
					bit = (a & ma) ? 1 : 0;
					a = ChangeBit(a, numberbit, bit);
					order = sizeof(int) * 8 - 1;
					mask = 1 << order;
					for (int i = 1; i <= order + 1; i++) {
						cout << ((a & mask) ? 1 : 0);
						mask >>= 1;
						if (i % 8 == 0 || i == 1)
							cout << " ";
					}
					cout << endl;
					cout << "Do you want to repeat? (1 - yes, 0 - no)" << endl;
					if (!(cin >> changebit && changebit >= 0 && changebit <= 1))
					{
						cout << "error, you have run out of limits" << endl;
						return -1;
					}
					if (changebit == 0)
						break;
				}

			}
			break;
		case 3:
			union {
				float fa;
				int ia;
			};
			cout << "write a number" << endl;
			cin >> fa;
			order = sizeof(int) * 8 - 1;
			mask = 1 << order;
			for (int i = 1; i <= order + 1; i++) {
				cout << ((ia & mask) ? 1 : 0);
				mask >>= 1;
				if ((i % 8 == 0 && i != 8) || i == 1 || i == 9)
					cout << " ";
			}
			cout << endl;
			cout << "Do you want to change a bit? (1 - yes, 0 - no)" << endl;
			if (!(cin >> changebit && changebit >= 0 && changebit <= 1))
			{
				cout << "error, you have run out of limits" << endl;
				return -1;
			}
			if (changebit == 1) {
				while (true) {
					cout << "print a number of bit from 1 to " << sizeof(int) * 8 << endl;
					if (!(cin >> numberbit && numberbit >= 0 && numberbit <= sizeof(int) * 8))
					{
						cout << "error, you have run out of limits" << endl;
						return -1;
					}
					srand(time(0));
					r = (rand() % sizeof(int) * 8);
					ma = 1 << r;
					bit = (ia & ma) ? 1 : 0;
					ia = ChangeBit(ia, numberbit, bit);
					order = sizeof(int) * 8 - 1;
					mask = 1 << order;
					for (int i = 1; i <= order + 1; i++) {
						cout << ((ia & mask) ? 1 : 0);
						mask >>= 1;
						if ((i % 8 == 0 && i != 8) || i == 1 || i == 9)
							cout << " ";
					}
					cout << endl;
					cout << "Do you want to repeat? (1 - yes, 0 - no)" << endl;
					if (!(cin >> changebit && changebit >= 0 && changebit <= 1))
					{
						cout << "error, you have run out of limits" << endl;
						return -1;
					}
					if (changebit == 0)
						break;
				}
			}
			break;
		case 4:
			union {
				double da;
				unsigned int massivea[massivelen];
			};
			cout << "write a number" << endl;
			cin >> da;
			for (int j = 1; j >= 0; j--) {
				order = sizeof(unsigned int) * 8 - 1;
				mask = 1 << order;
				for (int i = 1; i <= order + 1; i++) {
					cout << ((massivea[j] & mask) ? 1 : 0);
					mask >>= 1;
					if ((i == 1 && j == 1) || (i == 12 && j == 1))
						cout << " ";
				}
			}
			cout << endl;
			cout << "Do you want to change a bit? (1 - yes, 0 - no)" << endl;
			if (!(cin >> changebit && changebit >= 0 && changebit <= 1))
			{
				cout << "error, you have run out of limits" << endl;
				return -1;
			}
			if (changebit == 1) {
				while (true) {
					cout << "print a number of bit from 1 to " << sizeof(double) * 8 << endl;
					int numberbit;
					if (!(cin >> numberbit && numberbit >= 0 && numberbit <= sizeof(double) * 8))
					{
						cout << "error, you have run out of limits" << endl;
						return -1;
					}
					int slotnumber = 1;
					if (numberbit > 32) {
						numberbit -= 32;
						slotnumber = 0;
					}
					srand(time(0));
					r = (rand() % sizeof(double) * 8);
					int slotr;
					slotr = 1;
					if (r > sizeof(int) * 8) {
						slotr = 0;
						r -= sizeof(int) * 8;
					}
					ma = 1 << r;
					bit = (massivea[slotr] & ma) ? 1 : 0;
					for (int i = 0; i < 2; i++)
						massivea[i] = ChangeBit(massivea[i], numberbit, bit);
					for (int j = 1; j >= 0; j--) {
						order = sizeof(unsigned int) * 8 - 1;
						unsigned int mask;
						mask = 1 << order;
						for (int i = 1; i <= order + 1; i++) {
							cout << ((massivea[j] & mask) ? 1 : 0);
							mask >>= 1;
							if ((i == 1 || i == 12) && j == 1)
								cout << " ";
						}
					}
					cout << endl;
					cout << "Do you want to repeat? (1 - yes, 0 - no)" << endl;
					if (!(cin >> changebit && changebit >= 0 && changebit <= 1))
					{
						cout << "error, you have run out of limits" << endl;
						return -1;
					}
					if (changebit == 0)
						break;
				}
			}
			break;
		}
		if (number == 0)
			break;
		cout << "Do you want to continue? (1 - yes, 0 - no)" << endl;
		if (!(cin >> _continue && _continue >= 0 && _continue <= 1))
		{
			cout << "error, you have run out of limits" << endl;
			return -1;
		}
		if (_continue == false)
			break;
	}
	return 0;
}
