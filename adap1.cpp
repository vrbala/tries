#include <iostream>
#include <string.h>

int main()
{
    char *str = strdup("membermememeererermemberamemberp");
    char *pat = strdup("ermb");

    std::cout << "str: " << str << " pat: " << pat << std::endl;

    bool lookup[26];
    memset(lookup, false, 26);

    for(int i=0; i<strlen(pat); i++)
        lookup[pat[i]-'a'] = true;
    
    int m=0, n=0;
    // m - first pattern character
    // n - first non pattern character
    // both updated for every iteration
    
    while(true)
    {
        for(int i=m; i<strlen(str); i++)
        {
            if(!lookup[str[i]-'a'])
                m++;
            else
                break;
        }

        // start the stride after first character in pattern
        n=m;
        
        for(int i=n; i<strlen(str); i++)
        {
            if(lookup[str[i]-'a'])
                n++;
            else
                break;
        }

        //std::cout << "m " << m << std::endl;
        //std::cout << "n " << n << std::endl;

        if(n >= strlen(str)) break;

        // swap
        char t = str[m];
        str[m] = str[n];
        str[n] = t;

        m++;
        
        //   std::cout << "after swap: str: " << str << " pat: " << pat << std::endl;
    }

    str[m] = '\0';
    std::cout << "at the end - str: " << str << " pat: " << pat << std::endl;    
}
