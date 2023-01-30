#include<bits/stdc++.h>
using namespace std;

#define ll                 long long
// #define int                long long
#define mod                1000000007
#define inf                1e18
const ll N = 1e5 + 5;
void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}



// Link :- https://leetcode.com/problems/tweet-counts-per-frequency/description/


class TweetCounts {
    map<string, multiset<int>> mpp;
    map<string, int> inS = { {"minute", 60 - 1}, {"hour", 3600 - 1}, {"day", 86400 - 1} };;
public:
    TweetCounts() {}

    void recordTweet(string tweetName, int time) {
        mpp[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tName, int startTime, int endTime) {
        vector<int> ans;
        int s = startTime, e = min(s + inS[freq], endTime);
        auto it = mpp[tName].lower_bound(s);
        while (s <= endTime) {
            int cnt = 0;
            // cout<<s<<" "<<e<<" ";
            while (it != mpp[tName].end() && *it <= e) it++, cnt++;
            ans.push_back(cnt);
            s = e + 1;
            e = min(s + inS[freq], endTime);
        }
        return ans;
    }
};









class TweetCounts1 {
    map<string, vector<int>> mpp;
    map<string, int> inS = { {"minute", 60}, {"hour", 3600}, {"day", 86400} };;
public:
    TweetCounts1() {}

    void recordTweet(string tweetName, int time) {
        mpp[tweetName].push_back(time);
    }

    vector<int> getTweetCountsPerFrequency(string fr, string tN, int sT, int eT) {
        vector<int> ans;
        for (int i = 0; i <= (eT - sT) / inS[fr]; i++) ans.push_back(0);

        for (auto t : mpp[tN]) {
            if (t >= sT && t <= eT) {
                int ind = (t - sT) / inS[fr];
                ans[ind]++;
            }
        }
        return ans;
    }
};


/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */


int32_t main() {
    fastIO();
    // Solution sol;
    
    
    
    return 0;
}
    



