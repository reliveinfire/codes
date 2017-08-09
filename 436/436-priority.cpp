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

struct StartPoint{
	int value;
	int pos;
	StartPoint(int v, int p) : value(v), pos(p){}
};

bool mycompare(const StartPoint& a, const StartPoint& b)
{
	if (a.value < b.value)
		return true;
	else
		return false;
}

int binary_search(vector<StartPoint>& nums, int l, int r, int target)
{
	int m = (l + r) / 2;
	if (l==r)
		return l;

	if (nums[m].value == target)
		return m;
	if (nums[m].value > target){
		return binary_search(nums, l , m-1, target);
	} else {
		return binary_search(nums, m+1 , r, target);
	}
}

class Solution {
	public:
		vector<StartPoint> sPoints;
		vector<int> findRightInterval(vector<Interval>& intervals){
			vector<int> result;

			if (intervals.empty())
				return result;

			for (int i = 0 ; i < intervals.size() ; i++){
				StartPoint sp(intervals[i].start, i);
				sPoints.push_back(sp);
			}
			sort(sPoints.begin(), sPoints.end(), mycompare);

			for (int i = 0 ; i < intervals.size() ; i++){
				int target = intervals[i].end;

				int po = binary_search(sPoints, 0, sPoints.size() - 1, target);

#if 0
		cout << "i:" << i << " target:" << target << " po:" << po <<"\n";
		for (int i = 0 ; i < sPoints.size() ; i++)
			cout << " " << sPoints[i].value;
		cout << "\n";
#endif
				if (po== sPoints.size() - 1
						&& target > sPoints[po].value) {
					result.push_back(-1);
				} else {
					if (sPoints[po].value < target)
						result.push_back(sPoints[po+1].pos);
					else
						result.push_back(sPoints[po].pos);
				}

			}
			return result;
		}
};

int main()
{

	vector<Interval> data;
	vector<int> ret;
	Solution sol;
#if 0
	int test[1][2]= { {1,2},
			 };
	for (int i = 0 ; i < 1 ; i++) {
		Interval tmp(test[i][0], test[i][1]);
		data.push_back(tmp);
	}

	
	ret = sol.findRightInterval(data);

	for (int i = 0 ; i < ret.size() ; i++)
		cout << " " << ret[i];
	cout << "\n";
	data.clear();
#endif
#if 0
	int test2[3][2]= { {3,4},
			 {2,3},
			 {1,2},
			 };
	for (int i = 0 ; i < 3 ; i++) {
		Interval tmp(test2[i][0], test2[i][1]);
		data.push_back(tmp);
	}
	
	ret = sol.findRightInterval(data);

	for (int i = 0 ; i < ret.size() ; i++)
		cout << " " << ret[i];
	cout << "\n";

	data.clear();
#endif	
#if 0
	int test3[3][2]= { {1,4},
			   {2,3},
			   {3,4}
			 };
	
	for (int i = 0 ; i < 3 ; i++) {
		Interval tmp(test3[i][0], test3[i][1]);
		data.push_back(tmp);
	}
	ret = sol.findRightInterval(data);

	for (int i = 0 ; i < ret.size() ; i++)
		cout << " " << ret[i];
	cout << "\n";
#endif
#if 1
	int test3[6][2]= { {1,12},
			   {2,9},
			   {3,10},
			   {13,14},
			   {15,16},
			   {16,17}
			 };
	
	for (int i = 0 ; i < 6 ; i++) {
		Interval tmp(test3[i][0], test3[i][1]);
		data.push_back(tmp);
	}
	ret = sol.findRightInterval(data);

	for (int i = 0 ; i < ret.size() ; i++)
		cout << " " << ret[i];
	cout << "\n";
#endif

	return 0;
}
