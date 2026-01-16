class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        size_t n = mat.size();
        int primaryDigSum = 0, secondaryDigSum = 0;
        // primary diagonal follows pattern
        // for r,c=n where n = 3 -> 0,0 1,1 2,2
        // i = j, i -> row , j -> col
        // so each iteration increment both
        // secondary diagonal follow pattern:
        // for r,c-n where n = 3 -> 0,2 1,1 2,0
        // i = 0 and it increments j = n-1 - i
        // so each iteration
        for (size_t i = 0; i < n; i++) {
            primaryDigSum += mat[i][i];
            secondaryDigSum += mat[i][n - 1 - i];
        }
        int sum = primaryDigSum + secondaryDigSum;
        // if n [=r=c] is odd central element would be counted twice so get rid of it
        if (n%2 != 0) sum -= mat[n/2][n/2];
        return sum;
    }
};