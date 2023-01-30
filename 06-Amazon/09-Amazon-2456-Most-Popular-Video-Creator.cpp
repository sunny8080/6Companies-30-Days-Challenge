#include<bits/stdc++.h>
using namespace std;

// #define ll                 long long
// #define int                long long
#define mod                1000000007
#define inf                1e18
// const ll N = 1e5 + 5;
void fastIO() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


// Link :- https://leetcode.com/problems/most-popular-video-creator/description/


class Solution {
    typedef long long ll;
public:
    vector<vector<string>> mostPopularCreator1(vector<string>& creat, vector<string>& ids, vector<int>& views) {
        unordered_map<string, ll> popu;
        unordered_map<string, vector<ll>> mpp;
        unordered_map<string, ll> popCreat;
        vector<vector<string>> ans;
        ll maxiPop = INT_MIN, n = creat.size();

        for (ll i = 0; i < n; i++) {
            popu[creat[i]] += views[i];
            mpp[creat[i]].push_back(i);

            if (maxiPop < popu[creat[i]]) {
                maxiPop = popu[creat[i]];
                popCreat.clear();
                popCreat[creat[i]] = 1;
            } else if (maxiPop == popu[creat[i]]) {
                popCreat[creat[i]] = 1;
            }
        }


        for (auto x : popCreat) {
            string cur = x.first;
            ll maxiView = INT_MIN;
            string maxiId = "zzzzz";

            for (auto i : mpp[cur]) {
                if (creat[i] == cur) {
                    if (maxiView < views[i]) maxiView = views[i], maxiId = ids[i];
                    else if (maxiView == views[i] && maxiId > ids[i]) maxiId = ids[i];
                }
            }
            ans.push_back({ cur, maxiId });
        }

        return ans;
    }




    vector<vector<string>> mostPopularCreator(vector<string>& creat, vector<string>& ids, vector<int>& views) {
        unordered_map<string, ll> viewCnt, popular; // {creator_name, total_views} , {creator_name, creator_ind}
        vector< vector<string>> ans;
        ll maxiView = INT_MIN;
        for (int i = 0; i < creat.size(); i++) {
            viewCnt[creat[i]] += views[i];
            maxiView = max(maxiView, viewCnt[creat[i]]);


            // it.second must point to ind of id having maximum view and smallest lexicographically id
            auto it = popular.find(creat[i]);
            if (it == popular.end()) {
                popular[creat[i]] = i;
            } else if (views[i] > views[it->second]) {
                it->second = i;
            } else if (views[i] == views[it->second] && ids[i] < ids[it->second]) {
                it->second = i;
            }
        }

        for (auto it : viewCnt) {
            if (it.second == maxiView) {
                ans.push_back({ it.first, ids[popular[it.first]] });
            }
        }
        return ans;
    }
};



int32_t main() {
    fastIO();
    // Solution sol;



    return 0;
}




