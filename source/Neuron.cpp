/**
 * @file	Neuron.cpp.
 *
 * @brief	Implements the neuron class.
 */
#include "../include/Neuron.hpp"

namespace etunn
{
	Neuron::Neuron(int numInputs) : numInputs(numInputs + 1)
	{
		for (int i = 0; i < numInputs + 1; ++i)
		{
			//Set up the weights with an initial random value
			float rand1 = (rand()) / (RAND_MAX + 1.0);
			float rand2 = (rand()) / (RAND_MAX + 1.0);

			weights.push_back(rand1 - rand2);
		}
	};
}
