#include <iostream>
#include <string.h>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node() {
        this->next = nullptr;
    }

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template<class T>
class LinkedList {
public:
    Node<T> *head;

    LinkedList() { head = nullptr; }

    LinkedList(T val[], int len);

    ~LinkedList() {}

    int length();

    void print();

    Node<T> *get(int index);
};

template<class T>
LinkedList<T>::LinkedList(T *val, int len) {
    head = new Node<T>(val[0]);
    Node<T> *ptemp, *pnew;
    ptemp = head;
    for (int i = 1; i < len; ++i) {
        pnew = new Node<T>(val[i]);
        ptemp->next = pnew;
        ptemp = pnew;
    }
}


template<class T>
int LinkedList<T>::length() {
    int len = 0;
    Node<T> *p = head;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

template<class T>
void LinkedList<T>::print() {
    Node<T> *p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void findMissMin(int a[], int n) {
    int b[n + 2];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++) {
        if (a[i] > 0)
            b[a[i]] = 1;
    }
    for (int i = 1; i < n + 2; i++) {
        if (b[i] == 0) {
            cout << i;
            break;
        }
    }
}

int main() {
    int a[5] = {-5, 3, 2, 3};
    findMissMin(a, 4);
    return 0;
}
/*int a[5] = {1, 2, 3, 4, 5};
    LinkedList<int> A(a, 5);
    A.print();
    int len = A.length();
    int *b = new int[len];
    Node<int> *L = A.head;
    for (int i = 0; i < len; i++) {
        b[i] = L->data;
        L = L->next;
    }
    for (int i = len - 1; i >= 0; i--) {
        cout << b[i] << " ";
    }
    delete[] b;*/