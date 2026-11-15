
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long mod = 1e9 + 7;

        long long even = 1;
        long long odd = 0;
        long long ans = 0;
        long long sum = 0;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if(sum % 2 == 0) {
                ans += odd;
                even++;
            }
            else {
                ans += even;
                odd++;
            }

            ans %= mod;
        }

        return ans;
    }
};
