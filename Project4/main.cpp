#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "types.hpp"
using namespace std;

int readInFile(char filename[], Graph *g);

int main(int argc, char **argv){
	Graph *g = new Graph();
  readInFile(argv[1], g);
}

