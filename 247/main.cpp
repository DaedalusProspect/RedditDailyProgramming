#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <algorithm>

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

using namespace std;

struct Person
{
    string Name;
    vector<string> FamilyMembers;
    string Match;
};

int main()
{
	vector<Person> GiftGivers;
    vector<Person> Matched;
    bool noMatches = true;
    
    
    ifstream Data;
    Data.open("data.txt");
    if(Data.is_open())
    {
        vector<string> TempNames;
        cout << "Data opened!" << endl;
        string CurrentLine = "";
        // Get all of our recipients and struct our data
        while(getline(Data,CurrentLine))
        {
            // This just puts all our names in a storage container for later sorting
            boost::split(TempNames,CurrentLine, boost::is_any_of(" ")); // Split the line by spaces
            Person CurrentPerson; // Holder var
            // Struct each person based on name, and add family members

                
            // Add each family member making sure not to add self.
            for(vector<string>::iterator xt= TempNames.begin(); xt < TempNames.end(); ++xt)
            {
                int index = xt - TempNames.begin();
                CurrentPerson.Name = TempNames[index];
                if (*xt != CurrentPerson.Name && *xt != "")
                {
                        // Add it to their family
                        CurrentPerson.FamilyMembers.push_back(*xt);
                }
                GiftGivers.push_back(CurrentPerson);
            }
                // Add to available recipients

        }
    }
    else
    {
        cout << "Data did not open :(";
        return 0;
    }
    
    Data.close();
    
    for(vector<Person>::iterator it = GiftGivers.begin(); it < GiftGivers.end(); ++it)
    {
        int index = it - GiftGivers.begin();
        cout << GiftGivers[index].Name <<  endl;
    }
    
    // We should have all of our data constructed now
    
    // Now get our matches

    srand(time(NULL));
    for(vector<Person>::iterator it = GiftGivers.begin(); it < GiftGivers.end(); ++it)
    {
        // Iterate through from the beginning and lets start matching
        Person person1 = *it;

        
        // Seed the rand
        
        while(person1.Match == "")
        {
            int num = rand() % GiftGivers.size() + 1; // Our random number
            bool family = true;
            
            for(vector<string>::iterator xt = person1.FamilyMembers.begin(); xt < person1.FamilyMembers.end(); ++xt)
            {
                int index = xt - person1.FamilyMembers.begin();
                if (person1.FamilyMembers[index] == GiftGivers[num].Name)
                {
                    family = true;
                    continue; // Loop through again
                    
                }
                else
                {
                    family = false;
                    break;
                }
            }
            
            if (family == false)
            {
                 // Got a match, lets make sure someone else doesn't have this person as well
                if (noMatches)
                {
                    person1.Match = GiftGivers[num].Name;
                    noMatches = false;
                }
                else
                {
                
                    for(vector<Person>::iterator xt = Matched.begin(); xt < Matched.end(); ++xt)
                    {
                        if(Matched[xt - Matched.begin()].Match == GiftGivers[num].Name) // Theyre already Matched, so we need another
                        {
                            continue;
                        }
                        else
                        {
                            person1.Match = GiftGivers[num].Name;
                        }
                    } 
                }
            }
            else
            {
               continue;
            }
        }
        
        if(person1.Match != "")
        {
            // Add them to our matched list
            Matched.push_back(person1);
            
            // Make them not available anymore
            int index = (it - GiftGivers.begin());
            GiftGivers.erase(GiftGivers.begin() + index);
        }
    }
    
    
    // Now we should have all of our data
    // We just need to print it
    
    for(vector<Person>::iterator it = Matched.begin(); it != Matched.end(); ++it)
    {
        int index = it - Matched.begin();
        cout << Matched[index].Name << " <> " << Matched[index].Match << endl;
    }

	return 0;
}
