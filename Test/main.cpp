#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

int main()
{
	stringstream ss("123 213 321");
	string s;
	while (ss>>s)
	{
		cout << s;
	}
}