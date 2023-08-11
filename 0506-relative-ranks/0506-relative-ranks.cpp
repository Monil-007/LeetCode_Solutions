class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
       priority_queue<pair<int,int>> pq;
       for(int i=0;i<score.size();i++){
           pq.push({score[i],i});
       } 
       vector<string> res(score.size(),"");
       int cn=1;
        while(pq.size()){
            if(cn==1){res[pq.top().second]="Gold Medal";}
            else if(cn==2){res[pq.top().second]="Silver Medal";}
            else if(cn==3){res[pq.top().second]="Bronze Medal";}
            else{
                res[pq.top().second]=to_string(cn);
            }
            pq.pop();
            cn++;
        }
        return res;
    }
};