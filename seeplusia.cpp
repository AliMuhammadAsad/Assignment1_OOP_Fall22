#include "seeplusia.hpp"
#include "mover.hpp"

int applesLeft = 20, nCrystalsFound = 0;
string gameState  = "Running";

string currentState = "Enchanted Forest";
int c_marsh = 0; int c_swamps = 0; int c_werewolf = 0; int c_eisten = 0;
//Implementation of Logic

void makeMove(string direction){
	if (applesLeft <=0){ gameState = "Lost"; } //game lost when apples are 0 or less - death by starvation(yikes)
	
	if (direction == "East"){ 
		if(currentState == "Enchanted Forest" && applesLeft >= 1)
		{
			moveEast(); currentState = "Sands of Quick"; //move east from Enchanted Forest to Sands of quick
			gameState = "Lost"; applesLeft = 0;
		}
		else if (currentState == "Swamps of Despair" && applesLeft >= 1){
			moveEast(); currentState = "Wampire Cove";  //east to Wampire Cove from Swamps
			applesLeft -= 1; gameState = "Running";
		}
		else if (currentState == "Wampire Cove" && applesLeft >= 1){
			moveEast(); currentState = "Marsh of Undead";  //East to Marsh from Wampire
			applesLeft -= 1; gameState = "Running";
			if (c_marsh == 0){
				nCrystalsFound += 1; c_marsh += 1; //Check if crystal is found, if not then add it and mark it found
			}
		}
		else if (currentState == "Eisten Tunnel" && applesLeft >= 2){
			// if (applesLeft < 2){gameState = "Lost";}
			moveEast(); currentState = "Elvin Waterfall";  //Eisten tunnel to Elvin Waterfall (U get the idea by this point)
			applesLeft -= 2; gameState = "Running";
		} 
		else if (currentState == "Elvin Waterfall" && applesLeft >= 2){
			// if (applesLeft < 2){gameState = "Lost";}
			moveEast(); currentState = "Werewolf Hill"; 
			applesLeft -= 2; gameState = "Running";
			if (c_werewolf == 0){
				nCrystalsFound += 1; c_werewolf += 1;
			}
			
		}
		//Checks if can't move east, then won't change gamestate and reduce number of apples by 1
		else if (currentState == "Werewolf Hill"){applesLeft -= 1;}
		else if (currentState == "Marsh of Undead"){applesLeft -= 1;}
		else if (currentState == "Apples Orchard"){applesLeft -= 1;}
		else if (currentState == "Bridge of Death"){applesLeft -= 1;}
		else {gameState = "Lost";}
	}
	//This concludes our East Direction i think, moving on

	//Moving on to Direction West
	if (direction == "West" && applesLeft >= 1){
		if (currentState == "Bridge of Death" && nCrystalsFound == 4 && applesLeft >= 5){
			moveWest(); currentState = "Wizards Castle"; //Moves West to move west obviously
			applesLeft -= 5; gameState = "Won"; //Wins by reaching Wizards Castle and saves Prince Lazy (Students also need saving now xD)
		}
		else if (currentState == "Wampire Cove" && applesLeft >= 1){
			moveWest(); currentState = "Swamps of Despair";
			applesLeft -= 1; gameState = "Running";
			if (c_swamps == 0){
				nCrystalsFound += 1; c_swamps += 1;
			}
		}
		else if (currentState == "Marsh of Undead" && applesLeft >= 1){
			moveWest(); currentState = "Wampire Cove";
			applesLeft -= 1; gameState = "Running";
		}
		else if (currentState == "Elvin Waterfall" && applesLeft >= 2){
			moveWest(); currentState = "Eisten Tunnel";
			applesLeft -= 2; gameState = "Running";
			if (c_eisten == 0){
				nCrystalsFound += 1; c_eisten += 1;
			}
		}
		else if (currentState == "Werewolf Hill" && applesLeft >= 2){
			moveWest(); currentState = "Elvin Waterfall";
			applesLeft -= 2; gameState = "Running";
		}
		else if (currentState == "Apples Orchard" && applesLeft >= 1){
			moveWest(); currentState = "Werewolf Hill";
			applesLeft -= 1; gameState = "Running";
			if (c_werewolf == 0){
				nCrystalsFound += 1; c_werewolf += 1;
			}
		}
		else if (currentState == "Enchanted Forest"){applesLeft -= 1;}
		else if (currentState == "Swamps of Despair"){applesLeft -= 1;}
		else if (currentState == "Eisten Tunnel"){applesLeft -= 1;}
	}

	if (direction == "North" && applesLeft >= 1){
		if (currentState == "Swamps of Despair" && applesLeft >= 1){
			moveNorth(); currentState = "Bridge of Death";
			applesLeft -= 1; gameState = "Running";
		}
		else if (currentState == "Wampire Cove" && applesLeft >= 3){
			moveNorth(); currentState = "Enchanted Forest";
			applesLeft -= 3; gameState = "Running";
		}
		else if (currentState == "Werewolf Hill" && applesLeft >= 3){
			moveNorth(); currentState = "Wampire Cove";
			applesLeft -= 3; gameState = "Running";
		}
		else if (currentState == "Eisten Tunnel" && applesLeft >= 10 && nCrystalsFound == 4){
			moveNorth(); moveNorth(); currentState = "Wizards Castle";
			applesLeft -= 10; gameState = "Won";
		}
		else if (currentState == "Bridge of Death"){applesLeft -= 1;}
		else if (currentState == "Enchanted Forest"){applesLeft -= 1;}
		else if (currentState == "Marsh of Undead"){applesLeft -= 1;}
		else if (currentState == "Apples Orchard"){applesLeft -= 1;}
		else if (currentState == "Elvin Waterfall"){applesLeft -= 1;}
		else {gameState = "Lost";}
	}

	if (direction == "South" && applesLeft >= 1){
		if (currentState == "Enchanted Forest" && applesLeft >= 3){
			moveSouth(); currentState = "Wampire Cove";
			applesLeft -= 3; gameState = "Running";
		}
		else if (currentState == "Wampire Cove" && applesLeft >= 3){
			moveSouth(); currentState = "Werewolf Hill";
			applesLeft -= 3; gameState = "Running";
			if (c_werewolf == 0){
				nCrystalsFound += 1; c_werewolf += 1;
			}
		}
		else if (currentState == "Marsh of Undead" && applesLeft >= 1){
			moveSouth(); currentState = "Apples Orchard";
			applesLeft -= 1; applesLeft += 6; gameState = "Running";
		}
		else if (currentState == "Bridge of Death"){applesLeft -= 1;}
		else if (currentState == "Swamps of Despair"){applesLeft -= 1;}
		else if (currentState == "Eisten Tunnel"){applesLeft -= 1;}
		else if (currentState == "Elvin Waterfall"){applesLeft -= 1;}
		else if (currentState == "Werewolf Hill"){applesLeft -= 1;}
		else if (currentState == "Apples Orchard"){applesLeft -= 1;}
		else {gameState = "Lost";}

	}


}

