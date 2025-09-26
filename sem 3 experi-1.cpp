#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;
// Define node using typedef
typedef struct lnode {
         int data;
         struct lnode* next;
} node;
//push operation
void push(node** top, int val) {
         node* newNode = (node*)malloc(sizeof(node));
         if (newNode == NULL) 
        {
           cout << "Out of memory" << endl; return;
        }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
  }
// Pop operation
int pop(node** top) {
          if (*top == NULL) {
                cout << "Stack is empty" << endl;
                return INT_MIN;
       }
node* del = *top;
*top = (*top)->next;
int temp = del->data;
free(del);
return temp;
}

// Peek operation
int peek(node* top) {
        if (top == NULL) {
                   cout << "Stack is empty" << endl;
                   return INT_MIN;
           }
           return top->data;
}

// Check if stack is empty
int isEmpty(node* top) {
           return top == NULL;
}
// Get stack size
int size(node* top) {
          int count = 0;
          while (top != NULL) {
                       count++; top = top->next;
         }
      return count;
}
// Display stack
void display(node* top) {
     if (top == NULL) {
                cout << "Stack is empty" << endl;
               return;
     }
     cout << "Stack elements (top to bottom): ";
     while (top != NULL) {
             cout << top->data << " ";
            top = top->next;
   }
   cout << endl;
}

// Main function with menu
int main() {
     node* top = NULL;
     int choice, val;

   while (1) {
           cout << "\n--- Stack Menu ---\n";
           cout << "1. Push\n";
           cout << "2. Pop\n";
           cout << "3. Peek\n";
           cout << "4. Check if Empty\n";
          cout << "5. Stack Size\n";
          cout << "6. Display Stack\n";
         cout << "7. Exit\n";
     cout << "Enter your choice: ";
      cin >> choice;

    switch (choice) {
      case 1:
          cout << "Enter value to push: ";
          cin >> val;
          push(&top, val);
          break;
    case 2:
         val = pop(&top);
         if (val != INT_MIN) cout << "Popped: " << val << endl;
         break;
  case 3:
         val = peek(top);
         if (val != INT_MIN) cout << "Top element: " << val << endl;
         break;
 case 4:
        cout << (isEmpty(top) ? "Stack is empty\n" : "Stack is not empty\n");
        break;
case 5:
         cout << "Stack size: " << size(top) << endl;
         break;
case 6:
        display(top);
        break;
case 7:
        cout << "Exiting..." << endl;
        return 0;
default:
        cout << "Invalid choice. Try again." << endl;
     }
  }
   return 0;
}

