class Solution {
public:
    bool slv(int i){
        if(i==1){return true;}
        if(i==0){return false;}
        if(i%3!=0){return false;}
        return slv(i/3);
    }
    bool isPowerOfThree(int n) {
        if(n<0){return false;}
        return slv(n);
    }
};