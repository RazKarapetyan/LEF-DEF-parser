#ifndef __CELL__
#define __CELL__

#include<vector>
class CPin;

class CCell
{
public:
	CCell(std::vector<CPin>, std::string name);
	~CCell();
	double area() const;
	std::string name() const;
private:
	std::vector<CPin> m_pins;
	std::string m_name;
};

#endif // __CELL__
