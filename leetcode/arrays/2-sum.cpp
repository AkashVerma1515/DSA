class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int p = (target-nums[i]);
            if(m.find(p) != m.end())
            {
                return {m[target-nums[i]],i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};