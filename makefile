COMP := g++
CFLAGS := -I../ -std=c++11 -pthread
LFLAGS :=

majn: Sender.cpp Listener.cpp main.cpp kontroler.cpp widok.cpp model.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp
	$(COMP) $(CFLAGS) Sender.cpp Listener.cpp main.cpp kontroler.cpp widok.cpp model.cpp  ../Komunikaty/Komunikat.cpp ../Komunikaty/LoginRequest.cpp ../Komunikaty/FriendListRequest.cpp ../Komunikaty/FriendAdd.cpp ../Komunikaty/RegistrationRequest.cpp  CommunicationNode.cpp -o majn.app
