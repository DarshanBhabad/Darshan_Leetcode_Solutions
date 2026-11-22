class Solution {
public:
    bool checkString(string s) {
        //every a should be before every b
        bool a=false;
        bool b=false;
        for(int i=0;i<s.size();i++){
             if(s[i]=='a' && b) return false;
             if(s[i]=='a') a=true;
             if(s[i]=='b') b=true;

        }

        // or just sort copy the string sort it and if sorted and original equal return true els efalse 
        // as for a to appear before b it should be sorted
        return true;
    }
};