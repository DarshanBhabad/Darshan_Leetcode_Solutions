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
      ans=min(ans,m[c]/t[c]);  // refer que 1189 
      // suppose you need i.e in target word have 2l and s has 3l so req target will form only once as 
      // for single target to form we need 2 occu of l 
      // so we devide occu of letter in s by occu of it in target 
      //if target's letter isn't in s it will create m[c] with 0 freq;
      // we store min occu

    }
        return ans;
    }
};