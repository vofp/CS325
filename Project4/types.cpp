/*#include <iostream>
#include <vector>*/
#include "types.hpp"
using namespace std;

/*class City {
  std::string id;
  int x;
  int y;
  City *next;
  City *prev;
  City(char *id_new, int x_new, int y_new);
  void print();
};*/


City::City(char *id_new, int x_new, int y_new){
	id = id_new;
	x = x_new;
	y = y_new;
}
void City::print(){
	cout << id << ": (" << x << ", " << y << ")" << endl;
}

void City::plot(){
	cout << x << ", " << y << endl;
}

class Graph {
	vector<City> cities;
	unsigned int path_size;
	
};
