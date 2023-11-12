#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

char a;
char Harta[40][40];
int n, m, level;
int nr_chei_lvl[5];
int nr_bombe_lvl[5], e_deja_o_bomba;
int win, dead;

struct pozitie
{
    int x, y;
}tu, bomba;

void Prezentare_Joc()
{
    cout<<"   --Box Game--"<<endl<<endl;
    cout<<"    Welcome to my game!"<<endl;
    cout<<"    The goal of each level is to get to the '?' mark"<<endl;
    cout<<"    -you are the player 'T'"<<endl;
    cout<<"    -'#' are walls you can't go through"<<endl;
    cout<<"    -'@' are boxes you can push"<<endl;
    cout<<"    -'O' are platforms that open doors if they are pressed by boxes"<<endl;
    cout<<"    -'m' are gates that can be opened if its associated platforms are all pressed at the same time"<<endl;
    cout<<"    -'M' are doors that can be opened if you hold a key"<<endl;
    cout<<"     Use w,a,s,d to move"<<endl;
    cout<<"     Good luck!"<<endl;
    cout<<"     Press 's' to start"<<endl;
    char s;
    s=getch();
    while (s!='s')
        s=getch();
    system("CLS");
    cout<<endl<<"     Select the level to begin with!";
    char lvl;
    lvl=getch();
    level=lvl-'0';
    system("CLS");
}

void Config_Harta()
{
    dead=0;
    for (int i=1;i<=5;i++)
    {
        nr_chei_lvl[i]=0;
    }
    if (level==1)
    {
    tu.x=tu.y=2;
    n=m=10;
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        Harta[i][j]=' ';
    int i;
    for (i=1;i<=10;i++)
        Harta[1][i]=Harta[n][i]=Harta[i][1]=Harta[i][n]='#';
    //Prima incapere
    Harta[3][4]='B';
    for (i=2;i<=5;i++)
        Harta[i][5]=Harta[5][i]='#';
    Harta[5][3]='m';
    Harta[4][4]='O';
    Harta[3][3]='@';
    Harta[2][2]='T';
    //A doua incapere
    for (i=5;i<=9;i++)
        Harta[i][6]='#';
    Harta[7][4]='#';
    Harta[8][6]='m';
    Harta[6][5]=Harta[9][5]='O';
    Harta[7][3]=Harta[8][4]='@';
    //A treia incapere
    Harta[3][6]=Harta[3][7]=Harta[6][9]=Harta[7][9]='#';
    Harta[5][8]=Harta[4][9]=Harta[7][8]=Harta[8][8]='@';
    Harta[4][6]=Harta[2][9]=Harta[3][9]=Harta[9][8]='O';
    Harta[2][7]='m';
    Harta[2][6]='?';
    }
    if (level==2)
    {
        tu.x=tu.y=2;
        n=10;
        m=14;
        for (int i=1;i<=10;i++)
            Harta[i][1]=Harta[i][14]='#';
        for (int j=1;j<=14;j++)
            Harta[1][j]=Harta[10][j]='#';
        for (int i=2;i<10;i++)
            for (int j=2;j<14;j++)
            Harta[i][j]=' ';

        for (int i=2;i<=5;i++)
            Harta[6][i]='#';
        Harta[5][5]=Harta[4][5]=Harta[3][6]='#';
        Harta[2][6]='m';
        Harta[4][3]=Harta[4][4]='@';
        Harta[3][3]=Harta[3][5]='O';
        Harta[2][2]='T';
        Harta[3][7]='C';
        Harta[7][3]='@';
        Harta[7][5]='M';
        Harta[8][5]='#';
        for (int j=2;j<=5;j++)
            Harta[9][j]='#';
        Harta[2][9]=Harta[2][10]='O';
        Harta[5][9]='#';
        Harta[6][8]=Harta[7][8]=Harta[8][8]='#';
        Harta[5][10]='M';
        Harta[7][10]=Harta[7][11]='@';
        for (int j=8;j<=13;j++)
            Harta[9][j]='#';
        Harta[8][13]=Harta[7][13]=Harta[6][13]='#';
        Harta[6][12]=Harta[6][11]='#';
        Harta[5][11]=Harta[4][11]='#';
        Harta[4][12]=Harta[3][12]=Harta[3][13]='#';
        Harta[2][13]='?';
        Harta[2][12]='m';
    }
    if (level==3)
    {
        tu.x=2;
        tu.y=11;
        n=9;
        m=22;
        for (int i=1;i<=m;i++)
            Harta[1][i]=Harta[n][i]='#';
        for (int i=1;i<=n;i++)
            Harta[i][1]=Harta[i][m]='#';
        for (int i=2;i<n;i++)
            for (int j=2;j<m;j++)
                Harta[i][j]=' ';
        Harta[3][2]=Harta[7][2]=Harta[4][21]=Harta[7][10]=Harta[7][12]=Harta[8][10]=Harta[8][12]='#';
        for (int i=13;i<=18;i++)
            Harta[3][i]='#';
        for (int i=2;i<=21;i++)
            Harta[5][i]='#';
        Harta[2][2]=Harta[4][2]=Harta[5][3]=Harta[5][11]=Harta[7][9]='O';
        Harta[3][20]=Harta[4][3]=Harta[6][17]=Harta[7][3]=Harta[7][4]='@';
        Harta[7][11]='m';
        Harta[8][11]='?';
        Harta[2][11]='T';
    }
}

