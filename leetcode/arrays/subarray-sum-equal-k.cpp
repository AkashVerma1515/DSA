class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int sum = 0 , count = 0;
        unordered_map<int,int> m;
        for(int i=0;i<a.size();i++)
        {
            sum = sum + a[i];
            if(sum==k)
            {
                count++;
            }
            if(m.find(sum-k) != m.end())
            {
                count += m[sum-k];
            }
            m[sum]++;
        }
        return count;
    }
};