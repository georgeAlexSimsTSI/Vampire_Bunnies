#include "../include/bunnyManager.h"

#include <iostream>
#include <fstream>

int main()
{
    system("cls");
    std::ifstream namesFile;
    std::string name;
    // male names are from https://www.verywellfamily.com/top-1000-baby-boy-names-2757618
    std::vector<std::string> maleBunnyNames;
    try
    {
        namesFile.open("../maleNames.txt");
        while (namesFile)
        {
            std::getline(namesFile, name);
            if (!name.empty())
                maleBunnyNames.push_back(name);
        }
        namesFile.close();
    }
    catch (...)
    {
        namesFile.close();
        maleBunnyNames = {"Jason", "Liam", "Noah", "Oliver", "Peter"};
    }
    // female names are from https://www.verywellfamily.com/top-1000-baby-girl-names-2757832
    std::vector<std::string> femaleBunnyNames;
    try
    {
        namesFile.open("../femaleNames.txt");
        while (namesFile)
        {
            std::getline(namesFile, name);
            if (!name.empty())
                femaleBunnyNames.push_back(name);
        }
        namesFile.close();
    }
    catch (...)
    {
        namesFile.close();
        femaleBunnyNames = {"Olivia", "Emma", "Charlotte", "Amelia", "Ava"};
    }
    std::vector<std::string> infectedBunnyNames{"Patient Zero"};

    int gridHeight = 80, gridWidth = 80, startingNumber = 500; // would recomend a smaller grid size as it is easier to read
    bool verbose = false;
    BunnyManager manager = BunnyManager(maleBunnyNames, femaleBunnyNames, infectedBunnyNames, gridHeight, gridWidth, startingNumber, verbose); // numbers are x , y and starting number
    manager.run();
}