#include <iostream>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
int MajorColorCount = sizeof(majorColor)/sizeof(majorColor[0]);
int MinorColorCount = sizeof(minorColor)/sizeof(minorColor[0]);


std::string getMajorColorofPair(int pairNumber)
{
    int zerobasedIndex = pairNumber - 1;
    int majorColorIndex = zerobasedIndex/MajorColorCount;
    return majorColor[majorColorIndex];
}

std::string getMinorColorofPair(int pairNumber)
{
    int zerobasedIndex = pairNumber - 1;
    int minorColorIndex = zerobasedIndex % MinorColorCount;
    return minorColor[minorColorIndex];
}
std::string getColorPair(int pairNumber)
{
    return getMajorColorofPair(pairNumber) + "|" + getMinorColorofPair(pairNumber);
}

int printColorMap(std::string(*getColorPair(int pairNum)) {
    int i;
    for(i = 0; i < 25; i++) {
        std::string colorPair = getColorPair(i);
        if(!colorPair.empty())
        {
            std::cout << i << "|" << colorPair<< "\n";
        }
        else
        {
            std::cout << "Error in pair \n"<< i ;
            break;
        }
    }
    return i;
}

int main() {
    int result = printColorMap(getColorPair);
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
