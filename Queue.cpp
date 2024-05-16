#include "Queue.h"
#include "Man.h"
using namespace std;
Queue::Queue()
{
    set_count(0);
    head = NULL;
    tail = NULL;
}

Queue::Queue(const Queue& init)//конструктор копии
{
    Man* temp = init.head;//в temp присваиваем голову init
    while (temp != NULL)//идём по всей очереди(из которой копируем), пока не доходи до конца (temp!=NULL)
    {
        add_con(temp->get_value());//в очередь, с которой работаем добавляем в конец значение из текущего элемента(temp)
        temp = temp->get_next();//переходим к следующему элементу очереди из которой копируем
    }
}

Queue& Queue::operator=(const Queue& right)
{
    if (this != &right)
    {
        del_all();//удаляем всё из очереди с которой работаем
        Man* temp = right.get_head();//присваиваем в temp голову из очереди right(мы из неё копируем)
        for (int i = 0; i < right.get_count(); i++)//идём по всему количеству элементов 
        {
            add_con(temp->get_value());//в очередь, с которой работаем добавляем в конец значение из текущего элемента(temp)
            temp = temp->get_next();////переходим к следующему элементу очереди из которой копируем
        }
        cout << "Очередь скопирована\n";
    }
    return *this;//возвращаем заполненную очередь
}

void Queue::set_count(int new_count)
{
    count = new_count;
}

int Queue::get_count() const
{
    return count;
}

void Queue::set_head(Man* new_head)
{
    head = new_head;
}

void Queue::set_tail(Man* new_tail)
{
    tail = new_tail;
}

Man* Queue::get_head() const
{
    return head;
}

Man* Queue::get_tail() const
{
    return tail;
}

void Queue::add_con(float value)//добавление в конец значение, которое передали
{
    Man* new_man = new Man(value);//создаем новый элемент очереди с переданным значением(в next присваивается NULL)
    if (new_man != NULL)
    {
        if (get_head() == NULL)//если очередь, с которой работаем пуста
        {
            set_head(new_man);//делаем новый элемент головой
        }
        else
        {
            get_tail()->set_next(new_man);//у последнего элемента меняем NULL на новый элемент
        }
        set_tail(new_man);//теперь новый элемент - хвост
        count++;//количество элементов увеличилось на 1
        cout << "Элемент добавлен\n";
    }
    else
        cout << "Память не выделилась";
}

void Queue::add_nach(float value)//добавление в начало
{
    if (count == 1)//если в очереди был только один элемент
    {
        tail = head;//хвост равен глолове
        cout << "Элемент добавлен\n";
    }
    head = new Man(value, head);//голове присваиваем новый элемент, который создается с параметрами(новое значение и следующий элемент голова очереди, с которой работаем)
    if (head != NULL)
    {
        count++;//количество увеличивается на 1
        if (count == 1)//если в очереди был только один элемент
        {
            tail = head;//хвост равен глолове
        }
        cout << "Элемент добавлен\n";
    }
    else {
        cout << "Память не выделилась\n";
    }
}

void Queue::del_head()//удаление головы
{
    if (!isEmpty())
    {
        Man* temp = head;//указатель temp указывает туда же, куда и голова
        head = head->get_next();//меняем голову на следующий после головы элемент
        delete temp;//удаляем значения (то что хранится по указателю temp(head))
        count--;//уменьшение количества
        cout << "Элемент удалён\n";
    }
}

void Queue::del_all()//удаление всего
{
    while (count != 0)//пока количество элементов в очереди с которой работает не равно 0
    {
        del_head();//удаляем головы
        cout << "Очередь очищена\n";
    }
}

float Queue::del_index(int index)
{
    if (index >= count)
    {
        return 0;
    }

    if (index == 0)
    {
        float znach = head->get_value();
        if (head->get_next() == NULL)
            tail = head;
        del_head();
        return znach;
    }

    else
    {
        Man* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->get_next();
        }
        Man* toDel = previous->get_next();
        previous->set_next(toDel->get_next());


        if (index == count - 1)
        {
            Man* new_tail = this->head;
            for (int i = 0; i < count - 2; i++)
            {
                new_tail = new_tail->get_next();
            }
            tail = new_tail;
        }
        float znach = toDel->get_value();
        delete toDel;

        count--;
        return znach;
    }

}

float Queue::del_znach(float znach)//удаление значения
{
    int temp_count = count;//запоминаем размер(нужно для индексации)
    Man* temp = this->head;//создаем указатель на глову
    int del_count = 0;//количесво удаленных элементов(нужно для индексации)
    for (int i = 0; i < temp_count; i++)//идём по всей очереди(доходя до каждого элемента)
    {
        if (temp->get_value() == znach)//если значение элемента совпало со значением удаления
        {
            temp = temp->get_next();//переход к следующему
            float u = this->del_index(i - del_count);//удаление по индексу(передаем значение в случайную переменнную, тк функция возвращает значение удаления)
            del_count++;//количество удаленных +1
        }
        else//если значение не совпало
        {
            temp = temp->get_next();//переходим к следующему
        }

    }
    return znach;
}



