class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){return false;}
        if((n&(n-1))==0){return true;}
        else{return false;}
    }
};