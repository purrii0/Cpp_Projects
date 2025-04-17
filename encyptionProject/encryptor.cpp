#include <iostream>
#include <fstream>

std::string decryptor(std::string, int);

int main() 
{
    int shift, tempShift;
    std::string msg = "hello! test z";
    std::cout << "How Much shift do you want: ";
    std::cin >> shift;
    if(shift > 26) 
    {
        int rem = shift % 26;
        (rem == 0) ? shift = 26 : shift = rem;
    }
    tempShift = shift;
    for (size_t i = 0; '\0' != msg[i]; i++)
    {
        char c = msg[i];
        if(c >= 'a' && c <= 'z' )
        {
            if(( (int)c  + shift ) >= 122)
            {
                shift = shift - ('z' - c) - 1;
                c = 'a';
            }
            c += shift;
        }
        if(c >= 'A' && c <= 'Z')
        {
            if( ( (int)c + shift) >= 90) 
            {
                shift = shift - ('Z' - c) - 1;
                c = 'A';
            }
            c += shift;
        }
        msg[i] = c;
        shift = tempShift;
    }
    std::cout << msg << std::endl;

    std::cout << decryptor(msg, shift) << std::endl;
    
    return 0;
}