#include <stdio.h>
#include <stdlib.h>

int mergeAndCount(int arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int count = 0;
    int i;

    int size = high - low + 1;
    int *temp = (int *)malloc(size * sizeof(int));
    int t = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[t++] = arr[left];
            left++;
        }
        // right is smaller (what we need)
        else
        {
            temp[t++] = arr[right];
            count += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid)
    {
        temp[t++] = arr[left];
        left++;
    }

    while (right <= high)
    {
        temp[t++] = arr[right];
        right++;
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    free(temp);

    return count;
}

int divide(int arr[], int low, int high)
{
    if (low >= high)
        return 0;

    int count = 0;
    int mid = (low + high) / 2;

    count += divide(arr, low, mid);
    count += divide(arr, mid + 1, high);

    count += mergeAndCount(arr, low, mid, high);

    return count;
}

int inversionCount(int arr[], int n)
{
    return divide(arr, 0, n - 1);
}


int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = inversionCount(arr, n);
    printf("Number of inversions: %d\n", result);

    return 0;
}