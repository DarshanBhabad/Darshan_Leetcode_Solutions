class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt=0;
        unordered_set<char>s;
        for(int i=0;i<word.size();i++){
            s.insert(word[i]);

            


        }

        // for(int i=0;i<word.size();i++){
        //     if(islower(word[i]) && s.find(toupper(word[i]))!=s.end()) cnt++;
        // }
        // return cnt;
        for(auto c : s){
             if(islower(c) && s.find(toupper(c))!=s.end()) cnt++;

        }
        return cnt;
    }
};