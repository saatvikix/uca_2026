#include <iostream>
#include <vector>
using namespace std;

int getNumber(vector<int> &arr) {

    int ans = 0;

    for(int x : arr) {
        ans ^= x;
    }

    return ans;
}

int main() {

    vector<int> arr1 = {1, 3, 5, 1, 5, 1, 3};
    vector<int> arr2 = {2, 2, 3, 3, 4, 4, 4};

    cout<<getNumber(arr1)<<endl;
    cout<<getNumber(arr2)<<endl;
}
