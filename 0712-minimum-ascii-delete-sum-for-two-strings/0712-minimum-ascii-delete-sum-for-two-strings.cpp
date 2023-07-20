class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // insted of finding LCS find Subsequence with max ASKII sum.
        int maxASCIIsum = LongestCommonSubSeqTebu(s1, s2);
        // just find the cost of deleting all other chars then in maxASCIIsum
        int ASCIIs1 = 0;
        int ASCIIs2 = 0;
        for(auto i : s1)
            ASCIIs1 += (int)i;
        for(auto i : s2)
            ASCIIs2 += (int)i;
        
        return ASCIIs1 + ASCIIs2 - (2 * maxASCIIsum);
    }
    
    int LongestCommonSubSeqTebu(string a, string b) {
        vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1));

        // inn
        for(int i = 0; i < dp.size(); i++)  
            dp[i][0] = 0; 
        for(int i = 0; i <= b.size(); i++)      
            dp[0][i] = 0;


        // other table
        for(int i = 1; i <= a.size() ; i++){
            for(int j = 1; j <= b.size(); j++) {
                if(a[i - 1] == b[j - 1])
                    dp[i][j] = (int)a[i-1] + dp[i-1][j-1];    // only modification is in this line, in LCS code we have 1 + dp[i-1][j-1];;
                else    
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp.back().back();

    }   
    
    
    
};