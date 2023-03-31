#include "Point.h"
#include <iostream>
using namespace std;

main(){
    Point<int> p1;
    cout << "Point 1" << endl;
    cin >> p1;
    Point<int> p2;
    cout << "Point 2" << endl;
    cin >> p2;
    Point<int> p3 = p1 + p2;
    cout << p1 << " + " << p2 << " = " << p3 << endl;
    p1 += p2;
    cout << "Increment p1 by p2 to get " << p1 << endl;
    p3 = p1 - p2;
    cout << p1 << " - " << p2 << " = " << p3 << endl;
    p1 -= p2;
    cout << "Increment backwards p1 by p2 to get " << p1 << endl;
}