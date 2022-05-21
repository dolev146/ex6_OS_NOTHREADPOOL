all:clean client clienttest pollclientsend pollclientlis buildOfiles buildshared main1.o pollserver.o main1 pollserver guardtest.o guardtest singletontest.o singletontest

buildOfiles:
	g++ -g -fpic -c -Wall myqueue.c myActiveObject.c Pipeline.c blockqueue.c reactor.cpp guard.cpp singleton.cpp -lpthread

buildshared:
	g++ -g -o libex6.so myqueue.o myActiveObject.o Pipeline.o blockqueue.o reactor.o guard.o singleton.o -fpic -shared  -lpthread

main1.o:
	g++ -g -o main1.o main1.c -c -lpthread

main1:
	g++ -o main1 main1.o ./libex6.so -lpthread -g

pollclientsend:
	g++ -o pollclientsend pollclientsend.cpp -lpthread -g

pollclientlis:
	g++ -o pollclientlis pollclientlis.cpp -lpthread -g

pollserver.o:
	g++ -o pollserver.o -c pollserver.cpp -lpthread -g

pollserver:
	g++ -o pollserver pollserver.o ./libex6.so -lpthread -g

guardtest.o:
	g++ -o guardtest.o -c guardtest.cpp -lpthread -g

guardtest:
	g++ -o guardtest guardtest.o ./libex6.so -lpthread -g

singletontest.o:
	g++ -o singletontest.o -c singletontest.cpp -lpthread -g

singletontest:
	g++ -o singletontest singletontest.o ./libex6.so -lpthread -g

clienttest:
	g++ -g -Wall -o clienttest clienttest.c -lpthread -g

client:
	g++ -g -Wall -o client client.c -lpthread -g

clean:
	rm -f client clienttest pipeline Pipeline myqueue myActiveObject blockedq *.o *.so main1 libmath.so.1.2.3 pollclientlis pollclientsend pollserver guardtest singletontest singleton

