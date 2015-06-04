#ifndef widok_hpp
#define widok_hpp
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <list>

using namespace std;

/*Klasa reprezentująca nowy ekran terminala widoczny dla
 * użytkownika.
 */
class Ekran
{
	private:
	// Lista komunikatów do wyświetlenia.
	list<string> lista;
	// Nazwa klasy.
	string nazwaKlasy;
	
	public:
	Ekran();
	// Zwraca nawę klasy.
	string getNazwaKlasy();
	// Ustawia nazwę klasy.
	void setNazwaKlasy(string nazwa);
	// Czyści widoczny ekran terminala.
	void czyscEkran();
	// Wyświetla pojedynczą linie tekstu.
	void wyswietlLinieTekstu(string linia);
	// Wyświetla tekst składający się z kilku linii.
	void wyswietlTekst(list<string> lista);
	// Dodaje linie tekstu do listy.
	void dodajLinieTekstu(string linia);
	// Zwraca listę komunikatów:
	list<string> zwrocListeKomunikatow();
	// Oczekuje na odpowiedź użytkownika i ją zwraca:
	virtual int oczekujNaOdpowiedz();
	// Przechodzi do wskazanego przez użytkownika ekranu:
	virtual Ekran* przejdzDoWybranegoEkranu(int i);
};

/* Klasa pozwalająca na wyświetlanie komunikatu wyboru
 * jednej z listy operacji
 */ 
class EkranWyboru : public Ekran
{
	private:
	// Lista opcji wyboru użytkownika.
	list<string> lista;
	
	public:
	EkranWyboru();
	// Dodaje opcję do listy.
	void dodajOpcje(string nazwaOpcji);
	// Zwraca listę opcji.
	list<string> zwrocListeOpcji();
	// Oczekuje na odpowiedź użytkownika i ją zwraca:
	int oczekujNaOdpowiedz();
};

/* Klasa reprezentująca operacje, które może wybrać użytkownik po
 * poprawnym zalogowaniu/zarejestrowaniu w systemie.
 * Do operacji należą:
 * 			1) Rozpoczęcie komunikacji z innym użytkownikiem przez serwer
 * 			2) Wyświetlenie listy użytkowników
 * 			3) Bezpośrednie połączenie z innym użytkownikiem
 * 			4) Przejście do ekranu logowania
 * 			5) Zakończenie pracy
 */
class EkranPoprawnejAutoryzacji : public EkranWyboru
{
	public:
	EkranPoprawnejAutoryzacji();
	// Przechodzi do wskazanego ekranu.
	Ekran* przejdzDoWybranegoEkranu(int i);
};

/* Klasa umożliwiająca dokonanie autoryzacji użytkownika
 */
class EkranAutoryzacji : public Ekran
{
	private:
	// Pole zawiera login podany przez użytkownika.
	string login;
	// Pole zawiera hasło lub sciezke podane przez użytkownika.
	string hasloSciezka;
	// Pole komunikatu do wyswietlenia - haslo/klucz.
	string komunikatHasloSciezka;
	
	public:
	EkranAutoryzacji();
	// Oczekuje na odpowiedź użytkownika i ją zwraca.
	virtual int oczekujNaOdpowiedz();
	// Przechodzi do wskazanego przez użytkownika ekranu:
	Ekran* przejdzDoWybranegoEkranu(int i);
	void setLogin(string login);
	void setHasloSciezka(string hasloSciezka);
	void setKomunikatHasloSciezka(string komunikatHasloSciezka);
	string getLogin();
	string getHasloSciezka();
};

/* Klasa umożliwiająca dokonanie autoryzacji przy pomocy hasła
 * podawanego przez użytkownika.
 */
class EkranAutoryzacjiHaslem : public EkranAutoryzacji
{
	public:
	EkranAutoryzacjiHaslem();
};

/* Klasa umożliwiająca dokonanie autoryzacji przy użyciu klucza
 * Jaka forma? czy plik?
 */
class EkranAutoryzacjiKluczem : public EkranAutoryzacji
{
	public:
	EkranAutoryzacjiKluczem();
};

