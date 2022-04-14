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
    for (auto it = mdd.cbegin(); it != mdd.cend(); it++)
    {
        addCatalogComponent(*it);
    }
}

Category* Category::clone(void) const
{
    return new Category(*this);
}

AbsCatalogComponent& Category::addCatalogComponent(const AbsCatalogComponent& member)
{
    m_products.push_back(std::make_unique<Category>(member.getName()));
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
    m_products.clear();
}

const AbsProduct* Category::findProduct(std::string productName) const
{
    const AbsProduct* foundProduct = nullptr;

    for (auto it = cbegin(); it != cend(); it++)
    {
        foundProduct = it->findProduct(productName);
    }
    return foundProduct;
}

std::ostream& Category::printToStream(std::ostream& o) const
{
    o << "Category: " << m_name << std::endl;
    
    m_indent++;
    for (auto it = cbegin(); it != cend(); it++)
    {
        indent(o);
        o << *it;
    }
    m_indent--;

    return o;
}

std::ostream& Category::indent(std::ostream& o) const
{
    for (int i = 0; i < m_indent; ++i)
        o << '\t';
    return o;
}