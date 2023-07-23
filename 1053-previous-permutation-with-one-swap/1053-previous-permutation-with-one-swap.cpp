class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int i,n=arr.size();
        for(i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){break;}
        }
        if(i<0){return arr;}
        int j;
        for(j=n-1;j>=0;j--){
            if(arr[j]<arr[i] && arr[j]!=arr[j-1]){
                break;
            }
        }
        swap(arr[i],arr[j]);
        return arr;
    }
};