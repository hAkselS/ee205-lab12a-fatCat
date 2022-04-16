#include <iostream>
#include "Weight.h"

using namespace std;
int main() {
    cout << "Begin Fattus Cattus" << endl;
    cout << "print constants////////"<< endl;
    cout << "unknown weight" << Weight::UNKNOWN_WEIGHT << endl;
    cout << "kilos per pound" << Weight::KILOS_PER_POUND << endl;
    cout << "slugs per pound" << Weight::SLUGS_PER_POUND << endl;

    cout << "instantiate the class" << endl;
    Weight catWeight;           //instantiate the class
    catWeight.setWeight( 42 );
    cout << "get the freshly set weight (in pounds) :" << catWeight.getWeight() << endl;


    return 0;
}
