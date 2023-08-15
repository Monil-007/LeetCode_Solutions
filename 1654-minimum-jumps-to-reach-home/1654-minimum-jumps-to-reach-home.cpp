class Solution {
public:
    int slv(int i,int cnt,int &a,int &b,int &x,vector<vector<int>> &t,unordered_map<int,int> &f,vector<int> &vis){
        if(i<0 || f[i]==1 || i>6000){return INT_MAX;}
        if(i==x){return 0;}
        if(t[i][cnt]!=-1){return t[i][cnt];}
        if(vis[i]){return INT_MAX;}
        vis[i]=1;
        int forw=slv(i+a,0,a,b,x,t,f,vis);
        if(forw==INT_MAX){forw=INT_MAX;}
        else{forw++;}
        int backw=INT_MAX;
        if(cnt==0){
            backw=slv(i-b,cnt+1,a,b,x,t,f,vis);
            if(backw==INT_MAX){backw=INT_MAX;}
            else{backw++;}    
        }
        vis[i]=0;
        return t[i][cnt]=min(forw,backw);
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int,int> mp;
        for(auto i:forbidden){
            mp[i]=1;
        }
        vector<vector<int>> t(6001,vector<int> (2,-1));
        vector<int> vis(6001);
        int x1=slv(0,0,a,b,x,t,mp,vis);
        if(x1==INT_MAX){return -1;}
        return x1;
    }
};