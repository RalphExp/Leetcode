#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

namespace lc {

void quick_sort(vector<int> &v, int beg, int end) {  // [beg, end]
    if (beg >= end)
        return;

    // now v has at least 2 elements
    int i = beg;
    int j = beg;

    do {
        if (v[++j] <= v[beg]) {
            swap(v[++i], v[j]);
        }
    } while (j < end);

    swap(v[beg], v[i]);
    quick_sort(v, beg, i-1);
    quick_sort(v, i+1, end);
}

void quick_sort(vector<int> &v) {
    quick_sort(v, 0, v.size()-1);
}

void print_vector(vector<int> &v) {
    size_t i = 0;
    for (; i < v.size()-1; ++i) 
        printf("%d, ", v[i]); 

    printf("%d\n", v[i]);
}

} // namespace lc

int main() {
    using namespace lc;
    vector<int> v{1,2,3,4,5,6,7};
    quick_sort(v);    
    print_vector(v);

    v = vector<int>{2, 5, 6, 7, 1, 3, 4};
    quick_sort(v);    
    print_vector(v);

    v = vector<int>{7, 6, 5, 4, 3, 2, 1};
    quick_sort(v);    
    print_vector(v);
}
