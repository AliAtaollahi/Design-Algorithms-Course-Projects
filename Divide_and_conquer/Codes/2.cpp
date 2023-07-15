#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int sum;

void count_smaller_right_side(int arr[], int left, int right){
    if(left == right) return;
    int mid = (left + right) / 2;
    count_smaller_right_side(arr,left,mid);
    count_smaller_right_side(arr,mid + 1,right);

    int left_head = left;
    int right_head = mid + 1;
    while (left_head <= mid && right_head <= right) {
        if (arr[left_head] > 2 * arr[right_head]){
            sum += mid - left_head + 1;
            right_head++;
        }
        else left_head++;
    }

    int res[right - left + 1];

    left_head = left;
    right_head = mid + 1;
    int start_point = 0;

    while (left_head <= mid && right_head <= right)
        res[start_point++] = (arr[left_head] <= arr[right_head]) ? 
                              arr[left_head++] : 
                              arr[right_head++];

    while (left_head <= mid)
        res[start_point++] = arr[left_head++];

    while (right_head <= right)
        res[start_point++] = arr[right_head++];

    int index = 0;
    for (int i = left; i <= right; i++)
        arr[i] = res[index++];
}

int main(){
    int temp;
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++){
        cin >> temp;
        arr[i] = temp;
    }
    sum = 0;
    count_smaller_right_side(arr, 0, num - 1);
    cout << sum;
}
