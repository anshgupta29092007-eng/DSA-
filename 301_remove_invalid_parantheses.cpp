class Solution {
public:

    set<string> ans;

    void dfs(string &s, int index,
             int leftRemove, int rightRemove,
             int leftCount, int rightCount,
             string current) {

        // Reached end
        if (index == s.length()) {

            if (leftRemove == 0 &&
                rightRemove == 0 &&
                leftCount == rightCount) {

                ans.insert(current);
            }

            return;
        }

        char ch = s[index];

        // OPTION 1: Remove current '('
        if (ch == '(' && leftRemove > 0) {
            dfs(s, index + 1,
                leftRemove - 1, rightRemove,
                leftCount, rightCount,
                current);
        }

        // OPTION 2: Remove current ')'
        if (ch == ')' && rightRemove > 0) {
            dfs(s, index + 1,
                leftRemove, rightRemove - 1,
                leftCount, rightCount,
                current);
        }

        // OPTION 3: Keep current character

        if (ch != '(' && ch != ')') {
            dfs(s, index + 1,
                leftRemove, rightRemove,
                leftCount, rightCount,
                current + ch);
        }

        else if (ch == '(') {
            dfs(s, index + 1,
                leftRemove, rightRemove,
                leftCount + 1, rightCount,
                current + ch);
        }

        else if (ch == ')' && leftCount > rightCount) {
            dfs(s, index + 1,
                leftRemove, rightRemove,
                leftCount, rightCount + 1,
                current + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum number of removals
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }

            else if (ch == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        dfs(s, 0,
            leftRemove, rightRemove,
            0, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};
