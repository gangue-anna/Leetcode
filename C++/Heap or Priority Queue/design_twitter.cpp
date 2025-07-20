#include <bits/stdc++.h>
using namespace std;

/**
 * Design Twitter: support posting tweets, following/unfollowing users,
 * and retrieving the 10 most recent tweets in a user's news feed.
 * 
 * Approach:
 * - Use a global timestamp `count` that decrements with each tweet.
 *   (more negative means newer tweet)
 * - Store each user's tweets as a list of (time, tweetId) pairs in tweetMap.
 * - Store each user's followees in a set in followMap.
 * - To fetch news feed:
 *   - For the user and all their followees, push their most recent tweet into a min-heap.
 *   - Pop the most recent tweet, add it to result, and push the next tweet from that user if exists.
 *   - Repeat until 10 tweets are collected or heap is empty.
 *
 * Time Complexity:
 * - postTweet: O(1)
 * - follow/unfollow: O(1)
 * - getNewsFeed: O(F log F + 10 log F), where F is number of followees (including self).
 *
 * Space Complexity:
 * - O(U + T), where U is number of users and T is total tweets.
 */

class Twitter {
    int count; // global timestamp counter
    unordered_map<int, vector<pair<int, int>>> tweetMap; // userId → list of (time, tweetId)
    unordered_map<int, unordered_set<int>> followMap;   // userId → set of followees

    // comparator for priority_queue: smallest (most recent) time comes first
    struct cmp {
        bool operator()(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
            return get<0>(a) > get<0>(b);
        }
    };

public:
    Twitter() {
        count = 0;
    }

    void postTweet(int userId, int tweetId) {
        // append (current time, tweetId) to this user's tweet list
        tweetMap[userId].push_back(make_pair(count, tweetId));
        count--; // decrement time
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        // priority_queue to get the most recent tweet at the top
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, cmp> pq;

        // user always follows themselves
        followMap[userId].insert(userId);

        // push most recent tweet of each followee into pq
        for (int followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId) && !tweetMap[followeeId].empty()) {
                int idx = tweetMap[followeeId].size() - 1;
                pair<int, int> lastTweet = tweetMap[followeeId][idx];
                pq.push(make_tuple(lastTweet.first, lastTweet.second, followeeId, idx - 1));
            }
        }

        // collect up to 10 most recent tweets
        while (!pq.empty() && res.size() < 10) {
            tuple<int, int, int, int> top = pq.top();
            pq.pop();

            int time = get<0>(top);
            int tweetId = get<1>(top);
            int followeeId = get<2>(top);
            int idx = get<3>(top);

            res.push_back(tweetId);

            // if this followee has more tweets, push next older one
            if (idx >= 0) {
                pair<int, int> prevTweet = tweetMap[followeeId][idx];
                pq.push(make_tuple(prevTweet.first, prevTweet.second, followeeId, idx - 1));
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) // no explicit self-follow
            followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followMap[followerId].count(followeeId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};

/*
----------------------------------------------
📄 Line-by-Line Syntax Explanation:
----------------------------------------------

#include <bits/stdc++.h>
    → Includes all standard C++ headers (like iostream, vector, map, etc.)

using namespace std;
    → Avoids prefixing std:: everywhere.

class Twitter { ... };
    → Defines the Twitter class.

int count;
    → Integer to act as a global timestamp.

unordered_map<int, vector<pair<int, int>>> tweetMap;
    → Maps userId → vector of (time, tweetId)

unordered_map<int, unordered_set<int>> followMap;
    → Maps userId → set of followees.

struct cmp { bool operator()(...) { return ...; } };
    → Custom comparator for priority_queue to get smallest `time`.

Twitter() { count = 0; }
    → Constructor initializing count to 0.

void postTweet(int userId, int tweetId) { ... }
    → Adds a tweet for userId.

vector<int> getNewsFeed(int userId) { ... }
    → Returns list of up to 10 most recent tweetIds in user's news feed.

priority_queue<tuple<...>, vector<...>, cmp> pq;
    → Min-heap based on time (most recent first).

followMap[userId].insert(userId);
    → Ensures user follows themselves.

pq.push(make_tuple(...));
    → Inserts a tweet into the heap.

tuple<int, int, int, int> top = pq.top();
    → Retrieves most recent tweet from heap.

get<0>(top), get<1>(top), etc.
    → Access elements of the tuple.

res.push_back(tweetId);
    → Adds tweetId to result.

if (idx >= 0) { ... }
    → If user has more tweets, push next one into heap.

void follow(int followerId, int followeeId) { ... }
    → Adds followeeId to followerId’s follow list.

void unfollow(int followerId, int followeeId) { ... }
    → Removes followeeId from followerId’s follow list if exists.

----------------------------------------------
⏱ Time & Space:
- postTweet: O(1)
- follow/unfollow: O(1)
- getNewsFeed: O(F log F + 10 log F)

🧹 Space: O(U + T) for users & tweets.
----------------------------------------------

*/
