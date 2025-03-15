#include "Serializer.hpp"

int main()
{
    Data original('A', 1337, 3.14, 42);

    uintptr_t serialized = Serializer::serialize(&original);

    Data *deserialized = Serializer::deserialize(serialized);

    if (deserialized == &original)
        std::cout << "Serialization and deserialization successful! The pointers match." << std::endl;
    else {
        std::cout << "Error: The pointers do not match!" << std::endl;
        return 1;
    }
    
    std::cout<<"Original Data: \n"<<"Adress: "<<&original<<"\nValue: "<<original.c<<", "<<original.i<<", "<<original.f<<", "<<original.d<<std::endl;
    std::cout<<"\ndeserialized Data: \n"<<"Adress: "<<deserialized<<"\nValue: "<<deserialized->c<<", "<<deserialized->i<<", "<<deserialized->f<<", "<<deserialized->d<<std::endl;
    return 0;
}