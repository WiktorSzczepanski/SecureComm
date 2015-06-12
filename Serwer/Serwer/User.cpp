#include "User.h"

//serializacja do bazy danych
std::string User::toDbString()//1,Marian,haslo1234,2015,06,25#
{
	using std::to_string;
	std::string result = to_string(id) + ',' + this->nazwa + ',' + this->haslo +
		',' + to_string(this->dataRejestracji.tm_year) +
		',' + to_string(this->dataRejestracji.tm_mon) +
		',' + to_string(this->dataRejestracji.tm_mday) + 
		',' + this->znajomiDoStringa() + '#';
	return result;
}

// operacje na liscie
bool User::jestNaLiscie(unsigned int id) const
{
	return this->znajomi.end() != std::find(this->znajomi.begin(), this->znajomi.end(), id);
}
void User::sortujListe()
{
	std::sort(this->znajomi.begin(), this->znajomi.end());
}
bool User::wczytajZnajomych(std::string wejsciowy)
{
	// wejsciowy to np: 1,2,4,5,11
	if (wejsciowy.empty())	return false;
	StringIterator it = wejsciowy.begin();
	std::string podciag = "";
	while (it != wejsciowy.end())
	{
		if (*it != ',' || *it != '#') // gdy cyfra
		{
			podciag += *it;
			if (it + 1 == wejsciowy.end())
			{
				this->dodajZnajomego(std::stoi(podciag));
			}
		}
		else if (podciag.size() != 0)
		{
			this->dodajZnajomego(std::stoi(podciag));
		}
		++it;
	}
	return true;
}
std::string User::znajomiDoStringa()
{
	std::string wynik;
	for (ZnajomiIterator it = this->znajomi.begin(); it < this->getZnajomi().end(); ++it)
	{
		wynik += std::to_string(*it) + ',';
	}
	if(!wynik.empty())	wynik.erase(wynik.end() - 1);
	return wynik;
}

bool User::dodajZnajomego(unsigned int id)
{
	if (this->jestNaLiscie(id))		return false;

	this->znajomi.push_back(id);
	return true;
}
bool User::dodajZnajomego(User user)
{
	if (this->jestNaLiscie(user.getId()))		return false;

	this->znajomi.push_back(user.getId());
	this->sortujListe();
	return true;
}
bool User::usunZnajomego(unsigned int id)
{
	// it - pozycja id do uduniecia. 
	ZnajomiIterator it = std::find(this->znajomi.begin(), this->znajomi.end(), id);
	if (it == this->znajomi.end())	return false; // jesli nie znaleziono
	
	this->znajomi.erase(it);
	this->sortujListe();
	return true;
}
bool User::usunZnajomego(User user)
{
	// it - pozycja id do uduniecia. 
	ZnajomiIterator it = std::find(this->znajomi.begin(), this->znajomi.end(), user.getId());
	if (it == this->znajomi.end())	return false; // jesli nie znaleziono

	this->znajomi.erase(it);
	this->sortujListe();
	return true;
}

//gettery
unsigned int User::getId() const
{
	return this->id;
}
std::string User::getNazwa() const
{
	return this->nazwa;
}
std::string User::getHaslo() const
{
	return this->haslo;
}
std::vector<unsigned int>& User::getZnajomi()
{
	return this->znajomi;
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
User::User(unsigned int id, std::string nazwa, std::string haslo)
{
	this->id = id;
	this->setNazwa(nazwa);
	this->setHaslo(haslo);

	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	this->dataRejestracji = *now;
	this->znajomi.clear();
}
/*
User::User(std::string nazwa, std::string haslo, std::tm dataRejestracji)
{
	this->id = BazaDanych::getBazaDanych().getMaxId() + 1;
	this->setNazwa(nazwa);
	this->setHaslo(haslo);
	this->dataRejestracji = dataRejestracji;
}
*/
User::User(unsigned int id, std::string nazwa, std::string haslo, std::tm dataRejestracji)
{
	this->id = id;
	this->setNazwa(nazwa);
	this->setHaslo(haslo);
	this->dataRejestracji = dataRejestracji;
	this->znajomi.clear();
}
User::User(std::string id, std::string nazwa, std::string haslo, std::string rok, std::string miesiac, std::string dzien)
{
	this->id = std::stoi(id);
	this->setNazwa(nazwa);
	this->setHaslo(haslo);
	this->dataRejestracji.tm_year = std::stoi(rok);
	this->dataRejestracji.tm_mon = std::stoi(miesiac);
	this->dataRejestracji.tm_mday = std::stoi(dzien);
	this->znajomi.clear();
}
User::User(std::string id, std::string nazwa, std::string haslo, std::string rok, std::string miesiac, std::string dzien, std::string znajomi)
{
	this->id = std::stoi(id);
	this->setNazwa(nazwa);
	this->setHaslo(haslo);
	this->dataRejestracji.tm_year = std::stoi(rok);
	this->dataRejestracji.tm_mon = std::stoi(miesiac);
	this->dataRejestracji.tm_mday = std::stoi(dzien);
	this->znajomi.clear();
	this->wczytajZnajomych(znajomi);
}
User::User(unsigned int id, std::string nazwa, std::string haslo, std::tm dataRejestracji, std::string znajomi)
{
	this->id = id;
	this->setNazwa(nazwa);
	this->setHaslo(haslo);
	this->dataRejestracji = dataRejestracji;
	this->znajomi.clear();
	this->wczytajZnajomych(znajomi);
}

User::~User()
{
}
