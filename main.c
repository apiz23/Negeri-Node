#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node
{
    char name[50];
    struct Node *next;
};

void insertEnd(struct Node **head, const char *name);
void displayAscending(struct Node *head);
void displayDescending(struct Node *head);
void sortList(struct Node **head);
int searchNode(struct Node *head, const char *name);
void deleteNode(struct Node **head, const char *name);
void displayMenu();
void toLowerCase(char *str);
void pauseAndClear();

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
            printf("\nList in Ascending Order:\n");
            displayAscending(head);
            pauseAndClear();
            break;

        case 2:
            printf("\nList in Descending Order:\n");
            displayDescending(head);
            pauseAndClear();
            break;

        case 3:
            sortList(&head);
            printf("\nThe list has been sorted in ascending order.\n");
            pauseAndClear();
            break;

        case 4:
            printf("\nEnter the name of the state/territory to search: ");
            scanf("%s", name);
            toLowerCase(name);
            int position = searchNode(head, name);
            if (position != -1)
            {
                printf("'%s' found at position %d.\n", name, position + 1);
            }
            else
            {
                printf("'%s' not found in the list.\n", name);
            }
            pauseAndClear();
            break;

        case 5:
            printf("\nEnter the name of the state/territory to delete: ");
            scanf("%s", name);
            deleteNode(&head, name);
            printf("'%s' has been deleted from the list.\n", name);
            pauseAndClear();
            break;

        case 6:
            printf("\nEnter the name of the state/territory to insert: ");
            scanf("%s", name);
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
    displayDescending(head->next);
    printf("%s -> ", head->name);
}

void sortList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *index = NULL;
    char temp[50];

    if (*head == NULL)
        return;

    while (current != NULL)
    {
        index = current->next;
        while (index != NULL)
        {
            if (strcmp(current->name, index->name) > 0)
            {
                strcpy(temp, current->name);
                strcpy(current->name, index->name);
                strcpy(index->name, temp);
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
    char lowerCaseName[50];

    while (temp != NULL)
    {
        strcpy(lowerCaseName, temp->name);
        toLowerCase(lowerCaseName);
        if (strcmp(lowerCaseName, name) == 0)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

void deleteNode(struct Node **head, const char *name)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
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
    printf("1. Display List in Ascending Order\n");
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
    getchar();
    system("cls");
}
