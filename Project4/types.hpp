#include <iostream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>

class City {
public:
  std::string id;
  int x;
  int y;
  City *next;
  City *prev;
  City(char *id_new, int x_new, int y_new);
  void output();
	void plot();
};

class Graph {
public:
  std::vector<City> cities;
  unsigned int path_size;

};

