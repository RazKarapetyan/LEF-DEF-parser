#include "CLefParser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include "utils.h"

CLefParser::CLefParser(std::string fname) : file_name(fname)
{
}

CLefParser::~CLefParser()
{
}

std::vector<CCell> CLefParser::retrieveCells()
{
	parse();

	return std::vector<CCell>();
}

void CLefParser::parse()
{	
	// lef_example.lef
	std::ifstream file("lef_example.lef");
	/*std::string line;
	std::string cellName;

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::vector<std::string> words;
		std::string word;

		while (ss >> word)
			words.push_back(word);
		 
		if (words.size() && words[0] == MACRO)
		{
			cellName = words[1];
			std::cout << "cellName = " << cellName << std::endl;
		} 
	}*/

	std::vector<std::string> words;
	std::copy(std::istream_iterator<std::string>(file),
		std::istream_iterator<std::string>(),
		std::back_inserter(words));

	int cellIndex = 0;
	int pinIndex = 0;
	std::string cellName;
	std::string pinName;


	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i] == MACRO)
		{
			cellName = words[i + 1];
			cellIndex = i;
			std::cout << "Cell name = " << cellName << std::endl;

			for (int j = cellIndex; j < words.size(); ++j)
			{
				if (words[j] == PIN)
				{
					pinName = words[j + 1];
					std::cout << "Pin name = " << pinName << std::endl;

				}
			}
		}	
	}

}
