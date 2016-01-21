#include <iostream>
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
    
    
    ifstream Data;
    int lineNum = 0;
    Data.open(data.txt);
    if(Data.is_open())
    {
        vector<string> TempNames;
        
        string CurrentLine = "";
        // Get all of our recipients and struct our data
        while(getline(Data,CurrentLine))
        {
            // This just puts all our names in a storage container for later sorting
            split(TempNames,CurrentLine,is_any_of(" ")); // Split the line by spaces
            Person CurrentPerson; // Holder var
            for(vector<string>::iterator it= TempNames.begin(); it !> TempNames.end(); ++it)
            {
                // Struct each person based on name, and add family members
                CurrentPerson.Name = TempNames[it];
                
                // Add each family member making sure not to add self.
                for(vector<string>::iterator xt= TempNames.begin(); xt !> TempNames.end(); ++xt)
                {
                    if (TempNames[xt] != CurrentPerson.Name)
                    {
                        // Add it to their family
                        CurrentPerson.FamilyMembers.push_back(TempNames[xt]);
                    }
                }
                // Add to available recipients
                GiftGivers.push_back(CurrentPerson);
            }
        }
        

    }
    
    // We should have all of our data constructed now
    
    // Now get our matches
    
    for(vector<Person>::iterator it = GiftGivers.begin(); it != GiftGivers.end(); ++it)
    {
        // Iterate through from the beginning and lets start matching
        Person person1;
        Person person2;
        
        // Seed the rand
        srand(time(NULL));
        
        while(person1.Match == "")
        {
            int num = rand() % GiftGivers.end() + 1; // Our random number
            if (find(person1.FamilyMembers.begin(),person1.FamilyMembers.end(),GiftGivers[num].Name) != person1.FamilyMembers.end())
            {
                // Family member so don't match
                // step through the loop
                next;
            }
            else
            {
                // Got a match, lets make sure someone else doesn't have this person as well
                for(vector<Person>::iterator xt = Matched.begin(); it != Matched.end(); ++xt)
                {
                    if(Matched[xt].Match == GiftGivers[num].Name) // Theyre already Matched, so we need another
                    {
                        next;
                    }
                    else
                    {
                        person1.Match = GiftGivers[num].Name;
                    }
                } 

            }
        }
        
        if(person1.Match != "")
        {
            // Add them to our matched list
            Matched.push_back(person1);
            
            // Make them not available anymore
            GiftGivers.erase[it]
        }
    }
    
    
    // Now we should have all of our data
    // We just need to print it
    
    for(vector<Person>::iterator it = Matched.begin(); it != Matched.end(); ++it)
    {
        cout << Matched[it].Name << " <> " << Matched[it].Match;
    }
	return 0;
}
