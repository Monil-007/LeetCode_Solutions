class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
       vector<int> lft(n,1);
       vector<int> rgt(n,1);
       
       for(int i=1;i<n;i++){
           if(r[i-1]<r[i]){
               lft[i]+=lft[i-1];
           }
           else{
               lft[i]=1;
           }
       } 
       for(int i=n-2;i>=0;i--){
           if(r[i]>r[i+1]){
               rgt[i]+=rgt[i+1];
           }
           else{
               rgt[i]=1;
           }
       }
       int rs=0;
       for(int i=0;i<n;i++){
           rs+=max(lft[i],rgt[i]);
       }
       return rs;
    }
};