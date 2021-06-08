class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
        {
            return 0;
        }
        int i=0,j=0,n=s.length(),maxi = INT_MIN;
        unordered_map<char,int> m;
        while(j<n)
        {
            m[s[j]]++;
            if(m.size() == j-i+1)
            {
                maxi = max(maxi,j-i+1);
                j++;
            }
            else if(m.size() < j-i+1)
            {
                while(m.size() < j-i+1)
                {
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};