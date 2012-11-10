#include <vector>
#include <iostream>
#include <math.h>
#include "types.hpp"
using namespace std;

void sort(Graph *graph, vector<City *> *x, vector<City *> *y);

void addToPath(Graph *graph, vector<City *> *path);

int greaterX(City *c1, City *c2);
int greaterY(City *c1, City *c2);
void hull(Graph *graph, vector<City *> *x, vector<City *> *y, vector<City *> *path);

void tsp(Graph *graph){
	vector<City *> *x = new vector<City *>;
	vector<City *> *y = new vector<City *>;
	vector<City *> *path = new vector<City *>;
	x->reserve(graph->size);
	y->reserve(graph->size);
	sort(graph, x, y);
	vector<City *>::iterator it;
	/*for ( it = x->begin() ; it < x->end(); it++ ){
		cout << "x "<<*((*it)->output());
	}
	for ( it = y->begin() ; it < y->end(); it++ ){
		cout << "y "<<*((*it)->output());
	}*/
	//cout << graph->cities.front().next->x <<endl;
	
	hull(graph,x,y,path);
	//addToPath(graph,path);
	//City *front = &(graph->cities.front());
	/*City *front = path->front();
	City *current = front->next;
	while(front != current){
		cout << current->id << endl;
		current = current->next;
	}
	cout << current->id << endl;
	*/

	ofstream output("output.txt");
	if (output.is_open()){
		int i;
		for(i = 0; i < path->size();i++){
			output << *(path->at(i)->plot());
		}
		output << *(path->at(0)->plot());
		output.close();
	}
	else cout << "Unable to open file";
}

void hull(Graph *graph, vector<City *> *x, vector<City *> *y, vector<City *> *path){
	int lowX = x->front()->x;
	int lowY = y->front()->y;
	int highX = x->back()->x;
	int highY = y->back()->y;
	int i = 0;
	while(x->at(i)->x==lowX){
		cout << *(x->at(i)->output());
		if(!x->at(i)->onPath){
			path->push_back(x->at(i));
			x->at(i)->onPath = true;
		}
		i++;
	}
	i = 0;
	while(y->at(i)->y==lowY){
		cout << *(y->at(i)->output());
		if(!y->at(i)->onPath){
			path->insert(path->begin(),y->at(i));
			y->at(i)->onPath = true;
		}
		i++;
	}
	i = 1;
	while(x->at(x->size()-i)->x==highX){
		cout << *(x->at(x->size()-i)->output());
		if(!x->at(x->size()-i)->onPath){
			path->insert(path->begin()+i-1,x->at(x->size()-i));
			x->at(x->size()-i)->onPath = true;
		}
		i++;
	}
	i = 1;
	while(y->at(y->size()-i)->y==highY){
		cout << *(y->at(y->size()-i)->output());
		if(!y->at(y->size()-i)->onPath){
			path->insert(path->end()-i+1,y->at(y->size()-i));
			y->at(y->size()-i)->onPath = true;
		}
		i++;
	}

	for(i = 0; i < path->size();i++){
		cout << "path: "<<*(path->at(i)->output());
	}
}

void addAfter(City *c1, City *c2){
	c2->next = c1->next;
	c2->prev = c1;
	c1->next = c2;
	c2->next->prev = c2;
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

int distance(City *current, City *next){
	int d = sqrt(pow(current->y - next->y,2)+pow(current->x - next->x,2));
	//cout <<  "("<<current->x << ", "<< current->y << ") (" << next->x << ", " << next->y << "):   " << d << endl;
	return d;
}

void addToPath(Graph *graph, vector<City *> *path){
	
	vector<City *>::iterator it;
	for ( it = path->begin() ; it < path->end()-1;){
			City *current = (*it);
			it++;
			City *next = (*it);
			/*cout << current->id << endl;
			next->next = current->next;
			current->next->prev = next;
			current->next = next;
			next->prev = current;*/
			addAfter(current,next);
			graph->path_size += distance(current, next);
	}
	City *current = (path->back());
	City *next = (path->front());
	current->next = next;
	next->prev = current;	
	graph->path_size += distance(current, next);
	cout << graph->path_size << endl;	
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


