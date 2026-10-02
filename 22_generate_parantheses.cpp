class Solution {
public:
    void solve(int open, int close, int n, string s, vector<string>& ans) {

        // If we have used all parentheses
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }

        // We can add '(' if we haven't used n opening brackets
        if (open < n) {
            solve(open + 1, close, n, s + '(', ans);
        }

        // We can add ')' only if there are unmatched '('
        if (close < open) {
            solve(open, close + 1, n, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};
