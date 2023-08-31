//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int celeb = -1;
        for(int i=0;i<n;i++){
            bool knows = false;
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                if(M[i][j])
                    knows = true;
            }
            if(!knows)
                {
                    celeb = i;
                    break;
                }
        }
        if(celeb==-1)
            return -1;
        bool allKnow = true;
        for(int j=0;j<n;j++){
            if(j==celeb)
                continue;
            if(M[j][celeb]!=1)
                {
                    return -1;
                }
        }
        return celeb;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends