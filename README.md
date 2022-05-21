
## Authors

- [@Dolev Dublon, ID: 207867342](https://www.github.com/dolev146)
- [@Yakov Khodorkovsky, ID: 207045063 ](https://www.github.com/yakov103)
- 
# Ex6 OS

A brief description of what this project does and who it's for

![image]()
[![IMAGE ALT TEXT HERE](https://user-images.githubusercontent.com/62290677/169662935-c8e019cc-17ef-4984-8ce0-792a7ede9096.png)](https://www.youtube.com/watch?v=dRJ1sNYKU78)

this project is about implementing design patterns 

**implemented patterns**

* [Singleton](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/singleton.cpp)](Singleton template)
* [Reactor](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/reactor.hpp)
* [Guard](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/guard.cpp)
* [Active Object](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/myActiveObject.h)
* [Pipeline](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/Pipeline.h)

also need to implement a Queue that uses cond when waiting to deQ

**QUEUE implemented methods**

* [deQ( );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/blockqueue.c#L22)
* [enQ( );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/blockqueue.c#L22)
* [createQ( );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/blockqueue.c#L39)
* [destroyQ( );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/blockqueue.c#L47)

we used c.

now implement the active object using the Queue.

**Active Object implemented methods**

* [newAO( );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/myActiveObject.c#L12)
* [destroyAO( );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/myActiveObject.c#L12)


**Guard implemented methods**

* [constructor(pthread_mutex_t );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/guard.cpp#L10)
* [destuctor( );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/guard.cpp#L15)

the constructor lock the pthread_mutex_t
and the destructor unlock it.

**Singleton template**

* [Instance( );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/singleton.cpp#L35)
* [Destroy( );]()


**Reactor implementing**

* [newReactor( );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/reactor.cpp#L12)
* [InstallHandler( );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/reactor.cpp#L18)
* [RemoveHandler( );](https://github.com/dolev146/ex6_OS_NOTHREADPOOL/blob/main/reactor.cpp#L32)


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


