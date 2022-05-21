// question 5
// https://refactoring.guru/design-patterns/singleton/cpp/example#example-1
// https://stackoverflow.com/questions/72132929/how-to-test-a-singleton-generic-template-to-be-thread-safe
// https://codereview.stackexchange.com/questions/173929/modern-c-singleton-template
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>
#include <memory>

/************
 * Singleton template implementation
 *
 *  brief : Singleton template implementation for singleton class with generic type T and with mutex lock for thread safety
 * functions : getInstance() - returns the singleton instance of the class and creates it if it doesn't exist yet
 * Destructor : ~Singleton() - destructor for the singleton class
 * test this class with main()
 * use valgrind to run the test
 * $$$$_____Compile____$$$$
 * first compile the program with
 * g++ -std=c++2a singleton.cpp -o singleton
 * then run the program with
 * $$$$_____Valgrind____$$$$
 * valgrind --leak-check=full --show-leak-kinds=all ./singleton
 *
 * ****************/
template <typename T>
class Singleton
{
public:
    static T &Instance();
    void Destroy();
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton) = delete;

protected:
    struct token
    {
    };
    Singleton() {}
};

template <typename T>
T &Singleton<T>::Instance()
{
    static const std::unique_ptr<T> instance{new T{token{}}};
    return *instance;
}

template <typename T>
void Singleton<T>::Destroy()
{
    delete &Instance();
}


