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
        


    }
        return ans;
    }
};