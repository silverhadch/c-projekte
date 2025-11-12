#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define FILE_NAME "data.txt"

void hash_password(const char *password, char *outputBuffer) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)password, strlen(password), hash);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[SHA256_DIGEST_LENGTH * 2] = '\0';
}

void add_user() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    FILE *file = fopen(FILE_NAME, "a");  // append mode

    if (file == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    printf("Enter username: ");
    scanf("%49s", username);
    printf("Enter password: ");
    scanf("%49s", password);

    char hashed[SHA256_DIGEST_LENGTH * 2 + 1];
    hash_password(password, hashed);


    fprintf(file, "%s %s\n", username, hashed);  // username + password on one line
    fclose(file);

    printf("User '%s' added successfully!\n", username);
}

void list_users() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    int count = 0;

    printf("\n=== Registered Users ===\n");

    while (fscanf(file, "%49s %49s", username, password) == 2) {
        printf("User %d: %s (Password: %s)\n", ++count, username, password);
    }

    if (count == 0)
        printf("No users found.\n");

    fclose(file);
}

void login() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char stored_user[MAX_USERNAME];
    char stored_hash[SHA256_DIGEST_LENGTH * 2 + 1];
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    printf("Enter username: ");
    scanf("%49s", username);

    int user_found = 0;
    char correct_hash[SHA256_DIGEST_LENGTH * 2 + 1];

    // Look for the user in the file
    while (fscanf(file, "%49s %64s", stored_user, stored_hash) == 2) {
        if (strcmp(username, stored_user) == 0) {
            user_found = 1;
            strcpy(correct_hash, stored_hash);
            break;
        }
    }

    fclose(file);

    if (!user_found) {
        printf("User '%s' not found!\n", username);
        return;
    }

    // Give up to 3 tries
    for (int tries = 1; tries <= 3; tries++) {
        printf("Enter password: ");
        scanf("%49s", password);

        char hashed[SHA256_DIGEST_LENGTH * 2 + 1];
        hash_password(password, hashed);

        if (strcmp(hashed, correct_hash) == 0) {
            printf("Login successful! Welcome, %s.\n", username);
            return;
        } else {
            printf("Incorrect password (%d/3)\n", tries);
        }
    }

    printf("Too many failed attempts! Access denied.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Add user\n");
        printf("2. List users\n");
        printf("3. Login\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                list_users();
                break;
            case 3:
                login();
                exit(0);
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
