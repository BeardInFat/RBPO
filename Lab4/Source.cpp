#include <iostream>
using namespace std;

struct Node {//Структура Узел с конструктором, значением и указателем на следующий узел списка
    int val;
    Node* Next;
    Node(int _val) : val(_val), Next(nullptr) {}
};

std::ostream& operator<< (std::ostream& os, Node* node)//Если поступает указатель на узел, также выводятся все следующие за ним узлы
{
    if (node == nullptr)
        return os;
    return os << node->val << " " << node->Next;
}

std::ostream& operator<< (std::ostream& os, Node node)//Если поступает узел, выводится только его значение
{
    return os << node.val;
}



class UnidirectionalLinkedList
{
    Node* Head, * Tail; //Указатели на начало списка и на конец
public:
    UnidirectionalLinkedList() : Head(nullptr), Tail(nullptr) {}; //Конструктор по умолчанию
    UnidirectionalLinkedList(const UnidirectionalLinkedList& list); //Конструктор копирования
    UnidirectionalLinkedList(UnidirectionalLinkedList&& other); //Конструктор перемещения
    UnidirectionalLinkedList(std::initializer_list<int> i0); //Конструктор, принимающий на вход std::initializer_list
    ~UnidirectionalLinkedList(); //Деструктор

    unsigned int GetSize() const;//возвращает количество узлов в списке
    void InsertAt(int value, int index);//вставляет на данный индекс новый узел со значением value
    int RemoveAt(int index);//удаляет с данного индекса узел
    Node getHead() { return Node(Head->val); }//возвращает копию первого члена списка
    Node getTail() { return Node(Tail->val); }//возвращает копию последнего члена списка

    UnidirectionalLinkedList& operator=(const UnidirectionalLinkedList& other);//Операция присваивания
    UnidirectionalLinkedList& operator=(UnidirectionalLinkedList&& other);//Операция присваивания с перемещением
    UnidirectionalLinkedList& operator=(std::initializer_list<int> ilist);// Операция присваивания листу инициализации
    friend std::ostream& operator<< (std::ostream& os, UnidirectionalLinkedList& list);//Оператор вывода списка

};

UnidirectionalLinkedList::UnidirectionalLinkedList(const UnidirectionalLinkedList& list) //Конструктор копирования
{
    Head = new Node(list.Head->val);
    Tail = Head;
    Node* temp = list.Head;
    while (temp->Next != nullptr)
    {
        temp = temp->Next;
        Tail->Next = new Node(temp->val);
        Tail = Tail->Next;
    }
}
UnidirectionalLinkedList::UnidirectionalLinkedList(UnidirectionalLinkedList&& other) //Конструктор перемещения
{
    Head = other.Head;
    Tail = other.Tail;
    other.Head = nullptr;
    other.Tail = nullptr;
}
UnidirectionalLinkedList::UnidirectionalLinkedList(std::initializer_list<int> ilist) //Конструктор, принимающий на вход std::initializer_list
{
    const int* initptr = ilist.begin();
    Head = new Node(*initptr);
    Tail = Head;
    initptr++;
    const int* endptr = ilist.end();
    while (initptr != endptr)
    {
        Tail->Next = new Node(*initptr);
        Tail = Tail->Next;
        initptr++;
    }
}
UnidirectionalLinkedList::~UnidirectionalLinkedList() //Деструктор
{
    Node* temp = Head; //Временный указатель на начало списка
    while (temp != nullptr) //Пока в списке что-то есть

    {
        temp = Head->Next; //Резерв адреса на следующий элемент списка
        delete Head;  //Освобождение памяти от первой структуры как элемента списка

        Head = temp;  //Сдвиг начала на следующий адрес, который берем из резерва

    }
    Head = nullptr;
    Tail = nullptr;
}

