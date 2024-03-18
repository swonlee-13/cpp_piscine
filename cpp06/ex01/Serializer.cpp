#include "Serializer.hpp"

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) {
	uintptr_t res = reinterpret_cast<uintptr_t>(ptr);
	return res;
}

Data *Serializer::deSerialize(uintptr_t raw) {
	Data *res = reinterpret_cast<Data *>(raw);
	return res;
}