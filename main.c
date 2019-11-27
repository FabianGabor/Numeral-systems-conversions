#include <stdio.h>

typedef struct node {
    char bit;
    struct node *next;
} binary;

void push (binary **head, int bit)
{
    binary *new_head = NULL;
    new_head = malloc(sizeof(binary));

    new_head->next = *head;
    if (bit > 9)
        new_head->bit = (bit - 10) + 'A';
    else
        new_head->bit = bit + '0';

    //new_head->bit = bit + '0';
    *head = new_head;
}
void print_list (binary *head)
{
    binary *current = head;
    while (current != NULL)
    {
        printf("%c", current->bit);
        current = current->next;
    }
    printf("\n\n");
}

void *dectobin (int dec, binary *bin)
{
    int i = 0;
    int debug[10] = {0};

    bin->bit = (dec % 2) + '0';
    bin->next = NULL;
    dec /= 2;

    while (dec >=1)
    {
        push(&bin, dec % 2 );
        dec /= 2;
        i++;
    }
    return bin;
}

void *dectobaseN (int dec, int base, binary *bin)
{
    int i = 0;

    int debug = dec % base;

    if (dec % base > 9)
        bin->bit = ((dec % base)-10) + 'A';
    else
        bin->bit = (dec % base) + '0';
    bin->next = NULL;
    dec /= base;

    while (dec >=1)
    {
        push(&bin, dec % base );
        dec /= base;
        i++;
    }
    return bin;
}

int main()
{
    binary *head = NULL;
    head = malloc(sizeof(binary));
    if (head == NULL) return 1;

    int x = 122919815;
    int base;

    //head->bit = 1;
    //head->next = NULL;

    head = dectobin(x, head);
    printf("Decimal %d in base %d:\n",x,2);
    print_list(head);

    base = 2;
    head = dectobaseN(x, base, head);
    printf("Decimal %d in base %d:\n",x,base);
    print_list(head);

    base = 16;
    head = dectobaseN(x, base, head);
    printf("Decimal %d in base %d:\n",x,base);
    print_list(head);

    base = 24;
    head = dectobaseN(x, base, head);
    printf("Decimal %d in base %d:\n",x,base);
    print_list(head);

    return 0;
}
