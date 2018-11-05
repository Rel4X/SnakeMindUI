/*
 * SnakeSquad.h
 *
 *  Created on: Oct 6, 2018
 *      Author: nonmaislol
 */

#ifndef SNAKESQUAD_H_
#define SNAKESQUAD_H_

#include	<vector>
#include	<memory>
#include	"SnakeBrain.hh"
#include	"BrainMemory.h"

#define	PSHR(Value)		std::shared_ptr<Value>

#define	SNAKEPOP		100
#define	WILLSEX			20
#define	MUTATIONRATE	50
#define	MUTATIONFORCE	0.5

typedef	unsigned int	uint;

class 	SnakeSquad
{
private:
	std::vector<PSHR(SnakeBrain)>		p_dudes;
	Game								p_board;

public:
	SnakeSquad();
	virtual ~SnakeSquad();

public:
	PSHR(SnakeBrain)	GetDude(uint i)	{ return (this->p_dudes[i]); }

public:
	void		Darwin();
	void		Darwin(uint generation);
	void		Evaluate();
	void		Order();
	void		BabyBoom();
	void		HaveSex(uint dad, uint mum, uint son, uint dau);
	void		Tchernorbyl();
	void		ShowScores();
};

#endif /* SNAKESQUAD_H_ */
