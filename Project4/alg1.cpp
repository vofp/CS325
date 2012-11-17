#include "alg1.hpp"
using namespace std;

void tsp(Graph *graph){
	int checkSize = 0;
	int addIdx = graph->size+1;
	/* TODO: move path and length into graph class*/
	vector<City *> *x = new vector<City *>;
	vector<City *> *y = new vector<City *>;
	vector<City *> *path = graph->path;
	vector<int> *length = graph->length;
	vector<City *> *checkList = new vector<City *>;
	
	/* reserve size so its a constent add time */
	x->reserve(graph->size);
	y->reserve(graph->size);
	path->reserve(graph->size);
	length->reserve(graph->size);
	
	
	sort(graph, x, y);
	
	hull(graph,x,y,path);
	pathLength(path,length);
	sortD(graph, x, y,checkList);

	/* Removes one city from checkList and addes to path */
	while(checkList->size() != 0){
		addIdx = setupChecklist(path, length,checkList,addIdx);
	}
	
}

/* Inputs:
 *	path - Cities already on the path
 *	length - length from one city to the next on the path
 *	checkList - list of cities to check to put on path
 *	addedPath - the index of the latest added city *important when you add
 *	city it shifts index 1 to the right*
 */
int setupChecklist(vector<City *> *path, vector<int> *length, vector<City *> *checkList, int addedPath){
	int i;
	int minPathAdd = INT_MAX;
	int minPathAddC = 0;

	/* This code will be used to optimize later 
	 * Doesn't do anything right now
	 */
	int newCheckSize = checkList->size()/1 + 1;
	//cout << checkList->size() << " " <<newCheckSize << endl;
	/* Can be threaded */
	for(i=0; i < checkList->size() && i < newCheckSize; i++){
		//cout << "i "<< i << endl;
		int pAdd = shortestPath(path, length, checkList,addedPath, i);
		/* Checks if this city is the one to add */
		if(pAdd < minPathAdd){
			minPathAdd = pAdd;
			minPathAddC = i;
		}
	}			
	ofstream output("output2.txt", ofstream::app);
	output << checkList->at(minPathAddC)->idx << " " << checkList->at(minPathAddC)->id << endl;
	output.close();
	//cout << path->size()+1 <<" City id="<<checkList->at(minPathAddC)->id << " adding "<< minPathAdd << " distance" << endl;	
	int pathId = checkList->at(minPathAddC)->idx;
	int prevId = pathId -1;
	int nextId = pathId +1;
	path->insert(path->begin()+ pathId,checkList->at(minPathAddC));
	if(pathId == 0 ){
		prevId = path->size()-1;
	}
	if(pathId == path->size()-1){
		nextId = 0;
	}
	length->insert(length->begin()+pathId, distance(path->at(pathId),path->at(nextId)));
	length->at(prevId) = distance(path->at(prevId),path->at(pathId));
	checkList->at(minPathAddC)->onCheck = true;
	checkList->erase(checkList->begin()+minPathAddC);
	return pathId;
}

int shortestPath(vector<City *> *path, vector<int> *length, vector<City *> *checkList, int addedPath, int i){
	City *checkC = checkList->at(i);
	if(checkList->at(i)->pathAdd >= 0){
		/* The shortest path for this city completely changed due to adding
		 * the city, so we have to recalculate shortest path.
		 */
		if(checkC->idx == addedPath-1 || checkC->idx == addedPath){
			checkList->at(i)->pathAdd = -1;
		}else{
		
			/* Index for shortest path changed */
			if(checkC->idx > addedPath){
				checkC->idx += 1;
				if(checkC->idx == path->size()){
					checkC->idx = 0;
				}
			}
			int j;
			int length1;
			int length2;
			City *prev;
			City *current;
			City *next;
			/* Looping the back of list*/
			if(addedPath == 0){
				prev = path->back();
				length1 = length->back();
			}else{
				prev = path->at(addedPath-1);
				length1 = length->at(addedPath-1);
			}
			current = path->at(addedPath);
			length2 = length->at(addedPath);
			if(addedPath == path->size()-1){
				next = path->front();
				j = 0;
			}else{
				next = path->at(addedPath+1);
				j = addedPath+1;
			}
			int prevD = distance(checkC, prev);
			int currentD = distance(checkC, current);
			int nextD = distance(checkC, next);
			/* Length added if checkC is added to the path between prev and
			 * current or current and next 
			 */
			int pathAdd1 = prevD + currentD - length1;
			int pathAdd2 = currentD + nextD - length2;

			/* finds the position where it added the least length */
			if(pathAdd1 < checkC->pathAdd){
				checkC->idx = addedPath;
				checkC->pathAdd = pathAdd1;
			}

			if(pathAdd2 < checkC->pathAdd){
				checkC->idx = j;
				checkC->pathAdd = pathAdd2;
			}

			return checkC->pathAdd;
		}
	
	}
	
	/* First time to calculate shortest path or recalculating */
	if(checkList->at(i)->pathAdd == -1){
		int j = 0;
		City *current = path->back();
		City *next = path->front();
		int currentD = distance(checkC, current);
		int nextD = distance(checkC, next);
		int pathAdd = currentD + nextD - length->back();
		checkC->idx = 0;
		checkC->pathAdd = pathAdd;
		if(pathAdd < checkC->pathAdd){
			checkC->idx = 0;
			checkC->pathAdd = pathAdd;
		}
		for(j = 1; j < path->size(); j++){
			//cout << "j " << j << endl;
			current = next;
			next = path->at(j);
			currentD = nextD;
			nextD = distance(checkC, next);
			pathAdd = currentD + nextD - length->at(j-1);
			//cout << pathAdd << " "<< currentD << " " << nextD << " " << length->at(j-1) << endl;
			if(pathAdd < checkC->pathAdd){
				checkC->idx = j;
				checkC->pathAdd = pathAdd;
			}
		}
		//cout<< checkC->id << " " << checkC->pathAdd << endl;
		return checkC->pathAdd;
	}
	return INT_MAX;
}


