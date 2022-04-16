#include <iostream>
#include "Weight.h"

using namespace std;
int main() {
    cout << "Begin Fattus Cattus" << endl;
    cout << "print constants////////"<< endl;
    cout << "unknown weight" << Weight::UNKNOWN_WEIGHT << endl;
    cout << "kilos per pound" << Weight::KILOS_PER_POUND << endl;
    cout << "slugs per pound" << Weight::SLUGS_PER_POUND << endl;

    ///instantiate the class, set and get
    cout << "instantiate the class" << endl;
    Weight catWeight;           //instantiate the class
    catWeight.setWeight( 42 );
    cout << "get the freshly set weight (in pounds) :" << catWeight.getWeight() << endl;
    cout << endl;

    ///test bad weight validation
    cout << "try to add a bad weight" << endl;
    catWeight.setWeight( -1 );
    cout << "after trying to add a bad weight, catWeight = " << catWeight.getWeight() << endl;
    cout << endl;

    ///test unit conversions, get by unit, set by unit
    cout << "try to return weight in kilograms" << endl;
    cout << "cat weight in kilograms = " << catWeight.getWeight( Weight::KILO ) << endl;


    return 0;
}
