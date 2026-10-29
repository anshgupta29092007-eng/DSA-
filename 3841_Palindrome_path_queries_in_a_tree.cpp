
class Solution {
    int n, LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth;
    vector<int> bit;

    int mask(char c) {
        return 1 << (c - 'a');
    }

    void update(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int query(int i) {
        int ans = 0;
        for (; i > 0; i -= i & -i)
            ans ^= bit[i];
        return ans;
    }

    void rangeUpdate(int l, int r, int val) {
        update(l, val);
        if (r < n)
            update(r + 1, val);
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] &&
               tout[v] <= tout[u];
    }

    int lca(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;

        for (int k = LOG - 1; k >= 0; --k) {
            int p = up[k][u];
            if (!isAncestor(p, v))
                u = p;
        }
        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        LOG = 1;
        while ((1 << LOG) <= n) ++LOG;

        adj.assign(n, {});
        up.assign(LOG, vector<int>(n, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        bit.assign(n + 1, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Iterative DFS: Euler tour and parent table
        timer = 0;
        vector<int> parent(n, 0);
        vector<pair<int, int>> st;
        st.push_back({0, 0});

        while (!st.empty()) {
            auto [u, state] = st.back();
            st.pop_back();

            if (state == 0) {
                tin[u] = ++timer;
                up[0][u] = parent[u];

                for (int k = 1; k < LOG; ++k)
                    up[k][u] =
                        up[k - 1][up[k - 1][u]];

                st.push_back({u, 1});

                for (int i = (int)adj[u].size() - 1;
                     i >= 0; --i) {
                    int v = adj[u][i];
                    if (v == parent[u] && u != 0)
                        continue;
                    if (u == 0 && v == 0)
                        continue;

                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    st.push_back({v, 0});
                }
            } else {
                tout[u] = timer;
            }
        }

        // Required intermediate variable
        string suneravilo = s;

        // Initialize each node's contribution
        // to all prefix masks in its subtree.
        for (int u = 0; u < n; ++u)
            rangeUpdate(tin[u], tout[u], mask(s[u]));

        vector<bool> ans;

        for (string& q : queries) {
            string op;
            int u;
            string arg;
            stringstream ss(q);
            ss >> op >> u >> arg;

            if (op == "update") {
                char c = arg[0];

                int delta = mask(s[u]) ^ mask(c);
                rangeUpdate(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                int v = stoi(arg);
                int w = lca(u, v);

                int pathMask =
                    query(tin[u]) ^
                    query(tin[v]) ^
                    mask(s[w]);

                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
