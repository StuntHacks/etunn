/**
 * @file	Params.hpp.
 *
 * @brief	Declares the parameters class.
 */
#ifndef PARAMS_H
#define PARAMS_H

#include "NeuralNetConfiguration.hpp"

namespace etunn
{
	class Params
	{
	public:

		/**
		 * @fn	Params::Params();
		 *
		 * @brief	Default constructor.
		 */
		Params();

		/** @brief  Number of inputs */
		static int numInputs;

		/** @brief	Number of hidden layers */
		static int numHidden;

		/** @brief	Number of neurons per hidden layer */
		static int neuronsPerHiddenLayer;

		/** @brief	Number of outputs */
		static int numOutputs;

		/** @brief	For tweeking the sigmoid function. */
		static double activationResponse;

		/** @brief	Bias value. */
		static double bias;

		/** @brief	The crossover rate */
		static double crossoverRate;

		/** @brief	The mutation rate */
		static double mutationRate;

		/** @brief	Maximum amount the genetic algorithm may mutate each weight. */
		static double maxPerturbation;

		/** @brief	Number of elites */
		static int numElite;

		/** @brief	Number of copies of the elites */
		static int numCopiesElite;

		/**
		 * @fn	void Params::setParams(NeuralNetConfiguration config);
		 *
		 * @brief	Sets the parameters.
		 *
		 * @param	config	The configuration.
		 */
		void setParams(NeuralNetConfiguration config);
	};
}

#endif