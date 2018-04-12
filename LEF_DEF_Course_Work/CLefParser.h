#ifndef __LEFPARSER__
#define __LEFPARSER__

#include <string>
#include "CCell.h"

class CLefParser
{
public:
	CLefParser(std::string);
	~CLefParser();
	std::vector<CCell> retrieveCells();
private:
	std::string file_name;
	std::vector<CCell> cells;
	void parse();
};

#endif //__LEFPARSER__
