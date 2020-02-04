#define F first
#define S second

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0){return 0;}
        if(n==1){return nums[0];}
        vector<pair<int,int> > dp(n+1);
        dp[n].F=0;
        dp[n].S=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>=0){
                dp[i].F=max(nums[i],(dp[i+1].F)*nums[i]);
                dp[i].S=(dp[i+1].S)*nums[i];
            }else{
                dp[i].S=min(nums[i],(dp[i+1].F)*nums[i]);
                dp[i].F=(dp[i+1].S)*nums[i];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i].F);
        }
        return ans;
    }
};
