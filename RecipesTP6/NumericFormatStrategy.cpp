///////////////////////////////////////////////////////////
//  NumericFormatStrategy.cpp
//  Implementation of the Class NumericFormatStrategy
//  Created on:      02-avr.-2022 14:16:27
//  Original author: francois
///////////////////////////////////////////////////////////

#include "NumericFormatStrategy.h"

// Objet singleton est instancié Q4.3
NumericFormatStrategy NumericFormatStrategy::instance;

NumericFormatStrategy::NumericFormatStrategy()
	: FormatStrategy(NumericFormat)
{
}

std::string NumericFormatStrategy::format(int time) const 
{
	// À compléter: décomposer la durée et construire une chaine avec en format numérique
	auto [days, hours, minutes, seconds] = decomposeTime(time);
	return std::string(
           std::to_string(days) + ":" +
           std::to_string(hours) + ":" +
           std::to_string(minutes) + ":" +
           std::to_string(seconds)
           );
}