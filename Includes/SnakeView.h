/*
 * SnakeView.h
 *
 *  Created on: Oct 18, 2018
 *      Author: nonmaislol
 */

#ifndef SNAKEVIEW_H_
#define SNAKEVIEW_H_

#include	<SFML/Graphics.hpp>
#include	"SnakeBrain.hh"
#include	"Game.hh"

#define		FRAMERATE	20.0

typedef	unsigned int	uint;

class 	SnakeView
{
public:
	SnakeView();
	virtual ~SnakeView();

public:
	void		Play(SnakeBrain& brain);
};

#endif /* SNAKEVIEW_H_ */
