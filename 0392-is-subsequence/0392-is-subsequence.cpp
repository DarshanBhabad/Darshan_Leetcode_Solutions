class Solution {
public:
    bool isSubsequence(string s, string t) {
       // int prev=0;
        int cnt=0;
        int j=0;
        if(s.empty()) return true;
        for(int i=0;i<t.size();i++){
            if(cnt==s.size()) return true;
            if(t[i]==s[j]){
                cnt++;
                
                j++;

            } 
        }
         return cnt == s.size();   //or no need to compare with cnt just compare with j
    }
};