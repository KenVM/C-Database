#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a user to the database
void addUser(const char *filename, int user_id, const char *name, const char *email) {
    FILE *file = fopen(filename, "ab");  // Open the file in append binary mode
    if (!file) {
        perror("Failed to open file");
        return;
    }

    typedef struct {
        int user_id;
        char name[50];
        char email[50];
    } User;

    // Create a user record
    User user;
    user.user_id = user_id;
    snprintf(user.name, sizeof(user.name), "%s", name);  // Copy name
    snprintf(user.email, sizeof(user.email), "%s", email);  // Copy email

    // Write the record to the file
    fwrite(&user, sizeof(User), 1, file);
    fclose(file);

    printf("Added User: ID=%d, Name=%s, Email=%s\n", user.user_id, user.name, user.email);
}

int main() {
    const char *filename = "users.db";

    // Hardcoded users
    addUser(filename, 1, "Alice Smith", "alice.smith@example.com");
    addUser(filename, 2, "Bob Johnson", "bob.johnson@example.com");
    addUser(filename, 3, "Charlie Brown", "charlie.brown@example.com");
    addUser(filename, 4, "Diana Taylor", "diana.taylor@example.com");
    addUser(filename, 5, "Eve Anderson", "eve.anderson@example.com");
    addUser(filename, 6, "Frank White", "frank.white@example.com");
    addUser(filename, 7, "Grace Harris", "grace.harris@example.com");
    addUser(filename, 8, "Hank Martin", "hank.martin@example.com");
    addUser(filename, 9, "Ivy Thomas", "ivy.thomas@example.com");
    addUser(filename, 10, "Jack Wilson", "jack.wilson@example.com");

    printf("10 users added successfully to %s.\n", filename);

    return 0;
}