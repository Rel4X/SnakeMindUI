/*
 * SnakeBrain.h
 *
 *  Created on: Jun 25, 2018
 *      Author: nonmaislol
 */

#ifndef 	SNAKEBRAIN_HH_
#define 	SNAKEBRAIN_HH_

#include	<iostream>
#include	<fstream>
#include	"Game.hh"
#include	"NeuralNetwork.h"

#define		APPLEPOWER	30.0

class 		SnakeBrain
{
private:
	Vector			p_sensors;
	NeuralNetwork	p_brain;
	uint			p_score;

public:
	SnakeBrain();
	virtual ~SnakeBrain();

public:
	NeuralNetwork&	GetBrain()	{ return (this->p_brain); }
	uint			GetScore()	{ return (this->p_score); }

	void			SetScore(uint s)	{ this->p_score = s; }

public:
	int				TakeDecision(const Game& g);

};

#endif 		/* SNAKEBRAIN_HH_ */
