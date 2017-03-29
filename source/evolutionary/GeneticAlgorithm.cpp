/**
 * @file	evolutionary\GeneticAlgorithm.cpp.
 *
 * @brief	Implements the genetic algorithm class.
 */
#include "../../include/evolutionary/GeneticAlgorithm.hpp"
#include <algorithm>

namespace etunn
{
	namespace evolutionary
	{
		GeneticAlgorithm::GeneticAlgorithm(int popSize, double mutRat, double crossRat, int numWeights)
			: popSize(popSize),
			mutationRate(mutRat),
			crossoverRate(crossRat),
			chromosomeLength(numWeights),
			totalFitness(0),
			generation(0),
			fittestGenome(0),
			bestFitness(0),
			worstFitness(99999999),
			averageFitness(0)
		{
			//Initialise population with chromosomes consisting of random weights and all fitnesses set to zero
			for (int i = 0; i < popSize; ++i)
			{
				population.push_back(Genome());

				for (int j = 0; j < chromosomeLength; ++j)
				{
					float rand1 = (rand()) / (RAND_MAX + 1.0);
					float rand2 = (rand()) / (RAND_MAX + 1.0);

					population[i].weights.push_back(rand1 - rand2);
				}
			}
		}

		std::vector<Genome> GeneticAlgorithm::epoch(std::vector<Genome> &old_pop, Params p)
		{
			//Assign the given population to the classes population
			population = old_pop;

			//Reset everything
			reset();

			//Sort the population (for scaling and elitism)
			std::sort(population.begin(), population.end());

			//Calculate best, worst, average and total fitness
			calculateBestWorstAvTot();

			//Create a temporary vector to store the new chromosones
			std::vector<Genome> newPopulation;

			//Add elitism (insert a set number of copies of the fittest chromosomes)
			//The amount of the copies HAS to be EVEN (or it will crash)
			if (!(p.numCopiesElite * p.numElite % 2))
			{
				grabNBest(p.numElite, p.numCopiesElite, newPopulation);
			}

			while (newPopulation.size() < popSize)
			{
				//Grab two chromosones
				Genome mum = getChromoRoulette();
				Genome dad = getChromoRoulette();

				//Generate offspring (using crossover)
				std::vector<double> baby1, baby2;
				crossover(mum.weights, dad.weights, baby1, baby2);

				//Mutate
				mutate(baby1, p);
				mutate(baby2, p);

				newPopulation.push_back(Genome(baby1, 0));
				newPopulation.push_back(Genome(baby2, 0));
			}

			population = newPopulation;
			return population;
		}

		void GeneticAlgorithm::grabNBest(int nBest, const int numCopies, std::vector<Genome> &pop)
		{
			while (nBest--)
			{
				for (int i = 0; i < numCopies; ++i)
				{
					pop.push_back(population[(popSize - 1) - nBest]);
				}
			}
		}

		void GeneticAlgorithm::crossover(const std::vector<double> &mum, const std::vector<double> &dad,
			std::vector<double> &baby1, std::vector<double> &baby2)
		{
			//Return the parents as the offspring depending on the crossover rate or if the parents are the same
			if (((rand()) / (RAND_MAX + 1.0) > crossoverRate) || (mum == dad))
			{
				baby1 = mum;
				baby2 = dad;

				return;
			}

			//Determine the crossover point
			int x = 0, y = chromosomeLength - 1;
			int cp = rand() % (y - x + 1) + x;

			//Generate the offspring
			for (int i = 0; i < cp; ++i)
			{
				baby1.push_back(mum[i]);
				baby2.push_back(dad[i]);
			}

			for (int i = cp; i < mum.size(); ++i)
			{
				baby1.push_back(dad[i]);
				baby2.push_back(mum[i]);
			}
		}

		void GeneticAlgorithm::mutate(std::vector<double> &chromo, Params p)
		{
			//Mutate each weight depending on the mutation rate
			for (int i = 0; i < chromo.size(); ++i)
			{
				if ((rand()) / (RAND_MAX + 1.0)  < mutationRate)
				{
					//Add or subtract a small value
					float rand1 = (rand()) / (RAND_MAX + 1.0);
					float rand2 = (rand()) / (RAND_MAX + 1.0);
					chromo[i] += (rand1 - rand2 * p.maxPerturbation);
				}
			}
		}

		Genome GeneticAlgorithm::getChromoRoulette()
		{
			double slice = (double)((rand()) / (RAND_MAX + 1.0) * totalFitness);
			Genome returnGenome;
			double currentFitness = 0;

			for (int i = 0; i < popSize; ++i)
			{
				currentFitness += population[i].fitness;

				if (currentFitness >= slice)
				{
					returnGenome = population[i];
					break;
				}
			}

			return returnGenome;
		}

		void GeneticAlgorithm::calculateBestWorstAvTot()
		{
			totalFitness = 0;

			double currentHighest = 0;
			double currentLowest = 9999999;

			for (int i = 0; i < popSize; ++i)
			{
				//Update best if necessary
				if (population[i].fitness > currentHighest)
				{
					currentHighest = population[i].fitness;

					fittestGenome = i;

					bestFitness = currentHighest;
				}

				//Update worst if necessary
				if (population[i].fitness < currentLowest)
				{
					currentLowest = population[i].fitness;

					worstFitness = currentLowest;
				}

				totalFitness += population[i].fitness;


			}

			averageFitness = totalFitness / popSize;
		}

		void GeneticAlgorithm::reset()
		{
			totalFitness = 0;
			bestFitness = 0;
			worstFitness = 9999999;
			averageFitness = 0;
		}

		std::vector<Genome> GeneticAlgorithm::getChromos() const
		{
			return population;
		}

		double GeneticAlgorithm::getAverageFitness() const
		{
			return totalFitness / popSize;
		}

		double GeneticAlgorithm::getBestFitness() const
		{
			return bestFitness;
		}
	}
}