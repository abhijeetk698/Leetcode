class Solution {
public:
    // The Underlying concept is that for every bar i , we have to search for the leftmost bar with height greater than i th bar
    // and rightmost bar with height greater than the i th bar to find the max rectangle formed by the ith bar
    // we can do this for all bar and return the maximum area
    
    int largestRectangleArea(vector<int>& heights) {
        // to find the leftmost bar with height greater than the bar i we will use stack
        stack<int> S;
        heights.push_back(0);
        int n=heights.size();
        int ans=0;
        int i;
        // Filling of Stack
        // *if Stack is empty we will insert the index of the bar 
        // *else if the height of current bar is greater than the height of the bar associated with the height[Stack->top]
        //  we will push the index
        // *we do this because with this we will be sure that stack will contain values arranged in assending order 
        
        // Popping of Stack
        // if the height of current bar, say with index i, is less than height[Stack->top] we will be sure that
        // for Stack->top , 
        //  rightmost greater bar will have index of i-1 (say x=i);
        //  leftmost greater bar will have index of Stack[second element from top]-1(say y=Stack[second element from top])
        //  area associated will be (y-x-1)*heights[Stack->top]
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
        return ans;
    }
};
