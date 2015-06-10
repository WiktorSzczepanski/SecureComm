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
		virtual int wykonajAkcje( Ekran* ekran, int odp)
		{ 
			return odp;
		};
		virtual ~SecureCommAction(){};
	};
	
	class EkranPowitalnyAction : public SecureCommAction
	{
		Model * model;
		
		public:
		EkranPowitalnyAction(Model * model)
		{
			this->model = model;
		};
		int wykonajAkcje(Ekran* ekran, int odp)
		{
			ekran->czyscEkran();
			
			return odp;
		};
		~EkranPowitalnyAction(){};
	};
	
	class EkranLogowaniaAction : public SecureCommAction
	{
		Model * model;
		
		public:
		EkranLogowaniaAction(Model * model)
		{
			this->model = model;
		};
		int wykonajAkcje(Ekran* ekran, int odp)
		{
			ekran->czyscEkran();
			
			return odp;
		};
		~EkranLogowaniaAction(){};
	};
	
	
	
	
	class RejestrowanieAction : public SecureCommAction
	{
		Model * model;
		
		public:
		RejestrowanieAction(Model* model)
		{
			this->model = model;
		};
		int wykonajAkcje( Ekran* ekran, int odp)
		{
			string login = ((EkranRejestracji*)ekran)->getLogin();
			string haslo = ((EkranRejestracji*)ekran)->getHasloSciezka();
			
			ekran->wyswietlLinieTekstu("Czekaj na rejestracje.");
			
			model->wyslijKomunikatRejestracji(RegistrationRequest(login,haslo));
			model->setLoginUzytkownika(((EkranRejestracji*)ekran)->getLogin());
			ekran->czyscEkran();
			
			return odp;
			
		};
		
		~RejestrowanieAction(){};
	};
	
	class AutoryzacjaHaslemAction : public SecureCommAction
	{
		Model *model;
		
		public:
		AutoryzacjaHaslemAction(Model *model)
		{
			this->model = model;
			
		};
		int wykonajAkcje(Ekran* ekran, int odp)
		{
			string login = ((EkranAutoryzacjiHaslem*)ekran)->getLogin();
			string haslo = ((EkranAutoryzacjiHaslem*)ekran)->getHasloSciezka();
			
			ekran->wyswietlLinieTekstu("Czekaj na autoryzacje haslem.");
			
			model->wyslijKomunikatLogowania(LoginRequest(login,haslo));
			model->setLoginUzytkownika(login);
			
			ekran->czyscEkran();
			
			return odp;
			
		};
		
		~AutoryzacjaHaslemAction()
		{
			//delete model;
			//delete ekran;
		};
	};
	
	class PoprawneLogowanieAction : public SecureCommAction
	{
		Model * model;
		
		public:
		PoprawneLogowanieAction(Model * model)
		{
			this->model = model;
		};
		int wykonajAkcje(Ekran* ekran, int odp)
		{
			return 1;
		};
		~PoprawneLogowanieAction(){};
	};
	
	class NiepoprawneLogowanieAction : public SecureCommAction
	{
		Model * model;
		
		public:
		NiepoprawneLogowanieAction(Model * model)
		{
			this->model = model;
		};
		int wykonajAkcje(Ekran* ekran, int odp)
		{
			return 2;
		};
		~NiepoprawneLogowanieAction(){};
	};
	
	class PoprawnaRejestracjaAction : public SecureCommAction
	{
		Model * model;
		
		public:
		PoprawnaRejestracjaAction(Model * model)
		{
			this->model = model;
		};
		int wykonajAkcje(Ekran* ekran, int odp)
		{
			return 1;
		};
		~PoprawnaRejestracjaAction(){};
	};
	
	class NiepoprawnaRejestracjaAction : public SecureCommAction
	{
		Model * model;
		
		public:
		NiepoprawnaRejestracjaAction(Model * model)
		{
			this->model = model;
		};
		int wykonajAkcje(Ekran* ekran, int odp)
		{
			return 2;
		};
		~NiepoprawnaRejestracjaAction(){};
	};
	
	class WiadomoscPosredniaAction : public SecureCommAction
	{
		Model * model;
		
		public:
		WiadomoscPosredniaAction(Model * model)
		{
			this->model = model;
		};
		int wykonajAkcje(Ekran* ekran, int odp)
		{
			return odp;
		};
		~WiadomoscPosredniaAction(){};
	};
	
	class ListaZnajomychAction : public SecureCommAction
	{
		Model * model;
		
		public:
		ListaZnajomychAction(Model * model)
		{
			this->model = model;
		};
		int wykonajAkcje(Ekran* ekran, int odp)
		{
			//todo:: wyswietl komunikat oczekuj na enter
			return odp;
		};
		~ListaZnajomychAction(){};
	};
	
	class PoprawneDodanieZnajomego : public SecureCommAction
	{
		Model * model;
		
		public:
		PoprawneDodanieZnajomego(Model * model)
		{
			this->model = model;
		};
		int wykonajAkcje(Ekran* ekran, int odp)
		{
			return 1;
		};
		~PoprawneDodanieZnajomego(){};
	};
	
	class PoprawneWylogowanie : public SecureCommAction
	{
		Model * model;
		
		public:
		PoprawneWylogowanie(Model * model)
		{
			this->model = model;
		};
		int wykonajAkcje(Ekran* ekran, int odp)
		{
			return odp;
		};
		~PoprawneWylogowanie(){};
	};
	
	
	
	class AutoryzacjaKluczemAction : public SecureCommAction
	{
		public:
		AutoryzacjaKluczemAction()
		{
		
		};
		int wykonajAkcje( Ekran* ekran, int odp)
		{
			return odp;
		};
		
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
		int wykonajAkcje( Ekran * ekran, int odp)
		{
			model->dodajKomunikacjeZeZnajomym(((EkranWyboruZnajomego*)ekran)->getIdZnajomego());
			model->setIdOdbiorcy(((EkranWyboruZnajomego*)ekran)->getIdZnajomego());
			
			return odp;
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
		int wykonajAkcje( Ekran * ekran, int odp)
		{
			model->dodajKomunikacjeBezposredniaZeZnajomym(((EkranWyboruZnajomegoBezposrednia*)ekran)->getAdresOdbiorcy());
			model->setAdresOdbiorcy(((EkranWyboruZnajomegoBezposrednia*)ekran)->getAdresOdbiorcy());
			model->utworzPolaczenieBezposrednie();
			
			return odp;
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
		int wykonajAkcje( Ekran* ekran, int odp)
		{
			((EkranKomunikacji*)ekran)->setLoginUzytkownika(model->getLoginUzytkownika());
			((EkranKomunikacji*)ekran)->setLoginZnajomego(model->getIdOdbiorcy());
			model->wyslijWiadomoscPosrednio(WiadomoscPosrednia(model->getIdOdbiorcy(),((EkranKomunikacji*)ekran)->getKomunikat()));
			((EkranKomunikacji*)ekran)->setKomunikat("");
			
			return odp;
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
		int wykonajAkcje( Ekran* ekran,int odp)
		{
			((EkranKomunikacjiBezposredniej*)ekran)->setLoginUzytkownika(model->getLoginUzytkownika());
			((EkranKomunikacjiBezposredniej*)ekran)->setLoginZnajomego(model->getIdOdbiorcy());
			model->wyslijWiadomoscBezposrednio(WiadomoscPosrednia("",((EkranKomunikacjiBezposredniej*)ekran)->getKomunikat()));
			((EkranKomunikacjiBezposredniej*)ekran)->setKomunikat("");
			
			return odp;
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
		int wykonajAkcje( Ekran* ekran, int odp)
		{
			string id = ((EkranDodawaniaKontaktu*)ekran)->getIdZnajomego();
			
			model->wyslijKomunikatDodaniaZnajomego(FriendAdd(id));
			ekran->czyscEkran();
			
			return odp;
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
		int wykonajAkcje( Ekran* ekran, int odp)
		{
			model->wyslijKomunikatWyswietlaniaZnajomych(FriendListRequest());
			ekran->czyscEkran();
			
			return odp;
		};
		
		~WyswietlenieZnajomychAction(){};
	};

class Kontroler
{
	
	private:
	map<string, SecureCommAction*> mapaAkcji;
	map<string, SecureCommAction*>::iterator it;
	
	Model *model;
	BQueue<string> *blockingQueue;
	
	public:
	Kontroler(BQueue<string> *blockingQueue, Model *model);
	~Kontroler();
	
	void petlaAplikacji();
	void wypelnijMapeAkcji();
};



#endif
