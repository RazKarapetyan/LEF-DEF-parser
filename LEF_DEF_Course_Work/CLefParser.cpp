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

	return this->cells;
}

void CLefParser::parse()
{	
	std::ifstream file(file_name);

	std::vector<std::string> words;
	std::copy(std::istream_iterator<std::string>(file),
		std::istream_iterator<std::string>(),
		std::back_inserter(words));

	int cellStartIndex = 0;
	int cellEndIndex = 0;
	int pinIndex = 0;
	std::string cellName;
	std::string pinName;

	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i] == MACRO)
		{
			cellName = words[i + 1];
			cellStartIndex = i + 1;

			for (int j = cellStartIndex + 1; j < words.size(); ++j)
			{
				if (words[j] == cellName && words[j - 1] == END)
					cellEndIndex = j;
			 }

			//std::cout << "start cell " << words[cellStartIndex] << " ,end cell " << words[cellEndIndex] << std::endl;
			CCell cell = retrieveOneCell(words, cellStartIndex, cellEndIndex, cellName);
			cells.push_back(cell);
		}	
	}

	//std::cout << "=========================== Cells.count = " << cells.size()<<std::endl;
}

CCell CLefParser::retrieveOneCell(const std::vector<std::string> words, int start, int end, const std::string& name)
{
	std::vector<CPin> pins;
	std::string pinName;
	int pinStartIndex = 0;
	int pinEndIndex = 0;

	for (int i = start; i < end; i++)
	{
		if (words[i] == PIN)
		{
			pinName = words[i + 1];
			pinStartIndex = i;

			for (int j = pinStartIndex + 1; j < end; ++j)
			{
				if (words[j] == pinName && words[j - 1] == END)
					pinEndIndex = j;
			}

			//std::cout << "start Pin " << words[pinStartIndex] << " ,= " << words[pinEndIndex] << std::endl;
			CPin pin = retrieveOnePin(words, pinStartIndex, pinEndIndex, pinName);
			pins.push_back(pin);
		}
	}
	
	//std::cout << "=========================== pins.count = " << pins.size() << std::endl;

	return CCell(pins, name);
}

CPin CLefParser::retrieveOnePin(const std::vector<std::string> words, int start, int end, const std::string& name)
{
	std::vector<CRectangle> rects;
	std::vector<CLayer> layers;
	std::string layerName;
	int layerStartIndex = 0;
	int layerEndIndex = 0;
	int rectStartIndex = 0;


	for (int i = start; i < end; i++)
	{
		if (words[i] == LAYER)
		{
			layerName = words[i + 1];
			layerStartIndex = i;
			rectStartIndex = layerStartIndex + 3;
			//std::cout << "Layer name " << layerName << std::endl;

			double x = std::stod(words[rectStartIndex + 1]);
			double y = std::stod(words[rectStartIndex + 2]);
			double weight = std::stod(words[rectStartIndex + 3]);
			double height = std::stod(words[rectStartIndex + 4]);
			CRectangle rect(x, y, weight, height);
			rects.push_back(rect);
			//std::cout << "Rect coordinates " << x << " " << y << " " << weight << " " << height << std::endl;

			/* Populate to find rects more than one */
			while (words[rectStartIndex + 6] == RECT)
			{
				rectStartIndex = rectStartIndex + 6;
				double x = std::stod(words[rectStartIndex + 1]);
				double y = std::stod(words[rectStartIndex + 2]);
				double weight = std::stod(words[rectStartIndex + 3]);
				double height = std::stod(words[rectStartIndex + 4]);
				CRectangle rect(x, y, weight, height);
				rects.push_back(rect);
				//std::cout << "Rect coordinates " << x << " " << y << " " << weight << " " << height << std::endl;
			}

			CLayer layer(rects, layerName);
			layers.push_back(layer);
			//std::cout << "=========================== layers.count = " << layers.size() << std::endl;

		}	
	}

	return CPin(layers, name);
}

int CLefParser::parsedCellCount() const
{
	return cells.size();
}
