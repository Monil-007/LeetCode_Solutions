class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum=0;
        int i=0;
        while(i<costs.size()){
            sum+=costs[i];
            if(sum>coins){return i;}
            i++;
            //if(sum==coins){return i;}
            //sum+=costs[i++];
        }
       
        return i;
    }
};