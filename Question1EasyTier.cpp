//Ryan Howse
//5/5/2021
//Determines whether there is a valid sequence within a given array

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  //we have a variable for the next valid number in the sequence
  int nextNumberToFind;
  //we have a variable for what point in the sequence array we're at
  int nextSequenceIndex = 0;
  //set the nextNumberToFind as the first number in the sequence array
  nextNumberToFind = sequence[nextSequenceIndex];
  //we need a variable to save our return value for OOP standards
  //it starts off as false, and if the sequence becomes valid, it will be true
  bool sequenceIsValid = false;

  for(int i = 0; i < array.size(); i++){
    if(nextNumberToFind == array[i]){
      //this triggers if there is another number left to be looked for
      if(nextSequenceIndex < sequence.size()-1){
        nextSequenceIndex++;
        nextNumberToFind = sequence[nextSequenceIndex];
      }
      else{
        //this triggers if all values in the sequence array have appeared
        //in the data array, in order
        sequenceIsValid = true;
      }
    }
  }
  return sequenceIsValid;
}
