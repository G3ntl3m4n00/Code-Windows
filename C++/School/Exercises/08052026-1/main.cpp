#include <iostream>
#include <vector>
#include <fstream>

class Interval {
    double a;
    double b;

public:
    [[nodiscard]] double begin() const {
        return a;
    }

    [[nodiscard]] double end() const {
        return b;
    }

    Interval(double x, double y) {
        a = x;
        b = y;
    }

     [[nodiscard]] bool isInterval() const {
        return a < b;
    }

    void writeToConsole() const {
        if (!isInterval())
            return;
        std::cout << "[" << a << "," << b << "] ";
    }

    [[nodiscard]] double length() const {
        return b-a;
    }

    // [[nodiscard]] Interval intersect(Interval I) const {
    //    return {a > I.a ? a : I.a, b < I.b ? b : I.b};
    // }

};


std::vector<Interval> Intervals;
int length;

void readFromFile() {
    std::ifstream inputFile("intervals.in");

    inputFile >> length;
    for (int i = 0; i < length; i++) {
        double x, y;
        inputFile >> x >> y;

        Intervals.emplace_back(x, y);
    }

}

void writeIntervalArrToConsole() {
    std::cout << "Intervals: " << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << i + 1 << ": ";
        Intervals[i].writeToConsole(); std::cout << std::endl;
    }
}

void lengthOfIntervals() {
    std::cout << "Lengths of intervals: " <<  std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << i + 1 << ": ";
        std::cout << Intervals[i].length() << std::endl;
    }
}

void toHeap(std::vector<Interval>& arr, const int num_of_elements, const int i) {
    int big = i;
    const int right = 2*i + 2;
    const int left = 2*i + 1;

    if (left < num_of_elements && arr[big].begin() > arr[left].begin())
        big = left;

    if (right < num_of_elements && arr[big].begin() > arr[right].begin()) {
        big = right;
    }

    if (big != i) {
        std::swap(arr[big], arr[i]);
        toHeap(arr, num_of_elements, big);
    }

}

void HeapSort(std::vector<Interval>& arr, const int num_of_elements) {
    for (int i = num_of_elements/2 - 1; i >= 0; i--)
        toHeap(arr, num_of_elements, i);

    for (int i = num_of_elements-1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        toHeap(arr,i,0);
    }
}

int main() {
    // const auto A = Interval(3, 5);
    // std::cout << A.isInterval() << std::endl;
    // A.writeToConsole(); std::cout << std::endl;
    // std::cout << "The length of interval: " << A.length() << std::endl;
    //
    // const auto B = Interval(4.2, 23);
    // std::cout << B.isInterval() << std::endl;
    // B.writeToConsole(); std::cout << std::endl;
    // std::cout << "The length of interval: " << B.length() << std::endl;
    //
    //
    // const auto AIB = A.intersect(B);
    // std::cout << AIB.isInterval() << std::endl;
    // AIB.writeToConsole(); std::cout << std::endl;
    // std::cout << "The length of interval: " << AIB.length() << std::endl;
    readFromFile();
    writeIntervalArrToConsole();
    lengthOfIntervals();
    HeapSort(Intervals, length);
    writeIntervalArrToConsole();

}