class Solution {
public:
    int countCommas(int n) {
       
        int td=0;
        int k=n;
        while(k!=0){
            td++;
            k/=10;
        }
       if(td<4) return 0;
     // int p=td/3;
     return n-999;

        
    }
};