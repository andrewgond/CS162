1. Your name and ONID
    Andrew Gondoputro 
    934509117

2. Description: One paragraph advertising what your program does (for a user who knows
nothing about this assignment, does not know C++, and is not going to read your code).
Highlight any special features.

    This program is the game called "Hunt the Wumpus". The player takes over an adventurer on a 2D
    map hunting searching for the hiddent gold in a cave system that is adjusted to difficulty. When the
    player starts, their original position is their rope to return to when they have found the gold hidden
    somewhere on the map. The user is not able to see anything but the position of the player on the map 
    but when they are near a room that has an event they are given a precept that tells them what might be
    in an adjacent room. The different events a user can interact with are: stalactites that have a 50% of killing
    the user when entered, pools which when entered will let the player traverse the map until they run out of oxygen
    without interacting with the events in the room, gold which can be picked up as the win condition, and the 
    wumpus which is an automatic death when touched. In each map there are 2 pools, 2 stalactites, 1 gold, and 1 wumpus
    randomly places across the map. The user can also kill the wumpus by shooting arrows to hunt it, with every 
    missed arrow having a 75% chance of waking up the wumpus from its room and moving it somewhere else in the map. 
    The end goal is to avoid all hazards and bring the gold back to the starting position. 

3. Instructions: Step-by-step instructions telling the user how to compile and run your
program. If you expect a certain kind of input at specific steps, inform the user what the
requirements are. Include examples to guide the user.
    The user must be on a command line base interface with linux commands. They should go to the
    directiory with all the .h and .cpp files and run the makefile with the command make. This should
    then create more files with the important one being ./wumpus. By calling ./wumpus in the terminal 
    the user will the start the program and play the game.


4. Limitations: Describe any known limitations for things the user might want or try to do
but that program does not do/handle.
    If the user does an improper input the terminal will print out that there was an invalid input
    and then reprompt the user with the correct options/inputs. 

5. (Part 2 only) Extra credit: If your program includes extra credit work, describe it here for
the user.
    Extra credit 5pts - Prompt the user to play again. This extra credit just makes it so that when the user
    ends the game either by winning or by dying to a hazard, they will be prompted with three options 
    to continue, or quit with different map layouts

    Extra credit 10pts - New Event called Armor. This armor raises the player's HP by two so they can take
    two fatal hits without dying.

6. Your answers to the following questions:
a. For part 1 (Hunt the Wumpus), what is the hierarchy of the classes? Which
classes represent a “has-a” relationship, which classes represent an “is-a”
relationship?
    hierarchy of the classes:
        game class 
            has: an array room objects
        Room class
            has: event (and all derived classes)
        Event class:
            children:
                gold
                    is a: event
                wumpus
                    is a: event
                pool
                    is a: event
                armor 
                    is a: event
                stalactites
                    is a: event


b. For part 1 (Hunt the Wumpus), which function(s) did you make virtual? Pure
virtual? Please explain why.
    The functions I made virtual for hunt the wumpus are print_precept() and inteaction(bool) from the Event
    parent class. This means every derived event class needed to implement their own print precept for the user
    and their own unique interaction for the game. They were better as virtual because the Event class would not be
    a base object with a default operation for those functions.

c. Did you implement the Big 3 for any classes? If yes, why? If not, why not?
    I only implemented all of the BIG 3 for the Room objects, but I had destructors for the game and event classes.
    For the Room objects, because in the project so many of them were called in an array by doing the big three they were
    easier to manage and move around with copy constructors and =. The destructors were useful for managing memory with delete
    while vectors just kind of helped with this by managing the memory when out of scope.

d. For part 2 (Recursive stair problem), what is your thought process when designing
the recursive function? How did you determine the base case and recursive call(s)
for your function?
    For the recursive stair problem I thought of how many ways from a given stair can get to a goal stair. Since the biggest 
    jump was 3, I made three base cases in which to get to that goal from three different steps below it and how many combinations
    there were from there. I then thought about it recursively and how to add from the previous steps and in combination to get 
    ways_to_top(n-1) + ways_to_top(n-2) + ways_to_top(n-3). The base cases were how those original three steps can go up to the goal
    added together. 

e. In this assignment, which requirement did you find most challenging? How did you
overcome it? What would you do differently if given a second chance? 
    In this assignment the hardest part would be interacting with the objects from the game class. This is because
    while using functions in the individual room and event classes, you can't mess with the private variables outside
    of the scope. I think I found a clever way of doing this by using ints and matching specific outputs to be able to do
    specific operations in the game class like changing the is_alive variable or such. If given a second chance I would probably
    spend more time optimizing these functions so they didn't take so much repetition in code. 