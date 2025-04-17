#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>
#include <string>
#include <iomanip> 

struct userInfo
{
    std::string name;
    std::string phoneNumber;
    std::string address;
};

std::vector<std::string> split(const std::string& str, char seperator)
{
    std::vector<std::string> result;
    std::stringstream sr(str);
    std::string token;
    while (std::getline(sr, token, seperator))
    {
        result.push_back(token);
    }
    
    return result;
}

int main()
{
    std::fstream file1;
    int choice;
    std::cout << "\n========= Telephone Directory =========\n"
    << " 1) Add Record\n"
    << " 2) View Record\n"
    << " 3) Search Record\n"
    << " 4) Delete Record\n"
    << " 5) Exit\n"
    << "=======================================\n";
    std::cout << "Enter your choice: ";

    std::cin >> choice;
    if(choice == 1)
    {
        int size;
        file1.open("db.csv", std::ios::app);
        std::cout << " Enter no. of people: ";
        std::cin >> size;
        userInfo u;
        for (size_t i = 0; i < size; i++)
        {
            std::cout << " Enter Name: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush buffer
            std::getline(std::cin, u.name);
            std::cout << " Enter Phone Number: ";
            std::getline(std::cin, u.phoneNumber);
            std::cout << " Enter Address: ";
            std::getline(std::cin, u.address);
            file1 << "\n" << u.name << "," << u.phoneNumber << "," << u.address;
        }
        file1.close();
    }
    else if( choice == 2) 
    {
        file1.open("db.csv", std::ios::in);
        std::string line;
        std::cout << std::left << std::setw(20) << "Name"
          << std::setw(15) << "Phone No."
          << std::setw(30) << "Address" << std::endl;
        std::cout << "-----------------------------------------------------------\n";
        while (std::getline(file1, line))
        {
            std::vector<std::string> splitter = split(line, ',');
            if(splitter.size() >= 3) {
            std::cout << std::left << std::setw(20) << splitter[0]
                << std::setw(15) << splitter[1]
                << std::setw(30) << splitter[2] << std::endl;
            }
        }
        file1.close();
    }
    else if (choice == 3)
    {
        file1.open("db.csv", std::ios::in);
        std::string name, line;
        std::cout << "Enter the person name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush buffer
        std::getline(std::cin, name);
        while (std::getline(file1, line))
        {
            std::vector<std::string> splitter = split(line, ',');
            if(splitter[0] == name)
            {
                std::cout << "\n--- Record Found ---\n";
                std::cout << "Name         : " << splitter[0] << "\n";
                std::cout << "Phone Number : " << splitter[1] << "\n";
                std::cout << "Address      : " << splitter[2] << "\n";
            }
        }

        file1.close();
    }
    else if( choice == 4 ) {
        std::fstream file1("db.csv", std::ios::in);        
        std::fstream tempFile("temp.csv", std::ios::out);
        std::string name, line;
        std::cout << "Enter the person name that is to be deleted: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush buffer
        std::getline(std::cin, name);
        std::vector<std::string> temp;
        while (std::getline(file1, line))
        {
            std::vector<std::string> splitter = split(line, ',');
            if(name == splitter[0])
            {
                std::cout << splitter[0];
                continue;
            }
            tempFile << line << "\n";
        }

        file1.close();
        tempFile.close();
        
        std::remove("db.csv");
        std::rename("temp.csv", "db.csv");
        
        std::cout << "Entry deleted successfully!\n";
    }
    else if (choice == 5) 
    {
        exit(0);
    }
    else std::cout << " Enter a Valid Option.";
    return 0;
}