class Solution {
public:

 vector<vector<int>> rotateninety(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> rotated(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][n - 1 - i] = mat[i][j];
            }
        }

        return rotated;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        //the should have same elements columnwise
        int n=mat.size();
        
// there are only 4 valid matric roations 90 deg = 0,90,180,270 ..360 again give sma eas 0

            for(int k=0;k<4;k++){
       
                if(mat==target) return true;

                mat=rotateninety(mat);
            }



        return false;
    }
};