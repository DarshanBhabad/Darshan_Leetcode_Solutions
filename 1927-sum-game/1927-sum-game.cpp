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

       // Alice/Bob can compensate for this difference
        int requiredDiff = 9 * (diffQ / 2);

        return suml - sumr != 9 * (qr - ql) / 2;

    }
};