#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
bool compare(const pair<int,int>& a, const pair<int,int>& b)
{
	if ( a.first == b.first){
		return a.second < b.second;
	} else 
		return a.first < b.first;
}
class Solution {
	public:
	int findMinArrowShots(vector<pair<int, int> >& points){
		int ret = 0;
		int size = points.size();
		if (size == 0)
			return ret;
		sort(points.begin(), points.end(), compare);
		int compare;
		for (int i = 0 ; i < size ; i++) {
			cout<< "[" << points[i].first << ":";
			cout << points[i].second << "]"<<endl;
		}
		int low;
		for (int i = 0 ; i < size ; i++){
			pair<int,int> pa = points[i];
			if (i==0){
				compare = pa.second;
				ret++;
			} else {
				if (compare >= pa.first && compare <= pa.second){
					continue;
				} else if (compare >= pa.second) {
					compare = pa.second;
				} else {
					// compare < pa.first
					compare = pa.second;
					ret++;
				}
				
			}
		}
		return ret;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	pair<int,int> p1(3,9);
	pair<int,int> p2(2,8);
	pair<int,int> p3(1,6);
	pair<int,int> p4(7,12);
	int test[][2] = {
			{3,9},
			{7,12},
			{3,8},
			{6,8},
			{9,10},
			{2,9},
			{0,9},
			{3,9},
			{0,6},
			{2,8}
	};
	vector< pair<int,int> > data;
	for (int i = 0 ; i < 10 ; i++){
		pair<int,int> pa(test[i][0], test[i][1]);
		data.push_back(pa);
	}


	Solution sol;
	ret = sol.findMinArrowShots(data);
	cout << ret << "\n";

	return 0;
}
