///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author  Aksel Sloan <@aksel@hawaii.edu>
/// @date   15_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "Weight.h"
#include <cassert>
#include <iostream>
using namespace std;
#define DEBUG


            ///labels and such
const string Weight::POUND_LABEL   = "Pound"   ;
const string Weight::KILO_LABEL    = "Kilo"    ;
const string Weight::SLUG_LABEL    = "Slug"    ;
const float Weight :: UNKNOWN_WEIGHT    = -1;




///conversion scalars
const float Weight :: KILOS_PER_POUND   = 0.453592    ;
const float Weight :: SLUGS_PER_POUND   = 0.031081    ;



            ///unit converters

float Weight::fromKiloToPound(float kiloIn) noexcept {
    float poundOut;
    poundOut = kiloIn * ( 1 / KILOS_PER_POUND );
    return poundOut;
}

float Weight::fromPoundToKilo(float poundIn) noexcept {
    float kiloOut;
    kiloOut = poundIn * KILOS_PER_POUND;
    return kiloOut;
}

float Weight::fromSlugToPound(float slugIn) noexcept {
    float poundOut;
    poundOut = slugIn * ( 1 / SLUGS_PER_POUND);
    return poundOut;
}

float Weight::fromPoundToSlug(float poundIn) noexcept {
    float slugOut;
    slugOut = poundIn * SLUGS_PER_POUND;
    return slugOut;
}
float Weight::convertWeight(float fromWeight, Weight::UnitOfMeasure fromUnit, Weight::UnitOfMeasure toUnit) noexcept {
    //@todo validate weight
    switch ( fromUnit ){
        case POUND:
            switch ( toUnit ){
                case POUND:
                    return fromWeight;
                case KILO:
                    return fromPoundToKilo( fromWeight );
                case SLUG:
                    return fromPoundToSlug( fromWeight );
            }
        case KILO:
            switch ( toUnit ){
                case POUND:
                    return fromKiloToPound( fromWeight );
                case KILO:
                    return fromWeight;
                case SLUG:
                    return fromPoundToSlug(fromKiloToPound( fromWeight ));  ///double check this
            }
        case SLUG:
            switch ( toUnit ){
                case POUND:
                    return fromSlugToPound( fromWeight );
                case KILO:
                    return fromPoundToSlug(fromPoundToKilo( fromWeight ));  ///double check this
                case SLUG:
                    return fromWeight;
            }
    }
    cout << "convertWeight: invalid to/from unit" << endl;
    return UNKNOWN_WEIGHT;
}

            ///constructors
            ///1
Weight::Weight() {
    weightInPounds = UNKNOWN_WEIGHT;
    weightInKilos = UNKNOWN_WEIGHT;
    weightInSlugs = UNKNOWN_WEIGHT;
    maxWeight     = UNKNOWN_WEIGHT;
}
            ///2
Weight::Weight(float newWeight) {
    if (Weight::isWeightValid( newWeight)){
        setWeight( newWeight );
        bIsKnown = true;
        maxWeight = UNKNOWN_WEIGHT;
    }
    else {
        cout << "constructor: invalid weight" << endl;
        weightInPounds = UNKNOWN_WEIGHT;
    }
}
            ///3
Weight::Weight(Weight::UnitOfMeasure newUnitOfMeasure) : Weight() {
    unitOfMeasure = newUnitOfMeasure;
    maxWeight = UNKNOWN_WEIGHT;
    bIsKnown = false;
    bHasMax = false;
    assert(validate());
}
            ///4
Weight::Weight(float newWeight, Weight::UnitOfMeasure newUnitOfMeasure) {
    if (Weight::isWeightValid( newWeight)){
        bIsKnown = true;
        bHasMax = false;
        maxWeight = UNKNOWN_WEIGHT;
        unitOfMeasure = newUnitOfMeasure;
        setWeight( newWeight, newUnitOfMeasure );
    }
    else {
        cout << "constructor: invalid weight" << endl;
        weightInPounds = UNKNOWN_WEIGHT;
    }
    assert(validate());
}
           ///5 problem here
