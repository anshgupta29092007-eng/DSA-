
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum) {
            return "";
        }

        int nines = sum / 9;
        int rem = sum % 9;

        string ans(nines, '9');

        if (rem > 0) {
            ans += char('0' + rem);
        }

        while (ans.size() < num) {
            ans += '0';
        }

        return ans;
    }
};
