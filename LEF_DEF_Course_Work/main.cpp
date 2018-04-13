#include <iostream>
#include "CCell.h"
#include "CLefParser.h"

int main()
{
	// lef_example.lef
	CLefParser parser("raz.txt");
	std::vector<CCell> res = parser.retrieveCells();
	std::cout << "cell count = " << parser.parsedCellCount() << std::endl;
	
	for (int i = 0; i < res.size(); ++i) 
		std::cout << "Area = " << res[i].area() << std::endl;

	system("pause");
	return 0;
}
