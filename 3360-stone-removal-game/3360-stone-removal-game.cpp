class Solution {
public:
   bool check(int n,int c,bool next){
    if(c>n) return !next;//cant take the turn 
    n=n-c;
    if(next)//alice turn
     return check(n,c-1,false); //next turn will be bobbob turn; 
    else //bob turn 
       return check(n,c-1,true); //nex turn wil be alice

   }
    bool canAliceWin(int n) {
        //recursion
        if(n<10) return false;
       // bool ans=true;
       return check(n,10,true);
    }
};