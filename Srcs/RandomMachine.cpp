/*
 * RandomMachine.cpp
 *
 *  Created on: Oct 3, 2018
 *      Author: nonmaislol
 */

#include "RandomMachine.h"

bool					RandomMachine::p_init = false;

unsigned long long		RandomMachine::Seed()
{
	unsigned int lo,hi;
	__asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
	return ((unsigned long long)hi << 32) | lo;
}

uint					RandomMachine::RDM(uint min, uint max)
{
	if (RandomMachine::p_init == false)
	{
		std::srand(Seed());
		RandomMachine::p_init = true;
	}
	return (std::rand() % (max - min + 1) + min);
}
