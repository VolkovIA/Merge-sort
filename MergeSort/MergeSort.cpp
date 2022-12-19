#include <iostream>
// Merge sort

void Merge(int* arr, int first, int mid, int last)
{
	int left_start, right_start, j;
	int* tmp = new int[last + 1];
	left_start = first; // start of left part
	right_start = mid + 1; // start of right part

	for (j = first; j <= last; j++) // write sorted data to the temp array
	{
		if ((left_start <= mid) && ((right_start > last) || (arr[left_start] < arr[right_start])))
		{
			tmp[j] = arr[left_start];
			++left_start;
		}
		else
		{
			tmp[j] = arr[right_start];
			++right_start;
		}
	}

	// writing sorted data to the input array
	for (j = first; j <= last; j++)
	{
		arr[j] = tmp[j];
	}
	delete[]tmp;
};

void MergeSort(int* A, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2; // dividing an array into left and right parts

		MergeSort(A, first, mid); // sorting the left part
		MergeSort(A, mid + 1, last); // sorting the right part
		Merge(A, first, mid, last); // merging parts
	}
};

void sum(int* arr)
{
	arr[0] += arr[0];
}

int main()
{
	setlocale(LC_ALL, "ru");
	int arr[]{ 34, 65, 89, 0, 1, 3, 10, 12, 11, 4, 99, 78, 77, 45 };
	std::cout << "Input array: ";
	for (int i = 0; i < 14; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << '\n';

	MergeSort(arr, 0, 13);

	std::cout << "Sorted array: ";
	for (int i = 0; i < 14; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << '\n';

	return 0;
}