#include "Serializer.hpp"

int main(void)
{
    Data data;

    data.name = "Jules";
    data.grade = 100;

    uintptr_t ptr = Serializer::serialize(&data);
    Data* data_ptr = Serializer::deserialize(ptr);

    std::cout << "Original adress: "<<&data << std::endl;
    std::cout << "Deserialized adress: "<< data_ptr << "\n" << std::endl;
    std::cout << data_ptr->name << " got " << data_ptr->grade << " on his last exam" << std::endl;
}