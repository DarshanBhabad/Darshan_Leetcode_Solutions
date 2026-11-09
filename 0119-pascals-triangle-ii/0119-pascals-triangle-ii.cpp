class Solution {
public:
    vector<int> getRow(int rowIndex) {
    int numRows=rowIndex+1;
         vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1);
        for(int i=1;i<numRows;i++){
            vector<int>temp;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) temp.push_back(1);
                else temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans.push_back(temp);
        }
       return ans.back(); 
    }
};