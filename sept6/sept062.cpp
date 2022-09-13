//
// Created by Owner on 9/6/2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

/*
 * "int argc, char *argv[]" lets main receive two arguments
 * char * is an outdated form of a string, array of characters
 */

//./dadjoke [add/remove/tellme] [dadjoke]
int main(int argc, char *argv[]){

    if(argc < 2)
    {
        cout << "Thou fool. Raca. Thou art not funny." << endl;
        return -1;
    }

    string mandato = argv[1];

    if(mandato == "add")
    {
        if(argc < 3)
        {
            cout << "RACA! Thou fool. Thou didst not do it right." << endl;
            return -1;
        }
        string s = argv[2];
        //open the file
        //ios app opens up the file for appending
        ofstream output;
        output.open("dadjokes.txt", ios::app);

        //write new dad joke to file
        output << s << endl;
        //close the file
        output.close();
    }else if(mandato == "remove")
    {
        //first check to make sure we have a dadjoke to remove
        if(argc < 3)
        {
            cout << "RACA! Thou fool. Thou didst not do it right." << endl;
            return -1;
        }//end validating if
        //second, read in the file to a vector
        //opening file
        ifstream input;
        input.open("dadjokes.txt");
        //confirm that file opened correctly
        if(!input)
        {
            cout << "dadjokes.txt not found" << endl;
            return -1;
        }//end file opened? if

        vector<string> theJokes;
        string linea;
        while(!input.eof())
        {
            getline(input, linea);
            if(linea.length() > 2)
            {
                theJokes.push_back(linea);
            }
        }//end reading while loop

        input.close();

        //third, remove the bad dad joke from vector
        string badDadJoke = argv[2];

        for(int i = 0; i < theJokes.size(); i++)
        {
            if(theJokes.at(i).find(badDadJoke) != string::npos)
            {
                //remove it
                theJokes.erase(theJokes.begin() + i);
                //stop
                break;
            }
        }//end 4
        //fourth, write the remaining dadjokes back to the file.
        ofstream output;
        output.open("dadjokes.txt");

        //write new dad joke to file
        for(int i = 0; i < theJokes.size(); i++)
        {
            output << theJokes.at(i) << endl;
        }//printing out array
        //close the file
        output.close();
    }else if(mandato == "tellme")
    {
        srand(time(nullptr));

        ifstream input;
        input.open("dadjokes.txt");
        //confirm that file opened correctly
        if(!input)
        {
            cout << "dadjokes.txt not found" << endl;
            return -1;
        }//end file opened? if

        vector<string> theJokes;
        string linea;
        while(!input.eof())
        {
            getline(input, linea);
            if(linea.length() > 2)
            {
                theJokes.push_back(linea);
            }
        }//end reading while loop

        input.close();

        int num = rand() % theJokes.size();
        cout << theJokes.at(num) << endl;
    }else
    {
        cout << "Raca. I don't understand thee." << endl;
        return -1;
    }//end options if block

    return 0;
    /*
    if(argc != 2)
    {
        cout << "Thou fool. Raca. You didst not tell me ONE dad joke. Thou art not funny." << endl;
        return -1;
    }

    cout << "Thanks for the most hilarious dad joke" << endl;
    string s = argv[1];

    //open the file
    //ios app opens up the file for appending
    ofstream output;
    output.open("dadjokes.txt", ios::app);

    //write new dad joke to file
    output << s << endl;
    //close the file
    output.close();

    return 0;
     */
    /*
    if(argc != 2)
    {
        cout << "Thou fool. Raca. You didst not tell me ONE dad joke. Thou art not funny." << endl;
        return -1;
    }

    cout << "Thanks for the hilarious dad joke." << endl;

    string s;
    s = argv[1];
    cout << "Your dad joke is: " << s << endl;

    return 0;
     */
    /*
    cout << "argc: " << argc << endl;

    //will print out the first string
    //which is the command itself actually
    cout << "the first argument is: " << argv[0] << endl;
    cout << "the second argument is: " << argv[1] << endl;

    for(int i = 0; i < argc; i++)
    {
        cout << "The" << i << "th argument is: " << argv[i] << endl;
    }
     */
    /*
    string s;
    cout << "Enter a dad joke: ";

    getline(cin, s);

    cout << endl << "The dad joke is: " << s << endl;
    return 0;
     */
}
