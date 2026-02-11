#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct PAGE {
    char url[100];
    struct PAGE *prev;
    struct PAGE *next;
};

struct PAGE *current = NULL;

// Visit new page
void visitPage(char url[]) {

    struct PAGE *newNode =
        (struct PAGE*)malloc(sizeof(struct PAGE));

    strcpy(newNode->url, url);
    newNode->next = NULL;

    if (current == NULL) {
        newNode->prev = NULL;
        current = newNode;
        return;
    }

    // Remove forward history
    struct PAGE *temp = current->next;
    while (temp != NULL) {
        struct PAGE *del = temp;
        temp = temp->next;
        free(del);
    }

    current->next = newNode;
    newNode->prev = current;
    current = newNode;
}

// Back operation
void goBack() {

    if (current == NULL || current->prev == NULL) {
        printf("No previous page\n");
        return;
    }

    current = current->prev;
    printf("Moved Back to: %s\n", current->url);
}

// Forward operation
void goForward() {

    if (current == NULL || current->next == NULL) {
        printf("No forward page\n");
        return;
    }

    current = current->next;
    printf("Moved Forward to: %s\n", current->url);
}

// Show current page
void showCurrent() {

    if (current == NULL) {
        printf("No page open\n");
        return;
    }

    printf("Current Page: %s\n", current->url);
}

// Main
int main() {

    int choice;
    char url[100];

    while (1) {

        printf("\n--- Browser Menu ---\n");
        printf("1. Visit Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Show Current Page\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visitPage(url);
                break;

            case 2:
                goBack();
                break;

            case 3:
                goForward();
                break;

            case 4:
                showCurrent();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
