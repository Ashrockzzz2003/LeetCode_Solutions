class Solution {
public:
    bool isValid(string word) {
        /*
        A word is considered valid if:

            It contains a minimum of 3 characters.
            It consists of the digits 0-9, and the uppercase and lowercase English letters. (Not necessary to have all of them.)
            It includes at least one vowel.
            It includes at least one consonant.
        */
        
        if (word.length() < 3) {
            return false;
        }
        
        bool isDigitPresent = false, isUpperCasePresent = false, isLowerCasePresent = false, isVowelPresent = false, isConsonantPresent = false;
        
        for(char& c : word) {
            if (isdigit(c) == 1) {
                isDigitPresent = true;
            } else if (isalpha(c) > 0 && tolower(c) == c) {
                isLowerCasePresent = true;
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    isVowelPresent = true;
                } else {
                    isConsonantPresent = true;
                }
            } else if (isalpha(c) > 0 && toupper(c) == c) {
                isUpperCasePresent = true;
                if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    isVowelPresent = true;
                } else {
                    isConsonantPresent = true;
                }
            } else {
                return false;
            }
        }
        
        return (isDigitPresent || isUpperCasePresent || isLowerCasePresent) && (isVowelPresent && isConsonantPresent);
    }
};