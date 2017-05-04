//#include <bits/stdc++.h>
#include <iostream>
 
int f(int i) {
    if (i <= 0) {
        return 1;
    }
    return i * f(i - 1);
}
 
int main()
{
    for (size_t i = 10; i >= 0; --i) {
        std::cout << f(i) << std::endl;
    }
    return 0;
}