#pragma once

template <typename T>
class Gvector
{
    // 접근 제한자
private: // 멤버 변수
    T* vec_ptr;
    int vec_cnt;
    int vec_max;

public: // 멤버 함수
    void push_back(const T& data);
    void pop_back();

    T& at(const unsigned int& idx);

    int size();
    int capacity();
    void resize(const unsigned int& new_size);

    // 이너클래스 iterator //////////////////////////////
    class iterator
    {
    };

public: // 연산자 오버로딩 operator
    // Gvector& operator=
    T& operator[](const unsigned int& idx);

public:
    Gvector();  // 생성자
    ~Gvector(); // 소멸자
};


template <typename T>
Gvector<T>::Gvector() : vec_ptr(nullptr), vec_cnt(0), vec_max(0)
{
}

template <typename T>
Gvector<T>::~Gvector()
{
    delete[] vec_ptr;
}

template <typename T>
T& Gvector<T>::operator[](const unsigned int& idx)
{
    return vec_ptr[idx];
}

template <typename T>
T& Gvector<T>::at(const unsigned int& idx)
{
    return vec_ptr[idx];
}

template <typename T>
void Gvector<T>::push_back(const T& data)
{
    if (vec_ptr == nullptr || (vec_cnt == vec_max))
        resize(vec_max * 2);

    vec_ptr[vec_cnt++] = data;
}

template <typename T>
void Gvector<T>::pop_back()
{
}

template <typename T>
int Gvector<T>::size()
{
    return vec_cnt;
}

template <typename T>
int Gvector<T>::capacity()
{
    return vec_max;
}

template <typename T>
void Gvector<T>::resize(const unsigned int& new_size)
{
    T* new_vec = new int[new_size == 0 ? 1 : new_size];

    for (int i = 0; i < vec_max; i++)
        new_vec[i] = vec_ptr[i];

    delete[] vec_ptr;
    vec_ptr = new_vec;
    vec_max = new_size == 0 ? 1 : new_size;
}
