#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to print tokens
void printToken(const char *start, int length) {
    char token[length + 1];
    strncpy(token, start, length);
    token[length] = '\0';
    printf("%s\n", token);
}

// Function to parse the string
void parseString(const char *input) {
    int length = strlen(input);
    int inDoubleQuote = 0;
    int inSingleQuote = 0;
    const char *start = input;
    
    for (int i = 0; i <= length; i++) {
        char c = input[i];
        if (c == '"' && !inSingleQuote) 
        {
            inDoubleQuote = !inDoubleQuote;
        } 
        else if (c == '\'' && !inDoubleQuote) 
        {
            inSingleQuote = !inSingleQuote;
        } 
        else if (isspace(c) && !inDoubleQuote && !inSingleQuote) 
        {
            if (i > start - input) 
            {
                printToken(start, i - (start - input));
            }
            start = input + i + 1;
        }
    }
    
    if (start < input + length) 
    {
        printToken(start, input + length - start);
    }
}

int main() {
    const char *input = "l\"s\" >  \"hello \" <'worde  \"'-l -a\" \"\" > \"\" out";
    printf("%s\n",input);
    parseString(input);
    return 0;
}
