#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
#if 0
class Solution {
	public:
	int findRotateSteps(string ring, string key){
		vector<int> key_pos;
		int n = key.size() - 1;
		int ret = INT_MAX;
		for (int i = 0 ; i < ring.size() ; i++){
			if ( key[n] == ring[i])
				key_pos.push_back(i);
		}
		for (int i = 0 ; i < key_pos.size() ; i++){
			int tp = key_pos[i];
			ret= min(ret, helper(ring, key, n, tp));
		}
		ret += key.size();
		return ret;
	}

	int helper(string ring, string key, int n, int pos){
		vector<int> ring_pos;
		int local_min = INT_MAX;
		if (n < 0){
			return 0;	
		} else if (n == 0){
			ring_pos.push_back(0);
		} else {
			for(int i = 0 ; i < ring.size() ; i++){
				if (key[n-1] == ring[i])
					ring_pos.push_back(i);
			}
		}
		for (int i = 0 ; i < ring_pos.size() ; i++){
			int pp = ring_pos[i];
			int diff1 = pos - pp >= 0 ? pos - pp : pos - pp + ring.size();
			int diff2 = pp - pos >= 0 ? pp - pos : pp - pos + ring.size();
			int mindiff = min(diff1, diff2);
#if 0
			cout << "pos=" << pos;
			cout << " ring_pp=" << pp;
			cout << " diffs= ";
			cout << diff1 << ":" << diff2 << endl;
#endif
			local_min = min(local_min, mindiff + helper(ring, key, n-1, pp));
		}
		return local_min;
	}
};
#else
class Solution {
	public:
	int findRotateSteps(string ring, string key){
		vector< vector<int> > dp(key.size() + 1, vector<int>(ring.size(), INT_MAX));
		vector<int> prepos;
		int diff1, diff2;
		int localmin;
		for (int j = 0 ; j < ring.size() ;  j++)
			dp[0][j] = 0;

		for (int i = 1 ; i <= key.size() ; i++){
			for (int j = 0 ; j < ring.size() ; j++){
				//cout << key[i-1] << " vs " << ring[j] << endl;
				localmin = INT_MAX;
				if (key[i-1] == ring[j]){
					prepos.clear();
					if (i == 1){
						prepos.push_back(0);
					} else {
						prepos = findPos(ring, key, i-2);
					}

					for (int k = 0 ; k < prepos.size() ; k++){
						int pre = prepos[k];
						diff1 = j - pre >= 0 ? j - pre : j - pre + ring.size();
						diff2 = pre - j >= 0 ? pre - j : pre - j + ring.size();
						//cout << pre << endl;
						//cout << diff1 << ":" << diff2 << endl;
						localmin = min(localmin, min(diff1, diff2) + dp[i-1][pre]);
					}
					dp[i][j] = localmin;
				}
			}
		}

		int ret = INT_MAX;
		for (int j = 0 ; j < ring.size(); j++){
			ret = min(ret, dp[key.size()][j]);
		}
		ret = ret + key.size();
		return ret;
	}

	vector<int> findPos(string ring, string key, int kp){
		vector<int> ret;
		for (int i = 0 ; i < ring.size() ; i++){
			if (key[kp] == ring[i])
				ret.push_back(i);
		}
		return ret;
	}
};
#endif

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	genVector(da, A);
	genVector(db, B);
	string sa("godding");
	string sb("gd");

	Solution sol;
	ret = sol.findRotateSteps(sa,sb);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
