class Solution {
public:
    string strWithout3a3b(int a, int b) {

      
        string res="";
        int la=0,lb=0;
        while(a>0 || b>0){

            if((a>=b && la<2 )||(b>=a && lb==2)){
                res+="a";
                a--;
                la++;
                lb=0;
            }
            else {
                res+="b";
                b--;
                lb++;
                la=0;
            }

        }
        return res;
        
    }
};