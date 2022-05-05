// question 5
// https://refactoring.guru/design-patterns/singleton/cpp/example#example-1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <thread>
#include <chrono>

// /**
//  * The Singleton class defines the `GetInstance` method that serves as an
//  * alternative to constructor and lets clients access the same instance of this
//  * class over and over.
//  */
// template <typename T>
// class Singleton
// {

//     /**
//      * The Singleton's constructor/destructor should always be private to
//      * prevent direct construction/desctruction calls with the `new`/`delete`
//      * operator.
//      */
// private:
//     static Singleton *pinstance_;
//     static std::mutex mutex_;

// protected:
//     Singleton(const T value) : value_(value)
//     {
//     }
//     ~Singleton() {}
//     T value_;

// public:
//     /**
//      * Singletons should not be cloneable.
//      */
//     Singleton(Singleton &other) = delete;
//     /**
//      * Singletons should not be assignable.
//      */
//     void operator=(const Singleton &) = delete;
//     /**
//      * This is the static method that controls the access to the singleton
//      * instance. On the first run, it creates a singleton object and places it
//      * into the static field. On subsequent runs, it returns the client existing
//      * object stored in the static field.
//      */

//     static Singleton *GetInstance(T value)
//     {
//         std::lock_guard<std::mutex> lock(mutex_);
//         if (pinstance_ == nullptr)
//         {
//             pinstance_ = new Singleton(value);
//         }
//         return pinstance_;
//     }
//     /**
//      * Finally, any singleton should define some business logic, which can be
//      * executed on its instance.
//      */
//     void SomeBusinessLogic()
//     {
//         // ...
//     }

//     T value() const
//     {
//         return value_;
//     }

//     static Singleton *Singleton::pinstance_{nullptr};
//     static std::mutex Singleton::mutex_;
// };

// /**
//  * Static methods should be defined outside the class.
//  */
// // template <typename T>

// // template <class T>

// /**
//  * The first time we call GetInstance we will lock the storage location
//  *      and then we make sure again that the variable is null and then we
//  *      set the value. RU:
//  */
// g++ -o singleton singleton.cpp

std::mutex guard_mutex;

template <class T>
class Singleton
{
    // private static Singleton obj;
private:
    static Singleton *pinstance_;
    T value;
    Singleton(T a)
    {
        value = a;
    }

public:
    void print()
    {
        std::cout << value << std::endl;
    }

    static Singleton *GetInstance(T value)
    {
        if (pinstance_ == NULL)
        {
            std::lock_guard<std::mutex> lock(guard_mutex);
            if (pinstance_ == NULL)
            {
                pinstance_ = new Singleton(value);
            }
        }
        return pinstance_;
    }
};


void ThreadFoo()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton<std::string> *singleton = Singleton<std::string>::GetInstance("FOO");
    singleton->print();
}

void ThreadBar()
{
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton<std::string> *singleton = Singleton<std::string>::GetInstance("BAR");
    singleton->print();
}

int main()
{
    std::cout << "If you see the same value, then singleton was reused (yay!\n"
              << "If you see different values, then 2 singletons were created (booo!!)\n\n"
              << "RESULT:\n";
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; i++)
    {
        if ((i % 2) == 0)
        {
            // threads.push_back(std::thread(ThreadFoo));
        }
        else
        {
            threads.push_back(std::thread(ThreadBar));
        }
    }

    for (int i = 0; i < 4; i++)
    {
        threads[i].join();
    }

    return 0;
}