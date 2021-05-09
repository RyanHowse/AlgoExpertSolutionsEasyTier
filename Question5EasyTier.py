def nonConstructibleChange(coins):
  #we need a return value
	minimumChange = 0
	
	#we'll use a flag to determine if we need to do things the long way or if one of the short edge cases is true
	doTheMath = True
	
 	#first lets sort the coins vector
	coins = sorted(coins)
	
	#3let's handle some edge cases!
	#A couple of if's can save us some looping later; let's not do the math if we don't have to
	#if the lowest amount is also the highest amount, the lowest amount is the sum of all values + 1
	if len(coins) > 1:
		if coins[0] == coins[len(coins)-1]:
			doTheMath = False
			minimumChange = sum(coins, 0) + 1
			
	#if we have no coins OR 1 coin, the lowest will be 1
	if len(coins) == 0:
		minimumChange = 1
		doTheMath = False
	if len(coins) == 1:
		doTheMath = False
		#unless we have 1 coin with value 1, which case 2 is the answer
		if coins[0] > 1:
			minimumChange = 1
		else:
			minimumChange = 2

	#if doTheMath is still true, lets do some math
	#i'm using a while loop, so i'll have a variable for iteration
	currentIndex = 0
	#and a running total
	runningTotal = 0
	
	while doTheMath:
		#this keeps us from going out of bounds
		if len(coins) > currentIndex + 1:
			#check if the current running total + the current index is greater than the next index
			#example: running total = 3, current index value is 4, next index value is 9
			#3 + 4 = 7, next value is 9, this means the minimum change we cannot make is 8
			if (runningTotal + coins[currentIndex] + 1) >= coins[currentIndex+1]:
				#update our running total
				runningTotal = runningTotal + coins[currentIndex]
				#increment index and keep going
				currentIndex = currentIndex + 1
			else:
				#we have found the minimum! Only triggers if the minimum is between the values at coins[0] and coins[n]
				minimumChange = runningTotal + coins[currentIndex] + 1
				doTheMath = False
		else:
			minimumChange = sum(coins, 0) + 1
			doTheMath = False
					
  return minimumChange
