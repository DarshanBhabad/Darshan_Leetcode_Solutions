class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        for(auto &r:image){
            reverse(r.begin(),r.end());
            for(int &e:r){
                if(e==1) e=0;
                else e=1;
            }
        }

       return image;
    }
};