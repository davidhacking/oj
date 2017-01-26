#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct bin_tree {
	char data;
	bin_tree *left;
	bin_tree *right;
};

static int find_char_in_str(const char *str, char tobe_find) {
	if (str == NULL || tobe_find == '\0') {
		return -1;
	}
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == tobe_find) {
			return i;
		}
	}
	return -1;
}

static bin_tree *gen_bin_tree(const char *preord, int preord_start, int preord_end, 
	const char *inord, int inord_start, int inord_end) {
	if (preord_start < 0 || preord_end < 0 || inord_start < 0 || inord_end < 0) {
		return NULL;
	}
	bin_tree *root = new bin_tree();
	root->data = preord[preord_start];
	root->left = NULL;
	root->right = NULL;

	if (preord_start == preord_end && inord_start == inord_end) {
		return root;
	}
	int x = find_char_in_str(inord, preord[preord_start]);
	if (x == -1) {
		return NULL;
	}
	if (x > inord_start) {
		root->left = gen_bin_tree(preord, preord_start + 1, preord_start + x - inord_start, inord, inord_start, x - 1);
	}
	if (x < inord_end) {
		root->right = gen_bin_tree(preord, preord_start + x - inord_start + 1, preord_end, inord, x + 1, inord_end);
	}
	return root;
}

static void print_postord(bin_tree *root) {
	if (root == NULL) {
		return;
	}
	print_postord(root->left);
	print_postord(root->right);
	cout << root->data;
}

int main() {
	char preord[27];
	char inord[27];
	memset(preord, 0, 27);
	memset(inord, 0, 27);
	while (scanf("%s %s", preord, inord) != EOF) {
		bin_tree *root = gen_bin_tree(preord, 0, strlen(preord) - 1, inord, 0, strlen(inord) - 1);
		print_postord(root);
		cout << endl;
	}
	return 0;
}

/*
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 10000
char a[MAX],b[MAX];
void build(int n,char *a,char *b){
	if(n<=0)return;
	else{
		int p=strchr(b,a[0])-b;
		build(p,a+1,b);
		build(n-1-p,a+p+1,b+p+1);
		printf("%c",a[0]);
	}
}
int main(){
	
	while(scanf("%s %s",a,b)!=EOF){
		int n=strlen(a);
		build(n,a,b);
		printf("\n");
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
}
*/