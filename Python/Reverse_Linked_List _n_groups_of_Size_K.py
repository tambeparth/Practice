class Node:
    def __inti__(self,data,next_node=None):
        self.data = data
        self.next = next_node
        
# function to reverse the linked list using 3 pointer approach
def reverseLinkedList(head):
    temp = head
    prev = None
    
    while temp is not None:
        front = temp.next
        temp.next = prev
        prev = temp
        temp = front
        
    return prev
        
        
# Function to get the kth node from a given position in the LL
def getKthNode(temp,k):
    k -= 1 # Decrement k as we already start from the 1st node
    while temp is not None and k > 0:
        k -= 1
        temp = temp.next
    return temp
    
#Function to reverse nodes in groups of k      
def kReverse(head,k):
    temp = head
    prevLast = None 
    
    while  temp is not None:
        kthNode = getKthNode(temp,k)
        if kthNode is None:
            if prevLast:
                prevLast.next = temp
            break
        
        nextNode = kthNode.next    
        kthNode.next = None
        
        reverseLinkedList(temp)
        
        if temp == head:
            head = kthNode
        else:
            prevLast.next = kthNode
        
        
        prevLast = temp
        temp = nextNode
        
    return head

def printLinkedList(head):
    temp =head
    while temp is not None:
        print(temp.data,end=" ")
        temp =temp.next
    print() 


class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        
        
head = Node(5)
head.next = Node(4)
head.next.next = Node(3)
head.next.next.next = Node(7)
head.next.next.next.next = Node(9)
head.next.next.next.next.next = Node(2)

print("Original Linked List: ", end="")
printLinkedList(head)

head = kReverse(head,3)
print("Reversed Linked List: ", end="")
printLinkedList(head)
