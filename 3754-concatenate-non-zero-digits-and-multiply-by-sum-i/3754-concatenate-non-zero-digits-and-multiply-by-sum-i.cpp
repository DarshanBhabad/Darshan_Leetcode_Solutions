class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        //as  original order needs to be preserved convert number to string
        long long x=0;
        long long sum=0;
        for(char c:s){
            int d=c-'0';  //to convert char into its integer val
            if(d!=0){
                x=x*10+d;
                sum+=d;
            }
        }
        return x*sum;
    }
};