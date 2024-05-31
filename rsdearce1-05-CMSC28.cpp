#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

// FUNCTION PROTOTYPES 
void displayInfos(); //Added function
int getValues(int *array) ;
int getLargest(int* array, int length);
int getSmallest(int* array, int length);
int getAverage(int* array, int length);
float getStandardDeviation(int* array, float mean, int length);
float getVariance(int* array, float mean, int length);
void printValues(int large, int small, float mean, float std, float var);

// MAIN FUNCTION 
int main() {
    // Variable delcarations 
    int arr[10], size, Largest, Smallest;
    float Average, Standard_deviation, Variance;

    // Function calls 
    displayInfos();
    size = getValues(arr);
    Largest = getLargest(arr, size);
    Smallest = getSmallest(arr, size);
    Average = getAverage(arr, size);
    Standard_deviation = getStandardDeviation(arr, Average, size);
    Variance = getVariance(arr, Average, size);
    printValues(Largest, Smallest, Average,  Standard_deviation, Variance);
    
    return 0;
}

// FUNCTION DEFINITIONS 

//Display programmer and the program description
void displayInfos(){
    cout << "Programming Exercise 05" << endl;
    cout << "Submitted by:  Richelle S. de Arce" << endl  << endl;
    cout << "This program will ask the user to input various numbers" << endl; 
    cout << "(positive or negative but not zero) and perform basic" << endl; 
    cout << "statistics on these numbers." << endl << endl;   
}

// Function to get values from the user and store them in the array
int getValues(int *array) {
    // Variable declaration
    int i = 0;
    int temp = -1;

    // Loop until the array is full
    while (i < 10) {
        cout << "Input an integer: ";

        // Putting the values in the temporary variable
        cin >> temp;

        // If the input is 0, exit the loop
        if (temp == 0) {
            cout << endl << "Inputting values terminated" << endl << endl;

            if (i == 0) {
                cout << "Array is empty" << endl << endl;
            }
            return i;
        }

        // Putting the values in the array
        array[i] = temp;

        // Increment the index
        i++;
    }
    cout << "Array is full" << endl << endl;
    return i;
}

// Function to find the largest element in the array
int getLargest(int* array, int length) {
    int largest = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }
    return largest;
}

// Function to find the smallest element in the array
int getSmallest(int* array, int length) {
    int smallest = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }
    return smallest;
}

// Function to calculate the average of the elements in the array
int getAverage(int* array, int length) {
    float sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum / 10;
}

// Function to calculate the standard deviation of the elements in the array
float getStandardDeviation(int* array, float mean, int length) {
    float sum = 0;
    for (int i = 0; i < length; i++) {
        sum += (array[i] - mean) * (array[i] - mean);
    }
    return sqrt(sum / length);
}

// Function to calculate the variance of the elements in the array
float getVariance(int* array, float mean, int length) {
    float sum = 0;
    for (int i = 0; i < length; i++) {
        sum += (array[i] - mean) * (array[i] - mean);
    }
    return sum / length;
}

// Function to print the values calculated
void printValues(int large, int small, float mean, float std, float var) {
    cout << "The largest number is: " << large << endl;
    cout << "The smallest number is: " << small << endl;
    cout << "The average is: "  << mean << endl;
    
    //I used C syntax to adjust the decimal point
    printf ("The standard deviation is: %.2f\n", std);
    printf ("The variance is: %.2f\n",var);
}
