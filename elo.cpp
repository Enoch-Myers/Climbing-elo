#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the Probability
double Probability(double rating1, double rating2)
{
    // Calculate and return the expected score
    // 1/2 chance of sending your elo, 1/4 chance 1 grade above, 1/8 for 2 grades avove
    double hold = (1.0 / (1 + pow(2, (rating1 - rating2) / 1)));
    cout << "Probability of sending in a given session: " << hold << endl;
    return 1.0 / (1 + pow(2, (rating1 - rating2) / 1));
}

// Function to calculate Elo rating
// K is a constant.
// outcome determines the outcome: 1 for Player A win, 0 for Player B win, 0.5 for draw.
void EloRating(double &climb_elo, double &V_Grade, double K, double outcome)
{
    // Calculate the Sending probability
    double Pb = Probability(climb_elo, V_Grade);

    // Update the Elo Ratings
    if ((climb_elo - V_Grade) >= 2 ){
        // nothin rn
    }
    climb_elo = climb_elo + K * (outcome - (1 - Pb));

    // Print updated ratings
    cout << "Updated Ratings:-\n";
    cout << "climb_elo = " << climb_elo << endl;
}

// Driver code
int main()
{
   // Current ELO ratings 
   double climb_elo, V_grade;

   // K is a constant
   double K = .5; // The max your score can change is .5pts
   
   // Outcome: 1 for Player A win, 0 for Player B win, 0.5 for draw
   double outcome;
   bool cont;
   cout << "Enter your elo" << endl;
   cin >> climb_elo;
   do
   {
       
      cout << "Enter the V-grade" << endl;
      cin >> V_grade;
      V_grade += .5;
      cout << "Did you send? 1 = yes, 0 = no" << endl;
      cin >> outcome;

      // Function call
      EloRating(climb_elo, V_grade, K, outcome);
      cout << endl << endl << climb_elo << endl;
      cout << "continue? 1 = yes, 0 = no" << endl;
      cin >> cont;
   } while (cont == true);
   return 0;
}