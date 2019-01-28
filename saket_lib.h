#pragma once
#include<map>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

unsigned long long findFact(unsigned long long num);
int findPermutation(int n, int r);
int findCombinations(int n, int r);
string findBinary(unsigned long long num, int bits);
vector<string> findBinariesUpto(unsigned long long num);
vector<string> findArrangements(string inp);
bool checkAnagram(string inp1, string inp2);
vector<int> findLongestChain(vector<int> inp, int idx1, int idx2);
bool isPalindrome(int num);
bool isPalindrome(string& str);