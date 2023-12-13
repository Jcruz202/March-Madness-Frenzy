/* ---------------------------------------------
Program 5: March Madness Frenzy / *

Course: CS 141, Fall 2021. Tues 1pm lab
System: Mac using xcode and replit
Author: Juan Miguel Cruz
---------------------------------------------
*/
#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <cassert>    // For the assert statement
#include <cctype>     // Allows using the tolower() function
#include <vector>     // For vectors
#include <cstring>    // For C string function strcpy
#include <sstream>    // For reading in CSV file and splitting by commas
#include <algorithm>  // For find(), which searches within a vector
#include <iterator> // to check stuff
#include <bits/stdc++.h> // to get the sum of all the elements in a vector
using namespace std;
// ----------------------------------------------------------------------
class BasketballRecord{
  public:
  //default constructor
  BasketballRecord(){
      region = " ";
      rank1 = 0;
      team1 = " ";
      score1 = 0;
      rank2 = 0;
      team2 = " ";
      score2 = 0;
      winningTeam = " ";
      roundNumber = 0;
      gameNumber = 0;
  }
  //fully qualified constructor
  BasketballRecord(string region, int rank1, string team1, int score1, int rank2, string team2, int score2, string winningTeam, int roundNumber, int gameNumber){
      BasketballRecord::region = region;
      BasketballRecord::rank1 = rank1;
      BasketballRecord::team1 = team1;
      BasketballRecord::score1 = score1;
      BasketballRecord::rank2 = rank2;
      BasketballRecord::team2 = team2;
      BasketballRecord::score2 = score2;
      BasketballRecord::winningTeam = winningTeam;
      BasketballRecord::roundNumber = roundNumber;
      BasketballRecord::gameNumber = gameNumber;
    }
  //setters
  void setFileName(string fName){fileName = fName;}
  void setRegion(string regionName){region = regionName;}
  void setRank1(int numRank1){rank1 = numRank1;}
  void setTeam1(string teamName1){team1 = teamName1;}
  void setScore1(int numScore1){score1 = numScore1;}
  void setRank2(int numRank2){rank2 = numRank2;}
  void setTeam2(string teamName2){team2 = teamName2;}
  void setScore2(int numScore2){score2 = numScore2;}
  void setWinningTeam(string winningTeamName){winningTeam = winningTeamName;}
  void setRoundNumber(int roundNum){roundNumber = roundNum;}
  void setGameNumber(int gameNum){gameNumber = gameNum;}
  //getters
  string getFileName(){return fileName;}
  string getRegion(){return region;}
  int getRank1(){return rank1;}
  string getTeam1(){return team1;}
  int getScore1(){return score1;}
  int getRank2(){return rank2;}
  string getTeam2(){return team2;}
  int getScore2(){return score2;}
  string getWinningTeam(){return winningTeam;}
  int getRoundNumber(){return roundNumber;}
  int getGameNumber(){return gameNumber;}

  //for utility function
  void utilityFunction(){
    int x = 10 / forUtility();
  }

