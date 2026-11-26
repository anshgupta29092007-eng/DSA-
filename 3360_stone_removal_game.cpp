
class Solution {
public:
    bool canAliceWin(int n) {
        int move = 10;
        int turns = 0;

        while (move > 0 && n >= move) {
            n -= move;
            move--;
            turns++;
        }

        return turns % 2 == 1;
    }
};
