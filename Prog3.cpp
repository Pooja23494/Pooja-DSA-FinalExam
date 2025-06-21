// Merge and Quick Sort

#include <iostream>
#include <vector>
using namespace std;

class Sorting
{
public:
    // Function to Merge element
    void merge(vector<int> &a, int start, int mid, int end)
    {
        vector<int> temp;
        int i = start, j = mid + 1;
        while (i <= mid && j <= end)
        {
            if (a[j] > a[i])
            {
                temp.push_back(a[i++]);
            }
            else
            {
                temp.push_back(a[j++]);
            }
        }
        while (i <= mid)
        {
            temp.push_back(a[i++]);
        }
        while (j <= end)
        {
            temp.push_back(a[j++]);
        }
        for (int k = 0; k < temp.size(); k++)
        {
            a[start + k] = temp[k];
        }
    }
    // Function for Divide and Sort
    void merge_sort(vector<int> &a, int start, int end)
    {
        if (start >= end)
            return;

        int mid = start + (end - start) / 2;
        merge_sort(a, start, mid);
        merge_sort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
    // function for Partition
    int partition(vector<int> &a, int start, int end)
    {
        int pivot = a[end];
        int i = start - 1;
        for (int j = start; j < end; j++)
        {
            if (a[j] < pivot)
            {
                swap(a[++i], a[j]);
            }
        }
        swap(a[++i], a[end]);
        return i;
    }
    // Function for Quick sort
    void quick_sort(vector<int> &a, int start, int end)
    {
        if (start >= end)
            return;

        int pivotIndex = partition(a, start, end);
        quick_sort(a, start, pivotIndex - 1);
        quick_sort(a, pivotIndex + 1, end);
    }
    // Function for Display
    void display(vector<int> &a, int n)
    {
        cout << "Vector is: ";
        for (int i = 0; i < n; i++)
        {
            cout << a.at(i) << " ";
        }
        cout << endl;
    }
};
int main()
{

    Sorting sort;
    int n, choice, element;
    vector<int> a;

    do
    {
        cout << endl;
        cout << "Enter 1 for Create Vector" << endl;
        cout << "Enter 2 for Merge Sort" << endl;
        cout << "Enter 3 for Quick Sort" << endl;
        cout << "Enter 4 for clear vector" << endl;
        cout << "Enter 0 for Exit." << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter size of vector: ";
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                cout << "Enter element at a[" << i << "]: ";
                cin >> element;
                a.push_back(element);
            }
            sort.display(a, n);
            break;
        case 2:
            sort.merge_sort(a, 0, n - 1);
            cout << "Sorted ";
            sort.display(a, n);
            break;
        case 3:
            sort.quick_sort(a, 0, n - 1);
            cout << "Sorted ";
            sort.display(a, n);
            break;
        case 4:
            a.clear();
            cout << "Vector clear successfully.." << endl;
            break;
        case 0:
            cout << "Exit Program" << endl;
            break;
        default:
            cout << "Wrong choice!" << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}