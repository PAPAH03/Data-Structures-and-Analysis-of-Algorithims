#include <iostream>
#include <chrono>
#include "LinkedList.h"
#include "BST.h"

using namespace std;

void runScenario(const string& scenarioName, int itemCount, int maxValue) {
    LinkedList list;
    BST bst;

    cout << "- " << scenarioName << ":" << endl;

    // Measure Linked List append time
    auto start_time_list = chrono::high_resolution_clock::now();
    list.appendRandomNumbers(itemCount, maxValue);
    auto end_time_list = chrono::high_resolution_clock::now();
    auto duration_list_insert = chrono::duration_cast<chrono::microseconds>(end_time_list - start_time_list);
    cout << "Linked List Append Time (" << scenarioName << "): " << duration_list_insert.count() << " microseconds" << endl;

    // Measure BST insert time
    auto start_time_bst = chrono::high_resolution_clock::now();
    bst.insertRandomNumber(itemCount, maxValue);
    auto end_time_bst = chrono::high_resolution_clock::now();
    auto duration_bst_insert = chrono::duration_cast<chrono::microseconds>(end_time_bst - start_time_bst);
    cout << "BST Insert Time (" << scenarioName << "): " << duration_bst_insert.count() << " microseconds" << endl;

    // Search for a random number in the Linked List
    int randomNumToSearch = rand() % maxValue + 1; // Generate a random number to search for
    auto start_time_list_search = chrono::high_resolution_clock::now();
    bool found_in_linkedlist = list.search(randomNumToSearch);
    auto end_time_list_search = chrono::high_resolution_clock::now();
    auto duration_list_search = chrono::duration_cast<chrono::microseconds>(end_time_list_search - start_time_list_search);
    cout << "Linked List Search (" << scenarioName << "): Number: " << randomNumToSearch << " Found: " << (found_in_linkedlist ? "Yes" : "No") << " Time: " << duration_list_search.count() << " microseconds" << endl;

    // Search for the same random number in the BST
    auto start_time_bst_search = chrono::high_resolution_clock::now();
    bool found_in_bst = bst.find(randomNumToSearch);
    auto end_time_bst_search = chrono::high_resolution_clock::now();
    auto duration_bst_search = chrono::duration_cast<chrono::microseconds>(end_time_bst_search - start_time_bst_search);
    cout << "BST Find (" << scenarioName << "): Number: " << randomNumToSearch << " Found: " << (found_in_bst ? "Yes" : "No") << " Time: " << duration_bst_search.count() << " microseconds" << endl;

    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator with current time

    runScenario("One Dozen", 12, 1000);
    runScenario("Two Dozen", 24, 1000);
    runScenario("Two Hundred", 200, 200);
    runScenario("One -> One-Thousand", 1000, 1000);
    runScenario("One-Thousand -> One", 1000, 1000);

    return 0;
}
