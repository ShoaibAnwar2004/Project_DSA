#include<bits/stdc++.h>
using namespace std;

// Stack
template <typename X>
class Stack {
private:
    struct Node {
        X data;
        Node* next;
    };
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    
    void push(X item) {
        Node* newNode = new Node{item, topNode};
        topNode = newNode;
    }

  
    bool pop() {
        if (!isEmpty()) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
            return true;  // Successfully popped
        } else {
            cout << "Stack is empty, cannot pop!" << endl;
            return false;  // Error: Stack is empty
        }
    }

    
    bool top(X& result) {
        if (!isEmpty()) {
            result = topNode->data;
            return true; 
        } else {
            cout << "Stack is empty!" << endl;
            return false;  
        }
    }

    
    bool isEmpty() const {
        return topNode == nullptr;
    }
};

//Queue
template <typename X>
class Queue {
private:
    struct Node {
        X data;
        Node* next;
    };
    Node* frontNode;
    Node* rearNode;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    
    void enqueue(X item) {
        Node* newNode = new Node{item, nullptr};
        if (rearNode) {
            rearNode->next = newNode;
        } else {
            frontNode = newNode;
        }
        rearNode = newNode;
    }

   
    bool dequeue() {
        if (!isEmpty()) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            if (!frontNode) {
                rearNode = nullptr;
            }
            delete temp;
            return true;  
        } else {
            cout << "Queue is empty, cannot dequeue!" << endl;
            return false;  
        }
    }

    
    bool front(X& result) {
        if (!isEmpty()) {
            result = frontNode->data;
            return true;  
        } else {
            //cout << "Queue is empty!" << endl;
            return false;  
        }
    }

    
    bool isEmpty() const {
        return frontNode == nullptr;
    }
};

// Browser class using Stack and Queue
class Browser {
private:
    Stack<string> backStack;    // Stack for going back
    Stack<string> forwardStack; // Stack for going forward
    Queue<string> tabQueue;     // Queue for tabs
    string currentPage;

public:
    // Function to go to a new page
    void visit(string page) {
        if (!currentPage.empty()) {
            backStack.push(currentPage);  
        }
        currentPage = page;

        
        while (!forwardStack.isEmpty()) {
            forwardStack.pop();
        }

        cout << "Visited page: " << currentPage << endl;
    }

    // Function to go back to the previous page
    void goBack() {
        string tempPage;
        if (backStack.top(tempPage)) {
            forwardStack.push(currentPage);  
            currentPage = tempPage;
            backStack.pop();
            cout << "Back to: " << currentPage << endl;
        }
    }

    // Function to go forward to the next page
    void goForward() {
        string tempPage;
        if (forwardStack.top(tempPage)) {
            backStack.push(currentPage);  
            currentPage = tempPage;
            forwardStack.pop();
            cout << "Forward to: " << currentPage << endl;
        }
    }

    // Function to open a new tab
    void openTab(string page) {
        tabQueue.enqueue(page);
        cout << "Opened new tab with: " << page << endl;
    }

    // Function to show all open tabs
    void showTabs() {
        Queue<string> temp = tabQueue;  
        string tab;
        if (!temp.isEmpty()) {
            cout << "Open tabs:" << endl;
            while (temp.front(tab)) {
                cout << tab << endl;
                temp.dequeue();  
            }
        }
    }
};

int main() {
    Browser browser;

    // Opening some tabs
    browser.openTab("www.tab1.com");
    browser.openTab("www.tab2.com");

    // Visit some pages
    browser.visit("www.pwioi.com");
    browser.visit("www.geeksforgeeks.com");
    browser.visit("www.codeforces.com");
    browser.visit("www.leetcode.com");

    // Go back and forward in the open pages
    browser.goBack();
    browser.goBack();
    browser.goBack();
    browser.goForward();
    browser.goForward();
    browser.goForward();

    // Show all open tabs
    browser.showTabs();

    return 0;
}
