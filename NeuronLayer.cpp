/**
 * @file	NeuronLayer.cpp.
 *
 * @brief	Implements the neuron layer class.
 */
#include "NeuronLayer.hpp"

namespace etunn
{
	NeuronLayer::NeuronLayer(int numNeurons, int NumInputsPerNeuron) : numNeurons(numNeurons)
	{
		for (int i = 0; i < numNeurons; ++i)

			neurons.push_back(Neuron(NumInputsPerNeuron));
	}
}