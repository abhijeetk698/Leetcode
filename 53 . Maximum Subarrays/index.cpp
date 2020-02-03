class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // curr_sum will store the current subarray sum the element under consideration is 
        // part of
        int curr_sum=0;
        int total_max=INT_MIN; // max sum obtained so far 
        int n=nums.size();
        // The underlying concept is that if at any time adding a element into curr_sum makes it negetive then there is 
        // no point of further considering the subbarray curr_sum takes the value of, we can 
        // start from the current element making curr_sum =0 
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            total_max=max(curr_sum,total_max);
            if(curr_sum<0){
                curr_sum=0;
            }
        }
        return total_max;
    }
};
