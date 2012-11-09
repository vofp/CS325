#include <vector>
#include <iostream>
#include "types.hpp"
using namespace std;

void sort(Graph *graph, vector<City *> *x, vector<City *> *y);

void addToPath(Graph *graph, vector<City *> *path);

int greaterX(City *c1, City *c2);
int greaterY(City *c1, City *c2);


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
	addToPath(graph,x);
	City *front	= &(graph->cities.front());
	City *current = front->next;
	cout << "path:\n" << front->id << endl;
	while(front != current){
		cout << current->id << endl;
		current = current->next;
	}
	cout << current->id << endl;
}

int greaterX(City *c1, City *c2){
	if(c1->x > c2->x){
		return 1;
	}else if(c1->x < c2->x){
		return -1;
	}else if(c1->y > c2->y){
		return 1;
	}else if(c1->y < c2->y){
		return -1;
	}else{
		return 0;
	}
}
int greaterY(City *c1, City *c2){
	if(c1->y > c2->y){
		return 1;
	}else if(c1->y < c2->y){
		return -1;
	}else if(c1->x > c2->x){
		return 1;
	}else if(c1->x < c2->x){
		return -1;
	}else{
		return 0;
	}
}

void addToPath(Graph *graph, vector<City *> *path){
	vector<City *>::iterator it;
	for ( it = path->begin() ; it < path->end()-1;){
			City *current = (*it);
			it++;
			City *next = (*it);
			current->next = next;
			next->prev = current;
	}
	City *current = (path->back());
	City *next = (path->front());
	current->next = next;
	next->prev = current;	
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
				int compare = greaterX(c,x->at(mid));
				if(low == high){
					if(compare == 1){
						x->insert(x->begin()+mid+1, c);
						done = true;
					}else{
						x->insert(x->begin()+mid, c );
						done = true;
					}
				}

				//if(c->x > x->at(mid)->x){
				if(compare == 1){
					low = mid+1;
				}else if(compare == -1){
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
				int compare = greaterY(c,y->at(mid));
				
				if(low == high){
					if(compare == 1){
						y->insert(y->begin()+mid+1, c);
						done = true;
					}else{
						y->insert(y->begin()+mid, c );
						done = true;
					}
				}

				if(compare == 1){
					low = mid+1;
				}else if(compare == -1){
					high = mid;
				}else if(!done){
					y->insert(y->begin()+mid, c);
					done = true;
				}
			}

		}
  }
}


