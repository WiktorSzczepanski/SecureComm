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
		virtual void wykonajAkcje( Ekran* ekran){};
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
	
	class KomunikacjaAction : public SecureCommAction
	{
		public:
		KomunikacjaAction()
		{
		
		};
		void wykonajAkcje( Ekran* ekran){};
		
		~KomunikacjaAction(){};
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
