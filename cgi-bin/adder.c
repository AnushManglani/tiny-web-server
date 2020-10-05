/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "csapp.h"
int dec(int n1, int n2);

int main(void) {
    char *buf, *p;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
    int n1=0, n2=0;

    /* Extract the two arguments */
    if ((buf = getenv("QUERY_STRING")) != NULL) {
        p = strchr(buf, '&');
        *p = '\0';

        
        strncpy(arg1, buf, MAXLINE);
        strncpy(arg2, p+1, MAXLINE);

        // there should be check here for the integer overflow
        n1 = atoi(arg1);
        n2 = atoi(arg2);

        if(dec(n1, n2))
        {
            printf("Integer Overflow detected!!");
            return;
        }
        
    }

    /* Make the response body */
    sprintf(content, "Welcome to add.com: ");
    sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
    sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", 
	    content, n1, n2, n1 + n2);
    sprintf(content, "%sThanks for visiting!\r\n", content);
  
    /* Generate the HTTP response */
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);
    exit(0);
}
/* $end adder */
int dec(int n1, int n2)
{
    int sum = n1 + n2;
    // printf("%d %d \n", n1, n2);
    if (((sum < 0) && (n1 > 0 && n2 > 0)) || ((sum > 0) && (n1 < 0 && n2 < 0)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}