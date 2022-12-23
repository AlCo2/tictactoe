#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
using namespace std;


string table[3][3];
void createTable(){
    int n = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            n++;
            table[i][j] = to_string(n);
        }
    }
}
void showTable(){
    for(int i=0;i<3;i++){
        cout << "\t";
        for(int j=0;j<3;j++){
            if(j==1 || j==2){
                cout << "|";
            }
            cout << "  " <<table[i][j] << "   ";
        }
        cout << endl;
        if(i==0|| i==1)
            cout << "\t______ ______ ______";
        cout << endl;
    }
}

#endif // TABLE_H_INCLUDED
