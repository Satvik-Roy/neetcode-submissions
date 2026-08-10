class Twitter {
private:
    int time;
    
    unordered_map<int, unordered_set<int>> follows;
    
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        
        follows[userId].insert(userId);
        
        for (int followeeId : follows[userId]) {
            auto& tweetList = tweets[followeeId];
            
            int count = 0;
            for (int i = tweetList.size() - 1; i >= 0 && count < 10; i--) {
                maxHeap.push(tweetList[i]);
                count++;
            }
        }
        
        vector<int> res;
        while (!maxHeap.empty() && res.size() < 10) {
            res.push_back(maxHeap.top().second); // .second is the tweetId
            maxHeap.pop();
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};