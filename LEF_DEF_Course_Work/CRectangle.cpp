#include "CRectangle.h"

CRectangle::CRectangle(double x, double y, double width, double height)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
}


CRectangle::~CRectangle()
{
}

double CRectangle::area() const
{
	return m_width * m_height;
}
