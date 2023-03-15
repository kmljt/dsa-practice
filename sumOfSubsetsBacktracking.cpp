#include <bits/stdc++.h>

using namespace std;

void recur(int n) {
    static int SIZE = n;
    static int arr[1001];
    static int k = 0;

    if (n == 0) {
        cout << k++ << ". ";
        for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
        cout << endl;
        return;
    }

    int possibleValues[] = {0, 1};
    for (int i : possibleValues) {
        arr[SIZE-n] = i;
        recur(n-1);
        memset(arr+SIZE-n, 0, n);
    }
}

void recurVec(int n, vector<int> vec) {
    static int SIZE = n;
    static int arr[1001];
    static int k = 0;

    if (n == 0) {
        cout << k++ << ". ";
        for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
        cout << endl;
        return;
    }

    for (int i : vec) {
        arr[SIZE-n] = i;
        recurVec(n-1, vec);
        memset(arr+SIZE-n, 0, n);
    }
}

void recurCharVec(int n, vector<char> vec) {
    static int SIZE = n;
    static char arr[1001];
    static int k = 0;

    if (n == 0) {
        cout << k++ << ". ";
        for (int i = 0; i < SIZE; i++) cout << arr[i] << " ";
        cout << endl;
        return;
    }

    for (int i : vec) {
        arr[SIZE-n] = i;
        recurCharVec(n-1, vec);
        memset(arr+SIZE-n, 0, n);
    }
}

void printSubsets(int* array01, vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << array01[i] << " ";
    }
    cout << ": ";
    int verify = 0;
    for (int i = 0; i < v.size(); i++) {
        if (array01[i] == 1) {
            cout << v[i] << " + ";
            verify += v[i];
        }
    }
    cout << "\b\b= " << verify;

    cout << endl;
}

void sumOfSubsets(int target, int valueTillNow, vector<int> vec, int remainingElements) {
    static int arr[1001];

    if (remainingElements == 0) {
        return;
    }

    int currentElement = vec.size() - remainingElements;

    int possibleValues[] = {0, 1};
    for (int i : possibleValues) {
        arr[currentElement] = i;
        if ((i == 1) && ((vec[currentElement] + valueTillNow) == target)) printSubsets(arr, vec);
        sumOfSubsets(target, ((vec[currentElement] * i) + valueTillNow), vec, remainingElements - 1);
        memset(arr + currentElement, 0, remainingElements);
    }
}

int main() {
    // recur(13);

    // vector<char> alphabet;
    // for (char i = 'A'; i <= 'Z'; i++) alphabet.push_back(i);
    // recurCharVec(3, alphabet);

    vector<int> v = {5, 10, 12, 13, 15, 18, -2, -6, -10};
    int n = 29;

    sumOfSubsets(n, 0, v, v.size());
}
