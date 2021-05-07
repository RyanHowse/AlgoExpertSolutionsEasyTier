def tournamentWinner(competitions, results):
    #we need a winner list
	winners = []
	#and a loop counter
	getWinnersCount = 0
	
	#first we'll dump every winner to a seperate list
	for i in results:
		if results[getWinnersCount] == 1:
			winners.insert(0, competitions[getWinnersCount][0])
		else:
			winners.insert(0, competitions[getWinnersCount][1])
		getWinnersCount = getWinnersCount + 1
	
	#then we sort it into alphabetical order so all of each language are grouped
	sortedWinners = sorted(winners)
	
	#next we just count how many of each winner there are
	#for that we need some counters
	currentWinner = ""
	currentHighScore = 0
	currentLang = ""
	currentScore = 0
	
	#lets reuse this counter
	getWinnersCount = 0
	
	for i in sortedWinners:
		if currentLang == sortedWinners[getWinnersCount]:
			currentScore = currentScore + 1
		else:
			#before we start counting for a new language, check to see if the previous language beat the highscore
			if currentScore > currentHighScore:
				currentHighScore = currentScore
				currentWinner = currentLang
			currentLang = sortedWinners[getWinnersCount]
			currentScore = 1
		getWinnersCount = getWinnersCount + 1
	
	#this extra check fixes scenarios where the last sorted language wins
	#and scenarios where there is only one contest
	#placing it here lets us elminate it from 2 places in the loop, saving checks
	if currentScore > currentHighScore:
		currentHighScore = currentScore
		currentWinner = currentLang
	
  return currentWinner
