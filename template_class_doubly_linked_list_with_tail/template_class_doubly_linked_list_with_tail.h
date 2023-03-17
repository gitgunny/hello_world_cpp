#pragma once

#include <iostream>

// using namespace std;
using std::cin;
using std::cout;
using std::endl;

// 구조체 템플릿 정의
template <typename T>
struct STNode // Struct Template Node(Doubly)
{
    STNode<T> *pPrev; // 이전 노드 주소
    T data;           // 노드 데이터
    STNode<T> *pNext; // 다음 노드 주소

    // 구조체 템플릿 생성자 오버로딩 선언
    STNode(STNode<T> *_pPrev, const T &_data, STNode<T> *_pNext); // 노드 객체 생성 시
};

// 구조체 템플릿 생성자 오버로딩 정의
template <typename T>
STNode<T>::STNode(STNode<T> *_pPrev, const T &_data, STNode<T> *_pNext) : pPrev(_pPrev), data(_data), pNext(_pNext) // 노드 객체 생성 시 초기화
{
}

// 클래스 템플릿 정의
template <typename T>
class CTList // Class Template Linked List(Doubly Linked List with Tail)
{
    // 사적 접근 제한자
private:
    // 멤버 변수 선언
    unsigned int node_cnt; // 리스트 총 노드 개수
    STNode<T> *pHead;      // 헤드 주소
    STNode<T> *pTail;      // 테일 주소

    // 아래부터 공적 접근 제한자
public:
    // 멤버 함수 선언
    void PrintList();                         // 리스트 데이터 출력
    void PushFirstData(const T &_data);       // 첫번째 데이터 삽입
    void PushBackData(const T &_data);        // 후단 데이터 삽입
    void PushFrontData(const T &_data);       // 전단 데이터 삽입
    void DeleteData(const T &_data);          // 데이터 삭제
    void InitList(const CTList<T> &_ct_list); // 리스트 초기화

    // 연산자 오버로딩 선언
    CTList<T> &operator<(const T &_data);             // < 연산자 선언 시 PushBackData 호출
    CTList<T> &operator<<(const T &_data);            // << 연산자 선언 시 PushFrontData 호출
    CTList<T> &operator>(const T &_data);             // > 연산자 선언 시 DeleteData 호출
    CTList<T> &operator>>(const CTList<T> &_ct_list); // >> 연산자 선언 시 InitList 호출

public:
    CTList();  // 생성자 선언
    ~CTList(); // 소멸자 선언
};

// 생성자 정의
template <typename T>
CTList<T>::CTList() : node_cnt(0), pHead(nullptr), pTail(nullptr) // 리스트 객체 생성 시 초기화
{
}

// 소멸자 정의
template <typename T>
CTList<T>::~CTList() // 리스트 객체 소멸 시 동적 할당 해제
{
    // 데이터가 있다면
    if (pHead != nullptr)
    {
        STNode<T> *pNode = pHead;      // 추적 포인터 선언 후 첫번째(헤드) 노드 주소 대입
        STNode<T> *pTmpNode = nullptr; // 임시 추적 포인터 선언 후 null 주소 대입

        // pTmpNode에 다음 노드 주소를 대입시켜 놓고 pNode로 해제 후 pTmpNode를 추적하며 다음 노드가 없을 때까지(끝까지) 해제
        while (pNode != nullptr)
        {
            pTmpNode = pNode->pNext;
            delete pNode; // 해제
            pNode = pTmpNode;
        }
        // 멤버 변수 초기화
        node_cnt = 0;
        pHead = nullptr;
        pTail = nullptr;
    }
}

// < 연산자 오버로딩 정의(선언 시 PushBackData 호출)
template <typename T>
CTList<T> &CTList<T>::operator<(const T &_data)
{
    PushBackData(_data);

    return *this;
}

// << 연산자 오버로딩 정의(선언 시 PushFrontData 호출)
template <typename T>
CTList<T> &CTList<T>::operator<<(const T &_data)
{
    PushFrontData(_data);

    return *this;
}

// > 연산자 오버로딩 정의(선언 시DeleteData 호출)
template <typename T>
CTList<T> &CTList<T>::operator>(const T &_data)
{
    DeleteData(_data);

    return *this;
}

// >> 연산자 오버로딩 정의(선언 시 InitList 호출)
template <typename T>
CTList<T> &CTList<T>::operator>>(const CTList<T> &_ct_list)
{
    InitList(_ct_list);

    return *this;
}

