/*Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
 

Constraints:

1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you search for the kth element.
*/

// sloution : 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    // Constructor that initializes the class with the k value and the initial numbers
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            if (minHeap.size() < k) {
                minHeap.push(num);  // Push the element if the heap has fewer than k elements
            } else if (num > minHeap.top()) {
                minHeap.push(num);  // Push the element if it's larger than the smallest element in the heap
                if (minHeap.size() > k) {
                    minHeap.pop();  // Pop the smallest element to maintain the heap size at k
                }
            }
        }
    }

    // Method to add a new element and return the kth largest element
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);  // Push the element if the heap has fewer than k elements
        } else if (val > minHeap.top()) {
            minHeap.push(val);  // Push the element if it's larger than the smallest element in the heap
            minHeap.pop();  // Pop the smallest element to maintain the heap size at k
        }
        return minHeap.top();  // Return the kth largest element, which is the smallest in the heap
    }

private:
    int k;  // The kth largest element to maintain
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap to store the k largest elements
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    KthLargest kthLargest(k, nums);
    
    cout << kthLargest.add(3) << endl;  // returns 4
    cout << kthLargest.add(5) << endl;  // returns 5
    cout << kthLargest.add(10) << endl; // returns 5
    cout << kthLargest.add(9) << endl;  // returns 8
    cout << kthLargest.add(4) << endl;  // returns 8

    return 0;
}
