#include <iostream>
#include <cassert>

class Vector
{
    int size;
    int* items;
public:
    Vector() : Vector(0) {}
    Vector(int size) : size{ size }
    {
        std::cout << this << " Vector construct\n";
        items = new int[size];
    }
    Vector(const Vector& v)
    {
        std::cout << this << " Vector copy construct\n";
        size = v.size;
        items = new int[size];
        for (int i = 0; i < size; i++)
            items[i] = v.items[i];
    }

    Vector operator=(const Vector& v)
    {
        size = v.size;
        
        delete[] items;
        items = new int[size];
        for (int i = 0; i < size; i++)
            items[i] = v.items[i];
        return *this;
    }


    int Size();

    void Push(int value);
    void Insert(int index, int value);
    int Pop();
    int RemoveAt(int index);

    int& At(int index);

    int& operator[](int index);


    ~Vector()
    {
        std::cout << this << " Vector destruct\n";
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
    assert(index >= 0 && index < size);

    return items[index];
}

int& Vector::operator[](int index)
{
    return this->At(index);
}

void VectorPrint(Vector v)
{
    for (int i = 0; i < v.Size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}

Vector VectorInit(int size)
{
    Vector v(size);
    for (int i = 0; i < v.Size(); i++)
        v[i] = rand() % 100;
    return v;
}


int main()
{
    srand(time(nullptr));

    Vector v = VectorInit(3);
    /*for (int i = 0; i < v.Size(); i++)
        v[i] = rand() % 100;*/
    //v = VectorInit(3);
    

    //VectorPrint(v);

    Vector v2, v3;
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
