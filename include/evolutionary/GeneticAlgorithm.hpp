/**
 * @file	evolutionary\GeneticAlgorithm.hpp.
 *
 * @brief	Declares the genetic algorithm class.
 */
#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <vector>
#include "../Params.hpp"
#include "Genome.hpp"

namespace etunn
{
	namespace evolutionary
	{
		/**
		 * @class	GeneticAlgorithm
		 *
		 * @brief	The genetic algorithm.
		 */
		class GeneticAlgorithm
		{
		public:

			/**
			 * @fn	GeneticAlgorithm::GeneticAlgorithm(int popSize, double mutRat, double crossRat, int numWeights);
			 *
			 * @brief	Constructor.
			 *
			 * @param	popSize   	Size of the population.
			 * @param	mutRat	  	The mutation rate.
			 * @param	crossRat  	The crossover rate.
			 * @param	numWeights	Number of weights.
			 */
			GeneticAlgorithm(int popSize, double mutRat, double crossRat, int numWeights);

			/**
			 * @fn	std::vector<Genome> GeneticAlgorithm::epoch(std::vector<Genome> &old_pop, Params p);
			 *
			 * @brief	Runs the genetic algorithm for one generation.
			 *
			 * @param [in,out]	old_pop	The old population.
			 * @param 		  	p	   	Variable arguments providing additional information.
			 *
			 * @return	The new population.
			 */
			std::vector<Genome> epoch(std::vector<Genome> &old_pop, Params p);

			/*Accessor methods*/

			/**
			 * @fn	std::vector<Genome> GeneticAlgorithm::getChromos() const;
			 *
			 * @brief	Gets the chromosomes.
			 *
			 * @return	The chromosomes.
			 */
			std::vector<Genome> getChromos() const;

			/**
			 * @fn	double GeneticAlgorithm::getAverageFitness() const;
			 *
			 * @brief	Gets average fitness.
			 *
			 * @return	The average fitness.
			 */
			double getAverageFitness() const;

			/**
			 * @fn	double GeneticAlgorithm::getBestFitness() const;
			 *
			 * @brief	Gets best fitness.
			 *
			 * @return	The best fitness.
			 */
			double getBestFitness() const;

		private:
			/** @brief	Entire population of chromosomes. */
			std::vector<Genome> population;

			/** @brief	Size of population. */
			int popSize;

			/** @brief	Amount of weights per chromosome. */
			int chromosomeLength;

			/** @brief	Total fitness of population. */
			double totalFitness;

			/** @brief	Best fitness this population. */
			double bestFitness;

			/** @brief	Average fitness this population. */
			double averageFitness;

			/** @brief	Worst fitness this population. */
			double worstFitness;

			/** @brief	Keeps track of the best genome. */
			int fittestGenome;

			//Probability that a chromosomes bits will mutate.
			//Recommended to be around 0.05 to 0.3
			double mutationRate;

			/**   
			 * @brief	Probability of chromosomes crossing over bits.
			 * 			Recommended to be around 0.7. */
			double crossoverRate;

			/** @brief	Generation counter. */
			int generation;

			/**
			 * @fn	void GeneticAlgorithm::crossover(const std::vector<double> &mum, const std::vector<double> &dad, std::vector<double> &baby1, std::vector<double> &baby2);
			 *
			 * @brief	Crossovers two chromosomes.
			 *
			 * @param 		  	mum  	The mum.
			 * @param 		  	dad  	The dad.
			 * @param [in,out]	baby1	The first baby.
			 * @param [in,out]	baby2	The second baby.
			 */
			void crossover(const std::vector<double> &mum, const std::vector<double> &dad, std::vector<double> &baby1, std::vector<double> &baby2);

			/**
			 * @fn	void GeneticAlgorithm::mutate(std::vector<double> &chromo, Params p);
			 *
			 * @brief	Mutates two chromosomes.
			 *
			 * @param [in,out]	chromo	The chromosome.
			 * @param 		  	p	  	Variable arguments providing additional information.
			 */
			void mutate(std::vector<double> &chromo, Params p);

			/**
			 * @fn	Genome GeneticAlgorithm::getChromoRoulette();
			 *
			 * @brief	Returns a random chromosome.
			 *
			 * @return	The random chromosome.
			 */
			Genome getChromoRoulette();

			/**
			 * @fn	void GeneticAlgorithm::grabNBest(int best, const int numCopies, std::vector<Genome> &vecPop);
			 *
			 * @brief	Grabs the n best chromosomes this generation.
			 *
			 * @param 		  	best	 	The n best chromosomes.
			 * @param 		  	numCopies	Number of copies.
			 * @param [in,out]	vecPop   	The population.
			 */
			void grabNBest(int best, const int numCopies, std::vector<Genome> &vecPop);

			/**
			 * @fn	void GeneticAlgorithm::calculateBestWorstAvTot();
			 *
			 * @brief	Calculates the best, worst, average and total.
			 */
			void calculateBestWorstAvTot();

			/**
			 * @fn	void GeneticAlgorithm::reset();
			 *
			 * @brief	Resets this object.
			 */
			void reset();
		};
	}
}

#endif