void Queue::change(float old_value, float new_value)//замена(получение чего менять на что менять)
{
    bool flag = false;
    Man* temp = this->head;//указатель на голову
    for (int i = 0; i < count; i++)//по всей очереди
    {
        if (temp->get_value() == old_value)//если значение того, что нужно поменять совпало со значнием элемента очереди
        {
            temp->set_value(new_value);//меняем значение элемента на новое
            flag = true;
        }
        temp = temp->get_next();//переходим к следующему
    }
    if (flag)
        cout << "Элементы заменены\n";
    else
        cout << "Такого элемента нет\n";
}

void Queue::tek_znach()//текущее значение
{
    if (!isEmpty())//если не пустая
    {
        int dlin = lenght();
        cout << "Длина очереди: "<< dlin;
       

        cout << " Значение головы " << head->get_value() << " Значенние хвоста " << tail->get_value() << endl;//вывод 
    }
    else//если пустая
        cout << "Очередь пуста\n";
}

int Queue::lenght()
{
    if (isEmpty())
    return 0;
    else {
        return count;
    }
}

bool Queue::isEmpty() const//проверка, пуста ли очередь
{
    return (head == NULL);//если указатель головы ни на что не ууказывает - очердь пуста
}



Queue::Queue(int count)
{
    set_count(count);
}

Queue::~Queue()//перегруженный деструктор
{
    del_all();//очищение всей очереди
}

/*float& Queue::operator[](const int index)
{
    Man* current = this->head;
    int counter = 0;

    while (current != NULL)
    {
        if (counter == index)
        {
            float* b = new float(current->get_value());
            if (b != NULL)
            {
                float& result = *b;
                delete b;

                return result;
            }
            else {
                cout << "Память не выделилась\n";
            }
        }
        current = current->get_next();
        counter++;
    }
    // В случае, если индекс не найден, можно вернуть ссылку на статическую переменную или бросить исключение
    static float error_value = 0.0f;
    return error_value;
}
*/

void Queue::print()
{
    if (isEmpty())
    {
        cout << "очередь пуста\n";
    }
    else
    {
        Man* temp = head;
        for (int i = 0; i < get_count(); i++)
        {
            cout << temp->get_value() << endl;
            temp = temp->get_next();
        }
    }
}

void Queue::sort()//сортировка
{
    int a = count;//запоминаем значение count
    float* list = new float[a];//создаем массив, выделяя место под наши элементы очереди
    if (list != NULL)
    {
        Man* temp = head;//указатель на голову

        for (int i = 0; i < a; i++)//проходим по всем элементам
        {
            list[i] = temp->get_value();//записываем значение элемента в список
            temp = temp->get_next();//переходим к следующему элементу
        }

        del_all();//чистим очередь с которой работаем

        //сортировка вставками
        for (int i = 1; i < a; i++) {//идем со второго элемента до конца
            float key = list[i];//записываем текущий элемент в key
            int j = i - 1;//индекс для предыдущего элемента
            while (j >= 0 && list[j] > key) {//пока не доши до начала и текущий(key) элемент меньше того, до которого дошли с помощью индекса
                list[j + 1] = list[j];//двигаем предыдущий элемент вперед
                j = j - 1;//уменьшаем индекс чтобы перейти к следующему элементу
            }
            list[j + 1] = key;//ставим key(текущий элемент) на своё место
        }

        for (int i = 0; i < a; i++)
        {
            this->add_con(list[i]);//все элементы списка добавляем в очередь
        }
        delete[] list;//очищение памяти, выделенной под массив
    }
    cout << "Очередь отсортирована\n";
}

ostream& operator<<(ostream& output, Queue& q)
{
    if (q.isEmpty())
    {
        cout << "очередь пуста \n";
        return output;
    }
    else
    {
        Man* temp = q.head;
        for (int i = 0; i < q.count; i++)
        {
            cout << temp->get_value() << "->";
            temp = temp->get_next();
        }
        cout << "NULL" << endl;
        return output;
    }
}
/*istream& operator>>(istream& input, Queue& q)//перегрузка ввода
{
    float value; //переменная для вводимого значения
    cout << "Введите, какое значение вы хотите добавить: ";
    input >> value; //вводим это значение
    Man* newPtr = new Man(value); //выделяем память на новую ячейку списка, вызываем конструктор с параметрами, чтобы положить значение value в value класса Man
        if (newPtr != NULL) //проверяем выделилась ли память
        {
            if (q.isEmpty()) //проверка «пустая ли очередь»
            {
                q.head = newPtr; //присваивание указателю на голову очереди указателя на созданную ячейку
            }
            else // если очередь не пустая 
            {
                q.tail->set_next(newPtr);//последний элемент очереди указывает на созданный 
            }
            q.tail = newPtr; //созданный элемент теперь новый последний
        }
        else //если память не выделилась 
        {
            cout << value << "не добавлен. Память не выделилась." << endl;
        }
    return input; //возвращаем input чтобы можно было вводить подряд cin >> q >> t >> … >> … ;
}
*/
void Queue::del_copy()
{
    if (isEmpty()) //проверка пустая ли очередь
    {
        cout << "Очередь пуста" << endl;
    }
    else//если не пустая
    {
        Man *curr, *temp, *prev; //создаем вспомогательные указатели на ячейки списка
        for (curr = head; curr != NULL; curr = curr->get_next()) //двигаемся по всей очереди
        {
            prev = curr; //запоминаем сравниваемый элемент
            for (temp = curr->get_next(); temp != NULL;) //цикл по элементам начиная со следующего от curr
            {
                if (temp->get_value() == curr->get_value()) //сравниваем curr со всеми остальными элементами очереди
                {
                    prev->set_next(temp->get_next()); //предыдущий указывает теперь на через одного
                    delete temp; //удаляем дубликат 
                    count--;
                    temp = prev->get_next(); //для того чтобы сравнивать дальше
                    continue; //пропуск оставшейся части кода тела цикла и переход к следующей итерации 
                }
                prev = temp; //предыдущий к сравниваемому
                temp = temp->get_next(); //двигаемся дальше по очереди
            }
        }
        temp = head;
        for (int i = 0; i < count; i++)
        {
            tail = temp;
            temp = temp->get_next();
        }
        cout << "Дубликаты удалены." << endl;
    }

}


