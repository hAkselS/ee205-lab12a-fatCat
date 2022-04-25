#include <iostream>
#include "Weight.h"


using namespace std;
int main() {
    cout << "Begin Fattus Cattus" << endl;

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


