class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int votes=0,candidate=-1;
        for(int i=0;i<n;i++)
        {
            if(votes==0)
            {
                votes++;
                candidate=nums[i];
            }
            else
            {
                if(nums[i]==candidate)
                    votes++;
                else
                    votes--;
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==candidate)
                count++;
        }
        if(count>=n/2)
            return candidate;
        else
            return -1;
    }
};