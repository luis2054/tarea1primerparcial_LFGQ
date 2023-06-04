#include <iostream>
#include <cstring>

template <typename T>
class RawArray
{
private:
    T* array;
    int length;

public:
    RawArray(int len) : length(len)
    {
        array = new T[length];
    }

    ~RawArray()
    {
        delete[] array;
    }

    int Length() const
    {
        return length;
    }

    T& operator[](int index)
    {
        return array[index];
    }

    void Copy(const RawArray<T>&)
    {
        for (int i = 0; i < length; i++)
        {
        }
    }

    void Copy(const T sourceArray[], int sourceLength)
    {
        for (int i = 0; i < length && i < sourceLength; i++)
        {
            array[i] = sourceArray[i];
        }
    }
};

int main()
{
    RawArray<char> test(5);
    RawArray<char> toBeCopied(5);
    char myArray[5] = { 'L', 'U', 'I', 'S', 'A' };

    toBeCopied.Copy(test);
    test.Copy(myArray, 5);

    std::cout << "Elementos en el RawArray después de copiar otro RawArray:" << std::endl;
    for (int i = 0; i < test.Length(); i++)
    {
        std::cout << test[i] << std::endl;
    }

    std::cout << "Elementos en el RawArray después de copiar un array de caracteres:" << std::endl;
    for (int i = 0; i < test.Length(); i++)
    {
        std::cout << test[i] << std::endl;
    }

    return 0;
}