/*
DERECLENNE Vincent
C00223820
*/
#include "BallotPaper.h"


BallotPaper::BallotPaper()
{
}


BallotPaper::~BallotPaper()
{
}

void BallotPaper::prefOrder(int n, Candidate* c)
{
	this->places[n] = c;
}

Candidate* BallotPaper::getPreforder(int n)
{
	return this->places[n];
}

string BallotPaper::toString()
{
	string str = "";
	for (int i = 1; i < places.size() + 1; i++)
	{
		str += to_string(i) + " _ " + places[i]->toString() + "\n";
	}
	return str;
}

void BallotPaper::print()
{
	for (int i = 1; i < places.size() + 1; i++)
	{
		cout << i << " _ ";
		places[i]->print();
	}
}