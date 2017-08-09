#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
/**
 *  * Definition for an interval.
 *  * struct Interval {
 *  *     int start;
 *  *     int end;
 *  *     Interval() : start(0), end(0) {}
 *  *     Interval(int s, int e) : start(s), end(e) {}
 *  * };
 *  */
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool interval_compare(const Interval& a, const Interval& b)
{
	if (a.start < b.start)
		return true;
	else
		return false;
}

class Solution {
	public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		int ret = 0;
		if (intervals.empty())
			return 0;
		sort(intervals.begin(), intervals.end(), interval_compare);
		Interval curr = intervals[0];
		// check curr and all next intervals
		for (int i = 1 ; i < intervals.size() ; i++) {
			if (curr.start == intervals[i].start ||
					intervals[i].start < curr.end) {
				// overlap
				ret++;
				if (curr.end > intervals[i].end){
					curr = intervals[i];
				}
			} else {
				curr = intervals[i];
			}
		}
		return ret;
	}
};
int main()
{
	int ret;

	vector<Interval> data;

	int test[4][2]= { {1,2},
			 {2,3},
			 {3,4},
			 {1,3}
			 };
	for (int i = 0 ; i < 4 ; i++) {
		Interval tmp(test[i][0], test[i][1]);
		data.push_back(tmp);
	}

	Solution sol;
	cout << sol.eraseOverlapIntervals(data) << "\n";
	data.clear();
	
	int test2[3][2]= { {1,2},
			 {1,2},
			 {1,2},
			 };
	for (int i = 0 ; i < 3 ; i++) {
		Interval tmp(test2[i][0], test2[i][1]);
		data.push_back(tmp);
	}
	cout << sol.eraseOverlapIntervals(data) << "\n";
	data.clear();
	
	int test3[2][2]= { {1,2},
			   {2,3}
			 };
	
	for (int i = 0 ; i < 2 ; i++) {
		Interval tmp(test3[i][0], test3[i][1]);
		data.push_back(tmp);
	}
	cout << sol.eraseOverlapIntervals(data) << "\n";

	data.clear();
	cout << sol.eraseOverlapIntervals(data) << "\n";

	return 0;
}
