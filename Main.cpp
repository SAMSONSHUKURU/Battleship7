/*Samson Shukuru
C++ Fall 2022
Due:December 12
Lab #7 Battleship
a simple battleship game against the computer*/

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

typedef char board[10][10];


void resetboard(board UserBoard1, board ComputerBoard, board UserEnemy, board ComputerEnemy);
//this functions creates the boards and outputs the "~" as water

void UserBoard(board UserBoard1);
//this function prints the User's boards and its corresponding characteristics.

void computerPlacement(board computerboard);
//prints computer board to screen

void UserPlacement(board UserBoard1);
//allows the user to places ships

void BadPlacement(int& row, int& column, board UserBoard1);
//this function notifies the user that they have inputed an invalid location

void AvaiablePlacement(int playerrow, int playercolumn, int playerlength, board UserEnemy);
//checks if the ship placements are valid locations

void Usershipsdirection(board UserEnemy, char shipdirection, int rownumber, int columnnumber, int lengthship);
//this function allows the user to place the 1st point a ship and checks its size to see if the ship fits in its selcected row or column

void computerplaceships(board ComputerEnemy);
//computers 1st ship point is randomly generated placement

void computershipsdirection(board ComputerEnemy, int Comlength, int ComRow, int ComColumn);
//computers randomly ships after 1st point is selected 

void Firing(board ComputerEnemy, board UserEnemy, int& wins, int& losses, board UserBoard1);
//the user and computer take turns firing agianst each other

void EndGame(int pwins, int plosses, bool& ContinuePlay);
//this function ask if the user wants to play again or quit
int main()
{
    board UserBoard1;
    board ComputerBoard;
    board UserEnemy;
    board ComputerEnemy;


  
  

    bool playagain = true;

    int Userwins = 0;
    int Userlosses = 0;


    resetboard(UserBoard1, ComputerBoard, UserEnemy, ComputerEnemy);

    while (playagain == true)
    {
        UserPlacement(UserBoard1);
        computerPlacement(ComputerBoard);
        Firing(ComputerBoard, UserBoard1, Userwins, Userlosses, UserBoard1);
        EndGame(Userwins, Userlosses, playagain);
        resetboard(UserBoard1, ComputerBoard, UserEnemy,ComputerEnemy);
    }
    return 0;
}


void resetboard(board Userboard1, board computerboard, board UserEnemy, board ComputerEnemy)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Userboard1[i][j] = 0;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            computerboard[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            UserEnemy[i][j] = 0;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ComputerEnemy[i][j] = 0;
        }
    }

}

void UserBoard(board UserBoard1)
{
    int x = 0;
    cout << "    ";
    while (x < 10)
    {
        cout << 1 + x << "  ";
        x++;
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        if (i < 9)
        {
            cout << 1 + i << "   ";
        }
        if (i == 9)
        {
            cout << "10  ";
        }
        for (int j = 0; j < 10; j++)
        {
            if (UserBoard1[i][j] == 0)

                //cout <<" "<< GameData.water<< " ";
                     
            cout << "~  ";
            if (UserBoard1[i][j] == 1)
            
                //cout << GameData.Ship;
            
            cout << "#  ";
            if (UserBoard1[i][j] == 2)
            
               //cout << GameData.Miss;
            
            cout << "M  ";
            if (UserBoard1[i][j] == 3)
            
                //cout << GameData.Hit;
            
             cout << "H  ";
        }
        cout << endl;
    }
    cout << endl;


}

void computerPlacement(board computerboard)
{
    int z = 0;
    cout << "    ";
    while (z < 10)
    {
        cout << 1 + z << "  ";
        z++;
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        if (i < 9)
        {
            cout << 1 + i << "   ";
        }
        if (i == 9)
        {
            cout << "10  ";
        }
        for (int j = 0; j < 10; j++)
        {
            if (computerboard[i][j] < 2)
                cout <<  "~  ";
            if (computerboard[i][j] == 2)
                cout << "M  ";
            if (computerboard[i][j] == 3)
                cout << "H  ";
        }
        cout << endl;
    }
    cout << endl;
}

