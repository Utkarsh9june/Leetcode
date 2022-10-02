class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=0,maxsum=INT_MIN;
        for(auto i : nums)
        {
            cursum+=i;
            if(maxsum<cursum)
                maxsum=cursum;
            if(cursum<0)
                cursum=0;
        }
        return maxsum;
    }
};