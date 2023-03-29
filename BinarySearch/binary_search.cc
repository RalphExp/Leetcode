
namespace lc {

/* LC: 34 lower bound returns the first index whose value is 
 * closest to the target from the left */

int lowerBound(vector<int> &nums, int target) {
    if (nums.size() == 0)
        return -1;

    size_t left = 0;
    size_t right = nums.size()-1;

    while (left < right) {
        // printf("L = %d, R = %d\n", left, right);
            
        // left will increase every time or right will decrease every time
        int mid = (left + right) / 2;
        if (nums[mid] < target) 
            left = mid + 1;
        else // mid >= target
            right = mid;
    }

    if (nums[left] <= target)
        return left;

    return left - 1;
   
}

} // end namespace

int main() {
	
}
