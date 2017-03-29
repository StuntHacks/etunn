/**
 * @file	NeuralNetConfiguration.cpp.
 *
 * @brief	Implements the neural net configuration class.
 */
#include "../include/NeuralNetConfiguration.hpp"

namespace etunn
{
	NeuralNetConfiguration::NeuralNetConfiguration()
	{
		loc_numInputs = 1;
		loc_numHidden = 0;
		loc_neuronsPerHiddenLayer = 1;
		loc_numOutputs = 1;
		loc_activationResponse = 1;
		loc_bias = -1;
		loc_crossoverRate = 0.7;
		loc_mutationRate = 0.1;
		loc_maxPerturbation = 0.3;
		loc_numElite = 4;
		loc_numCopiesElite = 1;
	}

	NeuralNetConfiguration& NeuralNetConfiguration::numInputs(int n)
	{
		loc_numInputs = n;
		return *this;
	}

	NeuralNetConfiguration& NeuralNetConfiguration::numHidden(int n)
	{
		loc_numHidden = n;
		return *this;
	}

	NeuralNetConfiguration& NeuralNetConfiguration::neuronsPerLayer(int n)
	{
		loc_neuronsPerHiddenLayer = n;
		return *this;
	}

	NeuralNetConfiguration & NeuralNetConfiguration::numOutputs(int n)
	{
		loc_numOutputs = n;
		return *this;
	}

	NeuralNetConfiguration & NeuralNetConfiguration::activationResponse(double n)
	{
		loc_activationResponse = n;
		return *this;
	}

	NeuralNetConfiguration & NeuralNetConfiguration::bias(double n)
	{
		loc_bias = n;
		return *this;
	}

	NeuralNetConfiguration & NeuralNetConfiguration::crossoverRate(double n)
	{
		loc_crossoverRate = n;
		return *this;
	}

	NeuralNetConfiguration & NeuralNetConfiguration::mutationRate(double n)
	{
		loc_mutationRate = n;
		return *this;
	}

	NeuralNetConfiguration & NeuralNetConfiguration::maxPerturbation(double n)
	{
		loc_maxPerturbation = n;
		return *this;
	}

	NeuralNetConfiguration & NeuralNetConfiguration::numElite(int n)
	{
		loc_numElite = n;
		return *this;
	}

	NeuralNetConfiguration & NeuralNetConfiguration::numCopiesElite(int n)
	{
		loc_numCopiesElite = n;
		return *this;
	}

	std::string NeuralNetConfiguration::outputConfig()
	{
		std::string output = "";
		output.append(" == NEURAL NETWORK DEBUG DATA ==\n\n");
		output.append("Displaying configuration...");

		output.append("\n Number of input neurons: " + std::to_string(loc_numInputs));
		output.append("\n Number of hidden layers: " + std::to_string(loc_numHidden));
		output.append("\n Number of neurons per layer: " + std::to_string(loc_neuronsPerHiddenLayer));
		output.append("\n Number of output neurons: " + std::to_string(loc_numOutputs));
		output.append("\n Activation response: " + std::to_string(loc_activationResponse));
		output.append("\n Bias: " + std::to_string(loc_bias));
		output.append("\n Crossover rate: " + std::to_string(loc_crossoverRate));
		output.append("\n Mutation rate: " + std::to_string(loc_mutationRate));
		output.append("\n Max. perturbation: " + std::to_string(loc_maxPerturbation));
		output.append("\n Number of elites: " + std::to_string(loc_numElite));
		output.append("\n Number of elite copies: " + std::to_string(loc_numCopiesElite));


		output.append("\n\n == END OF DEBUG DATA ==\n");

		return output;
	}

	/*Getter*/
	int NeuralNetConfiguration::getNumInputs()
	{
		return loc_numInputs;
	}

	int NeuralNetConfiguration::getNumHidden()
	{
		return loc_numHidden;
	}

	int NeuralNetConfiguration::getNeuronsPerHiddenLayer()
	{
		return loc_neuronsPerHiddenLayer;
	}

	int NeuralNetConfiguration::getNumOutputs()
	{
		return loc_numOutputs;
	}

	double NeuralNetConfiguration::getActivationResponse()
	{
		return loc_activationResponse;
	}

	double NeuralNetConfiguration::getBias()
	{
		return loc_bias;
	}

	double NeuralNetConfiguration::getCrossoverRate()
	{
		return loc_crossoverRate;
	}

	double NeuralNetConfiguration::getMutationRate()
	{
		return loc_mutationRate;
	}

	double NeuralNetConfiguration::getMaxPerturbation()
	{
		return loc_maxPerturbation;
	}

	int NeuralNetConfiguration::getNumElite()
	{
		return loc_numElite;
	}

	int NeuralNetConfiguration::getNumCopiesElite()
	{
		return loc_numCopiesElite;
	}
}