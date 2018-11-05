/*
 * Layer.cpp
 *
 *  Created on: Oct 3, 2018
 *      Author: nonmaislol
 */

#include "Layer.h"

Layer::Layer(uint neurons, uint inputs)
{
	this->p_neurons = neurons;
	this->p_inputs = inputs;
	this->p_outputs.resize(this->p_neurons);
}

Layer::Layer(uint neurons, uint inputs, const Vector2D& weights, double bias)
{
	this->p_neurons = neurons;
	this->p_inputs = inputs;
	this->p_outputs.resize(this->p_neurons);
	this->SetLayer(weights, bias);
}

Layer::~Layer()
{

}

bool		Layer::SetLayer(const Vector2D& weights, double bias)
{
	if (weights.size() != this->p_neurons)
		return (false);
	for (uint i = 0; i < this->p_neurons; ++i)
	{
		if (weights[i].size() != this->p_inputs)
			return (false);
	}
	this->p_weights = weights;
	this->p_bias = bias;
	return (true);
}

bool		Layer::Compute(const Vector& inputs)
{
	if (this->p_inputs != inputs.size())
		return (false);

	for (uint i = 0; i < this->p_neurons; ++i)
	{
		this->p_outputs[i] = 0.0;
		for (uint j = 0; j < this->p_inputs; ++j)
		{
			this->p_outputs[i] += (inputs[j] * this->p_weights[i][j]);
		}
		this->p_outputs[i] += this->p_bias;
		//this->p_outputs[i] = 1 / (1 + exp(-this->p_outputs[i]));
	}

	return (true);
}

void		Layer::Generate()
{
	this->p_weights.resize(this->p_neurons);
	for (uint i = 0; i < this->p_neurons; ++i)
	{
		this->p_outputs[i] = 0.0;
		this->p_weights[i].resize(this->p_inputs);
		for (uint j = 0; j < this->p_inputs; ++j)
		{
			this->p_weights[i][j] = (double)RandomMachine::RDM(0, 1000000) / 1000000.0;
			if (RandomMachine::RDM(0, 1) == 1)
				this->p_weights[i][j] *= -1;
		}
	}
	this->p_bias = (double)RandomMachine::RDM(0, 1000000) / 1000000.0;
}

void		Layer::Dump() const
{
	for (uint i = 0; i < this->p_neurons; ++i)
	{
		std::cout << "Neuron " << i + 1 << std::endl;
		for (uint j = 0; j < this->p_inputs; ++j)
		{
			std::cout << this->p_weights[i][j] << ' ';
		}
		std::cout << std::endl;
		std::cout << "Output: " << this->p_outputs[i] << std::endl;
	}
	std::cout << "Bias " << this->p_bias << std::endl;

}
