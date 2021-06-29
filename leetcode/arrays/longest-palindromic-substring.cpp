class Solution {
public:
    string longestPalindrome(string str) {
        //eg: forgeeksskeegfor
        
        int maxi = 1 , len = str.length();
        int low,high,index=0;
        for(int i=1;i<len;i++)
        {
            // for even length palindromes. 
            low = i-1;
            high = i;
            while((low>=0 && high<len) && (str[low] == str[high]))
            {
                if(high-low+1 > maxi)
                {
                    index = low;
                    maxi = high-low+1;
                }
                low--;
                high++;
            }
            // for odd length palindromes.
            low = i-1;
            high = i+1;
            while((low>=0 && high<len) && (str[low] == str[high]))
            {
                if(high-low+1 > maxi)
                {
                    index = low;
                    maxi = high-low+1;
                }
                low--;
                high++;
            }
        }
        string ans = "";
        for(int i=index;i<=index+maxi-1;i++)
        {
            ans = ans + str[i];
        }
        return ans;
    }
};