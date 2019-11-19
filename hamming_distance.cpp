#include<bits/stdc++.h>

using namespace std;

int hamming(string str[], int n)
{
     int hamming_distance_value = 0;
    for(int i=0; i<n; i++)
    {

        int a=0, t=0, c=0, g=0;

        for(int j=0; j<n; j++)
        {

            if(str[j][i] == 'a')
            {
                a++;
            }
            else if(str[j][i] == 't')
            {
                t++;
            }
            else if(str[j][i] == 'c')
            {
                c++;
            }
            else if(str[j][i] == 'g')
            {
                g++;
            }
        }
        int maximum=0;

        if(a>=c && a>=t && a>=g)
            maximum=a;
        if(t>=a && t>=c && t>=g)
            maximum=t;
        if(c>=a && c>=t && c>=g)
            maximum=c;
        if(g>=c && g>=t && g>=a)
            maximum=g;

        hamming_distance_value += n-maximum;
    }
    printf("Ans : %d\n",hamming_distance_value);
}

int main()
{

    int n;
    cin>>n;
    string str[3];
    for(int i=0; i<n; i++)
    {
        cin>>str[i];
    }

    hamming(str,n);

    return 0;
}
/*
INPUT :
3
atc
agc
cgt

OUTPUT : 3
*/
