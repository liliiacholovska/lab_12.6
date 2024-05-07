#include <iostream>
#include <fstream>

using namespace std;

typedef int Info;

struct Elem {
    Elem* link;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value) {
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

Info dequeue(Elem*& first, Elem*& last) {
    Elem* tmp = first->link;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    return value;
}

bool isEmpty(Elem* first) {
    return first == NULL;
}

int countElements(Elem* first) {
    int count = 0;
    while (first != NULL) {
        count++;
        first = first->link;
    }
    return count;
}

void printQueue(Elem* first) {
    while (first != NULL) {
        cout << first->info << " ";
        first = first->link;
    }
    cout << endl;
}

void copyQueue(Elem*& newFirst, Elem*& newLast, Elem* originalFirst) {
    newFirst = newLast = NULL;
    while (originalFirst != NULL) {
        enqueue(newFirst, newLast, originalFirst->info);
        originalFirst = originalFirst->link;
    }
}

void loadQueueFromFile(Elem*& first, Elem*& last, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "File could not be opened." << endl;
        return;
    }

    Info value;
    while (file >> value) {
        enqueue(first, last, value);
    }
    file.close();
}

int main() {
    Elem* first = NULL, * last = NULL;
    Elem* copyFirst = NULL, * copyLast = NULL;

    string filename = "data.txt";
    loadQueueFromFile(first, last, filename);

    if (isEmpty(first)) {
        cout << "Queue is empty." << endl;
    }
    else {
        cout << "Queue loaded from file:" << endl;
        printQueue(first);
    }

    copyQueue(copyFirst, copyLast, first);
    cout << "Copied queue:" << endl;
    printQueue(copyFirst);

    cout << "Number of elements in the queue: " << countElements(first) << endl;

    cout << "Original queue elements being dequeued:" << endl;
    while (!isEmpty(first)) {
        cout << dequeue(first, last) << " ";
    }
    cout << endl;

    return 0;
}