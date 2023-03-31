#pragma once
#include <iostream>
using std::string;

class Subsequences{
  public:
    Subsequences(string word): word(word){}
    bool isSubsequence(string sub);
    bool isSubsequence(string sub, int subPos, int wordPos);
  private:
    string word;
};

bool Subsequences::isSubsequence(string sub){
  return isSubsequence(sub, 0, 0);
}

bool Subsequences::isSubsequence(string sub, int subPos, int wordPos){
  if(subPos == sub.size()){
    return true;
  }
  else if(wordPos == word.size()){
    return false;
  }
  if(sub[subPos] == word[wordPos]){
    return isSubsequence(sub, subPos + 1, wordPos + 1);
  }
  else if(sub[subPos] != word[wordPos]){
    return isSubsequence(sub, subPos, wordPos + 1);
  }
}