/* Klasa reprezentująca ekran logowania, wyświetlany użytkownikowi,
 * po wyborze opcji logowania.
 * Prosi on użytkownika o podanie loginu oraz wyboru sposobu autoryzacji.
 * Autoryzacji można dokonać na dwa sposoby:
 * 		1) Przy pomocy hasła
 * 		2) Przy pomocy klucza
 * 		3) Powrót
 */
class EkranLogowania : public EkranWyboru
{
	public:
	EkranLogowania();
	// Przechodzi do wybranego ekranu.
	Ekran* przejdzDoWybranegoEkranu(int i);
};

/* Klasa umożliwiająca zarejestrowanie nowego użytkownika w
 * systemie. Kolejno podawane są informacje:
 * 		1) unikalny login użytkownika
 * 		2) wprowadzenie hasła użytkownika
 * 		3) przekazanie ścieżki pliku z kluczem publicznym
 */ 
class EkranRejestracji : public EkranAutoryzacji
{
	private:
	string sciezka;
	
	public:
	EkranRejestracji();
	int oczekujNaOdpowiedz();
	Ekran* przejdzDoWybranegoEkranu(int i);
	string getSciezka();
	void setSciezka(string sciezka);
};

/* Klasa reprezentująca ekran powitalny wyświetlany użytkownikowi,
 * który rozpoczyna pracę z programem.
 * Z tego poziomu dostępne są dwie opcje:
 * 		1) logowanie
 * 		2) rejestracja
 * 		3) wyjścia z programu
 */
class EkranPowitalny : public EkranWyboru
{
	public:
	EkranPowitalny();
	// Przechodzi do wybranego ekranu.
	Ekran* przejdzDoWybranegoEkranu(int i);
};

/* Klasa przekazująca użytkownikowi informację o błędzie podczas
 * realizowania jakiejś operacji np. podanie nie unikalnego loginu,
 * błędne hasło itp. itd.
 */
class EkranBleduOperacji : Ekran
{
	public:
	EkranBleduOperacji(list<string> komunikatBledu)
	{
		wyswietlTekst(komunikatBledu);
	}
};

/* Klasa umożliwiająca prowadzenie komunikacji z innym użytkownikem
 */ 
class EkranKomunikacji : public Ekran
{
	private:
	string komunikat;
	
	public:
	EkranKomunikacji();
	int oczekujNaOdpowiedz();
	string getKomunikat();
	void setKomunikat(string komunikat);
};

/* Klasa umożliwiająca wyświetlanie komunikatu oczekiwania na
 * odpowiedź serwera.
 */
class EkranOczekiwaniaNaSerwer : public Ekran
{

};
/* Klas umożliwiająca dodanie kontaktu do znajomych.
 * 
 */
class EkranDodawaniaKontaktu : public Ekran
{
	private:
	string idZnajomego;
	
	public:
	EkranDodawaniaKontaktu();
	int oczekujNaOdpowiedz();
	Ekran* przejdzDoWybranegoEkranu(int i);
	string getIdZnajomego();
	void setIdZnajomego(string idZnajomego);
	~EkranDodawaniaKontaktu();
};
/* Klasa umożliwiająca wyświetlenie listy użytkowników
 */
class EkranWyswietlaniaListyUzytkownikow : public Ekran
{
	public:
	EkranWyswietlaniaListyUzytkownikow();
	int oczekujNaOdpowiedz();
	Ekran* przejdzDoWybranegoEkranu(int i);
	~EkranWyswietlaniaListyUzytkownikow();

};

/* Klasa specjalizująca komunikację pośrednią z innym użytkownikem
 */
class EkranKomunikacjiPosredniej : public EkranKomunikacji
{

}; 

/* Klasa specjalizująca komunikację bezpośrednią z innym użytkownikem
 */
class EkranKomunikacjiBezposredniej : public EkranKomunikacji
{

}; 

/* Klasa umożliwiająca wysyłanie wiadomości od klienta
 */
class WysylanieWiadomosc
{
	
};

/* Klasa umożliwiająca odbieranie wiadomości przez klienta
 */
class OdbieranieWiadomosci
{
	
};

/* Klasa testowa pozwalajaca na powrot z nie zaimplementowanej
 * operacji.
 */
class EkranPowrotu : public EkranWyboru
{
	public:
	EkranPowrotu();
	Ekran* przejdzDoWybranegoEkranu(int i);
};

#endif
