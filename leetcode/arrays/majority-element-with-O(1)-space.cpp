class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int maj ;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                maj = nums[i];
            }
            if(maj == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return maj;
    }
};