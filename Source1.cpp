#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include <conio.h>
#include<sstream>
#include<ctime>
#include<time.h>
#include<conio.h>
#include <iomanip>
#include<windows.h>
#define LEFT 97
#define RIGHT 100
int x = 74;
int y = 44;

using namespace std;

// class prototypes
class user;
class admin;
class passenger;
class train;

// global functions
void mainmenu();
//Base Class

class User
{
private:
    string* username;
    string* password;

public:
    User()
    {
        username = new string("");
        password = new string("");
    }

    User(string username, string password)
    {
        this->username = new string(username);
        this->password = new string(password);
    }

    ~User() 
    {
        delete username;
        delete password;
    }

    string get_username() 
    {
        return *username;
    }

    string get_password()
    {
        return *password;
    }

    void set_username(string username)
    {
        *(this->username) = username;
    }

    void set_password(string password)
    {
        *(this->password) = password;
    }

    bool login(string idfile, string username, string password)
    {
        ifstream file(idfile);
        if (!file.is_open())
        {
            cout << "ERROR IN OPENING FILE." << endl;
            return false;
        }
        else 
        {
            string line;
            bool found = false;
            while (getline(file, line))
            {
                string username_stored = "";
                string password_stored = "";
                int i = 0; // iterator
                while (i < line.length() && line[i] != ',') 
                {
                    username_stored += line[i];
                    i++;
                }
                i++;
                while (i < line.length() && line[i] != ',') 
                {
                    password_stored += line[i];
                    i++;
                }
                if (username == username_stored && password == password_stored) 
                {
                    found = true;
                    file.close();
                }
            }
            file.close();
            return found;
        }
    }

    void register_user(string idfile, string username, string password) 
    {
        fstream file(idfile, ios::app);

        if (!file.is_open()) 
        {
            cout << "ERROR IN OPENING FILE." << endl;
            return;
        }

        file << username << "," << password << endl;
        file.close();
    }
};
//train Class
class train
{
private:
    //DATA MEMBERS
    static const int MAX_trainS = 100;
    static int trainCount;
    static train** trains;
    string* trainNumber;
    string* trainName;
    string* Efare;
    string* Bfare;
    string* Ffare;
    string* arrival;
    string* departure;
    string* departcity;
    string* arrivecity;
public:
    //Default Constructor
    train();
    // parameterized constructor
    train(string trainNumber, string trainName, string departcity, string arrivecity, string departure, string arrival, string Efare, string Bfare,string Ffare);
    //Setters
    void settrainNumber(string trainNumber); //A function that sets the trainNumber of the train.
    void settrainName(string trainName); // A function that sets the trainName of the train.
    void setEFare(string Efare); //A function that sets the Economy  fare of the train.
    void setBFare(string Bfare); //A function that sets the Business  fare of the train.
    void setFFare(string Ffare); //A function that sets the First class fare of the train.
    void setArrival(string arrival);// A function that sets the arrival timings of the train.
    void setDeparture(string arrival);// A function that sets the departure timings of the train.
    void setArrivecity(string arrivecity);  //A function that sets the source station of the train.
    void setDepartcity(string departcity);// A function that sets the destination station of the train.

    //Getters
    string gettrainNumber();//A function that returns the trainNumber of the train.
    string gettrainName(); //A function that returns the trainName of the train.
    string getEFare();// A function that returns the Economy fare of the train.
    string getBFare();// A function that returns the Business fare of the train.
    string getFFare();// A function that returns the First class fare of the train.
    string getArrival(); //A function that returns the arrival timings of the train.
    string getDeparture(); //A function that returns the departure timings of the train.
    string getArrivecity(); //A function that returns the source station of the train.
    string getDepartcity();// A function that returns the destination station of the train.

    //train class Functions
    void addtrain();
    void deletetrain();
    void modifyFare(string trainfile);
    void modifytrainTimings(string trainfile);
    void searchtrain(string city);
    void Booktrain(string un, string name, string age, string CNIC, string mbl_no, string adress);
    void cancelBooking(string un);
    void viewBooking(string un);
    void GenerateRevenue();

    ////Destructor
    //~train()
    //{
    //    delete trainNumber;
    //    delete trainName;
    //    delete Efare;
    //    delete Bfare;
    //    delete Ffare;
    //    delete arrival;
    //    delete departure;
    //    delete departcity;
    //    delete arrivecity;
    //    for (int i = 0; i < MAX_trainS; i++)
    //    {
    //        delete[]trains[i];
    //    }
    //    delete []trains;
    //    
    //}
};
int train::trainCount = 0;
train** train::trains = new train * [MAX_trainS];
//Default Constructor
train::train()
{
    trainNumber = new string("");
    trainName = new string("");
    Efare = new string("");
    Bfare = new string("");
    Ffare = new string("");
    arrival = new string("");
    departure = new string("");
    arrivecity = new string("");
    departcity = new string("");
}
//Paramterized Constructor
train::train(string trainNumber, string trainName, string Efare, string Bfare, string Ffare, string arrival, string departure, string arrivecity, string departcity)
{
    this->trainNumber = new string(trainNumber);
    this->trainName = new string(trainName);
    this->Efare = new string(Efare);
    this->Bfare = new string(Bfare);
    this->Ffare = new string(Ffare);
    this->arrival = new string(arrival);
    this->departure = new string(departure);
    this->arrivecity = new string(arrivecity);
    this->departcity = new string(departcity);
}
//train Class Getters
string train::gettrainNumber()
{
    return *trainNumber;
}
string train::gettrainName()
{
    return *trainName;
}
string train::getEFare()
{
    return *Efare;
}
string train::getBFare()
{
    return *Bfare;
}
string train::getFFare()
{
    return *Ffare;
}
string train::getArrival()
{
    return *arrival;
}
string train::getDeparture()
{
    return *departure;
}
string train::getArrivecity()
{
    return *arrivecity;

}
string train::getDepartcity()
{
    return *departcity;

}
//train Class Setters
void train::settrainNumber(string trainNumber)
{
    *(this->trainNumber) = trainNumber;
}
void train::settrainName(string trainName)
{
    *(this->trainName) = trainName;
}
void train::setEFare(string Efare)
{
    *(this->Efare) = Efare;
}
void train::setBFare(string Bfare)
{
    *(this->Bfare) = Bfare;
}
void train::setFFare(string Ffare)
{
    *(this->Ffare) = Ffare;
}
void train::setArrival(string arrival)
{
    *(this->arrival) = arrival;
}
void train::setDeparture(string departure)
{
   *(this->departure) = departure;
}
void train::setArrivecity(string arrivecity)
{
    *(this->arrivecity) = arrivecity;
}
void train::setDepartcity(string departcity)
{
    *(this->departcity) = departcity;
}

//ADMIN FUNCTIONALITIES

