#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {9, 3, 4, 1, 5, 6, 17, 7, 2, 10};
    int l = sizeof(arr)/sizeof(arr[0]);
    int temp;

    for(int j=0; j<l-1; j++)
    {
        for(int i=0; i<l-1-j; i++)
        {
            if(arr[i] > arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

    for(int i=0; i<l; i++)
        cout << arr[i] << " ";

    cout << "\n";

}