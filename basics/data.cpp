#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

struct AOS_particles {
    float x;
    float y;
    float z;
};

struct SOA_particles {
    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> z;
};

int main() {
    const std::size_t N = 10'000'00;

    // -------------------------
    // Create AoS data
    // -------------------------
    std::vector<AOS_particles> aos(N);

    // -------------------------
    // Create SoA data
    // -------------------------
    SOA_particles soa;
    soa.x.resize(N);
    soa.y.resize(N);
    soa.z.resize(N);

    // Initialize both with the same values
    for (std::size_t i = 0; i < N; ++i) {
        float value = static_cast<float>(i);

        aos[i].x = value;
        aos[i].y = value;
        aos[i].z = value;

        soa.x[i] = value;
        soa.y[i] = value;
        soa.z[i] = value;
    }

    // =========================================================
    // AoS benchmark
    // =========================================================

    auto aos_start = std::chrono::high_resolution_clock::now();

    for (std::size_t i = 0; i < N; ++i) {
        aos[i].x += 1.0f;
        aos[i].y += 2.0f;
        aos[i].z += 3.0f;
    }

    auto aos_end = std::chrono::high_resolution_clock::now();

    auto aos_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            aos_end - aos_start
        ).count();

    // =========================================================
    // SoA benchmark
    // =========================================================

    auto soa_start = std::chrono::high_resolution_clock::now();

    for (std::size_t i = 0; i < N; ++i) {
        soa.x[i] += 1.0f;
        soa.y[i] += 2.0f;
        soa.z[i] += 3.0f;
    }

    auto soa_end = std::chrono::high_resolution_clock::now();

    auto soa_time =
        std::chrono::duration_cast<std::chrono::microseconds>(
            soa_end - soa_start
        ).count();

    // =========================================================
    // Results
    // =========================================================

    std::cout << std::fixed << std::setprecision(3);

    std::cout << "AoS: "
              << aos_time / 1000.0
              << " ms\n";

    std::cout << "SoA: "
              << soa_time / 1000.0
              << " ms\n";

    // Prevent compiler from considering results unused
    std::cout << "\nCheck:\n";
    std::cout << "AoS[0]: "
              << aos[0].x << ", "
              << aos[0].y << ", "
              << aos[0].z << '\n';

    std::cout << "SoA[0]: "
              << soa.x[0] << ", "
              << soa.y[0] << ", "
              << soa.z[0] << '\n';

    return 0;
}
