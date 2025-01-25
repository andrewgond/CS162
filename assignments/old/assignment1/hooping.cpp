/******************************************************
** Program: hooping.cpp
** Author: Andrew Gondoputro
** Date: 1/15/2024
** Description: Simulates a basketball game
** Input: inputs for the game
** Output: Text output of the basketball game
******************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void playGame(int num, int*& moneyRacks, int*& playerAcc, int*& score, int**& playerNBoard);

void fillRack(int rackitem[], int acc , bool isMoneyRack);

bool takeShot(int acc);

void displayRack(int rack[5]);

void playerSetup(int playerNum , int *moneyRack, int *playerAcc);

int calculatePts(int rack[5]);

void printWinner(int playerCount,int scoreArr[]);

void printMultiTie(int winCount, int topScore, int scoreArr[]);

void printNormTie(int winnerIndex, int playerCount, int topScore, int scoreArr[]);

void calcWinner(int playerCount, int &winnerIndex, int &topScore, int &winnerCount, int scoreArr[]);

int requestPlayAgain();

void resetDynamicArrays(int num, int**& playerNBoard, int*& playerAcc, int*& moneyRacks, int*& score);

void setDynamicArrays(int num, int**& playerNBoard, int*& playerAcc, int*& moneyRacks, int*& score);

int setNumPlayers();




int main() {
  /*********************************************************************
  ** Function: main()
  ** Description: Main function that runs the game
  *********************************************************************/   
  srand(time(NULL)); //seeding the random functions
  int playAgain = 0;
  
  do 
  {
    int num = setNumPlayers();
    int** playerNBoard = new int*[num*5];
    for (int i = 0 ; i < (num*5) ; i++)
    {
      playerNBoard[i] = new int[5];
    } 
    int* playerAcc = new int[num];  
    int* moneyRacks = new int[num];
    int* score = new int[num];
    
    playGame(num, moneyRacks, playerAcc, score, playerNBoard);
    resetDynamicArrays(num, playerNBoard, playerAcc, moneyRacks, score);
    playAgain = requestPlayAgain();

  } while (playAgain == 1);
  return 0;
}

void playerSetup(int playerNum , int *moneyRack, int *playerAcc)
{
  /*********************************************************************
  ** Function: playerSetup(int playerNum , int *moneyRack, int *playerAcc)
  ** Description: Takes user inputs and sets them to the variable addresses in the parameters
  ** Parameters: int playerNum , int &moneyRack, int &playerAcc
  ** Pre-Conditions: 
  ** Post-Conditions: moneyRack is between 1 and 5, playerAcc is between 1 and 99
  *********************************************************************/ 
  cout << "Player " << playerNum << ":" << endl;
  do{
    cout << "Where do you want to put your money-ball rack? Enter 1-5:";
    cin >> *moneyRack; 
    cout << endl; 
    if (*moneyRack < 1 || *moneyRack > 5) cout << "That's not a valid input" << endl;
  } while (*moneyRack < 1 || *moneyRack > 5);

  do{
    cout << "Enter your shooting ability, from 1 to 99:";
    cin >> *playerAcc ; 
    cout << endl;
    if (*playerAcc < 1 || *playerAcc > 99) cout << "That's not a valid input" << endl; 
  } while (*playerAcc < 1 || *playerAcc > 99);
  return;

}


void fillRack(int rack[], int acc , bool isMoneyRack) 
{
  /*********************************************************************
  ** Function: Fills a 5 space array with shots based on accuracy
  ** Description: Sorts out what score a given shot is based on isMoneyRack, position in array, and if the shot is made
  ** Parameters: int rack[], int acc , bool isMoneyRack
  ** Post-Conditions: An array filled with the simulated shots
  *********************************************************************/ 
  for (int i = 0 ; i < 5 ; i++)
  {
    bool shot = takeShot(acc); 
    if (shot)
    {
      if (i == 4 || isMoneyRack) rack[i] = 2;
      else rack[i] = 1;
    }
    else rack[i] = 0;
  }
  return;
}

