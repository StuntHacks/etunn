/**
 * @file	feedforward\NeuralNet.cpp.
 *
 * @brief	Implements the feedforward neural net class.
 */
#include "../../include/feedforward/NeuralNet.hpp"

namespace etunn
{
	namespace feedforward
	{
		NeuralNet::NeuralNet()
		{
			//Do nothing
		}

		NeuralNet::NeuralNet(Params p)
		{
			numInputs = p.numInputs;
			numOutputs = p.numOutputs;
			numHiddenLayers = p.numHidden;
			neuronsPerHiddenLyr = p.neuronsPerHiddenLayer;
		}

		void NeuralNet::createNet()
		{
			//Create the layers of the network
			if (numHiddenLayers > 0)
			{
				//Create first hidden layer
				layers.push_back(NeuronLayer(neuronsPerHiddenLyr, numInputs));

				//Create the other layers
				for (int i = 0; i < numHiddenLayers - 1; ++i)
				{
					layers.push_back(NeuronLayer(neuronsPerHiddenLyr, neuronsPerHiddenLyr));
				}

				//Create output layer
				layers.push_back(NeuronLayer(numOutputs, neuronsPerHiddenLyr));
			}
			else
			{
				//Create output layer
				layers.push_back(NeuronLayer(numOutputs, numInputs));
			}
		}

		std::vector<double> NeuralNet::getWeights() const
		{
			//Holds the weights
			std::vector<double> weights;

			//Layers
			for (int i = 0; i < numHiddenLayers + 1; ++i)
			{
				//Neurons
				for (int j = 0; j < layers[i].numNeurons; ++j)
				{
					//Weights
					for (int k = 0; k < layers[i].neurons[j].numInputs; ++k)
					{
						weights.push_back(layers[i].neurons[j].weights[k]);
					}
				}
			}

			return weights;
		}

		void NeuralNet::putWeights(std::vector<double> &weights)
		{
			int weight = 0;

			//Layers
			for (int i = 0; i < numHiddenLayers + 1; ++i)
			{
				//Neurons
				for (int j = 0; j < layers[i].numNeurons; ++j)
				{
					//Weights
					for (int k = 0; k < layers[i].neurons[j].numInputs; ++k)
					{
						layers[i].neurons[j].weights[k] = weights[weight++];
					}
				}
			}
		}

		int NeuralNet::getNumberOfWeights() const
		{
			int weights = 0;

			//Layers
			for (int i = 0; i < numHiddenLayers + 1; ++i)
			{
				//Neurons
				for (int j = 0; j < layers[i].numNeurons; ++j)
				{
					//Weights
					for (int k = 0; k < layers[i].neurons[j].numInputs; ++k)
						weights++;
				}
			}

			return weights;
		}

		std::vector<double> NeuralNet::update(std::vector<double> &inputs, Params p)
		{
			//Stores the resultant outputs from each layer
			std::vector<double> outputs;

			int weight = 0;

			//Check that the amount of inputs is correct
			if (inputs.size() != numInputs)
			{
				//Return an empty vector if incorrect.
				return outputs;
			}

			//Layers
			for (int i = 0; i < numHiddenLayers + 1; ++i)
			{
				if (i > 0)
				{
					inputs = outputs;
				}

				outputs.clear();

				weight = 0;

				//Sum the (inputs * corresponding weights) for each neuron
				//Run the total at through sigmoid function to get the output
				for (int j = 0; j < layers[i].numNeurons; ++j)
				{
					double netinput = 0;

					int	NumInputs = layers[i].neurons[j].numInputs;

					//Weights
					for (int k = 0; k < layers[i].neurons[j].weights.size() - 1; ++k)
					{
						//Sum the weights * inputs
						netinput += layers[i].neurons[j].weights[k] *
							inputs[weight++];
					}

					//Add in the bias
					netinput += layers[i].neurons[j].weights[NumInputs - 1] *
						p.bias;

					//Store the outputs from each layer as they get generated
					//The combined activation is first filtered through the sigmoid  function
					outputs.push_back(sigmoid(netinput,
						p.activationResponse));

					weight = 0;
				}
			}

			return outputs;
		}

		inline double NeuralNet::sigmoid(double activation, double response)
		{
			return (1 / (1 + exp(-activation / response)));
		}
	}
}