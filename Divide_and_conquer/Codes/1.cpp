#include <iostream>
using namespace std;

int find_poorest_old_one(int arr[], int start, int end)
{

    if(start == end)
        return start;
    
    // if(start == end - 1)
    //     return (arr[start] < arr[end]) ? start : end; 

    int left, right;
    left = find_poorest_old_one(arr, start, (end + start) / 2);
    right = find_poorest_old_one(arr, ((end + start) / 2) + 1 , end);
    return (arr[right] > arr[left]) ? left : right; 
}

// int decrease_and_conquer(int arr[], int size)
// {
//     if (size == 0)
//         return 0;

//     int index = decrease_and_conquer(arr, size - 1);
//     return (arr[index] < arr[size]) ? index : size;
// }

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int index = find_poorest_old_one(arr, 0, n - 1);
    // int index = decrease_and_conquer(arr, n - 1);
    
    cout << '(' << index << ',' << arr[index] << ')';
    return 0;
}