void UserPlacement(board UserBoard1)
{
    int row;
    int column;
    char direction;
    int boatlength = 5;

    UserBoard(UserBoard1);

    cout << endl << "To start the game, please place your Carrier, which is five spaces long." << endl <<
        "First, choose which row you want to start your Carrier.  ";

    cin >> row;

    cout << "Now, which column do you want to place your Carrier.  ";

    cin >> column;

    BadPlacement(row, column, UserBoard1);

    UserBoard1[row - 1][column - 1] = 1;
    UserBoard(UserBoard1);

    AvaiablePlacement(row, column, boatlength, UserBoard1);

    cin >> direction;
    Usershipsdirection(UserBoard1, direction, row, column, boatlength);

    UserBoard(UserBoard1);
    boatlength--;

    cout << endl << "The next piece to be placed is the Battleship. This ship is four spaces long." << endl <<
        "First, choose which row you want to start your Battleship.  ";

    cin >> row;

    cout << "Now, which column do you want to place your Battleship.  ";

    cin >> column;

    BadPlacement(row, column, UserBoard1);

    UserBoard1[row - 1][column - 1] = 1;
    UserBoard(UserBoard1);

    AvaiablePlacement(row, column, boatlength, UserBoard1);

    cin >> direction;
    Usershipsdirection(UserBoard1, direction, row, column, boatlength);

    UserBoard(UserBoard1);
    boatlength--;

    cout << endl << "Next is the three space, Cruiser." << endl << "Choose which row to start your Cruiser.  ";

    cin >> row;

    cout << "Now, which column do you want to place your Cruiser.  ";

    cin >> column;

    BadPlacement(row, column, UserBoard1);

    UserBoard1[row - 1][column - 1] = 1;
    UserBoard(UserBoard1);

    AvaiablePlacement(row, column, boatlength, UserBoard1);

    cin >> direction;
    Usershipsdirection(UserBoard1, direction, row, column, boatlength);

    UserBoard(UserBoard1);

    cout << endl << "The Submarine is the next ship you need to place. The sub is three space long as well." << endl
        << "Pick the row where you want to start the submarine.   ";

    cin >> row;

    cout << "Now, which column do you want to place your Battleship.  ";

    cin >> column;

    BadPlacement(row, column, UserBoard1);

    UserBoard1[row - 1][column - 1] = 1;
    UserBoard(UserBoard1);

    AvaiablePlacement(row, column, boatlength, UserBoard1);

    cin >> direction;
    Usershipsdirection(UserBoard1, direction, row, column, boatlength);

    UserBoard(UserBoard1);
    boatlength--;

    cout << endl << "The final ship that needs to be placed is the two space long Destroyers." << endl <<
        "Chose the row where your Destroyer begins.   ";

    cin >> row;

    cout << "Now, which column do you want to place your Battleship.  ";

    cin >> column;

    BadPlacement(row, column, UserBoard1);

    UserBoard1[row - 1][column - 1] = 1;
    UserBoard(UserBoard1);

    AvaiablePlacement(row, column, boatlength, UserBoard1);

    cin >> direction;
    Usershipsdirection(UserBoard1, direction, row, column, boatlength);

    UserBoard(UserBoard1);
}

