#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

queue<int> Next;

int Sc[26][24]={0},Now[3]// y,x,shape
,point=0,Shape[5][5]={0},Shape2[5][5]={0},
Table[7][5][5]{
    { // I--0
        {0,0,0,0,0}
        ,{0,0,0,0,0}
        ,{0,1,1,1,1}
        ,{0,0,0,0,0}
        ,{0,0,0,0,0}
    },{// J--1
        {0,0,0,0,0}
        ,{0,1,0,0,0}
        ,{0,1,1,1,0}
        ,{0,0,0,0,0}
        ,{0,0,0,0,0}
    },{// L--2
        {0,0,0,0,0}
        ,{0,0,0,1,0}
        ,{0,1,1,1,0}
        ,{0,0,0,0,0}
        ,{0,0,0,0,0}
    },{// O--3
        {0,0,0,0,0}
        ,{0,0,1,1,0}
        ,{0,0,1,1,0}
        ,{0,0,0,0,0}
        ,{0,0,0,0,0}
    },{// S--4
        {0,0,0,0,0}
        ,{0,0,1,1,0}
        ,{0,1,1,0,0}
        ,{0,0,0,0,0}
        ,{0,0,0,0,0}
    },{// T--5
        {0,0,0,0,0}
        ,{0,0,1,0,0}
        ,{0,1,1,1,0}
        ,{0,0,0,0,0}
        ,{0,0,0,0,0}
    },{// Z--6
        {0,0,0,0,0}
        ,{0,1,1,0,0}
        ,{0,0,1,1,0}
        ,{0,0,0,0,0}
        ,{0,0,0,0,0}
    }
};

void gotoxy(int xpos, int ypos){
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void clrscr(void){
  gotoxy(0,0);
  for(int i=0;i<10*10;i++)printf(" ");
  gotoxy(0,0);
}

void swaps(){
    int Shape3[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            Shape3[i][j]=Shape[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            Shape[i][j]=Shape2[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            Shape2[i][j]=Shape3[i][j];
        }
    }
}

bool Check(int x,int y){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(Shape[i][j]==1){
                if(Sc[Now[0]+i+x][Now[1]+j+y]==2) return false;
            }
        }
    }
    return true;
}

void Draw(int x,int y,int ax,int ay){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(Shape2[i][j]==1){
                Sc[Now[0]+i][Now[1]+j]=0;
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(Shape[i][j]==1){
                Sc[Now[0]+i+ax][Now[1]+j+ay]=1;
            }
        }
    }
}

void Draw2(){
    for(int i=2;i<23;i++){
        for(int j=2;j<22;j++){
            if(Sc[i][j]==3) Sc[i][j]=0;
        }
    }
    int c=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            while(Check(c,0)) c++;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(Shape[i][j]==1){
                if(Sc[Now[0]+i+c-1][Now[1]+j]==0) Sc[Now[0]+i+c-1][Now[1]+j]=3;
            }
        }
    }
}

bool Setnew(){
    srand(time(NULL));
    int n=Next.front();
    if(n==0){
        Now[0]=0;Now[1]=rand()%15+1;
    }else{
        Now[0]=1;Now[1]=rand()%16+1;
    }
    Now[2]=Next.front();
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            Shape[i][j]=Shape2[i][j]=Table[n][i][j];
        }
    }
    if(Check(0,0)){
        Draw(Now[0],Now[1],0,0);
        Draw2();
    }else{
        Draw(Now[0],Now[1],0,0);
        return false;
    }
    Next.pop();
    Next.push(rand()%7);
    return true;
}

void Print(){
    clrscr();
    for(int i=2;i<23;i++){
        cout<<'|';
        for(int j=2;j<22;j++) if(Sc[i][j]==0) cout<<"  "; else if(Sc[i][j]==3) cout<<"()"; else cout<<"[]";
        cout<<'|'<<endl;
    }
    for(int i=0;i<22*2;i++) cout<<'-';
    cout<<endl<<"point:"<<point<<endl;

    queue<int> Q;
    int h;
    for(int i=0;i<5;i++){
        h=Next.front(); Next.pop(); Q.push(h);
        for(int j=0;j<5;j++) if(Table[h][i][j]) cout<<'*'; else cout<<' '; cout<<"   ";
        h=Next.front(); Next.pop(); Q.push(h);
        for(int j=0;j<5;j++) if(Table[h][i][j]) cout<<'*'; else cout<<' '; cout<<"   ";
        h=Next.front(); Next.pop(); Q.push(h);
        for(int j=0;j<5;j++) if(Table[h][i][j]) cout<<'*'; else cout<<' '; cout<<"   ";
        h=Next.front(); Next.pop(); Q.push(h);
        for(int j=0;j<5;j++) if(Table[h][i][j]) cout<<'*'; else cout<<' '; cout<<"   ";
        h=Next.front(); Next.pop(); Q.push(h);
        for(int j=0;j<5;j++) if(Table[h][i][j]) cout<<'*'; else cout<<' '; cout<<"   ";
        Next.push(Q.front()); Q.pop();
        Next.push(Q.front()); Q.pop();
        Next.push(Q.front()); Q.pop();
        Next.push(Q.front()); Q.pop();
        Next.push(Q.front()); Q.pop();
        cout<<endl;
    }
}

