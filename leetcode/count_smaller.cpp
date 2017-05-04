#include <cmath>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node *root;

void countInBinTree(Node** node, int data, int *count) {
	if (*node == NULL) {
		*node = (Node *) malloc(sizeof(Node));
		(*node)->left = NULL;
		(*node)->right = NULL;
		(*node)->data = data;
		return;
	}
	if ((*node)->data >= data) {
		countInBinTree(&((*node)->left), data, count);
		return;
	}
	if ((*node)->data < data) {
		(*count)++;
		countInBinTree(&((*node)->right), data, count);
		return;
	}
}

void free_node(Node *node) {
	if (node == NULL) {
		return;
	}
	if (node->left) {
		free_node(node->left);
		node->left = NULL;
	}
	if (node->right) {
		free_node(node->right);
		node->right = NULL;
	}
	free(node);
}

/*
https://leetcode.com/problems/count-of-smaller-numbers-after-self/#/description
*/
int* countSmaller(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
    int *ret = (int *) malloc(sizeof(int) * *returnSize);
    root = NULL;
    for (int i = numsSize - 1; i >= 0; i--) {
    	ret[i] = 0;
    	countInBinTree(&root, nums[i], &(ret[i]));
    }
    free_node(root);
    return ret;
}

int main() {
	int a[] = {5, 2, 6, 1};
	int b_len = 0;
	int* b = countSmaller(a, 4, &b_len);
	for (int i = 0; i < b_len; i++) {
		printf("%d, ", b[i]);
	}
	printf("\n");
	return 0;
}