#ifndef __PIN__
#define __PIN__

#include <vector>
#include "CLayer.h"
class CPin
{
public:
	CPin(std::vector<CLayer>, std::string);
	~CPin();
private:
	std::vector<CLayer> m_layers;
	std::string m_type;
};

#endif //__PIN__
