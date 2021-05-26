#Ryan Howse
#5/26/2021
#Can a class take a photo if everyone wearing one coloured shirt is in the back,
#everyone wearing another is in the front, and everyone in the back must be
#taller than the person in front of them?

def classPhotos(redShirtHeights, blueShirtHeights):
	#First we need a return variable, in this case a boolean
	#to determine if a photo with the current class makeup is possible
	#under the given rules
	#it will become false if conditions are not met
	isPossible = True
	#and a flag to check the alternate case if needed
	checkOtherCase = False
	
	#first lets sort both vectors in ascending order
	#if the students of both rows in height order do not satisfy the
	#conditions, then theres is no arrangement of students that will work
	redShirtHeights.sort()
	blueShirtHeights.sort()
	
	#now we'll iterate through each array and see if the person in
	#index i is taller than the person in index i of the other array
	#if one is false then we flip the arrays to see if it works to have the
	#people in the back row stand in the front row instead
	#if we get a false from both attempts then the class cannot take a photo
	#with the given rules, and the function will return isPossible = false;
	for i,j in zip(redShirtHeights, blueShirtHeights):
		if i <= j:
			#someone in the back row is shorter or of equal height to the person in front of them, 
			#so try to flip the rows
			checkOtherCase = True
			#stop checking for efficiency sake
			break
	
	#we only do this if there was a problem with the first case
	if checkOtherCase:
		for i,j in zip(blueShirtHeights, redShirtHeights):
			if i <= j:
				#at this point both cases have failed, and the photo is not possible
				isPossible = False
				#stop checking for efficiency sake
				break

	return isPossible;
