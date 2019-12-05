using namespace std;
#include <iostream>
#include <string>
#include "PhoneBook.h"



int main()
{
	setlocale(LC_ALL, "");
	PhoneBook my;
	//PhoneBook my{ {"alex", "yurievich", "nechiporenko", "380971720643", "34453535", "all ok!"} };
	while(true) my.ShowUserMenu();

	system("pause");
	return 0;

}