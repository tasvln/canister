/*
  Name: Temitope Oladimeji Samuel Adebayo

  I have done all the coding by myself and only copied the code that my professor 
  provided to complete my workshops and assignments.
*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds {
  // Copies the soruce character string into the destination
  void strCpy(char* des, const char* src);
  // Copies the specified amount of characters from the source string and replaces their position in the destination.
  void strnCpy(char* des, const char* src, int len);
  // Compares two C-strings
  int strCmp(const char* s1, const char* s2);
  // Compares two C-strings up to specified amount of characters
  int strnCmp(const char* s1, const char* s2, int len);
  // Returns the lenght of the C-string in characters
  int strLen(const char* s);
  // Returns a pointer to the first occurance of "str2" in "str1"
  const char* strStr(const char* str1, const char* str2);
  // Concatinates "src" C-string to the end of "des"
  void strCat(char* des, const char* src);
}

#endif