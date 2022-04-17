///////////////////////////////////////////////////////////
//  FormatStrategy.cpp
//  Implementation of the Class FormatStrategy
//  Created on:      02-avr.-2022 14:16:26
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FormatStrategy.h"
#include "TimeFormater.h"

FormatStrategy::FormatStrategy(std::string id)
{
	registerFormatStrategy(id, this);
}

FormatStrategy::time_decomposition FormatStrategy::decomposeTime(int time) const
{
	// À compléter: décomposer la durée en nombre de jours, heures, minutes et secondes
	//              retourner le résultat de la décomposition dans un objet time_decomposition
	int days = time / 86400;
	int hours = days / 3600;
	int minutes = hours / 60;
	int seconds = seconds / 60;

	return time_decomposition(days, hours, minutes, seconds);
}

void FormatStrategy::registerFormatStrategy(std::string id, const FormatStrategy* strategy)
{
	// À compléter: insérer la stratégie dans le registre des stratégies de la classe TimeFormater
	TimeFormater::getInstance().registerFormatStrategy(id, strategy);
}
