#include<bits/stdc++.h>
using namespace std;
int initial[100],finalOutput[100],n;
int count_step=0;

void print(){
    for(int i=0; i<n; i++){
        printf("%d ",initial[i]);
    }
    cout << endl;
}
void rvereseArray(int start, int endpoint){
    while(start<=endpoint){
        if(start==endpoint){
            initial[start] = -initial[start];
            break;
        }
        int temp = initial[start];
        //temp = -1*temp;
        initial[start] = initial[endpoint];
        initial[start] = -1*initial[start];
        initial[endpoint] = temp;
        initial[endpoint] = -1*initial[endpoint];
        start++;
        endpoint--;

    }
}

int main(){

    int limit;
    printf("Enter Length : ");
    scanf("%d",&n);
    printf("Enter Initial : ");
    for(int i=0; i<n; i++){
        scanf("%d",&initial[i]);
    }
    printf("Enter Final Output : ");
    for(int i=0; i<n; i++){
        scanf("%d",&finalOutput[i]);
    }


    for(int i=0; i<n; i++)
    {
        if(abs(initial[i])!=finalOutput[i])
        {
            count_step++;
            for(int j=i+1; j<n; j++)
            {
                if(abs(initial[j]) == finalOutput[i])
                {
                    limit = j;
                    break;
                }
            }
            rvereseArray(i, limit);
            print();
            if(initial[i]<0)
            {
                count_step++;
                initial[i] = -initial[i];
                print();
            }
        }
        else if(initial[i]<0)
        {
            count_step++;
            initial[i] = -initial[i];
            print();
        }

    }
    printf("\nTotal Step = %d",count_step);
}

//5 -6 1 3 -2 -4
//1 2 3 4 5 6
