class Twitter {
public:
    int tmr=0;
    vector<vector<pair<int,int>>> users;
    vector<vector<int>> mat;
    Twitter() {
        users.resize(501);
        mat.resize(501,vector<int> (501,0));
        tmr=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tmr++;
        users[userId].push_back({tmr,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto it:users[userId]){
            pq.push(it);
        }
        for(int j=0;j<501;j++){
            if(mat[userId][j]){
                for(auto it:users[j]){
                    pq.push(it);
                }
            }
        }
        vector<int> ans;
        int cnt=10;
        while(cnt-- && pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mat[followerId][followeeId]=1;
    }
    
    void unfollow(int followerId, int followeeId) {
        mat[followerId][followeeId]=0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */