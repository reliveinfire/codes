#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Interval{
	public:
		int start;
		int end;
		Interval(int s, int e): start(s), end(e){}
};
class Time{
	public:
	int val;
	int isStart;
	Time(int v, int is): val(v), isStart(is){}
	bool operator<(const Time& that) const{
		if (val == that.val){
			if (!isStart && that.isStart)
				return true;
			else 
				return false;
		} else
			return val < that.val;
	}
};
class Solution {
	public:
	int minMeetingRooms(vector<Interval>& intervals){
		vector<Time> times;
		for (Interval i : intervals){
			times.push_back(Time(i.start, 1));
			times.push_back(Time(i.end, 0));
		}
		sort(times.begin(), times.end());
		int count = 0, ans = INT_MIN;
		for (Time t : times){
			if (t.isStart)
				count++;
			else
				count--;
			ans = max(ans,count);
		}
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<Interval> il;
	il.push_back(Interval(0,30));
	il.push_back(Interval(5,10));
	il.push_back(Interval(15,20));
	Solution sol;
	int ret;
	ret = sol.minMeetingRooms(il);
	cout << ret << "\n";


	return 0;
}
