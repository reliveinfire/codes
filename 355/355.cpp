#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
		time = 0;
    }
    void postTweet(int userId, int tweetId) {
    		auto li = twits[userId];
		li.insert(li.begin(), pair<int,int>(tweetId, time));
		if (li.size()>10)
			li.pop_back();
		twits[userId] = li;
		time++;
		return;
    }
    vector<int> getNewsFeed(int userId) {
    	vector<int> res;
    	priority_queue<pair<int,int>, vector<pair<int,int>>, compare> qu;
		auto li = twits[userId];
		for (auto iter = li.begin() ; iter != li.end() ; iter++)
			qu.push(pair<int,int>(iter->first, iter->second));
		for (auto fo = wefollow[userId].begin() ; fo != wefollow[userId].end() ; fo++){
			li = twits[*fo];
			for (auto iter = li.begin() ; iter != li.end() ; iter++){
				qu.push(pair<int,int>(iter->first, iter->second));
				if (qu.size() > 10)
					qu.pop();
			}
		}
		while(!qu.empty()){
			//cout << "qu pop:" << qu.top().first <<"  time:"<<qu.top().second<<endl;
			res.push_back(qu.top().first);
			qu.pop();
		}
		reverse(res.begin(), res.end());
		return res;
    }

    void follow(int followerId, int followeeId) {
		if (followerId == followeeId)
			return;
		wefollow[followerId].insert(followeeId);
		return;
    }

    void unfollow(int followerId, int followeeId) {
		wefollow[followerId].erase(followeeId);
		return;
    }
private:
	int time;
	struct compare {
		bool operator()(const pair<int,int>& a, const pair<int,int>& b) const{
			return a.second > b.second;
		}
	};
	unordered_map<int, unordered_set<int>> wefollow;
	unordered_map<int, list<pair<int,int>>> twits; // userId,   List: twId, time
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Twitter tt;
	tt.postTweet(1,5);
	tt.postTweet(1,3);
	auto ret_vec = tt.getNewsFeed(1);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
