#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        int kEmptySlots(vector<int>& flowers, int k){
		set<int> pos;
		for (int i = 0 ; i < flowers.size() ; i++){
			pos.insert(flowers[i]);
			auto iter = pos.find(flowers[i]);
			int diff = -1;
			if (iter!=pos.begin()){
				diff = *iter - *prev(iter) - 1;
				if (diff==k)
					return i+1;
			}
			if (iter!=--pos.end()){
				diff = *next(iter) - *iter - 1;
				if (diff==k)
					return i+1;
			}
		}
		return -1;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {6,5,8,9,7,1,10,2,3,4};
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.kEmptySlots(A,2);
	cout << ret << "\n";


	return 0;
}