//Add Train Function
void train::addtrain()
{
    // Initialize the seat map
    const int ROWS = 10;
    const int COLS = 10;
    int** seatMap = new int* [ROWS];
    for (int i = 0; i < ROWS; ++i) 
    {
        seatMap[i] = new int[COLS];
        for (int j = 0; j < COLS; ++j)
        {
            seatMap[i][j] = 0;
        }
    }

    // Get the train information from the user
    system("cls");
    cout << "\n\n\t\t\t\t _______________________________________ " << endl;
    cout << "\t\t\t\t |                                      |" << endl;
    cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
    cout << "\t\t\t\t |______________________________________|" << endl;
    cout << "\n\n";
    cout << "ENTER TRAIN NUMBER: ";
    cin >> *trainNumber;
    cin.ignore();
    cout << "ENTER TRAIN NAME: ";
    getline(cin, *trainName);
    cout << "ENTER DEPARTURE CITY: ";
    getline(cin, *departcity);
    cout << "ENTER ARRIVAL CITY: ";
    getline(cin, *arrivecity);
    cout << "ENTER DEPARTURE TIME: ";
    getline(cin, *departure);
    cout << "ENTER ARRIVAL TIME: ";
    getline(cin, *arrival);
    cout << "ENTER ECONOMY CLASS FARE OF THE FARE: ";
    getline(cin, *Efare);
    cout << "ENTER  BUSINESS CLASS FARE OF THE FARE: ";
    getline(cin, *Bfare);
    cout << "ENTER FIRST CLASS FARE OF THE FARE: ";
    getline(cin, *Ffare);

    // Create a new train object with the user-provided information
    train* newtrain = new train(*trainNumber, *trainName, *Efare, *Bfare, *Ffare, *arrival, *departure, *arrivecity, *departcity);

    // Add the new train object to the array of trains;
    trains[trainCount] = newtrain;
    trainCount++;

    // Store the train information in a file
    ofstream file(*trainName + ".txt");
    if (!file.is_open()) {
        cout << "\t\t*********ERROR IN OPENING THE FILE!*********" << endl;
        return;
    }
    file << *trainNumber << "," << *trainName << "," << *departcity << "," << *arrivecity << "," << *departure << "," << *arrival << "," << *Efare << "," << *Bfare << "," << *Ffare << endl;
    file.close();
    cout << "\t\t**********TRAIN ADDED SUCCESSFULLY!**********" << endl;

    // Store the seat map for the train in a file
    ofstream inputFile(*trainName + " BOOKING FILE " + ".txt");
    if (inputFile.is_open())
    {
        for (int i = 0; i < ROWS; i++) 
        {
            for (int j = 0; j < COLS; j++) 
            {
                inputFile << seatMap[i][j] << " ";
            }
            inputFile << endl;
        }
    }
    inputFile.close();

    // Store the train name in a file
    ofstream nameFile("train_names.txt", ios::app);
    if (!nameFile.is_open())
    {
        cout << "\t\t*********ERROR IN OPENING THE FILE!*********" << endl;
        return;
    }
    nameFile << *trainName << endl;
    nameFile.close();

    // Deallocate memory for the seat map
    for (int i = 0; i < ROWS; i++)
    {
        delete[]seatMap[i];
    }
    delete[]seatMap;
}
//Delete Train Function
void train::deletetrain()
{
    system("cls");
    cout << "\n\n\t\t\t\t _______________________________________ " << endl;
    cout << "\t\t\t\t |                                      |" << endl;
    cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
    cout << "\t\t\t\t |______________________________________|" << endl;
    cout << "\n\n";
    /*string choice;*/
    cout << " TRAIN NAME : " << endl;
    cin.ignore();
    getline(cin, *trainName);
    cout << "TRAIN NUMBER : " << endl;
    cin >> *trainNumber;
    string filename = *trainName + ".txt";
    if (remove(filename.c_str()) != 0)
    {
        cout << "\t\t*********ERROR IN DELETING IN TRAIN.*********" << endl;
    }
    else
    {
        cout << "\t\t*********TRAIN DATA DELETED SUCCESSFULLY !*********" << endl;
    }
    //Delete train name from the file.
    // Read file names from train_names.txt and delete the line that contains filename
    ifstream input_file("train_names.txt");
    string line;
    string data;
    while (getline(input_file, line)) {
        if (line != *trainName) {
            data += line + "\n";
        }
    }
    input_file.close();

    // Write the remaining file names back to train_names.txt
    ofstream output_file("train_names.txt");
    output_file << data;
    output_file.close();
}
//Modify Fare Function
void train::modifyFare(string trainfile)
{
    int choice;
    cout << "\t\t************* MODIFY FARE *************" << endl;
    string line, newEfare, newBfare, newFfare;
    //OPEN FILE TO MODIFY FARE
    fstream file(trainfile, ios::in | ios::app | ios::out);

    if (!file.is_open())
    {
        cout << "\t\t************ERROR IN OPRNING IN FILE.************" << endl;
        return;
    }
    else if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
            cout << "\n";
            stringstream ss(line);
            getline(ss, *trainNumber, ',');
            getline(ss, *trainName, ',');
            getline(ss, *departcity, ',');
            getline(ss, *arrivecity, ',');
            getline(ss, *departure, ',');
            getline(ss, *arrival, ',');
            getline(ss, *Efare, ',');
            getline(ss, *Bfare, ',');
            getline(ss, *Ffare, ',');

            system("cls");
            cout << "\n\n\t\t\t\t _______________________________________ " << endl;
            cout << "\t\t\t\t |                                      |" << endl;
            cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
            cout << "\t\t\t\t |______________________________________|" << endl;
            cout << "\n\n";
            cout << "\t\tTRAIN DETAILS :" << endl;
            cout << "\t\tTrain Number : " << *trainNumber << endl;
            cout << "\t\tTrain Name : " << *trainName << endl;
            cout << "\t\tDeparture City : " << *departcity << endl;
            cout << "\t\tArrival City : " << *arrivecity << endl;
            cout << "\t\tDeparture Time : " << *departure << endl;
            cout << "\t\tArrival Time : " << *arrival << endl;
            cout << "\t\tECONOMY CLASS FAIR TRAIN : " << *Efare << endl;
            cout << "\t\tBUSINESS CLASS FAIR TRAIN : " << *Bfare << endl;
            cout << "\t\tFIRST CLASS FAIR TRAIN: " << *Ffare << endl;

        hello:

            cout << "\t\tENTER 1 TO MODIFY ECONOMY CLASS FAIR TRAIN ." << endl;
            cout << "\t\tENTER 2 TO MODIFY BUSINESS CLASS FAIR TRAIN ." << endl;
            cout << "\t\tENTER 3 TO MODIFY FIRST CLASS FAIR TRAIN ." << endl;
            cin >> choice;
            if (choice == 1)
            {
                cout << "\t\tENTER THE MODIFIED ECONOMY CLASS FARE : " << endl;
                cout << "\t\t";
                cin.ignore();
                getline(cin, newEfare);
                ofstream file(trainfile, ios::trunc);
                file << *trainNumber << "," << *trainName << "," << *departcity << "," << *arrivecity << "," << *departure << "," << *arrival << "," << newEfare << "," << *Bfare << "," << *Ffare << endl;
                file.close();

            }
            else if (choice == 2)
            {
                cout << "\t\tENTER THE MODIFIED BUSINESS CLASS FARE : " << endl;
                cout << "\t\t";
                cin.ignore();
                getline(cin, newBfare);
                ofstream file(trainfile, ios::trunc);
                file << *trainNumber << "," << *trainName << "," << *departcity << "," << *arrivecity << "," << *departure << "," << *arrival << "," << *Efare << "," << newBfare << "," << *Ffare << endl;
                file.close();

            }
            else if (choice == 3)
            {
                cout << "\t\tENTER THE MODIFIED FIRST CLASS FARE : " << endl;
                cout << "\t\t";
                cin.ignore();
                getline(cin, newFfare);
                //STORE MODIFIED FARE IN A FILE
                ofstream file(trainfile, ios::trunc);
                file << *trainNumber << "," << *trainName << "," << *departcity << "," << *arrivecity << "," << *departure << "," << *arrival << "," << *Efare << "," << *Bfare << "," << newFfare << endl;
                file.close();

            }
            else
            {
                cout << "\t\t****INVALID OPTION****" << endl;
                goto hello;
            }
            cout << "\t\t****TRAIN FAIR UPDATED SUCCESFULLY!****" << endl;
            break;
        }
    }

}
//Modify Fare Timings Function
void train::modifytrainTimings(string trainfile)
{

    string line, mat, mdt;
    //OPEN FILE TO MODIFY TIME
    fstream file(trainfile, ios::in | ios::app);
    if (!file.is_open())
    {
        cout << "ERROR IN OPENING IN FILE." << endl;
        return;
    }
    else if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
            cout << "\n";
            stringstream ss(line);
            getline(ss, *trainNumber, ',');
            getline(ss, *trainName, ',');
            getline(ss, *departcity, ',');
            getline(ss, *arrivecity, ',');
            getline(ss, *departure, ',');
            getline(ss, *arrival, ',');
            getline(ss, *Efare, ',');
            getline(ss, *Bfare, ',');
            getline(ss, *Ffare, ',');
            system("cls");
            cout << "\n\n\t\t\t\t _______________________________________ " << endl;
            cout << "\t\t\t\t |                                      |" << endl;
            cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
            cout << "\t\t\t\t |______________________________________|" << endl;
            cout << "\n\n";
            cout << "\n\t\tTRAIN NAME : " << *trainNumber << endl;
            cout << "\t\tTRAIN NUMBER : " << *trainName << endl;
            cout << "\t\tDEPARTURE CITY : " << *departcity << endl;
            cout << "\t\tARRIVAL CITY : " << *arrivecity << endl;
            cout << "\t\tDEPARTURE TIME : " << *departure << endl;
            cout << "\t\tARRIVAL  TIME : " << *arrival << endl;
            cout << "\t\tECONOMY CLASS FARE: " << *Efare << endl;
            cout << "\t\tBUSINESS CLASS FARE : " << *Bfare << endl;
            cout << "\t\tFIRST CLASS FARE : " << *Ffare << endl;
            cout << "\t\tENTER THE MODIFIED TIMINGS : " << endl << endl;
            cout << "\t\tENTER THE DEPARTURE  TIME :" << endl;
            cout << "\t\t";
            getline(cin, mdt);
            cout << "\t\tENTER THE ARRIVAL  TIME :" << endl;
            cout << "\t\t";
            getline(cin, mat);
            //STORE MODIFIED TIMINGS IN A FILE
            ofstream file(trainfile, ios::trunc);
            file << *trainNumber << "," << *trainName << "," << *departcity << "," << *arrivecity << "," << mdt << "," << mat << "," << *Efare << "," << *Bfare << "," << *Ffare << endl;

            file.close();
            cout << "\t\t****TRAIN TIMINGS  UPDATED SUCCESFULLY!****" << endl;
            break;
        }
    }
}
//Generate Revenue Function
void train::GenerateRevenue()
{
    string data{};
    //UPDATED REVENUE DATA IN A FILE
    fstream input("revenuegenerated.txt");
    while (getline(input, data))
    {
        cout << "THE TOTAL REVENUE GENERATED IS :" << data << endl;
    }
    input.close();

    char g = _getch();
    return;
}

