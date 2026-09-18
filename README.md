

# Overview
Simulate a horse race with 5 horses on a 15-character track using an
array of integers to track positions. The race continues, one coin-flip
turn at a time, until at least one horse reaches the end.

# Functions

## advance

* Take in a horse number and a pointer to the horses array
* Flip a coin using randomization (0 or 1)
* If the result is heads, increase the value at that horse's position by one
* If the result is tails, leave the value unchanged

## printLane

* Take in a horse number and a pointer to the horses array
* Loop through each position on the track, from the first to the last
* If the current loop position matches the horse's current value in the
  array, print the horse's number
* Otherwise, print a dot
* After the loop ends, move to a new line

## isWinner

* Take in a horse number and a pointer to the horses array
* Check if the value at that horse's position is greater than or equal
  to the last position on the track
* Return true if so, return false otherwise

## main

* Create an array of 5 integers, all starting at 0, representing horse positions
* Create a variable to track whether the race has been won, starting as false
* Loop continuously while no one has won:
    * Inner loop: for each horse from the first to the last
        * Call advance on that horse
        * Call printLane on that horse to show its updated position
    * Inner loop: for each horse from the first to the last
        * Call isWinner on that horse
        * If true, mark the race as won and print a message announcing
          that horse as the winner
    * If the race has not been won yet, print "Press enter for another
      turn" and wait for the user to press Enter before continuing
