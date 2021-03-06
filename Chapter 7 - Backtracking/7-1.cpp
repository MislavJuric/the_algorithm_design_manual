/*
	A derangement is a permutation p of {1, . . . , n} such that no item is in its proper
	position, i.e. pi != i for all 1 ≤ i ≤ n. Write an efficient backtracking program with
	pruning that constructs all the derangements of n items.
*/

#include "stdafx.h"
#include <iostream>

#define MAXCANDIDATES 3

bool is_a_solution(int a[], int k, int n) 
{
	if (k != (n - 1))
	{
		return false;
	}
	bool allPresentAndDifferent = true;
	bool canUse[MAXCANDIDATES];
	for (int i = 0; i < n; i++)
	{
		canUse[i] = true;
	}
	for (int i = 0; i < n; i++)
	{
		if (canUse[a[i]] == false)
		{
			allPresentAndDifferent = false;
		}
		canUse[a[i]] = false;
	}
	for (int i = 0; i < n; i++)
	{
		if (canUse[i] == true)
		{
			allPresentAndDifferent = false;
		}
	}
	return allPresentAndDifferent;
}
void process_solution(int a[], int k)
{
	for (int i = 0; i <= k; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	char c;
	std::cin >> c;
}
void construct_candidates(int a[], int k, int n, int c[], int& ncandidates)
{
	bool canUse[MAXCANDIDATES]; // sve na true na početku
	for (int i = 0; i < n; i++)
		canUse[i] = true;
	for (int i = 0; i < k; i++)
	{
		canUse[a[i]] = false;
	}
	canUse[k] = false; 
	ncandidates = 0;
	for (int i = 0; i < MAXCANDIDATES; i++)
	{
		if (canUse[i])
		{
			c[ncandidates] = i;
			++ncandidates;
		}
	}
}

void backtrack(int a[], int k) // data input)
{
	int c[MAXCANDIDATES]; /* candidates for next position */
	
	int n = MAXCANDIDATES; 

	int ncandidates; /* next position candidate count */
	int i; /* counter */
	if (is_a_solution(a, k, MAXCANDIDATES))
	{
		process_solution(a, k);
		return;
	}
	else {
		k = k + 1; 
		construct_candidates(a, k, n, c, ncandidates); 

		for (i = 0; i<ncandidates; i++) {
			a[k] = c[i];
			// make_move(a, k, input); // don't need this
			backtrack(a, k);
			// unmake_move(a, k, input); // don't need this
			
			// don't need the code below ()

			/*
			if (finished)
				return; // terminate early 
			*/
		}
	}
}

int main()
{
	int a[MAXCANDIDATES];
	for (int i = 0; i < MAXCANDIDATES; i++)
	{
		a[i] = 0;
	}
	backtrack(a, -1);
    return 0;
}

