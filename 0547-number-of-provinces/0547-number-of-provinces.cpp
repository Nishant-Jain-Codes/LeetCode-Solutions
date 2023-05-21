class Solution {
private:
    void DFS(int curV, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[curV] = true;
        for (int i = 0; i < adj[curV].size(); i++) {
            int nextV = adj[curV][i];
            if (!visited[nextV]) {
                DFS(nextV, adj, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        int n = M.size();
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                DFS(i, adj, visited);
            }
        }

        return count;
    }
};
