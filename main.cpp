#include <iostream>
#include "Weight.h"


using namespace std;
int main() {
    cout << "Begin Fattus Cattus" << endl;
/*

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
    cout << "after trying to add a bad weight, catWeight = " << catWeight.getWeight( Weight::POUND ) << endl;
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
    Weight weightThree( 21.1,22 ); //will fail if maxWeight is < newWeight
    cout << "catThree.dump 1" << endl;
    weightThree.dump();

    ///try to add bad weights
    cout << "TRY TO SET BAD WEIGHT IN POUNDS" << endl;
    weightThree.setWeight( 23, Weight::POUND);
    cout << "TRY TO SET BAD WEIGHT IN KILOS" << endl;
    weightThree.setWeight( 11, Weight::KILO );
    cout << "weightThree.getWeight(pounds): " << weightThree.getWeight( Weight::POUND) << endl;
    cout << endl;

    cout << "SET A GOOD WEIGHT" << endl;
    weightThree.setWeight( .1, Weight::KILO );
    weightThree.dump();
    cout << endl;

    ///destruct cat three
    cout << "DESTROY WEIGHT THREE" << endl;
    weightThree.~Weight();
    //weightThree.dump(); ///it worked

    ///test validate
    Weight weightFour;
    weightFour.validate();
    weightFour.setWeight( 2, Weight::SLUG );
    weightFour.validate();

    ///test the constructor
    cout << "construct weight five" << endl;
    ///4
    Weight weightFive ( 3, Weight::SLUG );
    weightFive.dump();
    //cout << "construct weight six" << endl;
    ///5
    //Weight weightSix ( 3, 4 );
    //weightSix.dump();
    cout << endl;

    cout << "TEST THE OPERATORS" << endl;
    cout << "put to operator" << endl;
*/

    cout << "TEST THE CONSTRUCTORS" << endl;
    ///1
    Weight catOne;
    catOne.dump();
    ///2
    Weight catTwo ( 10 );
    catTwo.dump();
    ///3
    Weight catThree ( Weight::SLUG ); //works with SLUG and POUND too!
    catThree.dump();
    ///4
    Weight catFour ( 10, Weight::KILO); //weight is set in kilos
    catFour.dump();
    ///5
    Weight catFive ( 10, 11 ); //catches invalid weight maxWeight combo
    catFive.dump();
    ///6
    Weight catSix ( Weight::KILO, 11 ); //maxweight in pounds always
    catSix.dump();
    ///7
    Weight catSeven ( 4.20, Weight::KILO, 11); //because weight is being set in kilos
    catSeven.dump();
    ///test the comparison operator
    cout << ( ( catTwo == catFive )  ? "comparison true" : "comparison false" ) << endl; // needed the parens on the outside of the print statement
    cout << ( ( catFour == catFive ) ? "comparison true" : "comparison false" ) << endl;
    ///test the add to operators
    cout << "TEST THE OPERATORS" << endl;
    catTwo += 32; //adds in pounds
    catTwo.dump();
    catSix += 4;
    catSix.dump();

    cout << "TEST CODE DEFENSIVENESS" << endl;
    catSeven += 14;
    catOne.setWeight( -1 );

    cout << "finished fattus cattus" << endl;
    return 0;
}


