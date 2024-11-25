#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class station
{
public:
    unordered_map<int, string> stations;
    int fare(int sn)
    {
        return sn * 10;
    }
};

int usercount = 0;

void passprint(int l)
{
    for (int i = 0; i < l; i++)
        cout << "*";
}

class user
{
public:
    pair<string, string> idpassword;
    pair<int, double> metrocardbalance;

    user() {}
    void display()
    {
        cout << "HERE IS YOUR DETAILS :- \n";
        cout << "........................................................................................................................\n";
        cout << "ID IS " << idpassword.first << endl
             << "PASSWORD IS ";
        passprint((idpassword.second).length());
        cout << "\n METROCARD NO . IS " << metrocardbalance.first;
        cout << "\n BALANCE IS - " << metrocardbalance.second;
        cout << "\n........................................................................................................................\n";
    }
    void updatebalance(double newone)
    {
        metrocardbalance.second += newone;
        cout << "\n your new balance is " << metrocardbalance.second << endl;
    }
};

void populatestation(station &metroSystem)
{
    // Insert station names into the map
    metroSystem.stations[1] = "SEC-51";
    metroSystem.stations[2] = "dhruvnagar";
    metroSystem.stations[3] = "SEC-50";
    metroSystem.stations[4] = "vanasthalicenter";
    metroSystem.stations[5] = "SEC-101";
    metroSystem.stations[6] = "khazi";
    metroSystem.stations[7] = "SEC-81";
    metroSystem.stations[8] = "NSEZ";
    metroSystem.stations[9] = "sec93";
    metroSystem.stations[10] = "SEC-83";
    metroSystem.stations[11] = "SEC-137";
    metroSystem.stations[12] = "rupamnagar";
    metroSystem.stations[13] = "SEC-142";
    metroSystem.stations[14] = "SEC-143";
    metroSystem.stations[15] = "SEC-144";
    metroSystem.stations[16] = "reva";
    metroSystem.stations[17] = "SEC-145";
    metroSystem.stations[18] = "SEC-147";
    metroSystem.stations[19] = "SEC-148";
    metroSystem.stations[20] = "PARI-CHOWK";
    metroSystem.stations[21] = "KNOWLEDGE-PARK";

    // Output the station names
    /* for (int i = 1; i <= 21; i++) {
         cout << "Station " << i << ": " << metroSystem.stations[i] << endl;
     }*/
}
// Function to perform depth-first search and find all paths
vector<vector<int>> findAllPaths(int source, int destination, unordered_map<int, set<pair<int, int>>> &adjList)
{
    stack<pair<int, vector<int>>> stk;
    stk.push({source, {source}});

    vector<vector<int>> allPaths;

    while (!stk.empty())
    {
        int current = stk.top().first;
        vector<int> path = stk.top().second;
        stk.pop();

        for (const auto &neighbor : adjList[current])
        {
            int nextNode = neighbor.first;
            if (find(path.begin(), path.end(), nextNode) == path.end())
            {
                vector<int> newPath = path;
                newPath.push_back(nextNode);
                stk.push({nextNode, newPath});

                if (nextNode == destination)
                {
                    allPaths.push_back(newPath);
                }
            }
        }
    }

    return allPaths;
}
void preparelist(unordered_map<int, set<pair<int, int>>> &adjlist)
{
    adjlist[1].insert({{2, 15}, {3, 3}, {9, 8}});
    adjlist[2].insert({{1, 15}, {4, 2}});
    adjlist[3].insert({{1, 3}, {4, 10}, {5, 2}, {9, 6}});
    adjlist[4].insert({{2, 2}, {3, 10}});
    adjlist[5].insert({{3, 2}, {7, 1}, {9, 6}});
    adjlist[6].insert({{7, 13}});
    adjlist[7].insert({{5, 1}, {6, 13}, {8, 2}});
    adjlist[8].insert({{7, 2}, {11, 1}});
    adjlist[9].insert({{1, 8}, {3, 6}, {5, 6}, {10, 10}, {16, 17}});
    adjlist[10].insert({{9, 10}});
    adjlist[11].insert({{8, 1}, {13, 2}});
    adjlist[12].insert({{13, 8}});
    adjlist[13].insert({{11, 2}, {14, 3}, {12, 8}});
    adjlist[14].insert({{13, 3}, {15, 4}});
    adjlist[15].insert({{14, 4}, {17, 6}});
    adjlist[16].insert({{9, 17}});
    adjlist[17].insert({{15, 6}, {18, 3}});
    adjlist[18].insert({{17, 3}, {19, 1}});
    adjlist[19].insert({{18, 1}, {20, 5}, {21, 1}});
    adjlist[20].insert({{19, 5}, {21, 2}});
    adjlist[21].insert({{19, 1}, {20, 2}});
}

