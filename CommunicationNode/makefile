#COMP := clang++
#clang na linuksie ma bug w muteksach
COMP := g++
CFLAGS := -I../ -std=c++11 -pthread
LFLAGS :=

test: node1 node2 

node1: Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node1.cpp
	$(COMP) $(CFLAGS) Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node1.cpp -o node1.app

node2: Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node2.cpp
	$(COMP) $(CFLAGS) Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node2.cpp -o node2.app
