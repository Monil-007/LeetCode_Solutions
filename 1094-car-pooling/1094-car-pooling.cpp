class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it:trips){
            pq.push({it[1],it[0]});
            pq.push({it[2],-it[0]});
        }
        int currCap=0;
        while(pq.size()){
            currCap+=pq.top().second;
            pq.pop();
            if(currCap>capacity){return false;}
        }
        return true;
    }
};