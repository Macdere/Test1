/*
DERECLENNE Vincent
C00223820
*/
#include "Candidate.h"


Candidate::Candidate()
{
}

Candidate::Candidate(string attributs)
{
	int pos = attributs.find(",");
	if (pos != -1)
	{
		this->setName(attributs.substr(0, pos));
		this->setParty(attributs.substr(pos + 1));
	}
	else {
		this->setName(attributs);
		this->setParty("We don't know it yet");
	}
}

Candidate::~Candidate()
{
}

void Candidate::setName(string name)
{
	this->name = name;
}

string Candidate::getName()
{
	return this->name;
}

void Candidate::setParty(string party)
{
	this->party = party;
}

string Candidate::getParty()
{
	return this->party;
}


string Candidate::toString()
{
	return this->getName() + " from " + this->getParty();
}

void Candidate::print()
{
	cout << this->toString() << "\n";
}