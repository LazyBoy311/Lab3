#include "compSort.h"

void count_merge(int a[], int first, int mid, int last, long long& cnt)
{
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1 && ++cnt; i++)
		L[i] = a[first + i];
	for (int j = 0; j < n2 && ++cnt; j++)
		R[j] = a[mid + j + 1];
	int i = 0;
	int j = 0;
	int k = first;
	while (i < n1 && j < n2) {
		cnt += 3;
		a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
	}
	while (j < n2 && ++cnt)
		a[k++] = R[j++];
	while (i < n1 && ++cnt)
		a[k++] = L[i++];
	delete[] L;
	delete[] R;
}
void count_mergeSort(int a[], int first, int last, long long& cnt)
{
	if (first < last && ++cnt)
	{
		int mid = first + (last - first) / 2;
		count_mergeSort(a, first, mid, cnt);
		count_mergeSort(a, mid + 1, last, cnt);
		count_merge(a, first, mid, last, cnt);
	}
}
long long mergeSortComp(int a[], int first, int last) {
	long long b = 0;
	count_mergeSort(a, first, last, b);
	return b;
}

long long radixSortComp(int a[], int n)
{
	long long cntcmp = 0;
	int* b = new int[n];
	int m = a[0], exp = 1;

	for (int i = 0; i < n && ++cntcmp; i++)
		if (a[i] > m && ++cntcmp)
			m = a[i];
	while (m / exp > 0 && ++cntcmp)
	{

		int bucket[10] = { 0 };
		for (int i = 0; i < n && ++cntcmp; i++)
			bucket[a[i] / exp % 10]++;
		for (int i = 1; i < 10 && ++cntcmp; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; i >= 0 && ++cntcmp; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (int i = 0; i < n && ++cntcmp; i++)
			a[i] = b[i];
		exp *= 10;
	}
	delete[] b;
	return cntcmp;
}

long long shellSortComp(int a[], int n)
{
	long long cntcmp = 0;
	for (int interval = n / 2; interval > 0 && ++cntcmp; interval /= 2)
		for (int i = interval; i < n && ++cntcmp; i++)
		{
			int temp = a[i];
			int j = i;
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
				cntcmp += 2;
			}
			a[j] = temp;
		}
	return cntcmp;
}

