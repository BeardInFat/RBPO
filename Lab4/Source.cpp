#include <iostream>
using namespace std;

struct Node {//��������� ���� � �������������, ��������� � ���������� �� ��������� ���� ������
    int val;
    Node* Next;
    Node(int _val) : val(_val), Next(nullptr) {}
};

std::ostream& operator<< (std::ostream& os, Node* node)//���� ��������� ��������� �� ����, ����� ��������� ��� ��������� �� ��� ����
{
    if (node == nullptr)
        return os;
    return os << node->val << " " << node->Next;
}

std::ostream& operator<< (std::ostream& os, Node node)//���� ��������� ����, ��������� ������ ��� ��������
{
    return os << node.val;
}



class UnidirectionalLinkedList
{
    Node* Head, * Tail; //��������� �� ������ ������ � �� �����
public:
    UnidirectionalLinkedList() : Head(nullptr), Tail(nullptr) {}; //����������� �� ���������
    UnidirectionalLinkedList(const UnidirectionalLinkedList& list); //����������� �����������
    UnidirectionalLinkedList(UnidirectionalLinkedList&& other); //����������� �����������
    UnidirectionalLinkedList(std::initializer_list<int> i0); //�����������, ����������� �� ���� std::initializer_list
    ~UnidirectionalLinkedList(); //����������

    unsigned int GetSize() const;//���������� ���������� ����� � ������
    void InsertAt(int value, int index);//��������� �� ������ ������ ����� ���� �� ��������� value
    int RemoveAt(int index);//������� � ������� ������� ����
    Node getHead() { return Node(Head->val); }//���������� ����� ������� ����� ������
    Node getTail() { return Node(Tail->val); }//���������� ����� ���������� ����� ������

    UnidirectionalLinkedList& operator=(const UnidirectionalLinkedList& other);//�������� ������������
    UnidirectionalLinkedList& operator=(UnidirectionalLinkedList&& other);//�������� ������������ � ������������
    UnidirectionalLinkedList& operator=(std::initializer_list<int> ilist);// �������� ������������ ����� �������������
    friend std::ostream& operator<< (std::ostream& os, UnidirectionalLinkedList& list);//�������� ������ ������

};

UnidirectionalLinkedList::UnidirectionalLinkedList(const UnidirectionalLinkedList& list) //����������� �����������
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
UnidirectionalLinkedList::UnidirectionalLinkedList(UnidirectionalLinkedList&& other) //����������� �����������
{
    Head = other.Head;
    Tail = other.Tail;
    other.Head = nullptr;
    other.Tail = nullptr;
}
UnidirectionalLinkedList::UnidirectionalLinkedList(std::initializer_list<int> ilist) //�����������, ����������� �� ���� std::initializer_list
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
UnidirectionalLinkedList::~UnidirectionalLinkedList() //����������
{
    Node* temp = Head; //��������� ��������� �� ������ ������
    while (temp != nullptr) //���� � ������ ���-�� ����

    {
        temp = Head->Next; //������ ������ �� ��������� ������� ������
        delete Head;  //������������ ������ �� ������ ��������� ��� �������� ������

        Head = temp;  //����� ������ �� ��������� �����, ������� ����� �� �������

    }
    Head = nullptr;
    Tail = nullptr;
}

unsigned int UnidirectionalLinkedList::GetSize() const//���������� ���������� ����� � ������
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
void UnidirectionalLinkedList::InsertAt(int value, int index)//��������� �� ������ ������ ����� ���� �� ��������� value
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
int UnidirectionalLinkedList::RemoveAt(int index)//������� � ������� ������� ����
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

UnidirectionalLinkedList& UnidirectionalLinkedList::operator=(const UnidirectionalLinkedList& other)//�������� ������������
{
    if (this == &other)
    {
        return *this;
    }
    Node* temp = Head; //��������� ��������� �� ������ ������
    while (temp != NULL) //���� � ������ ���-�� ����

    {
        temp = Head->Next; //������ ������ �� ��������� ������� ������
        delete Head;  //������������ ������ �� ������ ��������� ��� �������� ������

        Head = temp;  //����� ������ �� ��������� �����, ������� ����� �� �������

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
UnidirectionalLinkedList& UnidirectionalLinkedList::operator=(UnidirectionalLinkedList&& other)//�������� ������������ � ������������
{
    if (this == &other)
    {
        return *this;
    }
    Node* temp = Head; //��������� ��������� �� ������ ������
    while (temp != NULL) //���� � ������ ���-�� ����

    {
        temp = Head->Next; //������ ������ �� ��������� ������� ������
        delete Head;  //������������ ������ �� ������ ��������� ��� �������� ������

        Head = temp;  //����� ������ �� ��������� �����, ������� ����� �� �������

    }
    Head = other.Head;
    Tail = other.Tail;
    other.Head = nullptr;
    other.Tail = nullptr;
    return *this;
}
UnidirectionalLinkedList& UnidirectionalLinkedList::operator=(std::initializer_list<int> ilist)// �������� ������������ ����� �������������
{
    Node* temp = Head; //��������� ��������� �� ������ ������
    while (temp != NULL) //���� � ������ ���-�� ����
    {
        temp = Head->Next; //������ ������ �� ��������� ������� ������
        delete Head;  //������������ ������ �� ������ ��������� ��� �������� ������

        Head = temp;  //����� ������ �� ��������� �����, ������� ����� �� �������

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

std::ostream& operator<< (std::ostream& os, UnidirectionalLinkedList& list)//�������� ������ ������
{
    return os << list.Head;
}

class QueueBasedOnUnidirectionalLinkedList : public UnidirectionalLinkedList//������������ 
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
