#include <iostream>

std::string salary = "300";

void WritePersonData(const std::string& name, const std::string& height, const std::string& weight, const unsigned short* age)
//������������ ����� �� ����� �����, ��������, �����, ����, ���������� ����� ��������
{
	std::cout << name << "\t" << *(age) << "\t" << height << "\t" << weight << "\t" << salary;
}