#include <iostream>
#include <vector>
using namespace std;

void merge(vector<pair<int, int>> &arr, int low, int mid, int high,
           vector<int> &ans)
{

    int left = low;
    int right = mid + 1;

    int rightCount = 0;
    vector<pair<int, int>> temp;

    while (left <= mid && right <= high)
    {

        if (arr[left].first <= arr[right].first)
        {
            ans[arr[left].second] += rightCount;
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            rightCount++;
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        ans[arr[left].second] += rightCount;
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergeSort(vector<pair<int, int>> &arr, int low, int high,
               vector<int> &ans)
{

    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid, ans);
    mergeSort(arr, mid + 1, high, ans);

    merge(arr, low, mid, high, ans);
}

vector<int> countSmaller(vector<int> &nums)
{

    int n = nums.size();

    vector<pair<int, int>> arr;
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
        arr.push_back({nums[i], i});

    mergeSort(arr, 0, n - 1, ans);

    return ans;
}

int main() {

    vector<int> arr = {5,2,6,1};
    vector<int> smallerCounts = countSmaller(arr);

    cout<<"Input Array: ";
    for(int x:arr) {
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"Smaller Counts: ";
    for(int x:smallerCounts) {
        cout<<x<<" ";
    }
    cout<<endl;

}