#include <iostream>
#include <array>
#include <cstdio>

int main() {
    // Initlialize std::aray properly
    std::array<int,5> a = {1, 2, 3, 4, 5};

    int* ptr = a.data(); // point to a[0]

    for (int i = 0; i < a.size(); ++i)
	    std::printf("pointer[%d] %d\n", i, ptr[i]);
    
    return 0;
}
