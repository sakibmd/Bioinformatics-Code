#include<bits/stdc++.h>
using namespace std;

string str[100];
double count_Matrix[4][100];
double profile_Matrix[4][100];
int randmotif;

int check_All_String_To_Find_Best_Kmer(string str[],double profile_Matrix[][100],int k_mer_length,int Number_of_String,int length_of_str)
{
    string bestMotif[Number_of_String];
    double highest_Probability[Number_of_String];
    for(int i=0; i<Number_of_String; i++)
    {
        double mx = -1;
        for(int j=0; j<=length_of_str-k_mer_length; j++)
        {
            double prob = 1;
            string temp="";
            int col= 0;
            for(int x=j; x<j+k_mer_length; x++)
            {
                if(str[i][x]== 'a')
                {
                    prob = prob * profile_Matrix[0][col];
                    col++;
                }
                if(str[i][x]== 't')
                {
                    prob = prob * profile_Matrix[1][col];
                    col++;
                }
                if(str[i][x]== 'c')
                {
                    prob = prob * profile_Matrix[2][col];
                    length_of_str   col++;
                }
                if(str[i][x]== 'g')
                {
                    prob = prob * profile_Matrix[3][col];
                    col++;
                }
                temp.push_back(str[i][x]);
            }
            if(prob>mx)
            {
                mx=prob;
                bestMotif[i]=temp;
                highest_Probability[i]=mx;

            }
        }
        //printf("%.2f\n",mx);

    }
    cout << endl;
    for(int i=0; i<Number_of_String; i++)
    {
        cout << "Best Motif = " << bestMotif[i] << " and Probability = " << setprecision(3) << highest_Probability[i] << endl;
        //printf("Best Motifs = %s & Probability = %c\n",bestMotif[i],bestMotifValue[i]);
    }

}

void countMatirx(string temp,int Number_of_String,int k_mer_length)
{

    for(int i=0; i<k_mer_length; i++)
    {
        if(temp[i]=='a')
        {
            count_Matrix[0][i]++;
        }
        if(temp[i]=='t')
        {
            count_Matrix[1][i]++;
        }
        if(temp[i]=='c')
        {
            count_Matrix[2][i]++;
        }
        if(temp[i]=='g')
        {
            count_Matrix[3][i]++;
        }
    }
}


void generatrRandomizedMotif(string str[],int k_mer_length,int Number_of_String,int length_of_str)
{

    srand(time(0));
    randmotif = (length_of_str-k_mer_length);
    cout << endl << "Randomly Generated Motifs : " << endl;
    for(int i=0; i<Number_of_String; i++)
    {

        int p=rand()%randmotif;
        //printf("%d\n",p);


        string temp="";
        for(int j=p; j<p+k_mer_length; j++)
        {
            temp.push_back(str[i][j]);
        }
        cout << temp << endl;

        countMatirx(temp, Number_of_String, k_mer_length);
    }


    cout << endl  << "Count Matrix : " << endl;
    for(int i=0; i<4; i++)
    {
        if(i==0)
        {
            cout << "A : ";
        }
        if(i==1)
        {
            cout << "T : ";
        }
        if(i==2)
        {
            cout << "C : ";
        }
        if(i==3)
        {
            cout << "G : ";
        }
        for(int j=0; j<k_mer_length; j++)
        {
            cout << count_Matrix[i][j] << " ";
        }
        cout << endl;
    }


    for(int i=0; i<4; i++)
    {
        for(int j=0; j<k_mer_length; j++)
        {
            profile_Matrix[i][j] = count_Matrix[i][j]/Number_of_String;
        }
    }

    cout << endl << "Profile Matrix : " << endl;
    for(int i=0; i<4; i++)
    {
        if(i==0)
        {
            cout << "A : ";
        }
        if(i==1)
        {
            cout << "T : ";
        }
        if(i==2)
        {
            cout << "C : ";
        }
        if(i==3)
        {
            cout << "G : ";
        }
        for(int j=0; j<k_mer_length; j++)
        {
            printf("%.2f ",profile_Matrix[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    int length_of_str, Number_of_String, k_mer_length;

    cout << "Length of string : " ;
    cin>>length_of_str;
    cout << "How many string : ";
    cin>>Number_of_String;
    cout << "K-mer Length : ";
    cin >> k_mer_length;

    cout << "Enter Your String : " << endl;
    for(int i=0; i<Number_of_String; i++)
    {
        cin>>str[i];
    }

    generatrRandomizedMotif(str,k_mer_length, Number_of_String, length_of_str);
    check_All_String_To_Find_Best_Kmer(str,profile_Matrix,k_mer_length, Number_of_String, length_of_str);

    return 0;
}

/*
12 3 4
atcgaatgattc
aatccaaactcc
tgcgatcagtag

*/

