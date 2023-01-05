#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;

while (cin >> a){
    cin >>b>>c;
    int array [a*b][b*a]={0};
    int temp [a*b][b*a]={0};
    int aa=a;
    int bb=b;
    int tt=0;

    for (int i = 0; i<a; i++){
        for (int j =0; j< b; j++){
            cin>> array [i][j];

        }
    }

    int crray[c]={0};
    for (int i=0; i<c; i++){
        cin>> crray[i];
    }

    for  (int i =c-1; i>=0; i--){
        if (crray[i]==0){

            for (int j =0; j<aa; j++){
                for (int h=0; h<bb; h++){
                    temp [bb-1-h][j]= array [j][h];
                }
            }


            for (int j =0; j<bb; j++){
                for (int h=0; h<aa; h++){
                   array[j][h]= temp[j][h] ;
                }
            }

            tt=aa;
            aa=bb;
            bb=tt;
        }

        if (crray[i]==1){
            for (int j =0; j<aa; j++){
                for (int h=0; h<bb; h++){
                    temp [aa-1-j][h]= array [j][h];
                }
            }
            for (int j =0; j<aa; j++){
                for (int h=0; h<bb; h++){
                   array[j][h]= temp[j][h] ;
                }
            }
        }


    }
    cout<< aa<<" "<<bb<<endl;
     for (int j =0; j<aa; j++){
                for (int h=0; h<bb; h++){
                        if (h==bb-1 ) cout<<array[j][h];
                  else  cout<<array[j][h]<<" ";
                }
                cout<< endl;
     }

}

}
