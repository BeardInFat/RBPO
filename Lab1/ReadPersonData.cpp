#include <iostream>

void ReadPersonData(std::string& name, unsigned short& age, double& salary)//������������ ���� � ���������� ���, ������� � ���������� ����� ��������. ��� ����� ������������ ������������� ����� �������
{
	std::cin >> name >> age >> salary;
}

void ReadPersonData(std::string& name, unsigned short& age, unsigned short& height, unsigned short& weight)//������������ ���� � ���������� ���, �������, ���� � ��� ��������. ��� ����� ������������ ������������� ����� �������
{
	std::cin >> name >> age >> height >> weight;
}