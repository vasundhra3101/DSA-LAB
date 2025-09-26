#include <iostream>
#include <limits.h>
#include <cstdlib> // for malloc and free
using namespace std;
struct lnode {
int data;
struct lnode* next;
};
typedef struct lnode node;
struct Queue {
node* front;
node* rear;
};
struct Queue* createQueue() {
struct Queue* p = (struct Queue*)malloc(sizeof(struct Queue));
p->front = NULL;
p->rear = NULL;
return p;
}
// Enqueue operation
void enqueue(struct Queue* q, int val) {
node* newNode = (node*)malloc(sizeof(node));
if (newNode == NULL) {
cout << "Out of memory\n";
return;
}
newNode->data = val;
newNode->next = NULL;
if (q->rear == NULL)
q->front = newNode;
else
{
q->rear->next = newNode;
q->rear = newNode;
cout << "Enqueued " << val << endl;
}
// Dequeue operation
int dequeue(struct Queue* q) {
if (q->front == NULL) {
return INT_MIN;
}
node* del = q->front;
q->front = q->front->next;
if (q->front == NULL)
q->rear = NULL;
int temp = del->data;
free(del);
return temp;
}
// Peek front element
int peek(struct Queue* q) {
if (q->front == NULL)
return INT_MIN;
return q->front->data;
}
// Check if queue is empty
bool isEmpty(struct Queue* q) {
return q->front == NULL;
}
// Count elements
int size(struct Queue* q) {
int count = 0;
node* temp = q->front;
while (temp != NULL) {
count++;
temp = temp->next;
}
return count;
}
// Display queue
void display(struct Queue* q) {
if (isEmpty(q)) {
cout << "Queue is empty." << endl;
return;
}
cout << "Queue elements: ";
node* temp = q->front;
while (temp != NULL) {
cout << temp->data << " ";
temp = temp->next;
}
cout << endl;
}
// Main function with switch menu
int main() {
struct Queue* q = createQueue();
int choice, val;
do {
cout << "\n--- Queue Menu ---" << endl;
cout<<" "<<endl;
cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Is Empty\n5. Size\n6. Display\n7. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
cout << "Enter value to enqueue: ";
cin >> val;
enqueue(q, val);
break;
case 2:
val = dequeue(q);
if (val == INT_MIN)
cout << "Queue is empty." << endl;
else
cout << "Dequeued " << val << endl;
break;
case 3:
val = peek(q);
if (val == INT_MIN)
cout << "Queue is empty." << endl;
else
cout << "Front element: " << val << endl;
break;
case 4:
cout << (isEmpty(q) ? "Queue is empty." : "Queue is not empty.") << endl;
break;
case 5:
cout << "Queue size: " << size(q) << endl;
break;
case 6:
display(q);
break;
case 7:
cout << "Exiting program." << endl;
break;
default:
cout << "Invalid choice!" << endl;
}
} while (choice != 7);
return 0;
}

