#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100

typedef struct Song {
    char title[MAX_TITLE_LEN];
    struct Song* link;
} Song;

Song* first = NULL;        
Song* current = NULL;     

Song* createSong(char* title) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    newSong->link = NULL;
    return newSong;
}

void addSong() {
    char title[MAX_TITLE_LEN];
    printf("Enter song title: ");
    scanf(" %[^\n]", title);

    Song* newSong = createSong(title);

    if (first == NULL) {
        first = newSong;
        current = first;
    } else {
        Song* temp = first;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newSong;
    }

    printf("Song added to playlist.\n");
}

void deleteSong() {
    char title[MAX_TITLE_LEN];
    printf("Enter song title to delete: ");
    scanf(" %[^\n]", title);

    if (first == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    Song* temp = first;
    Song* prev = NULL;

    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Song not found.\n");
        return;
    }

    if (prev == NULL) {
        first = first->link;
    } else {
        prev->link = temp->link;
    }

    if (current == temp)
        current = first;

    free(temp);
    printf("Song deleted from playlist.\n");
}

void displayPlaylist() {
    if (first == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    Song* temp = first;
    printf("\nPlaylist:\n");
    while (temp != NULL) {
        if (temp == current)
            printf("-> [%s] (Currently Playing)\n", temp->title);
        else
            printf("-> %s\n", temp->title);
        temp = temp->link;
    }
}

void playNext() {
    if (current == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    if (current->link != NULL) {
        current = current->link;
        printf("Now playing: %s\n", current->title);
    } else {
        printf("You are at the last song.\n");
    }
}

void playPrevious() {
    if (current == NULL || current == first) {
        printf("This is the first song or playlist is empty.\n");
        return;
    }

    Song* temp = first;
    while (temp->link != current)
        temp = temp->link;

    current = temp;
    printf("Now playing: %s\n", current->title);
}

void menu() {
    printf("\n--- Music Player Menu ---\n");
    printf("1. Add Song\n");
    printf("2. Delete Song\n");
    printf("3. Display Playlist\n");
    printf("4. Play Next Song\n");
    printf("5. Play Previous Song\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSong(); break;
            case 2: deleteSong(); break;
            case 3: displayPlaylist(); break;
            case 4: playNext(); break;
            case 5: playPrevious(); break;
            case 6: printf("Exiting Music Player...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
