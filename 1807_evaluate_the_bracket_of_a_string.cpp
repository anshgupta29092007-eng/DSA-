class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;

        // Store key-value pairs
        for (int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {

                string key = "";
                i++;  // move inside bracket

                // Extract key
                for (; s[i] != ')'; i++) {
                    key += s[i];
                }

                // Check key in map
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += "?";
                }

            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};
