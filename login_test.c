#include <stdio.h>
#include <string.h>

int login(const char* inputFile, const char* username, const char* password) {
    FILE *in = fopen(inputFile, "r");
    if (!in) {
        printf("Error opening file.\n");
        return 0;
    }

    char u[30], email[50], p[30], confirm[30], mobile[15];
    while (fscanf(in, "%s %s %s %s %s", u, email, p, confirm, mobile) == 5) {
        if (strcmp(u, username) == 0 && strcmp(p, password) == 0) {
            fclose(in);
            return 1; // login success
        }
    }

    fclose(in);
    return 0; // login fail
}

int main() {
    char user[30], pass[30];
    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);

    if (login("users.txt", user, pass)) {
        printf("✅ Login Successful!\n");
    } else {
        printf("❌ Login Failed!\n");
    }

    return 0;
}