//PASSENGER FUNCTIONALITIES

//Search Train Function
void train::searchtrain(string t_name)
{
    //OPEN FILE OF TRAIN NAMES
    ifstream trainsFile("train_names.txt");
    if (!trainsFile.is_open())
    {
        cout << "\t\t*********ERROR IN OPENING THE FILE!*********" << endl;
        return;
    }
    cout << "\t\tFOLLOWINGS ARE THE TRAIN WHICH OPERATE " << t_name << endl;
    string trainFilename;
    while (getline(trainsFile, trainFilename))
    {
        //SEARCH THE SPECIFIC TRAIN
        ifstream trainFile(trainFilename + ".txt");
        if (!trainFile.is_open())
        {
            cout << "\t\tERROR IN OPENING THE FILE " << trainFilename << "!" << endl;
            continue;
        }

        string line;
        getline(trainFile, line);
        stringstream ss(line);
        getline(ss, *trainNumber, ',');
        getline(ss, *trainName, ',');
        getline(ss, *departcity, ',');
        getline(ss, *arrivecity, ',');
        getline(ss, *departure, ',');
        getline(ss, *arrival, ',');
        getline(ss, *Efare, ',');
        getline(ss, *Bfare, ',');
        getline(ss, *Ffare, ',');

        if (*arrivecity == t_name || *departcity == t_name)
        {
            cout << "\n\n";
            cout << "\t\tTRAIN NUMBER : " << *trainNumber << endl;
            cout << "\t\tTRAIN NAME : " << *trainName << endl;
            cout << "\t\tDEPARTURE CITY : " << *departcity << endl;
            cout << "\t\tARRIVAL CITY : " << *arrivecity << endl;
            cout << "\t\tDEPARTURE TIME : " << *departure << endl;
            cout << "\t\tARRIVAL  TIME : " << *arrival << endl;
            cout << "\t\tECONOMY CLASS FARE: " << *Efare << endl;
            cout << "\t\tBUSINESS CLASS FARE : " << *Bfare << endl;
            cout << "\t\tFIRST CLASS FARE : " << *Ffare << endl;

        }
        trainFile.close();
    }
    trainsFile.close();
}
//Book Train Seats Function
void train::Booktrain(string un, string name, string age, string CNIC, string mbl_no, string adress)
{

    const int ROWS = 10;
    const int COLS = 10;
    int seatMap[ROWS][COLS] = { 0 };
    string line, data;
    int numSeats, choice{};
    int row, col;
    cout << "\t\tENTER THE NAME OF TRAIN:" << "\t\t";
    getline(cin, *trainName);
    //OPEN THE FILE OF TRAIN NAMES
    ifstream file("train_names.txt", ios::out);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            data += "\t\t->";
            data += line + "\n";
        }
    }
    file.close();
    ifstream infile(*trainName + ".txt");
    string dd;
    getline(infile, dd);
    stringstream obj(dd);
    string T_NO, T_N, D_C, A_C, D_T, A_T, E_F, B_F, F_F;
    getline(obj, T_NO, ',');
    getline(obj, T_N, ',');
    getline(obj, D_C, ',');
    getline(obj, A_C, ',');
    getline(obj, D_T, ',');
    getline(obj, A_T, ',');
    getline(obj, E_F, ',');
    getline(obj, B_F, ',');
    getline(obj, F_F, ',');
    cout << "\t\tIN " << *trainName << " WE HAVE TOTAL HUNDRED SEATS .";
    cout << "\n\t\t(1 - 4) COLUMNS ARE FOR ECONOMY CLASS";
    cout << "\n\t\t(5 - 7) COLUMNS ARE FOR BUSINESS CLASS";
    cout << "\n\t\t(8 - 10) COLUMNS ARE FOR FIRST CLASS";
    cout << "\n\t\tENTER THE CLASS NAME TO BOOK THE SEATS ." << endl;
    cout << endl;
    cout << "\t\tENTER 1 TO SELECT ECONOMY CLASS." << endl;
    cout << "\t\tENTER 2 TO SELECT BUSINESS CLASS." << endl;
    cout << "\t\tENTER 3 TO SELECT FIRST CLASS ." << endl;
    cout << "\t\t";
    cin >> choice;
    //OPEN THE SPECIFIC BOOKING FILE 
    string f = *trainName + " BOOKING FILE ";
    ifstream filename(f + ".txt", ios::in);
    cout << "\t\t  ";
    for (int i = 1; i <= 10; i++)
    {
        cout << "(" << i << ")\t|";
    }
    cout << endl;
    for (int i = 0; i < ROWS; i++)
    {
        cout << "\t(" << i + 1 << ")\t|";
        for (int j = 0; j < COLS; j++)
        {
            filename >> seatMap[i][j];
            cout << seatMap[i][j] << "\t|";
        }
        cout << endl;
    }
    filename.close();
    if (choice == 1)
    {
        cout << "\t\tHOW MANY SEATS YOU WANT TO BOOK ? ";
        cout << "\t\t";
        cin >> numSeats;
        int* a = new int[numSeats];
        //UPDATE THE 2D ARRAY IN A BOOKING FILE OF EACH TRAIN
        string f1 = *trainName + " ECONOMY CLASS BOOKING FILE of " + un;

        fstream outputFile(f + ".txt");
        if (outputFile.is_open())
        {
            for (int i = 0; i < numSeats; i++)
            {
                cout << "\t\tENTER SEAT ROW : ";
                cout << "\t\t";
                cin >> row;
                cout << "\t\tENTER SEAT COLUMN : ";
                cout << "\t\t";
                cin >> col;

                if (row < 1 || row > ROWS || col < 1 || col > 4)
                {
                    cout << "\t\tINVALID SEAT SELECTED." << endl;
                    i--;
                    continue;
                }
                if (seatMap[row - 1][col - 1] == 1)
                {
                    cout << "\t\tSEAT ALREADY BOOKED." << endl;
                    i--;
                    continue;
                }
                seatMap[row - 1][col - 1] = 1;
                a[i] = (row) * (col);

            }

            outputFile.close();
        }
        fstream FileEmpty(f + ".txt", ios::trunc);
        fstream inputFile(f + ".txt");
        if (inputFile.is_open())
        {
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    inputFile << seatMap[i][j] << " ";
                }
                inputFile << endl;
            }
        }
        inputFile.close();
        time_t ct = time(0);
        string currenttime = ctime(&ct);
        int payment = stoi(E_F) * numSeats;
        int revenue;
        //SAVE THE PAYMENT IN REVENUE FILE
        ifstream revenuefile("revenuegenerated.txt");
        if (revenuefile >> revenue)
        {
            revenuefile.close();
        }
        else
        {
            revenue = 0;
        }
        revenue += payment;
        ofstream revenueoutfile("revenuegenerated.txt");
        revenueoutfile << revenue << endl;
        revenueoutfile.close();

        cout << "\t\tTHE TOTAL BILL YOU HAVE TO PAY IS:" << payment << endl;
        ofstream File(f1 + ".txt", ios::out);
        if (File.is_open())
        {
            File << currenttime << name << "\n" << age << "\n" << CNIC << "\n" << adress << "\n" << mbl_no << "\n" << numSeats << "\n" << payment << "\n";
            for (int i = 0; i < numSeats; i++)
            {
                File << a[i] << ",";
            }

        }
        else
        {
            cout << "\t\t*****ERROR IN OPRNING IN FILE*****" << endl;
        }
        File.close();
        ofstream bookingList("booking_list.txt", ios::app);
        if (bookingList.is_open())
        {
            bookingList << *trainName << " " << "ECONOMY CLASS" << " BOOKING FILE of " << un << endl;
            bookingList.close();
        }
        else
        {
            cout << "\t\t********ERROR IN OPENING IN BOOKING FILE ********\n";
        }

        delete[] a;
        a = NULL;
    }
    else if (choice == 2)
    {
        cout << "\t\tHOW MANY SEATS YOU WANT TO BOOK ? ";
        cout << "\t\t";
        cin >> numSeats;
        int* a = new int[numSeats];
        //UPDATE THE 2D ARRAY IN A BOOKING FILE OF EACH TRAIN
        string f1 = *trainName + " BUSINESS CLASS BOOKING FILE of " + un;
        int payment = stoi(B_F) * numSeats;
        int revenue;
        //SAVE THE PAYMENT IN REVENUE FILE
        ifstream revenuefile("revenuegenerated.txt");
        if (revenuefile >> revenue)
        {
            revenuefile.close();
        }
        else
        {
            revenue = 0;
        }
        revenue += payment;
        ofstream revenueoutfile("revenuegenerated.txt");
        revenueoutfile << revenue << endl;
        revenueoutfile.close();
        time_t ct = time(0);
        string currenttime = ctime(&ct);
        fstream outputFile(f + ".txt");
        if (outputFile.is_open())
        {
            for (int i = 0; i < numSeats; i++)
            {
                cout << "\t\tENTER SEAT ROW : ";
                cout << "\t\t";
                cin >> row;
                cout << "\t\tENTER SEAT COLUMN : ";
                cout << "\t\t";
                cin >> col;

                if (row < 1 || row > ROWS || col < 5 || col > 8)
                {
                    cout << "\t\tINVALID SEAT SELECTED." << endl;
                    i--;
                    continue;
                }
                if (seatMap[row - 1][col - 1] == 1)
                {
                    cout << "\t\tSEAT ALREADY BOOKED." << endl;
                    i--;
                    continue;
                }
                seatMap[row - 1][col - 1] = 1;
                a[i] = (row) * (col);

            }

            outputFile.close();
        }
        cout << "\t\tTHE TOTAL BILL YOU HAVE TO PAY IS:" << payment << endl;
        fstream FileEmpty(f + ".txt", ios::trunc);
        fstream inputFile(f + ".txt");
        if (inputFile.is_open())
        {
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    inputFile << seatMap[i][j] << " ";
                }
                inputFile << endl;
            }
        }
        inputFile.close();
        ofstream File(f1 + ".txt", ios::out);
        if (File.is_open())
        {
            File << currenttime << name << "\n" << age << "\n" << CNIC << "\n" << adress << "\n" << mbl_no << "\n" << numSeats << "\n" << payment << "\n";

            for (int i = 0; i < numSeats; i++)
            {
                File << a[i] << ",";
            }

        }


        else
        {
            cout << "\t\t*****ERROR IN OPENING IN FILE*****" << endl;
        }
        File.close();
        ofstream bookingList("booking_list.txt", ios::app);
        if (bookingList.is_open()) {
            bookingList << *trainName << " " << "BUSSINESS CLASS" << " BOOKING FILE of " << un << endl;
            bookingList.close();
        }
        else
        {
            cout << "\t\t*********ERROR IN OPENING IN BOOKING FILE *********\n";
        }

        delete[] a;
        a = NULL;
    }
    else if (choice == 3)
    {
        cout << "\t\tHOW MANY SEATS YOU WANT TO BOOK ? ";
        cout << "\t\t";
        cin >> numSeats;
        int* a = new int[numSeats] {0};
        //UPDATE THE 2D ARRAY IN A BOOKING FILE OF EACH TRAIN
        string f1 = *trainName + " FIRST CLASS BOOKING FILE of " + un;
        int payment = stoi(F_F) * numSeats;
        int revenue;
        //SAVE THE PAYMENT IN REVENUE FILE
        ifstream revenuefile("revenuegenerated.txt");
        if (revenuefile >> revenue)
        {
            revenuefile.close();
        }
        else
        {
            revenue = 0;
        }
        revenue += payment;
        ofstream revenueoutfile("revenuegenerated.txt");
        revenueoutfile << revenue << endl;
        revenueoutfile.close();
        time_t ct = time(0);
        string currenttime = ctime(&ct);
        fstream outputFile(f + ".txt");
        if (outputFile.is_open())
        {
            for (int i = 0; i < numSeats; i++)
            {
                cout << "\t\tENTER SEAT ROW : ";
                cout << "\t\t";
                cin >> row;
                cout << "\t\tENTER SEAT COLUMN : ";
                cout << "\t\t";
                cin >> col;

                if (row < 1 || row > ROWS || col < 8 || col > COLS)
                {
                    cout << "\t\tINVALID SEAT SELECTED." << endl;
                    i--;
                    continue;
                }
                if (seatMap[row - 1][col - 1] == 1)
                {
                    cout << "\t\tSEAT ALREADY BOOKED." << endl;
                    i--;
                    continue;
                }
                seatMap[row - 1][col - 1] = 1;
                a[i] = (row) * (col);

            }

            outputFile.close();
        }
        cout << "\t\tTHE TOTAL BILL YOU HAVE TO PAY IS:" << payment << endl;
        fstream FileEmpty(f + ".txt", ios::trunc);
        fstream inputFile(f + ".txt");
        if (inputFile.is_open())
        {
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    inputFile << seatMap[i][j] << " ";
                }
                inputFile << endl;
            }
        }
        inputFile.close();
        ofstream File(f1 + ".txt", ios::out);
        if (File.is_open())
        {
            File << currenttime << name << "\n" << age << "\n" << CNIC << "\n" << adress << "\n" << mbl_no << "\n" << numSeats << "\n" << payment << "\n";

            for (int i = 0; i < numSeats; i++)
            {
                File << a[i] << ",";
            }

        }

        else
        {
            cout << "\t\t*****ERROR IN OPENING IN FILE*****" << endl;
        }
        File.close();
        ofstream bookingList("booking_list.txt", ios::app);
        if (bookingList.is_open()) {
            bookingList << *trainName << " " << "FIRST CLASS" << " BOOKING FILE of " << un << endl;
            bookingList.close();
        }
        else
        {
            cout << "\t\t*********ERROR IN OPENING IN BOOKING FILE *********\n";
        }

        delete[] a;
        a = NULL;
    }

    cout << "\t\t*********SEATS BOOKED SUCCESSFULLY.*********" << endl;
}
void train::cancelBooking(string un)
{
    string train_name, class_name;
    cout << "ENTER TRAIN NAME TO CANCEL RESERVATION :" << endl;
    cin.ignore();
    getline(cin, train_name);
    cout << "ENTER TRAIN CLASS TO CANCEL RESERVATION :" << endl;
    getline(cin, class_name);
    //CANCEL THE BOOKING FILE
    string filename = train_name + " " + class_name + " BOOKING FILE of " + un;
    string file = filename + ".txt";
    //DELETE THE FARE FROM REVENUE GENERATED FILE
    string date, name, age, cnic, adress, mobileno, numseats, payment;
    fstream fileobj(file);
    if (fileobj.is_open())
    {
        while (getline(fileobj, date) && getline(fileobj, name) && getline(fileobj, age) &&
            getline(fileobj, cnic) && getline(fileobj, adress) && getline(fileobj, mobileno) &&
            getline(fileobj, numseats) && getline(fileobj, payment))
        {
            // Open revenuegenerated.txt to update the revenue
            fstream revenuefile("revenuegenerated.txt");
            if (revenuefile.is_open())
            {
                string revenue_str;
                getline(revenuefile, revenue_str);
                double revenue = stod(revenue_str);
                double fare = stod(payment);
                revenue -= fare;
                revenuefile.seekp(0);
                revenuefile << fixed << setprecision(2) << revenue << endl;
                revenuefile.close();
                cout << "\t\t*********FARE UPDATED IN REVENUE GENERATED FILE.*********" << endl;
            }
            else
            {
                cout << "\t\t*********ERROR IN OPENING REVENUE GENERATED FILE.*********" << endl;
            }
        }
        fileobj.close();
    }
    else
    {
        cout << "\t\t*********ERROR IN OPENING BOOKING FILE.*********" << endl;
    }
    int status = remove(file.c_str());
    if (status != 0)
    {
        cout << "\t\t*********ERROR IN DELETING IN RESERVATION.*********" << endl;
    }
    else
    {
        cout << "\t\t*********RESERVATION CANCELED SUCCESSFULLY !*********" << endl;
    }

    //DELETE THE FILE FROM BOOKING LIST FILE
    ifstream input_file("booking_list.txt");
    string line;
    string data;
    while (getline(input_file, line))
    {
        if (line != filename)
        {
            data += line + "\n";
        }
    }
    input_file.close();

    // Write the remaining file names back to train_names.txt
    ofstream output_file("booking_list.txt");
    output_file << data;
    output_file.close();


}
//View Booking Function
void train::viewBooking(string un)
{
    //string train_name, class_name;
    string class_name;
    cout << "ENTER TRAIN NAME TO VIEW RESERVATION :" << endl;
    cin.ignore();
    getline(cin, *trainName);
    cout << "ENTER TRAIN CLASS TO VIEW RESERVATION :" << endl;
    getline(cin, class_name);
    cout << "\n\n\n\n";
    //OPEN THE FILE TO VIEW DETAILS
    string filename = *trainName + " " + class_name + " BOOKING FILE of " + un;
    string lane;
    fstream fileobj(filename + ".txt");
    string date, name, age, cnic, adress, mobileno, numseats, payment, seats;
    if (fileobj.is_open())
    {
        while (getline(fileobj, date) && getline(fileobj, name) && getline(fileobj, age) &&
            getline(fileobj, cnic) && getline(fileobj, adress) && getline(fileobj, mobileno) &&
            getline(fileobj, numseats) && getline(fileobj, seats) && getline(fileobj, payment))
        {
            cout << "\t\tDATE & TIME\t\t:\t\t" << date << endl;
            cout << "\t\tNAME\t\t\t:\t\t" << name << endl;
            cout << "\t\tAGE\t\t\t:\t\t" << age << endl;
            cout << "\t\tCNIC\t\t\t:\t\t" << cnic << endl;
            cout << "\t\tADRESS\t\t\t:\t\t" << adress << endl;
            cout << "\t\tMOBILE NUMBER\t\t:\t\t" << mobileno << endl;
            cout << "\t\tNUMBER OF SEATS\t\t:\t\t" << numseats << endl;
            cout << "\t\tSEAT NUMBERS\t\t:\t\t" << seats << endl;
            cout << "\t\tTOTAL PAYMENT\t\t:\t\t" << payment << endl;
        }
        fileobj.close();
    }
    else
    {
        cout << "ERROR IN OPENING THE FILE " << endl;
    }
}

