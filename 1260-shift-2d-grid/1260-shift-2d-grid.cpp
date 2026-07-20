class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

       // k %= (m * n);

  k=k%(m*n); //IF K>N afterm* n rotations grid becomes original
  

  while(k--){ //K>0
    vector<vector<int>>temp(m,vector<int>(n)); //temp vect m*n to store changes matrix for current  k 


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j!=n-1) temp[i][j+1]=grid[i][j];
                else if(i!=m-1)  temp[i+1][0]=grid[i][j];         //j=n-1 and i!=m-1 (last row)
                else  temp[0][0]=grid[m-1][n-1]; //when i=m-1 and j=n-1
            }
        }
        grid=temp;

  }

return grid;
        
    }
};