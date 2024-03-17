#include <stdio.h>
#include <stdlib.h>

// 单向链表的节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 双向链表的节点结构
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// 创建一个新的节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("ERROR\n");
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 向链表末尾添加节点
void appendNode(Node** head, int data) {
		if(data==-1){
		return;
	}
	
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 打印单向链表
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 主函数测试单向链表


// 创建一个新的双向链表节点
DNode* createDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (newNode == NULL) {
        printf("ERROR\n");
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 向双向链表末尾添加节点
void appendDNode(DNode** head, int data) {
	if(data==-1){
		return;
	}
    DNode* newNode = createDNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        DNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// 打印双向链表
void printDList(DNode* head) {
    DNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void menu(){
	printf("**********************************\n");
	printf("***    linklist                ***\n");
	printf("***   1.create one linklist    ***\n");
	printf("***   2.create two linklist    ***\n");
	printf("***   3.print linklist         ***\n");
	printf("***   4.findMiddle             ***\n");
	printf("***   5.hasCycle               ***\n");
	printf("***   6.reverseListIterative   ***\n");
	printf("***   7.reverseListRecursive   ***\n");
	printf("***   0.exit                   ***\n");
	printf("**********************************\n");
}

/*
 奇偶交换(未完成)
 
Node* swap(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even; // 保留偶数链表头部
    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
*/
//发现中间结点
Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


// 判断链表是否成环
int hasCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}


// 反转链表（非递归）
Node* reverseListIterative(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// 反转链表（递归）
Node* reverseListRecursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* reversed = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return reversed;
}



int main() {
	 Node* head1 = NULL;
	 DNode* head2 = NULL;
     int sign=1;
      int t=0;
	while(sign!=0){
  		int input;
     	menu();
    	printf("please input:");
    	scanf("%d",&input);
    	int data=0;
    switch(input){
   	    case 1://创建单向链表
   	   			 while(data!=-1){
   	    		printf("please input: (-1 is exit)\n");
   	    		scanf("%d",&data);
   	    		appendNode(&head1,data);
		  			 }
   		printf("create one linklist success \n");
   		break;
   		
   	    case 2://创建双向链表
   	   
   	          while(data!=-1){
   	    		printf("please input: (-1 is exit)\n");
   	    		scanf("%d",&data);
   	    		appendDNode(&head2,data);
		 	  }
   	   
	   		 printf("create two linklist success  \n");	
	   		break;
        case 3://打印链表
       		
     	  		printf("please input 1 or 2 \n");	
     			scanf("%d",&t);
      		   if(t==1){
       	       	     printList(head1);
			   }else{
			   		printDList(head2);
			   }
	
       			break;
       		case 4:
           //发现中间结点
       			printf("%d",findMiddle(head1)->data);
       	   	break;
       	    
       	    
       	case 5:   // 判断链表是否成环	  
      		 t = hasCycle(head1);
       		if(t==1){
       	  		printf("has cycle");
	 		  }else{
	   			printf("no cycle");
	 		  }
    		break;
    	case 6://反转链表（非递归）
    		head1 = reverseListIterative(head1);
    		break;
    	case 7://反转链表（递归）
    		head1 = reverseListRecursive(head1);
    		break;
        case 0: //结束
    		sign=0;
    		break;
    		
     }
     }
   
	return 0;
   

}



