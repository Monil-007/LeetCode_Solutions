class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cntOdd=0,cntEv=0;
        for(int i=0;i<position.size();i++){
            if(position[i]%2==0){cntEv++;}
            else{cntOdd++;}
        }
        return min(cntOdd,cntEv);
    }
};