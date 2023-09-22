#include <iostream>

unsigned short ReadPersonAge()//Осуществляет ввод с клавиатуры возраста человека
{
	unsigned short age;
	std::cin >> age;
	return age;
}