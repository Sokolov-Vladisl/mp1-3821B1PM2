#pragma once

#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <string>
#include <windows.h>
#include <conio.h>



using namespace std;



class MyException : public exception //������� ����������
{
private:
	int var;
public:
	MyException(int n)
	{
		var = n;
	}
	void show()
	{
		if (var == 1)
		{
			cout << "  <!> ������ ������: �������� ������������ � ������������ ������\n";
		}
		if (var == 2)
		{
			cout <<"\n  <!> ������ � ����: ������� ������������ ���������� �� ����\n";
		}
	}
};