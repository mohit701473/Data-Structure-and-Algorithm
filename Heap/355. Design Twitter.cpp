// LeetCode -> 355. Design Twitter
https://leetcode.com/problems/design-twitter/description/



class Twitter {
public:
    vector<vector<pair<int, int>>> user_tweet;
    vector<unordered_set<int>> user_following;
    int time;

    Twitter() {
        time = 0;
        user_tweet = vector<vector<pair<int, int>>>(501);
        user_following = vector<unordered_set<int>>(501, unordered_set<int>());
        for(int i = 1 ; i < 501; i++) {
            user_following[i].insert(i);
        }
    }
    
    void postTweet(int userId, int tweetId) {
        user_tweet[userId].push_back({tweetId, time++});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto user: user_following[userId]) {
            int size = user_tweet[user].size();
            int i = max(0, size - 10);
            
            while(i < size) {
                int tweetId = user_tweet[user][i].first;
                int t = user_tweet[user][i].second;
                //cout << tweetId << " -> " << t << endl;
                if(pq.size() < 10){
                    pq.push({t, tweetId});
                } else if(pq.top().first < t) {
                    pq.pop();
                    pq.push({t, tweetId});
                }

                i++;
            }
        }
        //cout << endl;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        user_following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(user_following[followerId].find(followeeId) == user_following[followerId].end())
            return;
        
        user_following[followerId].erase(followeeId);
    }
};






class Twitter {
    private:

    unordered_map<int, unordered_map<int,int>>follows;
    vector<pair<int,int>>post;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        post.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;
        int count=0;

        for(int i=post.size()-1; i>=0 && count<10 ;i--)
        {
            if(post[i].first==userId || follows[userId][post[i].first])
            {
                feed.push_back(post[i].second);
                count++;
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId]=1;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId][followeeId]=0;
    }
};