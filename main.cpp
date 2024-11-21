#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Sequential search
int seq_search(vector<int> &keys, int key, int &numCmp) {
    for(int i = 0; i < keys.size(); i++){
        numCmp++;
        if(keys[i] == key){
            return i;
        }
    }

    return -1;
}

// Sequential search with start and stop range
int seq_search(vector<int> &keys, int key, int start, int stop, int &numCmp) {
    for(int i = start; i < stop; i++){
        numCmp++;
        if(keys[i] == key){
            return i;
        }
    }
    return -1;
}

// Binary search
int bin_search(vector<int> &keys, int key, int &numCmp) {
    int low = 0;
    int high = keys.size() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2; 
        numCmp++;
        if (key == keys[mid]) {
            return mid;
        }
        if (key < keys[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// Enhanced binary search: switches to sequential search if remaining range is < 15
int bin2_search(vector<int> &keys, int key, int &numCmp) {
    int low = 0;
    int high = keys.size() - 1;
    int mid;

    while(high - low > 15){
        mid = low + (high - low)/2;
        numCmp++;
        if(key == keys[mid]){
            return mid;
        }
        
        if(key < keys[mid]){
            high = mid - 1;
        }
        else if(key > keys[mid]){
            low = mid +1;
        }
        
    }

    return seq_search(keys, key, low, high, numCmp);

}

// Test the search algorithms
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create a vector of 100,000 integers
    vector<int> num;
    for (int i=0 ; i<100000; i++){
        int iRand = rand() % 10000000;
        num.push_back(iRand);
    }
    cout << "vector generated." << endl;

    // Sort the vector using STL sort
    sort(num.begin(),num.end());
    cout << "vector sorted." << endl;

    // Generate 50 random numbers from the data (guaranteed to be in the array)
    vector<int> randNum;
    for (int i=0 ; i<50; i++){
        int randIndex = rand() % 100000;
        randNum.push_back(num[randIndex]);
    }
    cout << "50 random numbers number in the vector generated." << endl;
 
    // Generate 50 random numbers (may or may not be in the array)
    for (int i=0 ; i<50; i++){
        int iRandNum = rand() % 100000;
        randNum.push_back(iRandNum);
    }
    cout << "50 random numbers number generated." << endl;

    // Test each search algorithm, output results
    cout << "Search\tFound\tSeq. Search\tBin Search\tEnhanced Search" << endl;
    for(int i : randNum){
        int numCmpSeq = 0;
        int numCmpBin = 0;
        int numCmpBin2 = 0;

        int foundSeq = seq_search(num,i,numCmpSeq);
        int foundBin = bin_search(num,i,numCmpBin);
        int foundBin2 = bin2_search(num,i,numCmpBin2);

        cout << i << "\t" << foundSeq << "\t" << numCmpSeq << "\t\t" << numCmpBin << "\t\t" << numCmpBin2 << endl;
    }
    











    // //test for each search
    // cout << "number want to find : " << endl;
    // int find;
    // cin >> find;
    // cout << endl;
    // int numCmp = 0;
    // int resultSeq = seq_search(num,find,numCmp);
    // int resultBin = bin_search(num,find,numCmp);
    // int resultBin2 = bin2_search(num,find,numCmp);
    // cout << "test for sequential search, target number find in position : " << resultSeq << endl;
    // cout << "test for binary search, target number find in position : " << resultBin << endl;
    // cout << "test for binary search 2, target number find in position : " << resultBin2 << endl;

    return 0;
}
