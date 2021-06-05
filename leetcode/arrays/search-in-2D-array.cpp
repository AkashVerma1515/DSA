class Solution {
public:
    
    //T.C : O(logN)
    //S.C : O(1)
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0, row, col, value;
        int r = matrix.size();
        int c = matrix[0].size();
        int end = r * c - 1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            row = mid/c;
            col = mid%c;
            value = matrix[row][col];
            if(target == value)
            {
                return true;
            }
            if(value>target)
            {
                end = mid-1;
            }
            if(value<target)
            {
                start = mid+1;
            }
        }
        return false;
    }
};