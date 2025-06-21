// Binary Search

#include <iostream>
#include <vector>
using namespace std;

// Function for binary serach
int binary_search(vector<int> &a, int target)
{
    int start = 0;
    int end = a.size() - 1;

    // check start less than or equal to end
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
// Function for Display
void Display(vector<int> &a)
{
    cout << "Vector is: ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a.at(i) << " ";
    }
    cout << endl;
}
int main()
{
    int n, element, target, result;
    cout << "Enter size of vector: ";
    cin >> n;

    vector<int> a;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element at a[" << i << "]: ";
        cin >> element;
        a.push_back(element);
    }
    Display(a);

    cout << "Enter target element: ";
    cin >> target;

    // binary search result store in result variable
    result = binary_search(a, target);

    // check result not equal to -1
    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
    return 0;
}