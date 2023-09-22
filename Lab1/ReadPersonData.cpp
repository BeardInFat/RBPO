#include <iostream>

void ReadPersonData(std::string& name, unsigned short& age, double& salary)//Осуществляет ввод с клавиатуры имя, возраст и заработную плату человека. Для ввода использовать разработанные ранее функции
{
	std::cin >> name >> age >> salary;
}

void ReadPersonData(std::string& name, unsigned short& age, unsigned short& height, unsigned short& weight)//Осуществляет ввод с клавиатуры имя, возраст, рост и вес человека. Для ввода использовать разработанные ранее функции
{
	std::cin >> name >> age >> height >> weight;
}