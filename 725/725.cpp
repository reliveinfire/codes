#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<ListNode*> splitListToParts(ListNode* root, int k){
		vector<ListNode*> res(k, NULL);
		int cnt = 0;
		ListNode* idx = root;
		while(idx!=NULL){
			cnt++;
			idx = idx->next;
		}
		int div = cnt / k;
		int mod = cnt % k;
		int cur = 0;
		ListNode* pre = NULL;
		idx = root;
		while(cur < k && idx!=NULL){
			if (pre)
				pre->next = NULL;
			res[cur++] = idx;
			for (int i = 0 ; i < div ; i++){
				pre = idx;
				if (idx==NULL)
					break;
				idx = idx->next;
			}
			if (mod>0){
				pre = idx;
				if (idx != NULL)
					idx = idx->next;
				mod--;
			}
		}
		return res;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
