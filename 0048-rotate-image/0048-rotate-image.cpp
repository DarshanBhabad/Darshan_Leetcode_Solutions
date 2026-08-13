class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
//         vector<vector<int>>ninety(n);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 // 90 degree coulums repaced by rows 
//                 ninety[i][j]=matrix[n-1-j][i];
//             }
//         }
// return ninety;
    
    // get the tranpose = all elements of rows are converted to columns then reverse each row using reverse function

vector<vector<bool>>visited(n,vector<bool>(n,false));

         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

              //  if(i!=j){
                if(!visited[i][j] &&!visited[j][i]){
               swap(matrix[i][j],matrix[j][i]); 
                visited[i][j]=true;
                visited[i][j]=true;
                }

              //  }
            }
         }
          // now we got the transpose
//reverse each row 
// for(auto r: matrix){
// reverse(matrix[r].begin(),matrix[r].end());
// }

// reverse(matrix.begin(),matrix.end()); last row to 1st 


for (auto& row : matrix) { // each rows elements are being reversed
    reverse(row.begin(), row.end());
}

return ;

// APPROACH 2 as i==j no swapping so 
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 swap(matrix[j][i],matrix[i][j]);     //it will make sure elements for each row only cross will swappped
//             }
//         }
//         for(int i=0;i<n;i++){
//             reverse(matrix[i].begin(),matrix[i].end());
//         }
//     }
//};
    }
};