void print(unordered_map<int, set<pair<int, int>>> adjlist)
{
    for (auto i : adjlist)
    {
        cout << i.first << " -> ";
        for (auto j : i.second)
        {
            cout << "{" << j.first << " , " << j.second << "}" << " ";
        }
        cout << endl;
    }
}

vector<int> shortestdistance(unordered_map<int, set<pair<int, int>>> adjlist, int source)
{
    vector<int> distance(adjlist.size() + 1, INT_MAX);
    distance[source] = 0; // Set the distance of the source node to 0

    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        auto top = *(st.begin());
        int topd = top.first;
        int topn = top.second;

        st.erase(st.begin());

        for (auto i : adjlist[topn])
        {
            if (topd + i.second < distance[i.first])
            {
                auto record = st.find(make_pair(distance[i.first], i.first));
                if (record != st.end())
                    st.erase(record);
                // Update the distance
                distance[i.first] = topd + i.second;
                st.insert(make_pair(distance[i.first], i.first));
            }
        }
    }

    return distance;
}

void convertToStandardTime(float totalHours)
{
    // Calculate hours, minutes, and seconds
    int hours = static_cast<int>(totalHours);
    float remainingMinutes = (totalHours - hours) * 60;
    int minutes = static_cast<int>(remainingMinutes);
    int seconds = static_cast<int>((remainingMinutes - minutes) * 60);

    // Display in standard time format
    cout << setfill('0') << setw(2) << hours << ":"
         << setfill('0') << setw(2) << minutes << ":"
         << setfill('0') << setw(2) << seconds << endl;
}
void saveUserCount(int count)
{
    ofstream file("usercount.txt");
    if (file.is_open())
    {
        file << count;
        file.close();
    }
}

int loadUserCount()
{
    ifstream file("usercount.txt");
    int count = 0;
    if (file.is_open())
    {
        file >> count;
        file.close();
    }
    return count;
}

