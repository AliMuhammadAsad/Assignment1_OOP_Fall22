# Assignment1_OOP_Fall22
This contains our first homework for OOP in which we had to design a game.

To run the game, go on seeplusia.cpp and press f5 / run it on vscode etc and play the game. Make sure to read the rules of the game.

//**Legend of SeePlusia**

Prince Lazy has been captured by an evil wizard. You are Zeldana, a female warrior who takes it upon yourself to rescue the prince and return him to his
family. You go off on a quest through the dangerous world of SeePlusia to search for the four mythical crystals of Objectos. Together the crystals will
give you the power to defeat the wizard and rescue Prince Lazy. The world of SeePlusia is shown in Fig. assests. It shows the different locations in the
world. The direction of travel between locations is given by an arrow and the number of apples required to travel from one location to other are also
shown.

The rules of the game of Legend of SeePlusia are as follows:
- You begin at Enchanted Forest on the first day with 20 apples.
- You have to save Prince Lazy who is held captive at Wizard’s Castle.
- At each location you can only go in one of four directions: north, south,
east, west.
- If a direction is not shown on the map, it’s an invalid move, e.g. north
from Marsh of the Undead. An invalid move uses up the move and
consumes one apple.
- A valid move consumes the number of apples as drawn on the arrow,
e.g. to travel from Enchanted Forest to Wampire Cove, three apples
are consumed.
- Before rescuing the prince, you have to collect all four objectos crystals
from the indicated locations.
- An objectos crystal is automaticaly retrieved when you arrive at its
location.
- Once you retrieve a crystal, it is no longer present at that location.
- If you arrive at Sands of Quick, you slowly sink into quicksand and die
and the game is Lost.
- You cannot move past Bridge of Death to Wizard’s Castle unless you
have all four crystals.
0 You cannot move past Eisten Tunnel unless you have at least three
crystals. You need 10 apples to reach Wizard’s Castle from Eisten
Tunnel. Call moveNorth twice to make a longer jump.
- Once you reach Wizard’s Castle, the Prince is rescued and the game is
Won.
- You can add 6 apples to your life by visiting Apples Orchard.
- If you run out of food before rescuing the prince, you die of starvation
and the game is Lost.


The Code provides the implementation of the game logic, the backend handling etc abt various stuff was given already.
