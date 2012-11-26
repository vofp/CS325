#include "optimize.hpp"

void optimize(vector<City *> *path, vector<int> *length, int s){
	int i;
	for(i = 0; i < path->size();i++){
		int a = i;
		int b = (i+1) % path->size();
		int c = (i+1+s) % path->size();
		int d = (c+1) % path->size();


		int ab = distance(path->at(a),path->at(b));
		int cd = distance(path->at(c),path->at(d));
		int ac = distance(path->at(a),path->at(c));
		int bd = distance(path->at(b),path->at(d));

		if((ab+cd) > (ac+bd)){
			int j = i+1;
			int k = i+1+s;
			while(j < k){
				int j2 = j % path->size();
				int k2 = k % path->size();
				City *J = path->at(j2);
				City *K = path->at(k2);
				path->at(j2) = K;
				path->at(k2) = J;
				j++;
				k--;
			}
			/* TODO: Optimize by adding code into while loop above */
			cout << pathLength(path,length) << endl;
		}
	}	
}

int shortestPath_opt(vector<City *> *path, vector<int> *length, vector<City *> *checkList, int i);

void optimize2(vector<City *> *path, vector<int> *length, int s){
	if(s < 3){
		return;
	}

	int minPathAdd = INT_MAX;
	int minPathAddC = 0;
	int i;
	for(i = 0; i < path->size();i++){
		vector<City *> path_new (*path);
		vector<int> length_new (*length);
		vector<City *> checkList;


		int j;
		for(j = 0; j < s; j++){
			int k = i;
			if(i >= path_new.size()){
				k = 0;
			}
			checkList.push_back(path_new.at(k));
			path_new.erase(path_new.begin()+k);
		}
		while(checkList.size() != 0){
			minPathAdd = INT_MAX;
			minPathAddC = 0;
			pathLength(&path_new,&length_new);
			for(j = 0; j < checkList.size(); j++){
				int pAdd = shortestPath_opt(&path_new,&length_new,&checkList, j);
				if(pAdd < minPathAdd){
					minPathAdd = pAdd;
					minPathAddC = j;
				}
			}
			path_new.insert(path_new.begin()+ checkList.at(minPathAddC)->idx, checkList.at(minPathAddC));
			checkList.erase(checkList.begin()+minPathAddC);
		}
		int pL1 = pathLength(path,length);
		int pL2 = pathLength(&path_new,&length_new);
		if(pL2 < pL1){
			cout << pL1 << endl;
			path->swap(path_new);
		}
	}
	
}


int shortestPath_opt(vector<City *> *path, vector<int> *length, vector<City *> *checkList, int i){
	City *checkC = checkList->at(i);	
	/* recalculating */
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
