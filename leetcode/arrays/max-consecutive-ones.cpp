class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0 , c = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                c++;
            }
            else
            {
                maxi = max(maxi,c);
                c = 0;
            }
        }
        maxi = max(maxi,c);		// if the last element is 1 then we have to update the maxi.
        return maxi;
    }
};