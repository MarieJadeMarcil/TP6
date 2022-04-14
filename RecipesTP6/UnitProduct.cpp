#include <string>

#include "UnitProduct.h"

UnitProduct::UnitProduct(std::string name, std::string origin, int quantity, float price)
	: AbsProduct(name, origin), m_quantity(quantity), m_price(price)
{
}

AbsCatalogComponent * UnitProduct::clone(void) const 
{
	return new UnitProduct(*this); 
}

void UnitProduct::setQuantityPrice(int quantity, float price)
{
	m_quantity = quantity;
	m_price = price;
}

float UnitProduct::getPrice() const
{ 
	return m_price; 
}

int UnitProduct::getQuantity() const 
{ 
	return m_quantity; 
}

std::ostream & UnitProduct::printToStream(std::ostream & o) const
{
	return o << m_name << "(from " << getOrigin() << ") " 
			 << m_price << "/pc.\n";
}
