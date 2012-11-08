#include <vector>
#include <iostream>
#include "types.hpp"
using namespace std;

void sort(Graph *graph, vector<City *> *x, vector<City *> *y);

void tsp(Graph *graph){
	vector<City *> *x = new vector<City *>;
	vector<City *> *y = new vector<City *>;
	x->reserve(graph->size);	
	y->reserve(graph->size);

	sort(graph, x, y);
	vector<City *>::iterator it;
	for ( it = x->begin() ; it < x->end(); it++ ){
			cout << *((*it)->output());
	}

}

void sort(Graph *graph, vector<City *> *x, vector<City *> *y){
	vector<City>::iterator it;
	for ( it = graph->cities.begin() ; it < graph->cities.end(); it++ ){
		if(x->empty()||y->empty()){
			x->push_back(*it);
			y->push_back(*it);
		}else{
			/* x placement */		
			int low = 0;
			int high = x->size() - 1;
			int mid;
			bool done = false;
			while(!done){
				mid = (high+low)/2;
				if(it->x > x->at(mid)->x){
					low = mid;
				}else if(it->x < x->at(mid)->x){
					high = mid;
				}else if(low == high){
					if(it->x > x->at(mid)->x){
						x->insert(mid+1, it);
					}else if(it->x <= x->at(mid)->x){
						x->insert(mid, it);
					}
				}else{
					x->insert(mid, it);
				}
			}
		}
  }
}


