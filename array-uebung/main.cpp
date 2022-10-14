#include <iostream>
#include <chrono>
#include <thread>
int main() {

    auto startTime = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    auto endTime = std::chrono::high_resolution_clock::now();

    auto elapsedDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << elapsedDuration.count() << std::endl;
    return 0;
}
