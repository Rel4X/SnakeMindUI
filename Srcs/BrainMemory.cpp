/*
 * BrainMemory.cpp
 *
 *  Created on: Oct 14, 2018
 *      Author: nonmaislol
 */

#include "BrainMemory.h"

BrainMemory::BrainMemory()
{

}

BrainMemory::~BrainMemory()
{

}

bool			BrainMemory::Memorize(const char* fname, SnakeBrain& brain)
{

	std::ofstream	os(fname);

	if (!os.is_open()) { return (false); }
	for (uint l = 0; l < brain.GetBrain().GetNLayers(); ++l)
	{
		for (uint n = 0; n < brain.GetBrain().GetLayers()[l].GetNNeurons(); ++n)
		{
			for (uint w = 0; w < brain.GetBrain().GetLayers()[l].GetNeurons()[n].size(); ++w)
			{
				os << "L: " << l + 1 << " - N: " << n + 1 << " - W: " << w + 1 << " = ";
				os << brain.GetBrain().GetLayers()[l].GetNeurons()[n][w];
				os << std::endl;
			}
		}
		os << "L: " << l + 1 << " Bias = " << brain.GetBrain().GetLayers()[l].GetBias();
		os << std::endl;
	}
	os.close();
	return (true);
}

bool			BrainMemory::Remember(const char* fname, SnakeBrain& brain)
{
	std::ifstream	is(fname);
	std::string		buffer;

	if (!is.is_open()) { return (false); }

	for (uint l = 0; l < brain.GetBrain().GetNLayers(); ++l)
	{
		for (uint n = 0; n < brain.GetBrain().GetLayers()[l].GetNNeurons(); ++n)
		{
			for (uint w = 0; w < brain.GetBrain().GetLayers()[l].GetNeurons()[n].size(); ++w)
			{
				if (std::getline(is, buffer))
				{
					buffer = buffer.substr(buffer.find_first_of('=') + 2);
					brain.GetBrain().GetLayers()[l].GetNeurons()[n][w] = std::stod(buffer);
				}
			}
		}
		if (std::getline(is, buffer))
		{
			buffer = buffer.substr(buffer.find_first_of('=') + 2);
			brain.GetBrain().GetLayers()[l].SetBias(std::stod(buffer));
		}
	}
	return (true);
}

char*			BrainMemory::LoadFile(const char* fname)
{
	std::fstream	file;
	int				fsize;
	char*			data;

	file.open(fname, std::ios::in | std::ios::out);
	if (file.is_open())
	{
		file.seekg(0, std::ios_base::end);
		fsize = file.tellg();
		file.seekg(0, std::ios_base::beg);
		data = new char[fsize + 1]();
		memset(data, 0, fsize + 1);
		file.read(data, fsize);
		file.close();
		return (data);
	}
	return (0);
}
