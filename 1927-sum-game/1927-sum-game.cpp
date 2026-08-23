class Solution {
public:
    bool sumGame(string num) {
        //GREEDY .... as each one want 2to win 

        // cnt initial sum of both halfs
        int n=num.size();
        int mid=n/2; // arr is allways even length
       int ql=0;
       int qr=0;
        int suml=0;
        int sumr=0;
        for(int i=0;i<n;i++){
             if (num[i] == '?') {
                if (i < mid)
                    ql++;
                else
                    qr++;
            }
            else {
                if (i < mid)
                    suml += num[i] - '0';
                else
                    sumr += num[i] - '0';
            }
        }
        
        //alice tries to maximuiz ethe difference so that sum never becomes equal so it adds the maximum value to already max half if max half doesnt have ?  minimize the min hald add 0
        // bob oin it sattempt tries to minimize the difference
       
       
        // If total number of ? is odd,
        // Alice gets one extra move and can always win.
        if ((ql + qr) % 2 == 1)
            return true;
    
    // Difference in ? between the two halves
        int diffQ = abs(ql - qr);

       // Alice/Bob can compensate for this difference both choosing 9 ,9 in respective tuns in opposite halfs


       //now q's that are in the same half  // alice always choose 9 and bob 0 to oppose each other 
        int requiredDiff = 9 * (diffQ / 2);  //dffQ/2 is the total  pairs  each pair gives 9

        return suml - sumr != 9 * (qr - ql) / 2; //(if true then alice win as cant make both sum equal)   // so we track respective halfs

//         suml - sumr = 9  
// 9 * (qr - ql) / 2   
// = 9 * (1 - 3) / 2    
// = -9  //  9!=-9 alice wins  these difference should be covered by one who has large value 
//here suml was large  and qr were less that is 1  so again left contains 1 extra pair 
// so it only make  suml big by 9 & not increase sumr to match suml

    }
};