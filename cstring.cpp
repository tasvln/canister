/*
  Name: Temitope Oladimeji Samuel Adebayo

  I have done all the coding by myself and only copied the code that my professor 
  provided to complete my workshops and assignments.
*/

#include <iostream>

#include "cstring.h"

using namespace std;

namespace sdds{
  // Copies the source character string into the destination
  void strCpy(char* des, const char* src){
    int i;

    // Iterate through the source string and copy each character to the destination string
    for (i = 0; src[i] != '\0'; i++){
      des[i] = src[i];
    }

    // Add the null terminator to the end of the destination string
    des[i] = '\0';
  }

  // Copies the specified amount of characters from the source string and replaces their position in the destination.
  void strnCpy(char* des, const char* src, int len){
    int i;

    // Iterate through the source string and copy each character to the destination string
    for (i = 0; i < len && src[i] != '\0'; i++){
      des[i] = src[i];
    }

    // Add the null terminator to the end of the destination string
    if (i < len){
      des[i] = '\0';
    }
  }

  // Compares two C-strings
  int strCmp(const char* s1, const char* s2){
    int i = 0;

    // Iterate through the strings until the end of the string or until a character is different
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]){
      i++;
    }

    // If the strings are the same, return 0, else return the difference between the two characters ascii values
    return s1[i] - s2[i];
  }

  // Compares two C-strings up to specified amount of characters
  int strnCmp(const char* s1, const char* s2, int len){
    int i = 0;

    // Iterate through the strings until the end of the string or until a character is different, or until the length is reached
    while (i < len && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]){
      i++;
    }

    // If the strings are the same, return 0, else return the difference between the two characters ascii values
    if (i == len){
      return 0;
    }

    return s1[i] - s2[i];
  }

  // Returns the lenght of the C-string in characters
  int strLen(const char* s){
    int i = 0;

    // Iterate through the string until the null terminator is reached
    while (s[i] != '\0'){
      i++;
    }

    return i;
  }

  // Returns a pointer to the first occurance of "str2" in "str1"
  const char* strStr(const char* str1, const char* str2){
    int i = 0;

    // Get the length of the strings
    int str1Len = strLen(str1);
    int str2Len = strLen(str2);

    // Iterate through the string until the end of the string or until the length of the second string is reached
    while (i <= str1Len - str2Len){
      if (strnCmp(&str1[i], str2, str2Len) == 0){
        return &str1[i];
      }

      i++;
    }

    return nullptr;
  }

  // Concatinates "src" C-string to the end of "des"
  void strCat(char* des, const char* src){
    int i, desLen, srcLen;

    // Get the length of the strings
    desLen = strLen(des);
    srcLen = strLen(src);

    // Iterate through the source string and copy each character to the destination string
    for(i = 0; i < srcLen; i++){
      des[desLen + i] = src[i];
    }

    // add the null terminator to the end of the destination string
    des[desLen + i] = '\0';
  }
}