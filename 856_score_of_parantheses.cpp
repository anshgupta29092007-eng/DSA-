class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int depth = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                depth++;
            }
            else {
                depth--;

                // Check if this is "()"
                if (s[i - 1] == '(') {
                    ans += (1 << depth);
                }
            }
        }

        return ans;
    }
};
