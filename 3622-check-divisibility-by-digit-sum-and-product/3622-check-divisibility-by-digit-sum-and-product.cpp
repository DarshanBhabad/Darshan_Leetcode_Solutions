class Solution {
public:
    bool checkDivisibility(int n) {
     int sum=0;
        double isum=0;
        double prod=1;
        int k=n;
       while(n!=0){
           int rem=n%10;
           
            isum =isum+ rem;
            prod=prod*rem;
           n=n/10;
           sum=isum+prod;
       }
        if(k%sum==0){
            return true;
        }
        return false;
    }
};