/*
DERECLENNE Vincent
C00223820
*/
#include "VoteCounter.h"


VoteCounter::VoteCounter()
{
	this->extract(file);
	this->results.fillUp(this->ballots, this->rank.size());
}


VoteCounter::~VoteCounter()
{
}

void VoteCounter::extract(string file)
{
	string line;
	ifstream myfile(file);
	if (myfile.is_open())
	{
		// get the 1st line
		getline(myfile, line);
		int i;
		int num = 0;
		string nom;
		// this line contains the candidates and their party
		while (line.find(";") != -1)
		{
			i = line.find(";");
			nom = line.substr(0, i);
			line = line.substr(i + 1);
			Candidate* c = new Candidate(nom);
			rank.push_back(c);
			num++;
		}
		// last candidate
		nom = line;
		Candidate* c = new Candidate(nom);
		rank.push_back(c);

		// get ballots
		while (getline(myfile, line))
		{
			BallotPaper* ballot = new BallotPaper();
			int cdt = 0;
			int choice;
			while (line.find(",") != -1)
			{
				i = line.find(",");
				choice = stoi(line.substr(0, i));
				ballot->prefOrder(choice, rank[cdt]);

				line = line.substr(i + 1);
				cdt++;
			}
			ballot->prefOrder(stoi(line), rank[cdt]);
			
			ballots.push_back(ballot);
		}
		myfile.close();
	}

	else cout << "we can't open the file";
}

Candidate * VoteCounter::getWinner()
{
	cout << "Total of ballots : " << this->ballots.size() << "\n";
	Candidate * winner = this->results.getWinner();
	return winner;
}

void VoteCounter::printCandidates()
{
	int len = rank.size();
	for (int i = 0; i < len; i++) {
		cout << "Candidate #" << i << " : \n";
		cout << rank.at(i)->toString();
		cout << "\n";
	}
	cout << "\n";
}

void VoteCounter::printBallots()
{
	for (int i = 0; i < ballots.size(); i++)
	{
		cout << "Ballot #" << i << " : \n";
		cout << ballots.at(i)->toString();
		cout << "\n";
	}
}
