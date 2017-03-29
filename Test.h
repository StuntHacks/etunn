#pragma once
#include "etunn.h"
#include <windows.h>

class Test
{
public:
	Test(etunn::Params p)
	{
		brain = etunn::evolutionary::NeuralNet(p);
	}

	std::wstring s2ws(const std::string& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		return r;
	}

	std::string intToLang(int i)
	{
		if (i == 0)
			return "German";
		else
			return "English";
	}

	void train(std::vector<std::vector<double>> inputVector, std::vector<std::vector<double>> outputVector, etunn::Params p, std::vector<std::string> wordlist, int id = 0)
	{
		std::vector<std::vector<double>> outputs;

		std::cout << "[ACTION] Checking the length of every word..." << std::endl;
		for (int i = 0; i < inputVector.size(); i++)
		{
			if (inputVector[i].size() != p.numInputs)
				while (inputVector[i].size() != p.numInputs)
					inputVector[i].push_back(32);
		}
		std::cout << "[INFO] Word checking finished. Starting evaluating inputs..." << std::endl;

		std::string consoleTitle;
		std::wstring stemp;
		LPCWSTR result;

		for (int i = 0; i < inputVector.size(); i++)
		{
			consoleTitle = "Training: Network " + std::to_string(id) + ", Word " + std::to_string(i);
			stemp = s2ws(consoleTitle);
			result = stemp.c_str();
			SetConsoleTitle(result);

			std::cout << "\nWord: " << wordlist[i] << std::endl;
			std::cout << "Actual language: " << intToLang(outputVector[i][0]) << std::endl;
			outputs.push_back(brain.update(inputVector[i], p));

			std::cout << "Brain's prediction: " << intToLang(outputs[i][0]);

			if (outputs[i][0] == outputVector[i][0])
				std::cout << " (TRUE)" << std::endl;
			else
				std::cout << " (FALSE)" << std::endl;
		}

		std::cout << "\n[INFO] Evaluation finished. Starting fitness calculation..." << std::endl;
		calculateFitness(outputVector, outputs);
		std::cout << "[INFO] Fitness calculation finished.\n" << std::endl;
	}

	std::vector<double> evaluate(std::vector<double> inputs, etunn::Params p)
	{
		std::vector<double> output = brain.update(inputs, p);

		if (output.size() < p.numOutputs)
		{
			std::cout << "Wrong amount of NN outputs!" << std::endl;
			system("PAUSE");
		}

		return output;
	}

	double calculateFitness(std::vector<std::vector<double>> desiredOutputs, std::vector<std::vector<double>> outputs)
	{
		double rightEnglish = 0;
		double wrongEnglish = 0;
		double rightGerman = 0;
		double wrongGerman = 0;

		for (int i = 0; i < outputs.size(); i++)
		{
			if (outputs[i][0] == desiredOutputs[i][0])
			{
				if (desiredOutputs[i][0] == 0)
					rightGerman += 1;
				else
					rightEnglish += 1;
			}
			else
			{
				if (desiredOutputs[i][0] == 0)
					wrongGerman += 1;
				else
					wrongEnglish += 1;
			}
		}

		double totalEnglish = rightEnglish + wrongEnglish;
		double totalGerman = rightGerman + wrongGerman;
		double totalRight = rightEnglish + rightGerman;
		double totalWrong = wrongEnglish + wrongGerman;
		double total = desiredOutputs.size();

		double f;
		f = (1 - (totalWrong / total));
		fitness = f;

		double accuracy = f * 100;
		double englishAccuracy = ((1 - (wrongEnglish / totalEnglish)));
		double germanAccuracy = ((1 - (wrongGerman / totalGerman)));

		std::cout << "Total amounts of words: " << std::to_string((int)total) << std::endl << std::endl;
		std::cout << "English words identified as english: " << std::to_string((int)rightEnglish) << std::endl;
		std::cout << "English words identified as german: " << std::to_string((int)wrongEnglish) << std::endl;
		std::cout << "German words identified as german: " << std::to_string((int)rightGerman) << std::endl;
		std::cout << "German words identified as english: " << std::to_string((int)wrongGerman) << std::endl;
		std::cout << "Total right identified words: " << std::to_string((int)totalRight) << std::endl;
		std::cout << "Total wrong identified words: " << std::to_string((int)totalWrong) << std::endl << std::endl;
		std::cout << "Total accuracy: " << std::to_string(accuracy) << std::endl;
		std::cout << "English accuracy: " << std::to_string(englishAccuracy) << std::endl;
		std::cout << "German accuracy: " << std::to_string(germanAccuracy) << std::endl << std::endl;
		std::cout << "Total fitness: " << std::to_string(f) << std::endl;

		return f;
	}

	double getFitness()
	{
		return fitness;
	}

	etunn::evolutionary::NeuralNet brain;
private:
	std::vector<double> loc_outputs;
	double fitness;
};