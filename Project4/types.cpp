#include <iostream>
#include <vector>
class City {
	std::string id;
	int x;
	int y;
	City *next;
	City *prev;
}
class Graph {
	vector<City> cities;
	unsigned int path_size;
	
}
