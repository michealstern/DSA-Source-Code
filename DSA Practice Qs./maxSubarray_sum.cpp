//1. Suppose we are given an array: [2, 3, -1, 4, -2, 5, -3].
//2. Initialization:
//   current_sum = 2
//   max_sum = 2
//3. Iterate through the array:
//   Element 2: current_sum = 2, max_sum = 2
//   Element 3:
//       current_sum = max(3, 2 + 3) = 5
//       max_sum = max(2, 5) = 5
//   Element -1:
//       current_sum = max(-1, 5 + (-1)) = 4
//       max_sum = max(5, 4) = 5
//   Element 4:
//       current_sum = max(4, 4 + 4) = 8
//       max_sum = max(5, 8) = 8
//   Element -2:
//       current_sum = max(-2, 8 + (-2)) = 6
//       max_sum = max(8, 6) = 8
//   Element 5:
//       current_sum = max(5, 6 + 5) = 11
//       max_sum = max(8, 11) = 11
//   Element -3:
//       current_sum = max(-3, 11 + (-3)) = 8
//       max_sum = max(11, 8) = 11
//4. Final Result:
// max_sum = 11

#include <iostream>
#include <vector>
#include <limits.h> // For INT_MIN

using namespace std;

int findMaximumSubarraySum(const vector<int>& arr){
    int max_sum = INT_MIN; // Initialize to the smallest possible integer
    int current_sum = 0;
    
    for (int num : arr) {
        current_sum = max(num, current_sum + num);
        max_sum = max(max_sum, current_sum);
    }
    
    return max_sum;
}

int main() {
    int n;

    // Input size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    // Input array elements
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Find the maximum subarray sum
    int max_sum = findMaximumSubarraySum(arr);

    // Output the result
    cout << "The maximum subarray sum is: " << max_sum << endl;

    return 0;
}