void computerplaceships(board ComputerEnemy)
{
    int computerrow;
    int computercolumn;
    int ComShipLength = 5;
    srand(time(NULL));

    computerrow = rand() % 10 + 1;
    computercolumn = rand() % 10 + 1;

    computershipsdirection(ComputerEnemy, ComShipLength, computerrow, computercolumn);


    ComShipLength--;


    computerrow = rand() % 10;
    computercolumn = rand() % 10;

    computershipsdirection(ComputerEnemy, ComShipLength, computerrow, computercolumn);


    ComShipLength--;


    computerrow = rand() % 10;
    computercolumn = rand() % 10;

    computershipsdirection(ComputerEnemy, ComShipLength, computerrow, computercolumn);



    computerrow = rand() % 10;
    computercolumn = rand() % 10;

    computershipsdirection(ComputerEnemy, ComShipLength, computerrow, computercolumn);

    ComShipLength--;


    computerrow = rand() % 10;
    computercolumn = rand() % 10;

    computershipsdirection(ComputerEnemy, ComShipLength, computerrow, computercolumn);

}

void BadPlacement(int& row, int& column, board Userboard1)
{
    if (row > 10)
    {
        cout << " The row you enter is invalid. Please enter a valid row.  ";
        cin >> row;
    }
    if (column > 10)
    {
        cout << "The column you enterer is invalid. Please enter a valid column.  ";
        cin >> column;
    }
    if (Userboard1[row - 1][column - 1] == 1)
    {
        cout << "The coordinate you typed in has already been used. Please enter new row and column" << endl;
        cout << "First a new row.  ";
        cin >> row;
        cout << "Now enter your new column.  ";
        cin >> column;
    }
}

void AvaiablePlacement(int playerrow, int playercolumn, int playerlength, board boardofplayer)
{

    if (playercolumn - playerlength >= 0 && boardofplayer[playerrow - 1][playercolumn - 2] == 0 && boardofplayer[playerrow - 1][playercolumn - 3] == 0
        && boardofplayer[playerrow - 1][playercolumn - 4] == 0)
        cout << "You can place your Carrier horizontally to the left, to do so enter L.\n";
    if (playercolumn - 1 + playerlength <= 10 && boardofplayer[playerrow - 1][playercolumn] == 0 && boardofplayer[playerrow - 1][playercolumn + 1] == 0
        && boardofplayer[playerrow - 1][playercolumn + 2] == 0)
        cout << "You can place your Carrier horizontally to the right, to do so enter R.\n";
    if (playerrow - playerlength >= 0 && boardofplayer[playerrow - 2][playercolumn - 1] == 0 && boardofplayer[playerrow - 3][playercolumn - 1] == 0
        && boardofplayer[playerrow - 4][playercolumn - 1] == 0)
        cout << "You can place your Carrier veritcally up, to do so enter U.\n";
    if (playerrow - 1 + playerlength <= 10 && boardofplayer[playerrow][playercolumn - 1] == 0 && boardofplayer[playerrow + 1][playercolumn - 1] == 0
        && boardofplayer[playerrow + 2][playercolumn - 1] == 0)
        cout << "You can place your Carrier veritcally down, to do so enter D.\n";
}

void Usershipsdirection(board UserEnemy, char shipdirection, int rownumber, int columnnumber, int lengthship)
{

    int i = 1;
    switch (shipdirection)
    {
    case  'U':
        while (i <= lengthship)
        {
            UserEnemy[rownumber - i][columnnumber - 1] = 1;
            i++;
        }
        break;
    case 'D':
        while (i < lengthship)
        {
            UserEnemy[rownumber + i - 1][columnnumber - 1] = 1;
            i++;
        }
        break;
    case 'R':
        while (i < lengthship)
        {
            UserEnemy[rownumber - 1][columnnumber + i - 1] = 1;
            i++;
        }
        break;
    case 'L':
        while (i <= lengthship)
        {
            UserEnemy[rownumber - 1][columnnumber - i] = 1;
            i++;
        }
        break;
    case 'u':
        while (i <= lengthship)
        {
            UserEnemy[rownumber - i][columnnumber - 1] = 1;
            i++;
        }
        break;
    case 'd':
        while (i < lengthship)
        {
            UserEnemy[rownumber + i - 1][columnnumber - 1] = 1;
            i++;
        }
        break;
    case 'r':
        while (i < lengthship)
        {
            UserEnemy[rownumber - 1][columnnumber + i - 1] = 1;
            i++;
        }
        break;
    case 'l':
        while (i <= lengthship)
        {
            UserEnemy[rownumber - 1][columnnumber - i] = 1;
            i++;
        }
        break;
    default: cout << "An error has occured.";
        break;
    }

}

