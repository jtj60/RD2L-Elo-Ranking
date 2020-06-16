#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <fstream>


using namespace std;
struct Predict
{
    string team1_name,
           team2_name;
    double team1_rating,
           team2_rating,
           team1_percentage,
           team2_percentage;
};
#define SIZE 18
void printHeader();
void printPredictions(Predict[]);
int main()
{
    Predict predictions[SIZE] = {
                                    {"Itachi", "Diaspora", 2047.98, 1729.98, 0, 0},
                                    {"StonedSpirit", "Cuzi", 1637.18, 1678.11, 0, 0},
                                    {"Ghost", "Toth", 1694.85, 1470.62, 0, 0},
                                    {"ForTheSwarm", "Spidez", 1557.07, 1358.21, 0, 0},
                                    {"MidOrCourierAdventure", "UltraGunner", 1549.06, 1676.13, 0, 0},
                                    {"FakePolo", "DoobyMoogey", 1343.18, 1150.74, 0, 0},
                                    {"Skater", "Vuvu", 1211.53, 1364.22, 0, 0},
                                    {"BoX", "Waifu", 1386.21, 1150.75, 0, 0},
                                    {"VelVelVel", "BurgeoningPhoneThrone", 1302.24, 1001.73, 0, 0},
                                    {"Nera", "Elidoto", 1175.50, 1150.75, 0, 0},
                                    {"GraciousPapi", "ChowMains", 1296.10, 1166.36, 0, 0},
                                    {"Ar", "ForestBear", 1149.06, 1182.7, 0, 0},
                                    {"Newbycakes", "NO!", 990.76, 1001.61, 0, 0},
                                    {"Wgod","Polo", 791.12, 1078.56, 0.0},
                                    {"TheMantis", "Danny", 1073.17, 766.36, 0, 0},
                                    {"PrinceMeerkat", "Mediocre/Mason", 775.94, 546.10, 0, 0},
                                    {"Bsvhsvj", "Sssst", 782.39, 903.90, 0, 0},
                                    {"Ana is back", "Sugoi-Chan", 775.94, 685.16, 0, 0}
                                 };
printHeader();
printPredictions(predictions);
system("color 0c");
system("PAUSE>NUL");
return 0;
}

void printHeader()
{
cout << endl << endl;
cout << "                                            RD2L PST Sunday Predictions:                         " << endl
     << "                                                        Week 5                                   " << endl << endl;

cout << left << setw(30) << "Team 1 " << setw(20)
     << left << "Win %"
     << left << "Series Predictions" << setw(20)
     << right << "Win % " << setw(31)
     << right << "Team 2 " << endl;
cout << "_______________________________________________________________________________________________________________________" << endl << endl;
}

void printPredictions(Predict predictions[])
{
for (int i = 0; i < SIZE; i++)
{
  double rating1 = predictions[i].team1_rating;
  double rating2 = predictions[i].team2_rating;
  int x,
      y;

  double win_percent = 1.0 * 1.0 / (1 + 1.0 * pow(10, 1.0 * (rating1 - rating2) / 400));
  predictions[i].team2_percentage = win_percent;
  predictions[i].team1_percentage = 1 - win_percent;
  predictions[i].team1_percentage = predictions[i].team1_percentage * 100;
  predictions[i].team2_percentage = predictions[i].team2_percentage * 100;
  if(predictions[i].team1_percentage >= 75.00)
  {
      x = 2;
      y = 0;
  }
  else if(predictions[i].team1_percentage >= 25.00 && predictions[i].team1_percentage <= 75.00)
  {
      x = 1;
      y = 1;
  }
  else
  {
      x = 0;
      y = 2;
  }
  cout << fixed << showpoint << setprecision(2)
       << left << setw(30)
       << predictions[i].team1_name << setw(25)
       << left << predictions[i].team1_percentage
       << left << x << "  -  "
       << right << y << setw(25)
       << right << predictions[i].team2_percentage << setw(32)
       << right << predictions[i].team2_name << endl;
}
}

