
#include<stdio.h>
int main (void)
{
    long long der[ 21 ] = { 0, 0, 1 };
    int i;
    for ( i = 3; i < 21; i++ ){
        der[ i ] = ( i - 1 ) * ( der[ i - 2] + der[ i - 1 ] );
    }
   
    int n;
    while ( scanf( "%d", &n ) != EOF ){
        printf("%lld\n", der[ n ] );
    }
    return 0;
}