#ifndef ARRAYINT_H
#define ARRAYINT_H	

#include <cassert>
#include <iostream>

//===============EX.1===============
//Добавить в контейнерный класс, который был написан в этом уроке, методы:
//для удаления последнего элемента массива(аналог функции pop_back() в векторах)
//для удаления первого элемента массива(аналог pop_front() в векторах)
//для сортировки массива
//для вывода на экран элементов.

class ArrayInt
{
    int m_length;
    int m_capacity;
    int* m_data;

public:

    ArrayInt() : m_length(0), m_capacity(0), m_data(nullptr)
    { }

    ArrayInt(int length) :
        m_length(length), m_capacity(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
        m_capacity = 0;
    }

    int getLength() const
    { 
        return m_length; 
    }

    int getCapacity() const
    {
        return m_capacity;
    }

    int* getArr() const
    {
        return m_data;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newCapacity)
    {
        if (newCapacity == m_length)
            return;

        if (newCapacity <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newCapacity];

        if (m_length > 0)
        {
            int elementsToCopy = (newCapacity > m_capacity) ? m_capacity : newCapacity;

            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;

        m_data = data;
        m_capacity = newCapacity;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length + 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        if (m_capacity == m_length)
            ++m_capacity;
        ++m_length;
    }

    void push_back(int value) 
    { 
        insertBefore(value, m_length); 
    }

    int pop_back()
    {
        assert(m_length > 0);

        int* data = new int[m_capacity];
        int delElement = this->m_data[m_length - 1];
        
        for (int i = 1, j = 0; i < m_length; i++, j++)
        {
            data[j] = this->m_data[i - 1];
        };

        delete[] m_data;
        m_data = data;
        --m_length;
        return delElement;
    }

    int pop_front()
    {
        assert(m_length > 0);

        int* data = new int[m_capacity];

        int delElement = this->m_data[0];

        for (int i = 1, j = 0; i < m_length; i++, j++)
        {
            data[j] = this->m_data[i];
        };

        delete[] m_data;
        m_data = data;
        --m_length;
        return delElement;
    }

    void sort(int* arr, int first, int last)
    {
        int i, j, x;
        i = first;
        j = last;
        x = arr[(first + last) / 2];

        do
        {
            while (arr[i] < x) i++;
            while (arr[j] > x) j--;

            if (i <= j)
            {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        } while (i <= j);

        if (first < j)
            sort(arr, first, j);
        if (i < last)
            sort(arr, i, last);
    }

    void print()
    {
        assert(m_length > 0);

        for (int i = 0; i < m_length; i++)
            std::cout << m_data[i] << " ";
        std::cout << "\n\n";
    }
};

#endif

//==================================