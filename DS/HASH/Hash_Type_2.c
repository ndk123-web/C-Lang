#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 1000

int sum(char num[]) {
    int len, ft = 0, lt = 0, i;
    len = strlen(num);
    for (i = 0; i < 3; i++) {
        ft = ft * 10 + (num[i] - '0');
    }
    for (i = len - 3; i < len; i++) {
        lt = lt * 10 + (num[i] - '0');
    }
    int s = ft + lt;
    return s;
}

int main() {
    int hash[size] = {0};
    char number[20];
    int loc, key, ch, i;

    printf("Enter Fold size: ");
    int k;
    scanf("%d", &k);

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter Data: ");
                scanf("%d", &key);
                sprintf(number, "%d", key); // Convert integer to string
                loc = sum(number);
                i = 1;
                while (hash[loc] != 0) {
                    loc = (loc + 1) % size; // Linear probing
                    i++;
                    if (i == size) {
                        printf("Hash Full\n");
                        break;
                    }
                }
                if (i < size) {
                    hash[loc] = key;
                    printf("Inserted at %d\n", loc);
                }
                break;
                
            case 2:
                printf("Enter element to be searched: ");
                int searchKey;
                scanf("%d", &searchKey);
                sprintf(number, "%d", searchKey); // Convert integer to string
                loc = sum(number);
                i = 1;
                while (hash[loc] != searchKey) {
                    loc = (loc + 1) % size; // Linear probing
                    i++;
                    if (hash[loc] == 0 || i == size) {
                        printf("Not found\n");
                        break;
                    }
                }
                if (hash[loc] == searchKey) {
                    printf("Found at %d\n", loc);
                }
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
