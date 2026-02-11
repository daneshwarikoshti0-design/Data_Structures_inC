#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct SONG {
    char name[50];
    struct SONG *next;
};

struct SONG *last = NULL;
struct SONG *current = NULL;

// Add song
void addSong(char name[]) {

    struct SONG *newNode =
        (struct SONG*)malloc(sizeof(struct SONG));

    strcpy(newNode->name, name);

    if (last == NULL) {
        last = newNode;
        last->next = last;
        current = last;
        return;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

// Delete song
void deleteSong(char name[]) {

    if (last == NULL) {
        printf("Playlist Empty\n");
        return;
    }

    struct SONG *temp = last->next;
    struct SONG *prev = last;

    do {
        if (strcmp(temp->name, name) == 0) {

            if (temp == last && temp->next == last) {
                last = NULL;
            }
            else {
                prev->next = temp->next;
                if (temp == last)
                    last = prev;
            }

            free(temp);
            printf("Song Deleted\n");
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != last->next);

    printf("Song Not Found\n");
}

// Play next song
void playNext() {

    if (current == NULL) {
        printf("Playlist Empty\n");
        return;
    }

    current = current->next;
    printf("Now Playing: %s\n", current->name);
}

// Display playlist
void display() {

    if (last == NULL) {
        printf("Playlist Empty\n");
        return;
    }

    struct SONG *temp = last->next;

    printf("Playlist:\n");

    do {
        printf("%s -> ", temp->name);
        temp = temp->next;
    } while (temp != last->next);

    printf("(Back to Start)\n");
}

// Main
int main() {

    int choice;
    char name[50];

    while (1) {

        printf("\n--- Music Playlist Menu ---\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Play Next Song\n");
        printf("4. Display Playlist\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter Song Name: ");
                scanf("%s", name);
                addSong(name);
                break;

            case 2:
                printf("Enter Song Name to Delete: ");
                scanf("%s", name);
                deleteSong(name);
                break;

            case 3:
                playNext();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
