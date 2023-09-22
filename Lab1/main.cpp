#include <iostream>

unsigned short ReadPersonAge();//Осуществляет ввод с клавиатуры возраста человека
std::string ReadPersonName();//Осуществляет ввод с клавиатуры имени человека
void ReadPersonHeight();//Осуществляет ввод с клавиатуры роста человека
void ReadPersonWeight(unsigned short&);//Осуществляет ввод с клавиатуры веса человека
void ReadPersonSalary(double*);//Осуществляет ввод с клавиатуры заработной платы человека
void ReadPersonData(std::string&, unsigned short&, double&);//Осуществляет ввод с клавиатуры имя, возраст и заработную плату человека. Для ввода использовать разработанные ранее функции
void ReadPersonData(std::string&, unsigned short&, unsigned short&, unsigned short&);//Осуществляет ввод с клавиатуры имя, возраст, рост и вес человека. Для ввода использовать разработанные ранее функции
void WritePersonData(const std::string&, const std::string&, const std::string&, const unsigned short*);//Осуществляет вывод на экран имени, возраста, роста, веса, заработной платы человека
void Main(int argc, char** argv)
{
	
}