#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool compare(const pair<int,int>& a, const pair<int,int>& b)
{
	if (a.first == b.first){
		return a.second < b.second;
	} else
		return a.first < b.first;
}
class Solution {
	public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people){
		vector<pair<int,int>> ans;
		vector<bool> used(people.size(), false);
		sort(people.begin(), people.end(), compare);
//		for (int i = 0 ; i < people.size() ; i++)
//			cout << people[i].first <<"," << people[i].second << endl;
		while(ans.size() != people.size()){
			for (int i = 0 ; i < people.size() ; i++){
				if (!used[i] && people[i].second <= ans.size()){
					int count = 0;
					for (int j = 0 ; j < ans.size() ; j++){
						if (ans[j].first >= people[i].first)
							count++;
					}
					if (count==people[i].second){
						used[i] = true;
						ans.push_back(people[i]);
						break;
					}
				}
			}
		}
		return ans;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<pair<int,int>> people;
	people.push_back(pair<int,int>(7,0));
	people.push_back(pair<int,int>(4,4));
	people.push_back(pair<int,int>(7,1));
	people.push_back(pair<int,int>(5,0));
	people.push_back(pair<int,int>(6,1));
	people.push_back(pair<int,int>(5,2));
	vector<pair<int,int>> ret_vec;
	int ret;
	ret_vec = sol.reconstructQueue(people);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i].first << "," << ret_vec[i].second << endl;
	cout <<endl;

	return 0;
}
