#include "Node.h"


Node::Node(Candidate * c)
{
	this->count = 0;
	this->cdt = c;
}


Node::~Node()
{
}


Node * Node::addNext(Candidate * c)
{
	Node* follower;
	int pos = this->posNext(c);
	if (pos == -1)
	{
		follower = new Node(c);
		this->next.push_back(follower);
	}
	else
	{
		follower = this->next[pos];
	}
	follower->increment();
	return follower;
}

int Node::posNext(Candidate * c)
{
	int pos = -1;
	for (int i = 0; i < this->next.size(); i++)
	{
		if (this->next[i]->cdt == c)
		{
			pos = i;
		}
	}
	return pos;
}

void Node::increment()
{
	this->count++;
}

void Node::addBranche(Node * added)
{
	for (int i = 0; i < added->next.size(); i++)
	{
		int pos = this->posNext(added->next[i]->getCdt());
		if (pos != -1)
		{
			this->next[pos]->count += added->next[i]->getVoteCount();
			this->next[pos]->addBranche(added->next[i]);
		}
	}
}

void Node::removeCandidate(Candidate * c)
{
	int pos = this->posNext(c);
	if (pos != -1)
	{
		this->addBranche(this->next[pos]);
		this->next.erase(this->next.begin() + pos);
	}
	for (int i = 0; i < this->next.size(); i++)
	{
		next[i]->removeCandidate(c);
	}
}

Node * Node::getLooser()
{
	Node * looser = next[0];
	for (int i = 0; i < this->next.size(); i++)
	{
		if (next[i]->getVoteCount() < looser->getVoteCount())
			looser = next[i];
	}
	return looser;
}

Candidate * Node::getCdt()
{
	return this->cdt;
}

int Node::getVoteCount()
{
	return this->count;
}

vector<Node*> Node::getNext()
{
	return this->next;
}

string Node::toString()
{
	string str = this->cdt->toString() + " obtain a total of " + to_string(this->count) + " vote(s).";
	return str;
}

void Node::print()
{
	if (this->cdt != nullptr)
	{
		cout << "++ " << this->count << " - ";
		this->cdt->print();
	}
	for (int i = 0; i < this->next.size(); i++)
	{
		next[i]->print();
	}
}
