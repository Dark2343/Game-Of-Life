#include <bits/stdc++.h>

using namespace std;

#define N 15
#define K 30

class Cell
{
private:
    char sign;
    bool state;     // 0 = Dead, 1 = Alive
    int neighbors;
public:

    void setSign(char input){
        sign = input;
    }

    char getSign(){
        return sign;
    }

    void setState(bool State){
        state = State;
    }

    bool getState(){
        return state;
    }

    void setNeighbors(int neigh){
        neighbors = neigh;
    }

    int getNeighbors(){
        return neighbors;
    }

};

class Universe
{

private:
    Cell cells[N][K];
    int count;
public:

    void Reset(){
        for (int i = 0; i < N; i++){
        
            for(int j = 0; j < K; j++){

                cells[i][j].setSign('.');

            }
        }
    }

    void Expand(){
        count = 0;
        system("cls");
        this->DisplayCells();
        system("pause");
        this->CountNeighbors();
        this->AssignState();
        this->NextGen();
    }

    void ChangeCells(char choice, int rows, int columns){

        if(choice == '2'){
            cells[rows][columns].setSign('O');
        }
        else if(choice == '3'){
            cells[rows][columns].setSign('.');
        }
        this->DisplayCells();
    }

    void NextGen(){

        for (int i = 0; i < N; i++){

            for(int j = 0; j < K; j++){

                if(cells[i][j].getState() == true){
                    cells[i][j].setSign('O');
                }
                else if(cells[i][j].getState() == false){
                    cells[i][j].setSign('.');
                }
            }
        }

        this->DisplayCells();
        this->CountNeighbors();
        this->AssignState();
        this->NextGen();
    }

    void DisplayCells(){
        
        this_thread::sleep_for(chrono::milliseconds(250));
        system("CLS");

        for (int i = 0; i < N; i++){

            for(int j = 0; j < K; j++){

                cout << cells[i][j].getSign(); 
            }
            cout << "\n";
        }
    }


    int CountNeighbors(){
        
        int count = 0;

        for (int i = 0; i < N; i++){

            for(int j = 0; j < K; j++){

                for (int k = i - 1; k <= i + 1; k++)
                {
                    if(k < 0 || k > N - 1){
                        continue;
                    }
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if(l < 0 || l > K - 1){
                            continue;
                        }
                        else if((k == i) && (l == j)){
                            continue;
                        }

                        else if(cells[k][l].getSign() == 'O'){
                            count++;
                        }
                    }
                }
                cells[i][j].setNeighbors(count);
                count = 0;
            }
        }
        return EXIT_SUCCESS;
    }

    void AssignState(){

        for (int i = 0; i < N; i++){

            for(int j = 0; j < K; j++){
                
                if(cells[i][j].getNeighbors() < 2 || cells[i][j].getNeighbors() > 3){
                    cells[i][j].setState(false);
                }
                else if((cells[i][j].getNeighbors() == 2 || cells[i][j].getNeighbors() == 3) && cells[i][j].getSign() == 'O'){
                    cells[i][j].setState(true);
                }
                else if(cells[i][j].getNeighbors() == 3 && cells[i][j].getSign() == '.'){
                    cells[i][j].setState(true);
                }
                else{
                    cells[i][j].setState(false);
                }
            }
        }
    }
};

