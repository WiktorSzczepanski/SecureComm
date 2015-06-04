#include "widok.hpp"

using namespace std;

// Konstruktor.
Ekran::Ekran()
{
	dodajLinieTekstu("----- ||  SecureComm  || -----");
	setNazwaKlasy("Ekran");
}
// Zwraca nazwe klasy.
string Ekran::getNazwaKlasy()
{
	return nazwaKlasy;
}
// Ustaw nazwe klasy.
void Ekran::setNazwaKlasy(string nazwa)
{
	nazwaKlasy = nazwa;
}
// Czyści widoczny ekran terminala.
void Ekran::czyscEkran()
{
	system("clear");
}
// Wyświetla pojedynczą linie tekstu.
void Ekran::wyswietlLinieTekstu(string linia)
{
	cout<<linia<<"\n";
}
// Wyświetla tekst składający się z kilku linii.
void Ekran::wyswietlTekst(list<string> lista)
{
	for (list<string>::iterator it = lista.begin(); it != lista.end(); it++)
	{
		wyswietlLinieTekstu(*it);
	}
}
// Dodaje linie tekstu do listy:
void Ekran::dodajLinieTekstu(string linia)
{
	lista.push_back(linia);
}
// Zwraca listę komunikatow:
list<string> Ekran::zwrocListeKomunikatow()
{
	return lista;
}
// Oczekuje na odpowiedź użytkownika:
int Ekran::oczekujNaOdpowiedz()
{
	cout << "to robie ale chce nadpisac metode!"<<endl;
	return 0;
}
// Przechodzi do wybranego ekranu:
Ekran* Ekran::przejdzDoWybranegoEkranu(int i)
{
	Ekran *ekran = new Ekran();
	return ekran;
}
/* ************************************************** */
EkranWyboru::EkranWyboru()
{
	setNazwaKlasy("EkranWyboru");
}
//Dodaje opcje do listy.
void EkranWyboru::dodajOpcje(string nazwaOpcji)
{
	ostringstream numerOpcji;
	int n = lista.size() + 1;
	numerOpcji << n;
	string opcja = "\t" + numerOpcji.str();
	opcja = opcja + ") ";
	opcja = opcja + nazwaOpcji;
	lista.push_back(opcja);
	dodajLinieTekstu(opcja);	
}
//Zwraca listę opcji.
list<string> EkranWyboru::zwrocListeOpcji()
{
	return lista;
}

// Oczekuje na odpowiedź użytkownika i ją zwraca
int EkranWyboru::oczekujNaOdpowiedz()
{
	int odpowiedz=0;
	
	while(odpowiedz<1 || odpowiedz>lista.size())
	{
		cin >> odpowiedz;
	}
	
	return odpowiedz;
}
/* ************************************************************* */
EkranAutoryzacji::EkranAutoryzacji()
{
	setNazwaKlasy("EkranAutoryzacji");
}
// Oczekuje na odpowiedź użytkownika i ją zwraca.
int EkranAutoryzacji::oczekujNaOdpowiedz()
{
	cin>>login;
	wyswietlLinieTekstu(komunikatHasloSciezka);
	cin>>hasloSciezka;
	
	return 0;
}

Ekran* EkranAutoryzacji::przejdzDoWybranegoEkranu(int i)
{
	Ekran* ekran = new EkranPoprawnejAutoryzacji();
	
	return ekran;
}

