#include <stdio.h>
#include <string.h>

void main()
{
    char buf[800], *p;
    gets(buf);
    p = strchr(buf, '&');
    *p = '\0';
    printf("%d\n", strlen(buf));
    printf("%d\n", strlen(p+1));
    // // printf(buf);

    // char *ret = strstr(buf, "POST");
    // if(strstr(buf, "POST") != NULL)
    // {
    //     printf("Post method found\n");
    // }
    // char b1[200], b2[200], b3[200];
    // sscanf(buf, "%s %s %s", b1, b2, b3);
    // if(b3 == NULL)
    // {
    //     printf("b3 is NULL\n");
    // }
    // printf("%s\n%s\n%s", b1, b2, b3);
    // int n1 = 1, n2 = 0;
    // int sum = n1 + n2;
    // if (((sum < 0) && (n1 > 0 && n2 > 0)) || ((sum > 0) && (n1 < 0 && n2 < 0)))
    // {
    //     printf("if\n");
    // }
    // else
    // {
    //     printf("else\n");
    // }
}