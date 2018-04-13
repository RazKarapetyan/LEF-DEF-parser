#include "CPin.h"

CPin::CPin(std::vector<CLayer> layers, std::string type):m_layers(layers),m_type(type)
{
}


CPin::~CPin()
{
}

double  CPin::area() const
{
	double area = 0;
	for (auto it = m_layers.begin(); it != m_layers.end(); ++it)
		area += it->area();

	return area;
}
