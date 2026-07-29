class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        
        map<int,int>m;//wherever key entry happens in map it initilizes itself with 0 value;
        // ordered map so sorted order of key that is value
        for(auto i:items1){
            m[i[0]]+=i[1];

        }
        for(auto i:items2){
            m[i[0]]+=i[1];

        }

        vector<vector<int>>ans;
        for(auto p: m){
            ans.push_back({p.first,p.second});
        }
        return ans;
    }
};