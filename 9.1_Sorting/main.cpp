#include "Collection.h"
#include <sstream>
#include <iostream>
using namespace std;

main(){
  string msg = "selectionsortseemsinefficient";
  cout << " " << msg[25] << endl;
	Collection<char>c;
	for (char l : msg) {
		c.add(l);
	}

	c.sortBySelection();
  cout << c << endl;
}
