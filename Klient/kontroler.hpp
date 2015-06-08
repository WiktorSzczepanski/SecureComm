#ifndef kontroler_hpp
#define kontroler_hpp
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <list>
#include "model.hpp"
#include "widok.hpp"
#include <map>

using namespace std;

class SecureCommAction
	{
		public:
		SecureCommAction(){};
		virtual void wykonajAkcje( Ekran* ekran)
		{
				ekran->czyscEkran();
		};
		virtual ~SecureCommAction(){};
	};
	
	class RejestrowanieAction : public SecureCommAction
	{
		Model * model;
		
		public:
		RejestrowanieAction(Model* model)
		{
			this->model = model;
		};
		void wykonajAkcje( Ekran* ekran)
		{
			string login = ((EkranRejestracji*)ekran)->getLogin();
			string haslo = ((EkranRejestracji*)ekran)->getHasloSciezka();
			
			ekran->wyswietlLinieTekstu("Czekaj na rejestracje.");
			
			model->wyslijKomunikatRejestracji(RegistrationRequest(login,haslo));
			model->setLoginUzytkownika(((EkranRejestracji*)ekran)->getLogin());
			ekran->czyscEkran();
		};
		
		~RejestrowanieAction(){};
	};
	
	class AutoryzacjaHaslemAction : public SecureCommAction
	{
		Model *model;
		//Ekran*ekran;
		
		public:
		AutoryzacjaHaslemAction(Model *model)
		{
			this->model = model;
			
		};
		void wykonajAkcje(Ekran* ekran)
		{
			string login = ((EkranAutoryzacjiHaslem*)ekran)->getLogin();
			string haslo = ((EkranAutoryzacjiHaslem*)ekran)->getHasloSciezka();
			
			ekran->wyswietlLinieTekstu("Czekaj na autoryzacje haslem.");
			
			model->wyslijKomunikatLogowania(LoginRequest(login,haslo));
			model->setLoginUzytkownika(login);
			
			ekran->czyscEkran();
		};
		
		~AutoryzacjaHaslemAction()
		{
			//delete model;
			//delete ekran;
		};
	};
	
	class AutoryzacjaKluczemAction : public SecureCommAction
	{
		public:
		AutoryzacjaKluczemAction()
		{
		
		};
		void wykonajAkcje( Ekran* ekran){};
		
		~AutoryzacjaKluczemAction(){};
	};
	
	class WyborZnajomegoAction : public SecureCommAction
	{
		Model * model;
		
		public:
		WyborZnajomegoAction(Model *model)
		{
			this-> model = model;
		}
		void wykonajAkcje( Ekran * ekran)
		{
			model->dodajKomunikacjeZeZnajomym(((EkranWyboruZnajomego*)ekran)->getIdZnajomego());
			model->setIdOdbiorcy(((EkranWyboruZnajomego*)ekran)->getIdZnajomego());
		}
		~WyborZnajomegoAction() {};
	};
	
	class WyborZnajomegoBezposredniaAction : public SecureCommAction
	{
		Model * model;
		
		public:
		WyborZnajomegoBezposredniaAction(Model *model)
		{
			this-> model = model;
		}
		void wykonajAkcje( Ekran * ekran)
		{
			model->dodajKomunikacjeBezposredniaZeZnajomym(((EkranWyboruZnajomegoBezposrednia*)ekran)->getAdresOdbiorcy());
			model->setAdresOdbiorcy(((EkranWyboruZnajomegoBezposrednia*)ekran)->getAdresOdbiorcy());
			model->utworzPolaczenieBezposrednie();
		}
		~WyborZnajomegoBezposredniaAction() {};
	};
	
	class KomunikacjaAction : public SecureCommAction
	{
		Model *model;
		
		public:
		KomunikacjaAction(Model* model)
		{
			this->model = model;
		};
		void wykonajAkcje( Ekran* ekran)
		{
			((EkranKomunikacji*)ekran)->setLoginUzytkownika(model->getLoginUzytkownika());
			((EkranKomunikacji*)ekran)->setLoginZnajomego(model->getIdOdbiorcy());
			model->wyslijWiadomoscPosrednio(WiadomoscPosrednia(model->getIdOdbiorcy(),((EkranKomunikacji*)ekran)->getKomunikat()));
			((EkranKomunikacji*)ekran)->setKomunikat("");
		};
		
		~KomunikacjaAction(){};
	};
	
	class KomunikacjaBezposredniaAction : public SecureCommAction
	{
		Model *model;
		
		public:
		KomunikacjaBezposredniaAction(Model* model)
		{
			this->model = model;
		};
		void wykonajAkcje( Ekran* ekran)
		{
			((EkranKomunikacjiBezposredniej*)ekran)->setLoginUzytkownika(model->getLoginUzytkownika());
			((EkranKomunikacjiBezposredniej*)ekran)->setLoginZnajomego(model->getIdOdbiorcy());
			model->wyslijWiadomoscBezposrednio(WiadomoscPosrednia("",((EkranKomunikacjiBezposredniej*)ekran)->getKomunikat()));
			((EkranKomunikacjiBezposredniej*)ekran)->setKomunikat("");
		};
		
		~KomunikacjaBezposredniaAction(){};
	};
	
	class DodanieZnajomegoAction : public SecureCommAction
	{
		Model *model;
		
		public:
		DodanieZnajomegoAction(Model *model)
		{
			this->model = model;
		};
		void wykonajAkcje( Ekran* ekran)
		{
			string id = ((EkranDodawaniaKontaktu*)ekran)->getIdZnajomego();
			
			model->wyslijKomunikatDodaniaZnajomego(FriendAdd(id));
			ekran->czyscEkran();
		};
		
		~DodanieZnajomegoAction(){};
	};
	
	class WyswietlenieZnajomychAction : public SecureCommAction
	{
		Model * model;
		
		public:
		WyswietlenieZnajomychAction(Model *model)
		{
			this->model = model;
		};
		void wykonajAkcje( Ekran* ekran)
		{
			model->wyslijKomunikatWyswietlaniaZnajomych(FriendListRequest());
			ekran->czyscEkran();
		};
		
		~WyswietlenieZnajomychAction(){};
	};

class Kontroler
{
	
	private:
	map<string, SecureCommAction*> mapaAkcji;
	map<string, SecureCommAction*>::iterator it;
	Ekran *ekran_pop;
	Ekran *ekran;
	Model *model;
	
	public:
	Kontroler();
	~Kontroler();
	
	void petlaAplikacji();
	void wypelnijMapeAkcji();
};



#endif
