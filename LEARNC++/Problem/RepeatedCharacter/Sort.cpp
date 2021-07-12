#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Player
{
    int score;
    string name;
};

//checker class to check for higher score and alphabetical order.
class Checker
{
public:
    // complete this method
    static int comparator(Player a, Player b)
    {

        if (a.score > b.score)
            return 1;
        if (a.score == b.score)
            return (a.name < b.name) ? 1 : -1;

        return -1;
    }
};

// Comparing the score with true or false;
bool compare(Player a, Player b)
{
    if (Checker::comparator(a, b) == -1)
        return false;
    return true;
}
int main()
{
    int n; // number of persons
    cin >> n;
    vector<Player> players;
    string name;
    int score;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);
    for (int i = 0; i < players.size(); i++)
    {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}