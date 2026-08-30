class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = 0;
        int maxindex = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[minIndex]){
                minIndex= i;
            }
            if(nums[i]>nums[maxindex]){
                maxindex = i;
            }

        }
        if(minIndex>maxindex){
            swap(minIndex,maxindex);
        }
        int front = maxindex +1;
        int both = (minIndex +1) + (nums.size() - maxindex);
        int back = nums.size()- minIndex;
        return min(front, min(back,both));
        
    }
};
