///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author  Aksel Sloan <@aksel@hawaii.edu>
/// @date   15_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once


class Weight {
public:     ///enums
    enum UnitOfMeasure { POUND, KILO, SLUG };
            ///unknown weight
    static const float UNKNOWN_WEIGHT    ;
            ///conversion units
    static const float KILOS_PER_POUND  ;
    static const float SLUGS_PER_POUND  ;

public:     ///hold the weights
    float inputWeight       ;
    float weightInPounds    ;
    float weightInKilos     ;
    float weightInSlugs     ;

};



