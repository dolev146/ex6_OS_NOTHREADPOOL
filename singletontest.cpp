
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
#include "singleton.cpp"
#include "assert.h"

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
class Test final : public Singleton<Test>
{
public:
    


    Test(token)
    {
        std::cout << "constructed" << std::endl;
    }
    ~Test()
    { 
        std::cout << "destructed" << std::endl;
    }
    void use() const
    {
        std::cout << "in use " << this << std::endl;
    };
};

int main()
{
    void *p1;
    void *p2;
    std::cout << "Entering main()" << std::endl;
    {
        auto const &t = Test::Instance();
        t.use();
        p1 = (void *)&t;
    }
    {
        auto const &t = Test::Instance();
        t.use();
        p2 = (void *)&t;
    }

    assert(p1 == p2);

    // this line will call destroy but in the end of the main function
    // the destructor is also called
    // so double free will be raised
    // Test::Destroy();

    std::cout << "Leaving main()" << std::endl;
}