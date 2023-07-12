class Solution {
public:
    
string printLCS(string s1,string s2){
    int n=s1.length(),m=s2.length();
    vector<vector<int>> t(n+1,vector<int>(m+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
            else{
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=t[i-1][j-1]+1;
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
    }
    string s="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s+=s1[i-1];
            i--;j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(s.begin(),s.end());
    return s;
    
}
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs=printLCS(str1,str2);
        int k1=0,i=0,j=0,n=str1.length(),m=str2.length(),k=lcs.length();
        string ans=""; 
        while(i<n && j<m){
            if(str1[i]==lcs[k1]){
                while(j<m && str2[j]!=lcs[k1]){
                    ans+=str2[j++];
                }
                ans+=lcs[k1++];
                i++;j++;
            }
            else if(str2[j]==lcs[k1]){
                while(i<n && str1[i]!=lcs[k1]){
                    ans+=str1[i++];
                }
                ans+=lcs[k1++];
                i++;j++;
            }
            else{
                ans+=str1[i++];
                ans+=str2[j++];
            }
            
        }
        while(i<n){ans+=str1[i++];}
        while(j<m){ans+=str2[j++];}

        return ans;
    }
};