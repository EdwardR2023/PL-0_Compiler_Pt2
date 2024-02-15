#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDENT_LEN 11
#define MAX_NUM_LEN 5
#define MAX_CODE_LEN 1000
#define MAX_STR_LEN 256

// Token types
enum {  skipsym = 1, identsym = 2, numbersym = 3, plussym = 4, minussym = 5,
    multsym = 6, slashsym = 7, fisym = 8, eqlsym = 9, neqsym = 10, lessym = 11,
    leqsym = 12, gtrsym = 13, geqsym = 14, lparentsym = 15, rparentsym = 16,
    commasym = 17, semicolonsym = 18, periodsym = 19, becomessym = 20,
    beginsym = 21, endsym = 22, ifsym = 23, thensym = 24, whilesym = 25, dosym = 26,
    callsym = 27, constsym = 28, varsym = 29, procsym = 30, writesym = 31,
    readsym = 32, elsesym = 33
};


// Token structure
typedef struct {
    int type;
    char value[MAX_IDENT_LEN + 1]; // +1 for null terminator
} Token;

// Array to store tokens
Token tokens[MAX_CODE_LEN];
int token_count = 0;

//Boolean is true while inside a comment
int isComment = 0;



// Function to check if a word is a keyword and return its token type
int is_keyword(const char *word) {

    if (strcmp(word, "null") == 0) return skipsym;
    if (strcmp(word, "begin") == 0) return beginsym;
    if (strcmp(word, "end") == 0) return endsym;
    if (strcmp(word, "if") == 0) return ifsym;
    if (strcmp(word,"fi") == 0) return fisym;
    if (strcmp(word, "then") == 0) return thensym;
    if (strcmp(word, "while") == 0) return whilesym;
    if (strcmp(word, "do") == 0) return dosym;
    if (strcmp(word, "call") == 0) return callsym;
    if (strcmp(word, "const") == 0) return constsym;
    if (strcmp(word, "var") == 0) return varsym;
    if (strcmp(word, "procedure") == 0) return procsym;
    if (strcmp(word, "write") == 0) return writesym;
    if (strcmp(word, "read") == 0) return readsym;
    if (strcmp(word, "else") == 0) return elsesym;
    return identsym;

    // If not a keyword, consider it an identifier
}

int is_symbol(const char *word) {
    if (strcmp(word, "+") == 0) return plussym;
    if (strcmp(word, "-") == 0) return minussym;
    if (strcmp(word, "*") == 0) return multsym;
    if (strcmp(word, "/") == 0) return slashsym;
    if (strcmp(word, "=") == 0) return eqlsym;
    if (strcmp(word, "<>") == 0) return neqsym;
    if (strcmp(word, "<") == 0) return lessym;
    if (strcmp(word, "<=") == 0) return leqsym;
    if (strcmp(word, ">") == 0) return gtrsym;
    if (strcmp(word, ">=") == 0) return geqsym;
    if (strcmp(word, "(") == 0) return lparentsym;
    if (strcmp(word, ")") == 0) return rparentsym;
    if (strcmp(word, ",") == 0) return commasym;
    if (strcmp(word, ";") == 0) return semicolonsym;
    if (strcmp(word, ".") == 0) return periodsym;
    if (strcmp(word, ":=") == 0) return becomessym;
    return -1;
}

void add_token(int type, char *value) {

    return identsym; // If not a keyword, consider it an identifier

}
//adds into token array
void add_token(int type, const char *value) {
    tokens[token_count].type = type;
    strcpy(tokens[token_count].value,value);
    token_count++;
 main

    strcpy(tokens[token_count].value, value);
    tokens[token_count++].type = type;
}

void tokenize_line(const char *line){

    int lineCounter = 0, wordLen = 0;
    char c = line[lineCounter++];
    while( ( c != '\n' && c != '.')|| isComment){

        char word[MAX_STR_LEN] = {0};
        //Keyword/Identifier loop
        if(isalpha(c)) {

            while (isalpha(c) || isdigit(c)) {

                word[wordLen++] = c;
                c = line[lineCounter++];
            }

            add_token(is_keyword(word), word);
        }

        //Number loop
        else if(isdigit(c)) {

            while (isdigit(c)) {

                word[wordLen++] = c;
                c = line[lineCounter++];
            }

            add_token(numbersym, word);
        }

        //Symbol loop
        else if(!isspace(c)) {

            while (!isspace(c)) {

                word[wordLen++] = c;
                c = line[lineCounter++];
            }

            int symType = is_symbol(word);

            if (symType == -1)
                printf("eh");
            else
                add_token(symType, word);
        } else{
            c = line[lineCounter++];
        }

        wordLen = 0;

    }

    if( c == '.') {

        add_token(periodsym, &c);
    }
}



// Main function
int main() {
    FILE *file = fopen("input.txt", "r"); // Open input file
    if (!file) {
        perror("Error opening file.\n");
        return 1;
    }

    char line[MAX_CODE_LEN];
    printf("SOURCE PROGRAM:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s",line);
        tokenize_line(line);
    }

    printf("\n\nLEXEME TABLE\n\nLexeme\t\tToken Type\n");
    for(int i = 0; i < token_count; i++){

        printf("%s\t\t%d\n", tokens[i].value, tokens[i].type);
    }

    printf("\nTOKEN LIST\n");
    for(int i = 0; i < token_count; i++){

        printf("%d ", tokens[i].type);

        if(tokens[i].type == 2 || tokens[i].type == 3)
            printf("%s ", tokens[i].value);
    }
    fclose(file);
    return 0;
}
