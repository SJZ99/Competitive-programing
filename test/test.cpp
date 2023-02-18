# include <bits/stdc++.h>
using namespace std;

int arr[8][8];
int record [8];


bool check(int r, int c){
    int k=0;
    for(int i = 0; i<8; i++){
       if ( arr[r][i]!=0 || arr[i][c]!=0) k++;

    }

    for (int i=1; r+i<8 && c+i<8; i++ ){
       if(arr[r+i][c+i]!=0) k++;
    }

    for (int i=1; r-i>0 && c-i>0; i++ ){
        if (arr[r-i][c-i]!=0) k++;
    }

    for (int i=1; r-i>0 && c+i<8; i++ ){
        if (arr[r-i][c+i]!=0) k++;
    }

    for (int i=1; r+i<8 && c-i>0; i++ ){
        if (arr[r+i][c-i]!=0) k++;
    }
    if (k!=0) return false;
    else return true;
}

int number(int r, int c, int countt){
    if (check(r, c)){
        if (c>7){
            c=0;
        }

        for(int i = 0; i<8; i++){
            arr[r][i]=0;
            arr[i][c]=0;
        }

        for (int i=1; r+i<8 && c+i<8; i++ ){
            arr[r+i][c+i]=0;
        }

        for (int i=1; r-i>0 && c-i>0; i++ ){
            arr[r-i][c-i]=0;
        }

        for (int i=1; r-i>0 && c+i<8; i++ ){
            arr[r-i][c+i]=0;
        }

        for (int i=1; r+i<8 && c-i>0; i++ ){
            arr[r+i][c-i]=0;
        }

        arr[r][c]=1;
        for (int j=0; j<8; j++){
            if (arr[j][c]=!0 )  {
                record [c]=j;

                if (countt ==7){
                    for (int i=0; i<8; i++){
                        cout<<record[i]<<" ";
                    }
                }
                else number(c+1, j, countt++);
            }

        }
    }

}

int main(){
    int a;
    cin>> a;
    for (int h=0; h<a; h++){
        for (int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                arr[i][j]=-1;
            }
        }
    }
    int r, c;
    cin>>r >> c;
    record[c]=r;
    number(r,c, 0);
}