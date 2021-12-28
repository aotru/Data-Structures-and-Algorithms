// Credit: Andrew Zhou
#include <vector>
using namespace std;


using memo = vector<vector<int>>;
inline int helper(vector<int>& pipes, memo& weights, memo& costs, int first, int last);


inline int weld_pipes(vector<int>& pipes) {
    memo weights(pipes.size(), vector<int>(pipes.size()));
    memo costs(pipes.size(), vector<int>(pipes.size(), -1));
    return helper(pipes, weights, costs, 0, pipes.size() - 1);
}

inline int helper(vector<int>& pipes, memo& weights, memo& costs, int first, int last) {
    if (costs[first][last] != -1) {
        return costs[first][last];
    }

    // Base Case
    if (first == last) {
        costs[first][last] = 0;
        weights[first][last] = pipes[first];
        return 0;
    }

    int min_cost = INT_MAX;
    for (int k = first; k < last; ++k) {
        int weld_cost = helper(pipes, weights, costs, first, k)
                      + helper(pipes, weights, costs, k + 1, last);
        weld_cost += max(weights[first][k], weights[k + 1][last]);
        min_cost = min(min_cost, weld_cost);
    }

    costs[first][last] = min_cost;
    weights[first][last] = weights[first][first] + weights[first + 1][last];
    return min_cost; // or costs[first][last]
}