#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
typedef std::vector<unsigned int>::iterator ZnajomiIterator;
typedef std::string::iterator StringIterator;
class User
{
private:
	//Unikalny identyfikator uzytkownika
	unsigned int id;

	//Unikalna nazwa uzytkownika
	std::string nazwa;

	//haslo uzytkownika
	std::string haslo;

	//Lista znajomych
	std::vector<unsigned int> znajomi;

	// operacje na liscie
	bool jestNaLiscie(unsigned int) const;
	void sortujListe();
	bool wczytajZnajomych(std::string wejsciowy);
	std::string znajomiDoStringa();

	std::tm dataRejestracji;
	std::tm dataOstatniegoLogowania;
public:
	//serializacja do bazy danych
	std::string toDbString();

	// operacje na liscie
	bool dodajZnajomego(unsigned int id);
	bool dodajZnajomego(User user);
	bool usunZnajomego(unsigned int id);
	bool usunZnajomego(User user);

	//gettery
	unsigned int getId() const;
	std::string getNazwa() const;
	std::string getHaslo() const;
	std::vector<unsigned int>& getZnajomi();

	//settery
	void setNazwa(std::string nowaNazwa);
	void setHaslo(std::string noweHaslo);

	//konstruktory
	User();
	User(unsigned int id, std::string nazwa, std::string haslo);
	//User(std::string nazwa, std::string haslo, std::tm dataRejestracji);
	User(unsigned int id, std::string nazwa, std::string haslo, std::tm dataRejestracji);
	User(std::string id, std::string nazwa, std::string haslo, std::string rok, std::string miesiac, std::string dzien);
	User(std::string id, std::string nazwa, std::string haslo, std::string rok, std::string miesiac, std::string dzien, std::string znajomi);
	User(unsigned int id, std::string nazwa, std::string haslo, std::tm dataRejestracji, std::string znajomi);
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

typedef std::vector<User>::iterator UserIterator;
