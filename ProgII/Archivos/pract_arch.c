#include<stdio.h>
#include<string.h>

int main()
{
    int a, b, c;
    //printf("char = %c\n", x);
    printf("Enter the first value: \n");
    scanf("%d", &a);

    printf("Enter the second value: \n");
    scanf("%d", &b);

    c = a + b;
    printf("%d + %d = %d\n", a, b, c);
    return 0;
}


//
//// ex3
//int main()
//{
//    const int MAX = 10;
//    char line[MAX];
//
//    int n = getline(line, MAX);
//    printf("get %d characters: %s.\n", n, line);
//    return 0;
//}
//
//int getline(char* line, int max)
//{
//    if(fgets(line, max, stdin) == NULL) {return 0; }
//    else
//        return strlen(line);
//}
