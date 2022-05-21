// question 4
// https://rules.sonarsource.com/cpp/RSPEC-5999
// https://www.youtube.com/watch?v=KrdNNOLi21E
// https://www.youtube.com/watch?v=_2rNPXAYa0E
// https://www.youtube.com/watch?v=Zp17-UDKM90
// https://www.youtube.com/watch?v=wg3td0Dz5hw
// https://www.youtube.com/watch?v=sXXU4a6z3kE
// https://stackoverflow.com/questions/59966836/stdscoped-lock-behaviour-with-a-single-mutex
// https://stackoverflow.com/questions/69369380/stdscoped-lock-and-mutex-ordering
// https://stackoverflow.com/questions/67356331/scoped-lock-with-repeating-arguments
// https://en.cppreference.com/w/cpp/thread/lock_guard
// https://www.youtube.com/watch?v=_2rNPXAYa0E
// https://en.wikipedia.org/wiki/C10k_problem
// buld a program that implements a guard design pattern
// the guard should be able to:
// 1. only allow one thread to enter a function and update a global pointer
// does it possible to use a guard like this to protect strtok
// instead of strtok_r
// write the  answer in comments:
// 1. NO
// it is not possible to use a guard to protect strtok
// because if a the threads can enter the function in a different order then
// exptected and it can cause a output that is not as expected
// link to explenation
// https://stackoverflow.com/questions/20820937/strtok-function-and-multithreading

#include "pthread.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>

class Guard
{
public:
    pthread_mutex_t *m_mutex;
    Guard(pthread_mutex_t *m_mutex)
    {
        this->m_mutex = m_mutex;
        pthread_mutex_lock(this->m_mutex);
    }
    ~Guard()
    {
        pthread_mutex_unlock(this->m_mutex);
    }
};

/*****
 * took the example from here
 * https://www.youtube.com/watch?v=oq29KUy29iQ&t=473s
 * Example:
 * here we have a global pointer that is only updated by one thread
 * the other threads will try to update the pointer but will fail
 * because the pointer is already updated by another thread
 * they will wait untill the other thread updates the pointer
 * and only when finished they will be able to update the pointer
 * using a scoped_lock or a lock_guard
 *
 *****/

void *global_pointer;
int shared_value = 0;
// TODO , decide if static or not
// static int shared_value = 0;
std::mutex guard_mutex;

pthread_mutex_t C_lang_guard_mutex = PTHREAD_MUTEX_INITIALIZER;

void *update_global_pointer(void *arg)
{

    /*
        we can use a scoped_lock to protect the global pointer or we can use a lock_guard
         std::scoped_lock lockGuard(guard_mutex);
    */

    // Code that belong to Example
    // std::lock_guard<std::mutex> lockGuard(guard_mutex);

    Guard myguard = Guard(&C_lang_guard_mutex);
    for (int m = 0; m < 1000000; m++)
    {
        shared_value++;
    }
    int b = *(int *)arg;
    b++;
    void *local_pointer = (void *)malloc(sizeof(int));
    global_pointer = local_pointer;
    return global_pointer;
}

int main()
{
    // compile the code
    // g++ -std=c++2a -Wall -Wextra -Werror  -pthread  guard.cpp -o guard ; ./guard
    std::cout << "global_pointer: " << global_pointer << std::endl;
    std::cout << "shared_value: " << shared_value << std::endl;
    pthread_t th[4];
    int i = 0;
    int x = 0;
    for (i = 0; i < 4; i++)
    {
        pthread_create(&th[i], NULL, update_global_pointer, &x);
    }
    for (i = 0; i < 4; i++)
    {
        pthread_join(th[i], NULL);
    }
    std::cout << "after join" << std::endl;
    std::cout << "global_pointer: " << global_pointer << std::endl;
    std::cout << "shared_value: " << shared_value << std::endl;
}