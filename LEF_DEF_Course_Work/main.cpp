#include <iostream>
#include "CCell.h"
#include "CLefParser.h"
#include <thread>
#include <mutex>

void area_calculator(const std::vector<CCell>& cells, 
		     int start, int end, double& result)
{
	for (int i = start; i < end; ++i)
		result += cells[i].area();
}

int main()
{
	// lef_example.lef
	// raz.txt
	CLefParser parser("lef_example.lef");
	std::vector<CCell> res = parser.retrieveCells();
	int cell_count = parser.parsedCellCount();
	double result = 0;

	for (int i = 0; i < cell_count; i+=5)
	{
		int start = i;
		int end = (i + 5 > cell_count) ? cell_count-1 : i+5;
		std::thread th(area_calculator, std::cref(res), start, end,std::ref(result));
		th.join();
	}
	std::cout << "cell count = " << cell_count << std::endl;

	//Single Threaded Example
	/*for (int i = 0; i < res.size(); ++i) 
		result += res[i].area();*/

	std::cout << " result = " << result << std::endl;
	system("pause");
	return 0;
}
