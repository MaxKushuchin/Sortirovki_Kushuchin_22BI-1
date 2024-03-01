#include <iostream>
#include <ctime>



void BubbleSort(int array[], int length)
{
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (array[j] > array[j + 1])
				std::swap(array[j], array[j + 1]);
		}
	}
}



int main()
{

	srand(time(0));

	std::cout << "Enter the length of the array: ";
	int len;
	std::cin >> len;
	int* arr = new int[len];

	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 1000 + 1;
	}

	unsigned int start_time = clock();
	BubbleSort(arr, len);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	std::cout << "Time to perform a bubble sort on an array of " << len << " elements: " << search_time << " ms" << std::endl;

	delete[] arr;
	return 0;

}
