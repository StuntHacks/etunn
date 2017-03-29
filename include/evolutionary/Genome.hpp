/**
 * @file	evolutionary\Genome.hpp.
 *
 * @brief	Declares the genome struct.
 */
#ifndef GENOME_H
#define GENOME_H

#include <vector>

namespace etunn
{
	namespace evolutionary
	{
		/**
		 * @struct	Genome
		 *
		 * @brief	A genome.
		 */
		struct Genome
		{
			/** @brief	The weights */
			std::vector <double>  weights;

			/** @brief	The fitness */
			double fitness;

			/**
			 * @fn	Genome()
			 *
			 * @brief	Default constructor.
			 */
			Genome() : fitness(0) {}

			/**
			 * @fn	Genome(std::vector<double> w, double f)
			 *
			 * @brief	Constructor.
			 *
			 * @param	w	The weights.
			 * @param	f	The fitness
			 */
			Genome(std::vector<double> w, double f) : weights(w), fitness(f) {}

			/**
			 * @fn	friend bool operator< (const Genome& lhs, const Genome& rhs)
			 *
			 * @brief	Overload '<' used for sorting.
			 *
			 * @param	lhs	The first instance to compare.
			 * @param	rhs	The second instance to compare.
			 *
			 * @return	True if the first parameter is less than the second.
			 */
			friend bool operator < (const Genome& lhs, const Genome& rhs)
			{
				return (lhs.fitness < rhs.fitness);
			}
		};
	}
}

#endif