class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> S;
        int n=heights.size();
        int ans=0;
        int i;
        for(i=0;i<n;i++){
            while(!S.empty()&&heights[S.top()]>heights[i]){
                int t=S.top();
                S.pop();
                int x=-1;
                int y=i;
                if(!S.empty()){x=S.top();}
                ans=max(ans,(heights[t]*(y-x-1)));
            }
            S.push(i);
        }
        while(!S.empty()){
                int t=S.top();
                S.pop();
                int x=-1;
                int y=i;
                if(!S.empty()){x=S.top();}
                ans=max(ans,(heights[t]*(y-x-1)));
            }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0){
            return 0;
        }
        int m=matrix[0].size();
        vector<vector<int> >heights(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(matrix[0][i]=='1'){
                heights[0][i]=1;
            }else{
                heights[0][i]=0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    heights[i][j]=1;
                    heights[i][j]+=heights[i-1][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,largestRectangleArea(heights[i]));
        }return ans;
    }
};
