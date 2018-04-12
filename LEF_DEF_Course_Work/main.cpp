#include <iostream>
#include "CCell.h"
#include "CLefParser.h"

int main()
{

	CLefParser parser("aaa");
	//std::vector<CCell> res = 
	parser.retrieveCells();

	std::cout << "cell count = " << parser.cells.size() << std::endl;
	system("pause");
	return 0;
}
