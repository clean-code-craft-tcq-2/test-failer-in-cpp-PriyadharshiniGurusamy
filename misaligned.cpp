#include <iostream>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
MajorColorCount = sizeof(majorColor)/sizeof(majorColor[0]);
MinorColorCount = sizeof(minorColor)/sizeof(minorColor[0]);

int printColorMap() {
    for(int i = 0; i < 25;) {
        std::string colorPair = getColorPair(i);
        if(!colorPair.empty())
        {
            std::cout << i << "|" << colorPair;
            i++;
        }
        else
        {
            std::cout << "Error in pair \n"<< i ;
            break;
        }
    }
    return i;
}

std::string getColorPair(int pairNumber)
{
    std::string colorPair = getMajorColorofPair(pairNumber) + "|" + getMinorColorofPair(pairNumber);
}

std::string getMajorColorofPair(int pairNumber)
{
    int zerobasedIndex = pairNumber - 1;
    majorColorIndex = zerobasedIndex/MajorColorCount;
    return std::string majorcolor = majorColor[majorColorIndex];
}


std::string getMinorColorofPair(int pairNumber)
{
    int zerobasedIndex = pairNumber - 1;
    minorColorIndex = zerobasedIndex/MinorColorCount;
    return std::string minorcolor = minorColor[minorColorIndex];
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
