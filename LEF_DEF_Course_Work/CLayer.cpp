#include "CLayer.h"

CLayer::CLayer(std::vector<CRectangle> rects, std::string type) : m_rectangles(rects), m_type(type)
{
}


CLayer::~CLayer()
{
}

double  CLayer::area() const
{
	double area = 0;
	for (auto it = m_rectangles.begin(); it != m_rectangles.end(); ++it)
		area += it->area();

	return area;
}
