class Solution {
public:
// void getv(int i,int j, vector<vector<int>>& matrix,)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        //recursion
        // getv(0,0,matrix,m,n,ans); 

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         ans.push_back(nums[i]);
        //     }

        //there are four boundries upper lower right and left
       // initially 
   int left=0;
   int right=n-1;
   int up=0;
   int down=m-1;
   while(left<=right && up<=down){
     // Top
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[up][i]);

            up++;// earlier so that it will not be visited again


    // Right
            for (int i = up; i <= down; i++)
                ans.push_back(matrix[i][right]);

            right--; //avaoid duplication on spot --
     // Bottom
            if (up <= down) { //duplication avoided overlapp of up and downup=down singlwe cell
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[down][i]);

                down--;
            }
      // Left
            if (left <= right) {
                for (int i = down; i >= up; i--)
                    ans.push_back(matrix[i][left]);

                left++;
            }
    
   
   }
        return ans;
    }
};