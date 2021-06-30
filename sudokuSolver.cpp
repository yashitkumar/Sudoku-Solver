#include<iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;


HANDLE hCon;

enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, 
  TEAL, RED, PINK, YELLOW, WHITE };

void SetColor(Color c){
        if(hCon == NULL)
                hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hCon, c);
}


  int a[9][9]={0},sol[9][9]={0},o[9][9]={0};                
   




 int easy[5][9][9]={
                { {3, 0, 6, 5, 0, 8, 4, 0, 0}, {5, 2, 0, 0, 0, 0, 0, 0, 0}, {0, 8, 7, 0, 0, 0, 0, 3, 1}, {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                  {9, 0, 0, 8, 6, 3, 0, 0, 5}, {0, 5, 0, 0, 9, 0, 6, 0, 0}, {1, 3, 0, 0, 0, 0, 2, 5, 0}, {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                  {0, 0, 5, 2, 0, 6, 3, 0, 0} } ,

                 {{0, 7, 0, 0, 0, 0, 0, 0, 9}, {5, 1, 0, 4, 2, 0, 6, 0, 0}, {0, 8, 0, 3, 0, 0, 7, 0, 0}, {0, 0, 8, 0, 0, 1, 3, 7, 0}, 
                  {0, 2, 3, 0, 8, 0, 0, 4, 0}, {4, 0, 0, 9, 0, 0, 1, 0, 0}, {9, 6, 2, 8, 0, 0, 0, 3, 0}, {0, 0, 0, 0, 1, 0, 4, 0, 0}, 
                  {7, 0, 0, 2, 0, 3, 0, 9, 6} }  , 

                   {{1, 0, 6, 0, 0, 2, 3, 0, 0}, {0, 5, 0, 0, 0, 6, 0, 9, 1}, {0, 0, 9, 5, 0, 1, 4, 6, 2}, {0, 3, 7, 9, 0, 5, 0, 0, 0}, 
                  {5, 8, 1, 0, 2, 7, 9, 0, 0}, {0, 0, 0, 4, 0, 8, 1, 5, 7}, {0, 0, 0, 2, 6, 0, 5, 4, 0}, {0, 0, 4, 1, 5, 0, 6, 0, 9}, 
                  {9, 0, 0, 8, 7, 4, 2, 1, 0} } ,  

                  {{0, 8, 0, 7, 0, 1, 0, 3, 0}, {4, 0, 9, 0, 0, 0, 0, 0, 0}, {0, 5, 0, 0, 6, 0, 4, 1, 8}, {7, 0, 0, 0, 0, 9, 0, 0, 0}, 
                  {8, 0, 0, 6, 1, 0, 5, 0, 0}, {0, 3, 5, 0, 0, 0, 0, 2, 9}, {0, 6, 0, 4, 0, 7, 0, 9, 0}, {1, 0, 0, 0, 0, 8, 0, 0, 4}, 
                  {0, 2, 0, 0, 5, 0, 0, 7, 0} } ,  

                  {{2, 0, 5, 0, 0, 9, 0, 0, 4}, {0, 0, 0, 0, 0, 0, 3, 0, 7}, {7, 0, 0, 8, 5, 6, 0, 1, 0}, {4, 5, 0, 7, 0, 0, 0, 0, 0}, 
                  {0, 0, 9, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 2, 0, 8, 5}, {0, 2, 0, 4, 1, 8, 0, 0, 6}, {6, 0, 8, 0, 0, 0, 0, 0, 0}, 
                  {1, 0, 0, 2, 0, 0, 7, 0, 8} }
 
 };                 

int med[5][9][9]={ {{0, 0, 6, 0, 9, 0, 2, 0, 0}, {0, 0, 0, 7, 0, 2, 0, 0, 0}, {0, 9, 0, 5, 0, 8, 0, 7, 0}, {9, 0, 0, 0, 3, 0, 0, 0, 6}, 
                  {7, 5, 0, 0, 0, 0, 0, 1, 9}, {1, 0, 0, 0, 4, 0, 0, 0, 5}, {0, 1, 0, 3, 0, 9, 0, 8, 0}, {0, 0, 0, 2, 0, 1, 0, 0, 0}, 
                  {0, 0, 9, 0, 8, 0, 1, 0, 0} } ,

                  {{6, 3, 0, 0, 0, 0, 0, 0, 0}, {0, 2, 0, 0, 0, 8, 9, 0, 0}, {4, 8, 0, 6, 2, 0, 0, 0, 0}, {2, 6, 0, 0, 0, 0, 0, 0, 0}, 
                  {0, 1, 4, 0, 0, 0, 7, 6, 0}, {0, 0, 0, 0, 0, 0, 0, 4, 9}, {0, 0, 0, 0, 3, 1, 0, 7, 8}, {0, 0, 1, 7, 0, 0, 0, 3, 0}, 
                  {0, 0, 0, 0, 0, 0, 0, 9, 5} } ,

                  {{0, 8, 0, 0, 0, 0, 0, 3, 2}, {4, 0, 0, 0, 0, 6, 5, 0, 0}, {0, 0, 0, 0, 3, 0, 1, 0, 0}, {0, 0, 3, 6, 0, 5, 4, 0, 0}, 
                  {1, 0, 0, 0, 0, 0, 0, 0, 6}, {0, 0, 4, 8, 0, 7, 9, 0, 0}, {0, 0, 9, 0, 5, 0, 0, 0, 0}, {0, 0, 8, 7, 0, 0, 0, 0, 9}, 
                  {6, 2, 0, 0, 0, 0, 0, 8, 0} } ,


                 {{0, 0, 0, 0, 0, 0, 2, 0, 0}, {0, 8, 0, 0, 0, 7, 0, 9, 0}, {6, 0, 2, 0, 0, 0, 5, 0, 0}, {0, 7, 0, 0, 6, 0, 0, 0, 0}, 
                  {0, 0, 0, 9, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 2, 0, 4, 0}, {0, 0, 5, 0, 0, 0, 6, 0, 3}, {0, 9, 0, 4, 0, 0, 0, 7, 0}, 
                  {0, 0, 6, 0, 0, 0, 0, 0, 0} } ,

                  {{0, 0, 0, 0, 0, 1, 2, 3, 0}, {1, 2, 3, 0, 0, 8, 0, 4, 0}, {8, 0, 4, 0, 0, 7, 6, 5, 0}, {7, 6, 5, 0, 0, 0, 0, 0, 0}, 
                  {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 2, 3}, {0, 1, 2, 3, 0, 0, 8, 0, 4}, {0, 8, 0, 4, 0, 0, 7, 6, 5}, 
                  {0, 7, 6, 5, 0, 0, 0, 0, 0} }

};

int hard[5][9][9]={{{0, 0, 0, 8, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 4, 3}, {5, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 7, 0, 8, 0, 0}, 
                  {0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 2, 0, 0, 3, 0, 0, 0, 0}, {6, 0, 0, 0, 0, 0, 0, 7, 5}, {0, 0, 3, 4, 0, 0, 0, 0, 0}, 
                  {0, 0, 0, 2, 0, 0, 6, 0, 0} } ,

                  {{8, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 3, 6, 0, 0, 0, 0, 0}, {0, 7, 0, 0, 9, 0, 2, 0, 0}, {0, 5, 0, 0, 0, 7, 0, 0, 0}, 
                  {0, 0, 0, 0, 4, 5, 7, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 3, 0}, {0, 0, 1, 0, 0, 0, 0, 6, 8}, {0, 0, 8, 5, 0, 0, 0, 1, 0}, 
                  {0, 9, 0, 0, 0, 0, 4, 0, 0} } ,

                  {{4, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 9, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 7, 8, 5}, {0, 0, 7, 0, 4, 8, 0, 5, 0}, 
                  {0, 0, 1, 3, 0, 0, 0, 0, 0}, {0, 0, 6, 0, 7, 0, 0, 0, 0}, {8, 6, 0, 0, 0, 0, 9, 0, 3}, {7, 0, 0, 0, 0, 5, 0, 6, 2}, 
                  {0, 0, 3, 7, 0, 0, 0, 0, 0} } ,

                   {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 3, 0, 8, 5}, {0, 0, 1, 0, 2, 0, 0, 0, 0}, {0, 0, 0, 5, 0, 7, 0, 0, 0}, 
                  {0, 0, 4, 0, 0, 0, 1, 0, 0}, {0, 9, 0, 0, 0, 0, 0, 0, 0}, {5, 0, 0, 0, 0, 0, 0, 7, 3}, {0, 0, 2, 0, 1, 0, 0, 0, 0}, 
                  {0, 0, 0, 0, 4, 0, 0, 0, 9} } ,
   
                  {{0, 0, 0, 7, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 4, 3, 0, 2, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 6}, 
                  {0, 0, 0, 5, 0, 9, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 4, 1, 8}, {0, 0, 0, 0, 8, 1, 0, 0, 0}, {0, 0, 2, 0, 0, 0, 0, 5, 0}, 
                  {0, 4, 0, 0, 0, 0, 3, 0, 0} }


};






void main_menu();
void play_game_menu();
void instructions();
void Game(int n);
void continue_to_game(int n);
void rc_unlock(int n,int m);
void Intro();
void random(int n);
void grid(int n);
void erase(int n);
void enter_puzzle();
void user_grid();
void user_puzzle_menu();
void user_puzzle();
bool isNumber(string s);


bool canplace(int board[][9],int n,int row,int col,int curnum){

for(int i=0;i<n;i++){

if(board[row][i]==curnum) return false;

if (board[i][col]==curnum) return false;
}

int rootn=sqrt(n);

int rowstart=(row/rootn)*rootn;

int colstart=(col/rootn)*rootn;

for(int i=rowstart;i<rowstart+rootn;i++)  

for(int j=colstart;j<colstart+rootn;j++)
  
  if(board[i][j]==curnum) return false;
 return true;

}

bool sudoku(int board[][9],int n,int row,int col){
if(row==n) return true;
if(col==n) return sudoku(board,n,row+1,0);
if(board[row][col]!=0) return sudoku(board,n,row,col+1);

for(int curnum=1;curnum<=n;curnum++){

if(canplace(board,n,row,col,curnum)){

board[row][col]=curnum;
if(sudoku(board,n,row,col+1))
  return true;
board[row][col]=0;


}


}

return false;

}







void instructions(){

system("cls");

system("COLOR B0");
cout<<"\n\n\t\t\t\t\t\t\tINSTRUCTIONS";

cout<<"\n\n\n\n\t--> There is only one valid solution to each Sudoku puzzle."; 
cout<<"\n\n\n\n\t--> The only way the puzzle can be considered solved correctly is when all 81 boxes contain numbers and other Sudoku rules have been followed ";

cout<<"\n\n\n\n\t--> 1. When you start a game of Sudoku, some blocks will be pre-filled for you. You cannot change these numbers in the course of the game.";

cout<<"\n\n\n\n\t--> 2. Each column must contain all of the numbers 1 through 9 and no two numbers in the same column of a Sudoku puzzle can be the same.";

cout<<"\n\n\n\n\t--> 3. Each row must contain all of the numbers 1 through 9 and no two numbers in the same row of a Sudoku puzzle can be the same.";

cout<<"\n\n\n\n\t--> 4. Each block must contain all of the numbers 1 through 9 and no two numbers in the same block of a Sudoku puzzle can be the same.";

cout<<"\n\n\n\n\t\t\t\t YOU CAN USE FEATURES OF THIS GAME ";
cout<<"\n\n\n\n\t\t\t\t\t 1. HINT ";
cout<<"\n\n\n\n\t\t\t\t\t 2. COMPLETE SOLUTION ";
cout<<"\n\n\n\n\t\t\t\t\t 3. ROW UNLOCK ";
cout<<"\n\n\n\n\t\t\t\t\t 4. COLUMN UNLOCK ";
cout<<"\n\n\n\n\t\t\t\t\t 5. ERASE THE MOVE ";
cout<<"\n\n\n\n\t\t\t\t\t 6. MANUALLY ENTER PUZZLE TO SOLVE";


getch();
main_menu();

}
void user_erase(){

system("cls");

user_grid();

int row,col;
r:
cout<<"\n\n ENTER ROW TO ERASE (1-9) : "; cin>>row;

if(row<1 or row>9) {
 cout<<"INVALID ROW! ENTER AGAIN !";
 goto r; 
}
c:
cout<<"\n ENTER COLUMN TO ERASE (1-9) : "; cin>>col;

if(col<1 or col>9){
 cout<<"INVALID COLUMN! ENTER AGAIN !";
 
 goto c; 

}



 o[row-1][col-1]= a[row-1][col-1]=0;

cout<<"YOUR BOX IS NOW ERASED!!";
Sleep(1000);

enter_puzzle();





}


void user_grid(){
system("cls");
system("COLOR A0");
SetColor(WHITE);

char c[9][9];

cout<<"\t\t\t\t\t*********************************************************\n";

for(int i=0;i<9;i++){

for(int j=0;j<9;j++){
 if(a[i][j]==0) c[i][j]=' ';
 else c[i][j]=a[i][j]+'0'; 
}




SetColor(WHITE);
cout<<"\t\t\t\t\t*     *     *     ||     *     *     ||     *     *     *\n";
SetColor(YELLOW);     
cout<<"\t\t\t\t\t*  "<<c[i][0]<<"  *  "<<c[i][1]<<"  *  "<<c[i][2]<<"  ||  "<<c[i][3]<<"  *  "<<c[i][4]<<"  *  "<<c[i][5]<<"  ||  "<<c[i][6]<<"  *  "<<c[i][7]<<"  *  "<<c[i][8]<<"  *\n";     
SetColor(WHITE);
cout<<"\t\t\t\t\t*     *     *     ||     *     *     ||     *     *     *\n";     
if(i==2){
  cout<<"\t\t\t\t\t---------------------------------------------------------\t\t\t ENTER E TO ERASE THE MOVE\n";
  cout<<"\t\t\t\t\t---------------------------------------------------------\t\t\t\t\n";
}

 else if(i==3)
  cout<<"\t\t\t\t\t*********************************************************\t\t\t ENTER S TO STOP ENTERING!!!!!\n";
else 
if(i==5){
 cout<<"\t\t\t\t\t---------------------------------------------------------\t\t\t ENTER A TO EXIT!!!!!\n";
 cout<<"\t\t\t\t\t---------------------------------------------------------\t\t\t\n";
}
   
   else cout<<"\t\t\t\t\t*********************************************************\n";

}


}

void enter_puzzle(){
string inp1,inp2,inp3; 
int row,col,number;


while(1){
s:

system("cls");

user_grid();
r:
cout<<"\n\nENTER ROW (1-9) : "; cin>>inp1;

 if(inp1=="s" or inp1=="S"){
 Game(4);
}

else  if(inp1=="e" or inp1=="E"){
user_erase();
}
else  if(inp1=="a" or inp1=="A"){
 main_menu();
}

else if(isNumber(inp1)){

row=stoi(inp1);


if(row<1 or row>9) {
 cout<<"INVALID ROW! ENTER AGAIN !";
 goto r; 
}


c:
cout<<"\nENTER COLUMN (1-9) : "; cin>>inp2;
col=stoi(inp2);
if(col<1 or col>9){
 cout<<"INVALID COLUMN! ENTER AGAIN !";
 
 goto c; 

}



n:

cout<<"\n\n ENTER  NUMBER (1-9) : "; cin>>inp3;
number=stoi(inp3);
if(number<1 or number>9){
  cout<<"INVALID NUMBER! ENTER AGAIN !";
 
 goto n; 
}


 o[row-1][col-1] = sol[row-1][col-1]= a[row-1][col-1]=number;



}
else{
  cout<<"INVALID ROW! ENTER AGAIN !";
 goto r; 
}

}



}

void enter_oneline(){

system("cls");
system("COLOR A0");

cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tENTER A TO EXIT!!!";

cin.ignore();
t:


string p;
cout<<"\n\n\n\t\t\t\tENTER PUZZLE HERE :  ";
getline(cin,p);

if(p=="a" or p=="A")
user_puzzle_menu();    

if(p.size()!=81){
 cout<<"\n\n\t\t\t\tWRONG PUZZLE ENTER AGAIN!!!";
goto t;   
}

for(int i=0;i<81;i++){
 if(!isNumber(p)){
   cout<<"\n\n\t\t\t\tWRONG PUZZLE ENTER AGAIN!!!";
    goto t;
 } 
}

int index=0;

for(int i=0;i<9;i++){
for(int j=0;j<9;j++){
o[i][j]=a[i][j] =sol[i][j]=(int)(p[index] -'0');
index++;    
}

}
Game(4);

}

void user_puzzle_menu(){
top:
system("cls");
system("COLOR F4");




cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t ###############::PUZZLE !!!::###################\n";
        cout<<"\t\t\t\t\t ================================================\n\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t1. ENTER PUZZLE BY ROW COLUMN \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t2. ENTER PUZZLE IN ONE LINE \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t3. BACK TO MAIN MENU \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
         
        
 
 
         cout<<"\n\t\t\t\t\tEnter your choice:-> ";


int ch;  cin>>ch;
switch(ch){
case 1:  user_puzzle();
         break;

case 2:  enter_oneline(); 
break;

case 3: main_menu();
        break;


default : cout<<"\n\t\t\t\t\t\t\t\tENTER VALID CHOICE  " ;
          Sleep(1000);
           goto top;   
}





}


void user_puzzle(){
system("cls");


for(int i=0 ; i<9;i++){
   for(int j=0;j<9;j++)
    o[i][j] = a[i][j]=0; 
}

enter_puzzle();


}




void main_menu(){

top:
system("cls");
system("COLOR F1");




cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t ###############::SUDOKU SOLVER !!!::############\n";
        cout<<"\t\t\t\t\t ================================================\n\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t1. PLAY THE GAME \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t2. ENTER PUZZLE TO SOLVE \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t3. INSTRUCTIONS \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
         cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t4. EXIT \t\t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";
        
 
 
         cout<<"\n\t\t\t\t\tEnter your choice:-> ";


int ch;  cin>>ch;
switch(ch){
case 1:  play_game_menu();
         break;

case 2:  user_puzzle_menu(); 
break;

case 3: instructions();
        break;

case 4: cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
        system("cls");
        exit(0);

default : cout<<"\n\t\t\t\t\t\t\t\tENTER VALID CHOICE  " ;
          Sleep(1000);
           goto top;   
}


}



void grid(int n){

system("cls");
if(n==1)
 system("COLOR E2");    

if(n==2)
  system("COLOR C4");
 if(n==3)
  system("COLOR 91");
   if(n==4)
  system("COLOR B3");

SetColor(WHITE);

char c[9][9];

cout<<"\t\t\t\t\t*********************************************************\n";

for(int i=0;i<9;i++){

for(int j=0;j<9;j++){
 if(a[i][j]==0) c[i][j]=' ';
 else c[i][j]=a[i][j]+'0'; 
}




SetColor(WHITE);
cout<<"\t\t\t\t\t*     *     *     ||     *     *     ||     *     *     *\n";
SetColor(YELLOW);     
cout<<"\t\t\t\t\t*  "<<c[i][0]<<"  *  "<<c[i][1]<<"  *  "<<c[i][2]<<"  ||  "<<c[i][3]<<"  *  "<<c[i][4]<<"  *  "<<c[i][5]<<"  ||  "<<c[i][6]<<"  *  "<<c[i][7]<<"  *  "<<c[i][8]<<"  *\n";     
SetColor(WHITE);
cout<<"\t\t\t\t\t*     *     *     ||     *     *     ||     *     *     *\n";     

if(i==1)
  cout<<"\t\t\t\t\t*********************************************************\t\t\t ENTER O TO UNLOCK ROW!!!!!\n";

else if(i==2){
  cout<<"\t\t\t\t\t---------------------------------------------------------\t\t\t\t\n";
  cout<<"\t\t\t\t\t---------------------------------------------------------\t\t\t ENTER P TO UNLOCK COLUMN\n";
}

else if(i==3)
  cout<<"\t\t\t\t\t*********************************************************\t\t\t ENTER H TO GET HINT!!!!!\n";

else if(i==4) 
 cout<<"\t\t\t\t\t*********************************************************\t\t\t ENTER C TO GET COMPLETE SOLUTION!!!!!\n";
else 
if(i==5){
 cout<<"\t\t\t\t\t---------------------------------------------------------\t\t\t ENTER E TO ERASE THE MOVE!!!!!\n";
 cout<<"\t\t\t\t\t---------------------------------------------------------\t\t\t\n";
}
else if(i==6)
 cout<<"\t\t\t\t\t*********************************************************\t\t\t ENTER A TO EXIT!!!!!\n";

  else cout<<"\t\t\t\t\t*********************************************************\n";



}


}

void Hint(int n){

system("cls");

grid(n);


int row,col;
r:
cout<<"\n\n ENTER ROW TO UNLOCK (1-9) : "; cin>>row;

if(row<1 or row>9) {
 cout<<"INVALID ROW! ENTER AGAIN !";
 goto r; 
}
c:
cout<<"\n ENTER COLUMN TO UNLOCK (1-9) : "; cin>>col;

if(col<1 or col>9){
 cout<<"INVALID COLUMN! ENTER AGAIN !";
 
 goto c; 

}

cout<<"YOUR BOX IS NOW UNLOCKED!!";
Sleep(1000);

a[row-1][col-1]=sol[row-1][col-1];

continue_to_game(n);
  

}

void rc_unlock(int n,int m){
system("cls");

grid(m);


int row,col;

if(n==1){
r:
cout<<"\n\n ENTER ROW TO UNLOCK (1-9) : "; cin>>row;

if(row<1 or row>9) {
 cout<<"INVALID ROW! ENTER AGAIN !";
 goto r; 
}

for(int i=0;i<9;i++){
   a[row-1][i]=sol[row-1][i]; 
}

cout<<"YOUR ROW IS NOW UNLOCKED!!";
}
if(n==2){
c:

cout<<"\n ENTER COLUMN TO UNLOCK (1-9) : "; cin>>col;

if(col<1 or col>9){
 cout<<"INVALID COLUMN! ENTER AGAIN !";
 
 goto c; 

}
for(int i=0;i<9;i++){
   a[i][col-1]=sol[i][col-1]; 
}


cout<<"YOUR COLUMN IS NOW UNLOCKED!!";
}

Sleep(1000);


continue_to_game(m);
  

   

}

void complete(int n){

for(int i=0;i<9;i++){
  for(int j=0;j<9;j++){
   a[i][j]=sol[i][j]; 
  }
}
system("cls");
if(n==1)
 system("COLOR E2");    

if(n==2)
  system("COLOR C4");
 if(n==3)
  system("COLOR 91");
   if(n==4)
  system("COLOR B3");

SetColor(WHITE);

char c[9][9];

cout<<"\t\t\t\t\t********************************************************\n";

for(int i=0;i<9;i++){

for(int j=0;j<9;j++){
 if(a[i][j]==0) c[i][j]=' ';
 else c[i][j]=a[i][j]+'0'; 
}




SetColor(WHITE);
cout<<"\t\t\t\t\t*     *     *     ||     *     *     ||     *     *    *\n";
SetColor(YELLOW);     
cout<<"\t\t\t\t\t*  "<<c[i][0]<<"  *  "<<c[i][1]<<"  *  "<<c[i][2]<<"  ||  "<<c[i][3]<<"  *  "<<c[i][4]<<"  *  "<<c[i][5]<<"  ||  "<<c[i][6]<<"  *  "<<c[i][7]<<"  *  "<<c[i][8]<<" *\n";     
SetColor(WHITE);
cout<<"\t\t\t\t\t*     *     *     ||     *     *     ||     *     *    *\n";     
if(i==2){
  cout<<"\t\t\t\t\t--------------------------------------------------------\t\t\t\t\n";
  cout<<"\t\t\t\t\t--------------------------------------------------------\t\t\t\t\n";
}

else if(i==5){
 cout<<"\t\t\t\t\t--------------------------------------------------------\t\t\t\n";
 cout<<"\t\t\t\t\t--------------------------------------------------------\t\t\t\n";
}

  else cout<<"\t\t\t\t\t********************************************************\n";



}



cout<<"\n\n\t\t\tPUZZLE IS SOLVED !! PRESS ANY KEY TO GO BACK ";

getch();
cout<<"\n\n\n\n";

main_menu();

}

void erase(int n){

system("cls");

grid(n);

int row,col;
r:
cout<<"\n\n ENTER ROW TO ERASE (1-9) : "; cin>>row;

if(row<1 or row>9) {
 cout<<"INVALID ROW! ENTER AGAIN !";
 goto r; 
}
c:
cout<<"\n ENTER COLUMN TO ERASE (1-9) : "; cin>>col;

if(col<1 or col>9){
 cout<<"INVALID COLUMN! ENTER AGAIN !";
 
 goto c; 

}

if(o[row-1][col-1]!=0){
 cout<<"\n SORRY QUESTION CANNOT BE ERASED!!! " ;
 Sleep(1000);
 continue_to_game(n);
} 

a[row-1][col-1]=0;

cout<<"YOUR BOX IS NOW ERASED!!";
Sleep(1000);

continue_to_game(n);



}

void random(int n){

srand(time(NULL));
int no=rand()%5;



for(int i=0;i<9;i++){
for(int j=0;j<9;j++){

if(n==1) 
 sol[i][j]= a[i][j]=o[i][j]=easy[no][i][j];
else if(n==2)
 sol[i][j]= a[i][j]=o[i][j]=med[no][i][j];
else 
 sol[i][j]= a[i][j]=o[i][j]=hard[no][i][j];

 
}

}

}


void continue_to_game(int n){
string inp1,inp2,inp3; 
int row,col,number;


while(1){
s:

system("cls");

grid(n);
r:
cout<<"\n\nENTER ROW (1-9) : "; cin>>inp1;

if(inp1=="H" or inp1=="h"){

Hint(n);

}

else if(inp1=="C" or inp1=="c"){

complete(n);

}

else if(inp1=="E" or inp1=="e"){
 erase(n);
}

else if(inp1=="A" or inp1=="a"){
play_game_menu();  
}
else if(inp1=="o" or inp1=="O"){
 rc_unlock(1,n); 
}
else if(inp1=="p" or inp1=="p"){
 rc_unlock(2,n); 
}


else if(isNumber(inp1)){

row=stoi(inp1);


if(row<1 or row>9) {
 cout<<"INVALID ROW! ENTER AGAIN !";
 goto r; 
}


c:
cout<<"\nENTER COLUMN (1-9) : "; cin>>inp2;
col=stoi(inp2);
if(col<1 or col>9){
 cout<<"INVALID COLUMN! ENTER AGAIN !";
 
 goto c; 

}


if(o[row-1][col-1]!=0){
 cout<<"\n SORRY QUESTION CANNOT BE EDITED!!! " ;
 Sleep(1000);
 goto s;
} 

n:

cout<<"\n\n ENTER  NUMBER (1-9) : "; cin>>inp3;
number=stoi(inp3);
if(number<1 or number>9){
  cout<<"INVALID NUMBER! ENTER AGAIN !";
 
 goto n; 
}

if(number!=sol[row-1][col-1]){

cout<<"\n\t\t\tOOPS !!!! YOU ARE GOING WRONG WAY";
 Sleep(2000);
goto s;

  
}

a[row-1][col-1]=number;

int check=1;

for(int i=0;i<9;i++){
 for(int j=0;j<9;j++){
  if(a[i][j]!=sol[i][j])
  check=0;          
 } 
}

if(check==1) complete(n);

}

else{
  cout<<"INVALID ROW! ENTER AGAIN !";
 goto r; 
}

}


}


bool IsSafe( int row,  int col, int num) 
{       
  
        for (int i = 0; i < 9; i++)
          if(i!=col)
          if (o[row][i] == num) 
            return false;
            
    for (int i = 0; i < 9; i++) 
        if(i!=row)
        if (o[i][col] == num) 
            return false; 
int rootn=sqrt(9);
  
    int rowstart=(row/rootn)*rootn;

int colstart=(col/rootn)*rootn;
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            if(i+rowstart!=row and j+colstart!=col)
            if (o[i + rowstart][j +colstart] == num) 
                return false; 
  
    return true; 
} 
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}


