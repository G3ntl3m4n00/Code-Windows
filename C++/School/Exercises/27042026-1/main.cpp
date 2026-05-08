#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

std::vector<int> arr;
int numOfElements;

void generateRandomArr() {
    std::cout << "Num of elements in the array: ";
    std::cin >> numOfElements;

    arr.resize(numOfElements + 1);

    srand(time(nullptr));

    for (int i = 0; i < numOfElements; i++) {
        arr[i] = rand()%101;
    }
}

void writeOut() {
    for (int i = 0; i < numOfElements; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


void toHeap(std::vector<int> currentArr, const int num_of_elements, int i) {
    int big = i;
    const int left = 2*i + 1, right = 2*i + 2;

    if (left < num_of_elements && currentArr[big] < currentArr[left])
        big = left;

    if (right < num_of_elements && currentArr[big] < currentArr[right])
        big = right;

    if (big != i) {
        std::swap(currentArr[big], currentArr[i]);
        toHeap(currentArr, num_of_elements, big);
    }
}

void heapSort(std::vector<int> &currentArr, int num_of_elements) {
    for (int i = num_of_elements / 2 - 1; i>= 0; i--)
        toHeap(currentArr,num_of_elements,i);
    for (int i = num_of_elements-1; i > 0; i--) {
        std::swap(currentArr[0], currentArr[i]);
        toHeap(currentArr, i , 0);
    }
}

int main() {
    generateRandomArr();
    writeOut();

    heapSort(arr, numOfElements);
    writeOut();

}