COMP := clang++
CFLAGS :=
LFLAGS :=

client: Sender.cpp client.cpp
	$(COMP) $(CFLAGS) Sender.cpp client.cpp -o client.app

server: Listener.cpp server.cpp
	$(COMP) $(CFLAGS) Listener.cpp server.cpp -o server.app

