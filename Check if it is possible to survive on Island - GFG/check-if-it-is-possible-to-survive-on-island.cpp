//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int cntSun=S/7;
        int days=S-cntSun;
        int ans=0;
        if((S*M)%N==0){
            ans=(S*M)/N;
        }
        else{
            ans=(S*M)/N+1;
            //return ((S*M)/(N))+1;
        }
        if(ans<=days){return ans;}
        return -1;
        //return ceil((S*M)/N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends