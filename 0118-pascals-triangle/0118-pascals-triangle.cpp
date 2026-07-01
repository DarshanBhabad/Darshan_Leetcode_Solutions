class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        vector<int>l;

        for(int i=1;i<=numRows;i++){
            for(int j=1;j<=i;j++){
                if(j==1 ||j==i){ //last ele of curr row is i
                    l.push_back(1);
                }
                else{
                    l.push_back(v[i-2][j-2] + v[i-2][j-1]);
                    //as vect ar 0 idx based previous rows will ve i-2; and curr element comes from 2 adjacent prev elements (for 0 idx based vector j-2 and j-1 here in dig you can see as j-1 and j)
                }

            }
            v.push_back(l);
            l.clear();

        }
        return v;
     }
};