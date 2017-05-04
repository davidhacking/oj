/**
https://leetcode.com/problems/copy-list-with-random-pointer
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, RandomListNode *> m;
        RandomListNode *node = head;
        RandomListNode *newHead = NULL;
        RandomListNode **tmp = &newHead;
        while (node != NULL) {
            *tmp = new RandomListNode(node->label);
            m[node] = *tmp;
            tmp = &((*tmp)->next);
            node = node->next;
        }
        node = head;
        while (node != NULL) {
            m[node]->random = m[node->random];
            node = node->next;
        }
        return newHead;
    }
};