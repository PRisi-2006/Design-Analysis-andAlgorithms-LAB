#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int temp[10], i = l, j = m + 1, k = 0;

    while(i <= m && j <= r)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= m)
        temp[k++] = a[i++];

    while(j <= r)
        temp[k++] = a[j++];

    for(i = 0; i < k; i++)
        a[l + i] = temp[i];
}

void mergesort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int a[5] = {14, 21, 35, 12, 23};

    mergesort(a, 0, 4);

    for(int i = 0; i < 5; i++)
        cout << a[i] << " ";

    return 0;
}