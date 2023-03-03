#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

// Using Vector to check if the number is the same after new assigned
template <class T> bool isInVec(T key, std::vector<T> tempVec)
{
    for (auto i = 0; i < (int)tempVec.size(); i++)
    {
        if (key == tempVec.at(i))
        {
            return true;
        }
    }
    return false;
}

// Bool check OutOfbound user input number that have to be large then 1 and not out of range
template <class T> bool outOfBounds(T userInput, T range)
{
    if (userInput < 1 || userInput > range)
    {
        return true;
    }
    return false;
}

template <class T> std::vector<T> gen(T size, T range)
{
    // A pseudo random number generator in C++ std library
    static auto gen{std::mt19937{std::random_device{}()}};

    std::vector<T> vec1(range);
    std::vector<T> vec2;

    std::iota(vec1.begin(), vec1.end(), 1);
    std::shuffle(vec1.begin(), vec1.end(), gen);
    std::copy_n(vec1.cbegin(), size, std::back_inserter(vec2));
    return vec2;
}

// Range based for loop with const auto reference so that it doesn't copy itself and value doesn't modify
template <class T> void printVec(std::vector<T> vec)
{
    for (const auto &i : vec)
    {
        std::cout << i << " ";
    }
}
// cin only number if not number clear and ignore
void inputNumOnly()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{

    // Initialize
    const int mainSIZE = 5;
    const int luckySIZE = 2;
    const int winSIZE = mainSIZE + luckySIZE;
    // unsigned int winNums[winSIZE];
    unsigned int userNums[winSIZE];
    const unsigned int mainBallRange = 50;
    const unsigned int luckyBallRange = 12;
    const double main2 = 2.10;
    const double main2luck1 = 4.00;
    const double main1luck2 = 6.40;
    const double main3 = 4.10;
    const double main3luck1 = 7.10;
    const double main2luck2 = 12.90;
    const double main4 = 13.20;
    const double main3luck2 = 48.60;
    const double main4luck1 = 63.00;
    const double main4luck2 = 1160.80;
    const double main5 = 5042.10;
    const double main5luck1 = 91688.80;
    const double main5luck2 = 230000000.00;

    // Initialize Vector to store number
    std::vector<unsigned int> temp;
    std::vector<unsigned int> luckyTemp;
    std::vector<unsigned int> winTemp;
    std::vector<unsigned int> luckyWinTemp;
    std::vector<unsigned int> mainNum;
    std::vector<unsigned int> luckyNum;

    // Seed random number to time so that the number is randomized
    // std::srand((unsigned int)(std::time(nullptr)));

    /*GENERATE WINNING NUM*/

    // Loop through winSIZE of 5 then assign random number ranging from 1-50

    // for (auto i = 0; i < winSIZE - 2; i++)
    // {
    //     winNums[i] = rand() % mainBallRange + 1;
    //     // checking if number is in vector or not if it is, assign new random number
    //     while (isInVec(winNums[i], winTemp))
    //     {
    //         winNums[i] = rand() % mainBallRange + 1;
    //     }
    //     // then push the number into vector
    //     winTemp.push_back(winNums[i]);
    // }
    // // assign random lucky number ranging from 1-12
    // for (auto i = 5; i < winSIZE; i++)
    // {
    //     winNums[i] = rand() % luckyBallRange + 1;

    //     while (isInVec(winNums[i], luckyWinTemp))
    //     {
    //         winNums[i] = rand() % luckyBallRange + 1;
    //     }

    //     luckyWinTemp.push_back(winNums[i]);
    // }

    // Generating Lottory

    // Generate mainBallNum
    const auto &main = gen<unsigned int>(mainSIZE, mainBallRange);
    std::copy_n(main.cbegin(), mainSIZE, std::back_inserter(winTemp));
    std::sort(winTemp.begin(), winTemp.end());

    // Generate luckyBallNum
    const auto &lucky = gen<unsigned int>(luckySIZE, luckyBallRange);
    std::copy_n(lucky.cbegin(), luckySIZE, std::back_inserter(luckyWinTemp));
    std::sort(luckyWinTemp.begin(), luckyWinTemp.end());

    std::cout << "Winning Number: ";
    printVec(winTemp);
    std::cout << "\n";

    std::cout << "Lucky Number: ";
    printVec(luckyWinTemp);
    std::cout << "\n";

    // printArrToFile(winNums, winSIZE, outfile);

    std::cout << "Please Enter 5 unique numbers ranging from 1-50 and 2 lucky numbers ranging from 1-12"
              << "\n";

    /*USER INPUT */

    // Loop through winSIZE of 5 then get userInput for the first 5 number
    for (int i = 0; i < mainSIZE; i++)
    {
        std::cout << "Number " << i + 1 << ": ";
        std::cin >> userNums[i];

        // //while loop to check if userInput number is the same or out of bound then let user re-input the number
        while (isInVec(userNums[i], temp) || outOfBounds(userNums[i], mainBallRange))
        {
            std::cout << "please do not enter duplicate or out of range number"
                      << "\n";
            std::cout << "please re-enter choice " << i + 1 << ": ";
            inputNumOnly();
            std::cin >> userNums[i];
        }

        // Push userInput to vector
        temp.push_back(userNums[i]);
    }

    // user lucky number input
    for (int i = mainSIZE; i < winSIZE; i++)
    {
        std::cout << "Lucky Number" << i + 1 << ": ";
        std::cin >> userNums[i];
        while (isInVec(userNums[i], luckyTemp) || outOfBounds(userNums[i], luckyBallRange))
        {
            std::cout << "please do not enter duplicate or out of range number"
                      << "\n";
            std::cout << "Please re-enter lucky number" << i + 1 << ": ";
            inputNumOnly();
            std::cin >> userNums[i];
        }
        luckyTemp.push_back(userNums[i]);
    }

    std::sort(temp.begin(), temp.end());
    std::sort(luckyTemp.begin(), luckyTemp.end());

    std::set_intersection(winTemp.begin(), winTemp.end(), temp.begin(), temp.end(), std::back_inserter(mainNum));
    std::set_intersection(luckyWinTemp.begin(), luckyWinTemp.end(), luckyTemp.begin(), luckyTemp.end(),
                          std::back_inserter(luckyNum));

    std::cout << "Matched Main Number: ";
    std::cout << mainNum.size() << "\n";
    std::cout << "Matched Lucky Number: ";
    std::cout << luckyNum.size() << "\n";

    std::cout << std::setprecision(2) << std::fixed;

    if (mainNum.size() == 2 && luckyNum.size() == 1)
    {
        std::cout << "You win \u20AC" << main2luck1;
    }
    else if (mainNum.size() == 1 && luckyNum.size() == 2)
    {
        std::cout << "You win \u20AC" << main1luck2;
    }
    else if (mainNum.size() == 2 && luckyNum.size() == 2)
    {
        std::cout << "You win \u20AC" << main2luck2;
    }
    else if (mainNum.size() == 3 && luckyNum.size() == 1)
    {
        std::cout << "You win \u20AC" << main3luck1;
    }
    else if (mainNum.size() == 3 && luckyNum.size() == 2)
    {
        std::cout << "You win \u20AC" << main3luck2;
    }
    else if (mainNum.size() == 4 && luckyNum.size() == 1)
    {
        std::cout << "You win \u20AC" << main4luck1;
    }
    else if (mainNum.size() == 4 && luckyNum.size() == 2)
    {
        std::cout << "You win \u20AC" << main4luck2;
    }
    else if (mainNum.size() == 5 && luckyNum.size() == 1)
    {
        std::cout << "You win \u20AC" << main5luck1;
    }
    else if (mainNum.size() == 5 && luckyNum.size() == 2)
    {
        std::cout << std::fixed << "You hit the Jackpot of \u20AC" << main5luck2;
    }
    else if (mainNum.size() == 2)
    {
        std::cout << "You win \u20AC" << main2;
    }
    else if (mainNum.size() == 3)
    {
        std::cout << "You win \u20AC" << main3;
    }
    else if (mainNum.size() == 4)
    {
        std::cout << "You win \u20AC" << main4;
    }
    else if (mainNum.size() == 5)
    {
        std::cout << "You win \u20AC" << main5;
    }

    else
    {
        throw std::runtime_error("Undefined Behavior");
    }
}