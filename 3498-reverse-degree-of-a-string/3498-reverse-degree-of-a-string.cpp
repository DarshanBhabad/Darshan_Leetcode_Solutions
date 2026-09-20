class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        int prod=1;
        for(int i=0;i<s.size();i++){
            prod=(abs(s[i]-'z')+1)*(i+1);
            sum+=prod;
        }
        return sum;
    }
};