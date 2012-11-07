#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "types.hpp"

void printOutput(char filename[], Graph *graph){
	ofstream output(filename);
  if (output.is_open()){
		output <<  
    output.close();
  }
  else cout << "Unable to open file";
}
