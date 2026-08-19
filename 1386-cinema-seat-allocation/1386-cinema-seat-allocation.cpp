class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        //optimal choice in each row
        // each r eo can maximum have 2  fromations to set group of 4


        // Every completely empty row can accommodate 2 groups
        int ans = 2 * n;

    set<pair<int,int>>s; // so rowwise order will be there 1st row and if row same then colm 
        for(auto p:reservedSeats){
            s.insert({p[0],p[1]});

        }
       
         
        // Process only rows having reservations
        set<int> rows;

        for(auto p : reservedSeats) {
            rows.insert(p[0]);
        }

        for(int row : rows) {

            bool left = true;   // 2,3,4,5
            bool middle = true; // 4,5,6,7
            bool right = true;  // 6,7,8,9

            for(int seat = 2; seat <= 9; seat++) {

                if(s.count({row, seat})) {//if its is reserved

                    if(seat >= 2 && seat <= 5)
                        left = false;

                    if(seat >= 4 && seat <= 7)
                        middle = false;

                    if(seat >= 6 && seat <= 9)
                        right = false;
                }
            }

            // We initially counted this row as 2.
            // Determine its actual capacity.
            if(left && right) {
                // Can actually accommodate 2
            }
            else if(left || middle || right) { //atleast one is true
                ans--; // this row can accommodate only 1
            }
            else {
                ans -= 2; // this row can accommodate 0
            }
        }

        return ans;
    
    

    }
};