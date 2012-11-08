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
			cout << "x "<<*((*it)->output());
	}
	for ( it = y->begin() ; it < y->end(); it++ ){
			cout << "y "<<*((*it)->output());
	}
}

void sort(Graph *graph, vector<City *> *x, vector<City *> *y){
	int it;
	for ( it = 0; it < graph->size; it++ ){
		City *c = &(graph->cities.at(it));
		if(x->empty()&&y->empty()){
			x->push_back(c);
			y->push_back(c);
		}else{
			/* x placement */		
			int low = 0;
			int high = x->size() - 1;
			int mid;
			bool done = false;
			while(!done){
				mid = (high+low)/2;
				
				if(low == high){
					if(c->x > x->at(mid)->x){
						x->insert(x->begin()+mid+1, c);
						done = true;
					}else{
						x->insert(x->begin()+mid, c );
						done = true;
					}
				}

				if(c->x > x->at(mid)->x){
					low = mid+1;
				}else if(c->x < x->at(mid)->x){
					high = mid;
				}else if(!done){
					x->insert(x->begin()+mid, c);
					done = true;
				}
			}


			/* y placement */		
			low = 0;
			high = y->size() - 1;
			mid;
			done = false;
			while(!done){
				mid = (high+low)/2;
				
				if(low == high){
					if(c->y > y->at(mid)->y){
						y->insert(y->begin()+mid+1, c);
						done = true;
					}else{
						y->insert(y->begin()+mid, c );
						done = true;
					}
				}

				if(c->y > y->at(mid)->y){
					low = mid+1;
				}else if(c->y < y->at(mid)->y){
					high = mid;
				}else if(!done){
					y->insert(y->begin()+mid, c);
					done = true;
				}
			}

		}
  }
}


