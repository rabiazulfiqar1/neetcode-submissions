class Twitter {
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    int cnt;
public:
    Twitter() {
        cnt = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        cnt+=1;
        tweetMap[userId].push_back({cnt, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> tweets;
        priority_queue<vector<int>> pq;
        followMap[userId].insert(userId);
        for (auto followeeId: followMap[userId]) {
            if (tweetMap[followeeId].size() > 0) {
                int idx = tweetMap[followeeId].size()-1; //most recent tweet
                pair<int, int> p = tweetMap[followeeId][idx];//cnt, tweetId
                pq.push({p.first, p.second, followeeId, idx-1});
            }
        }
        
        while (!pq.empty() && tweets.size() < 10) {
            auto curr = pq.top();
            pq.pop();

            int tweetId = curr[1];
            int followeeId = curr[2];
            int idx = curr[3];

            tweets.push_back(tweetId);

            if (idx >= 0) {
                auto p = tweetMap[followeeId][idx];
                pq.push({p.first, p.second, followeeId, idx - 1});
            }
        }
        return tweets;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
