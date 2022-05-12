#include "reactor_clean.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

void *newReactor()
{
    Reactor *reactor = new Reactor();
    return reactor;
}

void InstallHandler(Reactor *reactor, void (*funcpointer_param)(void *), int filedescriptor)
{
    reactor->funcpointer = funcpointer_param;
    reactor->filedescriptor = filedescriptor;
    reactor->m_member_thread = std::thread(funcpointer_param, reactor);

}

void RemoveHandler(Reactor *reactor, int filedescriptor)
{
    reactor->m_member_thread.join();
    reactor->filedescriptor = -1;
    reactor->funcpointer = NULL;
}