bool takeShot(int acc)
{
/*********************************************************************
** Function: takeShot(int acc)
** Description: Basically just returns if the shot makes it based on the rand() function
** Parameters: int acc
** Pre-Conditions: Accuracy is between 1 and 99
** Post-Conditions: return true/false for if a shot is made or not
*********************************************************************/ 
  return (rand()%100 < acc) ;
}

void displayRack(int rack[5])
{
  /*********************************************************************
  ** Function: displayRack(int rack[5])
  ** Description: Prints out a rack as a single formatted line
  ** Parameters: int rack[5]
  ** Pre-Conditions: rack is fileld with 0, 1, or 2
  ** Post-Conditions: print out to terminal
  *********************************************************************/ 
  int count = 0 ; 
  for( int j = 0 ; j < 5 ; j++ )
  {
    char out = 'X';
    if (rack[j] == 1) out = 'O';
    else if (rack[j] == 2) out = 'M';
    cout << out << ' ';
  }
  cout << "|   " << calculatePts(rack) << " pts" << endl ; 
  return; 
}

int calculatePts(int rack[5])
{
  /*********************************************************************
  ** Function: calculatePts(int rack[5])
  ** Description: Calculate the points in a given rack
  ** Parameters: int rack[5] to represent a rack 
  ** Pre-Conditions: rack is a 5 item array
  ** Post-Conditions: Number of points in a given rack is outputted
  *********************************************************************/ 
  int count = 0; 
  for (int j = 0 ; j < 5 ; j++)
  {
    count += rack[j];
  }
  return count; 
}

void printWinner(int playerCount, int scoreArr[])
{
  /*********************************************************************
  * Function: Calculates who the winner is and prints it out along with any ties
  ** Description: goes through all the player's scores and uses if else logic for ties
  ** Parameters: int playerCount, and int scoreArr[]
  ** Pre-Conditions: scoreArr is filled and is the size of playerCount
  ** Post-Conditions: Winner statement is printed
  *********************************************************************/ 
  int winnerIndex = 0;
  int winnerCount = 1;
  int topScore = scoreArr[0] ; 

  calcWinner(playerCount, winnerIndex, topScore, winnerCount, scoreArr);

  if (winnerCount > 2) printMultiTie(winnerCount, topScore, scoreArr);
  else if (winnerCount == 2) printNormTie(winnerIndex, playerCount, topScore, scoreArr);
  else cout << "Player " << (winnerIndex+1) << " has won \n";

  return;
}

void calcWinner(int playerCount, int &winnerIndex, int &topScore, int &winnerCount, int scoreArr[])
{
  /*********************************************************************
  ** Function: calcWinner()
  ** Description: Figure out what the winning 
  ** Parameters:int playerCount, int &winnerIndex, int &topScore, int &winnerCount, int scoreArr[]
  ** Pre-Conditions: all parameters are put in properly
  ** Post-Conditions: updated winnerIndex and topScore
  *********************************************************************/
  for (int p = 1 ; p < playerCount ; p++ )
  {
    if (scoreArr[p] > scoreArr[winnerIndex])
    {
      winnerIndex = p;
      winnerCount = 1; 
      topScore = scoreArr[winnerIndex];
    }
    else if (scoreArr[p] == topScore)
    {
      winnerCount ++;
    }
  } 
  return;
}


void printMultiTie(int winCount, int topScore, int scoreArr[])
{
  /*********************************************************************
  ** Function: void printMultiTie(int winCount, int topScore, int scoreArr[])
  ** Description: Prints out all players with the top score
  ** Parameters: int winCount, int topScore, int scoreArr[]
  ** Pre-Conditions: scoreArr is filled out
  ** Post-Conditions: Print out the tied players to the terminal
  *********************************************************************/
  cout << "Players ";
  for (int o = 0 ; winCount != 0 ; o++)
  {
    if (winCount == 1 && scoreArr[o] == topScore)
    {
      cout << "and " << (o+1) ;
      winCount -- ;
    }
    else if (scoreArr[o] == topScore)
    {
      cout << (o+1) << ", ";
      winCount--;
    }
    
  }
  cout << " have tied." << endl;
  return;
}

