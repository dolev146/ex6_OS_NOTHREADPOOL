all:clean client clienttest pollclientsend pollclientlis buildOfiles buildshared main1.o pollserver.o main1 pollserver guardtest.o guardtest singletontest

buildOfiles:
	g++ -fpic -c -Wall myqueue.c myActiveObject.c Pipeline.c blockqueue.c reactor.cpp guard.cpp singleton.cpp -lpthread

buildshared:
	g++ -o libex6.so myqueue.o myActiveObject.o Pipeline.o blockqueue.o reactor.o guard.o singleton.o -fpic -shared  -lpthread

main1.o:
	g++ -o main1.o main1.c -c -lpthread

main1:
	g++ -o main1 main1.o ./libex6.so -lpthread

pollclientsend:
	g++ -o pollclientsend pollclientsend.cpp -lpthread

pollclientlis:
	g++ -o pollclientlis pollclientlis.cpp -lpthread

pollserver.o:
	g++ -o pollserver.o -c pollserver.cpp -lpthread 

pollserver:
	g++ -o pollserver pollserver.o ./libex6.so -lpthread

guardtest.o:
	g++ -o guardtest.o -c guardtest.cpp -lpthread

guardtest:
	g++ -o guardtest guardtest.o ./libex6.so -lpthread

singleton.o:
	g++ -o singleton.o -c singletontest.cpp -lpthread

singleton:
	g++ -o singleton singleton.o ./libex6.so -lpthread

clienttest:
	g++ -g -Wall -o clienttest clienttest.c -lpthread

client:
	g++ -g -Wall -o client client.c -lpthread

clean:
	rm -f client clienttest pipeline Pipeline myqueue myActiveObject blockedq *.o *.so main1 libmath.so.1.2.3 pollclientlis pollclientsend pollserver

