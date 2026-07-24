class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n=matrix.size(); //its n*n matrix
        
    //     k=k-1; //to map k in 0 based indexing
    //     int m = k / n; // Correct row index
    //     int r = k % n; // Correct column index
    //    return matrix[m][r];

    priority_queue<int>q; //max heap keeps max element at the top from current inserted elements
    for(int i=0;i<n;i++ ){
        for(int j=0;j<n;j++){
            if(q.size()<k)q.push(matrix[i][j]);
            //when q size is greater then k or k
            else if(q.top()>matrix[i][j]) {
                q.pop();
                q.push(matrix[i][j]);
            }
        }
    }
        return q.top();
    }
};