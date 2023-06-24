#include "Serialization.hpp"
#include <iostream>

int main()
{
	Data byahn;

	byahn.name = "byahn";
	byahn.height = 190;
	byahn.job = "student";

	uintptr_t up = serialize(&byahn);
	std::cout << "serialized: " << up << std::endl;

	Data *data = deserialize(up);
	std::cout << data->name << ", " << data->height << ", " << data->job << std::endl;

	return 0;
}