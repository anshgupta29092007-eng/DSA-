class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (char c : s) {

            if (c == ')') {
                string temp = "";

                // Take characters until '('
                while (st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                // Remove '('
                st.pop();

                // Put reversed string back
                for (char x : temp) {
                    st.push(x);
                }

            } else {
                st.push(c);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
