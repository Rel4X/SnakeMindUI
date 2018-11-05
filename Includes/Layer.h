/*
 * Layer.h
 *
 *  Created on: Oct 3, 2018
 *      Author: nonmaislol
 */

#ifndef LAYER_H_
#define LAYER_H_

#include 	<iostream>
#include 	<vector>
#include	<cmath>
#include	<ctgmath>

#include	"RandomMachine.h"

typedef	unsigned int			uint;
typedef	std::vector<double>		Vector;
typedef	std::vector<Vector>		Vector2D;

class 	Layer
{
private:
	uint			p_neurons;
	uint			p_inputs;
	Vector2D		p_weights;
	Vector			p_outputs;
	double			p_bias;

public:
	Layer(uint neurons, uint inputs);
	Layer(uint neurons, uint inputs, const Vector2D& weights, double bias);
	virtual ~Layer();

private:
	Layer() { }

public:
	uint			GetNNeurons() const		{ return (this->p_neurons); }
	uint			GetNInputs() const		{ return (this->p_inputs); }
	Vector2D&		GetNeurons()			{ return (this->p_weights); }
	Vector&			GetOutputs()			{ return (this->p_outputs); }
	double			GetBias() const			{ return (this->p_bias); }

	bool			SetLayer(const Vector2D& weights, double bias);
	void			SetBias(double bias)	{ this->p_bias = bias; }

public:
	bool			Compute(const Vector& inputs);
	void			Generate();
	void			Dump() const;
};

#endif /* LAYER_H_ */
