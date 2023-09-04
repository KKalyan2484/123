#include <iostream>

class SubsetSumSolver {
private:
    int* set;
    int* subset;
    int n;
    int targetSum;

public:
    SubsetSumSolver(int arr[], int size, int sum) {
        set = new int[size];
        subset = new int[size];
        n = size;
        targetSum = sum;

        for (int i = 0; i < size; i++) {
            set[i] = arr[i];
            subset[i] = 0;
        }
    }

    ~SubsetSumSolver() {
        delete[] set;
        delete[] subset;
    }

    void printSubsetSums(int i, int currentSum) {
        if (currentSum == targetSum) {
            for (int j = 0; j < i; j++) {
                std::cout << subset[j] << " ";
            }
            std::cout << std::endl;
        }

        if (i == n || currentSum >= targetSum) {
            return;
        }

        subset[i] = set[i];
        printSubsetSums(i + 1, currentSum + set[i]);

        // Exclude the current element
        subset[i] = 0;
        printSubsetSums(i + 1, currentSum);
    }

    void findSubsetSums() {
        printSubsetSums(0, 0);
    }
};

int main() {
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    SubsetSumSolver solver(set, n, sum);
    solver.findSubsetSums();

    return 0;
}
