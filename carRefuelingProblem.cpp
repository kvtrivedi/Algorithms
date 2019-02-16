#include <iostream>
#include <vector>
using namespace std;
/*
Brief: This function calculates the minimum number of refills
	   required to go from point A to B.
Input: A vector x of gas station distances,
	   n: number of gas stations
	   D: maximum distance the car can go without refuelling.
Output: Minimum number of refills required.
*/
int minRefills(vector <int> x, int n, int D) {

	int numRefills = 0;
	int currentRefill = 0, lastRefill = 0;
	while (currentRefill <= n) {
		lastRefill = currentRefill;
		while (currentRefill <= n && (x[currentRefill + 1] - x[lastRefill]) <= D) {
			currentRefill++;
		}
		if (lastRefill == currentRefill)
			return -1; //Impossible to go from A-B
		if (currentRefill <= n)
			numRefills++;
	}
	return numRefills;
}

int main() {

	// Vector of distances between points A and B and gas stations 
	// in between them.
	vector <int> x{ 10, 27, 30, 48, 52, 67 };
	int n = 4;
	int D = 20;
	int numRefills = minRefills(x, n, D);
	if (numRefills == -1)
		cout << "The car cannot go from A to B";
	else
		cout << "The car can go from A to B in " << numRefills << " stops.";
	return 0;
}