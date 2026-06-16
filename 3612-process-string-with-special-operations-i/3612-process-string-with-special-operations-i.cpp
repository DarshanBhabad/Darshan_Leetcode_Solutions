class Solution {
public:
bool islowerc(char c){
    if(c>='a' && c<='z') return true; //checks ascii val
    return false;
}

void reverses(string &result){
    int i=0;
    int j=result.size()-1;

    while(i<j){
        swap(result[i],result[j]);
        i++;
        j--;
    }
}

string processStr(string s) {
    string result=""; //empty string 

    for(int i=0;i<s.size();i++){
 
    if(islowerc(s[i])) result+=s[i]; //or push_back()
    if(s[i]=='*' && !result.empty()) result.pop_back();
    if(s[i]=='#' && !result.empty()) result+=result;
    if(s[i]=='%' && !result.empty()) reverses(result);


    }

       return result; 
    }
};