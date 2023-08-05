class Solution {
public:
    int accountBalanceAfterPurchase(int pA) {
        int dv=pA/10;
        if(abs(10*dv-pA)<abs(10*(dv+1)-pA)){
            return 100-10*dv;
        }
        //if(10*dv==pA){return 100-10*dv;}
        return 100-(10*(dv+1));
    }
};