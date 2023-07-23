class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x2=tomatoSlices-2*cheeseSlices;
        vector<int> res;
        if(x2>=0 && x2%2==0){
            int jumbo=x2/2,sml=cheeseSlices-jumbo;
            if(jumbo<0 || sml<0){return res;}
            res.push_back(jumbo);res.push_back(sml);
            return res;
        }
        return res;
    }
};