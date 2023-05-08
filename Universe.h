#include <bits/stdc++.h>

using namespace std;

// Defining grid size
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

    // Populate the grid with dead cells
    void Reset(){
        for (int i = 0; i < N; i++){
        
            for(int j = 0; j < K; j++){

                cells[i][j].setSign('.');

            }
        }
    }

    // Run the game
    void Expand(){
        count = 0;
        system("cls");
        this->DisplayCells();
        system("pause");
        this->CountNeighbors();
        this->AssignState();
        this->NextGen();
    }

    // Change the state of a cell
    void ChangeCells(char choice, int rows, int columns){

        // Assign a new cell
        if(choice == '2'){
            cells[rows][columns].setSign('O');
        }

        // Delete an existing cell
        else if(choice == '3'){
            cells[rows][columns].setSign('.');
        }
        this->DisplayCells();
    }

    // Calculate the next generation
    void NextGen(){

        for (int i = 0; i < N; i++){

            for(int j = 0; j < K; j++){

                // If the cell is alive, set the sign to 'O'
                if(cells[i][j].getState() == true){
                    cells[i][j].setSign('O');
                }

                // If the cell is dead, set the sign to '.'
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

    // Display the grid
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

    // Count the number of neighbors for each cell
    int CountNeighbors(){
        
        int count = 0;

        for (int i = 0; i < N; i++){

            for(int j = 0; j < K; j++){

                for (int k = i - 1; k <= i + 1; k++)
                {
                    // Check if the cell is out of bounds
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

    // Assign the state of each cell
    void AssignState(){

        for (int i = 0; i < N; i++){

            for(int j = 0; j < K; j++){

                // Any live cell with fewer than two live neighbors or more than three live neighbors dies.                
                if(cells[i][j].getNeighbors() < 2 || cells[i][j].getNeighbors() > 3){
                    cells[i][j].setState(false);
                }

                // Any live cell with two or three live neighbors lives on to the next generation.
                else if((cells[i][j].getNeighbors() == 2 || cells[i][j].getNeighbors() == 3) && cells[i][j].getSign() == 'O'){
                    cells[i][j].setState(true);
                }

                // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                else if(cells[i][j].getNeighbors() == 3 && cells[i][j].getSign() == '.'){
                    cells[i][j].setState(true);
                }

                // Otherwise, the cell stays dead.
                else{
                    cells[i][j].setState(false);
                }
            }
        }
    }
};

