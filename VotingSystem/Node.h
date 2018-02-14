/*
DERECLENNE Vincent
C00223820
*/
#pragma once
#include "Candidate.h"
#include <vector>

using namespace std;

class Node
{
public:
	Node(Candidate * c);
	~Node();
	Node * addNext(Candidate* c);
	int posNext(Candidate* c);
	void increment();
	void addBranche(Node * added);
	void removeCandidate(Candidate * c);

	Node * getLooser();
	Candidate * getCdt();
	int getVoteCount();
	vector<Node*> getNext();

	string toString();
	void print();

private:
	Candidate * cdt;
	int count;
	vector<Node*> next;
};