#ifndef LIST_H
#define LIST_H

template<typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(T = T(), Node* = nullptr);
    };

    Node* head;
    size_t size;

public:
    List();
    List(const List&);
    ~List();
    List& operator=(const List&);
    void clear();
    void insertFront(const T&);
    void insertEnd(const T&);
    void deleteFront();
    void deleteEnd();
    void deleteValue(const T&);
    bool find(const T&, size_t&) const;
    void forEachModify(T (*func)(T));
    void forEachCallback(void (*func)(const T&)) const;
    void print() const;

};

    //Коструктор с параметром для узла
    template <typename T>
    List<T>::Node::Node(T rhsData, Node* rhsNext ) : data(rhsData), next(rhsNext)
{}

    //Конструктор по умолчанию
    template <typename T>
    List<T>::List(): head(nullptr) {}

    // Конструктор копирования
    template <typename T>
    List<T>::List(const List& rhs) : head(nullptr) 
    {
        Node* current = rhs.head;
        while (current != nullptr) 
        {
            insertEnd(current->data);
            current = current->next;
        }
    }

    //Деструктор
    template <typename T>
    List<T>::~List() 
    {
        clear();
    }


    // Перегрузка оператора присваивания

    template<typename T>
    List<T>& List<T>::operator=(const List& rhs)
    {
          if (this != &rhs)
           {
            clear();
            Node* current = rhs.head;
            while (current != nullptr) 
            {
                insertEnd(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    //Функция очистки списка
    template <typename T>
    void List<T>::clear() 
    {
        while (head != nullptr) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    //Вставка элемента в начало
    template <typename T>
    void List<T>::insertFront(const T& data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    //Вставка элемента в конец
    template <typename T>
    void List<T>::insertEnd(const T& data)
    {
        if (head == nullptr) {
            insertFront(data);
        } else {
            Node* newNode = new Node(data);
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            size++;
        }
    }

    //Удаление первого элемента
    template <typename T>
    void List<T>::deleteFront() 
    {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    //Удаление последнего элемента
    template <typename T>
    void List<T>::deleteEnd() 
    {
        if (head != nullptr) 
        {
            if (head->next == nullptr) 
            {
                deleteFront();
            } 
            else 
            {
                Node* current = head;

                while (current->next->next != nullptr) 
                {
                    current = current->next;
                }

                delete current->next;
                current->next = nullptr;
                size--;
            }
        }
    }

    //Удаление элемента по значению
    template <typename T>
    void List<T>::deleteValue( const T& value)
     {
        Node* current = new Node;
        current = head;
        Node* prev = nullptr;

        while (current != nullptr) 
        {
            if (current->data == value) 
            {
                if (prev == nullptr) 
                {
                    deleteFront();
                } 
                else 
                {
                    prev->next = current->next;
                    delete current;
                    size--;
                }

                return;
            }

            prev = current;
            current = current->next;
        }
    }

    //Поиск элемента по значению с подсчетом числа сравнений
    template <typename T>
    bool List<T>::find( const T& value, size_t& comparisons) const 
    {
        comparisons = 0;
        Node* current = new Node;
        current = head;

        while (current != nullptr) 
        {
            comparisons++;
            if (current->data == value) 
            {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    //просмотр списка с изменением всех значений
    template <typename T>
    void List<T>::forEachModify(T(*func)(T)) 
    {
        Node* current = head;

        while (current != nullptr) 
        {
            current->data = func(current->data);
            current = current->next;
        }

    }

    //просмотр списка с вызовом callback-функции, которая не изменяет хранящееся значение
    template <typename T>
    void List<T>::forEachCallback(void(*func)(const T&)) const 
    {
        Node* current = head;

        while (current != nullptr) 
        {
            func(current->data);
            current = current->next;
        }
    }

    //Печать списка
    template <typename T>
    void List<T>::print() const 
    {
        Node* current = head;

        while (current != nullptr) 
        {
            std::cout << current->data;
            current = current->next;
        }
    }

   #endif 