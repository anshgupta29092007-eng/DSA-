
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        set<int> available;
        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finishing time, server number}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> busy;

        vector<int> count(k, 0);

        for(int i = 0; i < arrival.size(); i++) {

            // Free servers that have completed their work
            while(!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if(available.empty()) {
                continue;
            }

            // Preferred server
            int server = i % k;

            // Find first available server >= preferred server
            auto it = available.lower_bound(server);

            // Circular search: wrap around
            if(it == available.end()) {
                it = available.begin();
            }

            int chosen = *it;

            // Remove server from available set
            available.erase(it);

            // Update request count
            count[chosen]++;

            // Mark server as busy
            busy.push({arrival[i] + load[i], chosen});
        }

        // Find maximum requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
