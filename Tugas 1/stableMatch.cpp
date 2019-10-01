#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const char *men_data[][6] = {
    { "Victor",  "Bertha","Amy","Diane","Erika","Clare"},
    { "Wyatt",  "Diane","Bertha","Amy","Clare","Erika"},
    { "Xavier",  "Bertha","Erika","Clare","Diane","Amy"},
    { "Yance",  "Amy","Diane","Clare","Bertha","Erika"},
    { "Zeus",   "Bertha","Diane","Amy","Erika","Clare"}
};

const char *women_data[][6] = {
    { "Amy",  "Zeus","Victor","Wyatt","Yance","Xavier"},
    { "Bertha",  "Xavier","Wyatt","Yance","Victor","Zeus"},
    { "Clare", "Wyatt","Xavier","Yance","Zeus","Victor"},
    { "Diane",  "Victor","Zeus","Yance","Xavier","Wyatt"},
    { "Erika",  "Yance","Wyatt","Zeus","Xavier","Victor"}
};

typedef vector<string> PrefList;
typedef map<string, PrefList> PrefMap;
typedef map<string, string> Couples;

// Apakah 'first' datang lebih dulu sebelum 'second' di preference list-nya?
bool prefers(const PrefList &prefer, const string &first, const string &second)
{
    for (PrefList::const_iterator it = prefer.begin(); it != prefer.end(); ++it)
    {
        if (*it == first) return true;
        if (*it == second) return false;
    }
    return false; // no preference
}

int main()
{
    PrefMap men_pref, women_pref;
    queue<string> bachelors;

    cout<<"Stable Matching: Marriage Problem\n";

    // masukan data
    for (int i = 0; i < 5; ++i) // person
    {
        for (int j = 1; j < 6; ++j) // preference
        {
              men_pref[  men_data[i][0]].push_back(  men_data[i][j]);
            women_pref[women_data[i][0]].push_back(women_data[i][j]);
        }
        bachelors.push(men_data[i][0]);
    }

    Couples engaged; // <woman,man>

    cout << "Mencocokkan:\n";
    while (!bachelors.empty())
    {
        const string &suitor = bachelors.front();
        const PrefList &preflist = men_pref[suitor];

        for (PrefList::const_iterator it = preflist.begin(); it != preflist.end(); ++it)
        {
            const string &bride = *it;

            if (engaged.find(bride) == engaged.end()) // Jika cewek jomblo
            {
                cout << "\t" << bride << " dan " << suitor << "\n";
                engaged[bride] = suitor; // Jadian
                break;
            }

            const string &groom = engaged[bride];

            if (prefers(women_pref[bride], suitor, groom))
            {
                cout << "\t" << bride << " mencampakan " << groom << " karena " << suitor << "\n";
                bachelors.push(groom); // Masukan kembali groom menjadi bujangan
                engaged[bride] = suitor; // Bride berpasangan dengan suitor
                break;
            }
        }
        bachelors.pop();
    }

    cout << "Pernikahan:\n";
    for (Couples::const_iterator it = engaged.begin(); it != engaged.end(); ++it)
    {
        cout << "\t" << it->first << " dan " << it->second << "\n";
    }
}
