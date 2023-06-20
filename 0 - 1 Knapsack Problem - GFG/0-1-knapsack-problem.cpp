//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return memoisation(W,n-1,wt,val,dp);
        return recursion(W,n-1,wt,val);
    }
private:
    int recursion(int leftW ,int curIdx , int * wt , int * val){
        if(curIdx==-1 || leftW == 0){
            return 0;
        }
        int take = 0 ;
        if(leftW >= wt[curIdx]){
            take = recursion(leftW - wt[curIdx] , curIdx - 1 , wt , val) + val[curIdx];
        }
        int notTake = recursion(leftW , curIdx - 1 , wt , val);
        return max(take , notTake);
    }
    int memoisation(int leftW ,int curIdx , int * wt , int * val,vector<vector<int>> &dp){
        if(curIdx==-1 || leftW == 0){
            return 0;
        }
        if(dp[curIdx][leftW] != -1){
            return dp[curIdx][leftW];
        }
        int take = 0 ;
        if(leftW >= wt[curIdx]){
            take = memoisation(leftW - wt[curIdx] , curIdx - 1 , wt , val,dp) + val[curIdx];
        }
        int notTake = memoisation(leftW , curIdx - 1 , wt , val,dp);
        return dp[curIdx][leftW] = max(take , notTake);
    }
};


//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends