class Solution {
public:
    int longestPalindrome(string s) {
     unordered_map<char,int>m;
     for(int i=0; i<s.size();i++){
        if(m.find(s[i])!=m.end()) m[s[i]]++;
        else{
            m[s[i]]=1;
        }
     }
int cnt=0;
bool odd=false;
     for(auto k :m){
        if(k.second%2==0) cnt+=k.second;
        else{ //odd
            cnt+=k.second-1;
            odd=true;
        }

     }
       if(odd) return cnt+1;  // ccc   else case will do cnt=2 and here it will be 3.., also cac if cnt=2 else cnt=0  and the will return 3
       return cnt;  //aaaa return cnt
    }
};