class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>m;
        for(int i=0;i<word.size();i++){
            if(m.find(word[i])==m.end()){ //so that we store only 1st occurrence of uppercase and last occurrence of lowercase
            m[word[i]]=i; 
            }
         if(islower(word[i])) m[word[i]]=i; //so that to store last occurrence of lowercase each time we find lowercase we need to update its indext but for uppercase we need to update only once
        }
int cnt=0;
        for(auto c:m){
            char u=toupper(c.first);
            if(islower(c.first) && m.find(u)!=m.end() && m[c.first]<m[u]){
                cnt++;
            }
        }
        return cnt;
    }
};