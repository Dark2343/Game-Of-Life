#include "Universe.h"

int main(){
    Universe Andromeda;
    Andromeda.Reset();

    while (true)
    {

        cout << "Do you want to\n1- Run the game\n2- Assign new cells\n3- Delete existing cells\n";
        char choice;
        cin >> choice;
        if(choice == '1'){
            Andromeda.Expand();
        }
        else{
            bool valid = true;
            while (valid)
            {
                int row, column;
                cout << "Select the cell you want\nRow: ";
                cin >> row;
                cout << "Column: ";
                cin >> column;
                
                if(row > N || column > K){
                    cout << "Cell out of bounds...\nTry choosing a different cell.";
                }
                else{
                    Andromeda.ChangeCells(choice, row, column);
                    valid = false;
                }
            }
        }
    }    
}