/*
DERECLENNE Vincent
C00223820
*/
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Candidate
{
public:
	Candidate();
	Candidate(string attributs);
	~Candidate();

	void setName(string name);
	void setParty(string party);
	string getName();
	string getParty();
	string toString();
	void print();

private:
	string name;
	string party;
};
