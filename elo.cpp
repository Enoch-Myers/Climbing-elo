#include <bits/stdc++.h>
using namespace std;

// Function to calculate the Probability
double Probability(double rating1, double rating2)
{
    // Calculate and return the expected score
    double hold = (1.0 / (1 + pow(2, (rating1 - rating2) / 1)));
    cout << hold << endl;
    return 1.0 / (1 + pow(2, (rating1 - rating2) / 1));
}

// Function to calculate Elo rating
// K is a constant.
// outcome determines the outcome: 1 for Player A win, 0 for Player B win, 0.5 for draw.
void EloRating(double &Ra, double Rb, double K, double outcome)
{
    // Calculate the Winning Probability of Player B
    double Pb = Probability(Ra, Rb);

    // Calculate the Winning Probability of Player A
    double Pa = Probability(Rb, Ra);

    // Update the Elo Ratings
    Ra = Ra + K * (outcome - Pa);
    Rb = Rb + K * ((1 - outcome) - Pb);

    // Print updated ratings
    cout << "Updated Ratings:-\n";
    cout << "Ra = " << Ra << " Rb = " << Rb << endl;
}

// Driver code
int main()
{
   // Current ELO ratings 
   double Ra, Rb;

   // K is a constant
   double K = .5;
   
   // Outcome: 1 for Player A win, 0 for Player B win, 0.5 for draw
   double outcome;
   bool cont;
   cout << "Enter your elo" << endl;
   cin >> Ra;
   do
   {
       
      cout << "Enter the V-grade" << endl;
      cin >> Rb;
      Rb += .5;
      cout << "Did you send? 1 = yes, 0 = no" << endl;
      cin >> outcome;

      // Function call
      EloRating(Ra, Rb, K, outcome);
      cout << endl << endl << Ra << endl;
      cout << "continue? 1 = yes, 0 = no" << endl;
      cin >> cont;
   } while (cont == true);
   return 0;
}