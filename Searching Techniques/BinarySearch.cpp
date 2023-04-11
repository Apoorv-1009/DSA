#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr)/sizeof(arr[0]);

    int low = 0, high = len-1;
    int mid;
    int x = 7;
    int found = -1;

    while(low != high)
    {
        mid = (low+high)/2;
        if(x == arr[mid])
        {
            cout << "\n Element found at: " << mid+1 << "\n";
            found = 1;
            break;
        } 
        else if(x > arr[mid])
            low = mid+1;

        else    
            high = mid-1;
    }

    if(found == -1)
        cout << "\n Element not found \n";
}