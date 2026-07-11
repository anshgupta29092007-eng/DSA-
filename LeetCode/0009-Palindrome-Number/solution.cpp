class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        int orignal = x;
        long long reverse = 0;

        for (; x>0;x=x/10){
            int rem = x% 10;
            reverse=reverse*10+rem;
        }
        return orignal == reverse;
        }

        
    
};
