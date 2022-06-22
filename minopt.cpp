// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to count the minimum
// steps required to reduce n
int downToZero(int n)
{
	// Base case
	if (n <= 3)
		return n;

	// Allocate memory for storing
	// intermediate results
	vector<int> dp(n + 1, -1);

	// Store base values
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	// Stores square root
	// of each number
	int sqr;
	for (int i = 4; i <= n; i++) {

		// Compute square root
		sqr = sqrt(i);

		int best = INT_MAX;

		// Use rule 1 to find optimized
		// answer
		while (sqr > 1) {

			// Check if it perfectly divides n
			if (i % sqr == 0) {
				best = min(best, 1 + dp[sqr]);
			}

			sqr--;
		}

		// Use of rule 2 to find
		// the optimized answer
		best = min(best, 1 + dp[i - 1]);

		// Store computed value
		dp[i] = best;
	}

	// Return answer
	return dp[n];
}

// Driver Code
int main()
{
	int n = 4;
	cout << downToZero(n);
	return 0;
}
