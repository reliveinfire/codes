#include "../helpers.cpp"
#ifdef I2C
static void i2c_flush_rxfifo(struct i2c_adapter *adap)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);
        while (readl(&i2c_base->ic_status) & IC_STATUS_RFNE) {
                readl(&i2c_base->ic_cmd_data);
                //debug("flush rxfifo: read data %02x\n", data);
        }
}
static int i2c_wait_for_bb(struct i2c_adapter *adap)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);
        int count = 0;

        //debug("wait for BB: ic status %08x\n", readl(&i2c_base->ic_status));
        while ((readl(&i2c_base->ic_status) & IC_STATUS_MA) ||
               !(readl(&i2c_base->ic_status) & IC_STATUS_TFE)) {
                /* Evaluate timeout */
                udelay(1000);
                count++;
                if (count > TIMEOUT_LOOP)
                        return 3;
        }

        return 0;
}
static int i2c_xfer_init(struct i2c_adapter *adap, uchar chip, uint addr,
                         int alen)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);

        int ret = i2c_wait_for_bb(adap);
        if (ret){
                return ret;
        }

        i2c_setaddress(adap, chip);
        while (alen) {
                alen--;
                /* high byte address going out first */
                writel((addr >> (alen * 8)) & 0xff,
                       &i2c_base->ic_cmd_data);
        }
static int i2c_xfer_finish(struct i2c_adapter *adap)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);

        int count = 0;
        while (1) {
                if ((readl(&i2c_base->ic_raw_intr_stat) & IC_STOP_DET)) {
                        readl(&i2c_base->ic_clr_stop_det);
                        break;
                } else if (count > TIMEOUT_LOOP){
                        break;
                } else {
                        udelay(1000);
                        count++;
                }
        }

        if (i2c_wait_for_bb(adap)) {
                return 5;
        }

        i2c_flush_rxfifo(adap);

        return 0;
}

static int dw_i2c_read(struct i2c_adapter *adap, u8 dev, uint addr,
                       int alen, u8 *buffer, int len)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);
        int count = 0;
        int ret = i2c_xfer_init(adap, dev, addr, alen);
        if (ret){
                return ret;
        }

        if (len == 1)
                writel(IC_CMD | IC_STOP, &i2c_base->ic_cmd_data);
        else if (len > 0)
                writel(IC_CMD, &i2c_base->ic_cmd_data);

        while (len) {
                if ((readl(&i2c_base->ic_status) & IC_STATUS_RFNE) != 0) {
                        *buffer++ = (uchar)readl(&i2c_base->ic_cmd_data);
                        len--;
                        if (len == 1)
                                writel(IC_CMD | IC_STOP, &i2c_base->ic_cmd_data);
                        else if (len > 0)
                                writel(IC_CMD, &i2c_base->ic_cmd_data);
                } else if (count > TIMEOUT_LOOP){
                        return 7;
                } else {
                        count++;
                        // 4bytes + address, start/stop bit, take it as 8 bytes
                        // 8 bytes = 256 bits
                        udelay(5000);
                }
        }

        return i2c_xfer_finish(adap);
}
int giu_i2c_read(unsigned int reg)
{
        unsigned int val;
        dw_i2c_read(NULL, GIU_SLAVE_ADDR, reg, 1, (u8*)&val, 4);
        val = (val &0x00FFFF00) | (val &0xFF) << 24 | (val &0xFF000000) >> 24;
        val = (val &0xFF0000FF) | (val &0xFF00) << 8 | (val&0xFF0000) >> 8;
        return val;
}

int giu_i2c_write(unsigned int reg, unsigned int val){
        int ret = 0;
        val = (val &0x00FFFF00) | (val &0xFF) << 24 | (val &0xFF000000) >> 24;
        val = (val &0xFF0000FF) | (val &0xFF00) << 8 | (val&0xFF0000) >> 8;
        ret = dw_i2c_write(NULL, GIU_SLAVE_ADDR, reg, 1, (uint8_t*)&val, 4);
        return ret;
}

#else

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class RandomizedCollection {
public:
    RandomizedCollection() {    }
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
	auto iter = tb.find(val);
	if (iter!=tb.end()){
		iter->second.insert(vec.size());
		vec.push_back(val);
		return false;
	} else {
		tb[val].insert(vec.size());
		vec.push_back(val);
		return true;
	}
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
	auto iter = tb.find(val);
	if (iter==tb.end())
		return false;
	int pos = *(iter->second.begin());
	int last = vec.back();

	iter->second.erase(iter->second.begin());
	if (iter->second.size()==0)
		tb.erase(iter);

	iter = tb.find(last);
	if (iter!= tb.end()){
		iter->second.erase(vec.size() - 1);
		iter->second.insert(pos);
	}

	vec[pos] = last;
	vec.pop_back();
	return true;

    }
    /** Get a random element from the collection. */
    int getRandom() {
	    random_device rd;
	    mt19937 gen(rd());
	    uniform_int_distribution<int> dis(0, vec.size() - 1);
	    int ret = dis(gen);
	    return ret;
    }
    void dump(){
    	for (int i = 0 ; i < vec.size() ; i++)
		cout << vec[i] << " ";
	cout << endl;
    }
    private:
    	vector<int> vec;
	unordered_map<int, unordered_set<int>> tb;
};
#endif
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	RandomizedCollection rr;
        cout  << "ans:" << rr.insert(1) << endl;
        cout << "ans:" << rr.insert(1) << endl;
        cout  << "ans:" << rr.insert(2) << endl;
        cout << "ans:" << rr.remove(1) << endl;
        rr.dump() << endl;


	return 0;
}
