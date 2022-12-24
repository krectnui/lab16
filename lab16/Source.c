#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int delete_k(double* ptr_arr, int size, double k);
int find_element(double* ptr_array, int n, double element);
double* insert(double* ptr_arr, int* size, int index, int num);
double* arifm(double* arr1, double* arr2, double* arr3, int size);

int main() {
	setlocale(LC_ALL, "RUS");
	// 1
	srand(time(NULL));
	int* ptr_array;
	int arrSize;
	printf("¬ведите размер массива: ");
	scanf("%d", &arrSize);
	ptr_array = (int*)malloc(arrSize * sizeof(int));
	if (ptr_array == NULL) {
		puts("error");
		return -1;
	}
	for (int i = 0; i < arrSize; i++) {
		ptr_array[i] = -100 + rand() % (100 - -100);
		printf("array[%d] = %d\n", i, ptr_array[i]);
	}
	puts("\n\n\n");
	for (int i = 0; i < arrSize; i++) {
		ptr_array[i] *= 2;
		printf("array[%d] = %d\n", i, ptr_array[i]);
	}
	free(ptr_array);

	// 2
	double* ptr_array2;
	int arrSize2;
	printf("¬ведите размер массива: ");
	scanf("%d", &arrSize2);
	ptr_array2 = (double*)malloc(arrSize2 * sizeof(double));
	if (ptr_array2 == NULL) {
		puts("error");
		return -1;
	}
	puts("\n\n\n");
	for (int i = 0; i < arrSize2; i++) {
		ptr_array2[i] = -1 + 1.f * (1 - -1) * rand() / RAND_MAX;
		printf("array[%d] = %lf\n", i, ptr_array2[i]);
	}
	free(ptr_array2);

	// 3
	puts("\n\n\n");
	double* ptr_array3;
	int arrSize3;
	printf("¬ведите размер массива: ");
	scanf("%d", &arrSize3);
	ptr_array3 = (double*)malloc(arrSize3 * sizeof(double));
	if (ptr_array3 == NULL) {
		puts("error");
		return -1;
	}
	for (int i = 0; i < arrSize3; i++) {
		ptr_array3[i] = -1 + 1.f * (1 - -1) * rand() / RAND_MAX;
		printf("array[%d] = %lf\n", i, ptr_array3[i]);
	}
	double max1 = -100000, max2 = -100000;
	for (int i = 0; i < arrSize3; i++) {
		if (ptr_array3[i] > max1) {
			max2 = max1;
			max1 = ptr_array3[i];
		}
	}
	printf("\n\nMax 1 = %lf; Max 2 = %lf", max1, max2);
	delete_k(ptr_array3, arrSize3, max1);
	arrSize3--;
	delete_k(ptr_array3, arrSize3, max2);
	arrSize3--;
	puts("\n\n\n");
	for (int i = 0; i < arrSize3; i++) {
		printf("array[%d] = %lf\n", i, ptr_array3[i]);
	}

	// 4
	double max = -10000;
	for (int i = 0; i < arrSize3; i++) {
		if (ptr_array3[i] > max) {
			max = ptr_array3[i];
		}
	}
	printf("\n\nMax = %lf;\n", max);
	insert(ptr_array3, &arrSize3, find_element(ptr_array3, arrSize3, max), -999);
	for (int i = 0; i < arrSize3; i++) {
		printf("array[%d] = %lf\n", i, ptr_array3[i]);
	}

	// 5
	int size1 = 10 + rand() % 50 - 10;
	int size2 = 10 + rand() % 50 - 10;
	int size3 = 10 + rand() % 50 - 10;
	double* arr1 = (double*)malloc(size1 * sizeof(double));
	double* arr2 = (double*)malloc(size2 * sizeof(double));
	double* arr3 = (double*)malloc(size3 * sizeof(double));
	puts("ARR 1 \n\n ");
	for (int i = 0; i < size1; i++) {
		arr1[i] = -10 + 1.f * (20 - -10) * rand() / RAND_MAX;
		printf("array[%d] = %lf\n", i, arr1[i]);
	}
	puts("ARR 2\n\n");
	for (int i = 0; i < size2; i++) {
		arr2[i] = -10 + 1.f * (20 - -10) * rand() / RAND_MAX;
		printf("array[%d] = %lf\n", i, arr2[i]);
	}
	puts("ARR 3\n\n");
	for (int i = 0; i < size3; i++) {
		arr3[i] = -10 + 1.f * (20 - -10) * rand() / RAND_MAX;
		printf("array[%d] = %lf\n", i, arr3[i]);
	}
	int minSize;
	if (size2 < size1 && size2 < size3) {
		minSize = size2;
	}
	else if (size3 < size2 && size3 < size1) {
		minSize = size3;
	}
	else {
		minSize = size1;
	}
	puts("ARR 4\n\n");
	arifm(arr1, arr2, arr3, minSize);
	return 0;
}

int delete_k(double* ptr_arr, int size, double k) {
	int n = size - 1;
	printf("»ндекс элемента %lf = %d", k, find_element(ptr_arr, size, k));
	for (int i = (find_element(ptr_arr, size, k) - 1); i < (size - 1); i++) ptr_arr[i] = ptr_arr[i + 1];
	return n;
}

int find_element(double* ptr_array, int n, double element) {
	int elementId = -1;
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] == element) {
			elementId = i + 1;
		}
	}
	return elementId;
}

double* insert(double* ptr_arr, int* size, int index, int num) {
	int size_n = (*size) + 1;
	if (ptr_arr == NULL) return NULL;
	double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));
	if (ptr_arr_n == NULL) return ptr_arr;
	ptr_arr = ptr_arr_n;
	for (int i = size_n - 1; i > index; i--)
		ptr_arr[i] = ptr_arr[i - 1];
	ptr_arr[index - 2] = num;
	*size = size_n;
	return ptr_arr;
}

double* arifm(double* arr1, double* arr2, double* arr3, int size) {
	double* arr = (double*)malloc(size * sizeof(double));
	for (int i = 0; i < size; i++) {
		arr[i] = (arr1[i] + arr2[i] + arr3[i]) / 3;
		printf("array[%d] = %lf\n", i, arr[i]);
	}
	return arr;
}