class Solution {
public:
    bool isAnagram(string s, string t) {
        //eitehtr use map or fixed 26 sized array 
        //reduce the count // freq of charcter is need to be same
        vector<int>frq(26,0);
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            frq[s[i]-'a']++;
            frq[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(frq[i]!=0) return false;
        }
        return true;
    }
};