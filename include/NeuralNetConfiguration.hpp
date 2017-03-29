/**
 * @file	NeuralNetConfiguration.hpp.
 *
 * @brief	Declares the neural net configuration class.
 */
#ifndef NEURALNETCONFIGURATION_H
#define NEURALNETCONFIGURATION_H

#include <iostream>
#include <string>

namespace etunn
{
	class NeuralNetConfiguration
	{
	public:

		/**
		 * @fn	NeuralNetConfiguration::NeuralNetConfiguration();
		 *
		 * @brief	Default constructor.
		 */
		NeuralNetConfiguration();

		/**
		 * @fn	NeuralNetConfiguration& NeuralNetConfiguration::numInputs(int n);
		 *
		 * @brief	The amount of input neurons (Default = 1)
		 *
		 * @param	n	The int to process.
		 *
		 * @return	This object.
		 */
		NeuralNetConfiguration& numInputs(int n);

		/**
		 * @fn	NeuralNetConfiguration& NeuralNetConfiguration::numHidden(int n);
		 *
		 * @brief	The amount of hidden layers (Default = 0)
		 *
		 * @param	n	The int to process.
		 *
		 * @return	This object.
		 */
		NeuralNetConfiguration& numHidden(int n);

		/**
		 * @fn	NeuralNetConfiguration& NeuralNetConfiguration::neuronsPerLayer(int n);
		 *
		 * @brief	The amount of neurons per hidden layer (Default = 1)
		 *
		 * @param	n	The int to process.
		 *
		 * @return	This object.
		 */
		NeuralNetConfiguration& neuronsPerLayer(int n);

		/**
		 * @fn	NeuralNetConfiguration& NeuralNetConfiguration::numOutputs(int n);
		 *
		 * @brief	The amount of output neurons (Default = 1)
		 *
		 * @param	n	The int to process.
		 *
		 * @return	This object.
		 */
		NeuralNetConfiguration& numOutputs(int n);

		/**
		 * @fn	NeuralNetConfiguration& NeuralNetConfiguration::activationResponse(double n);
		 *
		 * @brief	The response for the sigmoid curve (Default = 1).
		 * 			The lower this value the more the sigmoid curve becomes a step curve.
		 *
		 * @param	n	The double to process.
		 *
		 * @return	This object.
		 */
		NeuralNetConfiguration& activationResponse(double n);

		/**
		 * @fn	NeuralNetConfiguration& NeuralNetConfiguration::bias(double n);
		 *
		 * @brief	The bias (Default = -1)
		 *
		 * @param	n	The double to process.
		 *
		 * @return	This object.
		 */
		NeuralNetConfiguration& bias(double n);

		/**
		 * @fn	NeuralNetConfiguration& NeuralNetConfiguration::crossoverRate(double n);
		 *
		 * @brief	The crossover rate (evolutionary only) (Default = 0.7)
		 *
		 * @param	n	The double to process.
		 *
		 * @return	This object.
		 */
		NeuralNetConfiguration& crossoverRate(double n);

		/**
		 * @fn	NeuralNetConfiguration& NeuralNetConfiguration::mutationRate(double n);
		 *
		 * @brief	The mutation rate (evolutionary only) (Default = 0.1)
		 *
		 * @param	n	The double to process.
		 *
		 * @return	This object.
		 */
		NeuralNetConfiguration& mutationRate(double n);

		/**
		 * @fn	NeuralNetConfiguration& NeuralNetConfiguration::maxPerturbation(double n);
		 *
		 * @brief	The maximum amount a weight can be tweaked (Default = 0.3)
		 *
		 * @param	n	The double to process.
		 *
		 * @return	This object.
		 */
		NeuralNetConfiguration& maxPerturbation(double n);

		/**
		 * @fn	NeuralNetConfiguration& NeuralNetConfiguration::numElite(int n);
		 *
		 * @brief	The amount of the best neural networks per generation (evolutionary only) (Default = 4)
		 *
		 * @param	n	The int to process.
		 *
		 * @return	This object.
		 */
		NeuralNetConfiguration& numElite(int n);

		/**
		 * @fn	NeuralNetConfiguration& NeuralNetConfiguration::numCopiesElite(int n);
		 *
		 * @brief	The amount of copies that get generated of the best neural networks (evolutionary only) (Default = 1)
		 *
		 * @param	n	The int to process.
		 *
		 * @return	This object.
		 */
		NeuralNetConfiguration& numCopiesElite(int n);

		/**
		 * @fn	std::string NeuralNetConfiguration::outputConfig();
		 *
		 * @brief	Outputs the configuration.
		 *
		 * @return	The configuration.
		 */
		std::string outputConfig();

		/*Getter*/

		/**
		 * @fn	int NeuralNetConfiguration::getNumInputs();
		 *
		 * @brief	Gets the number of inputs.
		 *
		 * @return	The number of inputs.
		 */
		int getNumInputs();

		/**
		 * @fn	int NeuralNetConfiguration::getNumHidden();
		 *
		 * @brief	Gets the number of hidden layers.
		 *
		 * @return	The number of hidden layers.
		 */
		int getNumHidden();

		/**
		 * @fn	int NeuralNetConfiguration::getNeuronsPerHiddenLayer();
		 *
		 * @brief	Gets the number of neurons per hidden layer.
		 *
		 * @return	The number of neurons per hidden layer.
		 */
		int getNeuronsPerHiddenLayer();

		/**
		 * @fn	int NeuralNetConfiguration::getNumOutputs();
		 *
		 * @brief	Gets the number of outputs.
		 *
		 * @return	The number of outputs.
		 */
		int getNumOutputs();

		/**
		 * @fn	double NeuralNetConfiguration::getActivationResponse();
		 *
		 * @brief	Gets the activation response.
		 *
		 * @return	The activation response.
		 */
		double getActivationResponse();

		/**
		 * @fn	double NeuralNetConfiguration::getBias();
		 *
		 * @brief	Gets the bias.
		 *
		 * @return	The bias.
		 */
		double getBias();

		/**
		 * @fn	double NeuralNetConfiguration::getCrossoverRate();
		 *
		 * @brief	Gets the crossover rate.
		 *
		 * @return	The crossover rate.
		 */
		double getCrossoverRate();

		/**
		 * @fn	double NeuralNetConfiguration::getMutationRate();
		 *
		 * @brief	Gets the mutation rate.
		 *
		 * @return	The mutation rate.
		 */
		double getMutationRate();

		/**
		 * @fn	double NeuralNetConfiguration::getMaxPerturbation();
		 *
		 * @brief	Gets the maximum perturbation.
		 *
		 * @return	The maximum perturbation.
		 */
		double getMaxPerturbation();

		/**
		 * @fn	int NeuralNetConfiguration::getNumElite();
		 *
		 * @brief	Gets the number of elite chromosomes (evolutionary only).
		 *
		 * @return	The number of elites.
		 */
		int getNumElite();

		/**
		 * @fn	int NeuralNetConfiguration::getNumCopiesElite();
		 *
		 * @brief	Gets the number of copies of the elite chromosomes (evolutionary only).
		 *
		 * @return	The number of copies of the elite.
		 */
		int getNumCopiesElite();

	private:
		int loc_numInputs;
		int loc_numHidden;
		int loc_neuronsPerHiddenLayer;
		int loc_numOutputs;
		double loc_activationResponse;
		double loc_bias;
		double loc_crossoverRate;
		double loc_mutationRate;
		double loc_maxPerturbation;
		int loc_numElite;
		int loc_numCopiesElite;
	};
}

#endif