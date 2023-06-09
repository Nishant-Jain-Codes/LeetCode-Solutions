//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s) {
        //code here
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++)
        {
            for (int start = 0; start <= n - len; start++)
            {
                int end = start + len - 1;

                if (s[start] == s[end])
                {
                    dp[start][end] = 2 + dp[start + 1][end - 1];
                }
                else
                {
                    dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends