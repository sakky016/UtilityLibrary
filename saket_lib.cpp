#include "saket_lib.h"

#define USEDEBUG  // Comment to stop debug info

#ifdef USEDEBUG
#define Debug(x) std::cout << x
#else
#define Debug(x) 
#endif

/****************************************************************************************** 
@name        : findFact

@descriptions: Finding factorial of a number and stores them in factMap for
               future reference. This provides a faster calculation in case
               findFact is used multiple times to call factorial of same numbers. 
******************************************************************************************/
map<unsigned long long, unsigned long long> factMap;

unsigned long long findFact(unsigned long long num)
{
    unsigned long long result = 1;

    /* Check if already present in factMap. */
    auto it = factMap.find(num);
    if (it != factMap.end())
    {
        Debug("Found in Fact Map" << endl);
        return it->second;
    }
    else if (num == 0)
    {
        factMap[num] = result;
        return result;
    }
    else
    {
        for (unsigned long long i = 1; i <= num; i++)
        {
            result = result * i;
            Debug( i << " x ");
        }
        Debug(endl);

        factMap[num] = result;
    }

    return result;
}

/******************************************************************************************
@name        : findPermutation

@descriptions:  nPr = n!/r! * (n-r)!
******************************************************************************************/
int findPermutation(int n, int r)
{
    int result = 1;

    /* Input Validation */
    if (n <= 0)
    {
        return 0;
    }

    if (r <= 0)
    {
        return 0;
    }

    if (n - r == 0)
    {
        return 1;
    }

    result = findFact(n) / (findFact(r) * findFact(n - r));

    return result;
}

/******************************************************************************************
@name        : findCombinations

@descriptions:  nPr = n!/(n-r)!
******************************************************************************************/
int findCombinations(int n, int r)
{
    int result = 1;

    /* Input Validation */
    if (n <= 0)
    {
        return 0;
    }

    if (r <= 0)
    {
        return 0;
    }

    if (n - r == 0)
    {
        return 1;
    }

    result = findFact(n) / findFact(n - r);

    return result;
}

/******************************************************************************************
@name        : findBinary

@param num   : Number whose binary has to be found
@param bits  : Total bits which should be represented in the binary form. A value of -1
               will mean that bits according to size of unsigned long long will be considered.

@descriptions: Finding Binary of a number and stores them in binaryMap for
               future reference. This provides a faster calculation in case
               findBinary is used multiple times to find binary of same number.
******************************************************************************************/
map<unsigned long long, string> binaryMap;

string findBinary(unsigned long long num, int bits)
{
    string result;

    if (bits == -1)
    {
        bits = 8 * sizeof(num);
        Debug("Bits: " << bits << endl);
    }

    /* Check if already present in Binary map. */
    auto it = binaryMap.find(num);
    if (it != binaryMap.end())
    {
        Debug("Found in Binary Map" << endl);
        return it->second;
    }

    /* Create a dummy result. */
    for (int i = 0; i < bits; i++)
    {
        result.append("0");
    }

    //cout << result.size() << endl;
    /* Not present in map, calculate binary. */
    unsigned long long one = 1;
    for (int i = 0; i < bits; i++)
    {
        unsigned long long tmp = 1 << i;
        if ((num & tmp) == 0)
        {
            result[bits - i - 1] = '0';
        }
        else
        {
            result[bits - i - 1] = '1';
        }
    }
    //cout << result.size() << endl;
    
    binaryMap[num] = result;
    return result;
}

/******************************************************************************************
@name        : findBinariesUpto

@param num   : Number = (2^num) upto which binaries have to be calculated.

@descriptions: Returns a vector of strings of binary values of 1 to (2^num).
******************************************************************************************/
vector<string> findBinariesUpto(unsigned long long num)
{
    vector<string> result;
    unsigned long long arrangmentsCount = pow(2, num);
    
    for (unsigned long long i = 0; i < arrangmentsCount; i++)
    {
        if (i != 0)
        {
        string binaryValue = findBinary(i, num);
        Debug(binaryValue << endl);
        result.push_back(binaryValue);
        }
    }

    return result;
}