bool CheckId(const string &id)
{
    ifstream file("userdetails.txt");
    string line;

    while (getline(file, line))
    {
        if (line.find(id) != string::npos)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void saveUserDetails(user userDetails[], int count)
{
    ofstream file("userdetails.txt");
    if (file.is_open())
    {
        for (int i = 0; i < count; ++i)
        {
            file << userDetails[i].idpassword.first << " "
                 << userDetails[i].idpassword.second << " "
                 << userDetails[i].metrocardbalance.first << " "
                 << userDetails[i].metrocardbalance.second << "\n";
        }
        file.close();
    }
}

void loadUserDetails(user userDetails[], int count)
{
    ifstream file("userdetails.txt");
    if (file.is_open())
    {
        for (int i = 0; i < count; ++i)
        {
            file >> userDetails[i].idpassword.first >> userDetails[i].idpassword.second >> userDetails[i].metrocardbalance.first >> userDetails[i].metrocardbalance.second;
        }
        file.close();
    }
}
int main()
{
    user userdetails[100];
    int currentusernumber;

    cout << "                                                      METRO SYSYEM NOIDA ";
    cout << endl
         << ".......................................................................................................................\n ";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Welcome aboard the future of urban mobility! Step into the dynamic world of the Noida Metro System, where seamless journeys and efficient ";
    cout << endl;
    cout << endl;
    cout << "connections await you. Explore the heart of Noida with our state-of-the-art metro network, designed to make your daily commute a breeze and your";
    cout << endl;
    cout << endl;
    cout << " city adventures unforgettable. Whether you're a resident or a visitor, the Noida Metro is your key to unlocking the vibrant energy of this ";
    cout << endl;
    cout << endl;
    cout << "thriving city. Discover the beauty, culture, and convenience of Noida like never before as you embark on a remarkable metro experience. Fasten ";
    cout << endl;
    cout << endl;
    cout << "your seatbelts, and let's ride the future together!";
    cout << endl;
    cout << endl;
    cout << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                                      THIS IS NOIDA METRO SYSYEM";
    cout << endl
         << ".......................................................................................................................\n ";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "*SEC-51-------------------------------------------------------*dhruvnagar" << std::endl;
    cout << "     \\ \\                                                      /" << std::endl;
    cout << "      \\  *SEC-50--------------------------------------*vanasthalicenter" << std::endl;
    cout << "       \\   |   *SEC-101" << std::endl;
    cout << "        |   |   /    SEC-81----------------------------------------------------- khazi" << std::endl;
    cout << "        |   |  /             *NSEZ" << std::endl;
    cout << "        *sec93-------------------\\--------------------------*SEC-83 " << std::endl;
    cout << "            \\                     *SEC-137" << std::endl;
    cout << "             \\                              *SEC-142----------------------------*rupamnagar" << std::endl;
    cout << "              \\                                     *SEC-143" << std::endl;
    cout << "               \\                                             *SEC-144" << std::endl;
    cout << "               *reva                                                    *SEC-145" << std::endl;
    cout << "                                                                              *SEC-147" << std::endl;
    cout << "                                                                                     *SEC-148--------------*PARI CHOWK" << std::endl;
    cout << "                                                                                           \\               /" << std::endl;
    cout << "                                                                                            *KNOWLEDGE PARK" << std::endl;

    cout << endl
         << ".......................................................................................................................\n ";
    station metrosystem;
    populatestation(metrosystem);
    unordered_map<int, set<pair<int, int>>> adjlist;
    preparelist(adjlist);
    print(adjlist);
    cout << "\n hopefully, now you must be aware of all metro system ";
    cout << "\n want to login or freshly sign in \n";
    cout << endl
         << ".......................................................................................................................\n ";
    cout << "                    enter 1 for logging \n";
    cout << "                    enter 0 for signing up \n";
    cout << endl
         << ".......................................................................................................................\n ";
    cout << endl
         << " enter -  ";
    bool reply;
    cin >> reply;
    cout << endl
         << "      ...........\n";

    // Load user count and details
    usercount = loadUserCount();
    loadUserDetails(userdetails, usercount);

    if (reply)
    {
        cout << "NICE !! , NOW LOGIN INTO THE SYSYEM BY FILLING YOUR CREDENTIALS \n";
        string password;
        string id;
        string name;

        cout << "enter id ";
        cin >> id;
        cout << "enter name ";
        cin >> name;
        int i = 0;
        char temp2;

        cout << "Enter Password: ";
        while (1)
        {
            temp2 = _getch(); // Read a single character
            if (temp2 == '\r')
            {                       // Enter key
                password[i] = '\0'; // Null-terminate the password
                break;
            }
            else if (temp2 == '\b')
            { // Backspace key
                if (i > 0)
                {
                    i--;
                    cout << "\b \b"; // Move back, overwrite with a space, and move back again
                }
            }
            else if (temp2 == '\t' || temp2 == ' ')
            { // Ignore tabs and spaces
                continue;
            }
            else
            {
                password[i] = temp2;
                i++;
                cout << "*"; // Print an asterisk for each character
            }
        }
        int just = 1;
        for (int i = 0; i < usercount; i++)
        {
            if (userdetails[i].idpassword.first == id)
            {
                just = 0;
                currentusernumber = i;
                cout << "welcome !! , " << name << " \n do u want to see your balance and other details \n enter 1 for yes and 0 for no \n";
                int q;
                cin >> q;
                if (q)
                    userdetails[i].display();
            }
        }
        if (just == 1)
        {
            cout << "not found";
            return 0;
        }
    }
    else
    {
        cout << "welcome dear!! hopefully, your journey with us will come about to be more beautiful and healthy\n ";
        srand(static_cast<int>(time(nullptr)));
        string password;
        string id;
        string name;
        int card = rand() % 224;
        while (true)
        {
            cout << "\n enter Userid : ";
            cin >> id;
            if (CheckId(id))
                cout << "\n ID already exists , please enter another id \n";
            else
                break;
        }
        cout << "\n enter name : ";
        cin >> name;
        // cout << "\n enter password : ";
        int i = 0;
        char temp2;
        cout << "Enter Password: ";
        while (1)
        {
            temp2 = _getch(); // Read a single character
            if (temp2 == '\r')
            {                       // Enter key
                password[i] = '\0'; // Null-terminate the password
                break;
            }
            else if (temp2 == '\b')
            { // Backspace key
                if (i > 0)
                {
                    i--;
                    cout << "\b \b"; // Move back, overwrite with a space, and move back again
                }
            }
            else if (temp2 == '\t' || temp2 == ' ')
            { // Ignore tabs and spaces
                continue;
            }
            else
            {
                password[i] = temp2;
                i++;
                cout << "*"; // Print an asterisk for each character
            }
        }
        cout << "\n your userid id is " << id;
        cout << "\n here this is your metro card no. " << card << " so that now we can  link your journey safely with us \n";

        // Update user details
        userdetails[usercount].idpassword.first = id;
        userdetails[usercount].idpassword.second = password;
        userdetails[usercount].metrocardbalance.first = card;
        userdetails[usercount].metrocardbalance.second = 0;
        cout << "\n initially , your card 's balance is zero, update it by adding atleast 10 rs for stability \n ";
        cout << "\n enter initial amount ";
        double amt;
        cin >> amt;
        userdetails[usercount].updatebalance(amt);
        // Increment usercount and save
        saveUserCount(usercount + 1);
        saveUserDetails(userdetails, usercount + 1);

        currentusernumber = usercount;
        usercount++; // Increment after saving
    }

    int source, destination;
    string s, d;
    cout << endl
         << endl
         << "\n enter the source station and destination station out of these stations :- " << endl;
    for (int i = 1; i <= 21; i++)
    {
        cout << "Station " << i << ": " << metrosystem.stations[i] << endl;
    }
    // print(adjlist);
    cout << "\n enter source :- ";
    cin >> s;
    cout << "\n enter destination :- ";
    cin >> d;

    for (auto i : metrosystem.stations)
    {
        if (i.second == s)
            source = i.first;
        if (i.second == d)
            destination = i.first;
    }
    vector<vector<int>> allpaths = findAllPaths(source, destination, adjlist);
    cout << "\n \n so , now u have chose your journey \n now choose what kind of journey you'll prefer \n WANNA SEE ALL THE PATHS ( CLICK 1) \n\n";
    cout << "WANNA SEE PATH HAVING MAXIMUM STATIONS (CLICK 2) \n WANNA SEE PATH HAVING MINIMUM STATIONS (CLICK 3) \n\n";
    cout << "WANNA SEE PATH HAVING SHORTEST DISTANCE (click 4) \n DO U WANT A PATH THAT CROSSES FROM A CERTAIN STATION THEN CLICK 5 \n\n";
    int choice;
    cout << "enter choice ";
    cin >> choice;
    if (choice == 1)
    {
        for (const auto &path : allpaths)
        {
            cout << "Path: ";
            for (int node : path)
            {
                cout << metrosystem.stations[node] << "    ->   ";
            }
            cout << endl;
        }
        cout << "\n NOW after choosing to see all paths , which u want to choose , enter 0 if first , 1 if second and so on \n";
        int index;
        cout << "enter ";
        cin >> index;
        cout << endl;
        int sum = 0;
        int src = source;
        for (int i = 1; i < (allpaths[index].size()); i++)
        {
            for (auto j : adjlist[src])
            {
                if (j.first == allpaths[index][i])
                {
                    sum += j.second;
                }
            }
            src = allpaths[index][i];
        }

        cout << "\n \n \n so the distance that is possible between your source and destination is " << endl
             << endl;
        cout << "                                    " << sum << "km" << endl;
        cout << s << "----------------------------------------------------------------------------------------" << d << endl;
        float time = sum / 45.0;
        cout << "estimated time is - ";
        convertToStandardTime(time);
        int fareamount = abs(metrosystem.fare(source) - metrosystem.fare(destination));
        if (fareamount > 100)
            fareamount = 100;

        cout << "\n your fare from " << s << " to " << d << " is - " << fareamount << " rs.";
        if (userdetails[currentusernumber].metrocardbalance.second < fareamount)
        {
            cout << endl
                 << "\n SORRY !! U HAVE NOT ENOUGH BALANCE IN YOUR CARD TO TRAVEL , PLEASE UPDATE !!";
            cout << "\n atleast add " << fareamount - userdetails[currentusernumber].metrocardbalance.second;
            cout << "\n enter  amount to be added ";
            double amot;
            cin >> amot;

            userdetails[currentusernumber].updatebalance(amot);
        }
        userdetails[currentusernumber].metrocardbalance.second -= fareamount;
        saveUserDetails(userdetails, usercount);
        cout << endl;
        //<<" now the balance is :- \n ";
        userdetails[currentusernumber].display();
    }

    else if (choice == 3)
    {
        int mini = INT_MAX;
        int c = -1;
        for (auto i : allpaths)
        {
            if (i.size() < mini)
            {
                mini = i.size();
            }
            c++;
        }
        for (auto i : allpaths)
        {
            if (i.size() == mini)
            {
                for (auto j : i)
                {
                    cout << metrosystem.stations[j] << "    ->   ";
                }
            }
        }
        for (auto k : allpaths[c])
        {
            cout << metrosystem.stations[k] << "   -->    ";
            break;
        }
        int summ = 0;
        int srcc = source;
        for (int i = 1; i < (allpaths[c].size()); i++)
        {
            for (auto j : adjlist[srcc])
            {
                if (j.first == allpaths[c][i])
                {
                    summ += j.second;
                }
            }
            srcc = allpaths[c][i];
        }

        cout << endl;
        cout << "\n \n \n so the distance that is possible between your source and destination is " << endl
             << endl;
        cout << "                                    " << summ << "km" << endl;
        cout << s << "----------------------------------------------------------------------------------------" << d << endl;
        float time = summ / 45.0;
        cout << "estimated time is - ";
        convertToStandardTime(time);
        int fareamount = abs(metrosystem.fare(source) - metrosystem.fare(destination));
        if (fareamount > 100)
            fareamount = 100;

        cout << "\n your fare from " << s << " to " << d << " is - " << fareamount << " rs.";
        if (userdetails[currentusernumber].metrocardbalance.second < fareamount)
        {
            cout << endl
                 << "\n SORRY !! U HAVE NOT ENOUGH BALANCE IN YOUR CARD TO TRAVEL , PLEASE UPDATE !!";
            cout << "\n atleast add " << fareamount - userdetails[currentusernumber].metrocardbalance.second;
            cout << "\n enter  amount to be added ";
            double amot;
            cin >> amot;

            userdetails[currentusernumber].updatebalance(amot);
        }
        userdetails[currentusernumber].metrocardbalance.second -= fareamount;
        saveUserDetails(userdetails, usercount);
        cout << endl;
        //<<" now the balance is :- \n ";
        userdetails[currentusernumber].display();
    }

    else if (choice == 2)
    {
        int maxi = INT_MIN;
        int c = -1;
        for (auto i : allpaths)
        {
            if (i.size() > maxi)
            {
                maxi = i.size();
            }
            c++;
        }
        for (auto i : allpaths)
        {
            if (i.size() == maxi)
            {
                for (auto j : i)
                {
                    cout << metrosystem.stations[j] << "    ->   ";
                }
            }
        }
        int sum = 0;
        int src = source;
        for (int i = 1; i < (allpaths[c].size()); i++)
        {
            for (auto j : adjlist[src])
            {
                if (j.first == allpaths[c][i])
                {
                    sum += j.second;
                }
            }
            src = allpaths[c][i];
        }
        for (auto k : allpaths[c])
        {
            cout << metrosystem.stations[k] << "   -->    ";
        }
        cout << endl;
        cout << "\n \n \n so the distance that is possible between your source and destination is " << endl
             << endl;
        cout << "                                    " << sum << "km" << endl;
        cout << s << "----------------------------------------------------------------------------------------" << d << endl;
        float time = sum / 45.0;
        cout << "estimated time is - ";
        convertToStandardTime(time);
        int fareamount = abs(metrosystem.fare(source) - metrosystem.fare(destination));
        if (fareamount > 100)
            fareamount = 100;

        cout << "\n your fare from " << s << " to " << d << " is - " << fareamount << " rs.";
        if (userdetails[currentusernumber].metrocardbalance.second < fareamount)
        {
            cout << endl
                 << "\n SORRY !! U HAVE NOT ENOUGH BALANCE IN YOUR CARD TO TRAVEL , PLEASE UPDATE !!";
            cout << "\n atleast add " << fareamount - userdetails[currentusernumber].metrocardbalance.second;
            cout << "\n enter  amount to be added ";
            double amot;
            cin >> amot;

            userdetails[currentusernumber].updatebalance(amot);
        }
        userdetails[currentusernumber].metrocardbalance.second -= fareamount;
        saveUserDetails(userdetails, usercount);
        cout << endl;
        //<<" now the balance is :- \n ";
        userdetails[currentusernumber].display();
    }
    else if (choice == 4)
    {
        vector<int> ans = shortestdistance(adjlist, source);

        cout << "\n \n \n so the shortest distance that is possible between your source and destination is " << endl
             << endl;
        cout << "                                    " << ans[destination] << "km" << endl;
        cout << s << "----------------------------------------------------------------------------------------" << d << endl;
        float time = (ans[destination]) / 45.0;
        cout << "estimated time is - ";
        convertToStandardTime(time);
        int fareamount = abs(metrosystem.fare(source) - metrosystem.fare(destination));
        if (fareamount > 100)
            fareamount = 100;

        cout << "\n your fare from " << s << " to " << d << " is - " << fareamount << " rs.";
        if (userdetails[currentusernumber].metrocardbalance.second < fareamount)
        {
            cout << endl
                 << "\n SORRY !! U HAVE NOT ENOUGH BALANCE IN YOUR CARD TO TRAVEL , PLEASE UPDATE !!";
            cout << "\n atleast add " << fareamount - userdetails[currentusernumber].metrocardbalance.second;
            cout << "\n enter  amount to be added ";
            double amot;
            cin >> amot;

            userdetails[currentusernumber].updatebalance(amot);
        }
        userdetails[currentusernumber].metrocardbalance.second -= fareamount;
        saveUserDetails(userdetails, usercount);
        cout << endl;
        //<<" now the balance is :- \n ";
        userdetails[currentusernumber].display();
    }
    else if (choice == 5)
    {
        cout << endl
             << "ok , so tell us which station you want to visit in between of your journey  ";
        cout << endl
             << "(kindly , write station number )\n";
        int midwala;
        cin >> midwala;
        int cm = -1;
        int ui = 0;
        bool found = 0;
        for (const auto &path : allpaths)
        {

            for (auto node : path)
            {
                if (node == midwala)
                {
                    ui += cm;
                    found = 1;
                }
            }
            cm++;
        }
        if (found == 0)
        {
            vector<vector<int>> new1 = findAllPaths(source, midwala, adjlist);
            cout << endl;
            sort(new1.begin(), new1.end(), [](const vector<int> &a, const vector<int> &b)
                 { return a.size() < b.size(); });
            for (auto k : new1[0])
            {
                cout << metrosystem.stations[k] << "   -->    ";
            }
            vector<vector<int>> new2 = findAllPaths(midwala, destination, adjlist);
            sort(new2.begin(), new2.end(), [](const vector<int> &a, const vector<int> &b)
                 { return a.size() < b.size(); });
            for (auto k : new2[0])
            {
                cout << metrosystem.stations[k] << "   -->    ";
            }
            int sum = 0;
            int src = source;
            for (int i = 1; i < (new1[0].size()); i++)
            {
                for (auto j : adjlist[src])
                {
                    if (j.first == new1[0][i])
                    {
                        sum += j.second;
                    }
                }
                src = new1[0][i];
            }
            src = midwala;
            for (int i = 1; i < (new2[0].size()); i++)
            {
                for (auto j : adjlist[src])
                {
                    if (j.first == new2[0][i])
                    {
                        sum += j.second;
                    }
                }
                src = new2[0][i];
            }
            cout << "\n \n \n so the distance that is possible between your source and destination is " << endl
                 << endl;
            cout << "                                    " << sum << "km" << endl;
            cout << s << "----------------------------------------------------------------------------------------" << d << endl;
            float time = sum / 45.0;
            cout << "estimated time is - ";
            convertToStandardTime(time);
            int fareamount = abs(metrosystem.fare(source) - metrosystem.fare(destination));
            if (fareamount > 100)
                fareamount = 100;

            cout << "\n your fare from " << s << " to " << d << " is - " << fareamount << " rs.";
            if (userdetails[currentusernumber].metrocardbalance.second < fareamount)
            {
                cout << endl
                     << "\n SORRY !! U HAVE NOT ENOUGH BALANCE IN YOUR CARD TO TRAVEL , PLEASE UPDATE !!";
                cout << "\n atleast add " << fareamount - userdetails[currentusernumber].metrocardbalance.second;
                cout << "\n enter  amount to be added ";
                double amot;
                cin >> amot;

                userdetails[currentusernumber].updatebalance(amot);
            }
            userdetails[currentusernumber].metrocardbalance.second -= fareamount;
            saveUserDetails(userdetails, usercount);
            cout << endl;
            //<<" now the balance is :- \n ";
            userdetails[currentusernumber].display();
        }
        else
        {
            for (auto k : allpaths[ui])
            {
                cout << metrosystem.stations[k] << "   -->    ";
            }
            cout << endl;
            int sum = 0;
            int src = source;
            for (int i = 1; i < (allpaths[cm].size()); i++)
            {
                for (auto j : adjlist[src])
                {
                    if (j.first == allpaths[cm][i])
                    {
                        sum += j.second;
                    }
                }
                src = allpaths[cm][i];
            }
            cout << "\n \n \n so the distance that is possible between your source and destination is " << endl
                 << endl;
            cout << "                                    " << sum << "km" << endl;
            cout << s << "----------------------------------------------------------------------------------------" << d << endl;
            float time = sum / 45.0;
            cout << "estimated time is - ";
            convertToStandardTime(time);
            int fareamount = abs(metrosystem.fare(source) - metrosystem.fare(destination));
            if (fareamount > 100)
                fareamount = 100;

            cout << "\n your fare from " << s << " to " << d << " is - " << fareamount << " rs.";
            if (userdetails[currentusernumber].metrocardbalance.second < fareamount)
            {
                cout << endl
                     << "\n SORRY !! U HAVE NOT ENOUGH BALANCE IN YOUR CARD TO TRAVEL , PLEASE UPDATE !!";
                cout << "\n atleast add " << fareamount - userdetails[currentusernumber].metrocardbalance.second;
                cout << "\n enter  amount to be added ";
                double amot;
                cin >> amot;

                userdetails[currentusernumber].updatebalance(amot);
            }
            userdetails[currentusernumber].metrocardbalance.second -= fareamount;
            saveUserDetails(userdetails, usercount);
            cout << endl;
            //<<" now the balance is :- \n ";
            userdetails[currentusernumber].display();
        }
    }

    return 0;
}
