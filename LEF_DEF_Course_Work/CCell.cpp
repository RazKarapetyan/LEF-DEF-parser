#include "CCell.h"
#include "CPin.h"

CCell::CCell(std::vector<CPin> pins, std::string name) :m_pins(pins), m_name(name)
{
}


CCell::~CCell()
{
}
