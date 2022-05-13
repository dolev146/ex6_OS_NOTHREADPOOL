#include "reactor.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>



void *newReactor()
{
    Reactor *reactor = new Reactor();
    return reactor;
}

void InstallHandler(Reactor *reactor, void *(*funcpointer_param)(void *), int filedescriptor)
{
    reactor->funcpointer = funcpointer_param;
    reactor->filedescriptor = filedescriptor;
    // argsparam
    args_params *args = new args_params();
    args->filedescriptor = filedescriptor;
    args->reactor = reactor;

    pthread_create(&reactor->m_member_thread, NULL, funcpointer_param, (void *)args);
    // reactor->m_member_thread = std::thread(funcpointer_param, reactor);
    // reactor->m_member_thread = std::thread(reactor->funcpointer);
}

void RemoveHandler(Reactor *reactor, int filedescriptor)
{
    // join thread
    pthread_join(reactor->m_member_thread, NULL);

    // reactor->m_member_thread.join();
    reactor->filedescriptor = -1;
    reactor->funcpointer = NULL;
}