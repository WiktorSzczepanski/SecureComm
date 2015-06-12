#COMP := clang++
#clang na linuksie ma bug w muteksach
COMP := g++
CFLAGS := -I./ -std=c++11 -pthread
#CFLAGS := $(LFLAGS) -c

#OBJDIR := obj
BINDIR := bin


COMM_NODE_FILES := CommunicationNode/CommunicationNode.cpp CommunicationNode/Sender.cpp CommunicationNode/Listener.cpp Komunikaty/Komunikat.cpp
DEC_NODE_FILES := DeclarativeNode/State.cpp DeclarativeNode/DeclarativeNode.cpp $(COMM_NODE_FILES)
BASIC_TEST_FILES := BasicTest/WaitingState.cpp BasicTest/IdleState.cpp $(DEC_NODE_FILES)

test: node1 node2 

btest : bnode1 bnode2

node1: $(COMM_NODE_FILES) CommunicationNode/node1.cpp
	$(COMP) $(CFLAGS) $(COMM_NODE_FILES) CommunicationNode/node1.cpp -o $(BINDIR)/node1.app

node2: $(COMM_NODE_FILES) CommunicationNode/node2.cpp
	$(COMP) $(CFLAGS) $(COMM_NODE_FILES) CommunicationNode/node2.cpp -o $(BINDIR)/node2.app

#node1: Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node1.cpp
#	$(COMP) $(CFLAGS) Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node1.cpp -o node1.app
#
#node2: Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node2.cpp
#	$(COMP) $(CFLAGS) Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp node2.cpp -o node2.app

karo: Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp nodeK.cpp
	$(COMP) $(CFLAGS) Sender.cpp Listener.cpp ../Komunikaty/Komunikat.cpp CommunicationNode.cpp nodeK.cpp -o nodeK.app

#basicTest: basicTest.o $(OBJDIR)/basicTestMain.o $(OBJDIR)/komunikaty.o
#	$(COMP) $(CFLAGS) $(OBJDIR)/basicTest.o $(OBJDIR)/basicTestMain.o $(OBJDIR)/komunikaty.o -o $(BINDIR)/basicTest.app
#
#basicTest.o: BasicTest/WaitingState.cpp BasicTest/IdleState.cpp DeclarativeNode/State.cpp 
#	$(COMP) $(CFLAGS) BasicTest/WaitingState.cpp BasicTest/IdleState.cpp DeclarativeNode/State.cpp -o $(OBJDIR)/basicTest.o
#
#basicTestMain.o: BasicTest/main.cpp
#	$(COMP) $(CFLAGS) BasicTest/main.cpp -o $(OBJDIR)/basicTestMain.o
#
#komunikaty.o : Komunikaty/Komunikat.cpp
#	$(COMP) $(CFLAGS) Komunikaty/Komunikat.cpp -o $(OBJDIR)/komunikaty.o

bnode1 : $(BASIC_TEST_FILES) BasicTest/node1.cpp
	$(COMP) $(CFLAGS) $(BASIC_TEST_FILES) BasicTest/node1.cpp -o $(BINDIR)/bnode1.app

bnode2 : $(BASIC_TEST_FILES) BasicTest/node2.cpp
	$(COMP) $(CFLAGS) $(BASIC_TEST_FILES) BasicTest/node2.cpp -o $(BINDIR)/bnode2.app

silly : $(BASIC_TEST_FILES) BasicTest/main.cpp
	$(COMP) $(CFLAGS) $(BASIC_TEST_FILES) BasicTest/main.cpp -o $(BINDIR)/silly.app

