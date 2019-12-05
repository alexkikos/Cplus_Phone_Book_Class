#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <iomanip>
class HumanInfo
{

	string name;
	string patronymic;
	string surname;
	string additional_info;
	string home_phone;
	string work_phone;


public:

	bool SetName(string name1);
	bool SetPtronymic(string name);
	bool SetSurname(string n);
	bool SetHomePhone(string n);
	bool SetWorkPhone(string n);
	bool SetAdditionalInfo(string s);


	string GetName();
	string Getpatronymic();
	string GetSurname();
	string GetHomePhone();
	string GetWorkPhone();
	string GetAdditionalInfo();

	void ShowAllInfo();//для вывода результата поисков из под класса выше

	HumanInfo(string name1 = "defName", string patronymic1 = "defpatron", string surname1 = "defsurn", string home_phone1 = "380971720643", string work_phone1 = "380971720643", string addinfo = "1");//конструктор для иниц.значений
	//деструктора нет, тк  нечего чистить, инлайны не использую - не нравится читать код с ними...


};

