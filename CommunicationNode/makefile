#COMP := clang++
#clang na linuksie ma bug w muteksach
COMP := g++
CFLAGS := -I../ -std=c++11 -pthread
LFLAGS :=

all: client server

client: Sender.cpp client.cpp ../Komunikaty/Komunikat.cpp
	$(COMP) $(CFLAGS) Sender.cpp client.cpp ../Komunikaty/Komunikat.cpp -o client.app

server: Listener.cpp server.cpp
	$(COMP) $(CFLAGS) Listener.cpp server.cpp -o server.app

node: Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node.cpp
	$(COMP) $(CFLAGS) Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node.cpp -o node.app