// admin class
class admin : public User
{
public:
    //Default Constructor
    admin()
    {}
    // parameterized constructor
    admin(string username, string password) : User(username, password)
    {
    }

    void admin_menu(string idfile);
};
void admin::admin_menu(string idfile)
{
D:
    char g = _getch();
    system("cls");
    cout << "\n\n\t\t\t\t _______________________________________ " << endl;
    cout << "\t\t\t\t |                                      |" << endl;
    cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
    cout << "\t\t\t\t |______________________________________|" << endl;
    cout << "\n\n";
    int *choice = new int;
    *choice = 0;
    cout << "SELECT OPTION : " << endl;
    cout << "1. LOGIN" << endl;
    cout << "2. REGISTER" << endl;
    cin >> *choice;

    switch (*choice)
    {
    case 1:
    {
        string* username = new string;
        string* password = new string;
        system("cls");
        cout << "\n\n\t\t\t\t _______________________________________ " << endl;
        cout << "\t\t\t\t |                                      |" << endl;
        cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
        cout << "\t\t\t\t |______________________________________|" << endl;
        cout << "\n\n";
        string TrainName;
        cout << "ENTER USERNAME: ";
        cin.ignore();
        getline(cin, *username);
        cout << "ENTER PASSWORD: ";
        getline(cin, *password);
        if (login(idfile, *username, *password))
        {
            system("cls");
            cout << "..........LOGIN SUCESSFULL........." << endl;
            set_username(*username);
            set_password(*password);
            //Admin Menu
        B:
            system("cls");
            cout << "\n\n\t\t\t\t _______________________________________ " << endl;
            cout << "\t\t\t\t |                                      |" << endl;
            cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
            cout << "\t\t\t\t |______________________________________|" << endl;
            cout << "\n\n";
            cout << "\n\tPLEASE CHOOSE FROM THE OPTIONS GIVEN BELOW:\n\n";
            cout << "\t\tENTER 1 TO ADD A TRAIN\n\n";
            cout << "\t\tENTER 2 TO DELETE A TRAIN\n\n";
            cout << "\t\tENTER 3 TO MODIFY TRAIN TRAIN FARE\n\n";
            cout << "\t\tENTER 4 TO MODIFY TRAIN TRAIN TIMINGS\n\n";
            cout << "\t\tENTER 5 TO VIEW TOTAL REVENUE \n\n";
            cout << "\t\tENTER 6 TO EXIT THE RAILWAY PORTAL\n\n";
            cout << "\n\tENTER THE OPTION YOU WANT TO CARRY OUT:\t";
            int* OPTION = new int;
            *OPTION = 0;
            cin >> *OPTION;
            cout << "\n\n";
            if (*OPTION == 1)
            {
                train *trainobj1 = new train;
                trainobj1->addtrain();
                delete trainobj1;
                char g = _getch();
                goto B;
            }
            else if (*OPTION == 2)
            {
                train *trainobj2 = new train;
                trainobj2->deletetrain();
                delete trainobj2;
                char g = _getch();
                goto B;
            }
            else if (*OPTION == 3)
            {

                system("cls");
                cout << "\n\n\t\t\t\t _______________________________________ " << endl;
                cout << "\t\t\t\t |                                      |" << endl;
                cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
                cout << "\t\t\t\t |______________________________________|" << endl;
                cout << "\n\n";
                string f;
                cout << "\t\tENTER THE TRAIN NAME : " << endl;
                cout << "\t\t";
                cin.ignore();
                getline(cin, TrainName);
                f = TrainName + ".txt";
                train *trainobj3 = new train;
                trainobj3->modifyFare(f);
                char g = _getch();
                goto B;

            }
            else if (*OPTION == 4)
            {

                system("cls");
                cout << "\n\n\t\t\t\t _______________________________________ " << endl;
                cout << "\t\t\t\t |                                      |" << endl;
                cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
                cout << "\t\t\t\t |______________________________________|" << endl;
                cout << "\n\n";
                string f;
                cout << "\t\tENTER THE TRAIN NAME : " << endl;
                cin.ignore();
                cout << "\t\t";
                getline(cin, TrainName);
                f = TrainName + ".txt";
                train *trainobj4 = new train;
                trainobj4->modifytrainTimings(f);
                delete trainobj4;
                char g = _getch();
                goto B;
            }
            else if (*OPTION == 5)
            {
                system("cls");
                cout << "\n\n\t\t\t\t _______________________________________ " << endl;
                cout << "\t\t\t\t |                                      |" << endl;
                cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
                cout << "\t\t\t\t |______________________________________|" << endl;
                cout << "\n\n";
                train *trainobj5 = new train;
                trainobj5->GenerateRevenue();
                char x = _getch();
                goto B;
            }
            else if (*OPTION == 6)
            {
                return;
            }
            else
            {
                cout << "\n\n \t\tINVALID OPTION.\n\n\t\tPRESS ANY KEY TO ENTER AGAIN.........";
            }
            delete OPTION;
            delete username;
            delete password;
        }
        else
        {
            cout << "INVLAID USERNAME AND PASSWORD" << endl;
            cout << "\t\t********RE-ENTER USERNAME AND PASSWORD********" << endl;
            cout << "PRESS ANY KEY" << endl;
            goto D;

        }

        break;
    }
    case 2:
    {
        string* username = new string;
        string* password = new string;
        system("cls");
        cout << "\n\n\t\t\t\t _______________________________________ " << endl;
        cout << "\t\t\t\t |                                      |" << endl;
        cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
        cout << "\t\t\t\t |______________________________________|" << endl;
        cout << "\n\n";
        cout << "ENTER USERNAME: ";
        cin.ignore();
        getline(cin, *username);
        cout << "ENTER PASSWORD: ";
        getline(cin, *password);
        register_user(idfile, *username, *password);
        cout << "YOU HAVE SUCESSFULLY REGISTERED!" << endl;
        char g = _getch();
        delete username;
        delete password;
        break;
    }
    default:
        cout << "INVLAID CHOICE" << endl;
        break;
    }
    delete choice;
}
// passenger class
class passenger : public User
{
private:
    string *name;
    string *age;
    string *CNIC;
    string *mbl_no;
    string *adress;
public:
    //Default Constructor
    passenger()
    {
        name = new string("");
        age = new string("");
        CNIC = new string("");
        mbl_no = new string("");
        adress = new string("");
    }
    // parameterized constructor
    passenger(string username, string password, string name, string age, string CNIC, string mbl_no,string adress, string date) : User(username, password)
    {
        this->name = new string(name);
        this->age = new string(age);
        this->CNIC = new string(CNIC);
        this->mbl_no = new string(mbl_no);
        this->adress = new string(adress);
    }

