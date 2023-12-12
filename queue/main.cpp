#include <iostream>
#include "MyQueue.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    int num = 0, el, size;

    cout << "*Создание очереди*\nВведите размер: ";
    cin >> size;
    TQueue<int> Queue(size);

    while (num != 5)
    {
        cout << "\n1. Добавить элемент в очередь\n";
        cout << "2. Извлечь элемент из очереди\n";
        cout << "3. Размер очереди\n";
        cout << "4. Вывести содержимое очереди\n";
        cout << "5. Выход\n";
        cout << "Ввод: ";
        cin >> num;
        cout << endl;
        switch (num)
        {
        case 1:
            cout << "Введите элемент: ";
            cin >> el;
            Queue.Push(el);
            break;
        case 2:
            Queue.Get();
            break;
        case 3:
            Queue.GetCount();
            break;
        case 4:
            cout << "Содержимое очереди: " << Queue << endl;
            break;
        default:
            cout << "Такого пункта нет" << endl;
            break;
        }
    }
}
