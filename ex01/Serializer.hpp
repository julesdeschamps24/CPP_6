#pragma once

#include <stdint.h>
#include <string>
#include <iostream>

typedef unsigned long uintptr_t;

struct Data {
    std::string name;
    int grade;
};

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private: 
        Serializer();
        Serializer(const Serializer& copy);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
};
