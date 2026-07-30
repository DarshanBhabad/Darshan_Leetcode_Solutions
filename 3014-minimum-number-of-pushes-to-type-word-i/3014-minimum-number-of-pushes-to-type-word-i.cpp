class Solution {
public:
    int minimumPushes(string word) {
        // 1st as we can map letetr to keys 2 to 9 
       // what we will do is that we will keep 8 unique letters from string as clode as that 
    // is at 1st pos of unique keys // then if letters or size is greater than 8 we will pust letters at 2nd pos so we need 2 pushes 
    //also all letters in word are distinct  and max size is 26

 int n=word.size();
 if(n<=8) return n; // all words can be fitted in 1st places in keys (1 to 9) need one push so total pushes =n

 int div= n/8;
 int rem=n%8;
 int pushes= (div+1)*rem;

 while(div>0){
    pushes+=div*8;
    div--;
 }

        return pushes;
    }
};