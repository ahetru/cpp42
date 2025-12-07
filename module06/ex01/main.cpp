#include "Data.hpp"
#include "Serializer.hpp"
#include <stdint.h>

void printData(Data data)
{
    std::cout << "Data.intType: " << data.intType << std::endl;
    std::cout << "Data.floatType: " << data.floatType << std::endl;
    std::cout << "Data.charType: " << data.charType << std::endl;
    std::cout << "Data.stringType: " << data.stringType << std::endl;
    std::cout << "===================================================\n";
}

int main(void)
{

    Data data;
    data.intType = 42;
    data.floatType = 42.0f;
    data.charType = 42;
    data.stringType = "42";

    printData(data);
    uintptr_t serialized = Serializer::serialize(&data);
    Data *deserialized = Serializer::deserialize(serialized);
    printData(*deserialized);

    return 0;
}
