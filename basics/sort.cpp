#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

int main() {
    const size_t N = 50'000'000;   // 10 million elements

    // Random number generator
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, 1'000'000);

    // Fill vector with random numbers
    std::vector<int> v(N);
    for (size_t i = 0; i < N; ++i) {
        v[i] = dist(rng);
    }

    // Copy for fair comparison
    std::vector<int> v_copy = v;

    // -------- First sort (default) --------
    auto start1 = std::chrono::high_resolution_clock::now();
    std::sort(v.begin(), v.end());
    auto end1 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration1 = end1 - start1;

    // -------- Second sort (lambda comparator) --------
    auto start2 = std::chrono::high_resolution_clock::now();
    std::sort(v_copy.begin(), v_copy.end(),
              [](int a, int b) {
                  return a < b;
              });
    auto end2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration2 = end2 - start2;

    std::cout << "Time (default sort):  "
              << duration1.count() << " ms\n";

    std::cout << "Time (lambda sort):   "
              << duration2.count() << " ms\n";

    return 0;
}

