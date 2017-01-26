#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, const char *argv[]) {
	cout << fixed << setprecision(1);
	double a = 1.09;
	cout << "hello cpp\n" << "a=" << a << endl;
	cout << fixed << setprecision(2);
	cout << "hello cpp\n" << "a=" << a << endl;
	// test open file
	freopen("/Users/david/tmp/test.txt", "r", stdin);
	char *str = NULL;
	scanf("%s", str);
	cout << str << endl;
	fclose(stdin);
	return 0;
}