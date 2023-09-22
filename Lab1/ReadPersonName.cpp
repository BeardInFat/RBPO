#include <iostream>

std::string ReadPersonName()//Осуществляет ввод с клавиатуры имени человека
{
	std::string name;
	std::cin >> name;
	return name;
}