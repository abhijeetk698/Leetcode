class Solution {
public:
    string longestPalindrome(string s) {
        if(s==""){
            return "";
        }
        int n=s.size();
        bool dp[n][n];    // if dp[i][j] is true than substring s[i]-s[j] is a palindrome 
        memset(dp,false,sizeof(dp));  // initializing the dp matrix with false value
        for(int i=0;i<n;i++){ 
            dp[i][i]=true;
        }
        // used for storing the answer
        int x=0; // starting index of the answer
        int y=0; // ending index of the answer
        for(int k=1;k<n;k++){ // denotes the length of the substring under consideration
            for(int i=0;i<n-k;i++){
                int start=i;   // starting point of the substring under consideration 
                int end=i+k;   // ending point of the string under consideration  
                if(s[start]==s[end]){  
                    if(end==start+1){ // if there are only two elements and both are same
                        dp[start][end]=true;
                    }else{     // if starting element of the substring is same as the   
                            //ending index of the substring then if s[start+1]-s[end-1]   
                    dp[start][end]=dp[start+1][end-1];// is also a palindrome only then 
                    }// s[start][end] is a substring                     
                    if(dp[start][end]){
                        if((end-start)>(y-x)){  // Storing the answer if the length of the
                            y=end;      // palindromic substring is bigger than the 
                            x=start;    // previous found answer
                        }
                    }
                }
            }
        }
    string ans="";
    for(int i=x;i<=y;i++){ // getting the substring s[x]
        ans.push_back(s[i]);
    }
    return ans;
}
};
