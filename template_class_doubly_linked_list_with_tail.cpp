#include <iostream>
#include "template_class_doubly_linked_list_with_tail.h"

int main()
{
    // 클래스 템플릿 리스트 선언(Class Template Doubly Linked List with Tail)
    CTList<int> ct_list; // <> 안에 원하는 자료형 삽입
    int select_menu;
    int input_data; // 원하는 자료형으로 수정

    while (1)
    {
        // 리스트 데이터 출력
        ct_list.PrintList();

        // 데이터 삽입 및 삭제 선택
        cout << "1. Push Back Data  2. Push Front Data  3. Delete  4. Init List   (Other Exit) : ";
        cin >> select_menu;

        // 삽입 및 삭제 데이터 값 입력 및 리스트 초기화 선택
        if (select_menu == 1)
            cout << "Push Back Data : ";
        else if (select_menu == 2)
            cout << "Push Front Data : ";
        else if (select_menu == 3)
            cout << "Delete Data : ";
        else if (select_menu == 4)
        {
            ct_list >> ct_list;
            continue;
        }
        else
            break;
        cin >> input_data;

        if (select_menu == 1)
            ct_list < input_data; // 데이터 후단 삽입
        else if (select_menu == 2)
            ct_list << input_data; // 데이터 전단 삽입
        else if (select_menu == 3)
            ct_list > input_data; // 데이터 삭제
    }

    return 0;
}