class Solution {
public:
    double slv(int i,int j,int k,int n,vector<vector<vector<double>>> &mdp,double &prob){
    if(i<0 || j<0 || i>=n || j>=n){return 0;}
        if(k==0){return 1;}
        
        if(mdp[i][j][k]!=-1){return mdp[i][j][k];}
        
       double up1=slv(i-2,j-1,k-1,n,mdp,prob);
        double up2=slv(i-2,j+1,k-1,n,mdp,prob);
        double dwn1=slv(i+2,j-1,k-1,n,mdp,prob);
        double dwn2=slv(i+2,j+1,k-1,n,mdp,prob);
        double rgt1=slv(j+2,i-1,k-1,n,mdp,prob);
        double rgt2=slv(j+2,i+1,k-1,n,mdp,prob);
        double lft1=slv(j-2,i-1,k-1,n,mdp,prob);
        double lft2=slv(j-2,i+1,k-1,n,mdp,prob);
        return mdp[i][j][k]=(up1+up2+dwn1+dwn2+rgt1+rgt2+lft1+lft2)/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> mdp(n+1,vector<vector<double>> (n+1,vector<double> (k+1,-1)));
        double prob=1;
        return slv(row,column,k,n,mdp,prob);
        // int ans=
        // cout<<ans<<endl;
        // return prob;
    }
};