unsigned int UnidirectionalLinkedList::GetSize() const//возвращает количество узлов в списке
{
    if (Head == nullptr)
        return 0;
    int i = 1;
    Node* temp = Head;
    while (temp->Next != nullptr)
    {
        temp = temp->Next;
        i++;
    }
    return i;
}
void UnidirectionalLinkedList::InsertAt(int value, int index)//вставляет на данный индекс новый узел со значением value
{
    if (index < 1) return;
    if (index == 1)
    {
        Node* temp = Head;
        Head = new Node(value);
        Head->Next = temp;
        return;
    }
    int i = 2;
    Node* temp = Head;
    while (temp->Next != nullptr || i < index)
    {
        i++;
        temp = temp->Next;
    }
    if (i == index || temp->Next == nullptr)
    {
        Node* temp1 = temp->Next;
        temp->Next = new Node(value);
        temp->Next->Next = temp1;
    }
}
int UnidirectionalLinkedList::RemoveAt(int index)//удаляет с данного индекса узел
{
    if (index < 1) return 0;
    if (index == 1)
    {
        Node* temp = Head;
        Head = Head->Next;
        delete temp;
        return 1;
    }
    int i = 2;
    Node* temp = Head;
    while (temp->Next != nullptr || i < index)
    {
        i++;
        temp = temp->Next;
    }
    if (i == index)
    {
        Node* temp1 = temp->Next;
        temp->Next = temp1->Next;
        delete temp1;
        return 1;
    }
    return 0;
}

UnidirectionalLinkedList& UnidirectionalLinkedList::operator=(const UnidirectionalLinkedList& other)//Операция присваивания
{
    if (this == &other)
    {
        return *this;
    }
    Node* temp = Head; //Временный указатель на начало списка
    while (temp != NULL) //Пока в списке что-то есть

    {
        temp = Head->Next; //Резерв адреса на следующий элемент списка
        delete Head;  //Освобождение памяти от первой структуры как элемента списка

        Head = temp;  //Сдвиг начала на следующий адрес, который берем из резерва

    }
    Head = new Node(other.Head->val);
    Tail = Head;
    temp = other.Head;
    while (temp->Next != nullptr)
    {
        temp = temp->Next;
        Tail->Next = new Node(temp->val);
        Tail = Tail->Next;
    }
    return *this;
}
UnidirectionalLinkedList& UnidirectionalLinkedList::operator=(UnidirectionalLinkedList&& other)//Операция присваивания с перемещением
{
    if (this == &other)
    {
        return *this;
    }
    Node* temp = Head; //Временный указатель на начало списка
    while (temp != NULL) //Пока в списке что-то есть

    {
        temp = Head->Next; //Резерв адреса на следующий элемент списка
        delete Head;  //Освобождение памяти от первой структуры как элемента списка

        Head = temp;  //Сдвиг начала на следующий адрес, который берем из резерва

    }
    Head = other.Head;
    Tail = other.Tail;
    other.Head = nullptr;
    other.Tail = nullptr;
    return *this;
}
UnidirectionalLinkedList& UnidirectionalLinkedList::operator=(std::initializer_list<int> ilist)// Операция присваивания листу инициализации
{
    Node* temp = Head; //Временный указатель на начало списка
    while (temp != NULL) //Пока в списке что-то есть
    {
        temp = Head->Next; //Резерв адреса на следующий элемент списка
        delete Head;  //Освобождение памяти от первой структуры как элемента списка

        Head = temp;  //Сдвиг начала на следующий адрес, который берем из резерва

    }
    const int* initptr = ilist.begin();
    Head = new Node(*initptr);
    Tail = Head;
    initptr++;
    const int* endptr = ilist.end();
    while (initptr != endptr)
    {
        Tail->Next = new Node(*initptr);
        Tail = Tail->Next;
        initptr++;
    }
    return *this;
}

std::ostream& operator<< (std::ostream& os, UnidirectionalLinkedList& list)//Оператор вывода списка
{
    return os << list.Head;
}

class QueueBasedOnUnidirectionalLinkedList : public UnidirectionalLinkedList//Наследование 
{
public:
    using UnidirectionalLinkedList::UnidirectionalLinkedList;
    bool Push(const Node& element);
    bool Pop(Node& element);
    bool Peek(Node& element);
};

bool QueueBasedOnUnidirectionalLinkedList::Push(const Node& element)
{
    if (this->GetSize() >= 50)
        return 0;
    InsertAt(element.val, GetSize() + 1);
    return 1;
}
bool QueueBasedOnUnidirectionalLinkedList::Pop(Node& element)
{
    element = getHead();
    RemoveAt(1);
    return (GetSize() > 0);
}
bool QueueBasedOnUnidirectionalLinkedList::Peek(Node& element)
{
    element = getHead();
    return (GetSize() > 0);
}

void main()
{
    std::initializer_list<int> i0 = { 7, 2, 3, 4, 5 };
    QueueBasedOnUnidirectionalLinkedList l = i0;
    Node a = 1;
    cout << l << endl << l.GetSize() << endl << l.Peek(a); cout << endl << a;

}
