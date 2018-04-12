#pragma once
class CRectangle
{
public:
	CRectangle(double, double, double, double);
	~CRectangle();
	double area() const;
private:
	double m_x;
	double m_y;
	double m_width;
	double m_height;
};

