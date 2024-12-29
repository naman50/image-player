#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGES 5

void displayImage(const char *filePath) {
    printf("\nOpening: %s\n", filePath);
    
    #ifdef _WIN32
        // For Windows, use the "start" command
        char command[100];
        sprintf(command, "start %s", filePath);
        system(command);
    #elif __linux__
        // For Linux, use "xdg-open" command
        char command[100];
        sprintf(command, "xdg-open %s", filePath);
        system(command);
    #elif __APPLE__
        // For macOS, use "open" command
        char command[100];
        sprintf(command, "open %s", filePath);
        system(command);
    #else
        printf("Unsupported operating system.\n");
    #endif
}

void displayImages(const char *images[], int count) {
    printf("\nAvailable Images:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, images[i]);
    }
}

int main() {
    const char *images[MAX_IMAGES] = {
        "image1.jpeg",
        "image2.png",
        "image3.bmp",
        "image4.gif",
        "image5.jpeg"
    };

    int imageCount = 5;
    int choice;

    while (1) {
        displayImages(images, imageCount);
        printf("\nEnter the number of the image to view (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting picture viewer. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > imageCount) {
            printf("Invalid choice. Try again.\n");
        } else {
            displayImage(images[choice - 1]);
        }
    }

    return 0;
}
