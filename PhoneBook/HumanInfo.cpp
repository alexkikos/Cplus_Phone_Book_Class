#include "HumanInfo.h"

bool HumanInfo::SetName(string name1)
{

	if (name1.size() != 0 and name1.size() < 15) 	name = name1;
	else
	{
		cout << "\nWrong input";
		return false;
	}
	return true;
}

bool HumanInfo::SetPtronymic(string name1)
{
	if (name1.size() != 0 and name1.size() < 20) 		patronymic = name1;
	else
	{
		cout << "\nWrong input";
		return false;
	}
	return true;

}

bool HumanInfo::SetSurname(string n)
{
	if (n.size() != 0 and n.size() < 20) 	surname = n;
	else
	{
		cout << "\nWrong input";
		return false;
	}
	return true;
}

bool HumanInfo::SetHomePhone(string n)
{
	if (n.size() != 0 and n.size() < 20)
	{
		home_phone = n;
	}
	else
	{
		cout << "\nWrong input";
		return false;
	}
	return true;
}

bool HumanInfo::SetWorkPhone(string n)
{
	if (n.size() != 0 and n.size() < 15)
	{
		work_phone = n;
	}
	else
	{
		cout << "\nWrong input";
		return false;
	}
	return true;
}

bool HumanInfo::SetAdditionalInfo(string s)
{
	if (s.size() != 0 and s.size() < 20)	additional_info = s;
	else
	{
		cout << "\nWrong input";
		return false;
	}
	return true;
}

string HumanInfo::GetName()
{
	return name;
}

string HumanInfo::Getpatronymic()
{
	return patronymic;
}

string HumanInfo::GetSurname()
{
	return surname;
}

string HumanInfo::GetHomePhone()
{
	return home_phone;
}

string HumanInfo::GetWorkPhone()
{
	return work_phone;
}

string HumanInfo::GetAdditionalInfo()
{
	return additional_info;
}

void HumanInfo::ShowAllInfo()
{

	cout << GetName();
	cout << setw(26 - GetName().size()) << Getpatronymic();
	cout << setw(26 - Getpatronymic().size()) << GetSurname();
	cout << setw(28) << GetWorkPhone();
	cout << setw(24) << GetHomePhone();
	cout << setw(13) << GetAdditionalInfo() << endl;

}



HumanInfo::HumanInfo(string name1, string patronymic1, string surname1, string home_phone1, string work_phone1, string addinfo)
{

	this->SetName(name1);
	this->SetPtronymic(patronymic1);
	this->SetSurname(surname1);
	this->SetHomePhone(home_phone1);
	this->SetWorkPhone(work_phone1);
	this->SetAdditionalInfo(addinfo);

}
