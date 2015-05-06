#pragma once
#include <string>
#include <vector>
#include <ctime>
class User
{
private:
	//Unikalna nazwa uzytkownika
	std::string nazwa;

	//Lista znajomych
	std::vector<User*> znajomi;

	std::tm dataRejestracji;
	std::tm dataOstatniegoLogowania;
public:
	User(std::string nazwa, std::tm dataRejestracji);
	~User();
};