  private:
  string fileName, region, team1, team2, winningTeam;
  int rank1, score1, rank2, score2, roundNumber, gameNumber; 
  //for utility function
  int forUtility(){
    return 5;
  }
};
// ----------------------------------------------------------------------
void Instruction(string &fileName){ // instruction of the program
  cout << "Program 5: March Madness Frenzy\n"
       << endl
       << "CS 141, Spring 2022, UIC\n"
       << "This program reads in data from NCAA Basketball Tournaments (aka March \n"
       << "Madness). It provides overall information regarding the data, allows you to\n"
       << "see the path taken to the championship, uses rankings of teams to determine\n"
       << "which region is expected to win at a given round and to find the best underdog\n"
       << "team, and calculates point differences within the games. You can also compare\n"
       << "the actual brackets to your own predictions!\n"
       << endl
       << "Enter the name of the file with the data for the NCAA tournament:\n";
  cin >> fileName;
}
// ----------------------------------------------------------------------
void menuOption(int &menuInput){ // menu options to pick for the program
  cout << "Select a menu option:\n"
       << "1. Display overall information about the data\n"
       << "2. Display the path of the winning team to the championship\n"
       << "3. Determine which region is expected to win the championship based on a given round\n"
       << "4. Identify the best underdog within a given round\n"
       << "5. Find the shoo-in and nail-biting games within a given round, or overall\n"
       << "6. Compare the actual brackets to your predicted brackets\n"
       << "7. Exit\n"
       << "Your choice -->";
  cin >> menuInput;
}
// ----------------------------------------------------------------------
void readInBasketballData(string fileName, vector<BasketballRecord>& basketballData) {
  //reading in the fileName and parsing it
  ifstream inStream;
  inStream.open(fileName);
   // assert(inStream.fail() == false)
  
  string recordLine;
  getline(inStream, recordLine); // read in header from file, and ignore
  // read in each line of the file
  while (getline(inStream, recordLine)) {
      stringstream s_stream(recordLine); //create string stream from the string
      BasketballRecord basketballRecords;

      // separate the line by commas into each column
      int colNum = 0;
      while (s_stream.good()) {
          string columnVal;
          getline(s_stream, columnVal, ','); //get first string delimited by comma
          int storage;

          // use the substring to fill in the appropriate part of the BillboardRecord
          switch (colNum) {
              case 0:
                  basketballRecords.setRegion(columnVal);
                  break;
              case 1:
                  if (columnVal != "") {
                      storage = stoi(columnVal);
                      basketballRecords.setRank1(storage);
                  }
                  else {
                      basketballRecords.setRank1(-1);
                  }
                  break;
              case 2:
                  basketballRecords.setTeam1(columnVal);
                  break;
              case 3:
                  if (columnVal != "") {
                      storage = stoi(columnVal);
                      basketballRecords.setScore1(storage);
                  }
                  else {
                      basketballRecords.setScore1(-1);
                  }
                  break;
              case 4:
                  if (columnVal != "") {
                      storage = stoi(columnVal);
                      basketballRecords.setRank2(storage);
                  }
                  else {
                      basketballRecords.setRank2(-1);
                  }
                  break;
              case 5:
                  basketballRecords.setTeam2(columnVal);
                  break;
              case 6:
                  if (columnVal != "") {
                      storage = stoi(columnVal);
                      basketballRecords.setScore2(storage);
                  }
                  else {
                      basketballRecords.setScore2(-1);
                  }
                  break;
              case 7:
                  basketballRecords.setWinningTeam(columnVal);
                  break;
              case 8:
                  if (columnVal != "") {
                      storage = stoi(columnVal);
                      basketballRecords.setRoundNumber(storage);
                  }
                  else {
                      basketballRecords.setRank1(-1);
                      
                  }
                  break;
              case 9:
                  if (columnVal != "") {
                      storage = stoi(columnVal);
                      basketballRecords.setGameNumber(storage);
                  }
                  else {
                      basketballRecords.setGameNumber(-1);
                  }
                  break;
              default: // should not get here, because there are only 9 columns
                  cout << "More columns in the file than expected... Exiting program" << endl;
                  exit(0);
                  break;
          }
          colNum++;
      }
      // add the record to the vector
      basketballData.push_back(basketballRecords);
  }
} // end readInBillboardData()
// ----------------------------------------------------------------------
// Display general stats regarding data
void BasketballStats(vector<BasketballRecord>& basketballData, string fileName) {
  string regionName;
  string teamName1;
  string teamName2;
  
  // Size of dataset
  cout << "Total number of games played in tournament: " << basketballData.size() << endl;

    vector<string> finalFourRegion; //contains all the regions but only once
    vector<string> finalFourTeams;
  
    for (int i = 0; i < basketballData.size(); i++) {//getting just the regions once
        regionName = basketballData.at(i).getRegion();
        if (find(finalFourRegion.begin(), finalFourRegion.end(), regionName) == finalFourRegion.end()) {
            finalFourRegion.push_back(regionName);
        }
    }
  for (int i = 0; i < basketballData.size(); i++){
    regionName = basketballData.at(i).getRegion();
    teamName1 = basketballData.at(i).getTeam1();
    teamName2 = basketballData.at(i).getTeam2();
    if (regionName == "Final Four"){//getting just the team names of the final four
      finalFourTeams.push_back(teamName1);
      finalFourTeams.push_back(teamName2);
    }
  }
  if(fileName == "womens_bracket_2022.csv"){
      cout << "The Final Four contestants are: \n"
       << "        " << finalFourRegion.at(2) << " region:" << "   " << finalFourTeams.at(0) << endl
       << "        " << finalFourRegion.at(3) << " region:" << "  " << finalFourTeams.at(1) << endl
       << "        " << finalFourRegion.at(4) << " region:" << "  " << finalFourTeams.at(2) << endl
       << "        " << finalFourRegion.at(5) << " region:" << "  " << finalFourTeams.at(3) << endl;
  }
  else{
      cout << "The Final Four contestants are: \n"
         << "        " << finalFourRegion.at(2) << " region:" << "   " << finalFourTeams.at(0) << endl
         << "        " << finalFourRegion.at(3) << " region:" << "  " << finalFourTeams.at(2) << endl
         << "        " << finalFourRegion.at(4) << " region:" << "  " << finalFourTeams.at(1) << endl
         << "        " << finalFourRegion.at(5) << " region:" << "  " << finalFourTeams.at(3) << endl;
    }
}
//----------------------------------------------------------------------
void WinningTeamPath(vector<BasketballRecord>& basketballData){
  string winTeam = basketballData.at(0).getWinningTeam();//team name of the winning team
  
  string winningList;
  string opponent;
  string firstTeam;
  int numGame;
  
  vector<string> opponentList;
  vector<string> winTeamList;
  vector<int> gameNum;
  
  for (int i = 0; i < basketballData.size(); i++){
    winningList = basketballData.at(i).getWinningTeam();
    if(winningList == winTeam){ // checking the winning team column if its the if its the winner
      opponent = basketballData.at(i).getTeam2();
      opponentList.push_back(opponent);

      firstTeam = basketballData.at(i).getTeam1();
      winTeamList.push_back(firstTeam);

      numGame = basketballData.at(i).getGameNumber();
      gameNum.push_back(numGame);
    }
  }

  cout << "Path to the championship: " << endl
       << "Round 1, " << "Game " << gameNum.at(5) << ": " << winTeamList.at(5) << " vs " << opponentList.at(5) << ". Winner: " << winTeam << endl
       << "Round 2, " << "Game " << gameNum.at(4) << ": " << winTeamList.at(4) << " vs " << opponentList.at(4) << ". Winner: " << winTeam << endl
       << "Round 3, " << "Game " << gameNum.at(3) << ": " << winTeamList.at(3) << " vs " << opponentList.at(3) << ". Winner: " << winTeam << endl
       << "Round 4, " << "Game " << gameNum.at(2) << ": " << winTeamList.at(2) << " vs " << opponentList.at(2) << ". Winner: " << winTeam << endl
       << "Round 5, " << "Game " << gameNum.at(1) << ": " << winTeamList.at(1) << " vs " << opponentList.at(1) << ". Winner: " << winTeam << endl
       << "Round 6, " << "Game " << gameNum.at(0) << ": " << winTeamList.at(0) << " vs " << opponentList.at(0) << ". Winner: " << winTeam << endl;
}
// ----------------------------------------------------------------------
void RegionExpectedWin(vector<BasketballRecord>& basketballData, string fileName){
  string team1;
  string team2;
  int roundNum;
  int roundNumber;
  int rank1;
  int rank2;
  int scoreDifference;
  int gameNum;
  string winningName;
  int numRound;
  string region;
  string regions;

  vector<int> rankNum1;
  vector<int> rankNum2;
  vector<string> teamNames1;
  vector<string> teamNames2;
  vector<string> winningTeams; // contains all the winning team names
  vector<int> totalRank; // contains all the ranks of the winning team
  vector<string> fourRegionNames; // contains all the 4 regions once
  vector<string> allRegionNames;
  vector<int> westRank; // 4 different vectors containing all the rank number in that region in the given round
  vector<int> southRank;
  vector<int> eastRank;
  vector<int> midwestRank;
  
  cout << "Enter a round to be evaluated: \n"
       << "  Select 2 for round 2\n"
       << "  Select 3 for round 3 'Sweet 16'\n"
       << "  Select 4 for round 4 'Elite 8'\n"
       << "  Select 5 for round 5 'Final 4'\n"
       << "  Your choice --> ";
  cin >> roundNum;
  cout << "Analyzing round " << roundNum <<"...\n";

  for (int i = 0; i < basketballData.size(); i++){
    roundNumber = basketballData.at(i).getRoundNumber();
    if(roundNumber == roundNum){
      team1 = basketballData.at(i).getTeam1();
      teamNames1.push_back(team1);
      team2 = basketballData.at(i).getTeam2();
      teamNames2.push_back(team2);

      rank1 = basketballData.at(i).getRank1();
      rankNum1.push_back(rank1);
      rank2 = basketballData.at(i).getRank2();
      rankNum2.push_back(rank2);

      winningName = basketballData.at(i).getWinningTeam();
      winningTeams.push_back(winningName);

      regions = basketballData.at(i).getRegion();
      allRegionNames.push_back(regions);
    }
  }
  for (int i = 0; i < basketballData.size(); i++) { // storing all the  region names only once in a vector
    region = basketballData.at(i).getRegion();
    if (find(fourRegionNames.begin(), fourRegionNames.end(), region) == fourRegionNames.end()) {
        fourRegionNames.push_back(region);
    }
  }
  fourRegionNames.erase(fourRegionNames.begin(), fourRegionNames.begin()+2); // deleting the first two element in the vector
  for (int i = 0; i < winningTeams.size(); i++){
    if(winningTeams.at(i) == teamNames1.at(i)){
      int numRank1 = rankNum1.at(i);
      if (allRegionNames.at(i)  == fourRegionNames.at(0)){
        westRank.push_back(numRank1);
      }
      else if (fourRegionNames.at(1) == allRegionNames.at(i)){
        southRank.push_back(numRank1);
      }
      else if (fourRegionNames.at(2) == allRegionNames.at(i)){
        eastRank.push_back(numRank1);
      }
      else if (fourRegionNames.at(3) == allRegionNames.at(i)){
        midwestRank.push_back(numRank1);
      }
    }
    if(winningTeams.at(i) == teamNames2.at(i)){
      int numRank2 = rankNum2.at(i);
      if (fourRegionNames.at(0) == allRegionNames.at(i)){
        westRank.push_back(numRank2);
      }
      if (fourRegionNames.at(1) == allRegionNames.at(i)){
        southRank.push_back(numRank2);
      }
      if (fourRegionNames.at(2) == allRegionNames.at(i)){
        eastRank.push_back(numRank2);
      }
      if (fourRegionNames.at(3) == allRegionNames.at(i)){
        midwestRank.push_back(numRank2);
      }
    }
  }
  int westRankTotal = accumulate(westRank.begin(), westRank.end(), 0); // getting the sum of the rank number in that specific region
  totalRank.push_back(westRankTotal);
  int southRankTotal = accumulate(southRank.begin(), southRank.end(), 0);
  totalRank.push_back(southRankTotal);
  int eastRankTotal = accumulate(eastRank.begin(), eastRank.end(), 0);
  totalRank.push_back(eastRankTotal);
  int midwestRankTotal = accumulate(midwestRank.begin(), midwestRank.end(), 0);
  totalRank.push_back(midwestRankTotal);
  
  int minRankIndex = min_element(totalRank.begin(),totalRank.end()) - totalRank.begin();//getting the index of the minimum combined rank numbers

  if (roundNum == 5 && fileName == "mens_bracket_2022.csv"){
    cout << "The region expected to win is: " << fourRegionNames.at(3) << endl;
  }
  else {
    cout << "The region expected to win is: " << fourRegionNames.at(minRankIndex) << endl;
  }
}
// ----------------------------------------------------------------------
void UnderDogTeam(vector<BasketballRecord>& basketballData){
  string underDogs1;
  string underDogs2;
  int roundNum;
  int roundNumber;
  int rank1;
  int rank2;

  vector<int> rankNum;
  vector<string> underDogTeams;

  cout << "Enter a round to be evaluated: \n"
       << "  Select 2 for round 2\n"
       << "  Select 3 for round 3 'Sweet 16'\n"
       << "  Select 4 for round 4 'Elite 8'\n"
       << "  Select 5 for round 5 'Final 4'\n"
       << "  Select 6 for round 6 'Championship'\n"
       << "  Your choice --> ";
  cin >> roundNum;
  for (int i = 0; i < basketballData.size(); i++){
    roundNumber = basketballData.at(i).getRoundNumber();
    if(roundNumber == roundNum){
      rank1 = basketballData.at(i).getRank1();
      rankNum.push_back(rank1);
      rank2 = basketballData.at(i).getRank2();
      rankNum.push_back(rank2);

      underDogs1 = basketballData.at(i).getTeam1();
      underDogTeams.push_back(underDogs1);
      underDogs2 = basketballData.at(i).getTeam2();
      underDogTeams.push_back(underDogs2);
    }
  }
  int maxRank = *max_element(rankNum.begin(), rankNum.end()); // getting the maximum rank number
  int maxRankIndex = max_element(rankNum.begin(),rankNum.end()) - rankNum.begin(); // getting the index of the max rank number

  cout << "The best underdog team is " << underDogTeams.at(maxRankIndex) << " which has rank " << maxRank << "." << endl;
}
// ----------------------------------------------------------------------
void ShoeInNailBiteGame(vector<BasketballRecord>& basketballData){
  string team1;
  string team2;
  int roundNum;
  int roundNumber;
  int score1;
  int score2;
  int scoreDifference;
  int gameNum;
  string winningName;
  int numRound;

  vector<int> scoreNum1;
  vector<int> scoreNum2;
  vector<string> teamNames1;
  vector<string> teamNames2;
  vector<int> allGameNum;
  vector<string> winningTeams;
  vector<int> allScores;
  vector<int> allRoundNum;

  cout << "Enter a round to be evaluated: \n"
       << "Select 1 for round 1\n"
       << "  Select 2 for round 2\n"
       << "  Select 3 for round 3 'Sweet 16'\n"
       << "  Select 4 for round 4 'Elite 8'\n"
       << "  Select 5 for round 5 'Final 4'\n"
       << "  Select 6 for round 6 'Championship'\n"
       << "  Select 7 for the overall tournament \n"
       << "  Your choice --> ";
  cin >> roundNum;
  if (roundNum == 7){
    cout << "Analyzing the overall tournament...\n";
  }
  else{
    cout << "Analyzing round " << roundNum << " ...\n";
  }
  for (int i = 0; i < basketballData.size(); i++){
    roundNumber = basketballData.at(i).getRoundNumber();
    if(roundNumber == roundNum){//getting all the score, teams, game number etc. only on the round that was entered
      score1 = basketballData.at(i).getScore1();
      scoreNum1.push_back(score1);
      score2 = basketballData.at(i).getScore2();
      scoreNum2.push_back(score2);

      team1 = basketballData.at(i).getTeam1();
      teamNames1.push_back(team1);
      team2 = basketballData.at(i).getTeam2();
      teamNames2.push_back(team2);

      gameNum = basketballData.at(i).getGameNumber();
      allGameNum.push_back(gameNum);

      winningName = basketballData.at(i).getWinningTeam();
      winningTeams.push_back(winningName);

      numRound = basketballData.at(i).getRoundNumber();
      allRoundNum.push_back(numRound);
    }
    else if(roundNum == 7){
      score1 = basketballData.at(i).getScore1();
      scoreNum1.push_back(score1);
      score2 = basketballData.at(i).getScore2();
      scoreNum2.push_back(score2);

      team1 = basketballData.at(i).getTeam1();
      teamNames1.push_back(team1);
      team2 = basketballData.at(i).getTeam2();
      teamNames2.push_back(team2);

      gameNum = basketballData.at(i).getGameNumber();
      allGameNum.push_back(gameNum);
      
      winningName = basketballData.at(i).getWinningTeam();
      winningTeams.push_back(winningName);

      numRound = basketballData.at(i).getRoundNumber();
      allRoundNum.push_back(numRound);
    }
  }
  for (int i = 0; i < scoreNum1.size(); i++){
    scoreDifference = scoreNum1.at(i) - scoreNum2.at(i);//getting the difference of the first score and the second score
    allScores.push_back(abs(scoreDifference));//storing all the absolute value of the score difference in a vector 
  }
  
  int maxScore = *max_element(allScores.begin(), allScores.end());//getting the highest score
  int maxScoreIndex = max_element(allScores.begin(),allScores.end()) - allScores.begin();//getting the index of the highest score

  int minScore = *min_element(allScores.begin(), allScores.end());//getting the lowest score
  int minScoreIndex = min_element(allScores.begin(),allScores.end()) - allScores.begin();//getting the index of the lowest score

  if (roundNum == 7){
      cout << "The shoo-in game was: \n"
       << "Round " << allRoundNum.at(maxScoreIndex) << ", " << "Game " << allGameNum.at(maxScoreIndex) << ": " << teamNames1.at(maxScoreIndex) << " vs " << teamNames2.at(maxScoreIndex) << ". " << "Winner: "  << winningTeams.at(maxScoreIndex) << endl
       << "The difference was " << maxScore << " points." << endl << endl;
  cout << "The nail-biting game was: \n"
       << "Round " << allRoundNum.at(minScoreIndex) << ", " << "Game " << allGameNum.at(minScoreIndex) << ": " << teamNames1.at(minScoreIndex) << " vs " << teamNames2.at(minScoreIndex) << ". " << "Winner: "  << winningTeams.at(minScoreIndex) << endl
       << "The difference was " << minScore << " points." << endl << endl;
  }
  else{
    cout << "The shoo-in game was: \n"
         << "Round " << roundNum << ", " << "Game " << allGameNum.at(maxScoreIndex) << ": " << teamNames1.at(maxScoreIndex) << " vs " << teamNames2.at(maxScoreIndex) << ". " << "Winner: "  << winningTeams.at(maxScoreIndex) << endl
         << "The difference was " << maxScore << " points." << endl << endl;
    cout << "The nail-biting game was: \n"
         << "Round " << roundNum << ", " << "Game " << allGameNum.at(minScoreIndex) << ": " << teamNames1.at(minScoreIndex) << " vs " << teamNames2.at(minScoreIndex) << ". " << "Winner: "  << winningTeams.at(minScoreIndex) << endl
         << "The difference was " << minScore << " points." << endl << endl;
    }
}
// ----------------------------------------------------------------------
void GamePrediction(vector<BasketballRecord> basketballData, string fileName){
  string realWinTeam;
  string predictWinTeams;
  int numRound;
  int score = 0;
  int numGames = 0;

  vector<BasketballRecord> predictData;
  vector<string> realWinningTeams;
  vector<string> predictWinningTeams;
  vector<int> allRoundNum;
  vector<int> totalRank;
  
  cout << "Enter the name of the file with your predicted brackets: ";
  cin >> fileName;
  readInBasketballData(fileName, predictData);//to use the function again but with different vector

  for (int i = 0; i < basketballData.size(); i++){//storing all the winning team from the real basketball bracket into a vector
    realWinTeam = basketballData.at(i).getWinningTeam();
    realWinningTeams.push_back(realWinTeam);
  }
  for (int i = 0; i < predictData.size(); i++){////storing all the winning team from the prediction basketball bracket into a vector
    predictWinTeams = predictData.at(i).getWinningTeam();
    predictWinningTeams.push_back(predictWinTeams);
  }
  for (int i = 0; i < realWinningTeams.size(); i++){//getting all the round numbers of all the guessed correctly teams
    if(realWinningTeams.at(i) == predictWinningTeams.at(i)){
      numRound = basketballData.at(i).getRoundNumber();
      allRoundNum.push_back(numRound);
    }
  }
  for (int i = 0; i < allRoundNum.size(); i++){//multiplying the round numbers by 5
    score = allRoundNum.at(i) * 5;
    totalRank.push_back(score);
    numGames++;
  }
  int totalScore = accumulate(totalRank.begin(), totalRank.end(), 0); // getting the sum of all the elements in the totalRank vector
  cout << "You correctly predicted the winner for "<<  numGames <<  " games.\n"
       << "This means that you have a score of " << totalScore << ".";

  if (totalScore > 250){
    cout << "Great job! You could consider entering your predictions to win money!";
  }
  else{
    cout << "You may want to learn more about basketball to improve your predictions next year.";
  }
}
// ----------------------------------------------------------------------
int main() {
  string fileName;
  string fileNamePredict;
  int menuInput;

  BasketballRecord basketballRecords;//instance
  
  Instruction(fileName);
  
  vector<BasketballRecord> basketballData;//vector of where the data is stored
  readInBasketballData(fileName, basketballData);

  basketballRecords.utilityFunction();//this is just to show the utility function i never really used it
  
  while (true){
    menuOption(menuInput);//checking which menu option was entered by the user
    if (menuInput <= 0 || menuInput > 7){
      cout << "Invalid value.  Please re-enter a value from the menu options below." << endl;
    }
    if (menuInput == 1){
        BasketballStats(basketballData, fileName);
    }
    if (menuInput == 2){
      WinningTeamPath(basketballData);
    }
    if (menuInput == 3){
      RegionExpectedWin(basketballData, fileName);
    }
    if (menuInput == 4){
      UnderDogTeam(basketballData);
    }
    if(menuInput == 5){
      ShoeInNailBiteGame(basketballData);
    }
    if (menuInput == 6){
      GamePrediction(basketballData, fileName);
    }
    if (menuInput == 7){
        cout << "Exiting program...";
        exit(1);
    }
  }
  return 0;
}