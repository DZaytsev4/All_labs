#include <iostream>
#include "MyStack.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int num = 0, el, size;
    cout << "*Создание стека*\nВведите размер: ";
    cin >> size;
    TStack<int> stack(size);
    while (num != 6)
    {
        cout << "\n1. Добавить элемент\n";
        cout << "2. Извлечь элемент\n";
        cout << "3. Посмотреть верхний элемент\n";
        cout << "4. Размер\n";
        cout << "5. Вывести стек\n";
        cout << "6. Выход\n";
        cout << "Ввод: ";
        cin >> num;
        cout << endl;
        switch (num)
        {
        case 1:
            cout << "Введите элемент: ";
            cin >> el;
            stack.Push(el);
            break;
        case 2:
            stack.Pop();
            break;
        case 3:
            stack.TopView();
            break;
        case 4:
            stack.GetSize();
            break;
        case 5:
            cout << "Содержимое стека: " << stack << endl;
        default:
            cout << "Такого пункта нет" << endl;
            break;
        }
    }

}
