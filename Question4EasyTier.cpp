//Ryan Howse
//5/7/2021
//determine the winner of a round robin style tournament

#include <vector>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
	
	//we need a winner vector
	vector<string> winners = {};
	
	//first we'll dump every winner to a seperate vector
  for(int i = 0; i < results.size(); i++){
		if(results[i] == 1){
			winners.insert(winners.begin(), competitions[i][0]);
		}
		else{
			winners.insert(winners.begin(), competitions[i][1]);
		}
	}
	
	//then we sort it into alphabetical order so all of each language are grouped
	sort(winners.begin(), winners.end());
	
	//next we just count how many of each winner there are
	//for that we need some counters
	string currentWinner = "";
	int currentHighScore = 0;
	string currentLang = "";
	int currentScore = 0;
	
	for(int i = 0; i < winners.size(); i++){
		if(currentLang == winners[i]){
			currentScore++;
		}
		else{
			//before we start counting for a new language, check to see if the previous language beat the highscore
			if(currentScore > currentHighScore){
				currentHighScore = currentScore;
				currentWinner = currentLang;
			}
			currentLang = winners[i];
			currentScore = 1;
		}
	}
	
	//this extra check fixes scenarios where the last sorted language wins
	//and scenarios where there is only one contest
	//placing it here lets us elminate it from 2 places in the loop, saving checks
	if(currentScore > currentHighScore){
		currentHighScore = currentScore;
		currentWinner = currentLang;
	}
	
  return currentWinner;
}
