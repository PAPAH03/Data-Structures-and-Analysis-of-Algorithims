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

/*#include <iostream>
#include <chrono>
#include "LinkedList.h"
#include "BST.h"

using namespace std;

int main() {
    LinkedList list;
    BST bst;

    // One Dozen
    cout << "- One Dozen:" << endl;
    auto start_time_1 = chrono::high_resolution_clock::now();
    list.appendRandomNumbers(12, 1000);
    auto end_time_1 = chrono::high_resolution_clock::now();
    auto duration_list_insert_1 = chrono::duration_cast<chrono::microseconds>(end_time_1 - start_time_1);
    cout << "Linked List Append Time (1 Dozen): " << duration_list_insert_1.count() << " microseconds" << endl;

    start_time_1 = chrono::high_resolution_clock::now();
    bst.insertRandomNumber(12, 1000);
    end_time_1 = chrono::high_resolution_clock::now();
    auto duration_bst_insert_1 = chrono::duration_cast<chrono::microseconds>(end_time_1 - start_time_1);
    cout << "BST Insert Time ( 1 Dozen): " << duration_bst_insert_1.count() << " microseconds" << endl;

    int randomNumToSearch_1 = rand() % 1000; // Generate a random number to search for
    start_time_1 = chrono::high_resolution_clock::now();
    bool found_in_linkedlist_1 = list.search(randomNumToSearch_1);
    end_time_1 = chrono::high_resolution_clock::now();
    auto duration_list_search_1 = chrono::duration_cast<chrono::microseconds>(end_time_1 - start_time_1);
    cout << "Linked List Search (1 Dozen): Number: " << randomNumToSearch_1 << " Found: " << (found_in_linkedlist_1 ? "Yes" : "No") << " Time: " << duration_list_search_1.count() << " microseconds" << endl;

    start_time_1 = chrono::high_resolution_clock::now();
    bool found_in_bst_1 = bst.find(randomNumToSearch_1);
    end_time_1 = chrono::high_resolution_clock::now();
    auto duration_bst_search_1 = chrono::duration_cast<chrono::microseconds>(end_time_1 - start_time_1);
    cout << "BST Find (1 Dozen): Number: " << randomNumToSearch_1 << " Found: " << (found_in_bst_1 ? "Yes" : "No") << " Time: " << duration_bst_search_1.count() << " microseconds" << endl;

    cout << endl;

    // Two Dozen
    cout << "- Two Dozen:" << endl;
    auto start_time_2 = chrono::high_resolution_clock::now();
    list.appendRandomNumbers(24, 1000);
    auto end_time_2 = chrono::high_resolution_clock::now();
    auto duration_list_insert_2 = chrono::duration_cast<chrono::microseconds>(end_time_2 - start_time_2);
    cout << "Linked List Append Time (2 Dozen): " << duration_list_insert_2.count() << " microseconds" << endl;

    start_time_2 = chrono::high_resolution_clock::now();
    bst.insertRandomNumber(24, 1000);
    end_time_2 = chrono::high_resolution_clock::now();
    auto duration_bst_insert_2 = chrono::duration_cast<chrono::microseconds>(end_time_2 - start_time_2);
    cout << "BST Insert Time ( 2 Dozen): " << duration_bst_insert_2.count() << " microseconds" << endl;

    int randomNumToSearch_2 = rand() % 1000; // Generate a random number to search for
    start_time_2 = chrono::high_resolution_clock::now();
    bool found_in_linkedlist_2 = list.search(randomNumToSearch_2);
    end_time_2 = chrono::high_resolution_clock::now();
    auto duration_list_search_2 = chrono::duration_cast<chrono::microseconds>(end_time_2 - start_time_2);
    cout << "Linked List Search (2 Dozen): Number: " << randomNumToSearch_2 << " Found: " << (found_in_linkedlist_2 ? "Yes" : "No") << " Time: " << duration_list_search_2.count() << " microseconds" << endl;

    start_time_2 = chrono::high_resolution_clock::now();
    bool found_in_bst_2 = bst.find(randomNumToSearch_2);
    end_time_2 = chrono::high_resolution_clock::now();
    auto duration_bst_search_2 = chrono::duration_cast<chrono::microseconds>(end_time_2 - start_time_2);
    cout << "BST Find (2 Dozen): Number: " << randomNumToSearch_2 << " Found: " << (found_in_bst_2 ? "Yes" : "No") << " Time: " << duration_bst_search_2.count() << " microseconds" << endl;

    cout << endl;

    // Two Hundred
    cout << "- Two Hundred:" << endl;
    auto start_time_3 = chrono::high_resolution_clock::now();
    list.appendRandomNumbers(200, 200);
    auto end_time_3 = chrono::high_resolution_clock::now();
    auto duration_list_insert_3 = chrono::duration_cast<chrono::microseconds>(end_time_3 - start_time_3);
    cout << "Linked List Append Time (Two Hundred): " << duration_list_insert_3.count() << " microseconds" << endl;

    start_time_3 = chrono::high_resolution_clock::now();
    bst.insertRandomNumber(200,200);
    end_time_3 = chrono::high_resolution_clock::now();
    auto duration_bst_insert_3 = chrono::duration_cast<chrono::microseconds>(end_time_3 - start_time_3);
    cout << "BST Insert Time (Two Hundered): " << duration_bst_insert_3.count() << " microseconds" << endl;

    int randomNumToSearch_3 = rand() % 200; // Generate a random number to search for
    start_time_3 = chrono::high_resolution_clock::now();
    bool found_in_linkedlist_3 = list.search(randomNumToSearch_3);
    end_time_3 = chrono::high_resolution_clock::now();
    auto duration_list_search_3 = chrono::duration_cast<chrono::microseconds>(end_time_3 - start_time_3);
    cout << "Linked List Search (2 Dozen): Number: " << randomNumToSearch_3 << " Found: " << (found_in_linkedlist_3 ? "Yes" : "No") << " Time: " << duration_list_search_3.count() << " microseconds" << endl;

    start_time_3 = chrono::high_resolution_clock::now();
    bool found_in_bst_3 = bst.find(randomNumToSearch_3);
    end_time_3 = chrono::high_resolution_clock::now();
    auto duration_bst_search_3 = chrono::duration_cast<chrono::microseconds>(end_time_3 - start_time_3);
    cout << "BST Find (2 Dozen): Number: " << randomNumToSearch_3 << " Found: " << (found_in_bst_3 ? "Yes" : "No") << " Time: " << duration_bst_search_3.count() << " microseconds" << endl;

    cout << endl;
    

    // One -> One-Thousand
    cout << "- One -> One-Thousand:" << endl;
    auto start_time_4 = chrono::high_resolution_clock::now();
    int maxValue = 1000;
    for (int i = 1000; i >= 1; --i)
    {
        int randomNumber = rand() % maxValue + 1; // Generate a random number between 1 and maxValue
        list.append(randomNumber);
    }

    auto end_time_4 = chrono::high_resolution_clock::now();
    auto duration_list_insert_4 = chrono::duration_cast<chrono::microseconds>(end_time_4 - start_time_4);
    cout << "Linked List Append Time (1->1000): " << duration_list_insert_4.count() << " microseconds" << endl;

    start_time_4 = chrono::high_resolution_clock::now();
    for (int i = 1000; i >= 1; --i)
    {
        int randomNumber = rand() % maxValue + 1; // Generate a random number between 1 and maxValue
        bst.insert(randomNumber);
    }
    end_time_4 = chrono::high_resolution_clock::now();
    auto duration_bst_insert_4 = chrono::duration_cast<chrono::microseconds>(end_time_4 - start_time_4);
    cout << "BST Insert Time (1->1000): " << duration_bst_insert_4.count() << " microseconds" << endl;

    int randomNumToSearch_4 = rand() % maxValue+1; // Generate a random number to search for
    start_time_4 = chrono::high_resolution_clock::now();
    bool found_in_linkedlist_4 = list.search(randomNumToSearch_4);
    end_time_4 = chrono::high_resolution_clock::now();
    auto duration_list_search_4 = chrono::duration_cast<chrono::microseconds>(end_time_4 - start_time_4);
    cout << "Linked List Search (1->1000): Number: " << randomNumToSearch_4 << " Found: " << (found_in_linkedlist_4 ? "Yes" : "No") << " Time: " << duration_list_search_4.count() << " microseconds" << endl;

    start_time_4 = chrono::high_resolution_clock::now();
    bool found_in_bst_4 = bst.find(randomNumToSearch_4);
    end_time_4 = chrono::high_resolution_clock::now();
    auto duration_bst_search_4 = chrono::duration_cast<chrono::microseconds>(end_time_4 - start_time_4);
    cout << "BST Find (1->1000): Number: " << randomNumToSearch_4 << " Found: " << (found_in_bst_4 ? "Yes" : "No") << " Time: " << duration_bst_search_4.count() << " microseconds" << endl;

    cout << endl;
    

    // One-Thousand -> One
    cout << "- One-Thousand -> One:" << endl;
   
    auto start_time_5 = chrono::high_resolution_clock::now();
    int maxValue2 = 1000;
    for (int i = 1; i >= 1000; ++i)
    {
        int randomNumber = rand() % maxValue2 + 1; // Generate a random number between 1 and maxValue
        list.append(randomNumber);
    }

    auto end_time_5 = chrono::high_resolution_clock::now();
    auto duration_list_insert_5 = chrono::duration_cast<chrono::microseconds>(end_time_5 - start_time_5);
    cout << "Linked List Append Time (1000->1): " << duration_list_insert_5.count() << " microseconds" << endl;

    start_time_5 = chrono::high_resolution_clock::now();
    for (int i = 1; i >= 1000; ++i)
    {
        int randomNumber = rand() % maxValue2 + 1; // Generate a random number between 1 and maxValue
        bst.insert(randomNumber);
    }
    end_time_5 = chrono::high_resolution_clock::now();
    auto duration_bst_insert_5 = chrono::duration_cast<chrono::microseconds>(end_time_5 - start_time_5);
    cout << "BST Insert Time (1000->1): " << duration_bst_insert_5.count() << " microseconds" << endl;

    int randomNumToSearch_5 = rand() % maxValue2 + 1; // Generate a random number to search for
    start_time_5 = chrono::high_resolution_clock::now();
    bool found_in_linkedlist_5 = list.search(randomNumToSearch_3);
    end_time_5 = chrono::high_resolution_clock::now();
    auto duration_list_search_5 = chrono::duration_cast<chrono::microseconds>(end_time_5 - start_time_5);
    cout << "Linked List Search (1000->1): Number: " << randomNumToSearch_5 << " Found: " << (found_in_linkedlist_5 ? "Yes" : "No") << " Time: " << duration_list_search_5.count() << " microseconds" << endl;

    start_time_5 = chrono::high_resolution_clock::now();
    bool found_in_bst_5 = bst.find(randomNumToSearch_5);
    end_time_5 = chrono::high_resolution_clock::now();
    auto duration_bst_search_5 = chrono::duration_cast<chrono::microseconds>(end_time_5 - start_time_5);
    cout << "BST Find (1000->1): Number: " << randomNumToSearch_5 << " Found: " << (found_in_bst_5 ? "Yes" : "No") << " Time: " << duration_bst_search_5.count() << " microseconds" << endl;

    cout << endl;
    

    return 0;
}
*/
