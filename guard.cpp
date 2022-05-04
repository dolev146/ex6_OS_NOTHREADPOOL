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

// buld a program that implements a guard design pattern
// the guard should be able to:
// 1. only allow one thread to enter a function and update a global pointer
// does it possible to use a guard like this to protect strtok
// instead of strtok_r
// write the  answer in comments:
// 1. yes
// 2. no

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

/*****
 *
 * Example1:
 * here we have a global pointer that is only updated by one thread
 * the other threads will try to update the pointer but will fail
 * because the pointer is already updated by another thread
 * they will wait untill the other thread updates the pointer
 * and only when finished they will be able to update the pointer
 * using a scoped_lock or a lock_guard
 *
 *****/

void *global_pointer;
static int shared_value = 0;
std::mutex guard_mutex;

void *update_global_pointer()
{

    /*
        we can use a scoped_lock to protect the global pointer or we can use a lock_guard
         std::scoped_lock lockGuard(guard_mutex);
    */

    // Code that belong to Example1
    std::lock_guard<std::mutex> lockGuard(guard_mutex);
    void *local_pointer = (void *)malloc(sizeof(int));
    global_pointer = local_pointer;
    shared_value = shared_value + 1;

    

    return global_pointer;
}

int main()
{
    std::cout << "global_pointer: " << global_pointer << std::endl;
    std::cout << "shared_value: " << shared_value << std::endl;
    std::vector<std::thread> threads;
    for (int i = 0; i < 1000; i++)
    {
        threads.push_back(std::thread(update_global_pointer));
    }

    for (int i = 0; i < 1000; i++)
    {
        threads[i].join();
    }
    std::cout << "after join" << std::endl;
    std::cout << "global_pointer: " << global_pointer << std::endl;
    std::cout << "shared_value: " << shared_value << std::endl;
}