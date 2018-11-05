/*
 * Game.hh
 *
 *  Created on: Jun 25, 2018
 *      Author: nonmaislol
 */

#ifndef 	GAME_HH_
#define 	GAME_HH_

//#define		BASE_SIZE	50

#define		EROOR		0
#define		RUNNING		1
#define		LOST		2

#define		EMPTY		0
#define		SHEAD		1
#define		SBODY		2
#define		STAIL		3
#define		FOOD		4
#define		WALL		5

#define		TOP			0
#define		RIGHT		1
#define		DOWN		2
#define		LEFT		3

//#define		X2			0
//#define		Y2			1


#include	<iostream>
#include	<memory>
#include	<utility>
#include	<vector>
#include	<list>
#include	<string.h>

typedef		unsigned int						uint;
typedef		std::pair<uint, uint>				Coord;
typedef		std::list<std::pair<uint, uint>>	Snake;

#define		APPLEPOINT		1000
#define		MOVELEFT		500

class 		Game
{
private:
	int						p_size;
	std::unique_ptr<uint[]>	p_map;
	Snake					p_snake;
	Coord					p_food;
	uint					p_dir;
	uint					p_score;
	uint					p_moveleft;
	char					p_state;

public:
	Game(uint size = 50);
	virtual ~Game();

public:
	uint	GetElement(uint x, uint y) const;
	void	SetElement(uint x, uint y, uint v);

public:
	int								GetSize() const		{ return (this->p_size); }
	const std::unique_ptr<uint[]>&	GetMap() const		{ return (this->p_map); }
	const Snake&					GetSnake() const	{ return (this->p_snake); }
	uint							GetBodySize() const	{ return (this->p_snake.size()); }
	const std::pair<uint, uint>&	GetHead() const		{ return (this->p_snake.front()); }
	const std::pair<uint, uint>&	GetFood() const		{ return (this->p_food); }
	uint							GetScore() const	{ return (this->p_score); }
	char							GetState() const	{ return (this->p_state); }

public:
	void	RestartGame();
	void	ShowMap() const;
	void	Step();
	bool	ChangeDir(uint d);
	bool	IsBodyPart(uint x, uint y) const;

private:
	void	FoodPop();
};

#endif /* GAME_HH_ */