void Delete(){
    bool ok;
    int down=0;
    for(int i=22;i>=2;i--){
        ok=true;
        for(int j=2;j<22;j++) if(Sc[i][j]!=2){ok=false;break;}
        if(down){
            for(int j=2;j<22;j++){Sc[i+down][j]=Sc[i][j];Sc[i][j]=0;}
        }
        if(ok) down++;
    }
    point+=down*10000;
}

bool G(){
    if(Check(1,0)){
        Draw(Now[0],Now[1],1,0);
        Now[0]++;
        return true;
    }
    int t=0;
    while(1){
        if(t++ == 20) break;
        Sleep(10);
        char ch;
        if(_kbhit()){
            ch=_getch();
            if(ch=='a'){
                if(Check(0,-1)){
                    Draw(Now[0],Now[1],0,-1);
                    Now[1]--;
                }
            }
            if(ch=='d'){
                 if(Check(0,1)){
                    Draw(Now[0],Now[1],0,+1);
                    Now[1]++;
                }
            }
        }
    }

    if(Check(1,0)){
        Draw(Now[0],Now[1],1,0);
        Now[0]++;
        return true;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(Shape[i][j]==1){
                Sc[Now[0]+i][Now[1]+j]=2;
            }
        }
    }
    return false;
}

int main(){
    srand(time(NULL));
    for(int i=0;i<5;i++) Next.push(rand()%6);

    for(int i=0;i<24;i++) Sc[i][1]=2;
    for(int i=0;i<24;i++) Sc[i][22]=2;
    for(int i=0;i<24;i++) Sc[23][i]=2;

   char ch;
    int times=0;
    bool gameend=false;
    Setnew();

    while(1){
        for(int i=2;i<22;i++){
            if(Sc[2][i]==2) gameend=true;
        }
        Delete();
        if(gameend) break;
        if(times++ == 2){
            if(!G()){
                if(!Setnew()) gameend=true;
            }
            times=0;
        }
        Sleep(10);
        Print();
        if(_kbhit()){
            ch=_getch();
            switch(ch){
            case 'a':
                if(Check(0,-1)){
                    Draw(Now[0],Now[1],0,-1);
                    Now[1]--;
                    Draw2();
                }
                break;
            case 'd':
                if(Check(0,1)){
                    Draw(Now[0],Now[1],0,+1);
                    Now[1]++;
                    Draw2();
                }
                break;
            case 'l':
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        Shape2[i][j]=Shape[4-j][i];
                    }
                }
                swaps();
                if(!Check(0,0)){
                    swaps();
                    for(int i=0;i<5;i++){
                        for(int j=0;j<5;j++){
                            Shape2[i][j]=Shape[i][j];
                        }
                    }
                }
                Draw(Now[0],Now[1],0,0);
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        Shape2[i][j]=Shape[i][j];
                    }
                }
                Draw2();
                break;
            case 'j':
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        Shape2[i][j]=Shape[j][4-i];
                    }
                }
                swaps();
                if(!Check(0,0)){
                    swaps();
                    for(int i=0;i<5;i++){
                        for(int j=0;j<5;j++){
                            Shape2[i][j]=Shape[i][j];
                        }
                    }
                }
                Draw(Now[0],Now[1],0,0);
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        Shape2[i][j]=Shape[i][j];
                    }
                }
                Draw2();
                break;
            case 'f':
                while(G()){}
                if(!Setnew()) gameend=true;
                break;
            }
            if (ch == 27) break;
        }
    }
    clrscr();
    cout<<"\n\n\n\n\n\n\n     Game is Over!\n\n\n\     Your Score is:"<<point<<"\n\n\n\n\n";
    while(ch=getchar()){
        if(ch==27) break;
    }
}
