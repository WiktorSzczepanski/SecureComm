COMP := clang++
CFLAGS := -I../
LFLAGS :=

client: Sender.cpp client.cpp ../Komunikaty/Komunikat.cpp
	$(COMP) $(CFLAGS) Sender.cpp client.cpp ../Komunikaty/Komunikat.cpp -o client.app

server: Listener.cpp server.cpp
	$(COMP) $(CFLAGS) Listener.cpp server.cpp -o server.app

