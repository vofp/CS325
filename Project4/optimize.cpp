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
			//cout << pathLength(path,length) << endl;
		}
	}	
}
