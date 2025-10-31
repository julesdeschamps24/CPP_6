#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

class Base 
{
    public:
        virtual ~Base();

};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);