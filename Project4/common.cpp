#include "common.hpp"

int pathLength(vector<City *> *path, vector<int> *length){
	int i;
	int sum = 0;
	length->clear();
	for(i=0;i<path->size()-1;i++){
		int d = distance(path->at(i),path->at(i+1));
		sum += d;
		length->push_back(d);
	}
	int d = distance(path->at(path->size()-1),path->at(0));
	sum += d;
	length->push_back(d);
	return sum;
}


int distance(City *current, City *next){
	int d = floor(sqrt(pow(current->y - next->y,2)+pow(current->x - next->x,2))+0.5);
	return d;
}
