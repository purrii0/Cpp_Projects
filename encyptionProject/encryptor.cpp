#include <string>
std::string decryptor(std::string, int);
std::string encryptor(std::string msg, int shift) 
{
    int tempShift = shift;
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
    return msg;
}