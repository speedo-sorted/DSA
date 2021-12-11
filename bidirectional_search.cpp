/*
see full info here - 
https://www.geeksforgeeks.org/shortest-path-using-meet-in-the-middle/
*/

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find minimum number of
// swaps to make another permutation
int ShortestPath(int n, string start, string finish)
{
	unordered_map<string, bool> visited;
	unordered_map<string, int> D;
	unordered_map<string, string> src;

	visited[start] = visited[finish] = true;
	D[start] = D[finish] = 0;
	src[start] = start;
	src[finish] = finish;

	queue<string> q;
	q.push(start);
	q.push(finish);

	while (!q.empty()) {

		// Take top vertex of the queue
		string u = q.front();
		q.pop();

		// Generate n - 1 of it's permutations
		for (int i = 1; i < n; i++) {

			// Generate next permutation
			string v = u;
			swap(v[i], v[i - 1]);

			// If v is not visited
			if (!visited[v]) {

				// Set it visited
				visited[v] = true;

				// Make root of u and root of v equal
				src[v] = src[u];

				// Increment it's distance by 1
				D[v] = D[u] + 1;

				// Push this vertex into queue
				q.push(v);
			}

			// If it is already visited
			// and roots are different
			// then answer is found
			else if (src[u] != src[v])
				return D[u] + D[v] + 1;
		}
	}
}

// Driver code
int main()
{
	string p1 = "1234", p2 = "4123";
	int n = p1.length();
	cout << ShortestPath(n, p1, p2);

	return 0;
}
