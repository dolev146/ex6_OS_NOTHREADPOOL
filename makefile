CC=g++
CFlags=-g -Wall
BINS=main1
Main1OBJ=main1.o myqueue.o blockqueue.o myActiveObject.o Pipeline.o

all:clean clienttest client $(BINS) main1 guard

guard:guard.cpp
	$(CC) $(CFlags) -o guard guard.cpp -lpthread 

main1: $(Main1OBJ)
	$(CC) $(CFlags) -o $@  $^ -lpthread ; 

clienttest: clienttest.o
	$(CC) $(CFlags) -o $@  $^ -lpthread

client: client.o
	$(CC) $(CFlags) -o $@  $^ -lpthread

%: %.c
	$(CC) $(CFlags) -c -o $@  $^ -lpthread

%: %.cpp
	$(CC) $(CFlags) -c -o $@  $^ -lpthread

clean:
	rm -f *.dSYM $(BINS) *.o client clienttest guard