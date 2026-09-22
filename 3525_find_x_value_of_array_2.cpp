class Solution {
public:

    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int k;

    Node merge(Node a, Node b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left
        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        // Prefixes which contain entire left
        // and then some prefix of right
        for (int r = 0; r < k; r++) {
            int newRem = (a.prod * r) % k;
            res.cnt[newRem] += b.cnt[r];
        }

        return res;
    }

    vector<Node> seg;

    void build(vector<int>& nums, int idx, int l, int r) {

        if (l == r) {
            int v = nums[l] % k;

            seg[idx].prod = v;
            seg[idx].cnt[v] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, idx * 2, l, mid);
        build(nums, idx * 2 + 1, mid + 1, r);

        seg[idx] = merge(seg[idx * 2],
                         seg[idx * 2 + 1]);
    }

    void update(int idx, int l, int r,
                int pos, int val) {

        if (l == r) {

            val %= k;

            seg[idx] = Node();

            seg[idx].prod = val;
            seg[idx].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, val);
        else
            update(idx * 2 + 1, mid + 1, r, pos, val);

        seg[idx] = merge(seg[idx * 2],
                         seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r,
               int ql, int qr) {

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(idx * 2,
                         l, mid,
                         ql, qr);

        if (ql > mid)
            return query(idx * 2 + 1,
                         mid + 1, r,
                         ql, qr);

        Node left = query(idx * 2,
                          l, mid,
                          ql, qr);

        Node right = query(idx * 2 + 1,
                           mid + 1, r,
                           ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {

        k = K;

        int n = nums.size();

        seg.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Permanent update
            update(1, 0, n - 1,
                   index, value);

            // Query [start, n-1]
            Node res = query(1, 0, n - 1,
                             start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};
