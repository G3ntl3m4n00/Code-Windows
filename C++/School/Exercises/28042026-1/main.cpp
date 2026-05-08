#include <iostream>
#include <fstream>

struct interval {
    float beg;
    float end;
    float length;
} main_interval[50];

int num_of_intervals;

void readFromFile() {
    std::ifstream input_file("interval.in");

    input_file >> num_of_intervals;

    for (int i = 0; i < num_of_intervals; i++) {
        input_file >> main_interval[i].beg >> main_interval[i].end;
    }
}

void intervalToConsole(interval current) {
    std::cout << "[" << current.beg << ", "  << current.end << "]\n";
}

void intervalsToConsole(interval current[]) {
   for (int i = 0; i < num_of_intervals; i++) {
      std::cout << i + 1 << ": ";
       intervalToConsole(current[i]);
   }
}

void lengthOfIntervals(interval current[]) {
   for (int i = 0; i < num_of_intervals; i++) {
       current[i].length = current[i].end - current[i].beg;
       std::cout << i+1 << ": " << current[i].end - current[i].beg << "\n";
   }
}

void toHeap(interval current[], int n, int i) {
    int big = i;

    const int left = 2*i + 1, right = 2*i + 2;

    if (left < n && current[big].length > current[left].length)
        big = left;
    if (right < n && current[big].length > current[right].length)
        big = right;

    if (big != i) {
        std::swap(current[big], current[i]);
        toHeap(current, n, big);
    }
}

void toHeapBeg(interval current[], int n, int i) {
    int big = i;

    const int left = 2*i + 1, right = 2*i + 2;

    if (left < n && current[big].beg < current[left].beg)
        big = left;
    if (right < n && current[big].beg < current[right].beg)
        big = right;

    if (big != i) {
        std::swap(current[big], current[i]);
        toHeapBeg(current, n, big);
    }
}

void heapSort(interval current[], int n) {
    for (int i = n/2-1; i >= 0; i--)
        toHeap(current, n, i);
    for (int i = n -1; i > 0; i--) {
        std::swap(current[0], current[i]);
        toHeap(current, i, 0);
    }
}

void heapSortBeg(interval current[], int n) {
    for (int i = n/2-1; i >= 0; i--)
        toHeapBeg(current, n, i);
    for (int i = n -1; i > 0; i--) {
        std::swap(current[0], current[i]);
        toHeapBeg(current, i, 0);
    }
}

int numOfGivenNumberInIntervals(int n) {

    int num = 0;

    for (int i = 0 ; i < num_of_intervals; i++) {
       if (n < main_interval[i].end && n > main_interval[i].beg)
           num ++;
    }
    return num;
}

int main() {
    readFromFile();
    intervalsToConsole(main_interval);
    lengthOfIntervals(main_interval);

    heapSort(main_interval, num_of_intervals);
    intervalsToConsole(main_interval);
    heapSortBeg(main_interval, num_of_intervals);
    intervalsToConsole(main_interval);

    float n;
    std::cout << "Give a real number: ";
    std::cin >> n;
    std::cout << "Number of the given number occurred in the intervals: " << numOfGivenNumberInIntervals(n) << std::endl;

}