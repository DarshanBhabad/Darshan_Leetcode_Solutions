class Solution {
public:
    long long countCommas(long long n) {
        
    //     int cnt=0;
    //     long long k=n;
    //     while(k!=0){
    //          cnt++;
    //          k/=10;
    //     }
    //     if(cnt<4) return 0;
    //     else if(cnt<7) return n-999;
    //     else if(cnt<10) return 1e6-1000+2*(n-1e6+1);
    // return 3*(n-1e10)+1e6-1000+2*(n-1e6+1);

    //The key insight: a number with d digits has exactly ⌊(d-1)/3⌋ commas
    long long total = 0;
        long long low = 1;      // smallest d-digit number
        long long high = 9;     // largest d-digit number
        int d = 1;

        while (low <= n) {
            long long upper = min(n, high);
            long long cnt = upper - low + 1;
            total += cnt * ((long long)(d - 1) / 3);  // commas per number with d digits  //numbers * commas

            low = high + 1;
            high = high * 10 + 9;   // e.g. 9 -> 99 -> 999 -> ...
            d++;
        }

        return total;
    }
};