#include<bits/stdc++.h>
using namespace std;

char available_charachers[] = {'a', 't', 'c', 'g'};

string str[100];
string best_motif[100];
int mn = 100;


int hamming_distence(string str1[], int string_length,int how_many_str)
{
    int hamming_distance_value = 0;
    for(int i=0; i<string_length; i++)
    {

        int a=0, t=0, c=0, g=0;

        for(int j=0; j<how_many_str; j++)
        {


            if(str1[j][i] == 'a')
            {
                a++;
            }
            else if(str1[j][i] == 't')
            {
                t++;
            }
            else if(str1[j][i] == 'c')
            {
                c++;
            }
            else if(str1[j][i] == 'g')
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

        hamming_distance_value += how_many_str-maximum;
    }
    return hamming_distance_value;
}

void kmer_check(string ptn,int k_mer_length,int how_many_str,int string_length)
{
    string motif[how_many_str];
    for(int i=0; i<how_many_str; i++)
    {
        int mx = 0;
        for(int j=0; j<=string_length-k_mer_length; j++)
        {
            int cont = 0;
            string temp="";
            for(int x=j; x<j+k_mer_length; x++)
            {
                if(str[i][x]== ptn[x-j])
                {
                    cont++;
                }
                temp.push_back(str[i][x]);
            }
            if(cont>mx)
            {
                mx=cont;
                motif[i]=temp;
            }

        }

    }

    int hamming = hamming_distence(motif, string_length, how_many_str);
    if(hamming < mn )
    {
        mn = hamming;

        for(int i=0; i<how_many_str; i++)
        {
            best_motif[i]=motif[i];
        }
    }
}

void Pattern_Generate( string gen, int length, int k_mer_length, int how_many_str, int string_length )
{
    if(length == k_mer_length )
    {
        kmer_check(gen, k_mer_length, how_many_str, string_length);
        return ;
    }
    string temp;

    temp=gen;
    temp.push_back('a');
    Pattern_Generate(temp, length+1, k_mer_length,how_many_str, string_length);

    temp=gen;
    temp.push_back('t');
    Pattern_Generate(temp, length+1, k_mer_length, how_many_str, string_length);

    temp=gen;
    temp.push_back('c');
    Pattern_Generate(temp, length+1, k_mer_length, how_many_str, string_length );

    temp=gen;
    temp.push_back('g');
    Pattern_Generate(temp, length+1, k_mer_length, how_many_str, string_length);
}

int main()
{
    int string_length, Number_of_String, Length_of_K_mer;


    cout<<"How many string you input : ";
    cin>>Number_of_String;

    cout<<"Length of your String : ";
    cin>>string_length;

    cout<<"K-mer Length : ";
    cin>>Length_of_K_mer;

    cout<<"\n\nEnter Your Strings\n";

    for(int i=0; i<Number_of_String; i++)
    {
        cin>>str[i];
    }
    cout<<"\n";

    Pattern_Generate("", 0, Length_of_K_mer, Number_of_String, string_length);


    for(int i=0; i<Number_of_String; i++)
    {
        cout<<best_motif[i]<<endl;
    }
    return 0;
}



/*
3 8 3
atchatcg
aatccaag
gattcagt
*/


