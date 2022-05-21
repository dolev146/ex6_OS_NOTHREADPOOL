
#include <iostream>
#include <string>
#include <cstring>
#include "pthread.h"
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

