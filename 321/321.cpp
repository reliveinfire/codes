#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;
#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class Solution {
	public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
			vector<int> ans;
			for (int i = 0 ; i <= k ; i++){	
				if (i <= nums1.size() && k-i <= nums2.size()){
					vector<int> n1 = genMax(nums1, i);
					vector<int> n2 = genMax(nums2, k - i);
					int id1 = 0, id2 = 0;
					vector<int> tmp = merge(n1,n2,0,0);
					if (ans.empty())
						ans = tmp;
					else {
						if (greater(tmp, ans)){
							ans = tmp;
						}
					}
				}
			}
			return ans;
	}
	vector<int> merge(vector<int>& n1, vector<int>& n2, int id1, int id2){
		vector<int> ret;
		while(id1 < n1.size() || id2 < n2.size()){
			if (id1< n1.size() && id2< n2.size()){
				if (gg(n1,n2, id1, id2))
					ret.push_back(n1[id1++]);
				else
					ret.push_back(n2[id2++]);
			} else if (id1 < n1.size()){
					ret.push_back(n1[id1++]);
			} else if (id2 < n2.size()){
					ret.push_back(n2[id2++]);
			
			}
		}
		return ret;
	}
	bool gg(vector<int>& n1, vector<int>& n2, int id1, int id2){
		while(id1 < n1.size() && id2 < n2.size() && n1[id1]==n2[id2]){
			id1++;
			id2++;
		}
		if (id1 < n1.size() && id2 < n2.size()){
			return n1[id1] > n2[id2];
		} else if (id1 < n1.size()){
			return true;
		} else if (id2 < n2.size()){
			return false;
		} else
			return true;
	}

	bool greater(vector<int>& A, vector<int>& B){
		for (int i = 0 ; i < A.size() ; i++){
			if (A[i] < B[i])
				return false;
			else if (A[i] > B[i])
				return true;
		}
		return false;
	}
	vector<int> genMax(vector<int>& nums, int k){
		if (k == 0)
			return {};
		vector<int> ret;
		for (int i = 0 ; i < nums.size() ; i++){
			while(!ret.empty() && nums[i] > ret.back()){
				if ( k - ret.size() <= nums.size() - i - 1)
					ret.pop_back();
				else
					break;
			}
			if (ret.size() < k)
				ret.push_back(nums[i]);
		}
		return ret; 
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {6,7};
	vector<int> B = {6,0,4};
	Solution sol;
	vector<int> ret_vec;
	ret_vec = sol.maxNumber(A, B, 5);
//	ret_vec = sol.genMax(A,1);
	cout << "ans:";
	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