/******************************************************************************************
@name        : findArrangements

@param inp   : Input string whose arrangements has to be determined

@descriptions: Returns a vector of strings of different possible arrangements of inp string.
               Different order of same characters is not considered.
******************************************************************************************/
vector<string> findArrangements(string inp)
{
    int count = inp.size();

    /* find binary representation. */
    vector<string> arrangmentBinaries = findBinariesUpto(count);

    vector<string> arrangementsVector;
    for (int i = 0; i < arrangmentBinaries.size(); i++)
    {
        string arrangmentBinary = arrangmentBinaries[i];
        string str;
        for (int j = 0; j < count; j++)
        {
            if (arrangmentBinary[j] == '1')
            {
                str.push_back(inp[j]);
            }
        }
        arrangementsVector.push_back(str);
    }

    return arrangementsVector;
}

/******************************************************************************************
@name        : checkAnagram

@param inp1   : String 1
@param inp2   : String 2

@descriptions: An anagram is a word formed by rearranging the letters of another word
               using all the original letters exactly once. Returns true if inp1 and inp2 are
               anagrams else false.
******************************************************************************************/
bool checkAnagram(string inp1, string inp2)
{
    map<char, int> charMap;

    for (int i = 0; i < inp1.size(); i++)
    {
        charMap[inp1[i]]++;
    }

    for (int i = 0; i < inp2.size(); i++)
    {
        charMap[inp2[i]]++;
    }

    auto it = charMap.begin();
    bool isAnagram = true;
    while (it != charMap.end())
    {
        if (it->second != 2)
        {
            isAnagram = false;
        }
        it++;
    }

    return isAnagram;
}

/******************************************************************************************
@name        : findLongestChain

@param inp   : Input vector of ints
@param idx1  : starting index
@param idx2  : end index

@descriptions: Returns a vector of longest possible sequence within [idx1, idx2] which is
               non-decreasing. 0-based indexing is used. 
******************************************************************************************/
vector<int> findLongestChain(vector<int> inp, int idx1, int idx2)
{
    vector<int> result;
    vector<int> tmp;

    // Input validation
    if (inp.size() < 2)
    {
        cout << "ERROR: Invalid input size" << endl;
        return result;
    }

    if (idx1 < 0 || idx1 > inp.size() - 2)
    {
        cout << "ERROR: Invalid idx1" << endl;
        return result;
    }

    if (idx2 < 1 || idx2 > inp.size() - 1)
    {
        cout << "ERROR: Invalid idx2" << endl;
        return result;
    }

    /* Processing */
    for (int i = idx1; i <= idx2; i++)
    {
        if (i == idx1)
        {
            result.push_back(inp[i]);
        }
        else if (inp[i] >= inp[i - 1])
        {
            result.push_back(inp[i]);
        }
        else
        {
            // Save only if new chain is larger than previous one
            if (result.size() > tmp.size())
            {
                tmp = result;
            }

            result.clear();
            result.push_back(inp[i]);
        }
    }

    // Handling to cater to cases where we reach end of vector without
    // any clearing of it.
    if (result.size() > tmp.size())
    {
        return result;
    }
    else
    {
        return tmp;
    }
}

bool isPalindrome(int num)
{
    int reversedInteger = 0;
    int remainder = 0;
    int originalInteger = 0;

    originalInteger = num;

    // reversed integer is stored in variable 
    while (num != 0)
    {
        remainder = num % 10;
        reversedInteger = reversedInteger * 10 + remainder;
        num /= 10;
    }

    Debug("Original: " << originalInteger << endl);
    Debug("Reversed: " << reversedInteger << endl);
    // palindrome if orignalInteger and reversedInteger are equal
    if (originalInteger == reversedInteger)
        return true;
    else
        return false;
}

bool isPalindrome(string& str)
{
    string revStr;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        revStr.push_back(str[len - 1 - i]);
    }

    if (str == revStr)
    {
        return true;
    }
    else
    {
        return false;
    }
}