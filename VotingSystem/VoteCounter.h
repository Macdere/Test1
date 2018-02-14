/*
DERECLENNE Vincent
C00223820
*/
#pragma once
#include "BallotPaper.h"
#include "Candidate.h"
#include "Node.h"
#include "Arbre.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class VoteCounter
{
public:
	VoteCounter();
	~VoteCounter();
	void extract(string file_path);
	Candidate * getWinner();

	void printCandidates();
	void printBallots();

private:
	const string file = "../votes.txt";
	vector<BallotPaper*> ballots;
	vector<Candidate*> rank;
	Tree results;
};
