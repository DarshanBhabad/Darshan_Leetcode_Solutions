class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //O(M*N)
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>row(n,false);
        vector<bool>col(m,false);
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                //these are gonna get affected
                row[i]=true;
                col[j]=true; 
            }
        }
      }

      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]||col[j]){ //0 isp resent in these cells row or col 
                //these are gonna get affected
                matrix[i][j]=0;
            }
        }
      }

      

        
        
    }
};


// DFS traversal: \(O(n*m)\) — each cell is visited at most once because you use vis[r][c].



// Final nested loops: \(O(n*m))\) — you traverse every cell to set zeros.
// class Solution {
// public:
// //TC=O(m*n)
// void dfs(int r,int c, vector<vector<int>>& matrix,vector<vector<bool>>& vis,vector<bool>& row,
//              vector<bool>& col,int n,int m){
//     if(r<0 || r>=n ||c<0 || c>=m ) return;
//    if (vis[r][c])
//             return;
//    vis[r][c] = true;
//      if (matrix[r][c] == 0) {
//             row[r] = true;
//             col[c] = true;
//         }
//     dfs(r-1,c,matrix,vis,row, col, n, m);//up
//     dfs(r+1,c,matrix,vis,row, col, n, m);//down
//     dfs(r,c-1,matrix,vis,row, col, n, m);//left
//     dfs(r,c+1,matrix,vis,row, col, n, m);//right
//     return;
    
// }
//     void setZeroes(vector<vector<int>>& matrix) {
//         //WE CAN DDO IT BY TREATING IT AS GRAPH ALSO OPTIMIZE BY USING BOOL MATRIX
//         int n=matrix.size();
//         int m=matrix[0].size();

// vector<vector<bool>>vis(n,vector<bool>(m,false));
// vector<bool> row(n, false);
//         vector<bool> col(m, false);
//         dfs(0, 0, matrix, vis, row, col, n, m); //celculate or store how many s=cells gets affeted by zeros 

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if (row[i] || col[j]) //either of one is true i.e this elemnts row or col contains zero
//                     matrix[i][j] = 0;
//             }
//         }
//         return;
//     }
// };