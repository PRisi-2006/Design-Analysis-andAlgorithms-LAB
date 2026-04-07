#include <iostream>
using namespace std;

int n, target;
int arr[100];

void subsetSum(int index, int current, int subset[], int size) {
    if (current == target) {
        cout << "Subset found: { ";
        for (int i = 0; i < size; i++)
            cout << subset[i] << " ";
        cout << "}" << endl;
        return;
    }

    if (index == n || current > target)
        return;

    // Include current element
    subset[size] = arr[index];
    subsetSum(index + 1, current + arr[index], subset, size + 1);

    // Exclude current element
    subsetSum(index + 1, current, subset, size);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    int subset[100];

    cout << "\nSubsets with sum " << target << ":\n";
    subsetSum(0, 0, subset, 0);

    return 0;
}