
# Ex6 OS

A brief description of what this project does and who it's for

this project is about implementing design patterns 

**implemented patterns**

* Singleton (template singleton)
* Reactor* 
* Guard
* Active Object
* Pipeline

also need to implement a Queue that uses cond when waiting to deQ

**QUEUE implemented methods**

* deQ( );
* enQ( );
* createQ( );
* destroyQ( );

we used c.

now implement the active object using the Queue.

**Active Object implemented methods**

* newAO( );
* destroyAO( );


**Guard implemented methods**

* constructor(pthread_mutex_t );
* destuctor( );

the constructor lock the pthread_mutex_t
and the destructor unlock it.

**Singleton template**

* Instance( );
* Destroy( );


**Reactor implementing**

* newReactor( );
* InstallHandler( );
* RemoveHandler( );


the files will be compiled to shared library















## Run Locally

Clone the project

```bash
  git clone https://github.com/dolev146/ex6_OS_NOTHREADPOOL.git
```

Go to the project directory

```bash
  cd ex6_OS_NOTHREADPOOL
```

Install dependencies

```bash
  sudo apt install build-essential
```

make all the files

```bash
  make
```

to run the first part of the project open a terminal and run

```bash
  ./main1
```

then open a client

```bash
  ./client
```

and send a message and check the output 

if you want to run our test then run

```bash
  ./clienttest
```
it is checking that seperate clients got their own data , and that it is 


after testing the first part ,

now test the singleton by running

```bash
  ./singletontest
```

it will check that the pointers are equal

now test the guard by running

```bash
  ./guardtest
```

it will check that the incremented counter is equal to the amount of incementation
and that the incrementation are more with the guard then without it.

now test the reactor by running

```bash
  ./pollserver
```

then in a diffrent terminal open a new clientlis

```bash
  ./pollclientlis
```

then in a diffrent terminal open another pollclientlis

```bash
  ./pollclientlis
```

then in the last terminal open a clientsend

```bash
  ./pollclientsend
```

and then you should get a message from the clientsend to all of the listeners

using the rector handler , that handle the requests.


