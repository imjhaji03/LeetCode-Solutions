class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        using namespace std;
        if (n <= 1) {
            return n;
        }

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(1 << n, false)));
        queue<tuple<int, int, int>> q;
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            int mask = 1 << i;
            if (!visited[i][i][mask]) {
                q.push({i, i, mask});
                visited[i][i][mask] = true;
                maxLen = max(maxLen, 1);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int neighbor : adj[i]) {
                if (i < neighbor && label[i] == label[neighbor]) {
                    int mask = (1 << i) | (1 << neighbor);
                    if (!visited[i][neighbor][mask]) {
                        q.push({i, neighbor, mask});
                        visited[i][neighbor][mask] = true;
                        visited[neighbor][i][mask] = true;
                        maxLen = max(maxLen, 2);
                    }
                }
            }
        }

        while (!q.empty()) {
            auto [u, v, mask] = q.front();
            q.pop();

            for (int next_u : adj[u]) {
                for (int next_v : adj[v]) {
                    if (label[next_u] == label[next_v]) {
                        bool is_next_u_in_mask = (mask >> next_u) & 1;
                        bool is_next_v_in_mask = (mask >> next_v) & 1;

                        if (!is_next_u_in_mask && !is_next_v_in_mask) {
                            if (next_u == next_v) continue;
                            
                            int new_mask = mask | (1 << next_u) | (1 << next_v);
                            if (!visited[next_u][next_v][new_mask]) {
                                visited[next_u][next_v][new_mask] = true;
                                visited[next_v][next_u][new_mask] = true;
                                q.push({next_u, next_v, new_mask});
                                maxLen = max(maxLen, __builtin_popcount(new_mask));
                            }
                        }
                    }
                }
            }
        }

        return maxLen;
    }
};