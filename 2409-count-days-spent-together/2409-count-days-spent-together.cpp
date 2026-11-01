class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        //TC=O(1) SC=O(1)
        int nd[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        ///LAMDA FUNCTION when you do'nt want to create seperate function in class and want to crete a function unside your dfunctin then we use it - increases code eusability 

        //defn=>   auto name = [capture](parameters) { body }; 
        //{} = capture serves as what you want to capture which yopu dont want to pass as argument/parameter 

        // to convert date to days
        // & -> pass weverything else as reference so that we can use nd 
        auto getdays=[&](string s){ 
            int m = stoi(s.substr(0,2));//will extract month and cob=nvert to int
            int d=stoi(s.substr(3,2)); // st index and how many 

            for(int i=0;i<m-1;i++){
                d+=nd[i];   // to add days previous months 
            }
           return d;
        };
        //these function will give which day of year is it 
        int a1=getdays(arriveAlice);
        int l1=getdays(leaveAlice);
        int a2=getdays( arriveBob);
        int l2=getdays(leaveBob);


        int start=max(a1,a2);
        int end=min(l1,l2);
        //if end < st the means no overlapp 0 as we tppk start as max of startings and end as min of startings 
        //if overlapp end should come after start no mater what 


        if(start>end) return 0;
        return end-start+1; //inclusive 

    }
};