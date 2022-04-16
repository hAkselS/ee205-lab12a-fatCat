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
#include "Weight.h"
#include <cassert>
#include <iostream>
            ///labels and such
const std::string POUND_LABEL   = "Pound"   ;
const std::string KILO_LABEL    = "Kilo"    ;
const std::string SLUG_LABEL    = "Slug"    ;
const float Weight :: UNKNOWN_WEIGHT    = -1          ;

            ///conversion units
const float Weight :: KILOS_PER_POUND   = 0.453592    ;
const float Weight :: SLUGS_PER_POUND   = 0.031081    ;



///setters
void Weight::setWeight(const float newWeight) {
    ///@todo validate weight
    weightInPounds = newWeight;
}

            ///getters
float Weight::getWeight() const noexcept {
    ///@todo validate weight
    return weightInPounds;
}


