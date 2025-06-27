#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidUsername(const char* username) {
    int len = strlen(username);
    return len >= 3 && len <= 20;
}

int isValidEmail(const char* email) {
    int at = 0, dot = 0;
    for (int i = 0; email[i]; i++) {
        if (email[i] == '@') at++;
        else if (email[i] == '.') dot++;
    }
    return (at == 1 && dot >= 1);
}

int isValidPassword(const char* password) {
    int hasSpecial = 0, hasDigit = 0;
    for (int i = 0; password[i]; i++) {
        if (!isalnum(password[i])) hasSpecial = 1;
        if (isdigit(password[i])) hasDigit = 1;
    }
    return (strlen(password) >= 6 && hasSpecial && hasDigit);
}

int isPasswordMatch(const char* pass, const char* confirm) {
    return strcmp(pass, confirm) == 0;
}

int isValidMobile(const char* mobile) {
    if (strlen(mobile) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (!isdigit(mobile[i])) return 0;
    }
    return 1;
}

void processSignupFile(const char* inputFile, const char* outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("Error opening files.\n");
        return;
    }

    char username[30], email[50], password[30], confirm[30], mobile[15];
    int count = 1;

    while (fscanf(in, "%s %s %s %s %s", username, email, password, confirm, mobile) == 5) {
        fprintf(out, "Test Case %d:\n", count++);
        if (!isValidUsername(username)) fprintf(out, "- Invalid Username\n");
        if (!isValidEmail(email)) fprintf(out, "- Invalid Email\n");
        if (!isValidPassword(password)) fprintf(out, "- Invalid Password\n");
        if (!isPasswordMatch(password, confirm)) fprintf(out, "- Passwords Don't Match\n");
        if (!isValidMobile(mobile)) fprintf(out, "- Invalid Mobile Number\n");

        if (isValidUsername(username) && isValidEmail(email) &&
            isValidPassword(password) && isPasswordMatch(password, confirm) &&
            isValidMobile(mobile)) {
            fprintf(out, "-> Signup: PASS ✅\n\n");
        } else {
            fprintf(out, "-> Signup: FAIL ❌\n\n");
        }
    }

    fclose(in);
    fclose(out);
}
int main() {
    processSignupFile("users.txt", "results.txt");
    printf("Signup test completed. Check results.txt\n");
    return 0;
}
