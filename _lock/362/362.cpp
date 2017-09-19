#include "../helpers.cpp"

void insert(int in)
{
	vector<int> data(sz, 0);
	int end = 0,front = 0;
	if ( (end+1)%sz == front ){
		total -= data[front];
		total += in;
		front = (front+1)%sz;
	}
	data[back] = in;
	back = (back+1)%sz;
	return;
}
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class HitCounter {
        public:
        HitCounter{
		total = 0;
		curr = 1;
		curr_hit = 0;
        }
	void hit(int timestamp){
		if (curr != timestamp)
			update(timestamp);
		curr_hit++;
		return;
	}
	int getHits(int timestamp){
		if (curr!=timestamp){
			update(timestamp);
		}
		return total + curr_hit;
	}
	private:
		void update(int timestamp){
			int diff = timestamp - curr;
			if (diff > 300)
				diff = 301;
			for (int i = 0 ; i < diff ; i++){
				if (i==0){
					total += curr_hit;
					qu.push(curr_hit);
				} else
					qu.push(0);
				if (qu.size() > 300) {
					total -= qu.front();
					qu.pop();
				}
			}
			curr = timestamp;
			curr_hit = 0;
		}
		int total;
		int curr;
		int curr_hit;
		queue<int> count;
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
