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

class Solution {
	public:
	vector<StartPoint> sPoints;
	vector<int> findRightInterval(vector<Interval>& intervals){
		vector<int> result;

		if (intervals.empty())
			return result;
			
		for (int i = 0 ; i < intervals.size() ; i++){
			// insert to priority queue
			StartPoint sp(intervals[i].start, i);
			sPoints.push_back(sp);
		}
		sort(sPoints.begin(), sPoints.end(), mycompare);

		for (int i = 0 ; i < intervals.size() ; i++){
			int j;
			int target = intervals[i].end;

			for (j = 0 ; j < sPoints.size() ; j++){
				if (target <= sPoints[j].value){
					result.push_back(sPoints[j].pos);
					break;
				}
			}
			if (j == sPoints.size()){
				// not found
				result.push_back(-1);
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

	return 0;
}
