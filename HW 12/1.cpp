#include <iostream>
#include <cstring>
using namespace std;
char* strdup(const char* str) {
    if (str == nullptr) return nullptr;
    int length = 0;
    while (str[length] != '\0')
        length++;
    char* copy = new char[length + 1];
    for (int i = 0; i < length; ++i)
        copy[i] = str[i];
    copy[length] = '\0';
    return copy;
}
int main()
{
    int size = 10;
    char* buffer = new char[size];
    int index = 0;
    char ch;
    while (cin.get(ch) && ch != '!') {
        if (index >= size - 1) {
            size *= 2;
            char* newBuffer = new char[size];
            for (int i = 0; i < index; ++i)
                newBuffer[i] = buffer[i];
            delete[] buffer;
            buffer = newBuffer;
        }
        buffer[index++] = ch;
    }
    buffer[index] = '\0';
    cout<<buffer<<endl;
    delete[] buffer;
}