void EkranAutoryzacji::setLogin(string login)
{
	this->login = login;
}
void EkranAutoryzacji::setHasloSciezka(string hasloSciezka)
{
	this->hasloSciezka = hasloSciezka;
}
void EkranAutoryzacji::setKomunikatHasloSciezka(string komunikatHasloSciezka)
{
	this->komunikatHasloSciezka = komunikatHasloSciezka;
}
string EkranAutoryzacji::getLogin()
{
	return login;
}
string EkranAutoryzacji::getHasloSciezka()
{
	return hasloSciezka;
}
/* ********************************************************* */
EkranLogowania::EkranLogowania()
{
	setNazwaKlasy("EkranLogowania");
	dodajLinieTekstu("Wybierz sposób logowania:");
	dodajOpcje("Przy pomocy hasła");
	dodajOpcje("Przy pomocy klucza");
	dodajOpcje("Powrót");
}
Ekran* EkranLogowania::przejdzDoWybranegoEkranu(int i)
{
	Ekran *ekran = new Ekran();
	EkranAutoryzacjiHaslem *eAH = new EkranAutoryzacjiHaslem();
	EkranAutoryzacjiKluczem *eAK = new EkranAutoryzacjiKluczem();
	EkranPowitalny *ePow = new EkranPowitalny();
	
	switch(i)
	{
		case 1: ekran = eAH;
				break;
		case 2: ekran = eAK;
				break;
		case 3: ekran = ePow;
				break;
		default: cout << "JAKIS BLAD"<<endl;
				break;
	}
	
	return ekran;
}
/* ************************************************************ */
EkranPowitalny::EkranPowitalny()
{
	setNazwaKlasy("EkranPowitalny");
	dodajLinieTekstu("Witaj w programie SecureComm.");
	dodajLinieTekstu("Aby rozpocząć pracę z programem wybierz jedną z opcji:");
	dodajOpcje("Logowanie");
	dodajOpcje("Rejestracja");
	dodajOpcje("Zakończ");
}
Ekran* EkranPowitalny::przejdzDoWybranegoEkranu(int i)
{
	Ekran *ekran = new Ekran();
	EkranLogowania *eLog = new EkranLogowania();
	EkranRejestracji *eRej = new EkranRejestracji();
	
	switch(i)
	{
		case 1: ekran = eLog;
				break;
		case 2: ekran = eRej;
				break;
		case 3: exit(EXIT_SUCCESS);
				break;
		default:cout<<"JAKIS BLAD"<<endl;
				break;
	}
	
	return ekran;
}
/* ************************************************************ */
EkranPoprawnejAutoryzacji::EkranPoprawnejAutoryzacji()
{
	setNazwaKlasy("EkranPoprawnejAutoryzacji");
	dodajLinieTekstu("Wybierz opcję:");
	dodajOpcje("Bezpośrednia komunikacja z innym użytkownikiem");
	dodajOpcje("Dodaj znajomego");
	dodajOpcje("Wyświetl listę użytkowników");
	dodajOpcje("Przejdź do ekranu logowania");
	dodajOpcje("Pośrednia komunikacja z innym użytkownikiem");
	dodajOpcje("Wyloguj i zakończ");
}
Ekran* EkranPoprawnejAutoryzacji::przejdzDoWybranegoEkranu(int i)
{
	Ekran *ekran = new Ekran();
	EkranLogowania *eLog = new EkranLogowania();
	EkranPowrotu *ePowr = new EkranPowrotu();
	EkranKomunikacji *eKom = new EkranKomunikacji();
	EkranDodawaniaKontaktu *eDKon = new EkranDodawaniaKontaktu();
	EkranWyswietlaniaListyUzytkownikow *eWLU = new EkranWyswietlaniaListyUzytkownikow();
	
	
	switch(i)
	{
		case 1: ekran = ePowr;
				break;
		case 2: ekran = eDKon;
				break;
		case 3: ekran = eWLU;
				break;
		case 4: ekran = eLog;
				break;
		case 5: ekran = eKom;
				break;
		case 6: exit(EXIT_SUCCESS);
				break;
		default:cout<<"JAKIS BLAD"<<endl;
				break;
	}
	
	return ekran;
}
/* ************************************************************ */
EkranAutoryzacjiHaslem::EkranAutoryzacjiHaslem()
{
	setNazwaKlasy("EkranAutoryzacjiHaslem");
	dodajLinieTekstu("Wprowadź login:");
	setKomunikatHasloSciezka("Wprowadź hasło:");
}
/* ************************************************************ */
EkranAutoryzacjiKluczem::EkranAutoryzacjiKluczem()
{
	setNazwaKlasy("EkranAutoryzacjiKluczem");
	dodajLinieTekstu("Wprowadź login:");
	setKomunikatHasloSciezka("Wprowadź ścieżkę pliku z kluczem publicznym:");
}
/* ************************************************************ */
EkranRejestracji::EkranRejestracji()
{
	setNazwaKlasy("EkranRejestracji");
	dodajLinieTekstu("Podaj kolejne dane w celu rejestracji:");
	dodajLinieTekstu("Wprowadź login:");
	setKomunikatHasloSciezka("Wprowadź hasło:");
}

