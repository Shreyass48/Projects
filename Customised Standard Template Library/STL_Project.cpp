/////////////////////////////////////////////////////////
//
// Title : Customised Standard Template Libraray
// Author: Shreyas Kulkarni
// Date  : 19/11/21
//
/////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/////// Structure for Singly LL, Stack and Queue ///////
template <typename T>
struct snode
{
    T data;
    struct snode *next;
};

/////// Structure for Doubly LL ///////
template <typename T>
struct dnode
{
    T data;
    struct dnode *next;
    struct dnode *prev;
};

/////// Structure for BST ///////
template<typename T>
struct node
{
    T data;
    struct node * lchild;
    struct node * rchild;
};

//////////////////////////////////////////
/////// Class for Singly Linear LL ///////

template <class T>
class SinglyLL
{
private:
    snode<T> *first;
    int size;

public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

/////// Class for Singly Circular  LL ///////

template <class T>
class SinglyCircularLL
{
private:
    snode<T> *first;
    snode<T> *last;
    int size;

public:
    SinglyCircularLL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

/////// Class for Doubly Linear LL ///////

template <class T>
class DoublyLinearLL
{
private:
    int size;
    dnode<T> *first;

public:
    DoublyLinearLL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

/////// Class for Doubly Circular LL ///////

template <class T>
class DoublyCL
{
private:
    dnode<T> *first;
    dnode<T> *last;
    int size;

public:
    //Function Declaration
    DoublyCL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

/////// Class for Stack  LL ///////

template <class T>
class Stack
{
private:
    snode<T> *first;
    int size;

public:
    Stack();
    void push(T);
    int pop();
    void Display();
    int Count();
};

/////// Class for Queue  LL ///////

template <class T>
class Queue
{
private:
    snode<T> *first;
    int size;

public:
    Queue();
    void Enqueue(T);
    int Dequeue();
    void Display();
    int Count();
};

/////// Class for BST ///////
template<class T>
class BST
{
    public:
    void Insert(struct node<T>**,T);
    bool Search(node<T>**,T);
    int Count(node<T>*);
    int CountLeaf(node<T>*);
    int CountParent(node<T>*);
    void Inorder(node<T>*);
    void Preorder(node<T>*);
    void Postorder(node<T>*);
};

/////// All Functions of Singly Linear LL ///////

template <class T>
SinglyLL<T>::SinglyLL()
{
    first = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertFirst
// Input:			Template Input
// Output:			Nothing
// Description:		It Used to Insert node at First Location in LL
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    snode<T> *newn = new snode<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertLast
// Input:			Template Input
// Output:			Nothing
// Description:		It Used to Insert node at Last Location in LL
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    snode<T> *newn = new snode<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        snode<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertAtPos
// Input:			Template Input,Integer 
// Output:			Nothing
// Description:		It Used to Insert node at Given Location in LL
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
    int i = 0;
    if ((iPos < 1) || (iPos > size + 1))
    {
        cout << "invalid!\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        snode<T> *newn = new snode<T>;
        snode<T> *temp = first;

        newn->data = no;
        newn->next = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	DeleteFirst
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Delete First Node in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteFirst()
{
    snode<T> *temp = first;

    if (first != NULL)
    {
        first = first->next;
        delete temp;

        size--;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	DeleteLast
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Delete Last Node in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteLast()
{
    snode<T> *temp = first;

    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
        size--;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
        size--;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	DeleteAtPos
// Input:			Integer
// Output:			Nothing
// Description:		It Used to Delete Node which present at Given Position in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    snode<T> *temp = first;
    snode<T> *target = NULL;
    int i = 0;

    if ((iPos < 1) || (iPos > size))
    {
        cout << "invalid!\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == size)
    {
        DeleteLast();
    }
    else
    {
        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        size--;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Display
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Display LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLL<T>::Display()
{
    snode<T> *temp = first;

    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Count
// Input:			Nothing
// Output:			Integer
// Description:		It Used to Count Nodes in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLL<T>::Count()
{
    return size;
}

/////// All Functions of Singly Circular LL ///////

template <class T>
SinglyCircularLL<T>::SinglyCircularLL()
{
    first = NULL;
    last = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Display
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Display LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircularLL<T>::Display()
{
    snode<T> *temp = first;
    do
    {
        cout << "|" << temp->data << "| -> ";
        temp = temp->next;
    } while (temp != last->next);
    cout << "NULL\n";
}


///////////////////////////////////////////////////////////////////////
//
// Function name:	Count
// Input:			Nothing
// Output:			Integer
// Description:		It Used to Count Nodes in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCircularLL<T>::Count()
{
    return size;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertFirst
// Input:			Template Input
// Output:			Nothing
// Description:		It Used to Insert node at First Location in LL
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircularLL<T>::InsertFirst(T no)
{
    snode<T> *newn = new snode<T>;

    newn->data = no;
    newn->next = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertLast
// Input:			Template Input
// Output:			Nothing
// Description:		It Used to Insert node at Last Location in LL
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircularLL<T>::InsertLast(T no)
{
    snode<T> *newn = new snode<T>;

    newn->data = no;
    newn->next = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    last->next = first;
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertAtPos
// Input:			Template Input, Integer
// Output:			Nothing
// Description:		It Used to Insert node at Given Position in LL
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircularLL<T>::InsertAtPos(T no, int pos)
{
    int i = 0;
    snode<T> *temp = first;
    if ((pos < 1) || (pos > size + 1))
    {
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        snode<T> *newn = new snode<T>;
        newn->data = no;
        newn->next = NULL;

        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        size++;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	DeleteFirst
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Delete node at First Location in LL
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircularLL<T>::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    size--;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	DeleteLast
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Delete node at Last Location in LL
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircularLL<T>::DeleteLast()
{
    int i = 0;
    snode<T> *temp = first;
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        while (temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }

    size--;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	DeleteAtPos
// Input:			Integer
// Output:			Nothing
// Description:		It Used to Delete node at Given Location in LL
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCircularLL<T>::DeleteAtPos(int pos)
{
    int i = 0;
    snode<T> *temp = first;
    snode<T> *target = NULL;
    if ((pos < 1) || (pos > size))
    {
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == size)
    {
        DeleteLast();
    }
    else
    {
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        size--;
    }
}

/////// All Functions of Doubly Linear LL ///////

template <class T>
DoublyLinearLL<T>::DoublyLinearLL()
{
    size = 0;
    first = NULL;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Display
// Input:			Nothing
// Output:			Nothing
// Description:		It Used Display LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinearLL<T>::Display()
{
    dnode<T> *temp = first;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "| -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Count
// Input:			Nothing
// Output:			Integer
// Description:		It Used to Count Nodes in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLinearLL<T>::Count()
{
    return size;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertFirst
// Input:			Template Input
// Output:			Nothing
// Description:		It Used to Insert element at First Position in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinearLL<T>::InsertFirst(T no)
{
    dnode<T> *newn = new dnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        newn->next->prev = newn;
        first = newn;
    }
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertLast
// Input:			Template Input
// Output:			Nothing
// Description:		It Used to Insert element at Last Position in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinearLL<T>::InsertLast(T no)
{
    dnode<T> *temp = first;
    dnode<T> *newn = new dnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertAtPos
// Input:			Template Input, Integer
// Output:			Nothing
// Description:		It Used to Insert element at Given Position in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinearLL<T>::InsertAtPos(T no, int ipos)
{
    dnode<T> *temp = first;
    if ((ipos < 1) || (ipos > size + 1))
    {
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        dnode<T> *newn = new dnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size++;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	DeleteFirst
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Delete First element in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinearLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    size--;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	DeleteLast
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Delete Last element in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinearLL<T>::DeleteLast()
{
    dnode<T> *temp = first;
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    size--;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	DeleteAtPos
// Input:			Integer
// Output:			Nothing
// Description:		It Used to Delete element at Given Position in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLinearLL<T>::DeleteAtPos(int ipos)
{
    dnode<T> *temp = first;
    if ((ipos < 1) || (ipos > size))
    {
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == size)
    {
        DeleteLast();
    }
    else
    {
        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        size--;
    }
}

/////// All Functions of Doubly Circular LL ///////

template <class T>
DoublyCL<T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertFirst
// Input:			Template Input
// Output:			Nothing
// Description:		It Used to Insert element at First Location in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    dnode<T> *newn = new dnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertLast
// Input:			Template Input
// Output:			Nothing
// Description:		It Used to Insert element at Last Location in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    dnode<T> *newn = new dnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Display
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Display LL Nodes.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::Display()
{
    dnode<T> *temp = first;

    for (int i = 1; i <= size; i++)
    {
        cout << "|" << temp->data << "| -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Count
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Count LL Nodes.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCL<T>::Count()
{
    return size;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	DeleteFirst
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Delete element at First Location in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next; // first->prev
        first->prev = last;
        last->next = first;
    }
    size--;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertLast
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Delete element at Last Location in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::DeleteLast()
{
    dnode<T> *temp = first;
    if ((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next; //first->prev
        first->prev = last;
        last->next = first;
    }
    size--;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	InsertAtPos
// Input:			Template Input, Integer
// Output:			Nothing
// Description:		It Used to Insert element at Given Location in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::InsertAtPos(T no, int pos)
{
    dnode<T> *temp = first;
    if ((pos < 1) || (pos > size + 1))
    {
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        dnode<T> *newn = new dnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	DeleteAtPos
// Input:			Integer
// Output:			Nothing
// Description:		It Used to Delete element at Given Location in LL.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCL<T>::DeleteAtPos(int pos)
{
    dnode<T> *temp = first;
    if ((pos < 1) || (pos > size))
    {
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == size)
    {
        DeleteLast();
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        size--;
    }
}

/////// All Functions of Stack ///////

template <class T>
Stack<T>::Stack()
{
    first = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	push
// Input:			Template Input
// Output:			Nothing
// Description:		It Used to Insert element in Stack.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>::push(T no)
{
    snode<T> *newn = new snode<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	pop
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Delete element in Stack.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>::pop()
{
    snode<T> *temp = first;
    int val = 0;

    if (first->next == NULL)
    {
        val = first->data;
        delete first;
        first = NULL;
    }
    else
    {
        val = first->data;
        first = temp->next;
        delete temp;
    }
    size--;
    return val;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Display
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Display elements in Stack.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>::Display()
{
    snode<T> *temp = first;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|\n";
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Count
// Input:			Nothing
// Output:			Integer
// Description:		It Used to Count elements in Stack.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>::Count()
{
    return size;
}

/////// All Functions of Queue///////

template <class T>
Queue<T>::Queue()
{
    first = NULL;
    size = 0;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Enqueue
// Input:			Template Input
// Output:			Nothing
// Description:		It Used to Insert elements in Queue.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void Queue<T>::Enqueue(T no)
{
    snode<T> *newn = new snode<T>;
    snode<T> *temp = first;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Dequeue
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Delete elements in Queue.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
int Queue<T>::Dequeue()
{
    snode<T> *temp = first;
    int val = 0;

    if (size == 0)
    {
        cout << "Queue is empty!\n";
        return -1;
    }

    if (first->next == NULL)
    {
        val = first->data;
        delete first;
        first = NULL;
    }
    else
    {
        val = first->data;
        first = temp->next;
        delete temp;
    }
    size--;
    return val;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Display
// Input:			Nothing
// Output:			Nothing
// Description:		It Used to Display elements in Queue.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
void Queue<T>::Display()
{
    snode<T> *temp = first;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "| -> ";
        temp = temp->next;
    }
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Count
// Input:			Nothing
// Output:			Integer
// Description:		It Used to Count elements in Queue.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template <class T>
int Queue<T>::Count()
{
    return size;
}

/////// All Functions of BST ///////
///////////////////////////////////////////////////////////////////////
//
// Function name:	Insert
// Input:			Template Input
// Output:			Nothing
// Description:		It Used to insert elements in BST.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>:: Insert(struct node<T>** Head, T no)
{
    node<T>* newn = new node<T>;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        node<T>* temp = *Head;
        while(1)      
        {
           if(temp->data == no)    
           {
               cout<<"Duplicate NODE\n";
               delete newn;
               break;
           }
           else if(no < (temp->data))   
           {
               if(temp->lchild == NULL)
               {
                   temp->lchild = newn;
                   break;
               }
               temp = temp->lchild;               
           }
           else if(no > (temp->data))   
           {
               if(temp->rchild == NULL)
               {
                   temp->rchild = newn;
                   break;
               }
               temp = temp->rchild;
           }
        }
        

    }

}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Search
// Input:			Head,Template Input
// Output:			Nothing
// Description:		It Used to Search element in BST.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template<class T>
bool BST<T>::Search(PNODE Head, T no)
{

    if(Head == NULL)    
    {
        return false;
    }
    else                
    {
        while(Head != NULL)
        {
            if(Head->data == no)   
            {
                break;
            }
            else if(no > (Head->data))   
            {
                Head = Head->rchild;    
            }
            else if(no < (Head->data)) 
            {
                Head = Head->lchild;   
            }
            
        }

        if(Head == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Count
// Input:			Head
// Output:			Integer
// Description:		It Used to Count elements in BST.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template<class T>
int BST<T>::Count(PNODE Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        iCnt++;
        Count(Head->lchild);
        Count(Head->rchild);
    }
    return iCnt;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	CountLeaf
// Input:			Head
// Output:			Integer
// Description:		It Used to Count Leaves in BST.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template<class T>
int BST<T>::CountLeaf(PNODE Head)
{
    static int icnt = 0;

    if(Head != NULL)
    {
        if((Head->lchild == NULL) && (Head->rchild == NULL))
        {
            icnt++;
        }
        CountLeaf(Head->lchild);
        CountLeaf(Head->rchild);
    }
    return icnt;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	CountParent
// Input:			Head
// Output:			Integer
// Description:		It Used to Count Parents in BST.
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template<class T>
int BST<T>::CountParent(PNODE Head)
{
    static int icnt = 0;

    if(Head != NULL)
    {
        if((Head->lchild != NULL) || (Head->rchild != NULL))
        {
            icnt++;
        }
        CountParent(Head->lchild);
        CountParent(Head->rchild);
    }
    return icnt;
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Inorder
// Input:			Head
// Output:			Nothing
// Description:		It Used to Display elements in BST(LRR).
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>::Inorder(PNODE Head)
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);     
        cout<<Head->data<<"\n";     
        Inorder(Head->rchild);      
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Postorder
// Input:			Head
// Output:			Nothing
// Description:		It Used to Display elements in BST(LRR).
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>::Postorder(PNODE Head)
{
    if(Head != NULL)
    {
        Postorder(Head->lchild);      
        Postorder(Head->rchild);      
        cout<<Head->data<<"\n";     
    }
}

///////////////////////////////////////////////////////////////////////
//
// Function name:	Preorder
// Input:			Head
// Output:			Nothing
// Description:		It Used to Display elements in BST(RRL).
// Author:  		Shreyas Girish Kulkarni
// Date:			19/11/2021
//
//////////////////////////////////////////////////////////////////////
template<class T>
void BST<T>::Preorder(PNODE Head)
{
    if(Head != NULL)
    {
        cout<<Head->data<<"\n";     
        Preorder(Head->lchild);      
        Preorder(Head->rchild);      
    }
}

///////////////////////////////////////////////////////////////////////