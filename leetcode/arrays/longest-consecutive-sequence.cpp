class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans = 1 , maxi = 1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                continue;
            }
            if(nums[i+1] == nums[i]+1)
            {
                ans++;
            }
            else
            {
                maxi = max(ans,maxi);
                ans = 1;
            }
        }
        maxi = max(ans,maxi);   // if the array is already sorted.
        return maxi;
    }
};