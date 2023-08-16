class Solution {
public:
    vector<int> sve(){
        int ub=pow(2,31)-1;
        vector<int> prm;
        prm.push_back(2);
        for(int i=3;i<ub;i+=2){
            bool fg=false;
            for(int j=2;j*j<i;j++){
                if(i%j==0){fg=true;break;}
            }
            if(!fg){prm.push_back(i);}
        }
        return prm;
    }
    bool isUgly(int n) {
        vector<int> sv;
        //sv=sve();
        if(n<=0){return false;}
        while(n>1){
            if(n%2==0){n/=2;}
            else if(n%3==0){n/=3;}
            else if(n%5==0){n/=5;}
            else{
                return false;
            }
        }
        return true;
        // while(n%3==0){
        //     n/=3;
        // }
        // while(n%5==0){
        //     n/=5;
        // }
        // if(n)
    }
};