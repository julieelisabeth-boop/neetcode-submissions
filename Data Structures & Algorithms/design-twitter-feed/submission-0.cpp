class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tid++;
        tweets[userId].push_back({tid, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> heap;            // {tid, tweetId}, største tid øverst

    for (auto& t : tweets[userId])                 // egne tweets
        heap.push(t);


    for (int f : folger[userId])                   // tweets fra dem man følger
        for (auto& t : tweets[f])
            heap.push({t.first, t.second});   // {tid, tweetId}

    vector<int> feed;
    while (!heap.empty() && feed.size() < 10) {    // tag de 10 nyeste ud
        feed.push_back(heap.top().second);         // .second = tweetId
        heap.pop();
    }
    return feed;
}
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
        folger[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        folger[followerId].erase(followeeId);
    }
private:
    int tid = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;// user id: {tid, tweet id}
    unordered_map<int, unordered_set<int>> folger; // user id: hvem de følger (set fordi ingen dubletter)

};
