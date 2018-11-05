/*
 * BrainMemory.h
 *
 *  Created on: Oct 14, 2018
 *      Author: nonmaislol
 */

#ifndef BRAINMEMORY_H_
#define BRAINMEMORY_H_

#include	<fstream>
#include	<string>
#include	"SnakeBrain.hh"

class 	BrainMemory
{
public:
	BrainMemory();
	virtual ~BrainMemory();

public:
	bool		Memorize(const char* fname, SnakeBrain& brain);
	bool		Remember(const char* fname, SnakeBrain& brain);

private:
	char*		LoadFile(const char* fname);
};

#endif /* BRAINMEMORY_H_ */
