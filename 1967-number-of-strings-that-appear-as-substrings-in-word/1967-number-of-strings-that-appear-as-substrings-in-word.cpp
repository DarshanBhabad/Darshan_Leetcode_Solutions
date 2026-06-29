class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=word.size();
        int cnt=0;
       
        for(int i=0;i<patterns.size();i++){
          
           if(word.find(patterns[i])<n)  cnt++; //find function returns the idx whre it finds substr
           //1st pos of 1st occurrence
        }
        return cnt;
    }
};