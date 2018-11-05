/*
 * RandomMachine.h
 *
 *  Created on: Oct 3, 2018
 *      Author: nonmaislol
 */

#ifndef RANDOMMACHINE_H_
#define RANDOMMACHINE_H_

#include <iostream>

typedef	unsigned int	uint;

class 	RandomMachine
{
private:
	static	bool			p_init;

private:
	RandomMachine() 			{ }
	virtual ~RandomMachine() 	{ }

private:
	static unsigned long long		Seed();

public:
	static uint						RDM(uint, uint);
};

#endif /* RANDOMMACHINE_H_ */
