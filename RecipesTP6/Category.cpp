#include <string>

#include "Category.h"
#include "AbsProduct.h"

int Category::m_indent = 0;

Category::Category(std::string name) : AbsCatalogComponent(name)
{
}

Category::Category(const Category& mdd)
	: AbsCatalogComponent(mdd.m_name)
{
	// D + C
	for (auto it = mdd.cbegin(); it != mdd.cend(); it++)
	{
		addCatalogComponent(*it);
	}
}

Category* Category::clone(void) const
{
	// D C
	return new Category(*this);
}

AbsCatalogComponent& Category::addCatalogComponent(const AbsCatalogComponent& member)
{
	// D
	m_products.push_back(CatalogComponentPtr(member.clone()));
	return *m_products.back();
}

CatalogComponentIterator Category::begin()
{
	return m_products.begin();
}

CatalogComponentIterator_const Category::cbegin() const
{
	return m_products.cbegin();
}

CatalogComponentIterator_const Category::cend() const
{
	return m_products.cend();
}

CatalogComponentIterator Category::end()
{
	return m_products.end();
}

void Category::deleteCatalogComponent(CatalogComponentIterator_const child)
{
	m_products.erase(child);
}

void Category::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments de la catégorie

	/*for (CatalogComponentBaseIterator it = begin(); it != end(); it++) {
		m_products.remove(*it);
	}*/
	m_products.clear();

}

const AbsProduct* Category::findProduct(std::string productName) const
{
	// À compléter pour itérer sur les éléments contenus dans la catégorie à la recherche d'un produit
	// portant le nom reçu en argument. Si aucun produit n'est trouvé on retourne nullptr
	const AbsProduct* foundProduct = nullptr;

	for (auto&& element : m_products)
	{
		foundProduct = element->findProduct(productName);
		if (foundProduct != nullptr)
			break;
	}
	
	return foundProduct;
}

std::ostream& Category::printToStream(std::ostream& o) const
{
	// À compléter pour imprimer sur un stream une catégorie et ses produits
	o << "Category: " << m_name << std::endl;
	
	m_indent++;
	for (auto it = cbegin(); it != cend(); it++)
	{
		indent(o);
		o << *it;
	}
	m_indent--;
	o << std::endl;
	return o;
}

std::ostream& Category::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}
