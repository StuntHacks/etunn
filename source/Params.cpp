/**
 * @file	Params.cpp.
 *
 * @brief	Implements the parameters class.
 */
#include "../include/Params.hpp"
#include "../include/NeuralNetConfiguration.hpp"

namespace etunn
{
	//Initializing all parameters
	int Params::numInputs = 0;
	int Params::numHidden = 0;
	int Params::neuronsPerHiddenLayer = 0;
	int Params::numOutputs = 0;
	double Params::activationResponse = 0;
	double Params::bias = 0;
	double Params::crossoverRate = 0;
	double Params::mutationRate = 0;
	double Params::maxPerturbation = 0;
	int Params::numElite = 0;
	int Params::numCopiesElite = 0;

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