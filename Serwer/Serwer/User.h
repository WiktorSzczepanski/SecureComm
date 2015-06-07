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
	std::string getNazwa();
	std::string getHaslo();

	//settery
	void setNazwa(std::string nowaNazwa);
	void setHaslo(std::string noweHaslo);

	//konstruktory
	User();
	User(std::string nazwa, std::string haslo, std::tm dataRejestracji);
	User(unsigned int id, std::string nazwa, std::string haslo, std::tm dataRejestracji);
	User(std::string id, std::string nazwa, std::string haslo, std::string rok, std::string miesiac, std::string dzien);
	~User();
};

