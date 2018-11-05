/*
 * SnakeSquad.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: nonmaislol
 */

#include "SnakeSquad.h"

SnakeSquad::SnakeSquad()
{
	this->p_dudes.resize(SNAKEPOP);

	for (uint i = 0; i < SNAKEPOP; ++i)
	{
		this->p_dudes[i] = std::make_shared<SnakeBrain>();
	}
}

SnakeSquad::~SnakeSquad()
{

}

void			SnakeSquad::Darwin()
{
	BrainMemory	bm;
	uint		gen = 0;

    while (1)
	{
		this->Evaluate();
        this->Order();
		this->BabyBoom();
		this->Tchernorbyl();
		++gen;
	}
}

void			SnakeSquad::Darwin(uint	generation)
{
	BrainMemory	bm;

	for (uint gen = 0; gen < generation; ++gen)
	{
		this->Evaluate();
        this->Order();
		this->BabyBoom();
		this->Tchernorbyl();
		++gen;
	}
}

void			SnakeSquad::Evaluate()
{
	bool		state;

	for (uint i = 0; i < SNAKEPOP; ++i)
	{
		state = true;
		this->p_board.RestartGame();
		while (state)
		{
			this->p_board.Step();
			this->p_board.ChangeDir(this->p_dudes[i]->TakeDecision(this->p_board));
			if (this->p_board.GetState() == LOST)
			{
				state = false;
				this->p_dudes[i]->SetScore(this->p_board.GetScore());
			}
		}
	}
}

void			SnakeSquad::Order()
{
	PSHR(SnakeBrain)	tmp;
	uint				i;

	i = 0;
	while (i < this->p_dudes.size() - 1)
	{
		if (this->p_dudes[i]->GetScore() < this->p_dudes[i + 1]->GetScore())
		{
			tmp = this->p_dudes[i];
			this->p_dudes[i] = this->p_dudes[i + 1];
			this->p_dudes[i + 1] = tmp;
			i = 0;
		}
		else
		{
			++i;
		}
	}
}

void			SnakeSquad::BabyBoom()
{
	uint		i;

	i = 0;
	while (i < WILLSEX)
	{
		this->HaveSex(i, i + 1, (SNAKEPOP - 1) - i, (SNAKEPOP - 1) - (i + 1));
		i += 2;
	}
}

void			SnakeSquad::HaveSex(uint dad, uint mum, uint son, uint dau)
{
	uint		n_layers;
	uint		n_neurons;
	uint		n_inputs;
	uint		destiny;

	n_layers = this->p_dudes[dad]->GetBrain().GetNLayers();
	for (uint i = 0; i < n_layers; ++i)
	{
		n_neurons = this->p_dudes[dad]->GetBrain().GetLayers()[i].GetNNeurons();
		for (uint j = 0; j < n_neurons; ++j)
		{
			n_inputs = this->p_dudes[dad]->GetBrain().GetLayers()[i].GetNeurons()[j].size();
			for (uint k = 0; k < n_inputs; ++k)
			{
				destiny = RandomMachine::RDM(0, 1);
				if (destiny == 0)
				{
					this->p_dudes[son]->GetBrain().GetLayers()[i].GetNeurons()[j][k] =
							this->p_dudes[dad]->GetBrain().GetLayers()[i].GetNeurons()[j][k];
					this->p_dudes[dau]->GetBrain().GetLayers()[i].GetNeurons()[j][k] =
							this->p_dudes[mum]->GetBrain().GetLayers()[i].GetNeurons()[j][k];
				}
				else
				{
					this->p_dudes[son]->GetBrain().GetLayers()[i].GetNeurons()[j][k] =
							this->p_dudes[mum]->GetBrain().GetLayers()[i].GetNeurons()[j][k];
					this->p_dudes[dau]->GetBrain().GetLayers()[i].GetNeurons()[j][k] =
							this->p_dudes[dad]->GetBrain().GetLayers()[i].GetNeurons()[j][k];
				}
			}
		}
		destiny = RandomMachine::RDM(0, 1);
		if (destiny == 0)
		{
			this->p_dudes[son]->GetBrain().GetLayers()[i].SetBias(this->p_dudes[dad]->GetBrain().GetLayers()[i].GetBias());
			this->p_dudes[dau]->GetBrain().GetLayers()[i].SetBias(this->p_dudes[mum]->GetBrain().GetLayers()[i].GetBias());
		}
		else
		{
			this->p_dudes[son]->GetBrain().GetLayers()[i].SetBias(this->p_dudes[mum]->GetBrain().GetLayers()[i].GetBias());
			this->p_dudes[dau]->GetBrain().GetLayers()[i].SetBias(this->p_dudes[dad]->GetBrain().GetLayers()[i].GetBias());
		}
	}
}

void			SnakeSquad::Tchernorbyl()
{
	uint		n_layers;
	uint		n_neurons;
	uint		n_inputs;
	uint		destiny;
	uint		positivity;

	for (uint d = WILLSEX; d < SNAKEPOP - WILLSEX; ++d)
	{
		n_layers = this->p_dudes[0]->GetBrain().GetNLayers();
		for (uint i = 0; i < n_layers; ++i)
		{
			n_neurons = this->p_dudes[0]->GetBrain().GetLayers()[i].GetNNeurons();
			for (uint j = 0; j < n_neurons; ++j)
			{
				n_inputs = this->p_dudes[0]->GetBrain().GetLayers()[i].GetNeurons()[j].size();
				for (uint k = 0; k < n_inputs; ++k)
				{
					destiny = RandomMachine::RDM(0, 100);
					if (destiny <= MUTATIONRATE)
					{
						positivity = RandomMachine::RDM(0, 1);
						if (positivity == 0)
						{
							this->p_dudes[d]->GetBrain().GetLayers()[i].GetNeurons()[j][k] += MUTATIONFORCE;
						}
						else
						{
							this->p_dudes[d]->GetBrain().GetLayers()[i].GetNeurons()[j][k] -= MUTATIONFORCE;
						}
					}
				}
			}
			destiny = RandomMachine::RDM(0, 100);
			if (destiny <= MUTATIONRATE)
			{
				positivity = RandomMachine::RDM(0, 1);
				if (positivity == 0)
				{
					this->p_dudes[d]->GetBrain().GetLayers()[i].SetBias(this->p_dudes[d]->GetBrain().GetLayers()[i].GetBias() + MUTATIONFORCE);
				}
				else
				{
					this->p_dudes[d]->GetBrain().GetLayers()[i].SetBias(this->p_dudes[d]->GetBrain().GetLayers()[i].GetBias() - MUTATIONFORCE);
				}
			}
		}
	}
}

void			SnakeSquad::ShowScores()
{
	for (uint i = 0; i < this->p_dudes.size(); ++i)
	{
		std::cout << i + 1 << ": " << this->p_dudes[i]->GetScore() << std::endl;
	}
}


