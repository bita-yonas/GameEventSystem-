
#include <iostream>
#include <string>

using namespace std;

class GameEngine // creat a class
{
private:
    // This pointer will store the single instance of the class
    static GameEngine* Instance;
    // this is a private constructor so no other code can create an object of this class
    GameEngine() {}
    
    
public:
    // the function returns a pointer to the single instance of GameEngine
    static GameEngine* getInstance() {
        // if the single instance hasn't been created yet, creat a new instance
        if (Instance == NULL) {
            // here we'er creating then instance for the first time and assigning it to the instance
            Instance = new GameEngine();
        }
        
        // if the instance is already exists, then return the existing one
         return Instance;
        
    }
    // function that triggers a game event and prints the evnet to the console
     void triggerEvent(const string& event) {
         // print a message to the console, indicating that the event has occurred
         cout << " [GameEngine] Event triggerd: " << event << endl;
         
         
    }
    // Function that simulates a player's action and prints it to the console
     void playerAction(const string& playerName, const string& action){
         // print a message to the console, showing the player's action in the game
         cout << " [GameEngine] " << playerName << " " << action << endl;
    }

};

// Initialize the static instance variable to null
GameEngine* GameEngine ::Instance = NULL;

int main() {
    
  GameEngine* engine = GameEngine::getInstance();
    
   // Trigger game events
  engine->triggerEvent("Enemy appeared!");
  engine->triggerEvent("Treasure found!");
    
  // Simulate player actions
  engine->playerAction("Player1", "attacks the enemy.");
  engine->playerAction("Player2", "collects the treasure.");
    
  // Another game event and player action
  engine->triggerEvent("Player leveled up!");
  engine->playerAction("Player1", "casts a spell.");
    
    
    
  return 0;
}


