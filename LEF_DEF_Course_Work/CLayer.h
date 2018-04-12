#ifndef __LAYER__
#define __LAYER__

#include <string>
#include <vector>
#include "CRectangle.h"

class CLayer
{
public:
	CLayer(std::vector<CRectangle>, std::string);
	~CLayer();
private:
	std::string m_type;
	std::vector<CRectangle> m_rectangles;
};

#endif // __LAYER__
