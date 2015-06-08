COMP := g++
CFLAGS := -I../ -std=c++11 -pthread
LFLAGS :=

klient: ../CommunicationNode/Sender.cpp ../CommunicationNode/Listener.cpp main.cpp kontroler.cpp widok.cpp model.cpp ../Komunikaty/Komunikat.cpp ../CommunicationNode/CommunicationNode.cpp
	$(COMP) $(CFLAGS) ../CommunicationNode/Sender.cpp ../CommunicationNode/Listener.cpp main.cpp kontroler.cpp widok.cpp model.cpp  ../Komunikaty/Komunikat.cpp ../Komunikaty/LoginRequest.cpp ../Komunikaty/FriendListRequest.cpp ../Komunikaty/FriendAdd.cpp ../Komunikaty/RegistrationRequest.cpp ../Komunikaty/Wiadomosc.cpp ../Komunikaty/WiadomoscPosrednia.cpp ../Komunikaty/LogOut.cpp ../Komunikaty/ZapytanieDostepnosc.cpp ../Komunikaty/FriendSeek.cpp  ../CommunicationNode/CommunicationNode.cpp -o klient.app

