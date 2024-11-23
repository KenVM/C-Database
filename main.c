#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define User structure
typedef struct {
    int user_id;
    char name[50];
    char email[50];
} User;

// Define Product structure
typedef struct {
    int product_id;
    char name[50];
    float price;
} Product;

// Define Purchase structure
typedef struct {
    int purchase_id;
    int user_id;  // Link to the user who made the purchase
    int product_id;  // Link to the product bought
    int quantity;
} Purchase;