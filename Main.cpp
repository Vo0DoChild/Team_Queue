#include <iostream>
#include "Queue.h"
#include "Man.h"
bool proverka_index(int, int);
void instructions(void);

using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");

    int n, choice;
    cout << "Сколько очередей вы собираетесь использовать?" << endl;
    cin >> n;
    if (n > 0)
    {
        Queue* List = new Queue[n];
        if (List != NULL)
        {
            instructions();
            cout << "Введите выбор: ";
            cin >> choice;
            while (choice != 0)
            {
                switch (choice)
                {
                case 0://завершить
                    cout << "Завершение программы" << endl;
                    break;
                case 1://пустота
                    if (n > 1)
                    {
                        int number;
                        do {
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        if (List[number - 1].isEmpty())
                            cout << "Очередь пуста\n";
                        else
                            cout << "Очередь не пуста\n";
                    }
                    else
                    {
                        if (List[0].isEmpty())
                            cout << "Очередь пуста\n";
                        else
                            cout << "Очередь не пуста\n";
                    }
                    break;
                case 2://текущее значение
                    if (n > 1)
                    {
                        int number;
                        do {
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        List[number - 1].tek_znach();
                    }
                    else
                    {
                        List[0].tek_znach();
                    }
                    break;
                case 3://копирование
                    if (n > 1)
                    {
                        int number1, number2;
                        cout << "\nДля каких очередей вы хотите применить команду(введите прядковый номер): ";
                        do {
                            cout << "\nВведите номер первой очереди,в которую копируем : ";
                            cin >> number1;
                        } while (proverka_index(n, number1));
                        do {
                            cout << "\nВведите номер первой очереди, которую копируем : ";
                            cin >> number2;
                        } while (proverka_index(n, number2));
                        List[number1 - 1] = List[number2 - 1];
                    }
                    else
                    {
                        cout << "Вы не можете применить эту функцию. 1 очередь\n";
                    }
                    break;
                case 4://добавить до
                    float znach;
                    cout << "Какое значение вы хотите добавить? ";
                    cin >> znach;
                    if (n > 1)
                    {
                        int number;
                        do{
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        List[number - 1].add_nach(znach);
                    }
                    else
                    {
                        List[0].add_nach(znach);
                    }
                    break;
                case 5://добавить после
                    float znach1;
                    cout << "Какое значение вы хотите добавить? ";
                    cin >> znach1;
                    if (n > 1)
                    {
                        int number;
                        do {
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        List[number - 1].add_con(znach1);
                    }
                    else
                    {
                        List[0].add_con(znach1);
                    }
                    break;
                case 6://замена
                    float old_value, new_value;
                    cout << "Введите новое значение и то, которое вы хотите заменить: ";
                    cin >> new_value >> old_value;
                    if (n > 1)
                    {
                        int number;
                        do {
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        List[number - 1].change(old_value, new_value);
                    }
                    else
                    {
                        List[0].change(old_value, new_value);
                    }
                    break;
                case 7://удаление
                    if (n > 1)
                    {
                        int number;
                        do {
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        List[number - 1].del_head();
                    }
                    else
                    {
                        List[0].del_head();
                    }
                    break;
                case 8://удаление с выводом
                    int a;
                    cout << "Вы хотите удалить элемент по индексу(1) или по значению(2): ";
                    do {
                        cin >> a;
                    } while (a != 1 && a != 2);
                    if (a == 1)
                    {
                        int index;
                        do {
                            cout << "Введите индекс элемента, которого вы хотите удалить\n";
                            cin >> index;
                        } while (index < 1);
                        if (n > 1)
                        {
                            int number;
                            do {
                                cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                                cin >> number;
                            } while (proverka_index(n, number));


                            if (List[number - 1].lenght() >= index)
                                cout << "Удалено: " << List[number - 1].del_index(index - 1) << endl;

                            else {
                                cout << "Такого индекса нет\n";
                            }

                        }
                        else
                        {
                            if (List[0].lenght() >= index)
                                cout << "Удалено: " << List[0].del_index(index - 1) << endl;

                            else {
                                cout << "Такого индекса нет\n";
                            }
                        }
                    }
                    if (a == 2)
                    {
                        float element;
                        cout << "Введите значение элемента, которого вы хотите удалить: ";
                        cin >> element;
                        if (n > 1)
                        {

                            bool flag1 = false;
                            {
                                int number;
                                do {
                                    cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                                    cin >> number;
                                } while (proverka_index(n, number));
                                Man* temp = List[number - 1].get_head();
                                for (int i = 0; i < List[number - 1].lenght(); i++)
                                {
                                    if (temp->get_value() == element)
                                    {
                                        flag1 = true;
                                        break;
                                    }
                                }

                                if (flag1)
                                    cout << "Удалено: " << List[number - 1].del_znach(element) << endl;

                                else {
                                    cout << "Такого элемента нет\n";
                                }

                            }
                        }

                        else
                        {
                            bool flag = false;

                            Man* temp = List[0].get_head();
                            for (int i = 0; i < List[0].lenght(); i++)
                            {
                                if (temp->get_value() == element)
                                {
                                    flag = true;
                                    break;
                                }
                                temp = temp->get_next();
                            }

                            if (flag)
                                cout << "Удалено: " << List[0].del_znach(element) << endl;

                            else {
                                cout << "Такого элемента нет\n";
                            }
                        }
                    }
                    break;
                case 9://удаление всей очереди
                    if (n > 1)
                    {
                        int number;
                        do {
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        List[number - 1].del_all();
                    }
                    else
                    {
                        List[0].del_all();
                    }
                    break;
                case 10://узнать длину
                    if (n > 1)
                    {
                        int number;
                        do {
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        int dlin = List[number - 1].lenght();
                        cout << "Длина " << dlin << endl;
                    }
                    else
                    {
                        int dlin = List[0].lenght();
                        cout << "Длина " << dlin << endl;
                    }
                    break;
                case 11://сортировка
                    if (n > 1)
                    {
                        int number;
                        do {
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        List[number - 1].sort();
                    }
                    else
                    {
                        List[0].sort();
                    }
                    break;
                case 12://вывод(печать)
                    if (n > 1)
                    {
                        int number;
                        do {
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        cout << List[number - 1];
                    }
                    else
                    {
                        cout << List[0];
                    }
                    break;
                case 13://инвертирование
                    if (n > 1)
                    {
                        int number;
                        do {
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        List[number - 1].inversion();
                    }
                    else
                    {
                        List[0].inversion();
                    }
                    break;
                case 14://сложение
                    if (n > 1)
                    {
                        int number1, number2;
                        do {
                            cout << "\nВведите номер первой очереди, куда прибавить: ";
                            cin >> number1;
                        } while (proverka_index(n, number1));


                        do {
                            cout << "\nВведите номер второй очереди, что прибавить: ";
                            cin >> number2;
                        } while (proverka_index(n, number2));
                        List[number1 - 1] = List[number1 - 1]+(List[number2 - 1]);
                    }
                    else
                    {
                        cout << "Вы не можете применить эту функцию. 1 очередь\n";
                    }
                    break;
                case 15://слияние
                    if (n > 1)
                    {
                        cout << "\nДля каких очередей вы хотите применить команду(введите прядковый номер): ";
                        int number1, number2;
                        do {
                            cout << "\nВведите номер первой очереди: ";
                            cin >> number1;
                        } while (proverka_index(n, number1));
                        
                        do {
                            cout << "\nВведите номер второй очереди: ";
                            cin >> number2;
                        } while (proverka_index(n, number2));
                        List[number1 - 1]+=(List[number2 - 1]);
                    }
                    else
                    {
                        cout << "Вы не можете применить эту функцию. 1 очередь\n";
                    }
                    break;
                case 16://удаление двойников
                    if (n > 1)
                    {
                        int number;
                        do {
                            cout << "\nДля какой очереди вы хотите применить команду(введите прядковый номер): ";
                            cin >> number;
                        } while (proverka_index(n, number));
                        List[number - 1].del_copy();
                    }
                    else
                    {
                        List[0].del_copy();
                    }
                    break;
                default:

                    cout << "\nВыберете существующее значение" << endl << endl;
                    instructions();
                    break;
                }
                cout << "\n Введите следующую команду: ";
                cin >> choice;



            }
        }
    }
    return 0;
}
bool proverka_index(int n, int number)
{
    if (number < 0 || n < number)//если индекс меньше 0 или больше, чем количество очередей
        return true;

    else
        return false;
}
void instructions(void)
{
    cout << "Выберете действвие: \n 1)Проверить на пустоту"
        "\n 2)Узнать текущее значение"
        "\n 3)Копировать одну очередь в другую"
        "\n 4)Добавить до(в начало)"
        "\n 5)Добавить после(в конец)"
        "\n 6)Заменить один элемент другим"
        "\n 7)Удалить(голову)"
        "\n 8)Удалить и вывести на экран"
        "\n 9)Удалить всю очередь"
        "\n 10)Узнать длину очереди"
        "\n 11)Сортировать элементы"
        "\n 12)Распечатать очередь"
        "\n 13)Инвертировать очередь"
        "\n 14)Сложить две очереди"
        "\n 15)Слить две очереди"
        "\n 16)Удалить двойников"
        "\n 0)Завершить\n";
}
