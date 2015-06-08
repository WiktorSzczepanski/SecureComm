#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <vector>
#include <ctime>
class User
{
private:
	//Unikalna nazwa uzytkownika
	std::string nazwa;

	//haslo uzytkownika
	std::string haslo;
	
	//Unikalny identyfikator uzytkownika
	unsigned int id;

	//Lista znajomych
	std::vector<User*> znajomi;

	std::tm dataRejestracji;
	std::tm dataOstatniegoLogowania;
public:
	//serializacja do bazy danych
	std::string toDbString();

	//gettery
	unsigned int getId() const;
	std::string getNazwa() const;
	std::string getHaslo() const;

	//settery
	void setNazwa(std::string nowaNazwa);
	void setHaslo(std::string noweHaslo);

	//konstruktory
	User();
	User(unsigned int id, std::string nazwa, std::string haslo);
	//User(std::string nazwa, std::string haslo, std::tm dataRejestracji);
	User(unsigned int id, std::string nazwa, std::string haslo, std::tm dataRejestracji);
	User(std::string id, std::string nazwa, std::string haslo, std::string rok, std::string miesiac, std::string dzien);
	~User();
};

//operatory
inline bool operator==(const User& lhs, const User& rhs)
{
	return lhs.getId()==rhs.getId() && lhs.getNazwa()==rhs.getNazwa();
}
inline bool operator==(const User& user, const int& number)
{
	return user.getId() == number;
}
inline bool operator==(const int& number, const User& user)
{
	return number == user.getId();
}
inline bool operator==(const User& user, const std::string& string)
{
	return string == user.getNazwa();
}
inline bool operator==(const std::string& string, const User& user)
{
	return user.getNazwa() == string;
}
