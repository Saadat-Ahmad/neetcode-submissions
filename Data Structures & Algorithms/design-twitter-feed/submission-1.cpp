class Twitter {
private:
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> usrPosts;
    unordered_map<int, unordered_set<int>> usrFollows;
    unordered_set<int> accounts;
    vector<int> arr;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        usrPosts[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        usrFollows[userId].insert(userId);
        accounts = usrFollows[userId];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        arr.clear();
        for(const auto& account : accounts){
            for(const auto& post : usrPosts[account]){
                minH.push(post);
                if(minH.size() > 10) minH.pop();
            }
        }
        while(minH.size() > 0){
            arr.push_back(minH.top().second);
            minH.pop(); 
        }
        reverse(arr.begin(), arr.end());
        return arr;

    }
    
    void follow(int followerId, int followeeId) {
        usrFollows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        usrFollows[followerId].erase(followeeId);    
    }
};
