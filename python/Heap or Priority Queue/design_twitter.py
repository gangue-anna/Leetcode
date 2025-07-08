from typing import List
from collections import defaultdict
import heapq

class Twitter:
    def __init__(self):
        """
        Initialize data structures:
        - tweetMap: maps userId to a list of [timestamp, tweetId]
        - followMap: maps userId to a set of followeeIds
        - count: global timestamp counter (decremented for each new tweet)
        Time Complexity: O(1)
        Space Complexity: O(U + T), where U is number of users and T is number of tweets
        """
        self.count = 0
        self.tweetMap = defaultdict(list)
        self.followMap = defaultdict(set)

    def postTweet(self, userId: int, tweetId: int) -> None:
        """
        Post a new tweet for userId.
        Time Complexity: O(1)
        Space Complexity: O(1) per tweet
        """
        self.tweetMap[userId].append([self.count, tweetId]) 
        self.count -= 1

    def getNewsFeed(self, userId: int) -> List[int]:
        """
        Retrieve the 10 most recent tweetIds in the user's news feed.
        Time Complexity: O(F log F + 10 log F), where F is the number of followees (heap operations)
        Space Complexity: O(F)
        """
        res = []
        minHeap = []
        self.followMap[userId].add(userId)
        for followeeId in self.followMap[userId]:
            if followeeId in self.tweetMap:
                index = len(self.tweetMap[followeeId]) - 1
                count, tweetId = self.tweetMap[followeeId][index]
                minHeap.append([count, tweetId, followeeId, index - 1])
        heapq.heapify(minHeap)
        while minHeap and len(res) < 10:
            count, tweetId, followeeId, index = heapq.heappop(minHeap)
            res.append(tweetId)
            if index >=0:
                count, tweetId = self.tweetMap[followeeId][index]
                heapq.heappush(minHeap, [count, tweetId, followeeId, index - 1])
        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        """
        Follower follows a followee.
        Time Complexity: O(1)
        """
        self.followMap[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        """
        Follower unfollows a followee.
        Time Complexity: O(1)
        """
        if followeeId in self.followMap[followerId]:
            self.followMap[followerId].remove(followeeId)

# -------------------
# Test Cases
# -------------------
def test_twitter():
    twitter = Twitter()
    # User 1 posts a tweet
    twitter.postTweet(1, 5)
    assert twitter.getNewsFeed(1) == [5]
    # User 1 follows user 2
    twitter.follow(1, 2)
    # User 2 posts a tweet
    twitter.postTweet(2, 6)
    # User 1's news feed should return [6, 5]
    assert twitter.getNewsFeed(1) == [6, 5]
    # User 1 unfollows user 2
    twitter.unfollow(1, 2)
    # User 1's news feed should return [5]
    assert twitter.getNewsFeed(1) == [5]
    # User 2 posts another tweet
    twitter.postTweet(2, 7)
    # User 1's news feed should still return [5]
    assert twitter.getNewsFeed(1) == [5]
    # User 1 follows user 2 again
    twitter.follow(1, 2)
    # User 1's news feed should return [7, 5]
    assert twitter.getNewsFeed(1) == [7, 5]
    print("All test cases passed!")

if __name__ == "__main__":
    test_twitter()
