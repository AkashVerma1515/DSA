class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans;
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])] >= 0)
            {
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }
            else
            {
                ans = abs(nums[i]);
            }
        }
        return ans;
    }
};