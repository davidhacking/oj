#include "./stdc++.h"
using namespace std;

/*
beats 6.88
*/

struct Item
{
    int val;
    int index;
    Item(int v, int i): val(v), index(i) {}
};

void shiftdown_little(int i, std::vector<Item> &m_heap, std::map<int, int> &m) {
    int nexti = (i + 1) * 2 - 1, maxson = 0;
    if (nexti <= m_heap.size() - 1) {
        if (nexti + 1 <= m_heap.size() - 1 && m_heap[nexti + 1].val > m_heap[nexti].val) {
            maxson = m_heap[nexti + 1].val;
            nexti = nexti + 1;
        } else {
            maxson = m_heap[nexti].val;
        }
        if (maxson > m_heap[i].val) {
            int tmp = m_heap[nexti].index;
            m_heap[nexti].val = m_heap[i].val;
            m_heap[nexti].index = m_heap[i].index;
            m[m_heap[i].index] = nexti;
            m_heap[i].val = maxson;
            m_heap[i].index = tmp;
            m[tmp] = i;
            shiftdown_little(nexti, m_heap, m);
        }
    }
}

void shiftup_great(int i, std::vector<Item> &m_heap, std::map<int, int> &m) {
    int parenti = i % 2 == 0 ? (i / 2 - 1) : ((i + 1) / 2 - 1), parent = 0;
    if (parenti >= 0) {
        parent = m_heap[parenti].val;
        if (parent < m_heap[i].val) {
            int tmp = m_heap[parenti].index;
            m_heap[parenti].val = m_heap[i].val;
            m_heap[parenti].index = m_heap[i].index;
            m[m_heap[i].index] = parenti;
            m_heap[i].val = parent;
            m_heap[i].index = tmp;
            m[tmp] = i;
            shiftup_great(parenti, m_heap, m);
        }
    }
}

void print_vector(std::vector<Item> _v) {
    for (int i = 0; i < _v.size(); i++) {
        cout << _v[i].val << ", ";
    }
    cout << endl;
}

void print_v(std::vector<int> _v) {
    for (int i = 0; i < _v.size(); i++) {
        cout << _v[i] << ", ";
    }
    cout << endl;
}

void print_map(std::map<int, int> &m) {
    for (std::map<int, int>::iterator i = m.begin(); i != m.end(); i++) {
        cout << "key: " << i->first << " value: " << i->second << endl;
    }
}

void swap_item(Item *a, Item *b) {
    int val = a->val;
    int index = a->index;
    a->val = b->val;
    a->index = b->index;
    b->val = val;
    b->index = index;
}

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1 || nums.size() <= 0) {
        	return nums;
        }
        std::vector<int> ret;
        if (k == nums.size()) {
            int max = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (max < nums[i]) {
                    max = nums[i];
                }
            }
            ret.push_back(max);
            return ret;
        }
        // init heap
        std::vector<Item> m_heap;
        // index of item in nums, index of item in heap
        std::map<int, int> m;
        for (int i = 0; i < k; i++) {
            Item tmp(nums[i], i);
            m_heap.push_back(tmp);
            m[i] = m_heap.size() - 1;
        }
        for (int i = k / 2 - 1; i >= 0; i--) {
            shiftdown_little(i, m_heap, m);
        }
        // print_vector(m_heap);
        // print_map(m);
        ret.push_back(m_heap[0].val);
        // compute ret
        for (int i = 1; i <= nums.size() - k; i++) {
            // replace
            Item tmp(nums[i + k - 1], i + k - 1);
            m_heap[m[i - 1]] = tmp;
            m[i + k - 1] = m[i - 1];
            
            shiftdown_little(m[i - 1], m_heap, m);
            shiftup_great(m[i - 1], m_heap, m);

            // print_vector(m_heap);
            // print_map(m);
            ret.push_back(m_heap[0].val);
        }
        
        return ret;
    }
};



int main() {
	Solution  *s = new Solution();
	// int nums[] = {1,3,-1,-3,5,3,6,7};
	// std::vector<int> v(nums, nums + 8);
	// std::vector<int> v2 = s->maxSlidingWindow(v, 3);
	// print_v(v2);

    int nums2[] = {-7,-8,7,5,7,1,6,0};
    std::vector<int> v3(nums2, nums2 + 8);
    std::vector<int> v4 = s->maxSlidingWindow(v3, 4);
    print_v(v4);
	return 0;
}