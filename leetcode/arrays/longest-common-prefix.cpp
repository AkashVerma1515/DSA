class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int minlen = INT_MAX;
        if(s.size()==0)
        {
            return "";
        }
        string c = s[0];
        for(int i=1;i<s.size();i++)
        {
            int j = 0 , k = 0 , a = 0;
            while(j<c.length() && k < s[i].length())
            {
                if(c[j] == s[i][k])
                {
                    a++;
                }
                else
                {
                    break;
                }
                k++;
                j++;
            }
            minlen = min(minlen,a);
        }
        return c.substr(0,minlen);
        
    }
};