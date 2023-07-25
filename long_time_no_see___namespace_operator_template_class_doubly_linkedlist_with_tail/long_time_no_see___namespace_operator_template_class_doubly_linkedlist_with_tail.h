#pragma once

namespace gun
{
    template <typename T>
    class Node
    {
    public:
        Node<T>* prev_node;
        T node_data;
        Node<T>* next_node;

    public:
        static void TypeSize();

    public:
        Node();
        Node(const T& data);
    };

    template <typename T>
    void Node<T>::TypeSize()
    {
        printf("%dByte Type\n", sizeof(T));
    }

    template <typename T>
    Node<T>::Node() : prev_node(nullptr), node_data(), next_node(nullptr)
    {
    }

    template <typename T>
    Node<T>::Node(const T& data) : prev_node(nullptr), node_data(data), next_node(nullptr)
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    template <typename T>
    class List
    {
    private:
        Node<T>* head_node;
        Node<T>* tail_node;
        int node_cnt;

    public:
        void PrintList();
        void PushBack(const T& data);
        void PushFront(const T& data);
        void PopBack();
        void PopFront();

    public:
        static void TypeSize();

    public:
        void operator>>(const T& data);
        void operator<<(const T& data);

    public:
        List();
        ~List();
    };

    template <typename T>
    List<T>::List() : head_node(nullptr), tail_node(nullptr), node_cnt(0)
    {
    }

    template <typename T>
    List<T>::~List()
    {
        Node<T>* ptr_node = head_node;

        while (ptr_node)
        {
            ptr_node = head_node->next_node;
            delete head_node;
            head_node = ptr_node;
        }
    }

    template <typename T>
    void List<T>::operator>>(const T& data)
    {
        PushBack(data);
    }

    template <typename T>
    void List<T>::operator<<(const T& data)
    {
        PushFront(data);
    }

    template <typename T>
    void List<T>::TypeSize()
    {
        printf("%dByte Type\n", sizeof(T));
    }

    template <typename T>
    void List<T>::PrintList()
    {
        Node<T>* ptr_node = head_node;

        if (ptr_node == nullptr)
        {
            printf("List is NULL\n");
        }

        while (ptr_node)
        {
            printf("%d\t : %p", ptr_node->node_data, ptr_node);

            if (ptr_node == head_node)
                printf(" <-Head");
            if (ptr_node == tail_node)
                printf(" <-Tail");
            printf("\n");
            
            ptr_node = ptr_node->next_node;
        }
    }

    template <typename T>
    void List<T>::PushBack(const T& data)
    {
        Node<T>* ptr_node = new Node<T>(data);

        if (head_node == nullptr)
        {
            head_node = ptr_node;
            tail_node = ptr_node;
        }
        else
        {
            ptr_node->prev_node = tail_node;
            tail_node->next_node = ptr_node;
            tail_node = ptr_node;
        }

        node_cnt++;
    }

    template <typename T>
    void List<T>::PushFront(const T& data)
    {
        Node<T>* ptr_node = new Node<T>(data);

        if (head_node == nullptr)
        {
            head_node = ptr_node;
            tail_node = ptr_node;
        }
        else
        {
            ptr_node->next_node = head_node;
            head_node->prev_node = ptr_node;
            head_node = ptr_node;
        }

        node_cnt++;
    }

    template <typename T>
    void List<T>::PopBack()
    {
        Node<T>* ptr_node = tail_node;

        if (ptr_node)
        {
            ptr_node = tail_node->prev_node;
            delete tail_node;
            tail_node = ptr_node;

            if (--node_cnt == 0)
                head_node = nullptr;
            else
                tail_node->next_node = nullptr;
        }
    }

    template <typename T>
    void List<T>::PopFront()
    {
        Node<T>* ptr_node = head_node;

        if (ptr_node)
        {
            ptr_node = head_node->next_node;
            delete head_node;
            head_node = ptr_node;

            if (--node_cnt == 0)
                tail_node = nullptr;
            else
                head_node->prev_node = nullptr;
        }
    }
}