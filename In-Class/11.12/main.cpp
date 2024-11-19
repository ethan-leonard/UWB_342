#include <iostream>
#include <vector>

/* int* mergeSort(int* arr1, int* arr2, int length) {

    int* arr3 = new int[length];

    for (int i = 0; i <= length; i++) {

        if (arr1[i] < arr2[i]) {
            arr3[i] = arr1[i];
        } else {
            arr3[i] = arr2[i];
        }
    } return arr3;
} */
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

void mergeSort(std::vector<int>& vec, int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(vec, first, mid);
        mergeSort(vec, mid+1, last);
        merge(vec, first, mid, last);
    }
}

void quickSort(std::vector<int>& vec, int first, int last) {
    if (last - first < 4) {
        mergeSort(vec, first, last);
        return;
    }

    int mid = (first + last) / 2;

    if (vec[first], vec[last]) {
        std::swap(vec[first], vec[last]);
    } if (vec[first] > vec[mid]) {
        std::swap(vec[first], vec[last]);
    } else if (vec[mid > vec[last]]) {
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
            quickSort(vec, first, left - 1);
            quickSort(vec, left + 1, last);
            done = true;
        }
    }

}

void shellSort(std::vector<int>& vec) {
    int size = vec.size();
    for (int gap = size /2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i += 1) {
            int tmp = vec[i];
            int j;
            for (j = i; j >= gap && vec[j - gap] > tmp; j -= gap) {
                vec[j] = vec[j - gap];
            }
            vec[j] = tmp;
        }
    }
}

void countSort(std::vector<int>& vec, int exp) {
    int n = vec.size();
    std::vector<int> output(n);
    int count[10] = {0}; // Count Array

    for (int i = 0; i < n; i++) {
        int digit = (vec[i] / exp);
    }
}

int main() {

    int arr1[] = {10, 11, 15, 20, 30};
    int arr2[] = {5, 12, 17, 40, 50};

    int length = sizeof(arr1);

    std::vector<int> my_vec = {81, 87, 90, 91, 96, 109, 11, 4, 12, 43};

    shellSort(my_vec);

    std::cout << "Shell Sorted Array: ";
    for (int i = 0; i < my_vec.size(); i++) {
        std::cout << my_vec[i] << " ";
    }
    std::cout << std::endl;

}