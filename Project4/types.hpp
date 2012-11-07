#include <iostream>
#include <vector>

class City {
public:
  std::string id;
  int x;
  int y;
  City *next;
  City *prev;
  City(char *id_new, int x_new, int y_new);
  void print();
	void plot();
};