void computershipsdirection(board ComputerEnemy, int Comlength, int ComRow, int ComColumn)
{
    int z = 0;
    int success = 0;
    int fails = 0;
    int comDirection = rand() % 4 + 1;


    do
        switch (comDirection)
        {
        case 1:
            if (ComColumn - Comlength <= 1 || ComputerEnemy[ComRow - 1][ComColumn - 1] == 1 || ComputerEnemy[ComRow - 1][ComColumn - 2] == 1
                || ComputerEnemy[ComRow - 1][ComColumn - 3] == 1 || ComputerEnemy[ComRow - 1][ComColumn - 4] == 1)
            {
                comDirection++;
            }
            else
            {
                while (z < Comlength)
                {
                    ComputerEnemy[ComRow - 1][ComColumn - 1 - z] = 1;
                    z++;
                    success++;
                }
            }
            break;
        case 2:
            if (ComColumn + Comlength > 9 || ComputerEnemy[ComRow - 1][ComColumn - 1] == 1 || ComputerEnemy[ComRow - 1][ComColumn] == 1
                || ComputerEnemy[ComRow - 1][ComColumn + 1] == 1 || ComputerEnemy[ComRow - 1][ComColumn + 2] == 1)
            {
                comDirection++;
            }
            else
            {
                while (z < Comlength)
                {
                    ComputerEnemy[ComRow - 1][ComColumn - 1 + z] = 1;
                    z++;
                    success++;
                }
            }
            break;
        case 3:
            if (ComRow - Comlength <= 3 || ComputerEnemy[ComRow - 1][ComColumn - 1] == 1 || ComputerEnemy[ComRow - 2][ComColumn - 1] == 1
                || ComputerEnemy[ComRow - 3][ComColumn - 1] == 1 || ComputerEnemy[ComRow - 4][ComColumn - 1] == 1)
            {
                comDirection++;
            }
            else
                while (z < Comlength)
                {
                    ComputerEnemy[ComRow - 1 - z][ComColumn - 1] = 1;
                    z++;
                    success++;
                }
            break;
        case 4:
            if (ComRow + Comlength > 9 || ComputerEnemy[ComRow - 1][ComColumn - 1] == 1 || ComputerEnemy[ComRow][ComColumn - 1] == 1
                || ComputerEnemy[ComRow + 1][ComColumn - 1] == 1 || ComputerEnemy[ComRow + 2][ComColumn - 1] == 1)
            {
                comDirection = 1;
                fails++;
                if (fails >= 5)
                {
                    ComRow = rand() % 10 + 1;
                    ComColumn = rand() % 10 + 1;
                    fails = 0;
                    continue;
                }
            }
            else
                while (z < Comlength)
                {
                    ComputerEnemy[ComRow - 1 + z][ComColumn - 1] = 1;
                    z++;
                    success++;
                }
            break;
        default: cout << "error";
            break;

        }
    while (success < 1);
}

