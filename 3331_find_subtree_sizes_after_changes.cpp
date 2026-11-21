
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        vector<int> prev(n, -1);
        vector<int> last(26, -1);

        // Iterative DFS: {node, state}
        // state 0 = entering, state 1 = exiting
        stack<pair<int, int>> st;
        st.push({0, 0});

        while (!st.empty()) {
            auto [u, state] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (state == 0) {
                // Remember previous ancestor with same character
                prev[u] = last[c];

                // Current node becomes latest ancestor
                last[c] = u;

                // Process children before exiting
                st.push({u, 1});

                for (int i = adj[u].size() - 1; i >= 0; i--) {
                    st.push({adj[u][i], 0});
                }
            }
            else {
                // Restore previous ancestor
                last[c] = prev[u];

                // Determine final parent
                int p = (prev[u] != -1) ? prev[u] : parent[u];

                // Add current subtree size to its final parent
                if (p != -1) {
                    ans[p] += ans[u];
                }
            }
        }

        return ans;
    }
};
