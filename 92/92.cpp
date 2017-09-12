#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        ListNode* reverseBetween(ListNode* head, int m, int n){
		ListNode dummy;
		dummy.next = head;
		ListNode* start = head;
		ListNode* pre=&dummy;
		int diff = n-m;
		if (m==n)
			return dummy.next;
		while(m>1){
			pre = start;
			start = start->next;
			m--;
		}
		ListNode* end = start;
		while(diff>=0){
			end = end->next;
			diff--;
		}
		ListNode* i = *j = start;
		ListNode* k = start->next;
		while(k!=end){
			j = k;
			k = k->next;
			j->next = i;
			i = j;
		}
		start->next = end;
		pre->next = j;
		return dummy.next;
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
