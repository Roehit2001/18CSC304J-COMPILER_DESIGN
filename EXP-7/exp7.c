#include <stdio.h>
#include <conio.h>
#include <string.h>
struct prodn
{
    char p1[10];
    char p2[10];
};
void main()
{
    char input[20], stack[50], temp[50], ch[2], *t1, *t2, *t;
    int i, j, s1, s2, s, count = 0;
    struct prodn p[10];
    FILE *fp = fopen("input.txt", "r");
    stack[0] = '\0';
    printf("\n Enter the input string\n");
    scanf("%s", &input);
    while (!feof(fp))
    {
        fscanf(fp, "%s\n", temp);
        t1 = strtok(temp, "->");
        t2 = strtok(NULL, "->");
        strcpy(p[count].p1, t1);
        strcpy(p[count].p2, t2);
        count++;
    }
    i = 0;
    while (1)
    {
        if (i < strlen(input))
        {
            ch[0] = input[i];
            ch[1] = '\0';
            i++;
            strcat(stack, ch);
            printf("%s\n", stack);
        }
        for (j = 0; j < count; j++)
        {
            t = strstr(stack, p[j].p2);
            if (t != NULL)
            {
                s1 = strlen(stack);
                s2 = strlen(t);
                s = s1 - s2;
                stack[s] = '\0';
                strcat(stack, p[j].p1);
                printf("%s\n", stack);
                j = -1;
            }
        }
        if (strcmp(stack, "E") == 0 && i == strlen(input))
        {
            printf("\n Accepted");
            break;
        }
        if (i == strlen(input))
        {
            printf("\n Not Accepted");
            break;
        }
    }
    getch();
}
