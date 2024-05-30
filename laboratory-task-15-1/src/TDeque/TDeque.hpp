#ifndef FUNC_HPP
#define FUNC_HPP
#include <iostream>

template  <typename TInfo>
class TDeque /* дек – двустороння очередь */
{
protected:
struct TDequeItem // элемент дека
{
TInfo Info; // данные
TDequeItem* next; // указатель на следующий элемент
TDequeItem* prev; // указатель на предыдущий элемент
TDequeItem(TInfo info) : Info(info), next(nullptr), prev(nullptr) {}
};
/* указатели на первый и последний элементы в списке */
TDequeItem *front, *rear;
int size; // количество элементов в деке
void Erase(); // удаление всех элементов
void Clone(const TDeque&);
void DeleteItem(TDequeItem*); // удаление элемента по указателю
TDequeItem* PtrByIndex(unsigned) const;
// указатель на элемент с заданным индексом
public:
TDeque(); // конструктор
TDeque(const TDeque &); // конструктор копирования
virtual ~TDeque(); // деструктор
void InsFront(TInfo); // включить элемент в голову дека
void InsRear(TInfo); // включить элемент в хвост дека
bool DelFront(TInfo &); // исключить элемент из головы дека
bool DelRear(TInfo &); // исключить элемент из хвоста дека
const TDeque& operator = (const TDeque &); // оператор присваивания
const TInfo& GetByIndex(unsigned)const; // получить элемент по индексу
void SetByIndex(TInfo, unsigned); // изменить элемент по индексу
void Browse(void(*func)(TInfo&)); // просмотр с изменением элементов
void Browse(void(*func)(TInfo)) const; // просмотр без изменения элементов
void print();
};


template  <typename TInfo>
TDeque<TInfo>::TDeque():front(nullptr), rear(nullptr)
{ }

template  <typename TInfo>
TDeque<TInfo>::TDeque(const TDeque<TInfo> &rhs)
{
    Clone(rhs);
}

template  <typename TInfo>
TDeque<TInfo>::~TDeque()
{
    Erase();
}

template  <typename TInfo>
void TDeque<TInfo>::Erase()
{
    while(front != nullptr){
        TDequeItem* temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
}

template  <typename TInfo>
 void TDeque<TInfo>::Clone(const TDeque<TInfo>& other) {
        TDequeItem* current = other.front;
        while (current != nullptr) {
            InsRear(current->Info);
            current = current->next;
        }
    }

template <typename TInfo>
void TDeque<TInfo>::DeleteItem(TDequeItem* item) {
    if (item == front) {
        TInfo info;
        DelFront(info);
    } else if (item == rear) {
        TInfo info;
        DelRear(info);
    } else {
        item->prev->next = item->next;
        item->next->prev = item->prev;
        delete item;
    }
}

template <typename TInfo>
typename TDeque<TInfo>::TDequeItem* TDeque<TInfo>::PtrByIndex(unsigned index) const {

    TDequeItem* current = front;
    for (unsigned i = 0; i < index; ++i) {
        current = current->next;
    }

    return current;
}

template  <typename TInfo>
void  TDeque<TInfo>::InsFront(TInfo info) {
    TDequeItem* newItem = new TDequeItem(info);
        if (front == nullptr) {
            front = rear = newItem;
        } else {
            newItem->next = front;
            front->prev = newItem;
            front = newItem;
        }
    }

    template  <typename TInfo>
    void TDeque<TInfo>::InsRear(TInfo info) {
        TDequeItem* newItem = new TDequeItem(info);
        if (rear == nullptr) {
            front = rear = newItem;
        } else {
            newItem->prev = rear;
            rear->next = newItem;
            rear = newItem;
        }
    }

    template  <typename TInfo>
    bool TDeque<TInfo>::DelFront(TInfo& info) {
        if (front == nullptr)
            return false;
        info = front->Info;
        TDequeItem* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        
        delete temp;

        return true;
    }

    template  <typename TInfo>
    bool TDeque<TInfo>::DelRear(TInfo& info) {
        if (rear == nullptr)
            return false;
        info = rear->Info;
        TDequeItem* temp = rear;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }

        delete temp;

        return true;
    }

    template  <typename TInfo>
    const TDeque<TInfo>& TDeque<TInfo>::operator=(const TDeque& other) {
        if (this != &other) {
            Erase();
            Clone(other);
        }
        return *this;
    }

   template  <typename TInfo>
    const TInfo& TDeque<TInfo>::GetByIndex(unsigned index) const {
        TDequeItem* item = PtrByIndex(index);

        if (item == nullptr)
        {
            throw std::out_of_range("Index out of range");
        }

        return item->Info;
    }

    template  <typename TInfo>
    void TDeque<TInfo>::SetByIndex(TInfo info, unsigned index) {
        TDequeItem* item = PtrByIndex(index);

        if (item == nullptr)
        {
            throw std::out_of_range("Index out of range");
        }

        item->Info = info;
    }

    template  <typename TInfo>
    void TDeque<TInfo>::Browse(void(*func)(TInfo&)) {
        TDequeItem* current = front;
        while (current != nullptr) {
            func(current->Info);
            current = current->next;
        }
    }

    template  <typename TInfo>
    void TDeque<TInfo>::Browse(void(*func)(TInfo)) const {
        TDequeItem* current = front;
        while (current != nullptr) {
            func(current->Info);
            current = current->next;
        }
    }

    template <typename TInfo>
    inline void TDeque<TInfo>::print()
    {
         TDequeItem *temp = front;
        while (temp != nullptr)
        {
        std::cout << temp->Info << " ";
        temp = temp->next;
        }
        std::cout << "\n";
    }

#endif 