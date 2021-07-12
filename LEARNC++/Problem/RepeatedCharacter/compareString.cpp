#include <bits/stdc++.h>
using namespace std;
struct Player
{
    int score;
    string name;
};

class Checker
{
public:
    static int comparator(Player a, Player b)
    {
        if (a.score > b.score)
        {
            return 1;
        }
        else if (a.score == b.score)
        {
            return (a.name < b.name) ? 1 : -1;
        }
        return -1;
    }
};

bool compare(Player a, Player b)
{
    if (Checker::comparator(a, b) == -1)
    {
        return false;
    }
    return true;
}

int main()
{
    vector<Player> players;
    int n;
    cin >> n;

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

    for (int i = 0; i < n; i++)
    {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}