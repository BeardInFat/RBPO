#include <iostream>

unsigned short ReadPersonAge();//������������ ���� � ���������� �������� ��������
std::string ReadPersonName();//������������ ���� � ���������� ����� ��������
void ReadPersonHeight();//������������ ���� � ���������� ����� ��������
void ReadPersonWeight(unsigned short&);//������������ ���� � ���������� ���� ��������
void ReadPersonSalary(double*);//������������ ���� � ���������� ���������� ����� ��������
void ReadPersonData(std::string&, unsigned short&, double&);//������������ ���� � ���������� ���, ������� � ���������� ����� ��������. ��� ����� ������������ ������������� ����� �������
void ReadPersonData(std::string&, unsigned short&, unsigned short&, unsigned short&);//������������ ���� � ���������� ���, �������, ���� � ��� ��������. ��� ����� ������������ ������������� ����� �������
void WritePersonData(const std::string&, const std::string&, const std::string&, const unsigned short*);//������������ ����� �� ����� �����, ��������, �����, ����, ���������� ����� ��������
void Main(int argc, char** argv)
{
	
}