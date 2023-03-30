#include <stdio.h>

#include <vector>

using namespace std;

namespace lc {

/* LC: 34 binary_search returns the first index whose value is 
 * closest to the target from the left, note this is different
 * from the way std::lower_bound does. */

int binary_search(vector<int> &nums, int target) {
    if (nums.size() == 0)
        return -1;

    size_t left = 0;
    size_t right = nums.size()-1;

    while (left < right) {
        // left must increase or right must decrease
        int mid = (left + right) / 2;
        if (nums[mid] < target) 
            left = mid + 1;
        else // mid >= target
            right = mid;
    }

    if (nums[left] <= target)
        return left;

    // may return -1
    return left - 1;
   
}

} // end namespace

int main() {
    using namespace lc;            
 
    vector<int> v{1, 2, 3, 6, 7, 8, 9, 13};
    printf("Search 0 => %d\n", binary_search(v, 0));    
    printf("Search 1 => %d\n", binary_search(v, 1));    
    printf("Search 2 => %d\n", binary_search(v, 2));    
    printf("Search 4 => %d\n", binary_search(v, 4));    
    printf("Search 7 => %d\n", binary_search(v, 7));    
    printf("Search 13 => %d\n", binary_search(v, 13));    
    printf("Search 14 => %d\n", binary_search(v, 14));    
}
