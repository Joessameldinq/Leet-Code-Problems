#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int numberOfSubstrings(const char *s)
{
    int n = strlen(s);
    int counter = 0;

    int prefix_ones[n+1];
    int prefix_zeroes[n+1];
    for(int i = 0 ; i<n+1;i++)
    {
        prefix_ones[i] = 0;
        prefix_zeroes[i] =0;
    }
    for (int i = 0; i < n; i++)
        {
            int one = (s[i] == '1');
            int zero = (s[i] == '0');

            prefix_ones[i+1] = prefix_ones[i] + one;
            prefix_zeroes[i+1] = prefix_zeroes[i] + zero;
        }
    int ones=0,zeroes=0;
    for(int l = 0 ; l < n ;l++)
    {

        for(int r = l+1 ; r < n+1 ;r++)
        {
            ones = prefix_ones[r] - prefix_ones[l];
            zeroes = prefix_zeroes[r]-prefix_zeroes[l];

            if(ones>= (zeroes*zeroes))
                counter++;
            

        }
    }

    return counter;

    
    
}

int main()
{
    char s[] = "0001";
    printf("%d\n", numberOfSubstrings(s));
    return 0;
}
