#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (map[nums[i]] == 1) {
                return nums[i];
            }
        }
        return 0; // Default return if no single number found (not expected in problem statement)
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1};
    cout << sol.singleNumber(nums) << endl; // Output: 1
    return 0;
}


/*
The given C++ code defines a class `Solution` with a public method `singleNumber` that finds a single number in an array (`nums`) that appears only once, while all other numbers appear exactly twice. Here's a breakdown of how the code works:

### Explanation:

1. **Class `Solution`:**
   - Represents a solution class, typically used in competitive programming or algorithm challenges.

2. **Method `singleNumber`:**
   - **Parameters:** Takes a reference to a vector of integers `nums`.
   - **Return Type:** Returns an integer, which is the single number that appears only once in the array.

3. **Algorithm:**
   - **Using `unordered_map`:** An `unordered_map<int, int>` named `map` is used to store the frequency of each number in the array.
   - **First Loop (`for` loop):** Iterates through the `nums` vector and counts the occurrences of each number using `map[nums[i]]++`.
   - **Second Loop (`for` loop):** Iterates through the `nums` vector again and checks the frequency stored in `map`. When it finds a number with a frequency of `1`, it returns that number as it appears only once.
   - **Edge Case Handling:** If no such number is found (although the problem guarantees exactly one number appears once), it returns `0` (assuming a valid input).

4. **Complexity:**
   - The time complexity is `O(n)` where `n` is the size of the `nums` vector, due to the two passes through the vector (one for counting and one for finding the single number).
   - The space complexity is `O(n)` due to the usage of the `unordered_map` to store frequencies of the numbers.


### Notes:

- This solution assumes that the input array `nums` always has exactly one element that appears only once, and all other elements appear exactly twice.
- If the input array could violate this assumption (e.g., no single number appears once), additional error handling might be needed.
- The `unordered_map` provides an efficient way to count occurrences and look up frequencies in constant time on average, making it suitable for this type of frequency-based problem.

This implementation efficiently solves the problem using a hash map to track element frequencies and determines the unique number in linear time.
*/
