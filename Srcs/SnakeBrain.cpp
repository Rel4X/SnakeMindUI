/*
 * SnakeBrain.cpp
 *
 *  Created on: Jun 25, 2018
 *      Author: nonmaislol
 */

#include "SnakeBrain.hh"

SnakeBrain::SnakeBrain() :
p_brain(2)
{
	Layer		lhidden(32, 17);
	Layer		loutput(4, 32);

	lhidden.Generate();
	loutput.Generate();
	this->p_brain.SetLayers({lhidden, loutput});

	this->p_sensors.resize(17);
}

SnakeBrain::~SnakeBrain()
{

}

int				SnakeBrain::TakeDecision(const Game& g)
{
	std::fill(this->p_sensors.begin(), this->p_sensors.end(), 0.0);

	if (g.GetHead().second == g.GetFood().second)
	{
		if (g.GetHead().first > g.GetFood().first)
		{
			//std::cout << "LEFT" << std::endl;
			this->p_sensors[7] = APPLEPOWER;
		}
		else
		{
			//std::cout << "RIGHT" << std::endl;
			this->p_sensors[3] = APPLEPOWER;
		}
	}
	else if (g.GetHead().first == g.GetFood().first)
	{
		if (g.GetHead().second > g.GetFood().second)
		{
			//std::cout << "TOP" << std::endl;
			this->p_sensors[1] = APPLEPOWER;
		}
		else
		{
			//std::cout << "BOTTOM" << std::endl;
			this->p_sensors[5] = APPLEPOWER;
		}
	}
	else if (g.GetHead().first > g.GetFood().first
			&& g.GetHead().second > g.GetFood().second)
	{
		//std::cout << "TOP LEFT" << std::endl;
		this->p_sensors[0] = APPLEPOWER;
	}
	else if (g.GetHead().first > g.GetFood().first
			&& g.GetHead().second < g.GetFood().second)
	{
		//std::cout << "BOT LEFT" << std::endl;
		this->p_sensors[6] = APPLEPOWER;
	}
	else if (g.GetHead().first < g.GetFood().first
			&& g.GetHead().second < g.GetFood().second)
	{
		//std::cout << "BOT RIGHT" << std::endl;
		this->p_sensors[4] = APPLEPOWER;
	}
	else if (g.GetHead().first < g.GetFood().first
			&& g.GetHead().second > g.GetFood().second)
	{
		//std::cout << "TOP RIGHT" << std::endl;
		this->p_sensors[2] = APPLEPOWER;
	}

	//std::cout << "Dist Left: " << g.GetHead().first << std::endl;
	this->p_sensors[8] = g.GetHead().first;
	//std::cout << "Dist Right: " << g.GetSize() - g.GetHead().first - 1 << std::endl;
	this->p_sensors[10] = g.GetSize() - g.GetHead().first - 1;
	//std::cout << "Dist Top: " << g.GetHead().second << std::endl;
	this->p_sensors[9] = g.GetHead().second;
	//std::cout << "Dist Bottom: " << g.GetSize() - g.GetHead().second - 1 << std::endl;
	this->p_sensors[11] = g.GetSize() - g.GetHead().second - 1;


	// Body Left
	for (uint x = g.GetHead().first - 1; x > 0; --x)
	{
		if (g.IsBodyPart(x, g.GetHead().second))
		{
			this->p_sensors[12] = g.GetHead().first - x;
			break;
		}
	}
	if (this->p_sensors[12] == 0)
		this->p_sensors[12] = this->p_sensors[8];
	// Body Top
	for (uint y = g.GetHead().second - 1; y > 0; --y)
	{
		if (g.IsBodyPart(g.GetHead().first, y))
		{
			this->p_sensors[13] = g.GetHead().second - y;
			break;
		}
	}
	if (this->p_sensors[13] == 0)
		this->p_sensors[13] = this->p_sensors[9];
	// Body Right
	for (uint x = g.GetHead().first + 1; x < (uint)g.GetSize()  - 1; ++x)
	{
		if (g.IsBodyPart(x, g.GetHead().second))
		{
			this->p_sensors[14] = x - g.GetHead().first;
			break;
		}
	}
	if (this->p_sensors[14] == 0)
		this->p_sensors[14] = this->p_sensors[10];
	// Body Bot
	for (uint y = g.GetHead().second + 1; y < (uint)g.GetSize() - 1 ; ++y)
	{
		if (g.IsBodyPart(g.GetHead().first, y))
		{
			this->p_sensors[15] = y - g.GetHead().second;
			break;
		}
	}
	if (this->p_sensors[15] == 0)
		this->p_sensors[15] = this->p_sensors[11];

	this->p_sensors[16] = g.GetBodySize();

	if (this->p_brain.Compute(this->p_sensors) == false)
		std::cout << "Compute Failure." << std::endl;

	uint 	decision = 0;
	double 	bigger = this->p_brain.GetOutputs()[0];
	for (uint i = 1; i < this->p_brain.GetOutputs().size(); ++i)
	{
		if (this->p_brain.GetOutputs()[i] > bigger)
		{
			bigger = this->p_brain.GetOutputs()[i];
			decision = i;
		}
	}

	return (decision);
}

