/**
 * @file	Params.cpp.
 *
 * @brief	Implements the parameters class.
 */
#include "Params.hpp"
#include "NeuralNetConfiguration.hpp"

namespace etunn
{
	Params::Params()
	{
		//Initializing all parameters
		numInputs = 0;
		numHidden = 0;
		neuronsPerHiddenLayer = 0;
		numOutputs = 0;
		activationResponse = 0;
		bias = 0;
		crossoverRate = 0;
		mutationRate = 0;
		maxPerturbation = 0;
		numElite = 0;
		numCopiesElite = 0;
	}

	void Params::setParams(NeuralNetConfiguration config)
	{
		numInputs = config.getNumInputs();
		numHidden = config.getNumHidden();
		neuronsPerHiddenLayer = config.getNeuronsPerHiddenLayer();
		numOutputs = config.getNumOutputs();
		activationResponse = config.getActivationResponse();
		bias = config.getBias();
		crossoverRate = config.getCrossoverRate();
		mutationRate = config.getMutationRate();
		maxPerturbation = config.getMaxPerturbation();
		numElite = config.getNumElite();
		numCopiesElite = config.getNumCopiesElite();
	}
}