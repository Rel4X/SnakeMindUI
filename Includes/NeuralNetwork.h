/*
 * NeuralNetwork.h
 *
 *  Created on: Oct 5, 2018
 *      Author: nonmaislol
 */

#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include "Layer.h"

typedef std::vector<Layer>	Layers;

class 		NeuralNetwork
{
private:
	uint				p_nlayers;
	Layers				p_layers;

public:
	NeuralNetwork(uint nlayers);
	virtual ~NeuralNetwork();

private:
	NeuralNetwork() { }

public:
	const Vector&	GetOutputs();
	Layers&			GetLayers()			{ return (this->p_layers); }
	uint			GetNLayers() const	{ return (this->p_nlayers); }

	bool			SetLayers(const Layers& layers);

public:
	bool			Compute(const Vector& inputs);
	void			Dump();
	void			DumpOutput();
};

#endif /* NEURALNETWORK_H_ */
