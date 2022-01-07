#include "Utilities.hpp"
#include "ComponentManager.hpp"
int main()
{
    ComponentManager::t = (int *)malloc(sizeof(int) * 2);

    vector<int> highScores;
    string line;
    ifstream file;

    file.open("hs.txt", ios::out);

    while (std::getline(file, line))
    {
        highScores.push_back(stoi(line));
    }

    file.close();

    ComponentManager *game = new ComponentManager();
    game->begin_game();
    int timeRec = (game->get_t())[1] - (game->get_t())[0];
    //cout << "Time taken : " << timeRec << " ms" << endl;

    highScores.push_back(timeRec);
    sort(highScores.begin(), highScores.end());

    ofstream f;
    f.open("hs.txt", ios::out);

    for(int i = 0;i < highScores.size();i++)
    {
        f << highScores[i] << endl;
    }
    f.close();
    cout << "Time taken/Score is:- " << timeRec << endl;
    if(timeRec == highScores[0])
    {
        cout << "You have the best time!!!" << endl;
    }
    else
    {
        cout << "Time to beat is:- " << highScores[0] << endl;
    }
    return 0;
}