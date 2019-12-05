#pragma once
#include "HumanInfo.h"
#include <fstream>
#include <conio.h>
#define SHIFR 10


class PhoneBook
{
	int size_human;
	HumanInfo* humans;

	void LoadFromFile();//�������� �� �� ���� ������� ���������
	void SaveToFile();
	string SetSHifr(string s, bool revers=false); //���� ������, ����� ������ ���� �� � �������� ����

public:
	void AddHuman();//���������� ����� ����� �������
	void AddHuman(HumanInfo human);//���������� ������ �������
	void ShowHummanInfo();//���� � ��������, ������������ ��� ������ ����� ������
	void SetSizeHuman(int n);//������ ���������� ������� � �����
	void DeleteHuman(int index);//������ �������� �� ����������� �������
	void AddSizeHumansBooks();//��������� ���������� �����, ��� ������ � �������� �������
	void MinusSizeHumansBooks();
	void LoadFile();//�������� ���������� ���������� � �������� ����� ��������, �� ��� ���������� ���� ������
	void SaveFile();
	void ShowAllUsers();

	HumanInfo GetHuman(int index = 0);
	int GetSizeHuman();

	string MadeShifr(string s, bool revers = false);
	void ShowUserMenu();
	PhoneBook();//��� �������� �� ������� ����� ����� ��������
	PhoneBook(HumanInfo human);//������������� ��� ����.����� ������

	~PhoneBook();//�������� ��� �������� ��� ��������, ������ ������ �������

};

