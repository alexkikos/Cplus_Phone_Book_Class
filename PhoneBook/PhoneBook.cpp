#include "PhoneBook.h"



void PhoneBook::LoadFromFile()
{
	//Проблемы с чтением данных из файла, ранее не работали с чтением стрингов, будет вопрос по этому поводу на паре....
	ifstream read("users.dat");
	if (read.is_open())
	{
		int a;
		read >> a;
		humans = new HumanInfo[a];
		SetSizeHuman(a);
		for (int i = 0; i < a; i++)
		{
		
				string s, s1, s2, s3, s4, s5;
				read >> s >> s1 >> s2 >> s3 >> s4 >> s5;
				if (s.size() != 0 and s1.size() !=0)
				{
					humans[i].SetName(MadeShifr(s,true));//расшифровываю и заношу в поля
					humans[i].SetPtronymic(MadeShifr(s1,true));
					humans[i].SetSurname(MadeShifr(s2,true));
					humans[i].SetAdditionalInfo(MadeShifr(s3,true));
					humans[i].SetHomePhone(MadeShifr(s4,true));
					humans[i].SetWorkPhone(MadeShifr(s5,true));
				}
			
		}
	}
	else
		cout << "\nCant open file!!!" << endl;


	read.close();
}

void PhoneBook::SaveToFile()
{
	ofstream save("users.dat");
	if (save.is_open())
	{
		int a = GetSizeHuman();
		save << a << endl;
		for (int i = 0; i < a; i++)
		{
			string s, s1, s2, s3, s4, s5;

			s = MadeShifr(humans[i].GetName());//шифрую данные цезарем
			s1 = MadeShifr(humans[i].Getpatronymic());
			s2 = MadeShifr( humans[i].GetSurname());
			s3 = MadeShifr(humans[i].GetAdditionalInfo());
			s4 = MadeShifr(humans[i].GetHomePhone());
			s5 = MadeShifr(humans[i].GetWorkPhone());

			save << s << " " << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << endl;
		
		}
	}
	else
		cout << "\nCant open file!!!" << endl;


	save.close();
}

string PhoneBook::SetSHifr(string s, bool revers)
{
	string a = s;
	if (revers == false)
	{

		for (int i = 0; i < s.size(); i++)
		{
			a[i] += SHIFR;
		}

	}
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			a[i]-= SHIFR;
		}

	}
	return a;

}

void PhoneBook::AddHuman()
{
	HumanInfo temp_user;//можно было через указатель
	string s, s1, s2, s3, a, b;


	cout << "\nEnter name user: ";
	cin >> s1;
	if (temp_user.SetName(s1) == false) return;//if enter not correct return with error

	cout << "\nEnter patronymic name: ";
	cin >> s2;
	if (temp_user.SetPtronymic(s2)==false) return;


	cout << "\nEnter surname: ";
	cin >> s3;
	if (temp_user.SetSurname(s3)==false) return;


	cout << "\nEnter user work_phone: ";
	cin >> b;
	if (temp_user.SetWorkPhone(b)==false) return;



	cout << "\nEnter user home_phone: ";
	cin >> a;
	if (temp_user.SetHomePhone(a)==false) return;



	cout << "\nEnter additional info (limits 10 chars): ";
	cin >> s;
	if (temp_user.SetAdditionalInfo(s)==false) return;

	AddHuman(temp_user);
}

void PhoneBook::AddHuman(HumanInfo human)
{
	HumanInfo* temp = new HumanInfo[size_human + 1];//выделил память под нового юзера
	for (int i = 0; i < size_human; i++)
	{
		temp[i] = humans[i];//переписал значения старые
	}
	temp[size_human] = human;//добавил нового юзера
	AddSizeHumansBooks();//инкриментировал общее количество юзеров
	if (humans != nullptr) delete[] humans;//удалил старые значения
	humans = temp;//старому указателю присвоил новый адрес значений

}

void PhoneBook::ShowHummanInfo()
{
	for (int i = 0; i < GetSizeHuman(); i++)
	{
		cout << "\nName: " << humans[i].GetName();
		cout << "\nName2: " << humans[i].Getpatronymic();
		cout << "\nSurname: " << humans[i].GetSurname();
		cout << "\nPhoneHome: " << humans[i].GetHomePhone();
		cout << "\nPhoneWork: " << humans[i].GetWorkPhone();
		cout << "\nAddInfo: " << humans[i].GetAdditionalInfo();
		cout << endl;
	}
}

void PhoneBook::SetSizeHuman(int n)
{
	size_human = n;
}

void PhoneBook::DeleteHuman(int index)
{
	if (GetSizeHuman() == 0 or index > GetSizeHuman() or index < GetSizeHuman()) return;
	int count = 0;
	index--;//тк пользователь не учитывает 0, занижаю входящий индекс для удаления
	HumanInfo* temp = new HumanInfo[size_human - 1];//выделил память под новый массив -1
	for (int i = 0; i < GetSizeHuman(); i++)//получил текущий размер 
	{
		if (i == index) continue;
		else
		{
			temp[count++] = humans[i];//переписываем значения 
		}
	}
	delete[] humans;//удаляю старый масссив
	humans = temp;//принимаю новый
	MinusSizeHumansBooks();//минусую текущее количество юзеров


}