void hull(Graph *graph, vector<City *> *x, vector<City *> *y, vector<City *> *path){
	int lowX = x->front()->x;
	int lowY = y->front()->y;
	int highX = x->back()->x;
	int highY = y->back()->y;
	int i = 0;
	while(x->at(i)->x==lowX){
		//cout << *(x->at(i)->output());
		if(!x->at(i)->onPath){
			path->push_back(x->at(i));
			x->at(i)->onPath = true;
			x->at(i)->onCheck = true;
			ofstream output("output2.txt", ofstream::app);
			output << path->size()-1 << " " << x->at(i)->id << endl;
			output.close();
		}
		i++;
	}
	i = 0;
	while(y->at(i)->y==lowY){
		//cout << *(y->at(i)->output());
		if(!y->at(i)->onPath){
			path->insert(path->begin(),y->at(i));
			y->at(i)->onPath = true;
			y->at(i)->onCheck = true;
			ofstream output("output2.txt", ofstream::app);
			output << 0 << " " << y->at(i)->id << endl;
			output.close();
		}
		i++;
	}
	i = 1;
	while(x->at(x->size()-i)->x==highX){
		//cout << *(x->at(x->size()-i)->output());
		if(!x->at(x->size()-i)->onPath){
			ofstream output("output2.txt", ofstream::app);
			output << i-1 << " " << x->at(x->size()-i)->id << endl;
			output.close();
			path->insert(path->begin()+i-1,x->at(x->size()-i));
			x->at(x->size()-i)->onPath = true;
			x->at(x->size()-i)->onCheck = true;
		}
		i++;
	}
	i = 1;
	while(y->at(y->size()-i)->y==highY){
		//cout << *(y->at(y->size()-i)->output());
		if(!y->at(y->size()-i)->onPath){
			ofstream output("output2.txt", ofstream::app);
			output << path->size()-i+1 << " " << y->at(y->size()-i)->id << endl;
			output.close();
			path->insert(path->end()-i+1,y->at(y->size()-i));
			y->at(y->size()-i)->onPath = true;
			y->at(y->size()-i)->onCheck = true;
		}
		i++;
	}

	//for(i = 0; i < path->size();i++){
	//	cout << "path: "<<*(path->at(i)->output());
	//}
}

/*void addAfter(City *c1, City *c2){
	c2->next = c1->next;
	c2->prev = c1;
	c1->next = c2;
	c2->next->prev = c2;
}*/

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

int greaterD(City *c1, City *c2){
	if(c1->d > c2->d){
		return 1;
	}else if(c1->d < c2->d){
		return -1;
	}else{
		return 0;
	}
}



void sort(Graph *graph, vector<City *> *x, vector<City *> *y){
	int it;
	int low;
	int high;
	int mid;
	bool done;
	for ( it = 0; it < graph->size; it++ ){
		City *c = &(graph->cities.at(it));
		if(x->empty()&&y->empty()){
			x->push_back(c);
			y->push_back(c);
		}else{
			/* x placement */		
			low = 0;
			high = x->size() - 1;
			mid;
			done = false;
			while(!done){
				mid = (high+low)/2;
				//cout << "x: " <<low << " "<< mid<< " "<<high << endl;
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
				//cout << "y: " <<low << " "<< mid<< " "<<high << endl;
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

void sortD(Graph *graph, vector<City *> *x, vector<City *> *y, vector<City *> *checkList){
	int it;
	int midX = (x->at(x->size()-1)->x + x->at(0)->x)/2;
	int midY = (y->at(y->size()-1)->y + y->at(0)->y)/2;
	//cout << "d placement" << endl;
	for ( it = 0; it < graph->size; it++ ){
		City *c = &(graph->cities.at(it));
		int d = floor(sqrt(pow(c->y - midY,2)+pow(c->x - midX,2))+0.5);
		c->d = d;
		if(!c->onCheck){
			if(checkList->empty()){
				checkList->push_back(c);
			}else{
				/*  placement */		
				int low = 0;
				int high = checkList->size() - 1;
				int mid;
				bool done = false;
				while(!done){
					mid = (high+low)/2;
					int compare = greaterD(c,checkList->at(mid));
					
					if(low == high){
						if(compare == -1){
							checkList->insert(checkList->begin()+mid+1, c);
							done = true;
						}else{
							checkList->insert(checkList->begin()+mid, c );
							done = true;
						}
					}

					if(compare == -1){
						low = mid+1;
					}else if(compare == 1){
						high = mid;
					}else if(!done){
						checkList->insert(checkList->begin()+mid, c);
						done = true;
					}
				}
			}
		}
	}
}