bool Game_On()
{
    if (a=='i')
        return 0;
    return 1;
}

void Afisare_Harta()
{
    cout<<"      Level "<<level<<"   "<<endl<<endl;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            cout<<Harta[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl<<"   "<<nr_chei_lvl[level]<<" Keys     "<<nr_bombe_lvl[level]<<" Bombs";
    cout<<endl<<endl<<"To leave the game press 'i' and to restart press 'r'";
}

bool e_zid_sau_poarta(int i, int j)
{
    if (Harta[i][j]=='#' || Harta[i][j]=='m')
        return 1;
    return 0;
}

bool e_cutie(int i, int j)
{
    if (Harta[i][j]=='@')
        return 1;
    return 0;
}

bool e_bomba(int i ,int j)
{
    if (Harta[i][j]=='B')
        return 1;
    return 0;
}

bool e_cheie(int i ,int j)
{
    if (Harta[i][j]=='C')
        return 1;
    return 0;
}

bool e_zid_dupa_cutie(int i, int j, int k, int l)
{
    if (Harta[i][j]=='@' && (Harta[k][l]=='#' || Harta[k][l]=='m' || Harta[k][l]=='@'))
        return 1;
    return 0;
}

bool castig(int i, int j)
{
    if (Harta[i][j]=='?')
        return 1;
    return 0;
}

void Verif_Tasta()
{
    if (a=='w')
    {
        if (Harta[tu.x-1][tu.y]=='M')
        {
           if (nr_chei_lvl[level]>0)
           {
               Harta[tu.x-1][tu.y]='T';
            Harta[tu.x][tu.y]=' ';
            tu.x--;
            nr_chei_lvl[level]--;
           }
        }
        else
        if (!e_zid_sau_poarta(tu.x-1, tu.y) && !e_zid_dupa_cutie(tu.x-1, tu.y, tu.x-2, tu.y))
        {
            if (e_cutie(tu.x-1, tu.y))
                Harta[tu.x-2][tu.y]='@';
            else if (e_bomba(tu.x-1, tu.y))
                nr_bombe_lvl[level]++;
            else if (e_cheie(tu.x-1, tu.y))
                nr_chei_lvl[level]++;
            else if (castig(tu.x-1, tu.y))
                {
                    win=1;
                    return;
                }
            Harta[tu.x-1][tu.y]='T';
            Harta[tu.x][tu.y]=' ';
            tu.x--;
        }
    }
    if (a=='d')
    {
        if (Harta[tu.x][tu.y+1]=='M')
        {
           if (nr_chei_lvl[level]>0)
           {
               Harta[tu.x][tu.y+1]='T';
            Harta[tu.x][tu.y]=' ';
            tu.y++;
            nr_chei_lvl[level]--;
           }
        }
        else
        if (!e_zid_sau_poarta(tu.x, tu.y+1) && !e_zid_dupa_cutie(tu.x, tu.y+1, tu.x, tu.y+2))
        {
            if (e_cutie(tu.x, tu.y+1))
                Harta[tu.x][tu.y+2]='@';
            else if (e_bomba(tu.x, tu.y+1))
                nr_bombe_lvl[level]++;
            else if (e_cheie(tu.x, tu.y+1))
                nr_chei_lvl[level]++;
            else if (castig(tu.x, tu.y+1))
                {
                    win=1;
                    return;
                }
            Harta[tu.x][tu.y+1]='T';
            Harta[tu.x][tu.y]=' ';
            tu.y++;
        }
    }
    if (a=='s')
    {
        if (Harta[tu.x+1][tu.y]=='M')
        {
           if (nr_chei_lvl[level]>0)
           {
               Harta[tu.x+1][tu.y]='T';
            Harta[tu.x][tu.y]=' ';
            tu.x++;
            nr_chei_lvl[level]--;
           }
        }
        else
        if (!e_zid_sau_poarta(tu.x+1, tu.y) && !e_zid_dupa_cutie(tu.x+1, tu.y, tu.x+2, tu.y))
        {
            if (e_cutie(tu.x+1, tu.y))
                Harta[tu.x+2][tu.y]='@';
            else if (e_bomba(tu.x+1, tu.y))
                nr_bombe_lvl[level]++;
            else if (e_cheie(tu.x+1, tu.y))
                nr_chei_lvl[level]++;
            else if (castig(tu.x+1, tu.y))
                {
                    win=1;
                    return;
                }
            Harta[tu.x+1][tu.y]='T';
            Harta[tu.x][tu.y]=' ';
            tu.x++;
        }
    }
    if (a=='a')
    {
        if (Harta[tu.x][tu.y-1]=='M')
        {
           if (nr_chei_lvl[level]>0)
           {
               Harta[tu.x][tu.y-1]='T';
            Harta[tu.x][tu.y]=' ';
            tu.y--;
            nr_chei_lvl[level]--;
           }
        }
        else
        if (!e_zid_sau_poarta(tu.x, tu.y-1) && !e_zid_dupa_cutie(tu.x, tu.y-1, tu.x, tu.y-2))
        {
            if (e_cutie(tu.x, tu.y-1))
                Harta[tu.x][tu.y-2]='@';
            else if (e_bomba(tu.x, tu.y-1))
                nr_bombe_lvl[level]++;
            else if (e_cheie(tu.x, tu.y-1))
                nr_chei_lvl[level]++;
            else if (castig(tu.x, tu.y-1))
                {
                    win=1;
                    return;
                }
            Harta[tu.x][tu.y-1]='T';
            Harta[tu.x][tu.y]=' ';
            tu.y--;
        }
    }
    if (a=='e' && nr_bombe_lvl[level]>0 && !e_deja_o_bomba)
    {
        e_deja_o_bomba=1;
        nr_bombe_lvl[level]--;
        Harta[tu.x][tu.y]='*';
        bomba.x=tu.x;
        bomba.y=tu.y;
    }
    if (a=='f' && e_deja_o_bomba)
    {
        e_deja_o_bomba=0;
        for (int i=bomba.x-1;i<=bomba.x+1;i++)
            for (int j=bomba.y-1;j<=bomba.y+1;j++)
            {
                if (Harta[i][j]=='T')
                {
                    dead=1;
                    return;
                }
                if (i>1 && j>1 && i<n && j<m)
                Harta[i][j]=' ';
            }
    }
    if (e_deja_o_bomba)
        Harta[bomba.x][bomba.y]='*';
}

void RE_Placa(int i, int j)
{
    if (Harta[i][j]==' ')
        Harta[i][j]='O';
}


void RE()
{
    if (level==1)
    {
    RE_Placa(4, 4);
    RE_Placa(6, 5);
    RE_Placa(9 ,5);
    RE_Placa(4, 6);
    RE_Placa(2, 9);
    RE_Placa(3, 9);
    RE_Placa(9, 8);
    }
    if (level==2)
    {
        RE_Placa(3,3);
        RE_Placa(3,5);
        RE_Placa(2,9);
        RE_Placa(2,10);
    }
    if (level==3)
    {
        RE_Placa(2,2);
        RE_Placa(4,2);
        RE_Placa(5,3);
        RE_Placa(5,11);
        RE_Placa(7,9);
    }
}

void Consecinte()
{
    if (level==1)
    {
    if (Harta[4][4]=='@')
    {
        if (Harta[5][3]!='T' && Harta[5][3]!='@')
        Harta[5][3]=' ';
    }
    else
        Harta[5][3]='m';
    //
    if (Harta[6][5]=='@' && Harta[9][5]=='@')
    {
        if (Harta[8][6]!='T' && Harta[8][6]!='@')
        Harta[8][6]=' ';
    }
    else
        Harta[8][6]='m';
    //
    if (Harta[4][6]=='@' && Harta[2][9]=='@' && Harta[3][9]=='@' && Harta[9][8]=='@')
    {
        if (Harta[2][7]!='T' && Harta[2][7]!='@')
        Harta[2][7]=' ';
    }
    else
        Harta[2][7]='m';
    }

    if (level==2)
    {
        if (Harta[3][3]=='@' && Harta[3][5]=='@')
        {
            if (Harta[2][6]!='T' && Harta[2][6]!='@')
            Harta[2][6]=' ';
        }
        else
            Harta[2][6]='m';
        //
        if (Harta[2][9]=='@' && Harta[2][10]=='@')
        {
            if (Harta[2][12]!='T' && Harta[2][12]!='@')
            Harta[2][12]=' ';
        }
        else
            Harta[2][12]='m';
    }
    if (level==3)
    {
        if (Harta[2][2]=='@' && Harta[4][2]=='@' && Harta[5][3]=='@' && Harta[5][11]=='@' && Harta[7][9]=='@')
        {
            if (Harta[7][11]!='T' && Harta[7][11]!='@')
                Harta[7][11]=' ';
            else
                Harta[7][11]='m';
        }
    }
}


int main()
{
    Prezentare_Joc();
    LOOP:
    Config_Harta();
    while (Game_On())
    {
        Afisare_Harta();
        a = getch();
        if (a=='r')
        {
            system("CLS");
            goto LOOP;
        }
        Verif_Tasta();
        if (dead)
        {

            system("CLS");
            goto LOOP;
        }
        RE();
        Consecinte();
        if (win)
        {
            win=0;
            level++;
            system("CLS");
            if (level<=3)
            goto LOOP;
            else
            {
            cout<<endl<<"GG! You won!!"<<endl;
            return 0;
            }
        }
        system("CLS");
    }
    cout<<endl<<"Goodbye!"<<endl;
    return 0;
}
