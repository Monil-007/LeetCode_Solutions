class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:nums){
            if(i){pq.push(i);}
        }
        int totSub=0;
        while(pq.size()){
            if(pq.top()-totSub!=0){
                totSub+=pq.top()-totSub;
                cnt++;
            }
            pq.pop();
        }
        return cnt;
    }
};