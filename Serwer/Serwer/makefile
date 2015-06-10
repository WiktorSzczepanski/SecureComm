#COMP := clang++
#clang na linuksie ma bug w muteksach
COMP := g++
CFLAGS := -I../ -std=c++11 -pthread
LFLAGS :=

serwer: main.cpp User.cpp BazaDanych.cpp
	$(COMP) $(CFLAGS) main.cpp User.cpp BazaDanych.cpp -o serwer.app

node2: Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node2.cpp
	$(COMP) $(CFLAGS) Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node2.cpp -o node2.app

karo: Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp nodeK.cpp
	$(COMP) $(CFLAGS) Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp nodeK.cpp -o nodeK.app
