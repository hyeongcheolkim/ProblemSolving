//s2는 입력받은 문자열을 가르키지 않는다. 입력받은 문자열은 s2에 저장된다.
//s2는 포인터로 선언되었지만, 포인터의 기능을 잃었다.
//그렇기에 &s2가 포인터로 기능한다.
//&s2해야만 출력되는 이유

#include <stdio.h>

int main()
{
    char *s1 = "hello";
    char *s2="";
    scanf("%s", &s2);

    printf("%s", s1);

    printf("%s", &s2);
    printf("%c", s2);

    return 0;
}