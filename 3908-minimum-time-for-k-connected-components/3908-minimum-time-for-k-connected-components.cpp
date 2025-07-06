class Solution {
private:
    class DSU {
    public:
        vector<int> parent;
        vector<int> sz;
        int components;

        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            sz.assign(n, 1);
            components = n;
        }

        int find(int i) {
            if (parent[i] == i) {
                return i;
            }
            return parent[i] = find(parent[i]);
        }

        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                if (sz[root_i] < sz[root_j]) {
                    swap(root_i, root_j);
                }
                parent[root_j] = root_i;
                sz[root_i] += sz[root_j];
                components--;
                return true;
            }
            return false;
        }
    };

public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });

        DSU dsu(n);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];

            if (dsu.unite(u, v)) {
                if (dsu.components < k) {
                    return time;
                }
            }
        }
        return 0;
    }
};