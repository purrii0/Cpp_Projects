#include <string>
std::string encryptor(std::string, int);
std::string decryptor(std::string n, int shift)
{
    int tempShift = shift;
    for (size_t i = 0; n[i] != '\0' ; i++)
    {
        char c = n[i];
        if(c >= 'a'  && c <= 'z')
        {
            if(int(c) - shift <= 97)
            {
                shift = shift - (int(c) - 'a') - 1;
                c = 'z';
            }
            c -= shift;
        }
        else if(c >= 'A'  && c <= 'Z')
        {
            if(int(c) - shift <= 65)
            {
                shift = shift - (int(c) - 'A') - 1;
                c = 'Z';
            }
            c -= shift;            
        }
        n[i] = c;
        shift = tempShift;
    }
    return n;
};