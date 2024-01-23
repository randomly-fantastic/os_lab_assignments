#include <stdio.h>

int main() {
    int n, n1;
    int a[50];
    int frame[5];

    // Input: Number of elements in the reference string
    printf("Enter the number of elements in the reference string: ");
    scanf("%d", &n);

    // Input: Reference string elements
    printf("Enter the reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Input: Number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &n1);

    // Output: Display the reference string
    printf("The reference string is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");

    int f = 0;
    int flag = 0;
    int ph = 0, pf = 0;

    // Page replacement algorithm
    for (int k = 0; k < n; k++) {
        flag = 0;
        for (int i = 0; i < n1; i++) {
            // Check if the page is already in the frame
            if (a[k] == frame[i]) {
                ph++;  // Page Hit
                flag = 1;
                break;
            }
        }

        // If page is not in the frame, perform page replacement
        if (flag == 0) {
            frame[f] = a[k];
            f = (f + 1) % n1;
            pf++;  // Page Fault
        }
    }

    // Output: Display the number of Page Faults and Page Hits
    printf("Number of Page Faults: %d\n", pf);
    printf("Number of Page Hits: %d\n", ph);

    return 0;
}
