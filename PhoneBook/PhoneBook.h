#pragma once
#include "HumanInfo.h"
#include <fstream>
#include <conio.h>
#define SHIFR 10


class PhoneBook
{
	int size_human;
	HumanInfo* humans;

	void LoadFromFile();//закрытые тк не хочу пр€мого обращени€
	void SaveToFile();
	string SetSHifr(string s, bool revers=false); //шифр цезар€, чтобы данные были не в открытом виде

public:
	void AddHuman();//добавление юзера через консоль
	void AddHuman(HumanInfo human);//добавление целого обьекта
	void ShowHummanInfo();//инфо о человеке, используетс€ дл€ вывода после поиска
	void SetSizeHuman(int n);//сеттер количества человек в книге
	void DeleteHuman(int index);//удал€ю человека по указагнному индексу
	void AddSizeHumansBooks();//инкримент количества людей, при работе с массивом хуманов
	void MinusSizeHumansBooks();
	void LoadFile();//основную реализацию сохранени€ и загрузки решил спр€тать, тк там реализован шифр цезар€
	void SaveFile();
	void ShowAllUsers();

	HumanInfo GetHuman(int index = 0);
	int GetSizeHuman();

	string MadeShifr(string s, bool revers = false);
	void ShowUserMenu();
	PhoneBook();//при загрузке по дефолту сразу гружу контакты
	PhoneBook(HumanInfo human);//ѕерегруженный дл€ иниц.своих данных

	~PhoneBook();//сохран€ю при закрытии все контакты, удал€ю массив хуманов

};

