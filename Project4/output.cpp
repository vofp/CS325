#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "types.hpp"

int printOutput(char filename[], Graph *graph){
	ofstream output(filename);
  if (output.is_open()){
		vector<City>::iterator it;
		for ( it = graph->cities.begin() ; it < graph->cities.end(); it++ ){
			output << *(it->output());
		}
    output.close();
  }
  else cout << "Unable to open file";
}

int printPlot(char filename[], Graph *graph){
  ofstream output(filename);
  if (output.is_open()){
    vector<City>::iterator it;
    for ( it = graph->cities.begin() ; it < graph->cities.end(); it++ ){
      output << *(it->plot());
    }
    output.close();
  }
  else cout << "Unable to open file";
}

int printPlotPath(char filename[], Graph *graph){
  ofstream output(filename);
  if (output.is_open()){
		City *front = &(graph->cities.front());
		output << *(front->plot());
		City *current = front->next;
		while(front != current){
			output << *(current->plot());
			current = current->next;
		}
		output << *(current->plot());
    output.close();
  }
  else cout << "Unable to open file";
}
