#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>    
struct node{  
    int data;  
    struct node *left;  
    struct node *right;  
};  
typedef struct node* tree; 
tree root = NULL;  
   
 
tree createNode(int data){  
    
    tree newNode = (tree)malloc(sizeof(struct node));  
   
    newNode->data = data;  
    newNode->left = NULL;  
    newNode->right = NULL;  
      
    return newNode;  
}  
 
struct queue  
{  
    int front, rear, size;  
    tree *arr;  
};  
typedef struct queue* inqueue;  
 
inqueue createQueue()  
{  
    inqueue newQueue = (inqueue) malloc(sizeof( struct queue ));  
   
    newQueue->front = -1;  
    newQueue->rear = 0;  
    newQueue->size = 0;  
  
    newQueue->arr = (struct node**) malloc(100 * sizeof( tree ));  
   
    return newQueue;  
}  
   

void enqueue(inqueue queue, tree temp){  
    queue->arr[queue->rear++] = temp;  
    queue->size++;  
}  
   
  
tree dequeue(inqueue queue){  
    queue->size--;  
    return queue->arr[++queue->front];  
}  

void insertNode(int data) {  
  
    tree newNode = createNode(data);  
    
    if(root == NULL){  
        root = newNode;  
        return;  
    }  
    else {  
      
        struct queue* queue = createQueue();  
     
        enqueue(queue, root);  
          
        while(true) {  
            tree node = dequeue(queue);  
       
            if(node->left != NULL && node->right != NULL) {  
                enqueue(queue, node->left);  
                enqueue(queue, node->right);  
            }  
            else {  
                  
                if(node->left == NULL) {  
                    node->left = newNode;  
                    enqueue(queue, node->left);  
                }  
                
                else {  
                    node->right = newNode;  
                    enqueue(queue, node->right);  
                }  
                break;  
            }  
        }  
    }  
}  
   
 
void inorderTraversal(struct node *node) {  
   
    if(root == NULL){  
        printf("Tree is empty\n");  
        return;  
    }  
    else {  
            
        if(node->left != NULL)  
            inorderTraversal(node->left);  
        printf("%d ", node->data);  
        if(node->right != NULL)  
            inorderTraversal(node->right);  
                
        }  
    }  
            
int main(){  
    insertNode(11);  

    printf("Binary tree after insertion: \n");  
  
    inorderTraversal(root);  
      
    insertNode(22);  
    insertNode(33);  

    printf("\nBinary tree after insertion: \n");  

    inorderTraversal(root);  
      
    insertNode(44);  
    insertNode(55);  

    printf("\nBinary tree after insertion: \n");  

    inorderTraversal(root);  
      
    insertNode(66);  
    insertNode(77 );  

    printf("\nBinary tree after insertion: \n");  
  
    inorderTraversal(root);  
      
    return 0;  
}  