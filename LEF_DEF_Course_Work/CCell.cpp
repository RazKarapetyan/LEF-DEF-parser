#include "CCell.h"
#include "CPin.h"

CCell::CCell(std::vector<CPin> pins, std::string name) :m_pins(pins), m_name(name)
{
}


CCell::~CCell()
{
}

double CCell::area() const
{
	double area = 0;
	for (auto it = m_pins.begin(); it != m_pins.end(); ++it)
		area += it->area();

	return area;
}

std::string CCell::name() const
{
	return m_name;
}
