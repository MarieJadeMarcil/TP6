///////////////////////////////////////////////////////////
//  FindIngredientVisitor.cpp
//  Implementation of the Class FindIngredientVisitor
//  Created on:      02-avr.-2022 14:16:25
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FindIngredientVisitor.h"
#include "Ingredient.h"
#include "Recipe.h"
#include "CompositeStep.h"
#include "SingleStep.h"

FindIngredientVisitor::FindIngredientVisitor(const char* ingredientName)
	: m_searchedName(ingredientName), m_currentIterator(nullptr)
{
}

void FindIngredientVisitor::processCompositeStep(CompositeStep& composite)
{
	// RIEN À FAIRE POUR LES ÉTAPES COMPOSITES
}

void FindIngredientVisitor::processIngredient(Ingredient& ingredient)
{
	// À compléter: vérifier si le nom du produit utilisé comme ingrédient correspond au nom cherché
	//              si oui, ajouter l'itérateur sur cet ingrédient dans la liste des ingrédients trouvés
	m_searchedName == ingredient.get
}

void FindIngredientVisitor::processRecipe(Recipe& recipe)
{
	// � compl�ter: it�rer sur tous les ingr�dients de la recette
	//                   - conserver un pointeur sur l'it�rateur de l'ingr�dient
	//                   - appliquer le visiteur sur l'ingr�dient
}

void FindIngredientVisitor::processSingleStep(SingleStep& step)
{
	// RIEN � FAIRE POUR UNE �TAPE SIMPLE
}

FoundIngredientIterator FindIngredientVisitor::begin()
{
	return m_ingredientsFound.begin();
}

FoundIngredientIterator_const FindIngredientVisitor::cbegin() const
{
	return m_ingredientsFound.begin();
}

FoundIngredientIterator_const FindIngredientVisitor::cend() const
{
	return m_ingredientsFound.cend();
}

FoundIngredientIterator FindIngredientVisitor::end()
{
	return m_ingredientsFound.end();
}

void FindIngredientVisitor::reset()
{ 
	m_ingredientsFound.clear(); 
}

