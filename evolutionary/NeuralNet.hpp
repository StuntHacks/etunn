/**
 * @file	evolutionary\NeuralNet.hpp.
 *
 * @brief	Declares the evolutionary neural net class.
 */
#ifndef EVOL_NEURALNET_H
#define EVOL_NEURALNET_H

#include <iostream>
#include <string>
#include <vector>

#include "../NeuralNetConfiguration.hpp"
#include "../Params.hpp"
#include "../Neuron.hpp"
#include "../NeuronLayer.hpp"
#include "Genome.hpp"
#include "GeneticAlgorithm.hpp"

/**
 * @def	NUM_E
 *
 * @brief	A macro that defines the number e.
 */
#define NUM_E 2.71828182846

namespace etunn
{
	namespace evolutionary
	{
		/**
		 * @class	NeuralNet
		 *
		 * @brief	A neural net.
		 */
		class NeuralNet
		{
		public:

			/**
			 * @fn	NeuralNet::NeuralNet();
			 *
			 * @brief	Default constructor.
			 */
			NeuralNet();

			/**
			 * @fn	NeuralNet::NeuralNet(Params p);
			 *
			 * @brief	Constructor.
			 *
			 * @param	p	Variable arguments providing additional information.
			 */
			NeuralNet(Params p);

			/**
			 * @fn	void NeuralNet::createNet();
			 *
			 * @brief	Creates the network.
			 */
			void createNet();

			/**
			 * @fn	std::vector<double> NeuralNet::getWeights() const;
			 *
			 * @brief	Gets the weights from the network.
			 *
			 * @return	The weights.
			 */
			std::vector<double> getWeights() const;

			/**
			 * @fn	int NeuralNet::getNumberOfWeights() const;
			 *
			 * @brief	Returns the total number of weights in the net.
			 *
			 * @return	The number of weights.
			 */
			int getNumberOfWeights() const;

			/**
			 * @fn	void NeuralNet::putWeights(std::vector<double> &weights);
			 *
			 * @brief	Replaces the weights with new ones.
			 *
			 * @param [in,out]	weights	The weights.
			 */
			void putWeights(std::vector<double> &weights);

			/**
			 * @fn	std::vector<double> NeuralNet::update(std::vector<double> &inputs, Params p);
			 *
			 * @brief	Calculates the outputs from a set of inputs.
			 *
			 * @param [in,out]	inputs	The inputs.
			 * @param 		  	p	  	Variable arguments providing additional information.
			 *
			 * @return	The output of the network.
			 */
			std::vector<double> update(std::vector<double> &inputs, Params p);

			/**
			 * @fn	inline double NeuralNet::sigmoid(double activation, double response);
			 *
			 * @brief	Sigmoid response curve.
			 *
			 * @param	activation	The activation.
			 * @param	response  	The response.
			 *
			 * @return	A double.
			 */
			inline double sigmoid(double activation, double response);

		private:
			int numInputs, numOutputs, numHiddenLayers, neuronsPerHiddenLyr;
			std::string name;

			//Storage for each layer of neurons including the output layer
			std::vector<NeuronLayer> layers;
		};
	}
}

#endif