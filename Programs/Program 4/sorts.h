#ifndef SORTS_H_
#define SORTS_H_

#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& items, int first, int last) {
    bool swapped;
    for (int i = 0; i < items.size() - 1; i++) {
        swapped = false;
        for (int j = 0; j < items.size() - i - 1; j++) {
            if (items[j] > items[j + 1]) {
                std::swap(items[j], items[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped) {
            break;
        }
    }
}

void InsertionSort(std::vector<int>& items, int first, int last) {
    for (int i = 1; i < items.size(); i++) {
        int key = items[i];
        int j = i - 1;

        while (j >= 0 && items[j] > key) {
            items[j + 1] = items[j];
            j--;
        }
        items[j + 1] = key;
    }
}

void merge(std::vector<int>& vec, int first, int mid, int last) {
    int size = last - first + 1;
    int* tmpArr = new int[size];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = 0;

    while ((first1 <= last1) && (first2 <= last2)) {
        if (vec[first1] < vec[first2]) {
            tmpArr[index] = vec[first1];
            first1++;
        } else {
            tmpArr[index] = vec[first2];
            first2++;
        }
        index++;
    }

    while (first1 <= last1) {
        tmpArr[index] = vec[first1];
        first1++;
        index++;
    }

    while (first2 <= last2) {
        tmpArr[index] = vec[first2];
        first2++;
        index++;
    }

    for (index = 0; index < size; index++) {
        vec[first + index] = tmpArr[index];
    }

    delete[] tmpArr;
}

void MergeSort(std::vector<int>& vec, int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        MergeSort(vec, first, mid);
        MergeSort(vec, mid+1, last);
        merge(vec, first, mid, last);
    }
}

void QuickSort(std::vector<int>& vec, int first, int last) {
    if (last - first < 4) {
        MergeSort(vec, first, last);
        return;
    }

    int mid = (first + last) / 2;

    if (vec[first] > vec[last]) {
        std::swap(vec[first], vec[last]);
    } if (vec[first] > vec[mid]) {
        std::swap(vec[first], vec[mid]);
    } else if (vec[mid] > vec[last]) {
        std::swap(vec[mid], vec[last]);
    }
    
    int pivot = vec[mid];
    std::swap(vec[mid], vec[last-1]);

    int left = first + 1;
    int right = last -2;
    bool done = false;

    while (!done) {
        while (vec[left] < pivot) {
            left++;
        }

        while (vec[right] > pivot) {
            right--;
        }

        if (right > left) {
            std::swap(vec[left], vec[right]);
            right--;
            left++;
        } else {
            std::swap(vec[left], vec[last - 1]);
            QuickSort(vec, first, left - 1);
            QuickSort(vec, left + 1, last);
            done = true;
        }
    }

}

void ShellSort(std::vector<int>& vec, int first, int last) {
    int size = last - first + 1;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = first + gap; i <= last; i++) {
            int tmp = vec[i];
            int j;
            for (j = i; j >= first + gap && vec[j - gap] > tmp; j -= gap) {
                vec[j] = vec[j - gap];
            }
            vec[j] = tmp;
        }
    }
}

void IterativeMergeSort(std::vector<int>& vec, int first, int last) {
    int n = last - first + 1;

    std::vector<int> temp(n);
    
    for (int curr_size = 1; curr_size < n; curr_size = 2 * curr_size) {
        for (int left_start = first; left_start < last; left_start += 2 * curr_size) {
            int mid = std::min(left_start + curr_size - 1, last);
            int right_end = std::min(left_start + 2 * curr_size - 1, last);
            
            int size = right_end - left_start + 1;
            int left = left_start;
            int right = mid + 1;
            int index = 0;

            while (left <= mid && right <= right_end) {
                if (vec[left] <= vec[right]) {
                    temp[index++] = vec[left++];
                } else {
                    temp[index++] = vec[right++];
                }
            }

            while (left <= mid) {
                temp[index++] = vec[left++];
            }

            while (right <= right_end) {
                temp[index++] = vec[right++];
            }

            for (int i = 0; i < size; i++) {
                vec[left_start + i] = temp[i];
            }
        }
    }
}


#endif