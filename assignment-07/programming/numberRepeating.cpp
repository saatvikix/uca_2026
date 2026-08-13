#include <iostream>
#include <vector>
using namespace std;

int getNumber(const vector<int>& arr) {
    int ans = 0;

    for (int bit = 0; bit < 32; bit++) {
        int count = 0;

        for (int x : arr) {
            if (x & (1 << bit))
                count++;
        }

        if (count % 3 != 0)
            ans |= (1 << bit);
    }

    return ans;
}

int main() {

    vector<int> arr1 = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};

    cout<<getNumber(arr1)<<endl;
  
}
