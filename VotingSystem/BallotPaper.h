/*
DERECLENNE Vincent
C00223820
*/
#pragma once
#include "Candidate.h"
#include <map>

using namespace std;

class BallotPaper
{
public:
	BallotPaper();
	~BallotPaper();

	void prefOrder(int n, Candidate * c);
	Candidate * getPreforder(int n);
	string toString();
	void print();

private:
	// with a preference into a int from 1 to n
	map<int, Candidate*> places;	
};


