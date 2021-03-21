//baekjoon 1436 ps

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    //set value
    int n;
    cin >> n;
    char str[10];

    //algorithm
    for (int i = 1;; i++)
    {
        static int counter = 0;
        static bool flag = false;
        flag = false;
        sprintf(str, "%d", i); // itoa int i >> string str(char type)

        for (int j = 0; j < strlen(str); j++)
            if (str[j] == '6')
                if (j + 1 < strlen(str) && str[j + 1] == '6')
                    if (j + 2 < strlen(str) && str[j + 2] == '6')
                        flag = true;

        if (flag == true)
            counter++;
        if (counter == n)
        {
            printf("%s", str);
            break;
        }
    }

    return 0;
}