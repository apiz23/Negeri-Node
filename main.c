#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node
{
    char name[50];
    char lowerName[50];
    struct Node *next;
};

void insertEnd(struct Node **head, const char *name);
void displayAscending(struct Node *head);
void displayDescending(struct Node *head);
void sortList(struct Node **head);
int searchNode(struct Node *head, const char *name);
int deleteNode(struct Node **head, const char *name);
void displayMenu();
void toLowerCase(char *str);
void pauseAndClear();
void displayDescendingHelper(struct Node *head);

int main()
{
    struct Node *head = NULL;

    const char *states[] = {
        "Johore", "Kelantan", "Sabah", "Perak", "Kedah", "Malacca", "Putrajaya",
        "Pahang", "Perlis", "Labuan", "Negeri Sembilan", "Sarawak", "Pulau Pinang",
        "Selangor", "Terengganu", "Kuala Lumpur"};

    for (int i = 0; i < 16; i++)
    {
        insertEnd(&head, states[i]);
    }

    int choice;
    char name[50];

    while (1)
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nCurrent list (unsorted or as is):\n");
            displayAscending(head);
            getchar();
            pauseAndClear();
            break;

        case 2:
            printf("\nList in Descending Order:\n");
            displayDescending(head);
            getchar();
            pauseAndClear();
            break;

        case 3:
            printf("\nList before sorting:\n");
            displayAscending(head);
            sortList(&head);
            printf("\nList after sorting in ascending order:\n");
            displayAscending(head);
            getchar();
            pauseAndClear();
            break;

        case 4:
            printf("\nEnter the name of the state/territory to search: ");
            getchar();
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            toLowerCase(name);

            int position = searchNode(head, name);
            if (position != -1)
            {
                printf("Found at position %d.\n", position + 1);
            }
            else
            {
                printf("'%s' not found in the list.\n", name);
            }
            pauseAndClear();
            break;

        case 5:
            printf("\nEnter the name of the state/territory to delete: ");
            getchar();
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            toLowerCase(name);
            if (deleteNode(&head, name))
            {
                printf("'%s' has been deleted from the list.\n", name);
            }
            else
            {
                printf("'%s' was not found in the list.\n", name);
            }
            pauseAndClear();
            break;

        case 6:
            printf("\nEnter the name of the state/territory to insert: ");
            getchar();
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            insertEnd(&head, name);
            printf("'%s' has been added to the list.\n", name);
            pauseAndClear();
            break;

        case 7:
            printf("\nExiting the program. Goodbye!\n");
            return 0;

        default:
            printf("\nInvalid choice. Please try again.\n");
            pauseAndClear();
        }
    }

    return 0;
}

void insertEnd(struct Node **head, const char *name)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->lowerName, name);
    toLowerCase(newNode->lowerName);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayAscending(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayDescending(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    displayDescendingHelper(head);
    printf("NULL\n");
}

void sortList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *index = NULL;

    if (*head == NULL)
        return;

    while (current != NULL)
    {
        index = current->next;
        while (index != NULL)
        {
            if (strcmp(current->name, index->name) > 0)
            {
                char temp[50];

                strcpy(temp, current->name);
                strcpy(current->name, index->name);
                strcpy(index->name, temp);

                strcpy(temp, current->lowerName);
                strcpy(current->lowerName, index->lowerName);
                strcpy(index->lowerName, temp);
            }
            index = index->next;
        }
        current = current->next;
    }
}

int searchNode(struct Node *head, const char *name)
{
    struct Node *temp = head;
    int position = 0;

    while (temp != NULL)
    {
        if (strcmp(temp->lowerName, name) == 0)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

int deleteNode(struct Node **head, const char *name)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp != NULL && strcmp(temp->lowerName, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return 0;

    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
    return 1;
}

void displayMenu()
{
    printf("+=====================================================================+\n");
    printf("| ____        _          ____  _                   _                  |\n");
    printf("||  _ \\  __ _| |_ __ _  / ___|| |_ _ __ _   _  ___| |_ _   _ _ __ ___ |\n");
    printf("|| | | |/ _` | __/ _` | \\___ \\| __| '__| | | |/ __| __| | | | '__/ _ \\|\n");
    printf("|| |_| | (_| | || (_| |  ___) | |_| |  | |_| | (__| |_| |_| | | |  __/|\n");
    printf("||____/ \\__,_|\\__\\__,_| |____/ \\__|_|   \\__,_|\\___|\\__|\\__,_|_|  \\___||\n");
    printf("| ____            _           _                                       |\n");
    printf("||  _ \\ _ __ ___ (_) ___  ___| |_                                     |\n");
    printf("|| |_) | '__/ _ \\| |/ _ \\/ __| __|                                    |\n");
    printf("||  __/| | | (_) | |  __/ (__| |_                                     |\n");
    printf("||_|   |_|  \\___// |\\___|\\___|\\__|                                    |\n");
    printf("|              |__/                                                   |\n");
    printf("+=====================================================================+\n");
    printf("\n --- Linked List States In Malaysia ---");
    printf("\n\n--- MENU ---\n");
    printf("1. Display List in Unsorted Order\n");
    printf("2. Display List in Descending Order\n");
    printf("3. Sort the List\n");
    printf("4. Search for a State/Territory\n");
    printf("5. Delete a State/Territory\n");
    printf("6. Insert a New State/Territory\n");
    printf("7. Exit\n");
}

void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void pauseAndClear()
{
    printf("\nPress Enter to continue...");
    getchar();
    system("cls");
}

void displayDescendingHelper(struct Node *head)
{
    if (head == NULL)
        return;
    displayDescendingHelper(head->next);
    printf("%s -> ", head->name);
}