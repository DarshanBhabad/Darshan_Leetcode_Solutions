class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        
     unordered_map<char,int>m;
     unordered_map<char,int>t;
     for(char c : s) {
           
                m[c]++;
        }

    for(char c: target){
         t[c]++;
    }
int ans=INT_MAX;
    for(char c :target){
      ans=min(ans,m[c]/t[c]);
    }
        return ans;
    }
};