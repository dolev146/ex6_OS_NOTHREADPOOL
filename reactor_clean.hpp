#ifndef Reactor_Clean_HPP
#define Reactor_Clean_HPP

// g++ reactor_clean.hpp -o reactor_clean

class Reactor
{
private:
    /* data */
public:
    Reactor(/* args */);
    ~Reactor();
};

void *newReactor();
void InstallHandler(Reactor *reactor, void (*handler)(void *), int filedescriptor);
void RemoveHandler(Reactor *reactor, int filedescriptor);


#endif // Reactor_Clean_HPP