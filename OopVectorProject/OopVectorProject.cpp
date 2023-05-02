#include <iostream>
#include <cassert>

class User
{

};


template <class T>
class Vector
{
    int size;
    T* items;
public:
    Vector() : Vector(0) {}
    Vector(int size) : size{ size }
    {
        std::cout << this << " Vector construct\n";
        items = new T[size];
    }
    Vector(const Vector<T>& v)
    {
        std::cout << this << " Vector copy construct\n";
        size = v.size;
        items = new T[size];
        for (int i = 0; i < size; i++)
            items[i] = v.items[i];
    }

    Vector operator=(const Vector<T>& v)
    {
        size = v.size;
        
        delete[] items;
        items = new T[size];
        for (int i = 0; i < size; i++)
            items[i] = v.items[i];
        return *this;
    }


    int Size();

    void Push(T value);
    void Insert(int index, T value);
    T Pop();
    T RemoveAt(int index);

    T& At(int index);

    T& operator[](int index);


    ~Vector()
    {
        std::cout << this << " Vector destruct\n";
        delete[] items;
    }
};
template <class T>
int Vector<T>::Size() { return size; }

template <class T>
void Vector<T>::Push(T value)
{
    T* newItems = new T[size + 1];
    for (int i = 0; i < size; i++)
        newItems[i] = items[i];
    newItems[size] = value;
    delete[] items;
    items = newItems;
    size++;
}

template <class T>
void Vector<T>::Insert(int index, T value)
{
    T* newItems = new T[size + 1];
    for(int i = 0; i < index; i++)
        newItems[i] = items[i];
    newItems[index] = value;
    for(int i = index; i < size; i++)
        newItems[i + 1] = items[i];
    delete[] items;
    items = newItems;
    size++;
}

template <class T>
T Vector<T>::Pop()
{
    T value = items[size - 1];
    T* newItems = new T[size - 1];
    for (int i = 0; i < size - 1; i++)
        newItems[i] = items[i];
    delete[] items;
    items = newItems;
    size--;
    return value;
}

template <class T>
T Vector<T>::RemoveAt(int index)
{
    T value = items[index];
    T* newItems = new T[size - 1];
    for (int i = 0; i < index; i++)
        newItems[i] = items[i];
    for (int i = index; i < size - 1; i++)
        newItems[i] = items[i + 1];
    delete[] items;
    items = newItems;
    size--;
    return value;
}

template <class T>
T& Vector<T>::At(int index)
{
    assert(index >= 0 && index < size);

    return items[index];
}

template <class T>
T& Vector<T>::operator[](int index)
{
    return this->At(index);
}


void VectorPrint(Vector<int> v)
{
    for (int i = 0; i < v.Size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}

Vector<int> VectorInit(int size)
{
    Vector<int> v(size);
    for (int i = 0; i < v.Size(); i++)
        v[i] = rand() % 100;
    return v;
}


int main()
{
    srand(time(nullptr));

    Vector<int> v = VectorInit(3);
    Vector<float> vfl;
    Vector<User> users;
    /*for (int i = 0; i < v.Size(); i++)
        v[i] = rand() % 100;*/
    //v = VectorInit(3);
    

    //VectorPrint(v);

    Vector<int> v2, v3;
    v3 = v2 = v;

    //VectorPrint(v);

    
    //v.At(0) = 10;
    //std::cout << v.At(0) << "\n";

    //v[1] = 20;
    //std::cout << v[1] << "\n";

    ////v[100] = 10;

    //Vector* vptr = new Vector(2);

    //(*vptr)[0] = 10;

    //vptr->At(0) = 10;

    //delete vptr;
    
}
