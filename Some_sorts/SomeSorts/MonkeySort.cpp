// MonkeySort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>




template<typename Iterator>
bool Is_NOT_Sorted(Iterator b, Iterator e)
{
    Iterator rn = b + 1;
    while (rn != e)
    {
        if (*(rn - 1) < *(rn))
        {
            return true;
        }
        rn++;
    }
    return false;
}

template<typename Iterator>
//typename std::iterator_traits<Iterator> value_type;
void Monkey_Sort(Iterator b, Iterator e)
{
    if (b == e)
    {
        throw 1;
    }

    int size = e - b;

    uint64_t i = 0;
    int del1;
    int del2;

    while (Is_NOT_Sorted(b, e))
    {
        do
        {
           del1 = rand() % size;
           del2 = rand() % size;
        } while (del1 == del2);
   
        std::iter_swap(b + del1, b + del2);

        i++;
    }
    
    std::cout << "На упорядычивание " << size << " элеметного вектора ушло: " << i << " итерация" << '\n';
}

template <typename Iter>
void bubble_sort(Iter b, Iter e)
{
    if (b == e)
    {
        throw std::exception("Error");
    }

    Iter e1 = e;
    for (auto p1 = b; p1 < (e) ; p1++)
    {
        for (auto p = b; p != (e1-1); p++)
        {
            if (*p > *(p + 1)) {
                std::iter_swap(p, (p + 1));
            }
        }
        e1--;
    }
}

template<typename Iter>
void bubble_sort2(Iter b, Iter e)
{
    for (auto p1 = b; p1 != (e-1); p1++)
    {
        for (auto p = (e-1); p != (p1); p--)
        {
            if (*p > *(p - 1)) {
                std::iter_swap(p, (p - 1));
            }
        }
    }
}

template <class Iter>
Iter binary_search(Iter b, Iter e, int value)
{
    if (b == e)
    {
        throw std::exception("Empty array");
    }

    Iter left_b = b;
    Iter right_b = e-1;
    Iter midle = b + (right_b - left_b) / 2;

    while (right_b - left_b > 1)
    {
        if (*midle < value) {
            left_b = midle;
        }
        else {
            right_b = midle;
        }
      midle = left_b + (right_b - left_b) / 2;
    }
    return left_b;
}

template <class Iter>
void sort_merge(Iter b, Iter e)
{
    int size = e - b;

    if (size == 1)
    {
        return;
    }

    Iter left_b = b;
    Iter right_b = e;
    Iter middle = b  + (right_b - left_b)/2;
    Iter mid_b = middle;
   
    sort_merge(left_b, mid_b);
    sort_merge(mid_b, right_b);

    std::vector<int> sorted;
    while (left_b != middle && mid_b != right_b)
    {
        if (*left_b < *mid_b)
        {
            sorted.push_back(*left_b);
            left_b++;
        }
        else
        {
            sorted.push_back(*mid_b);
            mid_b++;
        }
    }

    while (left_b != middle)
    {
        sorted.push_back(*left_b);
        left_b++;
    }

    while (mid_b != right_b)
    {
        sorted.push_back(*mid_b);
        mid_b++;
    }

    std::copy(sorted.begin(), sorted.end(), b);

}

int main()
{
    //std::vector<int> my{ 1,2,3,4,5,6,7,8,9 };

    setlocale(LC_ALL, "ru");

   // auto p = binary_search(my.begin(), my.end(), 3);

    //std::cout << *p << '\n';
    std::vector<int> my{ 1, 75, 123, 23, 1, 5, 7, 8, 12, 8};
    sort_merge(my.begin(), my.end());

    for (auto x : my)
    {
        std::cout << x << " ";
    }
    std::cout << '\n';
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
