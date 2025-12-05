#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* List of C keywords (basic set) */
const char *keywords[] = {
    "auto","break","case","char","const","continue","default","do","double","else",
    "enum","extern","float","for","goto","if","int","long","register","return",
    "short","signed","sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while","inline","restrict", NULL
};

/* Check if given string is a keyword */
int is_keyword(const char *s) {
    for (int i = 0; keywords[i]; ++i) if (strcmp(s, keywords[i]) == 0) return 1;
    return 0;
}

/* Print token type and lexeme aligned */
void print_token(const char *type, const char *lexeme) {
    printf("%-15s : %s\n", type, lexeme);
}

int main() {
    FILE *fp = fopen("input.c", "r");
    if (!fp) {
        printf("Cannot open input.c\n");
        return 1;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        /* Skip whitespace */
        if (isspace(c)) continue;

        /* Identifiers and keywords: start with letter or underscore */
        if (isalpha(c) || c == '_') {
            char buf[256]; int idx = 0;
            buf[idx++] = c;
            while ((c = fgetc(fp)) != EOF && (isalnum(c) || c == '_')) {
                if (idx < (int)sizeof(buf)-1) buf[idx++] = c;
            }
            buf[idx] = '\0';
            if (c != EOF) ungetc(c, fp);
            if (is_keyword(buf)) print_token("KEYWORD", buf);
            else print_token("IDENTIFIER", buf);
            continue;
        }

        /* Numbers: integer and simple float support */
        if (isdigit(c)) {
            char buf[256]; int idx = 0; int dot = 0;
            buf[idx++] = c;
            while ((c = fgetc(fp)) != EOF && (isdigit(c) || (c=='.' && !dot))) {
                if (c=='.') dot = 1;
                if (idx < (int)sizeof(buf)-1) buf[idx++] = c;
            }
            buf[idx] = '\0';
            if (c != EOF) ungetc(c, fp);
            print_token("NUMBER", buf);
            continue;
        }

        /* String literal handling (handles escaped chars simply) */
        if (c == '"') {
            char buf[1024]; int idx = 0;
            buf[idx++] = '"';
            while ((c = fgetc(fp)) != EOF) {
                buf[idx++] = c;
                if (c == '\\') {
                    int nxt = fgetc(fp);
                    if (nxt == EOF) break;
                    if (idx < (int)sizeof(buf)-1) buf[idx++] = nxt;
                    continue;
                }
                if (c == '"') break;
                if (idx >= (int)sizeof(buf)-1) break;
            }
            buf[idx] = '\0';
            print_token("STRING_LITERAL", buf);
            continue;
        }

        /* Comments: // single-line or /* multi-line *\/ */
        if (c == '/') {
            int nxt = fgetc(fp);
            if (nxt == '/') {
                char buf[1024]; int idx = 0;
                buf[idx++] = '/'; buf[idx++] = '/';
                while ((c = fgetc(fp)) != EOF && c != '\n') {
                    if (idx < (int)sizeof(buf)-1) buf[idx++] = c;
                }
                buf[idx] = '\0';
                print_token("COMMENT", buf);
                continue;
            } else if (nxt == '*') {
                char buf[4096]; int idx = 0;
                buf[idx++] = '/'; buf[idx++] = '*';
                int prev = 0;
                while ((c = fgetc(fp)) != EOF) {
                    if (idx < (int)sizeof(buf)-1) buf[idx++] = c;
                    if (prev == '*' && c == '/') break;
                    prev = c;
                }
                buf[idx] = '\0';
                print_token("COMMENT", buf);
                continue;
            } else {
                if (nxt != EOF) ungetc(nxt, fp);
            }
        }

        /* Try two-character operators first */
        int nxt = fgetc(fp);
        if (nxt != EOF) {
            char two[3] = {(char)c, (char)nxt, '\0'};
            const char *ops2[] = {"==","!=","<=",">=","&&","||","++","--","+=","-=","*=","/=","%=","<<",">>", NULL};
            int matched = 0;
            for (int i = 0; ops2[i]; ++i) {
                if (strcmp(two, ops2[i]) == 0) {
                    print_token("OPERATOR", two);
                    matched = 1;
                    break;
                }
            }
            if (matched) continue;
            ungetc(nxt, fp);
        }

        /* Single-character operators and separators */
        char single[2] = {(char)c, '\0'};
        const char *ops1 = "+-*/%=<>&|^~!?:.";
        const char *seps = ",;(){}[]";
        if (strchr(ops1, c)) print_token("OPERATOR", single);
        else if (strchr(seps, c)) print_token("SEPARATOR", single);
        else {
            char s[4] = {single[0], 0, 0, 0};
            print_token("UNKNOWN", s);
        }
    }

    fclose(fp);
    return 0;
}
