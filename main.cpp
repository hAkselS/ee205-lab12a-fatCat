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
    Weight catWeight;           ///instantiate the class
    cout << "get weight without setting a weight: [" << catWeight.getWeight() << "]" << endl;
    catWeight.setWeight( 22 );
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
    cout << "test convert weight: " << endl;
    cout << "12 kilos = [" <<catWeight.convertWeight( 12, Weight::KILO, Weight::SLUG ) << "] slugs" << endl;
    cout << endl;

    ///test constructors
    cout << "test for invalid inputs in constructors" << endl;
    Weight badWeightOne( -42 );
    cout << badWeightOne.getWeight() << endl;
    Weight weightOne( 42 );
    cout << "weightOne constructed with weight = 42: [" << weightOne.getWeight() << "]" << endl;
    cout << "weightTwo constructed with unit of measure = kilos" << endl;
    Weight weightTwo ( Weight::KILO );
    cout << "weightTwo getUnits: [" << weightTwo.getUnits() << "]" << endl;

    ///test the dump
    catWeight.dump();
    cout << catWeight.printUnits( catWeight.getUnits() ) << endl;


    return 0;
}
