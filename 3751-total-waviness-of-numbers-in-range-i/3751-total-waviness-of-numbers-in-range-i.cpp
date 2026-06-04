class Solution {
public:
int countwavi(int num){
    string p= to_string(num);
    int cnt=0;
    if(p.size()<3) return 0; //optimization as if curr i is less tha 3 size wavi is 0;
    for(int i=1;i<p.size()-1;i++){
        // if((p[i-1]-'0'<p[i]-'0'>p[i+1]-'0') ||(p[i-1]-'0'>p[i]-'0'<p[i+1]-'0')) cnt++; doesnt support like paython a<b>c evaluated as (a>b)>c
        //so
        int a = p[i - 1] - '0';
        int b = p[i] - '0';
        int c = p[i + 1] - '0';
        if ((a < b && b > c) || (a > b && b < c))
            cnt++;
 
    }
    return cnt;
}
    int totalWaviness(int num1, int num2) {
        string s=to_string(num2);
        if(s.size()<3) return 0; //optimization as if num2 is less than 3 digit num1 has to be so wavi 0
int wavi=0;
        for(int i=num1;i<=num2;i++){

            wavi+=countwavi(i);

        }

    return wavi;
        
    }
};