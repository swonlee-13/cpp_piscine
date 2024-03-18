#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data t_data;

	std::cout << "original address :         " << std::hex << &t_data << std::endl;
	
	uintptr_t temp = Serializer::serialize(&t_data);
	std::cout << "after calling serialize:   0x" << std::hex << temp << std::endl;

	Data *ptr;
	ptr = Serializer::deSerialize(temp);
	std::cout << "after calling deSerialize: " << ptr << std::endl;
}