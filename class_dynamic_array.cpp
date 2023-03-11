#include <iostream>
#include "class_dynamic_array.h"

using namespace std;

int main()
{
    // 가변 배열 선언
    ClassDynamicArray c_dynamic_arr;
    int select_menu, input_data;

    while (1)
    {
        // 가변 배열 데이터 출력
        c_dynamic_arr.PrintArray();

        // 데이터 삽입 및 삭제 선택(리사이즈 임시 추가)
        cout << "1. Input 2. Delete 3. Resize  (Other Exit) : ";
        cin >> select_menu;

        // 삽입 및 삭제 데이터 값 입력
        if (select_menu == 1)
            cout << "Input Data : ";
        else if (select_menu == 2)
            cout << "Delete Data : ";
        else if (select_menu == 3)
            cout << "Resize len : ";
        else
            break;
        cin >> input_data;

        if (select_menu == 1)
            c_dynamic_arr.PushBackData(input_data); // 데이터 삽입
        else if (select_menu == 2)
            c_dynamic_arr.DeleteData(input_data);   // 데이터 삭제
        else if (select_menu == 3)
            c_dynamic_arr.ResizeArray(input_data);  // 리사이즈
    }

    return 0;
}