void PhoneBook::AddSizeHumansBooks()
{
	size_human += 1;
}

void PhoneBook::MinusSizeHumansBooks()
{
	size_human -= 1;
}

void PhoneBook::LoadFile()
{
	LoadFromFile();
}

void PhoneBook::SaveFile()
{
	SaveToFile();
}

void PhoneBook::ShowAllUsers()
{
	cout << "Users name ";
	cout << "         Users Getpatronymic";
	cout << "         Users Surname";
	cout << "         Users WorkPhone";
	cout << "         Users HomePhone";
	cout << "         Users AdditionalInfo";
	cout << endl;

	for (int i = 0; i < GetSizeHuman(); i++)
	{
		cout << i + 1 << ". " << humans[i].GetName();
		for (int ic = 0; ic < 18 - humans[i].GetName().length(); ic++)
		{
			cout << " ";
		}
		cout << humans[i].Getpatronymic();
		for (int ic = 0; ic < 27 - humans[i].Getpatronymic().length(); ic++)
		{
			cout << " ";
		}
		cout << humans[i].GetSurname();
		for (int ic = 0; ic < 21 - humans[i].GetSurname().length(); ic++)
		{
			cout << " ";
		}
		cout << setw(15) << humans[i].GetWorkPhone();
		cout << setw(25) << humans[i].GetHomePhone();
		cout << setw(20) << humans[i].GetAdditionalInfo() << endl;
	}
	cout << endl;
}

HumanInfo PhoneBook::GetHuman(int index)
{
	return humans[index];
}

int PhoneBook::GetSizeHuman()
{
	return size_human;
}




string PhoneBook::MadeShifr(string s, bool revers)
{
	string a;
	if (revers == false)
	{
		 a = SetSHifr(s);
	}
	else
	{
		a = SetSHifr(s,true);
	}
	return a;
}

void PhoneBook::ShowUserMenu()
{
	char choice;
	string search, phone;
	

	do
	{
		char a;
		cout << "\nДля продолжения нажмите клавишу!";
		cin.ignore();
		a = _getch();
		system("cls");
		bool find = false;
		cout << endl;
		cout << "================================================================" << endl;
		cout << "1. ShowAllusers" << endl;
		cout << "2. FindUserAtName" << endl;
		cout << "3. FindUserAtPatronymic" << endl;//отчество
		cout << "4. FindUserAtSurname" << endl;
		cout << "5. FindUserAtPhone" << endl;
		cout << "6. AddNewUser" << endl;
		cout << "7. DeleteUser" << endl;
		cout << "8. LoadContacts" << endl;
		cout << "9. SaveContatcs" << endl;
		cout << "================================================================" << endl;
		choice = _getch();
		switch (choice)
		{
		case '1': ShowAllUsers();break;
		case '2':

			cout << "\nEnter name for search: ";
			cin >> search;
			for (int i = 0; i < GetSizeHuman(); i++)
			{
				if (humans[i].GetName() == search)
				{
					humans[i].ShowAllInfo();
					find = true;
				}
			}
			if (find == false) cout << "\nNo contacts!" << endl;
			break;
		case '3':

			cout << "\nEnter Patronymic for search: ";
			cin >> search;
			for (int i = 0; i < GetSizeHuman(); i++)
			{
				if (humans[i].Getpatronymic() == search)
				{
					humans[i].ShowAllInfo();
					find = true;
				}
			}
			if (find == false) cout << "\nNo contacts!" << endl;
			break;
		case '4':
			cout << "\nEnter Surname for search: ";
			cin >> search;
			for (int i = 0; i < GetSizeHuman(); i++)
			{
				if (humans[i].GetSurname() == search)
				{
					humans[i].ShowAllInfo();
					find = true;
				}
			}
			if (find == false) cout << "\nNo contacts!" << endl;
			break;
		case '5':
			cout << "\nEnter Phone for search: ";
			cin >> phone;
			for (int i = 0; i < GetSizeHuman(); i++)
			{
				if (humans[i].GetWorkPhone() == phone or humans[i].GetHomePhone() == phone)
				{
					humans[i].ShowAllInfo();
					find = true;
				}
			}
			if (find == false) cout << "\nNo contacts!" << endl;
			break;


		case '6': AddHuman(); break;
		case '7': int index; ShowAllUsers();  cout << "\nВведите номер индекса контакта: "; cin >> index; DeleteHuman(index); break;
		case '8': LoadFile(); break;
		case '9':SaveFile(); break;
		default:
			break;
		}
	} while (choice > 9 and choice < 1);
}

PhoneBook::PhoneBook()
{
	humans = nullptr;
	LoadFile();
}

PhoneBook::PhoneBook(HumanInfo human)
{
	HumanInfo s;
	s.SetAdditionalInfo(human.GetAdditionalInfo());
	s.SetHomePhone(human.GetHomePhone());
	s.SetName(human.GetName());
	s.SetPtronymic(human.Getpatronymic());
	s.SetSurname(human.GetSurname());
	s.SetWorkPhone(human.GetWorkPhone());
	AddHuman(s);
}

PhoneBook::~PhoneBook()
{
	SaveToFile();//корректно ли так сохранять данные? при выходе из программы сохраняем данные а потом удаляем указатели
	delete[] humans;


}

