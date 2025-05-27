//traverse through linked list
  void display()
    {
        node *tmp;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
// to find maximum 
    //iterate through linked list looking at the data of each node
    //compare current node with next node to see which one is bigger
    //set a max variable to the node that is bigger 
        //or set the current node to whichever is bigger
    //after finding max variable, go through another while loop
        //and delete node that is equal to max (or current) 

//DELETE NODE

void deleteNode(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
 // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    // Free memory
    delete temp;
    }
}

//FINDMAX

 max = current node;

{
  while (head != NULL) {
 
        // If max is less than head->data then
        // assign value of head->data to max
        // otherwise node point to next node.
        if (max < head->data)
            max = head->data;
        head = head->next;
    }
    return max;
}

//FINDMIN 
{
    min = current ///where current is set to head of linked list 
       while (head != NULL) {
 
        // If min is greater than head->data then
        // assign value of head->data to min
        // otherwise node point to next node.
        if (min > head->data)
            min = head->data;
 
        head = head->next;
    }
    return min;
}

//reverse list 
 void reverse()
    {
        // Initialize current, previous and next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }


    //FIND MIDDLE 

 int getLen(class Node* head)
    {
        int len = 0;
        class Node* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        return len;
    }

       void printMiddle(class Node* head)
    {
 
        if (head) {
            // find length
            int len = getLen(head);
            class Node* temp = head;
 
            // trvaers till we reached half of length
            int midIdx = len / 2;
            while (midIdx--) {
                temp = temp->next;
            }
            // temp will be storing middle element
            cout << "The middle element is [" << temp->data
                 << "]" << endl;
        }
    }
};



//palindrome
bool isPalRec(char str[],
              int s, int e)
{
     
    // If there is only one character
    if (s == e)
    return true;
 
    // If first and last
    // characters do not match
    if (str[s] != str[e])
    return false;
 
    // If there are more than
    // two characters, check if
    // middle substring is also
    // palindrome or not.
    if (s < e + 1)
    return isPalRec(str, s + 1, e - 1);
 
    return true;
}


bool isPalindrome(char str[])
{
    int n = strlen(str);
     
    // An empty string is
    // considered as palindrome
    if (n == 0)
        return true;
     
    return isPalRec(str, 0, n - 1);
}
 