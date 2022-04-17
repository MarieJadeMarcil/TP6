///////////////////////////////////////////////////////////
//  Ingredient.cpp
//  Implementation of the Class Ingredient
//  Created on:      19-mars-2022 11:23:22
//  Original author: Fran�ois
///////////////////////////////////////////////////////////

#include "Ingredient.h"
#include "AbsRecipeVisitor.h"

Ingredient::Ingredient(std::string name, int duration, const AbsProduct& product)
	: AbsIngredient(name, duration), m_product(product)
{
}

Ingredient* Ingredient::clone() const
{
	return new Ingredient(*this);
}

void Ingredient::accept(class AbsRecipeVisitor& visitor)
{
	visitor.processIngredient(*this);
}

const AbsProduct& Ingredient::getProduct() const
{
	return m_product;
}

std::ostream& Ingredient::printToStream(std::ostream& o) const 
{
	// À compléter pour imprimer sur un stream une catégorie et ses produits
	return o << m_product.getName() << " " << m_description << std::endl;
}

