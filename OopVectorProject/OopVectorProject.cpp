#include <iostream>

class Vector
{
    int size;
    int* items;
public:
    Vector() : Vector(0) {}
    Vector(int size) : size{ size }
    {
        items = new int[size];
    }

    int Size();

    void Push(int value);
    void Insert(int index, int value);
    int Pop();
    int RemoveAt(int index);

    int& At(int index);


    ~Vector()
    {
        delete[] items;
    }
};

int Vector::Size() { return size; }


void Vector::Push(int value)
{
    int* newItems = new int[size + 1];
    for (int i = 0; i < size; i++)
        newItems[i] = items[i];
    newItems[size] = value;
    delete[] items;
    items = newItems;
    size++;
}

void Vector::Insert(int index, int value)
{
    int* newItems = new int[size + 1];
    for(int i = 0; i < index; i++)
        newItems[i] = items[i];
    newItems[index] = value;
    for(int i = index; i < size; i++)
        newItems[i + 1] = items[i];
    delete[] items;
    items = newItems;
    size++;
}

int Vector::Pop()
{
    int value = items[size - 1];
    int* newItems = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
        newItems[i] = items[i];
    delete[] items;
    items = newItems;
    size--;
    return value;
}

int Vector::RemoveAt(int index)
{
    int value = items[index];
    int* newItems = new int[size - 1];
    for (int i = 0; i < index; i++)
        newItems[i] = items[i];
    for (int i = index; i < size - 1; i++)
        newItems[i] = items[i + 1];
    delete[] items;
    items = newItems;
    size--;
    return value;
}

int& Vector::At(int index)
{
    return items[index];
}

int main()
{
    Vector v(3);
}