void Queue::inversion()//инвертирование
{
    Man* tmp_tail = this->get_head();//создаем указатель на голову
    Man* prev_ptr = NULL;//указатель на предыдущий элемент
    Man* current_ptr = this->get_head();//создаем указатель на текущий элемент, который равен голове
    Man* next_ptr = NULL;//указатель на следующий элемент(он равен NULL)

    while (current_ptr != NULL)//пока текущий не равен NULL, идйм по всей очереди
    {
        next_ptr = current_ptr->get_next();
        current_ptr->set_next(prev_ptr);
        prev_ptr = current_ptr;
        current_ptr = next_ptr;
    }

    this->set_head(prev_ptr);
    this->set_tail(tmp_tail);
    cout << "Очередь инвертирована\n";
}

//перегрузка сложения 
Queue Queue :: operator+(const Queue& second)
{
    //вовращает новую очередь, длина которой равна максимальной длине исходных очередей 
    //а все элементы равны сумме соответствующих элементов исходных очередей 
    // если очереди разных размеров, недостающие элементы считаются равными 0 
    Queue result;
    Man* current1;
    Man* current2;
    float x, x1, x2;
    current1 = head;
    current2 = second.head;//указатели на текущие элементы в каждой из складываемых очередей 
    while ((current1 != NULL) || (current2 != NULL))//пока в хоть одной есть элементы 
    {
        if (current1 != NULL) //значение текущего элемента из 1 очереди, если элемент есть 
        {
            x1 = current1->get_value();
            current1 = current1->get_next(); //сдвиг текущего 
        }
        else x1 = 0; //если в очереди закончились элементы 
        if (current2 != NULL)
        {
            x2 = current2->get_value();
            current2 = current2->get_next(); //сдвиг текущего 
        }
        else x2 = 0; //если в очереди закончились элементы 
        x = x1 + x2;
        result.add_con(x); //вставляем элемент с суммарным значением 
    }
    return result; //возвращаем новую очередь 
}

Queue& Queue::operator+=(const Queue& second)
{
    Man* current;//указатель для движения по очереди
    Queue result;
    //к первой очереди добавляем в конец все элементы из второй 
    
    current = second.head;//этот новый указатель указывает на голову второй очереди
    while (current != NULL)//пока не дошли до конца второй очереди
    {
        this->add_con(current->get_value());//создаем элемент в первой очереди со значением из второй 
        current = current->get_next();//переходим к следующему элменту
    }
    return *this;
}


/*//11 - to sum 2 queues (overload +) 
void Queue::sum(const Queue& second)
{
    //к первой прибавляется вторая 
    //отличается от оператора + тем, что изменяется первая очередь, а не создается новая 
    Man* current1;
    Man* current2;
    current1 = head;
    current2 = second.head;
    while ((current1 != NULL) && (current2 != NULL)) //пока обе очереди не пусты 
    {
        float value1 = current1->get_value();
        current1->set_value(current2->get_value()+value1); //к значению первой очереди прибавляем значение из второй 
        current1 = current1->get_next(); //сдвигаем указатели на «текущие элементы» 
        current2 = current2->get_next();
    }
    while (current2 != NULL)//если первая очередь закончилась и завершился первый цикл, но во 
        //второй еще остались элементы 
    {
        this->add_con(current2->get_value()); //добавляем элемент с значением из второй очереди 
        current2 = current2->get_next();
    }
}
*/

/*
//12 - to merge 2 queues 
void Queue::merge(const Queue& second)
{
    //к первой очереди добавляем в конец все элементы из второй 
    Man* current;//указатель для движения по очереди
    current = second.head;//этот новый указатель указывает на голову второй очереди
    while (current != NULL)//пока не дошли до конца второй очереди
    {
        this->add_con(current->get_value());//создаем элемент в первой очереди со значением из второй 
        current = current->get_next();//переходим к следующему элменту
    }
}
*/
