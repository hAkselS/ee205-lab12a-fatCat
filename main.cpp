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
    cout << "catWeight.dump" << endl;
    catWeight.dump();
    cout << "weightTwo.dump()" << endl;
    weightTwo.dump();
    Weight weightThree;
    cout << "catThree.dump 1" << endl;
    weightThree.dump();

    ///try to add bad weights
    weightThree.setMaxWeight( 10 );
    weightThree.setWeight( 21.1, Weight::POUND);
    weightThree.setWeight( 9.9, Weight::KILO );
    cout << "weightThree.getWeight( pounds): " << weightThree.getWeight() << endl;
    weightThree.getWeight( Weight::POUND );
    cout << endl;
    cout << "set a good weight for weight three" << endl;
    weightThree.setWeight( .1, Weight::KILO );
    weightThree.dump();
    cout << endl;


    return 0;
}


///note,