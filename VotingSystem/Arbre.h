/*
DERECLENNE Vincent
C00223820
*/
#pragma once
#include "Node.h"
#include "Candidate.h"
#include "BallotPaper.h"
#include <vector>

using namespace std;

class Tree
{
public:
	Tree();
	~Tree();
	void fillUp(vector<BallotPaper*> votes, int nbCdt);
	void ejectCandidate(Candidate* c);
	Node* getLooser();
	Candidate * getWinner();
	void toString();

private:
	Node * root;
};