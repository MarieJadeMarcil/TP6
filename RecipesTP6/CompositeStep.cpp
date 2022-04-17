///////////////////////////////////////////////////////////
//  CompositeStep.cpp
//  Implementation of the Class CompositeStep
//  Created on:      19-mars-2022 11:23:22
//  Original author: Fran�ois
///////////////////////////////////////////////////////////

#include "CompositeStep.h"

CompositeStep::CompositeStep(std::string title)
	: AbsStep(title, 0)
{
}

CompositeStep::CompositeStep(const CompositeStep& mdd)
	: AbsStep(mdd)
{
	for (auto it = mdd.cbegin(); it != mdd.cend(); it++) {
		addRecipeComponent(*it);
	}
}

CompositeStep* CompositeStep::clone() const
{
	return new CompositeStep(*this);
}

void CompositeStep::accept(class AbsRecipeVisitor& visitor) {
	visitor.processCompositeStep(*this);
}

RecipeComponentIterator CompositeStep::begin() {

	return m_stepsContainer.begin();
}


RecipeComponentIterator_const CompositeStep::cbegin() const {

	return m_stepsContainer.cbegin();
}


RecipeComponentIterator_const CompositeStep::cend() const
{
	return m_stepsContainer.cend();
}

RecipeComponentIterator CompositeStep::end()
{
	return  m_stepsContainer.end();
}

AbsRecipeComponent& CompositeStep::addRecipeComponent(const AbsRecipeComponent& member)
{
	const AbsStep& step = dynamic_cast<const AbsStep&>(member);
	return addRecipeComponent(step);
}

AbsRecipeComponent& CompositeStep::addRecipeComponent(const AbsStep& member)
{
	m_stepsContainer.push_back(RecipeComponentPtr(member.clone()));
	return *m_stepsContainer.back();
}

void CompositeStep::deleteRecipeComponent(RecipeComponentIterator_const child)
{
	m_stepsContainer.erase(child);
}

void CompositeStep::deleteAllComponents(void)
{
	m_stepsContainer.clear();
}

int CompositeStep::getDuration() const
{
	int sommeDuration = 0;

	for (auto&& step : m_stepsContainer) {
		sommeDuration += step->getDuration();
	}
	return sommeDuration;
}

std::ostream& CompositeStep::printToStream(std::ostream& o) const
{
	o << m_description << std::endl;
	int i = 1;
	m_indent++;
	for (auto&& step : m_stepsContainer) {
		indent(o) << i++ << " " << *step;
	}
	m_indent--;
	return o;// << std::endl;
}
