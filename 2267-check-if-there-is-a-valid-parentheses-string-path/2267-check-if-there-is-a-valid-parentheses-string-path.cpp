class Solution {
public:
//our stack only stores '(', so you don't actually need the characters in the stack. You only need to know:
// How many unmatched '(' are currently present?

// So:
// stack<int> s become int balance
    bool checkvalid(int i,int j,vector<vector<char>>& grid,int balance,int n,int m,   vector<vector<vector<int>>>& dp){
        if(i>=n||j>=m) return false; //out of bounds
        // if(dp[i][j]!=-1) return dp[i][j]; //path exist from that point

    //    if(grid[i][j] == ')') {
    //         if(s.empty()) return false; //when ) is the first and no (  pushed before
    //        s.pop();
    //    }
       
        // else s.push(grid[i][j]);

        if(grid[i][j] == '(')
            balance++;
        else
            balance--;

             if(balance < 0)
            return false; // i.e there  is only onr ) so it will not have previous (

            if(dp[i][j][balance] != -1)
            return dp[i][j][balance];

        // if(i == n-1 && j == m-1) {
        //     return s.empty();
        // }
        
    //     //dp will have either 0,1,-1
    //   return dp[i][j]= (checkvalid(i,j+1,grid,s,n,m,dp)||
    //     checkvalid(i+1,j,grid,s,n,m,dp)); //right and down
    if(i == n-1 && j == m-1)
            return dp[i][j][balance] = (balance == 0);   // store 1 if valid 0 if invalid i.e bal>0

        return dp[i][j][balance] =
            checkvalid(i, j+1, grid, balance, n, m, dp) ||
            checkvalid(i+1, j, grid, balance, n, m, dp); 
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        //stack<int>s;
        int balance =0; // count how many  (  currently exist 
        //memoization
        
        int n=grid.size();
        int m=grid[0].size();
        // true = calculates and valid path exist 1, false = 0, and initialized with -1;
        // vector<vector<int>>dp(n,vector<int>(m,-1));

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                m,
                vector<int>(n + m + 1, -1)
            )
        );
        return checkvalid(0,0,grid,balance,n,m,dp);

        
    }
};