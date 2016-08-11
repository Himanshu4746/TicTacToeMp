#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class matrix
{
    char mat[3][3];
    public:
    void getdata()
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                mat[i][j]=NULL;
        }
    }
    void clrscr()
    {
        for(int i=0;i<2;i++)
        {
            cout<<"\n\n";
        }
    }
    void putdata()
    {
        clrscr();
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t 0 1 2"<<endl;
        for(int i=0;i<3;i++)
        {
            cout<<"\t\t\t\t\t\t\t\t\t\t _ _ _\n\t\t\t\t\t\t\t\t\t      "<<i <<" |";
            for(int j=0;j<3;j++)
            {
                cout<<mat[i][j]<<"|";
            }
            cout<<"\n";
        }
        cout<<"\t\t\t\t\t\t\t\t\t\t - - -\n";
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }

    void gameplay(char p1,char p2)
    {
        int r1,r2,c1,c2,l=0,c=0;
        while(l!=1){
        k1:
        cout << "player1: enter row & column: " << endl ;
        cin>>r1>>c1;
        while(cin.fail()){
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout<<"Invalid Index.\nEnter Again!\n";
            cin>>r1>>c1;
            }
        if(0<=r1<3 && 0<=c1<3){}
        else
        {
            cout<<"choose a valid index !"<<endl;
            goto k1;
        }
        if(mat[r1][c1]==NULL)
        {
            mat[r1][c1]=p1;
            c++;
        }
        else
        {
            cout<<"invalid location & duplication is not allowed !"<<endl;
            goto k1;
        }
        putdata();
        winner(p1,p2,c);
        k2:
        cout << "player2: enter row & column: " << endl ;
        cin >> r2>> c2;
        if(0<=r2<3 && 0<=c2<3){}
        else
        {
            cout<<"choose a valid index !"<<endl;
            goto k2;
        }
        if(mat[r2][c2]==NULL)
        {
            mat[r2][c2]=p2;
            c++;
        }
        else
        {
            cout<<"invalid location & duplication not allowed !"<<endl;
            goto k2;
        }
        putdata();
        winner(p1,p2,c);
        }
    }
    void winner(char p1,char p2,int c)
    {
        if((mat[0][0]==p1 && mat[0][1]==p1 && mat[0][2]==p1)||
           (mat[1][0]==p1 && mat[1][1]==p1 && mat[1][2]==p1)||
           (mat[2][0]==p1 && mat[2][1]==p1 && mat[2][2]==p1)||
           (mat[0][0]==p1 && mat[1][0]==p1 && mat[2][0]==p1)||
           (mat[0][1]==p1 && mat[1][1]==p1 && mat[2][1]==p1)||
           (mat[0][2]==p1 && mat[1][2]==p1 && mat[2][2]==p1)||
           (mat[0][0]==p1 && mat[1][1]==p1 && mat[2][2]==p1)||
           (mat[2][0]==p1 && mat[1][1]==p1 && mat[0][2]==p1))
        {
            cout<<"player1 is the winner !!"<<endl;
            getch();
            exit(0);
        }
        else if((mat[0][0]==p2 && mat[0][1]==p2 && mat[0][2]==p2)||
           (mat[1][0]==p2 && mat[1][1]==p2 && mat[1][2]==p2)||
           (mat[2][0]==p2 && mat[2][1]==p2 && mat[2][2]==p2)||
           (mat[0][0]==p2 && mat[1][0]==p2 && mat[2][0]==p2)||
           (mat[0][1]==p2 && mat[1][1]==p2 && mat[2][1]==p2)||
           (mat[0][2]==p2 && mat[1][2]==p2 && mat[2][2]==p2)||
           (mat[0][0]==p2 && mat[1][1]==p2 && mat[2][2]==p2)||
           (mat[2][0]==p2 && mat[1][1]==p2 && mat[0][2]==p2))
        {
            cout<<"player2 is the winner !!"<<endl;
            getch();
            exit(0);
        }
        else if(c==9)
        {
            cout<<"game draw!"<<endl;
            getch();
            exit(0);
        }
        else
            cout<<"continue playing !"<<endl;
    }
};
int main()
{
    matrix m;
    m.getdata();
    char p1,p2;
    cout << "welcome !" << endl;
    cout << "choose symbol for player_1 (0 or x) :" << endl;
    cin >> p1;
    if(p1=='x'){}
    else if(p1=='0'){}
    else
    {
        p1='x';
        cout<<"your symbol is: "<<p1<<endl;
    }
    if(p1=='x')
    {
        p2='0';
        cout<<"symbol for player_2 is: "<<p2<<endl;
    }
    else
    {
        p2='x';
        cout<<"symbol for player_2 is: "<<p2<<endl;
    }
    m.putdata();
    m.gameplay(p1,p2);
    return 0;
}
