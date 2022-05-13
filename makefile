CC=g++
CFlags=-g -Wall -lpthread -std=c++2a
Main1OBJ=main1.o myqueue.o blockqueue.o myActiveObject.o Pipeline.o
all:clean clienttest client main1 guard singleton reactor

reactor:reactor.o pollserver.o pollclient pollclientsend
	g++ -o reactor reactor.o pollserver.o -lpthread

pollclientsend: pollclientsend.cpp
	$(CC) $(CFlags) -o pollclientsend pollclientsend.cpp -lpthread


pollclient:pollclientlis.cpp
	$(CC) $(CFlags) pollclientlis.cpp -o pollclientlis -lpthread


reactor.o:reactor.hpp
	$(CC) $(CFlags) -c reactor.cpp -o reactor.o

pollserver.o:reactor.hpp
	$(CC) $(CFlags) -c pollserver.cpp -o pollserver.o


singleton:
	$(CC) -o singleton singleton.cpp $(CFlags)

guard:guard.cpp
	$(CC) $(CFlags) -o guard guard.cpp -lpthread 

main1: $(Main1OBJ)
	$(CC) $(CFlags) -o $@  $^ -lpthread; 

clienttest: clienttest.o
	$(CC) $(CFlags) -o $@  $^ -lpthread

client: client.o
	$(CC) $(CFlags) -o $@  $^ -lpthread

%: %.c
	$(CC) $(CFlags) -c -o $@  $^ -lpthread

%: %.cpp
	$(CC) $(CFlags) -c -o $@  $^ -lpthread

clean:
	rm -f *.dSYM $(BINS) *.o client clienttest guard singleton reactor reactor1 pollclientlis pollclientsend