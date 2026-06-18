class Solution {
public:
    double angleClock(int hour, int minutes) {
//if hr are in 24 hr format // Convert 24-hour format to 12-hour format (e.g., 13 becomes 1, 12 becomes 0)
//int hour12 = hour % 12;    here no need
        
        // minutes hand travels 6 deg in 1 min as 60m =360 deg
        // and hour hand 12 hr= 360 deg so  1 min is 0.5 deg   and in 60min it will cover 30 deg
        // all prev 2 conc are for scle on 360 deg so use modulo to covert hour angles to 360 deg form
       double anglem=(double)minutes*6 ;
       double anglehr= (hour % 12) * 30 + minutes * 0.5;              //total minutes for hr hand is hr * 60 + minutes
     double diff=abs(anglehr-anglem);  //int = -1,2,3 , 0  float=1.5 2.4   double = large size 1.2233
       return min(diff,360-diff);
             
    //    Why 360 - diff?   as we need min angle betn them return the smaller angle (in degrees)
    //    hour hand = 10°
    //    minute hand = 350°
    }
};