// Given an array cotaining zeros and non-zero elements, you need to figure out
// the minimum number of swaps between zero and non-zero elements such that
// the non-zero elements are sorted in ascending order and all zeros are
// pushed to the end.

// If I didn't have the constraint that only zero and non-zero elements can be
// swapped, it would have been much easier:
//

#include <vector>

using namespace std;

int getMinSwaps(vector<int> arr) {
  int n = arr.size();

  // Step 1: Separate the problem - count swaps to sort non-zero elements
  vector<pair<int, int>> nonZeros;
  for (int i = 0; i < n; ++i) {
    if (arr[i] != 0) {
      nonZeros.push_back({arr[i], i});
    }
  }

  // Sort non-zero elements by value
  sort(nonZeros.begin(), nonZeros.end());

  // Count cycles in the permutation of non-zero elements
  int swaps = 0;
  vector<bool> visited(nonZeros.size(), false);

  for (int i = 0; i < nonZeros.size(); ++i) {
    // If already visited or already in correct position
    if (visited[i] || nonZeros[i].second == i) {
      continue;
    }

    // Count elements in this cycle
    int cycleSize = 0;
    int j = i;

    while (!visited[j]) {
      visited[j] = true;
      j = nonZeros[j].second;
      cycleSize++;

      // If we've gone beyond our array or hit a zero, break
      if (j >= nonZeros.size())
        break;
    }

    // In a cycle of size k, we need (k-1) swaps
    if (cycleSize > 0) {
      swaps += (cycleSize - 1);
    }
  }

  // Step 2: Count minimum swaps to move zeros to the end
  int zeroCount = n - nonZeros.size();
  int nonZeroPositionsAfterSort = 0;

  // Count non-zero elements that will be in zero positions after sorting
  for (int i = 0; i < nonZeros.size(); ++i) {
    if (nonZeros[i].second >= nonZeros.size()) {
      nonZeroPositionsAfterSort++;
    }
  }

  // Each non-zero element in the zero zone requires one swap with a zero
  swaps += nonZeroPositionsAfterSort;

  return swaps;
}
