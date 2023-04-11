#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {9, 3, 4, 1, 5, 6, 17, 7, 2, 10};
    int l = sizeof(arr)/sizeof(arr[0]);
    int key, j, temp;

    for(int i=1; i<l; i++)
    {
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for(int i=0; i<l; i++)
        cout << arr[i] << " ";
    
}