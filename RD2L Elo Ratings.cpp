#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <map>


using namespace std;
#define SIZE 37 //Amount of teams in league
#define fuckme 86 //number of series played
struct Team
{
    string name;
    double rating;
};
struct Result
{
    string team1_name,
           team2_name;
    int    team1_wins,
           team2_wins;

};
struct NewElo
{
    float Ra;
    float Rb;
};
NewElo eloRating(float, float, int, float);
float Probability(int, int);
int main()
{
    //Team array of structs with: Team Name/Rating(which is base 1200)
    Team teams[SIZE] ={
                       {"Itachi", 1200},
                       {"Diaspora", 1200},
                       {"StonedSpirit", 1200},
                       {"Cuzi", 1200},
                       {"Ghost", 1200},
                       {"ForTheSwarm", 1200},
                       {"Toth", 1200},
                       {"MidOrCourierAdventure", 1200},
                       {"Ultra", 1200},
                       {"FakePolo", 1200},
                       {"Skater", 1200},
                       {"Spidez", 1200},
                       {"Vuvu", 1200},
                       {"BoX", 1200},
                       {"DoobyMoogey", 1200},
                       {"VelVelVel", 1200},
                       {"Waifu", 1200},
                       {"Nera", 1200},
                       {"Elidoto", 1200},
                       {"GraciousPapi", 1200},
                       {"ChowMains", 1200},
                       {"Ar", 1200},
                       {"ForestBear", 1200},
                       {"Newbycakes", 1200},
                       {"Wgod", 1200},
                       {"NO!", 1200},
                       {"Polo", 1200},
                       {"BurgeoningPhoneThrone", 1200},
                       {"TheMantis", 1200},
                       {"Danny", 1200},
                       {"PrinceMeerkat", 1200},
                       {"Bsvhsvj", 1200},
                       {"Sssst", 1200},
                       {"Mediocre/Mason", 1200},
                       {"Ana is back", 1200},
                       {"Sugoi-Chan", 1200},
                       {"RuneWhore", 1200}
                      };
    //Initializing and iterating Map
    map <string, Team> m;
    for(int i = 0; i < SIZE; i++)
    {
        Team the_team = teams[i];
        m[the_team.name] = the_team;
    }
       //Results array of structs with: Team 1/Team2/Team 1 Wins/Team 2 Wins (in any given series)
        Result results[fuckme] = {
                                 {"VelVelVel", "Ultra", 2, 0},                      //week 1
                                 {"Mediocre/Mason", "Ar", 0, 2},
                                 {"BurgeoningPhoneThrone", "TheMantis", 1, 1},
                                 {"Skater", "Sssst", 2, 0},
                                 {"Sugoi-Chan", "Itachi", 0, 2},
                                 {"BoX", "Cuzi", 0, 2},
                                 {"Nera", "NO!", 2, 0},
                                 {"Vuvu", "Ana is back", 2, 0},
                                 {"ChowMains", "Newbycakes", 0, 2},
                                 {"Diaspora", "Bsvhsvj", 2, 0},
                                 {"ForestBear", "Waifu", 0, 2},
                                 {"MidOrCourierAdventure", "ForTheSwarm", 1, 1},
                                 {"Elidoto", "Ghost", 1, 1},
                                 {"DoobyMoogey", "GraciousPapi", 0 ,2},
                                 {"Toth", "StonedSpirit", 0, 2},
                                 {"Danny", "PrinceMeerkat", 0, 2},
                                 {"Polo", "RuneWhore", 2, 0},
                                 {"Spidez", "Wgod", 2, 0},
                                 {"Mediocre/Mason", "Ultra", 0 , 2},               //week 2
                                 {"Cuzi", "Ar", 2, 0},
                                 {"VelVelVel", "Itachi", 0, 2},
                                 {"BoX", "NO!", 1, 1},
                                 {"ForTheSwarm", "BurgeoningPhoneThrone", 2, 0},
                                 {"Ghost", "TheMantis", 2, 0},
                                 {"ChowMains", "Sssst", 2, 0},
                                 {"GraciousPapi", "Newbycakes", 0, 2},
                                 {"Wgod", "Ana is back", 2, 0},
                                 {"Diaspora", "Waifu", 2, 0},
                                 {"Vuvu", "StonedSpirit", 0, 2},
                                 {"PrinceMeerkat", "Skater", 0, 2},
                                 {"Runewhore", "ForestBear", 1, 1},
                                 {"Danny", "Sugoi-Chan", 2, 0},
                                 {"MidOrCourierAdventure", "Elidoto", 2, 0},
                                 {"Polo", "Nera", 0 , 2},
                                 {"Spidez", "FakePolo", 0, 2},
                                 {"Toth", "DoobyMoogey", 2, 0},
                                 {"Mediocre/Mason", "Sssst", 1,1},
                                 {"Ar", "TheMantis", 1, 1},
                                 {"Bsvhsvj", "Ultra", 0, 2},
                                 {"Nera", "Cuzi", 0, 2},
                                 {"Skater", "Itachi", 0, 2},
                                 {"FakePolo", "Newbycakes", 2, 0},
                                 {"ForestBear", "NO!", 0, 2},
                                 {"ForTheSwarm", "Ghost", 0, 2},
                                 {"Elidoto", "BurgeoningPhoneThrone", 1, 1},
                                 {"MidOrCourierAdventure", "VelVelVel", 1, 1},
                                 {"Diaspora", "StonedSpirit", 1, 1},
                                 {"RuneWhore", "BoX", 0, 2},
                                 {"Waifu", "ChowMains", 1, 1},
                                 {"PrinceMeerkat", "Vuvu", 0, 2},
                                 {"GraciousPapi", "Wgod", 1, 1},
                                 {"Toth", "Danny", 2, 0},
                                 {"Spidez", "Polo", 2, 0},
                                 {"Nera", "Ultra", 0 ,2},
                                 {"VelVelVel", "NO!", 2, 0},
                                 {"Waifu", "TheMantis", 2, 0},
                                 {"Newbycakes", "Skater", 0, 2},
                                 {"Sssst", "RuneWhore", 2, 0},
                                 {"ForestBear", "Mediocre/Mason", 2, 0},
                                 {"PrinceMeerkat", "BurgeoningPhoneThrone", 1, 1},
                                 {"Elidoto", "Bsvhsvj", 2, 0},
                                 {"Ar", "Wgod", 1, 1},
                                 {"FakePolo", "StonedSpirit", 0, 2},
                                 {"Vuvu", "MidOrCourierAdventure", 1, 1},
                                 {"Polo", "Danny", 2, 0},
                                 {"Spidez", "Toth", 1, 1},
                                 {"Cuzi", "Ultra", 1, 1},
                                 {"NO!", "BurgeoningPhoneThrone", 1, 1},
                                 {"Bsvhsvj", "Ana is back", 1, 1},
                                 {"Newbycakes", "BoX", 0, 2},
                                 {"TheMantis", "Sugoi-Chan", 2, 0},
                                 {"Itachi", "StonedSpirit", 2, 0},
                                 {"GraciousPapi", "Sssst", 2, 0},
                                 {"VelVelVel", "Ghost", 0 , 2},
                                 {"Elidoto", "Ar", 1, 1},
                                 {"Skater", "ForTheSwarm", 0, 2},
                                 {"Nera", "ChowMains", 1, 1},
                                 {"MidOrCourierAdventure", "Waifu", 2, 0},
                                 {"Diaspora", "FakePolo", 2, 0},
                                 {"PrinceMeerkat", "ForestBear", 0, 2},
                                 {"Wgod", "DoobyMoogey", 0, 2},
                                 {"Spidez", "Vuvu", 1, 1},
                                 {"Toth", "Polo", 2, 0}
                                };
        //Iterating through to get Elos
        for(int i = 0; i < fuckme; i++)
        {
            Result result = results[i];
            Team team1 = m[result.team1_name];
            Team team2 = m[result.team2_name];
            NewElo newElo = eloRating(team1.rating, team2.rating, 400, result.team1_wins /2.0);
            team1.rating = newElo.Ra;
            team2.rating = newElo.Rb;
            m [result.team1_name] = team1;
            m [result.team2_name] = team2;
        }
        //printing teams and their elos
        cout << endl << " Team " << setw(30) << "Elo Rating" << endl << endl;
        int x =1;
        for(int i = 0; i < SIZE; i++)
        {
            Team the_team = teams[i];
                cout << left << x << ")";
                cout << left << setw(25) << m[the_team.name].name;
                cout << left << setw(25) << m[the_team.name].rating << endl;
                x++;
        }
system("color 0c");
system("PAUSE>nul");
return 0;
}
NewElo eloRating(float Ra, float Rb, int K, float d)
{
    // To calculate the Winning
    // Probability of Player B
    float Pb = Probability(Ra, Rb);
    // To calculate the Winning
    // Probability of Player A
    float Pa = Probability(Rb, Ra);
    // Case -1 When Player A wins
    // Updating the Elo Ratings
    if (d == 1)
    {
        Ra = Ra + K * (1 - Pa);
        Rb = Rb + K * (0 - Pb);
    }
    else if (d == 0.5)
    {
        Ra = Ra + K * (0.5 - Pa);
        Rb = Rb + K * (0.5 - Pb);
    }
    // Case -2 When Player B wins
    // Updating the Elo Ratings
    else
    {
        Ra = Ra + K * (0 - Pa);
        Rb = Rb + K * (1 - Pb);
    }
   // cout << "Ra = " << Ra << " Rb = " << Rb;
    NewElo newElo = {Ra, Rb};
    return newElo;
}
float Probability(int rating1, int rating2)
{
    return 1.0 * 1.0 / (1 + 1.0 *
           pow(10, 1.0 * (rating1 - rating2) / 400));
}
