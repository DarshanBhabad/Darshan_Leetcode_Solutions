class Solution {
public:
    int distinctIntegers(int n) {

if(n==1) return 1; // if n=1 is there there will be only one number present i.e 1
return n-1; // automatically they add up like for ex n=8 now 7 will satisfy 8%7=1 for 7- 6 will satisfy justlike go backward   // exclude one as when we reach 2 2%1=0 or x%1=0 which doesnt satisfy
//rem 1 cond'n it will give 0 remainder always so n-1 (exclude 1) 

    }
};