    void passenger_menu(string idfile);
    //Destructor
    ~passenger()
    {
        delete name;
        delete age;
        delete CNIC;
        delete mbl_no;
        delete adress;
    }
};
void passenger::passenger_menu(string idfile)
{
    int *choice =  new int;
    *choice = 0;
    system("cls");
    cout << "\n\n\t\t\t\t _______________________________________ " << endl;
    cout << "\t\t\t\t |                                      |" << endl;
    cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
    cout << "\t\t\t\t |______________________________________|" << endl;
    cout << "\n\n";
    cout << "SELECT OPTION" << endl;
    cout << "1. LOGIN" << endl;
    cout << "2. REGISTER" << endl;
    cin >> *choice;
    switch (*choice)
    {
    case 1:
    {
        string* username = new string;
        string* password = new string;

    C:
        system("cls");
        cout << "\n\n\t\t\t\t _______________________________________ " << endl;
        cout << "\t\t\t\t |                                      |" << endl;
        cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
        cout << "\t\t\t\t |______________________________________|" << endl;
        cout << "\n\n";
        cout << "ENTER USERNAME :  ";
        cin.ignore();
        getline(cin, *username);
        cout << "ENTER PASSWORD : ";
        getline(cin, *password);
        if (login(idfile, *username, *password))
        {
            system("cls");
            cout << "..........LOGIN SUCESSFULL..........." << endl;
            set_username(*username);
            set_password(*password);
            //Passenger Menu
            int *OPTION = new int;
            *OPTION = 0;
        A:
            system("cls");
            cout << "\n\n\t\t\t\t _______________________________________ " << endl;
            cout << "\t\t\t\t |                                      |" << endl;
            cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
            cout << "\t\t\t\t |______________________________________|" << endl;
            cout << "\n\n";
            cout << "\n\tPLEASE CHOOSE FROM THE OPTIONS GIVEN BELOW:\n\n";
            cout << "\t\tENTER 1 TO SEARCH A TRAIN\n\n";
            cout << "\t\tENTER 2 TO BOOK TICKETS\n\n";
            cout << "\t\tENTER 3 TO CANCEL RESERVATION\n\n";
            cout << "\t\tENTER 4 TO VIEW  BOOK TICKETS\n\n";
            cout << "\t\tENTER 5 TO EXIT THE RAILWAY RESERVATION PORTAL \n\n";
            cout << "\n\tENTER THE OPTION YOU WANT TO CARRY OUT:\t";
            cin >> *OPTION;
            cout << "\n\n";

            if (*OPTION == 1)
            {
                system("cls");
                cout << "\n\n\t\t\t\t _______________________________________ " << endl;
                cout << "\t\t\t\t |                                      |" << endl;
                cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
                cout << "\t\t\t\t |_____________________________________|" << endl;
                cout << "\n\n";
                string tn;
                cout << " ENTER THE CITY FOR WHICH YOU WANT TO SEARCH TRAINS." << endl;
                cin.ignore();
                getline(cin, tn);
                train obj1;
                obj1.searchtrain(tn);
                char x = _getch();
                goto A;
            }
            else if (*OPTION == 2)
            {
                system("cls");
                cout << "\n\n\t\t\t\t _______________________________________ " << endl;
                cout << "\t\t\t\t |                                      |" << endl;
                cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
                cout << "\t\t\t\t |______________________________________|" << endl;
                //OPEN THE FILE OF TRAIN NAMES
                string line, data;
                ifstream file("train_names.txt", ios::out);
                if (file.is_open())
                {
                    while (getline(file, line))
                    {
                        data += "\t\t->";
                        data += line + "\n";
                    }
                }
                file.close();
                //GET DETAILS FROM THE PASSENGER
                cout << "\t\tFOLLOWINGS ARE THE AVAILABLE TRAINS ." << endl;
                cout << data << endl;
                cout << "ENTER THE FOLLOWING DETAILS TO BOOK YOUR TICKETS : " << endl;
                cout << endl;
                cin.ignore();
                cout << "\t\tENTER NAME : " << endl;
                cout << "\t\t";
                getline(cin, *name);
                cout << "\t\tENTER AGE : " << endl;
                cout << "\t\t";
                getline(cin, *age);
                cout << "\t\tENTER CNIC # : " << endl;
                cout << "\t\t";
                getline(cin, *CNIC);
                cout << "\t\tENTER MOBILE NUMBER : " << endl;
                cout << "\t\t";
                getline(cin, *mbl_no);
                cout << "\t\tENTER ADDRESS : " << endl;
                cout << "\t\t";
                getline(cin, *adress);
                train obj2;
                obj2.Booktrain(*username, *name, *age, *CNIC, *mbl_no, *adress);
                char g = _getch();
                goto A;
            }

            else if (*OPTION == 3)
            {
                system("cls");
                cout << "\n\n\t\t\t\t _______________________________________ " << endl;
                cout << "\t\t\t\t |                                      |" << endl;
                cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
                cout << "\t\t\t\t |______________________________________|" << endl;
                cout << "\n\n";

                train obj3;
                obj3.cancelBooking(*username);
                char g = _getch();
                goto A;
            }

            else if (*OPTION == 4)
            {
                system("cls");
                cout << "\n\n\t\t\t\t _______________________________________ " << endl;
                cout << "\t\t\t\t |                                      |" << endl;
                cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
                cout << "\t\t\t\t |______________________________________|" << endl;
                cout << "\n\n";

                train obj4;
                obj4.viewBooking(*username);
                char g = _getch();
                goto A;
            }

            else if (*OPTION == 5)
            {
                char g = _getch();
                return;
            }
            else
            {
                cout << "\n\n \t\tINVALID OPTION.\n\n\t\tPRESS ANY KEY TO ENTER AGAIN.........";
            }
            delete OPTION;
        }
        else
        {
            cout << "\t\t*********INVLAID USERNAME OR PASSWORD !*********" << endl;
            cout << "\t\t********RE-ENTER USERNAME AND PASSWORD********" << endl;
            cout << "\t\tPRESS ANY KEY" << endl;
            goto C;
        }
        delete username;
        delete password;
        
        break;
    }
    case 2:
    {
        string* username = new string;
        string* password = new string;
        system("cls");
        cout << "\n\n\t\t\t\t _______________________________________ " << endl;
        cout << "\t\t\t\t |                                      |" << endl;
        cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
        cout << "\t\t\t\t |______________________________________|" << endl;
        cout << "\n\n";
        cout << "ENTER USERNAME :  ";
        cin.ignore();
        getline(cin, *username);
        cout << "ENTER PASSWORD : ";
        getline(cin, *password);
        register_user(idfile, *username, *password);
        cout << "REGISTERATION SUCCESSFUL!" << endl;
        delete username;
        delete password;;
        break;
    }
    default:
        cout << "INVALID CHOICE!" << endl;
        break;
    }
}
void gotoxy(int x, int y)
{

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition{};
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
// global functions
void mainmenu()
{
    int *choice = new int;
    *choice = 0;
    string *idfile1 = new string("admindata.txt"); // file name to store user credentials
    string *idfile2 = new string("passengerdata.txt"); // file name to store user credentials
    do
    {
    B:
        system("cls");
        system("Color 0B");

        gotoxy(25, 7);	cout << "           ||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        Sleep(40);
        gotoxy(25, 8);	cout << "           ||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        Sleep(40);
        gotoxy(25, 9);	cout << "           |||                                            |||" << endl;
        Sleep(40);
        gotoxy(25, 10);	cout << "           |||                                            |||" << endl;
        Sleep(40);
        gotoxy(25, 11);	cout << "           |||                                            |||" << endl;
        Sleep(40);
        gotoxy(25, 12);	cout << "           |||                WELCOME TO                  |||" << endl;
        Sleep(40);
        gotoxy(25, 13);	cout << "           |||       RAILWAY  RESERVATION SYSTEM          |||" << endl;
        Sleep(40);
        gotoxy(25, 14);	cout << "           |||                                            |||" << endl;
        Sleep(40);
        gotoxy(25, 15);	cout << "           |||                 1:ADMIN                    |||" << endl;
        Sleep(40);
        gotoxy(25, 16);	cout << "           |||                 2:PASSENGER                |||" << endl;
        Sleep(40);
        gotoxy(25, 17);	cout << "           |||                 3:EXIT THE PORTAL          |||" << endl;
        Sleep(40);
        gotoxy(25, 18);	cout << "           |||                                            |||" << endl;
        Sleep(40);
        gotoxy(25, 19);	cout << "           |||                                            |||" << endl;
        Sleep(40);
        gotoxy(25, 20);	cout << "           |||                                            |||" << endl;
        Sleep(40);
        gotoxy(25, 21);	cout << "           ||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        Sleep(40);
        gotoxy(25, 22);	cout << "           ||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        Sleep(40);

        cin >> *choice;
        switch (*choice)
        {
        case 1:
        {
            admin *adminObj = new admin;
            adminObj->admin_menu(*idfile1);
            delete adminObj;
            goto B;
            break;
        }
        case 2:
        {
            passenger *passengerObj = new passenger;
            passengerObj->passenger_menu(*idfile2);
            delete passengerObj;
            break;
        }
        case 3:
            system("cls");
            cout << "\n\n\t\t\t\t _______________________________________ " << endl;
            cout << "\t\t\t\t |                                      |" << endl;
            cout << "\t\t\t\t | RAILWAY RESERVATION SYSTEM!          |" << endl;
            cout << "\t\t\t\t |______________________________________|" << endl;

            cout << "\n\n";
            cout << "\t\t\t   THANKS FOR VISITING THE ONLINE PORTAL" << endl;
            break;
        default:
            cout << "\t\t\t*********INVALID CHOICE*********" << endl;
            break;
        }
    } while (*choice != 3);
    delete choice;
}
void load()
{
    system("color 0e");
    char a = int(219); // ascii code for block is 219
    gotoxy(50, 20);
    cout << "loading..." << endl;
    gotoxy(50, 21);
    for (int i = 0; i < 20; i++)
    {
        cout << a;
        Sleep(40);
    }
}

void mainMenu()
{
    system("cls");
    system("Color 0B");

    gotoxy(10, 10);		cout << "                       " << endl;
    gotoxy(10, 11);    	cout << "    ||               ||" << endl;
    gotoxy(10, 12);	    cout << "    ||               ||" << endl;
    gotoxy(10, 13);	    cout << "    ||               ||" << endl;
    gotoxy(10, 14);	    cout << "    ||   _________   ||" << endl;
    gotoxy(10, 15);	    cout << "    ||   ||     ||   ||" << endl;
    gotoxy(10, 16);	    cout << "    ||   ||     ||   ||" << endl;
    gotoxy(10, 17);	    cout << "    ||   ||     ||   ||" << endl;
    gotoxy(10, 18);	    cout << "    ||___||     ||___||" << endl;
    Sleep(300);

    cout << endl;
    gotoxy(35, 10);	cout << " ____________" << endl;
    gotoxy(35, 11);	cout << " ||        " << endl;
    gotoxy(35, 12); cout << " ||        " << endl;
    gotoxy(35, 12); cout << " ||        " << endl;
    gotoxy(35, 13); cout << " ||        " << endl;
    gotoxy(35, 14); cout << " ||_____" << endl;
    gotoxy(35, 15); cout << " ||        " << endl;
    gotoxy(35, 16); cout << " ||        " << endl;
    gotoxy(35, 17); cout << " ||        " << endl;
    gotoxy(35, 18); cout << " ||        " << endl;
    gotoxy(35, 18); cout << " ----------" << endl;

    Sleep(300);
    cout << endl;
    gotoxy(50, 10);	cout << " ||         " << endl;
    gotoxy(50, 11);	cout << " ||         " << endl;
    gotoxy(50, 12); cout << " ||         " << endl;
    gotoxy(50, 13); cout << " ||         " << endl;
    gotoxy(50, 14); cout << " ||         " << endl;
    gotoxy(50, 15); cout << " ||         " << endl;
    gotoxy(50, 16); cout << " ||         " << endl;
    gotoxy(50, 17); cout << " ||         " << endl;
    gotoxy(50, 18); cout << " || _______" << endl;
    Sleep(300);
    cout << endl;

    cout << endl;
    gotoxy(60, 10); cout << "  ----------------   " << endl;
    gotoxy(60, 11);	cout << "  ||              " << endl;
    gotoxy(60, 12); cout << "  ||              " << endl;
    gotoxy(60, 13); cout << "  ||              " << endl;
    gotoxy(60, 14); cout << "  ||              " << endl;
    gotoxy(60, 15); cout << "  ||              " << endl;
    gotoxy(60, 16); cout << "  ||              " << endl;
    gotoxy(60, 17); cout << "  ||              " << endl;
    gotoxy(60, 18); cout << "  ||              " << endl;
    gotoxy(60, 18); cout << "  --------------- " << endl;

    Sleep(300);

    gotoxy(70, 10);	  cout << " ||---------||" << endl;
    gotoxy(70, 11);	  cout << " ||         ||" << endl;
    gotoxy(70, 12);   cout << " ||         ||" << endl;
    gotoxy(70, 13);   cout << " ||         ||" << endl;
    gotoxy(70, 14);   cout << " ||         ||" << endl;
    gotoxy(70, 15);   cout << " ||         ||" << endl;
    gotoxy(70, 16);   cout << " ||         ||" << endl;
    gotoxy(70, 17);   cout << " ||         ||" << endl;
    gotoxy(70, 18);   cout << " ||---------||" << endl;

    Sleep(300);
    cout << endl;

    gotoxy(85, 11);	   cout << "||------       --------" << endl;
    gotoxy(85, 12);    cout << "||      ||     ||    ||" << endl;
    gotoxy(85, 13);    cout << "||      ||     ||    ||" << endl;
    gotoxy(85, 14);    cout << "||      ||     ||    ||" << endl;
    gotoxy(85, 15);    cout << "||       -------     ||" << endl;
    gotoxy(85, 16);    cout << "||                   ||" << endl;
    gotoxy(85, 17);    cout << "||                   ||" << endl;
    gotoxy(85, 18);    cout << "||                   ||" << endl;
    Sleep(300);
    cout << endl;

    cout << endl;
    gotoxy(105, 10); cout << " ___________ " << endl;
    gotoxy(105, 11); cout << " ||          " << endl;
    gotoxy(105, 12); cout << " ||          " << endl;
    gotoxy(105, 13); cout << " ||          " << endl;
    gotoxy(105, 14); cout << " ||____      " << endl;
    gotoxy(105, 15); cout << " ||          " << endl;
    gotoxy(105, 16); cout << " ||          " << endl;
    gotoxy(105, 17); cout << " ||          " << endl;
    gotoxy(105, 18); cout << " ||          " << endl;
    gotoxy(105, 18); cout << " ----------- " << endl;

    Sleep(300);
    cout << endl;

}
int main()
{
    int x = 45, y = 74;
    mainMenu();
    load();
    mainmenu();
    return 0;
}