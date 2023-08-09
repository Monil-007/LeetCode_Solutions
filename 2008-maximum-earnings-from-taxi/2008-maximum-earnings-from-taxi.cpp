class Solution {
public:
    long long slv(int ind,vector<vector<int>> &rides,vector<long long> &t){
        if(ind>=rides.size()){return 0;}
        if(t[ind]!=-1){return t[ind];}
        int start=ind+1,end=rides.size()-1,mid,next=end+1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(rides[mid][0]>=rides[ind][1]){
                next=mid;
                end=mid-1;
            }
            else{start=mid+1;}
        }
        long long notTake=slv(ind+1,rides,t);
        long long take=rides[ind][1]-rides[ind][0]+rides[ind][2]+slv(next,rides,t);
        return t[ind]=max(notTake,take);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        // long long fair=0,drop=LLONG_MIN,start=LLONG_MIN;
        // for(auto i:rides){
        //     if(i[1]>=drop){drop=i[1];}
        //     if(i[0]>=start){start=i[0];}
        //     fair+=i[2];
        // }
        vector<long long> t(rides.size(),-1);
        // for(int ind=0;i<rides.size();i++){
        //     int notTake=t[rides[]i-1][rides]
        // }
        return slv(0,rides,t);
    }
};