Weight::Weight( float newWeight, float newMaxWeight) : Weight( newWeight ){
    setMaxWeight( newMaxWeight); //somehow messes with units of measure
    assert(validate());
}
            ///6
Weight::Weight(Weight::UnitOfMeasure newUnitOfMeasure, float newMaxWeight) : Weight( newUnitOfMeasure ) {
    setMaxWeight( newMaxWeight );
    assert(validate());
}

            ///7
Weight::Weight(float newWeight, Weight::UnitOfMeasure newUnitOfMeasure, float newMaxWeight) : Weight (  newWeight, newUnitOfMeasure) { //can only delegate once
    setMaxWeight( newMaxWeight );
    assert(validate());
}

            ///destructor
Weight::~Weight() {
    bIsKnown = false;
    weightInPounds = UNKNOWN_WEIGHT;
    weightInKilos = UNKNOWN_WEIGHT;
    weightInSlugs = UNKNOWN_WEIGHT;
    unitOfMeasure = POUND;
    bHasMax = false;
    maxWeight = UNKNOWN_WEIGHT;
}


            ///setters
void Weight::setWeight(const float newWeight) {
    if (isWeightValid( newWeight ) ){
        weightInPounds = newWeight;
        weightInKilos = fromPoundToKilo( newWeight );
        weightInSlugs = fromPoundToSlug( newWeight );
        bIsKnown = true;
    }
}
void Weight::setWeight( float newWeight, Weight::UnitOfMeasure weightUnits) {
    ///verfiry that weight is valid (in pounds) b/c max weight is stored in pounds
    float verifiableWeight = UNKNOWN_WEIGHT;
    switch ( weightUnits ){
        case POUND:
            verifiableWeight = newWeight;
            //cout << "setWeight: weightUnits == POUND" << endl;
            //cout << "setWeight: verifiableWeight ==" << verifiableWeight << endl;   //these are working
            break;
        case KILO:
            verifiableWeight = fromKiloToPound( newWeight );
            break;
        case SLUG:
            verifiableWeight = fromSlugToPound( newWeight);
            break;
    }
    if (isWeightValid( verifiableWeight)){
        switch ( weightUnits ){  //would be more efficient to convert out of pounds when retrieving
            case POUND:
                weightInPounds      = newWeight;
                weightInKilos       = fromPoundToKilo( newWeight );
                weightInSlugs       = fromPoundToSlug( newWeight );
                break;
                //cout << "setWeight: case POUND" << endl;
            case KILO:
                weightInPounds      = fromKiloToPound( newWeight );
                weightInKilos       = newWeight;
                weightInSlugs       = fromPoundToSlug(fromKiloToPound( newWeight));
                break;
                //cout << "setWeight: case KILO" << endl;
            case SLUG:
                weightInPounds      = fromSlugToPound( newWeight );
                weightInKilos       = fromPoundToKilo(fromSlugToPound( newWeight ) );
                weightInSlugs       = newWeight;
                break;
        }
        bIsKnown = true;
    }
    else{
        cout << "setWeight: invalid weight" << endl;
    }
    assert(validate());
}

void Weight::setMaxWeight(const float newMaxWeight) {
    ///max weight is always stored in POUNDS
    if ( !bHasMax ){
        if (isWeightValid( newMaxWeight)) {
            maxWeight = newMaxWeight;
            bHasMax = true;
        }
    }
    else{
        cout << "setMaxWeight: new max weight is invalid or max already set" << endl;
    }
}

            ///getters
