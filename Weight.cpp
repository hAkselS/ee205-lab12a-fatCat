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

            ///labels and such
const std::string POUND_LABEL   = "Pound"   ;
const std::string KILO_LABEL    = "Kilo"    ;
const std::string SLUG_LABEL    = "Slug"    ;
const float Weight :: UNKNOWN_WEIGHT    = -1          ;

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
    cout << "invalid to/from unit" << endl;
    return UNKNOWN_WEIGHT;
}

            ///constructors
Weight::Weight() {
    weightInPounds = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight) {
    if (Weight::isWeightValid( newWeight)){
        weightInPounds = newWeight;
        bIsKnown = true;
    }
    else {
        cout << "invalid weight" << endl;
        weightInPounds = UNKNOWN_WEIGHT;
    }
}

Weight::Weight(Weight::UnitOfMeasure newUnitOfMeasure) {
    unitOfMeasure = newUnitOfMeasure;
}

Weight::Weight(float newWeight, Weight::UnitOfMeasure newUnitOfMeasure) {

}

Weight::Weight(float newWeight, float newMaxWeight) {

}

Weight::Weight(Weight::UnitOfMeasure newUnitOfMeasure, float newMaxWeight) {

}

Weight::Weight(float newWeight, Weight::UnitOfMeasure newUnitOfMeasure, float newMaxWeight) {

}


            ///setters
void Weight::setWeight(const float newWeight) {
    if (isWeightValid( newWeight ) ){
        weightInPounds = newWeight;
        //weightInKilos = fromPoundToKilo( newWeight ); ///more efficient design I think
        bIsKnown = true;

    }
}

            ///getters
float Weight::getWeight() const noexcept {
    ///@todo validate weight
    return weightInPounds;
}
float Weight::getWeight(Weight::UnitOfMeasure weightUnits) {
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
        cout << "invalid unit of measure!" << endl;
        return -1;
    }
}
Weight::UnitOfMeasure Weight::getUnits() const noexcept {
    return Weight::unitOfMeasure;
}
bool Weight::isWeightKnown() const noexcept {
    return bIsKnown;
}

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)
void Weight::dump() const noexcept {
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Weight", "this" )         << this             << endl ;
    FORMAT_LINE( "Weight", "isKnown" )      << isWeightKnown()  << endl ;
    FORMAT_LINE( "Weight", "weight" )       << getWeight()      << endl ;

}

            ///validation
bool Weight::validate() const noexcept {
    //@todo make this validate everything

    return true;
}
bool Weight::isWeightValid(const float inputWeight) const noexcept {
    if ( inputWeight <= 0){
        cout << "weight must be greater than 0" << endl;
        return false;
    }
    return true;
}
















