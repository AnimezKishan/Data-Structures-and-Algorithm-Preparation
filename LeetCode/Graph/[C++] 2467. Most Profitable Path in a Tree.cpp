#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS to track Bob's movement towards node 0
    bool bobPath(int node, int parent, int time, unordered_map<int, vector<int>> &adj, unordered_map<int, int> &bobTime) {
        bobTime[node] = time;
        if (node == 0) return true; // Bob reached node 0

        for (int nbr : adj[node]) {
            if (nbr != parent) { // Prevent infinite recursion
                if (bobPath(nbr, node, time + 1, adj, bobTime)) {
                    return true;
                }
            }
        }

        bobTime.erase(node); // If Bob didn't reach 0 from this path, backtrack
        return false;
    }

    // DFS to track Alice's path and maximize profit
    void alicePath(int node, int parent, int currTime, int currIncome, 
                   unordered_map<int, vector<int>> &adj, 
                   unordered_map<int, int> &bobTime, 
                   vector<int> &amount, 
                   int &maxProfit) {

        // Determine Alice's profit at this node
        if (bobTime.find(node) != bobTime.end()) {
            if (bobTime[node] == currTime) {
                currIncome += amount[node] / 2; // Shared with Bob
            } else if (bobTime[node] > currTime) {
                currIncome += amount[node]; // Alice reaches first
            } 
            // If Bob reaches first, Alice gets nothing
        } else {
            currIncome += amount[node]; // Alice alone, takes full amount
        }

        // Check if Alice is at a leaf node (excluding the root)
        if (node != 0 && adj[node].size() == 1) {
            maxProfit = max(maxProfit, currIncome);
        }

        // Traverse neighbors
        for (int nbr : adj[node]) {
            if (nbr != parent) { // Prevent infinite recursion
                alicePath(nbr, node, currTime + 1, currIncome, adj, bobTime, amount, maxProfit);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int, vector<int>> adj;
        int n = edges.size() + 1;

        // Construct the adjacency list
        for (vector<int> &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 1: Calculate Bob's path from node `bob` to node `0`
        unordered_map<int, int> bobTime; // Maps node -> time Bob reaches
        bobPath(bob, -1, 0, adj, bobTime);

        // Step 2: Find Alice's maximum profit path using DFS
        int maxProfit = INT_MIN;
        alicePath(0, -1, 0, 0, adj, bobTime, amount, maxProfit);

        return maxProfit;
    }
};