void insertion_sort(int a[], int n, long long& cntcmp)
{
	for (int i = 1; i < n && ++cntcmp; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			cntcmp += 2;
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}

long long flashSortComp(int a[], int n)
{
	long long cntcmp = 0;
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m && ++cntcmp; i++)
		l[i] = 0;
	for (int i = 1; i < n && ++cntcmp; i++)
	{
		if (a[i] < minVal && ++cntcmp)
			minVal = a[i];
		if (a[i] > a[max] && ++ cntcmp)
			max = i;
	}
	if (a[max] == minVal && ++cntcmp)
		return 0;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n && ++cntcmp; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m && ++cntcmp; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		++cntcmp;
		while (j > l[k] - 1)
		{
			++cntcmp;
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0 && ++cntcmp) break;
		while (j != l[k])
		{
			++cntcmp;
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertion_sort(a, n, cntcmp);
	return cntcmp;
}

long long bubbleSortComp(int a[], int n)
{
	if (n == 1)
		return 0;
	long long cntcmp = 0;
	int i = n - 1;
	while (++cntcmp && i >= 0)
	{
		bool swapped = false;
		//day max ve cuoi mang
		int j = 0;
		while (++cntcmp && j < i)
		{
			if (++cntcmp && a[j] > a[j + 1])
			{
				swapped = true;
				swap(a[j], a[j + 1]);
			}
			j++;
		}
		if (++cntcmp && !swapped)
			return cntcmp;
		else return 0;
		i--;
	}
	return 0;
}

long long shakerSortComp(int a[], int n)
{
	long long cntcmp = 0;
	if (n == 1)
		return 0;
	int left = 0;
	int right = n - 1;
	int k = 0;
	int i = left;
	while (++cntcmp && i <= right)
	{
		bool swapped = false;
		//day max ve cuoi mang
		int j = left;
		while (++cntcmp && j < right)
		{
			if (++cntcmp && a[j] > a[j + 1])
			{
				swapped = true;
				swap(a[j], a[j + 1]);
				k = j;
			}
			j++;
		}
		if (++cntcmp && !swapped)
			return cntcmp;
		right = k;
		//day min ve dau mang
		swapped = false;
		int t = right;
		while (++cntcmp && t > left)
		{
			if (++cntcmp && a[t] < a[t - 1])
			{
				swapped = true;
				swap(a[t], a[t - 1]);
				k = t;
			}
			t--;
		}
		if (++cntcmp && !swapped)
			return cntcmp;
		left = k;
		i++;
		return 0;
	}
	return 0;
}


long long countingSortComp(int a[], int n)
{

	if (n == 1)
		return 0;
	long long cntcmp = 0;
	int max = a[0];
	int i = 1;
	while (++cntcmp && i < n)
	{
		if (++cntcmp && a[i] > max)
			max = a[i];
		i++;
	}

	int* count = new int[max + 1];
	i = 0;
	while (++cntcmp && i <= max)
	{
		count[i] = 0;
		i++;
	}

	i = 0;
	while (++cntcmp && i < n)
	{
		count[a[i]]++;
		i++;
	}

	i = 1;
	while (++cntcmp && i <= max)
	{
		count[i] += count[i - 1];
		i++;
	}

	int* temp = new int[n];
	i = 0;
	while (++cntcmp && i < n)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
		i++;
	}

	i = 0;
	while (++cntcmp && i < n)
	{
		a[i] = temp[i];
		i++;
	}
	delete[] count;
	delete[] temp;
	return cntcmp;
}
long long selectionSortComp(int a[], int n)
{
	long long numComps = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int lowest = i;
		for (int j = i + 1; j < n && numComps++; j++)
			if (a[j] < a[lowest] && numComps++)
				lowest = j;
		HoanVi(a[i], a[lowest]);
	}
	return numComps;
}

long long insertionSortComp(int a[], int n)
{
	long long cnt_comp = 0;
	for (int i = 1; ++cnt_comp && i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			cnt_comp += 2;
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
	return cnt_comp;
}

int partition_cnt(int a[], int first, int last, long long& cnt_comp)
{
	int pivot = a[(first + last) / 2];
	int i = first;
	int j = last;
	int tmp;
	while (++cnt_comp && i <= j)
	{
		while (++cnt_comp && a[i] < pivot)
			i++;
		while (++cnt_comp && a[j] > pivot)
			j--;
		if (++cnt_comp && i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	return i;
}

void quickSort_cnt(int a[], int first, int last, long long& cnt_comp)
{
	int index = partition_cnt(a, first, last, cnt_comp);
	if (++cnt_comp && first < index - 1)
		quickSort_cnt(a, first, index - 1, cnt_comp);
	if (++cnt_comp && index < last)
		quickSort_cnt(a, index, last, cnt_comp);
}
long long quickSortComp(int a[], int first, int last) {
	long long cnt_comp = 0;
	quickSort_cnt(a, first, last, cnt_comp);
	return cnt_comp;
}
void heapRebuild_cnt(int a[], int pos, int n,long long& cnt_comp)
{

	while (++cnt_comp && 2 * pos + 1 < n)
	{
		int j = 2 * pos + 1;
		if (++cnt_comp && j < n - 1)
			if (++cnt_comp && a[j] < a[j + 1])
				j = j + 1;
		if (++cnt_comp && a[pos] >= a[j])
			return;
		HoanVi(a[pos], a[j]);
		pos = j;
	}
}
void heapConstruct_cnt(int a[], int n, long long& cnt_comp)
{
	for (int i = (n - 1) / 2; ++cnt_comp && i >= 0; i--)
		heapRebuild_cnt(a, i, n, cnt_comp);
}
long long heapSortComp(int a[], int n)
{
	long long cnt_comp = 0;
	heapConstruct_cnt(a, n, cnt_comp);
	int r = n - 1;
	while (++cnt_comp && r > 0)
	{
		HoanVi(a[0], a[r]);
		heapRebuild_cnt(a, 0, r, cnt_comp);
		r--;
	}
	return cnt_comp;
}
