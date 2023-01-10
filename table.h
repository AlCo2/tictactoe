#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
using namespace std;


string table[3][3];
void createTable(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            table[i][j] = ".";
        }
    }
}
void showTable(){
    int n = 0;
    cout << "\n\n\n\n\n\n\n";
    for(int i=0;i<3;i++){
        cout << "\t\t\t\t\t";
        for(int j=0;j<3;j++){
            n++;
            if(j==1 || j==2){
                cout << "|";
            }
            if(table[i][j]==".")
                cout << "  " << n << "   ";
            else
                cout << "  " << table[i][j] << "   ";
        }
        cout << endl;
        if(i==0|| i==1)
            cout << "\t\t\t\t\t------+------+------";
        cout << endl;
    }
}

bool isMovesLeft(string table[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (table[i][j]==".")
                return true;
    return false;
}

#endif // TABLE_H_INCLUDED
