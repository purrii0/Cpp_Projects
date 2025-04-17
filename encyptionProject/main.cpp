#include <iostream>

std::string encryptor(std::string, int);
std::string decryptor(std::string, int);

int main()
{
    int shift;
    std::string msg = "hello";
    std::cout << "How Much shift do you want: ";
    std::cin >> shift;

    if (shift > 26)
    {
        if(shift%26 == 0) shift = 26;
        else shift = shift%26;
    }
    

    if(shift < 0)
    {
        shift = -(shift);
        std::string encrypted = decryptor(msg, shift);
        std::cout << "Encrypted: " << encrypted  << std::endl;
        std::cout << "Decrypted: " << encryptor(encrypted, shift) << std::endl;
        return 0;
    }
    std::string encrypted = encryptor(msg, shift);
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decryptor(encrypted, shift) << std::endl;

    return 0;
}