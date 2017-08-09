#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	int perm(int i)
	{
		return i *  (i-1);
	}
	int numberOfBoomerangs(vector<pair<int, int> >& points){
		map<int,int> distMap;
		map<int,int>::iterator iter;
		int dist;
		int tmp;
		int ret = 0;
		for (int i = 0 ; i < points.size() ; i++){
			for (int j = 0 ; j < points.size() ; j++){
				if (i==j) continue;
				pair<int,int> a = points[i];
				pair<int,int> b = points[j];
				dist =  (a.first - b.first) * (a.first - b.first)
					+ (a.second - b.second) * (a.second - b.second);
				iter = distMap.find(dist);
				if (iter == distMap.end()){
					distMap[dist] = 1;
				} else {
					tmp = iter->second;
					tmp++;
					distMap.erase(iter);
					distMap[dist] = tmp;
				}
				
			}
			for (iter = distMap.begin() ; iter!=distMap.end() ; iter++){
					//cout << "dist:" << iter->first;
					//cout << "  count:" << iter->second << endl;
					if (iter->second > 1)
						ret += perm(iter->second);
			}
			distMap.clear();
		}
		return ret;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	pair<int,int> p1(0,0);
	pair<int,int> p2(1,0);
	pair<int,int> p3(-1,0);
	pair<int,int> p4(0,1);
	pair<int,int> p5(0,-1);
	vector< pair<int,int> > data;
	data.push_back(p1);
	data.push_back(p2);
	data.push_back(p3);
	data.push_back(p4);
	data.push_back(p5);
	Solution sol;
	ret = sol.numberOfBoomerangs(data);
	cout << ret << "\n";

	return 0;
}
