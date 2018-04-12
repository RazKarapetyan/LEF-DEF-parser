#ifndef __LEFPARSER__
#define __LEFPARSER__

#include <string>
#include "CCell.h"
#include "CPin.h"

class CLefParser
{
public:
	CLefParser(std::string);
	~CLefParser();
	std::vector<CCell> cells;

	std::vector<CCell> retrieveCells();
private:
	std::string file_name;
	//std::vector<CCell> cells;
	void parse();
	CCell retrieveOneCell(const std::vector<std::string>, int ,int, const std::string&);
	CPin retrieveOnePin(const std::vector<std::string>, int, int, const std::string&);
};

#endif //__LEFPARSER__
