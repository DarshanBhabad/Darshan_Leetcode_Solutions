class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int h_al=0;
        int ans=0;
        for(int i=0;i<gain.size();i++){
          h_al+=gain[i];
          ans=max( ans, h_al);
          gain[i]=h_al;
        

        }
        return ans;
    }
};