#include "output.hpp"

int printOutput(char filename[], Graph *graph){
	ofstream output(filename);
	
	if (output.is_open()){
		int i;
		output << pathLength(graph->path,graph->length) << endl;
		for(i = 0; i < graph->path->size();i++){
			output << *(graph->path->at(i)->output());
		}
		//output << *(graph->path->at(0)->output());
		output.close();
	}
	else cout << "Unable to open file";
}

int printPlot(char filename[], Graph *graph){
	ofstream output(filename);
	if (output.is_open()){
		int i;
		for(i = 0; i < graph->path->size();i++){
			output << *(graph->path->at(i)->plot());
		}
		output << *(graph->path->at(0)->plot());
		output.close();
	}
	else cout << "Unable to open file";
}
/*
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
}*/
