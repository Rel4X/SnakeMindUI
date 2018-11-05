/*
 * Game.cpp
 *
 *  Created on: Jun 25, 2018
 *      Author: nonmaislol
 */

#include "Game.hh"

unsigned long long	Seed()
{
	unsigned int lo,hi;
	__asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
	return ((unsigned long long)hi << 32) | lo;
}

uint			RDM(uint min, uint max)
{
	static	bool	init = false;

	if (init == false)
	{
		std::srand(Seed());
		init = true;
	}
	return (std::rand() % (max - min + 1) + min);
}

Game::Game(uint size)
{
	this->p_size = size;
	if (this->p_size < 10) { this->p_size = 50; }
	this->p_map = std::make_unique<uint[]>(this->p_size * this->p_size);
	this->RestartGame();
}

Game::~Game()
{

}

uint		Game::GetElement(uint x, uint y) const
{
	return (this->p_map[y * this->p_size + x]);
}

void		Game::SetElement(uint x, uint y, uint v)
{
	this->p_map[y * this->p_size + x] = v;
}

void		Game::RestartGame()
{
	memset(this->p_map.get(), EMPTY, this->p_size * this->p_size * sizeof(uint));
	for (int y = 0; y < this->p_size; ++y)
	{
		for (int x = 0; x < this->p_size; ++x)
		{
			if (y == 0 || x == 0 || x == this->p_size - 1 || y == this->p_size - 1)
				this->SetElement(x, y, WALL);
		}
	}
	this->SetElement(10, 10, SHEAD);
	this->SetElement(9, 10, SBODY);
	this->SetElement(8, 10, STAIL);
	this->p_snake.clear();
	this->p_snake.push_back(std::pair<uint, uint>(10, 10));
	this->p_snake.push_back(std::pair<uint, uint>(9, 10));
	this->p_snake.push_back(std::pair<uint, uint>(8, 10));
	this->p_dir = RIGHT;
	this->p_score = 0;
	this->p_moveleft = MOVELEFT;
	this->p_state = RUNNING;

	this->FoodPop();
}

void		Game::ShowMap() const
{
	for (int i = 0; i < this->p_size; ++i)
	{
		for (int j = 0; j < this->p_size; ++j)
		{
			std::cout << this->GetElement(j, i);
		}
		std::cout << std::endl;
	}
}

void		Game::Step()
{
	static int	directions[4][2] = {
			{ 0, -1 },
			{ 1, 0 },
			{ 0, 1 },
			{ -1, 0 }
	};
	uint	shebang;

    shebang = this->GetElement(this->p_snake.front().first + directions[this->p_dir][0],
            this->p_snake.front().second + directions[this->p_dir][1]);
	if (shebang == EMPTY || shebang == FOOD)
	{
		if (this->p_score < 100000)
			++this->p_score;
		--this->p_moveleft;
		this->SetElement(this->p_snake.front().first, this->p_snake.front().second, SBODY);
        this->p_snake.push_front(std::pair<uint, uint>(this->p_snake.front().first + directions[this->p_dir][0],
                this->p_snake.front().second + directions[this->p_dir][1]));
		this->SetElement(this->p_snake.front().first, this->p_snake.front().second, SHEAD);
		if (shebang == FOOD)
		{
			this->p_score += APPLEPOINT;
			this->p_moveleft = MOVELEFT;
			this->FoodPop();
		}
		else
		{
			this->SetElement(this->p_snake.back().first, this->p_snake.back().second, EMPTY);
			this->p_snake.pop_back();
		}
		this->SetElement(this->p_snake.back().first, this->p_snake.back().second, STAIL);
		if (this->p_moveleft == 0)
			this->p_state = LOST;
	}
	else
	{
		this->p_state = LOST;
	}
}

bool	Game::ChangeDir(uint d)
{
	this->p_dir = d; // TO REMOVE WHEN LIVE
	return (true);
	if (!((this->p_dir == LEFT && d == RIGHT) || (this->p_dir == RIGHT && d == LEFT)
			|| (this->p_dir == TOP && d == DOWN) || (this->p_dir == DOWN && d == TOP)
			|| (this->p_dir == TOP && d == TOP) || (this->p_dir == DOWN && d == DOWN)
			|| (this->p_dir == RIGHT && d == RIGHT) || (this->p_dir == LEFT && d == LEFT)))
	{
		this->p_dir = d;
		return (true);
	}
	return (false);
}

bool		Game::IsBodyPart(uint x, uint y) const
{
	if (this->GetElement(x, y) == SHEAD || this->GetElement(x, y) == SBODY
		|| this->GetElement(x, y) == STAIL)
		return (true);
	return (false);
}

void		Game::FoodPop()
{
	bool	poped = false;
	uint	x, y;

	while (poped == false)
	{
		x = RDM(0, this->p_size - 1);
		y = RDM(0, this->p_size - 1);
		if (this->GetElement(x, y) == EMPTY)
		{
			this->p_food.first = x;
			this->p_food.second = y;
			this->SetElement(x, y, FOOD);
			poped = true;
		}
	}
}
