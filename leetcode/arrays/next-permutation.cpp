class Solution {
public:
    
    // T.C : O(N)
    // S.C : O(1)
    
    void nextPermutation(vector<int>& nums) {
        int index = -1 , l;
        int n = nums.size();
        for(int i = n-1; i>0 ;i--)
        {
            if(nums[i] > nums[i-1])
            {
                index = i-1;
                break;
            }
        }
        // cout<<index;
        if(index==-1 )
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(l=n-1 ; l>index ; l--)
            {
                if(nums[l] > nums[index])
                {
                    swap(nums[l] , nums[index]);
                    break;
                }
            }
            reverse(nums.begin()+index+1 , nums.end());
        }
    }
};