void Game(int n){

string inp1,inp2,inp3; 
int row,col,number;

if(n!=4)
random(n);


for(int i=0;i<9;i++){
for(int j=0;j<9;j++){
if(o[i][j]!=0){


if(IsSafe(i,j,o[i][j])==0){
system("cls");

 cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\tSORRY SUDOKU CANNOT BE COLORED ----- NOT SOLVABLE!!!";
   Sleep(2000);
main_menu(); 

}
}

}
   

}


if(!sudoku(sol,9,0,0))
{   

   cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\tSORRY SUDOKU  CANNOT BE COLORED ----- NOT SOLVABLE!!!";
   
   main_menu(); 
}


while(1){
s:

system("cls");

grid(n);
r:
cout<<"\n\nENTER ROW (1-9) : "; cin>>inp1;

if(inp1=="H" or inp1=="h"){

Hint(n);

}

else if(inp1=="C" or inp1=="c"){

complete(n);

}

else if(inp1=="E" or inp1=="e"){
 erase(n);
}

else if(inp1=="A" or inp1=="a"){
 main_menu(); 
}

else if(inp1=="o" or inp1=="O"){
 rc_unlock(1,n); 
}
else if(inp1=="p" or inp1=="p"){
 rc_unlock(2,n); 
}


else if(isNumber(inp1))
{

row=stoi(inp1);


if(row<1 or row>9) {
 cout<<"INVALID ROW! ENTER AGAIN !";
 goto r; 
}


c:
cout<<"\nENTER COLUMN (1-9) : "; cin>>inp2;
col=stoi(inp2);
if(col<1 or col>9){
 cout<<"INVALID COLUMN! ENTER AGAIN !";
 
 goto c; 

}


if(o[row-1][col-1]!=0){
 cout<<"\n SORRY QUESTION CANNOT BE EDITED!!! " ;
 Sleep(1000);
 goto s;
} 

n:

cout<<"\n\n ENTER  NUMBER (1-9) : "; cin>>inp3;
number=stoi(inp3);
if(number<1 or number>9){
  cout<<"INVALID NUMBER! ENTER AGAIN !";
 
 goto n; 
}


if(number!=sol[row-1][col-1]){

cout<<"\n\t\t\tOOPS !!!! YOU ARE GOING WRONG WAY";
 Sleep(2000);
goto s;

  
}
a[row-1][col-1]=number;

int check=1;

for(int i=0;i<9;i++){
 for(int j=0;j<9;j++){
  if(a[i][j]!=sol[i][j])
  check=0;          
 } 
}

if(check==1) complete(n);


}

else {
  cout<<"INVALID ROW! ENTER AGAIN !";
 goto r; 
}

}


}




