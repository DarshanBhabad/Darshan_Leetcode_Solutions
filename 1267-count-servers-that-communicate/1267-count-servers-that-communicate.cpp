class Solution {
public:

    int countServers(vector<vector<int>>& grid) {
        //use recursion
        int n=grid.size();
        int m=grid[0].size();
        
         vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Count servers row-wise and column-wise
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;

        // Count communicating servers
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 &&
                   (row[i] > 1 || col[j] > 1)) {
                    ans++; //if it can be connected or it has his supporters in row or col so it can be ans
                }
            }
        }

        return ans;
       
    }
};