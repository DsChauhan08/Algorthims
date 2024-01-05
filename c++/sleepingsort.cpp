// this is just a joke algorthim made famous by user on 4chan and has no good use and just for fun 
#include <iostream>
#include <thread>
#include <vector>

// Function to perform sleep sort
void sleepSort(int num) {
    // Sleep for 'num' milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(num));
    
    // Print the sorted element after sleeping
    std::cout << num << " ";
}

int main() {
    // Vector to store input numbers
    std::vector<int> numbers;

    // Read numbers from command line arguments
    for (int i = 1; i < argc; ++i) {
        numbers.push_back(std::stoi(argv[i]));
    }

    // Create threads for each number
    std::vector<std::thread> threads;
    for (int num : numbers) {
        threads.push_back(std::thread(sleepSort, num));
    }

    // Join threads to wait for their completion
    for (std::thread& t : threads) {
        t.join();
    }

    std::cout << std::endl;
    return 0;
}
