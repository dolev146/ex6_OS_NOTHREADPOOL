#ifndef Reactor_Clean_HPP
#define Reactor_Clean_HPP
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <mutex>
#include <thread>

using namespace std;
// g++ reactor_clean.hpp -o reactor_clean -std=c++2a -Wall -Wextra -Werror -pedantic -O3 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
// http://www.kegel.com/c10k.html

class Reactor
{
private:
    /* data */

public:
    /* data */
    int filedescriptor;
    std::thread m_member_thread;
    void (*funcpointer)(void *);
    Reactor(/* args */);
    ~Reactor();
};

void *newReactor();
void InstallHandler(Reactor *reactor, void (*funcpointer_param)(void *), int filedescriptor);
void RemoveHandler(Reactor *reactor, int filedescriptor);

#endif // Reactor_Clean_HPP