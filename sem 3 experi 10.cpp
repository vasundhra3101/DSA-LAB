#include <iostream>
using namespace std;
int main() {
int n;
cout << "Enter number of elements: ";
cin >> n;
int arr[n];
cout << "Enter " << n<< " elements: ";
for (int i = 0; i < n;i++) {
cin >> arr[i];
}
// Insertion Sort
for (int i = 1; i < n;i++) {
int key = arr[i]; 
//element to be inserted
int j = i - 1;
// Move elementsgreater than key one stepahead
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
cout << "Sorted array:";
for (int i = 0; i < n;i++) {
cout << arr[i] << " ";
}
cout << endl;
return 0;
}


