// question 6
// The type of a handle is system specific
// this example


class Reactor
{
private:
    /* data */
public:
    Reactor(/* args */);
    ~Reactor();
};

Reactor::Reactor(/* args */)
{
}

Reactor::~Reactor()
{
}

void *newReactor()
{
    return new Reactor();
}

void InstallHandler(Reactor *reactor, void (*handler)(void *), int filedescriptor)
{
    // install the handler to the file descriptor
    // of the reactor
    reactor->Register(handler, filedescriptor);
}

void RemoverHandler(Reactor *reactor, int filedescriptor)
{
    // remove the handler from the file descriptor
    // of the reactor
    reactor->Unregister(filedescriptor);
}
