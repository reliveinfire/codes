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
	bool operator<(const Interval& that){
		return start > that.start;
	}
};

bool compare(const Interval& a, const Interval& b){
	return a.start < b.start;
};
class Solution {
	public:
	bool canAttendMeetings(vector<Interval>& intervals){
		//sort(intervals.begin(), intervals.end(), compare);
		sort(intervals.begin(), intervals.end());
		for (Interval i : intervals){
			cout << i.start <<":"<<i.end <<endl;
		}
		for (int i = 0 ; i + 1 < intervals.size() ; i++){
			if (intervals[i].end > intervals[i+1].start)
				return false;
		}
		return true;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<Interval> times;
	times.push_back(Interval(5,10));
	times.push_back(Interval(0,30));
	times.push_back(Interval(15,20));
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.canAttendMeetings(times);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
