#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

// Define arrays for the queue
char songNames[MAX_SONGS][100];
int songDurations[MAX_SONGS];
int front = -1;
int rear = -1;

// Define arrays for the undo stack
int undoDurations[MAX_SONGS];
int undoTop = -1;

// Function to check if the queue is empty
int isQueueEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isQueueFull() {
    return (rear + 1) % MAX_SONGS == front;
}

// Function to enqueue a song into the queue
void enqueue(char name[], int duration) {
    if (!isQueueFull()) {
        if (isQueueEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SONGS;
        }
        strcpy(songNames[rear], name);
        songDurations[rear] = duration;
    } else {
        printf("Queue is full. Cannot add more songs.\n");
    }
}

// Function to dequeue a song from the queue
void dequeue() {
    if (!isQueueEmpty()) {
        printf("Playing: %s\n", songNames[front]);
        while (songDurations[front] > 0) {
            printf("Time left: %d seconds\n", songDurations[front]);
            songDurations[front]--;
        }
        printf("%s has finished playing.\n", songNames[front]);
        front = (front + 1) % MAX_SONGS;
    } else {
        printf("Queue is empty. Cannot play any songs.\n");
    }
}

// Function to check if the undo stack is empty
int isUndoStackEmpty() {
    return undoTop == -1;
}

// Function to check if the undo stack is full
int isUndoStackFull() {
    return undoTop == MAX_SONGS - 1;
}

// Function to push a song onto the undo stack
void pushUndo(int duration) {
    if (!isUndoStackFull()) {
        undoTop++;
        undoDurations[undoTop] = duration;
    }
}

// Function to pop a song from the undo stack
void popUndo() {
    if (!isUndoStackEmpty()) {
        undoTop--;
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add Song to Playlist\n");
        printf("2. Play Next Song\n");
        printf("3. Undo Last Song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isQueueFull()) {
                    char name[100];
                    int duration;
                    printf("Enter the name of the song: ");
                    scanf(" %[^\n]s", name);
                    printf("Enter the duration of the song (in seconds): ");
                    scanf("%d", &duration);
                    enqueue(name, duration);
                    printf("%s has been added to the playlist.\n", name);
                } else {
                    printf("Playlist is full. Cannot add more songs.\n");
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if (!isUndoStackEmpty()) {
                    int lastDuration = undoDurations[undoTop];
                    pushUndo(songDurations[rear]);
                    rear = (rear - 1 + MAX_SONGS) % MAX_SONGS;
                    printf("Last song has been undone.\n");
                } else {
                    printf("Nothing to undo.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
