#include <iostream>

using namespace std;

void print_array(int *, int);
void bubble_sort(int *, int);

int main()
{
    int size;
    cout << "Enter Array Size: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Item #" << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Array: ";
    print_array(arr, size);
    bubble_sort(arr, size);
    cout << "Sorted Array: ";
    print_array(arr, size);
    return 0;
}

void print_array(int *arr, int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i != size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
}

void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
