#pragma once

//Done

#include "STLINCLUDE.h"


class Puzzle
{
private:
	string question;
	vector<string> answers;
	int rightAnswer;


public:
	Puzzle(string fileName);
	virtual ~Puzzle();
	string getAsString();

	inline const int& getRightAnswer() const
	{
		return this->rightAnswer;
	}



};