#pragma once

#include <iostream>

using namespace std;

/* 클래스 템플릿은 선언 정의 한 파일에서 */

// 클래스 템플릿 가변 배열 정의
template <typename T>
class ClassDynamicArray
{
    // 사적 멤버 변수 선언
private:
    T *p_array;  // 가변 배열 시작 주소
    int arr_len; // 가변 배열 길이
    int max_len; // 가변 배열 최대 길이

    // 공적 멤버 함수 선언
public:
    void PrintArray();                           // 가변 배열 데이터 출력
    void PushBackData(const T &_data);           // 데이터 삽입
    void DeleteData(const T &_data);             // 데이터 삭제
    void ResizeArray(const unsigned int _count); // 가변 배열 리사이즈

    T &operator[](const unsigned int _idx); // 연산자 오버로딩

    // 생성자 소멸자 선언
public:
    ClassDynamicArray();  // 생성자
    ~ClassDynamicArray(); // 소멸자
};

template <typename T>
ClassDynamicArray<T>::ClassDynamicArray() : p_array(nullptr), arr_len(0), max_len(1) // 생성자 정의
{
    // 가변 배열 동적 할당
    p_array = new T[1];
}

template <typename T>
ClassDynamicArray<T>::~ClassDynamicArray() // 소멸자 정의
{
    // 가변 배열 동적 할당 해제
    delete[] p_array;
}

template <typename T>
void ClassDynamicArray<T>::PrintArray() // 가변 배열 데이터 출력 정의
{
    cout << "p_array Address : " << p_array << endl;
    cout << "arr_len : " << arr_len << endl;
    cout << "max_len : " << max_len << endl;
    cout << endl;
    if (arr_len > 0)
    {
        cout << "Data ::" << endl;
        for (int i = 0; i < arr_len; i++)
            cout << p_array[i] << endl;
    }
}

template <typename T>
void ClassDynamicArray<T>::PushBackData(const T &_data) // 데이터 삽입 정의
{
    // 가변 배열이 풀 이라면
    if (arr_len == max_len)
        // 리사이즈(할당 사이즈 조절로 비용 조절 가능)
        ResizeArray(arr_len + 10);

    // 데이터 삽입
    p_array[arr_len++] = _data;
}

template <typename T>
void ClassDynamicArray<T>::DeleteData(const T &_data) // 데이터 삭제 정의
{
    for (int i = 0; i < arr_len; i++)
    {
        if (p_array[i] == _data)
            // 삭제 처리(삭제 아님)
            p_array[i] = 0;
    }
    // 가변 배열 길이 최적화 동시에 삭제 처리 데이터 삭제
    ResizeArray(0);
    arr_len--;
}

template <typename T>
void ClassDynamicArray<T>::ResizeArray(const unsigned int _count) // 가변 배열 리사이즈 정의
{
    // 기존 가변 배열에 존재하고 있는 데이터 개수에서 입력 받은 사이즈 만큼 더한 새로운 가변 배열 동적 할당
    T *p_new_array = new T[arr_len + _count];

    // 기존 가변 배열 데이터를 새로운 가변 배열로 복사
    int cnt = 0;
    for (int i = 0; i < arr_len + 1; i++)
    {
        if (p_array[i] != 0) // 삭제 처리된 데이터 제외 후 복사
            p_new_array[cnt++] = p_array[i];
    }

    // 기존 가변 배열 동적 할당 해제
    delete[] p_array;

    // 기본 가변 배열 주소를 새로 할당한 가변 배열 주소로 지정
    p_array = p_new_array;

    // 기본 가변 배열 최대 개수를 기존 배열 데이터 개수 + 입력 받은 사이즈 개수로 설정
    max_len = arr_len + _count;
}

template <typename T>
T &ClassDynamicArray<T>::operator[](const unsigned int _idx) // 연산자 오버로딩 정의
{
    // 연산자 오버로딩 지원
    return p_array[_idx];
}