#ifndef __CELL__
#define __CELL__

#include<vector>
class CPin;

class CCell
{
public:
	CCell(std::vector<CPin>, std::string name);
	~CCell();
private:
	std::vector<CPin> m_pins;
	std::string m_name;
};

#endif // __CELL__