float Weight::getWeight() const noexcept {
    return weightInPounds;
}
float Weight::getWeight(Weight::UnitOfMeasure weightUnits) const {
    if ( weightUnits == POUND ){
        return weightInPounds;
    }
    if ( weightUnits == KILO ){
        return weightInKilos;
    }
    if ( weightUnits == SLUG ){
        return weightInSlugs;
    }
    else{
        cout << "getWeight: invalid unit of measure!" << endl;
        return -1;
    }
}
Weight::UnitOfMeasure Weight::getUnits() const noexcept {
    return unitOfMeasure;
}
bool Weight::isWeightKnown() const noexcept {
    return bIsKnown;
}
bool Weight::hasMaxWeight() const noexcept {
    return bHasMax;
}
float Weight::getMaxWeight() const noexcept {
    if (bHasMax){
        return maxWeight;
    }
    else{
        return -1;
    }
}


#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)
void Weight::dump() const noexcept {
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Weight", "this" )             << this                                     << endl ;
    FORMAT_LINE( "Weight", "isKnown" )          << isWeightKnown()                          << endl ;
    FORMAT_LINE( "Weight", "weight" )           << getWeight( getUnits() )       << endl ;
    FORMAT_LINE( "Weight", "unitOfMeasure" )    << getUnits()                               << endl ;
    FORMAT_LINE( "Weight", "hasMaxWeight" )     << hasMaxWeight()                           << endl ;
    FORMAT_LINE( "Weight", "MaxWeight" )        << getMaxWeight()                           << endl ;

}

            ///validation
bool Weight::validate() const noexcept {
    if ( !bIsKnown ){
        assert( weightInPounds == UNKNOWN_WEIGHT );
        assert( weightInKilos == UNKNOWN_WEIGHT );
        assert( weightInSlugs == UNKNOWN_WEIGHT );
    }
    if ( bIsKnown ){
        assert( weightInPounds >= 0 );
        assert( weightInKilos >= 0 );
        assert( weightInSlugs >= 0);
    }
    if ( !bHasMax ){
        assert( maxWeight == UNKNOWN_WEIGHT );
    }
    if ( bHasMax ){
        assert( maxWeight > 0 );
        assert( weightInPounds <= maxWeight );
    }

    return true;
}
bool Weight::isWeightValid(const float inputWeight) const noexcept {
    //cout << "isWeightValid: input weight = " << inputWeight << endl;
    if ( inputWeight <= 0){
        cout << "isWeightValid: weight must be greater than 0" << endl;
        return false;
    }
    if ( bHasMax ){
        //cout << "isWeightValid: bHasMax == true, maxWeight = " << maxWeight << endl;
        if ( inputWeight >= maxWeight ){
            //cout << inputWeight << " is greater than " << maxWeight << endl;
            cout << "isWeightValid: weight must be less than max weight" << endl;
            return false;
       }
    }
    return true;
}

            ///OPERATORS
            ///put to operator
std::ostream& operator<<( std::ostream& lhs_stream
        ,const Weight::UnitOfMeasure rhs_UnitOfMeasure ) {
    switch (rhs_UnitOfMeasure) {
        case Weight::POUND:
            return lhs_stream << Weight::POUND_LABEL;
        case Weight::KILO:
            return lhs_stream << Weight::KILO_LABEL;
        case Weight::SLUG:
            return lhs_stream << Weight::SLUG_LABEL;
        default:
            throw std::out_of_range("The unit can’t be mapped to a string");
    }
}
bool Weight::operator==(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? this->getWeight(Weight::POUND) : 0;
    float rhs_weight = (bIsKnown) ? rhs_Weight.getWeight( Weight::POUND ) : 0;
    return lhs_weight == rhs_weight;
}

Weight &Weight::operator+=(float rhs_addToWeight) { //only adds weight in pounds
    if ( bIsKnown ) {
        float currentWeight = this->getWeight(Weight::POUND);
        float newWeightPrime = currentWeight + rhs_addToWeight;
        this->setWeight(newWeightPrime, Weight::POUND);
    }
    else {
        this->setWeight( rhs_addToWeight );
    }
    return *this;
}





























