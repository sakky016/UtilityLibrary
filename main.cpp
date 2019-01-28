#include "saket_lib.h"

/* M A I N
*  Driver program to use library functions */
int main()
{
    unsigned long long num = 255;
    cout << findFact(10) << endl;;

    cout << findBinary(num, 32) << endl;;
    
    string inp = "abcdefg";
    cout << endl << "Arrangements of:" << inp<<endl;

    vector<string> arrangementsVector = findArrangements(inp);
    cout << "Total arrangements possible: " << arrangementsVector.size()<<endl;
    for (int i = 0; i < arrangementsVector.size(); i++)
    {
        cout << arrangementsVector[i] << endl;
    }

    string inp1 = "vinay";
    string inp2 = "vainy";
    cout << endl << "Check Anagram: " << endl;
    cout << "Inp1: " << inp1 << endl;
    cout << "Inp2: " << inp2 << endl;
    if (checkAnagram(inp1, inp2))
    {
        cout << "They are anagram" << endl;
    }
    else
    {
        cout << "They are NOT anagram" << endl;
    }

    //vector<int> inp3 = { 5, 1, 2, 3, 4, 6, 7, 2, 4, 9, 12, 1, 14, 15, 16 };
    vector<int> inp3 = {1,3,2,3,3,4,1,2,3,4,5,4,3,2,1,0};
    vector<int> result;
    cout << endl << "Longest increasing chain of: " << endl;
    for (int i = 0; i < inp3.size(); i++)
    {
        cout << inp3[i] << " ";
    }
    cout << endl;

    result = findLongestChain(inp3, 0, inp3.size() - 1);
    cout << "Result: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    int inp4 = 404;
    bool isPalind = isPalindrome(404);
    if (isPalind)
    {
        cout << inp4<<" is a palindrome" << endl;
    }
    else
    {
        cout << inp4 << " is NOT a palindrome" << endl;
    }

    string inp5 = "malayalam";
    isPalind = isPalindrome(inp5);
    if (isPalind)
    {
        cout << inp5 << " is a palindrome" << endl;
    }
    else
    {
        cout << inp5 << " is NOT a palindrome" << endl;
    }

    int n = 4;
    int r = 2;
    int perm = findPermutation(n, r);
    cout << "Permutation: (n,r) = " << n <<" "<<r << endl;
    cout << perm << endl;

    getchar();
    return 0;
}