class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int cnt[10] = {0};

        for(int i = 0; i < digits.size(); i++) {
            cnt[digits[i]]++;
        }

        int ans = 0;

        // Last digit must be even
        for(int last = 0; last <= 8; last += 2) {

            if(cnt[last] == 0)
                continue;

            // Use one copy of last digit
            cnt[last]--;

            // Choose first digit
            for(int first = 1; first <= 9; first++) {//o0 not considerd as start

                if(cnt[first] == 0)
                    continue;

                cnt[first]--;

                // Choose middle digit
                for(int mid = 0; mid <= 9; mid++) {

                    if(cnt[mid] > 0)
                        ans++; //number is forming
                }

                // Put first digit back
                cnt[first]++;
            }

            // Put last digit back
            cnt[last]++;
        }

        return ans;
    }
};