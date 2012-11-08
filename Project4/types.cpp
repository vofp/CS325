#include <sstream>
#include "types.hpp"
using namespace std;

City::City(char *id_new, int x_new, int y_new){
	id = id_new;
	x = x_new;
	y = y_new;
}

string *City::output(){
	stringstream out;
	out << id << ": (" << x << ", " << y << ")" << endl;
	string *s = new string(out.str());
	//cout << *s;

	return s;
}

string *City::plot(){
	stringstream out;
	out << x << ", " << y << endl;
	string *s = new string(out.str());
	//cout << *s;

	return s;
}

Graph::Graph(){
	size = 0;
}

void Graph::add(City c){
	cities.push_back(c);
}
