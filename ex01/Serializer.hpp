#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

struct Data {
    std::string name;
    int grade;
};

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};