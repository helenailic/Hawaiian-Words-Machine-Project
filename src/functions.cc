#include "functions.hpp"

#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

/**
 * TODO: Implement this function
 * @param word word to change to lowercase
 * @return result of changing every character in word to lowercase
 */
std::string StringToLower(const std::string& word) {
  // std::cout << "Input to StringToLower() : " << word << std::endl;
  std::string lowerword;
  for (unsigned int i = 0; i < word.size(); ++i) {
    lowerword += (char)std::tolower(
        word.at(i));  // tolower returns ASCII integer, must cast char
  }
  return lowerword;
}

/**
 * TODO: Implement this function
 * @param v1 first character in potential vowel group
 * @param v2 second character in potential vowel group
 * @return true if v1 and v2 form a valid vowel group
 */
bool IsVowelGroup(const char& v1, const char& v2) {
  // std::cout << "Input to IsVowelGroup() : \"" << v1 << "\" \"" << v2 << "\""
  //<< std::endl;
  std::string gr;  //= v1; doesn't work becuse it casts char to string but its a
  // constant
  gr += v1;  //+= copies value of char v1 and then appends    gr = v1 + v2
             // doesn't like because it adds and then changes
  gr += v2;
  if (gr == "ai" || gr == "ae" || gr == "ao" || gr == "au" || gr == "ei") {
    return true;
  }
  if (gr == "eu" || gr == "iu" || gr == "oi" || gr == "ou" || gr == "ui") {
    return true;
  }
  return false;
}

/**
 * TODO: Complete this function
 * @param v potential vowel character
 * @return true if v is a vowel
 */
bool IsVowel(const char& v) {
  // std::cout << "Input to IsVowel() : \"" << v << "\"" << std::endl;
  if (v == 'a' || v == 'e' || v == 'i') {
    return true;
  }
  if (v == 'o' || v == 'u') {
    return true;
  }

  return false;
}

/**
 * TODO: Complete this function
 * @param c potential consonant character
 * @return true if c is a consonant
 */
bool IsConsonant(const char& c) {
  // std::cout << "Input to IsConsonant() : \"" << c << "\"" << std::endl;
  if (c == 'p' || c == 'k' || c == 'l' || c == 'h' || c == 'm') {
    return true;
  }
  if (c == 'n' || c == 'w') {
    return true;
  }

  return false;
}

/**
 * TODO: Implement this function
 * @param c character to check validity of
 * @return true if input c is a valid character in the Hawaiian language, false
 * otherwise
 */
bool IsValidCharacter(const char& c) {
  // std::cout << "Input to IsValidCharacter() : \"" << c << "\"" << std::endl;
  if (c == ' ' || c == '\'' || c == 'a' || c == 'e' || c == 'i' || c == 'o') {
    return true;
  }
  if (c == 'u' || c == 'p' || c == 'k' || c == 'h' || c == 'l' || c == 'm' ||
      c == 'n' || c == 'w') {
    return true;
  }
  return false;
}

/**
 * TODO: Implement this function
 * @param word word to check validity of
 * @return true if every character in word is a valid character in the Hawaiian
 * language, false otherwise
 */
bool IsValidWord(const std::string& word) {
  // std::cout << "Input to IsValidWord() : " << word << std::endl;
  for (unsigned int i = 0; i < word.size(); ++i) {
    if (!(IsValidCharacter(word.at(i)))) {
      return false;
    }
  }
  return true;
}

/**
 * TODO: Implement this function
 * @param c consonant to get pronunciation of
 * @param prev character before c, used for determining w translation
 *    set to null character as default if no value is passed in
 * @return pronunciation of the consonant c as a char
 */
char ConsonantPronunciation(const char& c, const char& prev) {
  // std::cout << "Input to ConsonantPronunciation() : \"" << c << "\" \"" <<
  // prev
  //  << "\"" << std::endl;
  if ((c == 'w' && prev == 'i') || (c == 'w' && prev == 'e')) {
    return 'v';
  }
  return c;
}

/**
 * TODO: Implement this function
 * @param v1 first vowel in a vowel grouping
 * @param v2 second vowel in a vowel grouping
 * @return the pronunciation of the vowel grouping made up of v1 and v2
 * as a string
 */
std::string VowelGroupPronunciation(const char& v1, const char& v2) {
  // std::cout << "Input to VowelGroupPronunciation() : \"" << v1 << "\" \"" <<
  // v2
  //<< "\"" << std::endl;
  // 2 lowercase vowels form a valid vowel group
  std::string gr;  //= v1; doesn't work becuse it casts char to string but its a
  // constant
  gr += v1;  //+= copies value of char v1 and then appends    gr = v1 + v2
             // doesn't like because it adds and then changes
  gr += v2;
  if (gr == "ai" || gr == "ae") {
    return "eye";
  }
  if (gr == "ao" || gr == "au") {
    return "ow";
  }
  if (gr == "ei") {
    return "ay";
  }
  if (gr == "eu") {
    return "eh-oo";
  }
  if (gr == "iu") {
    return "ew";
  }
  if (gr == "oi") {
    return "oy";
  }
  if (gr == "ou") {
    return "ow";
  }
  if (gr == "ui") {
    return "ooey";
  }
  return gr;
}

