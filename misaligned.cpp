#include <iostream>
#include <cstring>
#include <string>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int MajorColorCount = sizeof(majorColor)/sizeof(majorColor[0]);
int MinorColorCount = sizeof(minorColor)/sizeof(minorColor[0]);

int MaxColorPair = MajorColorCount * MinorColorCount;

uint getMaxlengthofMajorColors()
{
    uint maxlength = 0;
    for(int i = 0; i < MajorColorCount ; i++)
    {
        maxlength = maxlength < strlen(majorColor[i])? strlen(majorColor[i]): maxlength;
    }
    return maxlength;
}
uint MajorColorMaxlen = getMaxlengthofMajorColors();

std::string getMajorColorofPair (int pairNumber)
{
   std::string majorColorString = "";
   if(pairNumber > 0 && pairNumber <= MaxColorPair)
   {
      int zerobasedIndex = pairNumber - 1;
      int majorColorIndex = zerobasedIndex / MajorColorCount;
      majorColorString = majorColor[majorColorIndex];
   }
  return majorColorString;
}

std::string getMinorColorofPair (int pairNumber)
{
   std::string minorColorString = "";
   if(pairNumber > 0 && pairNumber <= MaxColorPair)
   {
      int zerobasedIndex = pairNumber - 1;
      int minorColorIndex = zerobasedIndex % MinorColorCount;
      minorColorString = minorColor[minorColorIndex];
   }
  return minorColorString;
}

std::string appendSpaces(std::string majorColor)
{
    int spaceTobeAdded = static_cast < int >(MajorColorMaxlen - majorColor.length () + 2);	//2 spacs offset
    for (; spaceTobeAdded > 0; spaceTobeAdded--)
    {
      majorColor = majorColor + " ";
    }
    return majorColor;
    
}
std::string getColorPair(int pairNumber)
{
  std::string majorColorPair = getMajorColorofPair (pairNumber);
  std::string minorolorPair = getMinorColorofPair (pairNumber);
  std::string pairString = appendSpaces(majorColorPair) + "   |   "+ minorolorPair;
  return pairString;
}

int printColorMap(std::string(*getColorPair)(int pairNum)) {
    int i;
    for(i = 0; i < 25; i++) {
        std::string colorPair = getColorPair(i);
        if(!colorPair.empty())
        {
            std::cout << i << "  |  " << colorPair<< "\n";
        }
        else
        {
            std::cout << "Error in pair \n"<< i ;
            break;
        }
        if(i == MaxColorPair)
	    {
	       break;
	    }
    }
    return i;
}

int main() {
    int result = printColorMap(getColorPair);
    assert(result == 25);
    assert (getMinorColorofPair(11) == "Blue");
    assert (getMajorColorofPair(17) == "Yellow");
    assert (getMajorColorofPair(27) == "");
    std::cout << "All is well (maybe!)\n";
    return 0;
}