void printNormTie(int winnerIndex, int playerCount, int topScore, int scoreArr[])
{
  /*********************************************************************
  ** Function: void printNormTie(int winnerIndex, int playerCount, int topScore, int scoreArr[])
  ** Description: Prints out a statement for when two players are tied
  ** Parameters: int winnerIndex, int playerCount, int topScore, int scoreArr[]
  ** Pre-Conditions: all paramters are initalized and filled out
  ** Post-Conditions: prints out a statement for two players tying
  *********************************************************************/
  cout << "Player " << (winnerIndex+1) << " and Player ";
  for (int o = winnerIndex+1 ; o < playerCount ; o++)
  {
    if (scoreArr[o] == topScore)
    {
      cout << (o+1) << ' ';
      break;
    }
  }
  cout << "have tied." << endl;
  return;
}

int requestPlayAgain()
{
  /*********************************************************************
  ** Function: int requestPlayAgain()
  ** Description: Asks to 
  ** Parameters: n/a
  ** Pre-Conditions: n/a
  ** Post-Conditions: outputs either 1 or 0 to represent the game resuming or not
  *********************************************************************/
  int playAgain;
  do
  {
    cout << "Do you want to play again? (1-yes, 0-no): ";
    cin >> playAgain ; 
    cout << endl;
    if (playAgain != 1 && playAgain != 0) cout << "That's not a valid input" << endl;
  } while (playAgain != 1 && playAgain != 0);
  return playAgain; 
}

void playGame(int num, int*& moneyRacks, int*& playerAcc, int*& score, int**& playerNBoard)
{
  /*********************************************************************
  ** Function: void playGame(int num, int*& moneyRacks, int*& playerAcc, int*& score, int**& playerNBoard)
  ** Description: goes through the game and simulates taking user inputs and filling out what the score is and the board
  ** Parameters: int num, int*& moneyRacks, int*& playerAcc, int*& score, int**& playerNBoard
  ** Pre-Conditions: 
  ** Post-Conditions: Output the winner and put the game in the terminal
  *********************************************************************/
  for (int player = 0 ; player < num ; player++)
  {
    playerSetup(player+1, &moneyRacks[player], &playerAcc[player]);
    moneyRacks[player] --;
    score[player] = 0 ; 
    int r = 0 ;
    int c = 5 ;
    for (int r = 0; r < c ; r++)
    {
      fillRack(playerNBoard[r], playerAcc[player], (moneyRacks[player]==r));
      displayRack(playerNBoard[r]);
      score[player] += calculatePts(playerNBoard[r]) ;
    }
    c += r ; 
    cout << score[player] << "pts " << endl << endl;
  }
  printWinner(num, score);
  return;
}


void resetDynamicArrays(int num, int**& playerNBoard, int*& playerAcc, int*& moneyRacks, int*& score)
{
  /*********************************************************************
  ** Function: resetDynamicArrays(int num, int**& playerNBoard, int*& playerAcc, int*& moneyRacks, int*& score)
  ** Description: free up memory on the heap from the dynamic arrays
  ** Parameters:int num, int**& playerNBoard, int*& playerAcc, int*& moneyRacks, int*& score
  ** Pre-Conditions: All paramters exist
  ** Post-Conditions: All dynamic Arrays are now empty
  *********************************************************************/
  for (int i = 0 ; i < (num*5) ; i++)
  {
    delete[] playerNBoard[i];
  } 
  delete[] playerNBoard;
  playerNBoard = NULL;
  delete[] playerAcc;
  playerAcc = NULL;  
  delete[] moneyRacks;
  moneyRacks = NULL; 
  delete[] score;
  score = NULL;
  return;
}


int setNumPlayers()
  {
  /*********************************************************************
  ** Function: int setNumPlayers()
  ** Description: Takes user inputs for how many players will be in the game
  ** Parameters: n/a
  ** Pre-Conditions: 
  ** Post-Conditions: outputs the number of players greater than 2
  *********************************************************************/
    int num = 0;
    do
    {
      cout << "How many players? ";
      cin >> num;
      if (num < 2) cout << "Invalid input" << endl;
    } while (num < 2);
  return num;
  }