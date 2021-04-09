#include "Puzzle.h"

//Done


Puzzle::Puzzle(string fileName)
{
	this->rightAnswer = 0;

	ifstream inFile(fileName);

	int numberOfAnswers = 0;
	string answer = "";
	int rightAnswers = 0;

	if (inFile.is_open())
	{
		getline(inFile, this->question);
		inFile >> numberOfAnswers;
		inFile.ignore();

		for (size_t i = 0; i < numberOfAnswers; i++)
		{
			getline(inFile, answer);
			this->answers.push_back(answer);
		}

		inFile >> rightAnswer;
		this->rightAnswer = rightAnswer;
		inFile.ignore();
		inFile.close();

		
	}
	else
		throw("Can't Find Puzzle!");

}

Puzzle::~Puzzle()
{


}

string Puzzle::getAsString()
{
	string answers = "";

	for (size_t i = 0; i < this->answers.size(); i++)
	{
		answers += to_string(i) + ": " + this->answers[i] + "\n";
	}

	return this->question + "\n" + "\n" + answers + "\n";
}