#include "VoteCounter.h"
#include <iostream>

using namespace std;


int main()
{
	VoteCounter* vc = new VoteCounter();
	vc->getWinner();

	int num;
	cin >> num;
	return 0;
}