int EkranRejestracji::oczekujNaOdpowiedz()
{
	EkranAutoryzacji::oczekujNaOdpowiedz();
	wyswietlLinieTekstu("Wprowadź ścieżkę pliku z kluczem publicznym:");
	cin>>sciezka;
	
	return 0;
}

string EkranRejestracji::getSciezka()
{
	return sciezka;
}

void EkranRejestracji::setSciezka(string sciezka)
{
	this->sciezka = sciezka;
}

Ekran* EkranRejestracji::przejdzDoWybranegoEkranu(int i)
{
	// TO DO: zmienic!
	Ekran *ekran = new EkranPoprawnejAutoryzacji();
	return ekran;
}
/* *********************************************************** */
EkranKomunikacji::EkranKomunikacji()
{
	setNazwaKlasy("EkranKomunikacji");
}
int EkranKomunikacji::oczekujNaOdpowiedz()
{
	string tekst;
	wyswietlLinieTekstu("ROZMOWA:");
	cin>>komunikat;//tekst;
//	while(!tekst.empty())
//	{
//		cin>>tekst;
		
	//}
	
	return 0;
}
string EkranKomunikacji::getKomunikat()
{
	return komunikat;
}
void EkranKomunikacji::setKomunikat(string komunikat)
{
	
}
/* *********************************************************** */
EkranDodawaniaKontaktu::EkranDodawaniaKontaktu()
{
	setNazwaKlasy("EkranDodaniaKontaktu");
	dodajLinieTekstu("Podaj id znajomego:");
}

int EkranDodawaniaKontaktu::oczekujNaOdpowiedz()
{
	cin>>idZnajomego;
}
Ekran* EkranDodawaniaKontaktu::przejdzDoWybranegoEkranu(int i)
{
	Ekran *ekran = new EkranPoprawnejAutoryzacji();
	return ekran;
}
string EkranDodawaniaKontaktu::getIdZnajomego()
{
	return idZnajomego;
}
void EkranDodawaniaKontaktu::setIdZnajomego(string id)
{
	idZnajomego = id;
}
EkranDodawaniaKontaktu::~EkranDodawaniaKontaktu()
{
	
}
/* **************************************************************** */
EkranWyswietlaniaListyUzytkownikow::EkranWyswietlaniaListyUzytkownikow()
{
	setNazwaKlasy("EkranWyswietlaniaListyUzytkownikow");
	wyswietlLinieTekstu("Czekaj na odpowiedz serwera");
}
int EkranWyswietlaniaListyUzytkownikow::oczekujNaOdpowiedz()
{
	string odp;
	cin>>odp;
}
Ekran* EkranWyswietlaniaListyUzytkownikow::przejdzDoWybranegoEkranu(int i)
{
	Ekran *ekran = new EkranPoprawnejAutoryzacji();
	return ekran;
}
EkranWyswietlaniaListyUzytkownikow::~EkranWyswietlaniaListyUzytkownikow(){}

/* ********************************************************** */
EkranPowrotu::EkranPowrotu()
{
	setNazwaKlasy("EkranPowrotu");
	dodajLinieTekstu("Opcja nie jest zaimplementowana");
	dodajOpcje("Powrot go glownego menu");
	dodajOpcje("Zakoncz");
}
Ekran* EkranPowrotu::przejdzDoWybranegoEkranu(int i)
{
	Ekran *ekran = new Ekran();
	EkranPowitalny *ePow = new EkranPowitalny();
	switch(i)
	{
		case 1: ekran = ePow;
				break;
		case 2: exit(EXIT_SUCCESS);
				break;
		default: cout<<"JAKIS BLAD"<<endl;
				break;
	}
	
	return ekran;
}
