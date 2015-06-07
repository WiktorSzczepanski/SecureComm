#include "User.h"

//serializacja do bazy danych
std::string User::toDbString()//1,Marian,haslo1234,2015,06,25#
{
	using std::to_string;
	std::string result = to_string(id) + ',' + this->nazwa + ',' + this->haslo +
		',' + to_string(this->dataRejestracji.tm_year) +
		',' + to_string(this->dataRejestracji.tm_mon) +
		',' + to_string(this->dataRejestracji.tm_mday) + '#';
	return result;
}

//gettery
std::string User::getNazwa()
{
	return this->nazwa;
}
std::string User::getHaslo()
{
	return this->haslo;
}

//settery
void User::setNazwa(std::string nowaNazwa)
{
	this->nazwa = nowaNazwa;
}
void User::setHaslo(std::string noweHaslo)
{
	this->haslo = noweHaslo;
}

//konstruktory
User::User()
{

}
User::User(std::string nazwa, std::string haslo, std::tm dataRejestracji)
{
	this->setNazwa(nazwa);
	this->setHaslo(haslo);
	this->dataRejestracji = dataRejestracji;
}

User::User(std::string id, std::string nazwa, std::string haslo, std::string rok, std::string miesiac, std::string dzien)
{
	this->id = std::stoi(id);
	this->setNazwa(nazwa);
	this->setHaslo(haslo);
	this->dataRejestracji.tm_year = std::stoi(rok);
	this->dataRejestracji.tm_mon = std::stoi(miesiac);
	this->dataRejestracji.tm_mday = std::stoi(dzien);
}

User::~User()
{
}
