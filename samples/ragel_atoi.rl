#include <stdlib.h>
#include <stdio.h>
#include <string.h>

%%{
    machine atoi;
    write data;
}%%

long long ragel_atoi(char *str)
{
    char *p = str, *pe = str + strlen(str);
    int cs;
    long long val = 0;
    int neg = 0;

    %%{
        action see_neg {
            neg = 1;
        }

        action add_digit {
            val = val * 10 + (fc - '0');
        }

        main := ( '-'@see_neg | '+' )? ( digit @add_digit )+ '\n';

        # Initialize and execute.
        write init;
        write exec;
    }%%

    if ( neg == 1 )
        val = -1 * val;

    if ( cs < atoi_first_final )
        fprintf( stderr, "atoi: there was an error\n" );

    return val;
};

int main(int argc, char *argv[])
{
    char buf[100];

    while (fgets(buf, sizeof(buf), stdin) != 0) {
        long long value = ragel_atoi(buf);
        printf("%lld\n", value);
    }
    return 0;
}
