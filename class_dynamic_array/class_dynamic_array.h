#pragma once

// 가변 배열 클래스 정의
class ClassDynamicArray
{
    // 사적 멤버 변수 선언
private:
    int *p_array; // 가변 배열 시작 주소
    int arr_len;  // 가변 배열 길이
    int max_len;  // 가변 배열 최대 길이

    // 공적 멤버 함수 선언
public:
    void PrintArray();                           // 가변 배열 데이터 출력
    void PushBackData(int _data);                // 데이터 삽입
    void DeleteData(int _data);                  // 데이터 삭제
    void ResizeArray(const unsigned int _count); // 가변 배열 리사이즈

private:                                      // 연산자 오버로딩 미지원 처리
    int &operator[](const unsigned int _idx); // 연산자 오버로딩

    // 생성자 소멸자 선언
public:
    ClassDynamicArray();  // 생성자
    ~ClassDynamicArray(); // 소멸자
};