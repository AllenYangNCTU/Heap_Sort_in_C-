#include <iostream>
#include <vector>
using namespace std;
void swap(int &t1, int &t2)
{
    int temp = t1;
    t1 = t2;
    t2 = temp;
}

void MaxHeapify(vector<int> &array, int root, int length)
{

    int left = 2 * root,
        right = 2 * root + 1,
        largest;

    if (left <= length && array[left] > array[root])
        largest = left;
    else
        largest = root;

    if (right <= length && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap(array[largest], array[root]);
        MaxHeapify(array, largest, length);
    }
}

void BuildMaxHeap(vector<int> &array)
{

    for (int i = (int)array.size() / 2; i >= 1; i--)
    {
        MaxHeapify(array, i, (int)array.size() - 1);
    }
}

void HeapSort(vector<int> &array)
{

    array.insert(array.begin(), 0);

    BuildMaxHeap(array);

    int size = (int)array.size() - 1;
    for (int i = (int)array.size() - 1; i >= 2; i--)
    {
        swap(array[1], array[i]);
        size--;
        MaxHeapify(array, 1, size);
    }

    array.erase(array.begin());
}

void PrintArray(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[100] = {67,29,56,65,5,23,79,100,84,4,8,40,61,27,53,32,74,63,34,17,6,43,85,9,36,46,97,57,19,81,76,64,48,92,2,11,50,71,13,33,31,99,14,98,86,16,89,77,94,58,35,42,55,1,47,60,41,70,75,80,15,82,62,22,39,87,78,21,52,44,30,95,73,24,18,72,28,93,54,66,59,12,45,49,91,7,88,20,26,96,90,69,25,83,68,3,51,10,37,38};
    vector<int> array(arr, arr + sizeof(arr) / sizeof(int));

    cout << "original:\n";
    PrintArray(array);

    HeapSort(array);

    cout << "sorted:\n";
    PrintArray(array);

    return 0;
}
