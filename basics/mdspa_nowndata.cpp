#include <iostream>
#include <mdspan>
#include <array>

int main() {
    // Raw storage: 6 elements in a 1D array
    std::array<int, 6> data = {1, 2, 3, 4, 5, 6};

    // Create a 2D mdspan of shape (2 rows, 3 columns)
    std::mdspan<int, std::extents<size_t, 2, 3>> A(data.data());

    // Access elements as if it were a 2D array
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            std::cout << A(i, j) << " ";
        }
        std::cout << "\n";
    }
}

