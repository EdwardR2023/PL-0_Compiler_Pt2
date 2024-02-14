#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDENT_LEN 11
#define MAX_NUM_LEN 5
#define MAX_CODE_LEN 1000

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


// Function to check if a word is a keyword and return its token type
int is_keyword(const char *word) {

    return identsym; // If not a keyword, consider it an identifier
}

void add_token(int type, const char *value) {

}

void tokenize_line(const char *line){

}



// Main function
int main() {
    FILE *file = fopen("input.txt", "r"); // Open input file
    if (!file) {
        perror("Error opening file.\n");
        return 1;
    }

    char line[MAX_CODE_LEN];
    while (fgets(line, sizeof(line), file)) {
        printf("%s",line);

    }
    fclose(file);
    return 0;
}
