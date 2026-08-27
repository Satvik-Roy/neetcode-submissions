class Solution {
    vector<int> parent;
    vector<int> rank;

    int find(int n) {
        int p = parent[n];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]]; 
            p = parent[p];
        }
        return p;
    }

    bool unionNodes(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) {
            return false;
        }

        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            if (!unionNodes(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
};