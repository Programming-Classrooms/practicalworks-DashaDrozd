#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* topNode; 
    size_t stackSize; 

public:
    // Конструктор по умолчанию
    Stack() : topNode(nullptr), stackSize(0) {}

    // Конструктор копирования
    Stack(const Stack& other) : topNode(nullptr), stackSize(0) {
        if (other.topNode) {
            topNode = new Node(other.topNode->data);
            Node* current = topNode;
            Node* otherCurrent = other.topNode->next;

            while (otherCurrent) {
                current->next = new Node(otherCurrent->data);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
            stackSize = other.stackSize;
        }
    }

    // Деструктор
    ~Stack() {
        while (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // Оператор присваивания
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            Stack temp(other);
            std::swap(topNode, temp.topNode);
            std::swap(stackSize, temp.stackSize);
        }
        return *this;
    }

    // Оператор []
    const T& operator[](size_t index) const {
        if (index >= stackSize) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = topNode;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Вставка элемента в стек
    void push(const T& element) {
        Node* newNode = new Node(element);
        newNode->next = topNode;
        topNode = newNode;
        ++stackSize;
    }

    // Удаление элемента из стека
    void pop() {
        if (!topNode) {
            throw std::out_of_range("Stack is empty");
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        --stackSize;
    }

    // Просмотр элемента в вершине стека без его удаления
    const T& top() const {
        if (!topNode) {
            throw std::out_of_range("Stack is empty");
        }
        return topNode->data;
    }

    // Просмотр всех элементов, находящихся в стеке
    void print() const {
        Node* current = topNode;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return topNode == nullptr;
    }

    // Получение размера стека
    size_t size() const {
        return stackSize;
    }
};

#endif // STACK_HPP
