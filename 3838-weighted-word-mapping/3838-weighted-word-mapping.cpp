class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
    
    int j=0;
    string ans;
    for(int i=0;i<words.size();i++){
        int sum=0;

         for(char c: words[i]){
            sum+=weights[(c-'a')];
         }
        sum=sum % 26;
        ans+=('z'-sum); 
        // Since 114 fits in a char, C++ implicitly converts it:
        // 114  --->  char(114)
        // and char(114) is 'r' according to the ASCII table.
        


    }
        return ans;
    }
};