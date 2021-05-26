#Ryan Howse
#5/26/2021
#Pairing riders on a tandem bicycle to produce the fastest
#or slowest total speed, determined by the given boolean

def tandemBicycle(redShirtSpeeds, blueShirtSpeeds, fastest):
	#first we need a running total for the return variable
	totalSpeed = 0
	
    	#in order to do this, we have to sort the first vector in ascending order
	#whether we sort the second in ascending or descending depends
	#on whether we want the fastest or slowest possible speed total
	#basically to get the fastest speed possible, we want to pair the fastest people
	#with the slowest people
	redShirtSpeeds.sort()
	if fastest:
		blueShirtSpeeds.sort(reverse=True)
	else:
		blueShirtSpeeds.sort()
	
	#now we simply need to compare them and take the fastest of each pair
	#to calculate the total speed
	for i, j in zip(redShirtSpeeds, blueShirtSpeeds):
		if i >= j:
			totalSpeed = totalSpeed + i
		else:
			totalSpeed = totalSpeed + j
			
	return totalSpeed