void Firing(board ComputerEnemy, board UserEnemy, int& wins, int& losses,  board UserBoard1)
{
    bool gameplay = true;
    int computerfirerow;
    int computerfirecolumn;
    int playerfirerow;
    int playerfirecolumn;
    int playeroptions;
    bool playerfired = false;
    bool computerfired = false;
    int playerhits = 0;
    int computerhits = 0;

    cout << "Now that the boards are set up, you and the computer will take turns firing at each others ship.";



    do
    {
        cout << "It is now your turn." << endl << "You can start your shots by pressing 1: " << endl
            << "You can look at your board by pressing 2: " << endl << "You can also choose to surrender by pressing 3:  ";

        cin >> playeroptions;

        do
        {
            switch (playeroptions)
            {
            case 1:
                cout << "\033[2J\033[1;1H";
                computerPlacement(ComputerEnemy);
                cout << "First choose which row you want to fire at:  ";
                cin >> playerfirerow;
                if (playerfirerow > 10)
                {
                    cout << "The row you entered isn't valid, please enter a new valid row to fire at.  ";
                    cin >> playerfirerow;
                }
                cout << "Now Choose which column you want to fire at:   ";
                cin >> playerfirecolumn;
                if (playerfirecolumn > 10)
                {
                    cout << "The column you entered isn't valid, please enter a new valid row to fire at.  ";
                    cin >> playerfirecolumn;
                }


                if (ComputerEnemy[playerfirerow - 1][playerfirecolumn - 1] == 0)
                {
                    cout << "Miss!\n\n\n\n";
                    ComputerEnemy[playerfirerow - 1][playerfirecolumn - 1] += 2;
                    playerfired = true;
                }
                if (ComputerEnemy[playerfirerow - 1][playerfirecolumn - 1] == 1)
                {
                    cout << "Hit!\n\n\n\n";
                    ComputerEnemy[playerfirerow - 1][playerfirecolumn - 1] += 2;
                    playerfired = true;
                    playerhits++;
                }
                computerPlacement(ComputerEnemy);
                break;
            case 2: UserBoard(UserBoard1);

                cout << "Now to fire at the computer press 1." << endl << "To surrender press 3. ";
                cin >> playeroptions;
                break;
            case 3:gameplay = false;
                playerfired = true;
                break;
            default: cout << "The option you input isn't valid. Please input a valid option."
                << "You can start your shots by pressing 1." << endl
                << "You can look at your board by pressing 2." << endl
                << "You can also choose to surrender by pressing 3:  ";
                cin >> playeroptions;
                break;
            }
        } while (playerfired == false);


        playerfired = false;


        computerfirerow = rand() % 10 + 1;
        computerfirecolumn = rand() % 10 + 1;

        do
        {
            if (UserEnemy[computerfirerow - 1][computerfirecolumn - 1] == 0)
            {
                cout << "The Computer fired at row " << computerfirerow << ",and column " << computerfirecolumn << " and Missed!\n\n";
                UserEnemy[computerfirerow - 1][computerfirecolumn - 1] += 2;
                computerfired = true;
            }
            if (UserEnemy[computerfirerow - 1][computerfirecolumn - 1] == 1)
            {
                cout << "The Computer fired at row " << computerfirerow << ",and column " << computerfirecolumn << " and Hit!\n\n";
                UserEnemy[computerfirerow - 1][computerfirecolumn - 1] += 2;
                computerfired = true;
                computerhits++;
            }
            if (UserEnemy[computerfirerow - 1][computerfirecolumn - 1] >= 2)
            {
                computerfirerow = rand() % 10 + 1;
                computerfirecolumn = rand() % 10 + 1;
            }
        } while (computerfired == false);

        if (playerhits == 15)
        {
            cout << "*******You have won the game********\n\n\n";
            gameplay = false;
            wins++;
        }
        if (computerhits == 15)
        {
            cout << "*******You have lost the game********\n\n\n";
            gameplay = false;
            losses++;
        }

    } while (gameplay == true);
}

void EndGame(int pwins, int plosses, bool& ContinuePlay)
{
    int endgameoptions;
    cout << "The game is over.\nPress 1 to play again:\nPress 2 to finish playing the game: ";

    cin >> endgameoptions;

    switch (endgameoptions)
    {
    case 1: cout << "Okay. Let's play again.\n\n\n\n\n\n\n\n";
        break;
    case 2: cout << "Thank you for playing." << endl << "You won " << pwins << " games." << endl <<
        "You lost " << plosses << "games.";
        ContinuePlay = false;
        break;
    default:
        break;
    }

}
