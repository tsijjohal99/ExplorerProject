#include <iostream>
using namespace std;

/*struct CharacterStats {
    string Name = "";
    int 
}*/

void printGrid(int &userRows, int &userColumns){
  cout<<endl;
  cout<<" ";
  int i=1,j;
  for(j = 0; j <= 4*userColumns; j++){
    if(j%4==2)
        cout<<i++;
    else cout<<" ";
  }
  cout<<endl;
  for(i = 0; i <= 2*userRows; i++){
    if(i%2!=0)
      cout<<(char)(i/2 +'A');
    for(j = 0; j <= 2*userColumns; j++){
      if(i%2==0)
      {
        if(j==0)
            cout<<" ";
        if(j%2==0)
           cout << " ";
        else cout<<"---";
      }
      else{
        if(j%2==0)
            cout<<"|";
        else cout<<"   ";
      }
    }
    if(i%2!=0)
      cout<<(char)(i/2 +'A');
    cout<<endl;
  }
  cout<<" ";
  for(j = 0, i = 1; j <= 4*userColumns; j++){
    if(j%4==2)
        cout<<i++;
    else cout<<" ";
  }
  cout<<endl;
}

int main() {
    system("cls");

    int userColumn = 10;
    int userRow = 10;

    printGrid(userColumn, userRow);

    return 0;
}