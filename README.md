Compile:g++ Battlefield.cpp Grid.cpp Items.cpp Lists.cpp Livings.cpp Market.cpp Spells.cpp main.cpp -o game.out (name of "name".out can be changed)

Run:game.out

Player decides how many heroes the game consists of.
The Grid is a 10x10 table with predefined object positions.
Player decides each next move for each hero. This is done by changing the values of lastmovei and lastmovej in main function.
Each hero is initialized with default values (implemented in main function) and saved in an array which consists of objects heroes.
If a hero moves to a "shared" cell there is a possibility of fighting. If there is fighting at this cell, monsters are automatically created and their stats are initialized depending on first hero's stats.
There is also a Market with many items! Find the best combinations of items to increase your chances of defeating the monsters!
For more in depth documentation check the comments in files.
