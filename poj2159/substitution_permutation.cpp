#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void swap_char(char *a, char *b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
冒泡排序
比较相邻的元素。 如果第一个比第二个大，就交换他们两个。
对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。 在这一点，最后的元素应该会是最大的数。
针对所有的元素重复以上的步骤，除了最后一个。
持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
*/
static void bubble_sort(char *tobe_sort_str, int len) {
	for (int k = len - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (tobe_sort_str[i] > tobe_sort_str[i + 1]) {
				swap_char(&(tobe_sort_str[i]), &(tobe_sort_str[i + 1]));
			}
		}
	}
}

static char *cipher_string_func(const char *tobe_cipher_str, int len) {
	char *cipher_str = NULL;
	if (tobe_cipher_str == NULL || len == 0) {
		return NULL;
	}
	cipher_str = (char *) malloc(len);
	if (cipher_str == NULL) {
		return NULL;
	}
	for (int i = 0; i < len; i++) {
		if ('A' <= tobe_cipher_str[i] && tobe_cipher_str[i] <= 'Y') {
			cipher_str[i] = tobe_cipher_str[i] + 1;
		} else if (tobe_cipher_str[i] == 'Z') {
			cipher_str[i] = 'A';
		} else {
			if (cipher_str) {
				free(cipher_str);
				return NULL;
			}
		}
	}
	bubble_sort(cipher_str, len);
	return cipher_str;
}

static bool count_diff_char_in_string(const char *str1, const char *str2) {
	int map1[26],map2[26];
	memset(map1, 0, sizeof(map1));
	memset(map2, 0, sizeof(map2));

	for (int i = 0; str1[i] != '\0'; i++) {
		map1[str1[i] - 'A']++;
		map2[str2[i] - 'A']++;
	}

	int char_count[101];
	memset(char_count, 0, sizeof(char_count));
	for (int i = 0; i < 26; i++) {
		char_count[map1[i]]++;
		char_count[map2[i]]--;
	}

	for(int i = 0; i < 101; i++){
		if(char_count[i] != 0){
			return false;
		}
	}
	return true;
}

/*
test:
JWPUDJSTVP
VICTORIOUS

JWPUDJSTPV
VICTORIOUS

JWPUDJSTPP
VICTORIOUS
*/
int main(int args, const char *argv[]) {
	char cipher_str[101];
	int cipher_str_len = 0;
	char decrypted_str[101];
	int decrypted_str_len = 0;

	memset(cipher_str, 0, 101);
	memset(decrypted_str, 0, 101);
	scanf("%s%s", cipher_str, decrypted_str);
	
	if (count_diff_char_in_string(cipher_str, decrypted_str) == true) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}