void play_game_menu(){

top:

system("cls");
system("COLOR F4");





cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t #################::PLAY  GAME !!!::#############\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t1. EASY \t\t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t2. MEDIUM \t\t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t3. HARD \t\t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t4. BACK TO MAIN MENU \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";
        
 
      cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

int ch;  cin>>ch;
switch(ch){
case 1:  Game(1);
         break;
         

case 2: Game(2);
break;


case 3: Game(3);
break;

case 4: main_menu();
        break;

default : cout<<"\n\t\t\t\t\t\t\t\tENTER VALID CHOICE  " ;
          Sleep(1000);
           goto top;   
}

}


void Intro()
{
     system("cls");
     system("COLOR 0A");
     for(int i=1;i<=10;++i)
     {
         Sleep(5);
         system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLOADING "<<i*10<<"%";
         if(i==10)
         {
             Sleep(1000);
         }
     }
     system("cls");
     Sleep(3000);
     system("cls");
}




void Welcome()
{
    system("cls");
    system("COLOR 0E");

    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t ||                  WELCOME TO                ||\n";
    cout<<"\t\t\t\t\t ||                                            ||\n";
    cout<<"\t\t\t\t\t ||                 SUDOKU SOLVER              ||\n";
    cout<<"\t\t\t\t\t ||                                            ||\n";
    cout<<"\t\t\t\t\t ||                    PROJECT                 ||\n";
    cout<<"\t\t\t\t\t ================================================\n\n\n";

    cout<<"\t\t\t\t\t-------------------------------------------------\n";
    cout<<"\t\t\t\t\t\t\t Created By:-             \t\n";
    cout<<"\t\t\t\t\t\t\t                           \t\n";
    cout<<"\t\t\t\t\t\t\t  VARUN KUMAR             \t\n";
    cout<<"\t\t\t\t\t\t\t  YASHIT KUMAR        \t\n";
    cout<<"\t\t\t\t\t-------------------------------------------------\n\n";

    system("pause");
      Intro();
    main_menu();
}






int main()
{
   system("cls");

    Welcome();

   main_menu();



    return 0;
}





