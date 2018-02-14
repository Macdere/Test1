/*
DERECLENNE Vincent
C00223820
*/
#include "Arbre.h"


Tree::Tree()
{
	root = new Node(nullptr);
}


Tree::~Tree()
{
}

void Tree::fillUp(vector<BallotPaper*> voices, int nbCdt)
{
	Node* current;
	for (int i = 0; i < voices.size(); i++)
	{
		current = root;
		for (int pref = 1; pref < nbCdt + 1; pref++)
		{
			current = current->addNext(voices[i]->getPreforder(pref));
		}
	}
}

void Tree::ejectCandidate(Candidate * c)
{
	this->root->removeCandidate(c);
}

Node * Tree::getLooser()
{
	return root->getLooser();
}

Candidate * Tree::getWinner()
{
	int round = 1;
	while (this->root->getNext().size() > 1)
	{
		cout << "For round #" << round << " here are the candidates :\n";
		for (int numCdt = 0; numCdt < this->root->getNext().size(); numCdt++)
		{
			cout << " + " << this->root->getNext()[numCdt]->toString() << "\n";
		}
		Node * ejected = this->getLooser();
		cout << " Unfortunately,  " << ejected->getCdt()->toString() << " is eliminated.\n";
		cout << endl;
		this->ejectCandidate(ejected->getCdt());
		round++;
	}

	Node * winner = root->getNext()[0];
	cout << "Finally we finished with the round #" << round << " :\n";
	cout << "Our Winner is ...  " << winner->getCdt()->toString() << " !!!\n";
	return winner->getCdt();
}
