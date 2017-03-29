/**
 * @file	NeuronLayer.hpp.
 *
 * @brief	Declares the neuron layer struct.
 */
#ifndef NEURONLAYER_H
#define NEURONLAYER_H

#include <vector>
#include "Neuron.hpp"

namespace etunn
{
	struct NeuronLayer
	{
		/**
		 * @fn	NeuronLayer(int numNeurons, int numInputsPerNeuron);
		 *
		 * @brief	Constructor.
		 *
		 * @param	numNeurons		  	Number of neurons.
		 * @param	numInputsPerNeuron	Number of inputs per neurons.
		 */
		NeuronLayer(int numNeurons, int numInputsPerNeuron);

		/** @brief	Number of neurons in this layer. */
		int numNeurons;

		/** @brief	The layer of neurons. */
		std::vector<Neuron> neurons;
	};
}

#endif