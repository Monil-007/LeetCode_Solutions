class Solution {
public:
    int mod=1e9+7;
    int slv(int ind,int st,int en,int fuel,vector<int> &locations,vector<vector<int>> &mdp){
        // if(ind==locations.size()){return 0;}
        if(fuel<0){return 0;}
        // if(en==ind && fuel>=0){
        //     return 1;
        // }
        if(mdp[ind][fuel]!=-1){return mdp[ind][fuel];}
        long long int take=0;
        for(int j=0;j<locations.size();j++){
            if(j==ind){continue;}
            // if(fuel-abs(loactions[ind]-locations[j])>=0){
                fuel-=abs(locations[ind]-locations[j]);
                if(j==en && fuel>=0){take++;}
                take+=slv(j,st,en,fuel,locations,mdp);
                fuel+=abs(locations[ind]-locations[j]);
                // if(take){
                //     int take=1+slv(j,st,en,fuel-abs(loactions[ind]-locations[j]),locations);
                // }
            //}
        }
        return mdp[ind][fuel]=take%mod;

    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>> mdp(n,vector<int> (fuel+1,-1));
        int res=slv(start,start,finish,fuel,locations,mdp);
        if(start==finish){return res+1;}
        return res;
    }
};