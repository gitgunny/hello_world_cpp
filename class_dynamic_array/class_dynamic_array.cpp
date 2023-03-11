#include "class_dynamic_array.h"
#include <iostream>

using namespace std;

ClassDynamicArray::ClassDynamicArray() : p_array(nullptr), arr_len(0), max_len(1) // 생성자 정의
{
    // 가변 배열 동적 할당
    p_array = new int[1];
}

ClassDynamicArray::~ClassDynamicArray() // 소멸자 정의
{
    // 가변 배열 동적 할당 해제
    delete[] p_array;
}

void ClassDynamicArray::PrintArray() // 가변 배열 데이터 출력 정의
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

void ClassDynamicArray::PushBackData(int _data) // 데이터 삽입 정의
{
    // 가변 배열이 풀 이라면
    if (arr_len == max_len)
        // 리사이즈(할당 사이즈 조절로 비용 조절 가능)
        ResizeArray(arr_len + 10);

    // 데이터 삽입
    p_array[arr_len++] = _data;
}

void ClassDynamicArray::DeleteData(int _data) // 데이터 삭제 정의
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

void ClassDynamicArray::ResizeArray(const unsigned int _count) // 가변 배열 리사이즈 정의
{
    // 기존 가변 배열에 존재하고 있는 데이터 개수에서 입력 받은 사이즈 만큼 더한 새로운 가변 배열 동적 할당
    int *p_new_array = new int[arr_len + _count];

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

int &ClassDynamicArray::operator[](const unsigned int _idx) // 연산자 오버로딩 정의
{
    // 연산자 오버로딩 지원
    return p_array[_idx];
}