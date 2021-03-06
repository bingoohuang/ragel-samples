
#line 1 "ragel_atoi.rl"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#line 9 "ragel_atoi.c"
static const int atoi_start = 1;
static const int atoi_first_final = 4;
static const int atoi_error = 0;

static const int atoi_en_main = 1;


#line 8 "ragel_atoi.rl"


long long ragel_atoi(char *str)
{
    char *p = str, *pe = str + strlen(str);
    int cs;
    long long val = 0;
    int neg = 0;

    
#line 28 "ragel_atoi.c"
	{
	cs = atoi_start;
	}

#line 33 "ragel_atoi.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 43: goto st2;
		case 45: goto tr2;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr3;
	goto st0;
st0:
cs = 0;
	goto _out;
tr2:
#line 18 "ragel_atoi.rl"
	{
            neg = 1;
        }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 60 "ragel_atoi.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr3;
	goto st0;
tr3:
#line 22 "ragel_atoi.rl"
	{
            val = val * 10 + ((*p) - '0');
        }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 74 "ragel_atoi.c"
	if ( (*p) == 10 )
		goto st4;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr3;
	goto st0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	goto st0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 31 "ragel_atoi.rl"


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
