//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int> t;
        for(int i=0;i<N;i++){
            t.push_back(candies[i]);
        }
        sort(t.begin(),t.end());
        int i=N-1,j=0,ans1=0;
        while(i>=j){
            ans1+=t[i--];
            j+=K;
        }
        i=0;j=N-1;int ans2=0;
        while(j>=i){
            ans2+=t[i++];
            j-=K;
        }
        t.clear();
        t.push_back(ans2);t.push_back(ans1);
        return t;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends