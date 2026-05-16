class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        //GREEDY

    //    sort(coins.begin(),coins.end(),greater<int>()); //sort in decending order 
    //    //denominations is a face val like 2 ,3 ,4 totald deno=3
    //    int total=0;
    //    for(int i=0;i<coins.size() && amount>0;i++){
    //     int count=amount/coins[i]; //am=10 coin[i]=2 count=5 ...soln 2 che 5 coins
    //     if(count>0){
    //         total+=count;
    //         amount-=count*coins[i];



    //     }

    //    }

    //    if(amount==0) return total;
    //    return -1;


    //Dp
     vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for(int i = 1; i <= amount; i++) {

            for(int coin : coins) {

                if(i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];


        
    }
};