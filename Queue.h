#include <iostream>
#include "Man.h"
using namespace std;
#pragma once
class Queue {
	friend ostream& operator<<(ostream& output, Queue& q);//перегрузка вывода
	//friend istream& operator>> (istream& input, Queue& q);//перегрузка ввода

private:
	Man* head;//голова
	Man* tail;//хвост
	int count;//количество в очереди
public:
	void set_count(int new_count);//изменение количества
	void set_head(Man* new_head);//изменение головы
	void set_tail(Man* new_tail);//изменение хвоста

	int get_count() const;//получение значения количества
	Man* get_head() const;//получение значения головы
	Man* get_tail() const;//получение значения хвоста

	void add_con(float value);//добавление в конец
	void add_nach(float value);//добавление в начало
	void del_head();//удаление первого элемента(головы)
	void del_all();//удаление всей очереди
	float del_index(int index);//удаление элемета по индексу
	float del_znach(float znach);//удаление значения по значению
	void change(float old, float new_value);//замена элемента
	void tek_znach();//узнать текущее значение 
	int lenght();//узнать длину
	void inversion();//инвертирование
	void del_copy();//удаление дубликатов
	Queue& operator=(const Queue& right);//перегрузка приравнивания
	bool isEmpty() const;//проверка на пустоту
	Queue();//конструктор без параметров
	Queue(int count);//конструктор с параметром количества
	Queue(const Queue& init);//конструктор копии
	~Queue();//деструктор
	void print();//функция вывода
	void sort();//сортировка
	//void merge(const Queue& second);//слияние
	//void sum(const Queue& second);
	Queue operator +(const Queue& second);
	Queue& operator +=(const Queue& second);

	//float& operator[](const int index);//перегрузка индексации
};
