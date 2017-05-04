#include "./stdc++.h"

using namespace std;

/*
https://leetcode.com/problems/3sum/#/description
先将数组排序，使用指针法求解
前后个一个指针，如果两个指针加和为正则左++否则右++，零则输出，需要注意不能重复，此时应当跳过所有的相同数
即while(a[left] == a[left - 1]) left++,右边也一样
这里有个程序设计技巧，外层循环整个数列
*/

void print_v(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << ", ";
	}
	cout << endl;
}

void print(std::vector<int>& a, int length){  
    for(int j = 0; j < length; j++){  
        cout << a[j] << ", ";  
    }  
    cout << endl;  
}  
  
  
  
/** 
 * 已知H[s…m]除了H[s] 外均满足堆的定义 
 * 调整H[s],使其成为大顶堆.即将对第s个结点为根的子树筛选,  
 * 
 * @param H是待调整的堆数组 
 * @param s是待调整的数组元素的位置 
 * @param length是数组的长度 
 * 
 */  
void HeapAdjust(std::vector<int>& H, int s, int length)  
{  
    int tmp  = H[s];  
    int child = 2 * s + 1; //左孩子结点的位置。(i+1 为当前调整结点的右孩子结点的位置)  
    while (child < length) {  
        if (child +1 <length && H[child] < H[child + 1]) { // 如果右孩子大于左孩子(找到比当前待调整结点大的孩子结点)  
            ++child ;  
        }  
        if (H[s] < H[child]) {  // 如果较大的子结点大于父结点  
            H[s] = H[child]; // 那么把较大的子结点往上移动，替换它的父结点  
            s = child;       // 重新设置s ,即待调整的下一个结点的位置  
            child = 2 * s + 1;  
        } else {            // 如果当前待调整结点大于它的左右孩子，则不需要调整，直接退出  
             break;  
        }  
        H[s] = tmp;         // 当前待调整的结点放到比其大的孩子结点位置上  
    }  
    // print(H, length);  
}  
  
  
/** 
 * 初始堆进行调整 
 * 将H[0..length-1]建成堆 
 * 调整完之后第一个元素是序列的最小的元素 
 */  
void BuildingHeap(std::vector<int>& H)  
{   
    //最后一个有孩子的节点的位置 i=  (length -1) / 2  
    for (int i = (H.size() - 1) / 2 ; i >= 0; --i)  
        HeapAdjust(H, i, H.size());  
}  
/** 
 * 堆排序算法 
 */  
void HeapSort(std::vector<int>& H)
{  
    //初始堆  
    BuildingHeap(H);  
    //从最后一个元素开始对序列进行调整  
    for (int i = H.size() - 1; i > 0; --i)  
    {  
        //交换堆顶元素H[0]和堆中最后一个元素  
        int temp = H[i]; H[i] = H[0]; H[0] = temp;  
        //每次交换堆顶元素和堆中最后一个元素之后，都要对堆进行调整  
        HeapAdjust(H, 0, i);  
    }  
}

class Solution {
public:

    vector<vector<int> > threeSum(vector<int>& nums) {
    	vector<vector<int> > ret;
    	if (nums.size() < 3) {
    		return ret;
    	}
    	// const clock_t t1 = clock();
    	/*以排序快慢分*/
    	/*sort1*/
        sort(nums.begin(), nums.end());
        /*sort2*/
        // HeapSort(nums);
        /*sort3*/
        // priority_queue<int> pq(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size(); i++) {
        // 	nums[i] = pq.top(); pq.pop();
        // }


        // cout << "sort time: " << float(clock() - t1) / CLOCKS_PER_SEC << endl;
        // const clock_t t2 = clock();
        // print_v(nums);
        for (int i = 0; i < nums.size() - 2; i++) {
        	int sum = 0 - nums[i], left = i + 1, right = nums.size() - 1;
        	while (left < right) {
        		int tmp = sum - nums[left] - nums[right];
        		if (tmp == 0) {
        			std::vector<int> v(3, 0);
        			v[0] = nums[i];
        			v[1] = nums[left];
        			v[2] = nums[right];
        			ret.push_back(v);
        			while (nums[left] == nums[left + 1]) {
        				left++;
        			}
        			left++;
        			while (nums[right] == nums[right - 1]) {
        				right--;
        			}
        			right--;
        		}
        		if (tmp > 0) {
        			left++;
        		} else if (tmp < 0) {
        			right--;
        		}
        	}
        	while (nums[i] == nums[i + 1]) {
				i++;
			}
        }
        // cout << "find time: " << float(clock() - t2) / CLOCKS_PER_SEC << endl;
        return ret;
    }
};

void print_v_v(vector<vector<int> > &vv) {
	for (int i = 0; i < vv.size(); i++) {
		cout << "[ ";
		for (int j = 0; j < vv[i].size(); j++) {
			cout << vv[i][j] << ", ";
		}
		cout << " ]" << endl;
	}
	cout << endl;
}
/*
4.5 9:26
*/
int main() {
	Solution *s = new Solution();
	int a[] = {-1, -1, 3, 1, -0, -2,-1, -1, 3, 1, -0, -2,-1, -1, 3, 1, -0, -2,-1, -1, 3, 1, -0, -2,-1, -1, 3, 1, -0, -2,-1, -1, 3, 1, -0, -2};
	std::vector<int> v(a, a + 36);

	// int a[] = {0, 0, 0, 0};
	// std::vector<int> v(a, a + 4);
	vector<vector<int> > x = s->threeSum(v);
	print_v_v(x);

	return 0;
}