// 리스트 데이터 출력
template <typename T>
void CTList<T>::PrintList()
{
    // 데이터가 있다면
    if (pHead != nullptr)
    {
        STNode<T> *pNode = pHead; // 추적 포인터 노드 선언 후 첫번째(헤드) 노드 주소 대입

        // 다음 노드가 없을때까지 추적
        while (pNode != nullptr)
        {
            cout << pNode->data;    // 데이터 출력
            if (pNode == pHead)     // 추적 포인터가 가리키는 곳이 헤드라면
                cout << " <- Head"; // " <- Head" 출력
            if (pNode == pTail)     // 추적 포인터가 가리키는 곳이 테일이라면
                cout << " <- Tail"; // " <- Tail" 출력
            cout << endl;
            pNode = pNode->pNext; // 다음 노드 추적
        }
    }
    // 데이터가 없다면
    else
    {
        // 데이터 없음 출력
        cout << "Empty Data" << endl;
    }
}

// 첫번째 데이터 삽입
template <typename T>
void CTList<T>::PushFirstData(const T &_data)
{
    STNode<T> *pNode = new STNode<T>(nullptr, _data, nullptr); // 동적 할당 된 노드 객체 생성(nullptr, _data, nullptr)

    pHead = pNode; // 생성된 노드 객체 헤드 지정
    pTail = pNode; // 생성된 노드 객체 테일 지정
    node_cnt++;    // 리스트 노드 개수 증가
}

// 후단 데이터 삽입
template <typename T>
void CTList<T>::PushBackData(const T &_data)
{
    // 데이터가 없다면
    if (pHead == nullptr)
    {
        PushFirstData(_data); // 헤드 생성
    }
    // 데이터가 있다면(테일 다음 노드 생성)
    else
    {
        STNode<T> *pNode = new STNode<T>(pTail, _data, nullptr); // 동적 할당 된 노드 객체 생성(pTail, _data, nullptr)

        pTail->pNext = pNode; // 테일 노드의 다음 노드를 생성된 노드로 지정
        pTail = pNode;        // 생성된 노드 객체 테일 지정
        node_cnt++;           // 리스트 노드 개수 증가
    }
}

// 전단 데이터 삽입
template <typename T>
void CTList<T>::PushFrontData(const T &_data)
{
    // 데이터가 없다면
    if (pHead == nullptr)
    {
        PushFirstData(_data); // 헤드 생성
    }
    // 데이터가 있다면(헤드 이전 노드 생성)
    else
    {
        STNode<T> *pNode = new STNode<T>(nullptr, _data, pHead); // 동적 할당 된 노드 객체 생성(nullptr, _data, pHead)

        pHead->pPrev = pNode; // 헤드 노드의 이전 노드를 생성된 노드로 지정
        pHead = pNode;        // 생성된 노드 객체 테일 지정
        node_cnt++;           // 리스트 노드 개수 증가
    }
}

// 데이터 삭제
template <typename T>
void CTList<T>::DeleteData(const T &_data)
{
    STNode<T> *pNode = pHead; // 추적 포인터 노드 선언 후 첫번째(헤드) 노드 주소 대입

    // 다음 노드가 없을때까지 추적
    while (pNode != nullptr)
    {
        // 삭제할 데이터를 찾았다면
        if (pNode->data == _data)
        {
            // 삭제할 노드가 헤드라면
            if (pNode == pHead)
            {
                // 헤드 다음 노드가 있다면
                if (pNode->pNext != nullptr)
                    pNode->pNext->pPrev = nullptr; // 헤드 다음 노드의 이전은 nullptr
                pHead = pNode->pNext;              // 헤드 다음 노드를 헤드로(null이면 null)
            }
            // 삭제할 노드가 테일이라면
            else if (pNode == pTail)
            {
                pNode->pPrev->pNext = nullptr; // 테일 이전 노드의 다음은 nullptr
                pTail = pNode->pPrev;          // 테일 이전 노드를 테일로(null이면 null)
            }
            // 삭제할 노드가 중간 노드라면
            else
            {
                // 중간 노드가 양 노드를 이어준다.
                pNode->pPrev->pNext = pNode->pNext;
                pNode->pNext->pPrev = pNode->pPrev;
            }
            delete pNode; // 동적 할당 해제
            node_cnt--;   // 리스트 노드 개수 감소
        }
        pNode = pNode->pNext; // 다음 노드 추적
    }
}

// 리스트 초기화
template <typename T>
void CTList<T>::InitList(const CTList<T> &_ct_list)
{
    // 데이터가 있다면
    if (pHead != nullptr)
    {
        STNode<T> *pNode = pHead;      // 추적 포인터 선언 후 첫번째(헤드) 노드 주소 대입
        STNode<T> *pTmpNode = nullptr; // 임시 추적 포인터 선언 후 null 주소 대입

        // pTmpNode에 다음 노드 주소를 대입시켜 놓고 pNode로 해제 후 pTmpNode를 추적하며 다음 노드가 없을 때까지(끝까지) 해제
        while (pNode != nullptr)
        {
            pTmpNode = pNode->pNext;
            delete pNode; // 해제
            pNode = pTmpNode;
        }
        // 멤버 변수 초기화
        node_cnt = 0;
        pHead = nullptr;
        pTail = nullptr;
    }
}