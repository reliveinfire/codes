#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int maximumProduct(vector<int>& nums){
		multiset<int> pos;
		multiset<int> neg;
		for (int it : nums){
			if (it>=0){
				pos.insert(it);
				if (pos.size()>3)
					pos.erase(prev(pos.end()));
			} else {
				neg.insert(it);
				if (neg.size()>3)
					neg.erase(neg.begin());
			}
		}
		int ans = INT_MIN;
		vector<int> tt;
		for (auto it = pos.begin() ; it!= pos.end() ; it++)
			tt.push_back(*it);
		for (auto it = neg.begin() ; it!=neg.end() ; it++)
			tt.push_back(*it);
		cout << tt.size() << endl;
		for (int i = 0 ; i < tt.size() ; i++){
			for (int j = i+1 ; j < tt.size() ; j++){
				for (int k = j + 1 ; k < tt.size() ; k++){
					ans = max(ans, tt[i]*tt[j]*tt[k]);
				}
			}
		}
		return ans;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	Solution sol;
	int ret;
	ret = sol.maximumProduct(A);
	cout << ret << "\n";

	cout <<endl;

	return 0;
}
