class Solution {
public:
    int gcdOfOddEvenSums(int n) {
    int cnto=0;
    int cnte=0;
    int sumo=0;
    int sume=0;
        for(int i=1;i<INT_MAX;i++){
          
            if(cnte<n && i%2==0){ 
                cnte++;
                sume+=i; 
            }
            else if(cnto<n){
                cnto++;
                sumo+=i;

            } 
            else break;
             


        }
        return gcd(sumo,sume);
    }
};