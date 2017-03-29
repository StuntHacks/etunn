/**
 * @file	Neuron.hpp.
 *
 * @brief	Declares the neuron struct.
 */
#ifndef NEURON_H
#define NEURON_H

namespace etunn
{
	struct Neuron
	{
		/**
		 * @fn	Neuron(int numInputs);
		 *
		 * @brief	Constructor.
		 *
		 * @param	numInputs	Number of inputs.
		 */
		Neuron(int numInputs);

		/** @brief	The number of inputs into the neuron. */
		int numInputs;

		/** @brief	The weights for each input. */
		std::vector<double> weights;
	};
}

#endif