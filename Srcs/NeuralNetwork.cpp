/*
 * NeuralNetwork.cpp
 *
 *  Created on: Oct 5, 2018
 *      Author: nonmaislol
 */

#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(uint nlayers)
{
	this->p_nlayers = nlayers;
}

NeuralNetwork::~NeuralNetwork()
{

}

const Vector&	NeuralNetwork::GetOutputs()
{
	return (this->p_layers[this->p_layers.size() - 1].GetOutputs());
}

bool			NeuralNetwork::SetLayers(const Layers& layers)
{
	if (layers.size() != this->p_nlayers)
		return (false);
	this->p_layers = layers;
	return (true);
}

bool			NeuralNetwork::Compute(const Vector& inputs)
{
	Vector		tinputs = inputs;

	for (uint i = 0; i < this->p_layers.size(); ++i)
	{
		if (this->p_layers[i].Compute(tinputs) == false)
		{
			std::cout << "Computation failure." << std::endl;
			return (false);
		}
		tinputs = this->p_layers[i].GetOutputs();
	}
	return (true);
}

void			NeuralNetwork::Dump()
{
	for (uint i = 0; i < this->p_layers.size(); ++i)
	{
		this->p_layers[i].Dump();
		std::cout << "---------" << std::endl;
	}
}

void			NeuralNetwork::DumpOutput()
{
	for (uint i = 0; i < this->GetOutputs().size(); ++i)
	{
		std::cout << this->GetOutputs()[i] << ' ';
	}
	std::cout << std::endl;
}