/**
 * TODO: Implement this function
 * @param v single vowel to get pronunciation of
 * @return the pronunciation of v as a string
 */
std::string SingleVowelPronunciation(const char& v) {
  // std::cout << "Input to SingleVowelPronunciation() : \"" << v << "\""
  //<< std::endl;
  std::string vstr;
  vstr += v;
  if (v == 'a') {
    return "ah";
  }
  if (v == 'e') {
    return "eh";
  }
  if (v == 'i') {
    return "ee";
  }
  if (v == 'o') {
    return "oh";
  }
  if (v == 'u') {
    return "oo";
  }

  return vstr;
}

/**
 * TODO: Implement this function
 * @param prev first character in set of three passed to function
 * @param curr second character in set of three passed to function
 * @param next third character in set of three passed to function
 * @return pronunciation of curr using next and prev as needed to determine
 * result
 */
std::string ProcessCharacter(const char& prev,
                             const char& curr,
                             const char& next) {
  // std::cout << "Input to ProcessCharacter() : \"" << prev << "\" \"" << curr
  //<< "\" \"" << next << "\"" << std::endl;

  // prev, curr, and next 3 characters
  // pronunciation of curr based on prev and next
  std::string currstr;
  currstr += curr;

  // if (IsVowelGroup(prev, curr)) {
  //   return VowelGroupPronunciation(prev, curr);
  if (IsVowelGroup(curr, next)) {
    return VowelGroupPronunciation(curr, next);
  }
  if (IsVowel(curr)) {
    return SingleVowelPronunciation(curr);
  }
  if (IsConsonant(curr)) {
    std::string constr;
    constr += ConsonantPronunciation(curr, prev);
    return constr;
  }

  return currstr;
}

/**
 * TODO: Implement this function
 * @param word string to get pronunciation of
 * @return pronunciation of word
 */
std::string Pronunciation(const std::string& word) {
  std::string newword;
  unsigned int i = 0;
  while (i < word.size()) {
    if (i == 0) {
      newword += ProcessCharacter('*', word.at(i), word.at(i + 1));
      if (i != word.size() - 1 && IsVowelGroup(word.at(i), word.at(i + 1))) {
        ++i;
      }
    } else if (i == word.size() - 1) {
      newword += ProcessCharacter(word.at(i - 1), word.at(i), '*');
      if (i != word.size() - 1 && IsVowelGroup(word.at(i), word.at(i + 1))) {
        ++i;
      }
    } else {
      newword += ProcessCharacter(word.at(i - 1), word.at(i), word.at(i + 1));
      if (i != word.size() - 1 && IsVowelGroup(word.at(i), word.at(i + 1))) {
        ++i;
      }
    }

    if (i != 0 && i != word.size() - 1 &&
        IsVowelGroup(word.at(i - 1), word.at(i)) && word.at(i + 1) != '\'' &&
        word.at(i + 1) != ' ') {
      newword += "-";
      // std::cout << "HERE" << std::endl;
    } else if (i != word.size() - 1 && i != word.size() - 2 &&
               IsVowelGroup(word.at(i), word.at(i + 1)) &&
               word.at(i + 2) != '\'' && word.at(i + 2) != ' ') {
      newword += "-";
    } else if (i != word.size() - 1 && IsVowel(word.at(i)) &&
               !(IsVowelGroup(word.at(i), word.at(i + 1))) &&
               word.at(i + 1) != '\'' && word.at(i + 1) != ' ') {
      newword += "-";
    }

    ++i;
  }
  return newword;
}

/**
 * TODO: Implement this function
 * @param hawaiian_word word to get pronunciation of
 * @return the pronunciation of hawaiian_word as a string if valid
 *  and throws an invalid_argument error if not valid
 */

std::string GetPronunciation(const std::string& hawaiian_word) {
  // std::cout << "Input to GetPronunciation() : " << hawaiian_word <<
  // std::endl;

  std::string hawaiian_word_std;
  for (unsigned int i = 0; i < hawaiian_word.size(); ++i) {
    hawaiian_word_std += (char)tolower(hawaiian_word.at(i));
  }

  if (IsValidWord(hawaiian_word_std)) {
    return Pronunciation(hawaiian_word_std);
  }
  throw std::invalid_argument("not a valid hawaiian word");
}