//============================================================================
// Name        : HotelManagementSystem.cpp
// Author      : Muhammad Usman Naveed
// Version     : Final Release
// Copyright   : (c) Reserved
// Description : Basic Console based Hotel Management/Reservation System 
// Concepts    : Object Oriented Programming
//============================================================================

#include<iostream>
#include<a.out.h>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;

class Room
{
    private:
    int price_per_24; //Room Charges per Night
    bool reservation_availability; //Availability to reserve check
    string type; //Type of the room

    public:
    Room() //Default Constructor
    {}
    virtual void set_price_per_24(int i) //Virtual function to set price
    {
        price_per_24 = i;
    }
    virtual int get_price_per_24() const //Virtual function to get the price
    {
        return price_per_24;
    }
    virtual void set_type(string type) //Virtual function to set type of the room
    {
        this->type = type; //Set data member "type" equal to the argument
    }
    virtual void set_availability_for_reservation(int i) //Virtual function to set availability check
    {
        reservation_availability = i;
    }
    virtual int get_availability_for_reservation() const //Virtual function to get availability
    {
        return reservation_availability;
    }
    virtual string get_type() const //Virtual function to get price
    {
        return type;
    }
    virtual ~Room()
    {
        delete this;
    }
};

class Room_Standard:public Room //Child Classes 
{
    public: //Public default constructor
    Room_Standard() //Default constructor
    {
        set_price_per_24(300); //set price equal to 300
        set_type("Standard"); //Set type as "Standard"
        set_availability_for_reservation(1); //Set availability as 1 initially i.e. available to reserve
    }
};

class Room_Moderate:public Room
{
    public:
    Room_Moderate() //Default constructor
    {
        set_price_per_24(500); //set price equal to 300
        set_type("Moderate"); //Set type as "Moderate"
        set_availability_for_reservation(1); //Set availability as 1 initially i.e. available to reserve
    }
};

class Room_Superior:public Room
{
    public:
    Room_Superior() //Default constructor
    {
        set_price_per_24(1000); //set price equal to 300
        set_type("Superior"); //Set type as "Superior"
        set_availability_for_reservation(1); //Set availability as 1 initially i.e. available to reserve
    }
};

class Room_Junior_Suite:public Room
{
    public:
    Room_Junior_Suite() //Default constructor
    {
        set_price_per_24(2000); //set price equal to 300
        set_type("Junior Suite"); //Set type as "Junior Suite"
        set_availability_for_reservation(1); //Set availability as 1 initially i.e. available to reserve
    }
};

class Room_Suite:public Room
{
    public:
    Room_Suite() //Default constructor
    {
        set_price_per_24(5000); //set price equal to 300
        set_type("Suite"); //Set type as "Suite"
        set_availability_for_reservation(1); //Set availability as 1 initially i.e. available to reserve
    }
};

class Floor //Class of floors of the hotel.
{  
    private:
    Room **Arr_per_Floor; //Polymorphic array (data member) per floor of the hotel.
    int count_rooms_Standard,count_rooms_Moderate,count_rooms_Superior,count_rooms_Junior_Suite,count_rooms_Suite; //Variables to keep a count of reserved rooms of following type per floor of the hotel

    public:
    Floor() //Default Constructor
    {
        Arr_per_Floor = new Room*[50]; //Each floor has a polymorphic array of 50 "Room" type objects
        for(int i = 0; i < 50; ++i)
        {
            if(i >= 0 && i < 10)
            Arr_per_Floor[i] = new Room_Standard; //0 to 9 rooms will be of Standard type

            if(i >= 10 && i < 20)
            Arr_per_Floor[i] = new Room_Moderate; //10 to 19 rooms will be of Moderate type

            if(i >= 20 && i < 30)
            Arr_per_Floor[i] = new Room_Superior; //20 to 29 rooms will be of Superior type

            if(i >= 30 && i < 40)
            Arr_per_Floor[i] = new Room_Junior_Suite; //30 to 39 rooms will be of Junior Suite type

            if(i >= 40 && i < 50)
            Arr_per_Floor[i] = new Room_Suite; //40 to 49 rooms will be of Suite type
        }
        count_rooms_Standard  = count_rooms_Moderate = count_rooms_Superior = count_rooms_Junior_Suite = count_rooms_Suite = 0; //Initially set the count data members to 0 (No room reserved)
    }
    void increment_count_standard() //Increment function. To increment count standard variable.
    {
        count_rooms_Standard++;
    }
    void increment_count_Moderate() //Increment function. To increment count Moderate variable.
    {
        count_rooms_Moderate++;
    }
    void increment_count_superior() //Increment function. To increment count Superior variable.
    {
        count_rooms_Superior++;
    }
    void increment_count_Junior_Suite() //Increment function. To increment count Junior Suite variable.
    {
        count_rooms_Junior_Suite++;
    }
    void increment_count_suite() //Increment function. To increment count Suite variable.
    {
        count_rooms_Suite++;
    }
    int get_count_rooms_Standard() const //Getter for count of Standard rooms
    {
        return count_rooms_Standard;
    }
    int get_count_rooms_Moderate() const //Getter for count of Moderate rooms
    {
        return count_rooms_Moderate;
    }
    int get_count_rooms_Superior() const //Getter for count of Superior rooms
    {
        return count_rooms_Superior;
    }
    int get_count_rooms_Junior_Suite()const //Getter for count of Junior Suite rooms
    {
        return count_rooms_Junior_Suite;
    }
    int get_count_rooms_Suite() const //Getter for count of Suite rooms
    {
        return count_rooms_Suite;
    }
    void set_count_rooms_Standard(int i) //Setter for Standard Rooms
    {
        count_rooms_Standard = i;
    }
    void set_count_rooms_Moderate(int i) //Setter for Moderate Rooms
    {
        count_rooms_Moderate = i;
    }
    void set_count_rooms_Superior(int i) //Setter for Superior Rooms
    {
        count_rooms_Superior = i;
    }
    void set_count_rooms_Junior_Suite(int i) //Setter for Junior Suite Rooms
    {
        count_rooms_Junior_Suite = i;
    }
    void set_count_rooms_Suite(int i) //Setter for Suite Rooms
    {
        count_rooms_Suite = i;
    }
    Room* get_room(int j) const //Getter for the room on a respective floor.
    {
        return Arr_per_Floor[j];
    }
};

class Hotel //Class of Hotel
{
    private:
    string name;//Name of the hotel
    Floor *Floors_in_hotel; //The hotel has an array of floors with "Floor type" objects at indexes

    public:
    Hotel() //Default Constructor
    {
        Floors_in_hotel = new Floor[5]; //Array of 5 floors
    }
    Floor& get_floors(int index) const //Getter for the floor
    {
        return Floors_in_hotel[index]; //Return the entire floor
    }
    void print_count_rooms_in_empty_file()
    {
        ifstream ifs;
        ifs.open("count_rooms.dat");

        string get;
        getline(ifs,get);

        ofstream ofs;
        ofs.open("count_rooms.dat",ios::trunc);

        ofs<<"*\n";
        for(int i = 0; i < 5; ++i)
        {
            ofs<<"Count standard rooms on floor "<<i<<" is:\n"<<get_floors(i).get_count_rooms_Standard()<<endl; //Num of occupied standard rooms
            ofs<<"Count Moderate rooms on floor "<<i<<" is:\n"<<get_floors(i).get_count_rooms_Moderate()<<endl; //Num of occupied Moderate rooms
            ofs<<"Count Superior rooms on floor "<<i<<" is:\n"<<get_floors(i).get_count_rooms_Superior()<<endl; //Num of occupied Superior rooms
            ofs<<"Count Junior Suite rooms on floor "<<i<<" is:\n"<<get_floors(i).get_count_rooms_Junior_Suite()<<endl; //Num of occupied Junior Suite rooms
            ofs<<"Count Suite rooms on floor "<<i<<" is:\n"<<get_floors(i).get_count_rooms_Suite()<<endl<<"*"<<endl; //Num of occupied Suite rooms
        }
        ofs.close(); 
        ifs.close(); 
        return;
    }
    void print_reserved_rooms_data_in_file()
    {
        for(int i = 0; i < 5; ++i) //5 floors iteration
        {
            bool check = 0; //Bool check to find any reserved room else display cout statement
            for(int j = 0 ; j < 50; ++j) //50 rooms per floor
            {
                if((get_floors(i).get_room(j)->get_availability_for_reservation()) == 0) //If the room is reserved than initiate printing of the details
                {
                    cout<<"Floor Num: "<<i+1; //Floor num of the room
                    cout<<"\nRoom Number: "<<j+1; //Room number of the room
                    cout<<"\nRoom Type: "<<get_floors(i).get_room(j)->get_type(); //TYpe of the room
                    cout<<"\nReservation Availability: "<<get_floors(i).get_room(j)->get_availability_for_reservation(); //Reservation ability check of the room
                    cout<<"\nPrice per night: "<<get_floors(i).get_room(j)->get_price_per_24()<<endl<<endl; //Price of the room type
                    check = 1;
                }
            }
            if(check == 0) //If there is no room reserved
            cout<<"\nNo room reserved on floor: "<<i+1<<endl;
        }
    }
    void print_room_data_into_empty_file() //Function to print data of the rooms in rooms.dat file
    {
        string get;
        ofstream rooms_ofss;
        ifstream rooms_ifss;
        rooms_ofss.open("rooms.dat",ios::trunc); //Truncate and than update data
        rooms_ifss.open("rooms.dat");
        getline(rooms_ifss,get);
        rooms_ofss<<"*\n";
        for(int i = 0; i < 5; ++i) //F floors iteration
        {
            bool check = 0;
            rooms_ofss<<"Floor Number:\n"<<i+1<<endl<<endl; //FLoor num of the room
            for(int j = 0 ; j < 50; ++j)
            {
                //Displaying the data of the rooms
                if(j >= 0 && j < 10)
                rooms_ofss<<"Room Number:\n"<<j<<endl;

                if(j >= 10 && j < 20)
                rooms_ofss<<"Room Number:\n"<<j-10<<endl;
                
                if(j >= 20 && j < 30)
                rooms_ofss<<"Room Number:\n"<<j-20<<endl;

                if(j >= 30 && j < 40)
                rooms_ofss<<"Room Number:\n"<<j-30<<endl;

                if(j >= 40 && j < 50)
                rooms_ofss<<"Room Number:\n"<<j-40<<endl;

                rooms_ofss<<"Room Type:\n"<<get_floors(i).get_room(j)->get_type();
                rooms_ofss<<"\nReservation Availability:\n"<<get_floors(i).get_room(j)->get_availability_for_reservation();
                rooms_ofss<<"\nPrice per night:\n"<<get_floors(i).get_room(j)->get_price_per_24()<<endl<<endl;
                check = 1;
            }
        }
        rooms_ofss.close();
        rooms_ifss.close();
    }
    ~Hotel() //Destructor
    {
        delete[] Floors_in_hotel; 
    }
};

class Time //Class of time. 
{
    private: //Private data members
    int hours,minutes;

    public:
    Time() //Default constructor
    {
        hours = minutes = 0;
    }
    void set_hours(int hrs) //setter for hours
    {
        hours = hrs;
    }
    void set_minutes(int mins) //setter for minutes
    {
        minutes = mins;
    }
    int get_hours()const //getter for hours
    {
        return hours;
    }
    int get_minutes() const //getter for minutes
    {
        return minutes;
    }
    void get_current_time() //Get current time and date
    {
        cout<<"Enter the current minutes: "; //Get current minutes
        cin>>minutes;
        while(minutes > 59 || minutes <= 0) //Constraints
        {
            cout<<"Minutes cannot be less than 0 and greater than 60. Input again\n";
            cin>>minutes;
        }
        cout<<"Enter the current hours: "; //get hours
        cin>>hours;
        while(hours > 23 || hours <= 0) //Constraints
        {
            cout<<"Hours cannot be less than 0 and greater than 24. Input again\n";
            cin>>hours;
        }
    }
};

class Date //Class of Date
{
    private: //Private data members
    int date,month,year; 

    public:
    Date() //Default constructor
    {
        date = month = year = 0;
    }
    void set_date(int d) //setter for date 
    {
        date = d;
    }
    void set_month(int m) //setter for month
    {
        month = m;
    }
    void set_year(int y) //setter for year
    {
        year = y;
    }
    int get_date() const//getter for day
    {
        return date;
    }
    int get_month() const //getter for month
    {
        return month;
    }
    int get_year() const//getter for year
    {
        return year;
    }
    void operator++(int i) //Increment operator over loader
    {
        if(i == 1) //If argument is 1 than increment date
        date++;

        if(i == 2) //If argument is 2 than increment month
        month++;

        if(i == 3) //If argument is 3 than increment year
        year++;
    }
    void operator-(int i)  //Subtraction operator over loader
    {
        date -= i;
    }
    void get_current_date() //Get current time and date
    {
        cout<<"Enter the current month: "; //get month
        cin>>month;
        while(month > 12 || month <= 0)
        {
            cout<<"Month cannot be less than 0 and greater than 12. INput again\n";
            cin>>month;
        }
        cout<<"Enter the current day: "; //get day
        cin>>date;
        if(month == 4 || month == 9 || month == 6 || month == 11) //Days cannot be more than 30 in this month
        {
            while(date <= 0 || date > 30)
            {
                cout<<"Num of days in this month cannot be less than 0 and greater than 30 - Input Again\n";
                cin>>date;
            }  
        }
        else
        {
            while(date <= 0 || date > 31) //Days cannot be more than 31 in this month
            {
                cout<<"Num of days in this month cannot be less than 0 and greater than 31 - Input Again\n";
                cin>>date;
            }
        }
        cout<<"Enter the current year: ";
        cin>>year;
        while(year <= 0) //Year cannot be less than 0
        {
            cout<<"Year cannot be less than 0. INput again\n";
            cin>>year;
        }
    } 
    bool operator==(Date &temp) //Operator overloading == to compare all data members of class Date
    {
        if(this->date == temp.date && this->month == temp.month && this->year == temp.year)
        return 1;

        else
        return 0;

        return 0;
    }
};

class customer //Class of customer
{
    private: //Private Data members
    Room *R; //Room assigned to a customer
    string Full_Name,Gender,room_preferance; //String data members
    Time check_in_time,check_out_time,Time_remaining; //Type data type data members
    Date check_in_date,check_out_date,reservation_date; //Date data type data members
    long ID_Number; //Long data members
    int age, total_days_to_reserve, Floor_of_room, Room_Number; //int data members
    double balance; //double data members
    bool checked_in_or_not,checked_out_or_not; //Bool data members / checks

    public:
    customer() //Default Constructor
    {
        this->R = new Room(); //Each customer is assigned a room initially.
        //Set all data members to 0 initially to avoid garbage values
        check_in_date.set_date(0);
        check_in_date.set_month(0);
        check_in_date.set_year(0);
        check_in_time.set_hours(0);
        check_in_time.set_minutes(0);
        check_out_date.set_date(0);
        check_out_date.set_month(0);
        check_out_date.set_year(0);
        check_out_time.set_hours(0);
        check_out_time.set_minutes(0);
        Time_remaining.set_hours(0);
        Time_remaining.set_minutes(0);
        checked_in_or_not = 0;
        checked_out_or_not = 0;
    }
    void set_reservation_date(int date) //setter for reservation date i.e. when the customer reserved a room 
    {
        reservation_date.set_date(date);
    }
    void set_reservation_month(int month) //setter for reservation month i.e. when the customer reserved a room 
    {
        reservation_date.set_month(month);
    }
    void set_reservation_year(int year) //setter for reservation year i.e. when the customer reserved a room 
    {
        reservation_date.set_year(year);
    }
    int get_reservation_date() const //Getter for reservation date i.e. when the customer reserved a room 
    {
        int x = reservation_date.get_date();
        return x;
    }
    int get_reservation_month() const //Getter for reservation date i.e. when the customer reserved a room 
    {
        int x = reservation_date.get_month();
        return x;
    }
    int get_reservation_year() const //Getter for reservation date i.e. when the customer reserved a room 
    {
        int x = reservation_date.get_year();
        return x;
    }
    void set_checkin_or_not(bool check) //Setter for checkin check
    {
        checked_in_or_not = check;
    }
    bool get_checkin_or_not() const //Getter for checkin check
    {
        return checked_in_or_not;
    }
    void set_checkout_or_not(bool check) //Setter for checkout check
    {
        checked_out_or_not = check;
    }
    bool get_checkout_or_not() const //Getter for checkout check
    {
        return checked_out_or_not;
    }
    void set_room_preferance(string type) //Setter for chosen room type of the customer
    {
        room_preferance = type;
    }
    string get_room_preference() const //Getter for chosen room type of the customer
    {
        return room_preferance;
    }
    void operator++(int i) //Increment operator overloading
    {
        check_out_date.operator++(i);
    }
    void operator-(int i) //Subtraction operator overloading
    {
        check_out_date.operator-(i);
    }
    void set_Name(string name) //Setter for the name of the customer
    {
        Full_Name = name;
    }
    string get_Name() const //Getter for the name of the customer
    {
        return Full_Name;
    }
    void set_room_number(int num) //Setter for the room number assigned to the customer
    {
        Room_Number = num;
    }
    int get_room_number()  const //Getter for the room number assigned to the customer
    {
        return Room_Number;
    }
    void set_Age(int age) //Setter for the age of the customer
    {
        this->age = age;
    }
    int get_age() const//getter for the age of the customer
    {
        return age;
    }
    void set_Gender(string gender) //Setter for the gender
    {
        Gender = gender;
    }
    string get_Gender() const //Getter for the gender
    {
        return Gender;
    }
    void set_ID(int number) //Setter for the ID
    {
        ID_Number = number;
    }
    long get_ID() const //Getter for the ID
    {
        return ID_Number;
    }
    void set_reservation_days(int days) //Setter for the num of reservation days
    {
        total_days_to_reserve = days;
    }
    int get_reservation_days()const //Getter for the num of reservation days
    {
        return total_days_to_reserve;
    }
    void set_room(Room *room) //Setter for the room assigned 
    {
        R = room;
    }
    void set_floor_of_room(int floor) //Setter for the floor num assigned to the customer
    {
        Floor_of_room = floor;
    }
    int get_floor_of_room()const //Getterfor floor of the room
    {
        return Floor_of_room;
    }
    void set_balance(int amount) //Setter for the balance
    {
        balance = amount;
    }
    Room& get_room()const //Getter of the room
    {
        return *R;
    }
    int get_balance()const //Getter for the balance
    {
        return balance;
    }
    void set_check_in_hours(int hrs) //Setter for checkin hours
    {
        check_in_time.set_hours(hrs);
    }
    void set_check_in_minutes(int mins) //Setter for check in minutes
    {
        check_in_time.set_minutes(mins);
    }
    int get_check_in_hours() const //Getter for check in hours
    {
        int hrs = check_in_time.get_hours();
        return hrs;
    }
    int get_check_in_minutes() const //getter for check in minutes
    {
        int mins = check_in_time.get_minutes();
        return mins;
    }
    void set_check_out_hours(int hrs) //Setter for checkout hours
    {
        check_out_time.set_hours(hrs);
    }
    void set_check_out_minutes(int mins) //Setter for checkout minutes
    {
        check_out_time.set_minutes(mins);
    }
    int get_check_out_hours() const //Getter for checkout hours
    {
        int hrs = check_out_time.get_hours();
        return hrs;
    }
    int get_check_out_minutes() const //Getter for checkout minutes
    {
        int mins = check_out_time.get_minutes();
        return mins;
    }
    void set_check_in_date(int d) //Setter for check in date
    {
        check_in_date.set_date(d);
    }
    void set_check_in_month(int m) //Setter for checkin month
    {
        check_in_date.set_month(m);
    }
    void set_check_in_year(int y) //Setter for checkin year
    {
        check_in_date.set_year(y);
    }
    int get_check_in_date() const //Getter for checkin date
    {
        int date = check_in_date.get_date();
        return date;
    }
    int get_check_in_month()const //Getter for checkin month
    {
        int month = check_in_date.get_month();
        return month;
    }
    int get_check_in_year()  const//Getter for checkin year
    {
        int year = check_in_date.get_year();
        return year;
    }
    void set_check_out_date(int d) //Getter for check out date
    {
        check_out_date.set_date(d);
    }
    void set_check_out_month(int m) //Setter for checkout month
    {
        check_out_date.set_month(m);
    }
    void set_check_out_year(int y) //Setter for checkout year
    {
        check_out_date.set_year(y);
    }
    int get_check_out_date() const //Getter for checkout date
    {
        int date = check_out_date.get_date();
        return date;
    }
    int get_check_out_month() const //Getter for checkout month
    {
        int month = check_out_date.get_month();
        return month;
    }
    int get_check_out_year() const //Getter for checkout year
    {
        int year = check_out_date.get_year();
        return year;
    }
    void set_remaining_time(int hrs) //Setter for remainig time
    {
        Time_remaining.set_hours(hrs);
    }
    int get_remaining_time() const //Getter for remainig time
    {
        int hrs = Time_remaining.get_hours();
        return hrs;
    }
    void print_cutomer_data_file(int index)
    {
        ofstream ofs;
        ofs.open("customers.dat",ios::out | ios::app); //Appends the customers
        ofs<<"Customer:\n"<<index<<endl<<"Name:\n"<<get_Name()<<endl<<"Age:\n"<<get_age()<<endl<<"Gender:\n"<<get_Gender()<<endl<<"ID Card Num:\n"<<get_ID()<<endl<<"Num of days in hotel:\n"<<get_reservation_days()<<endl<<"Room type:\n"<<get_room_preference()<<endl<<"Floor Number:\n"<<get_floor_of_room()<<endl<<"Room number:\n"<<get_room_number()<<endl;
        ofs<<"Balance:\n"<<get_balance()<<endl;
        ofs<<"Checkin hours:\n"<<get_check_in_hours()<<endl<<"Checkin minutes:\n"<<get_check_in_minutes()<<endl;
        ofs<<"Checkin Date:\n"<<get_check_in_date()<<endl<<"Checkin Month:\n"<<get_check_in_month()<<endl<<"Checkin Year:\n"<<get_check_in_year()<<endl;
        ofs<<"Checkout hours:\n"<<get_check_out_hours()<<endl<<"Checkout minutes:\n"<<get_check_out_minutes()<<endl;
        ofs<<"Checkout Date:\n"<<get_check_out_date()<<endl<<"Checkout Month:\n"<<get_check_out_month()<<endl<<"Checkout Year:\n"<<get_check_out_year()<<endl;
        ofs<<"Time Remaining in Hotel:\n"<<get_remaining_time()<<endl<<"Has checked in or not:\n"<<get_checkin_or_not()<<endl<<"Has checked out or not:\n"<<get_checkout_or_not()<<endl;
        ofs<<"Reservation Day:\n"<<get_reservation_date()<<endl<<"Reservation Month:\n"<<get_reservation_month()<<endl<<"Reservation Year:"<<endl<<get_reservation_year()<<endl<<endl;
        ofs.close();
    }
    void assign_room_to_customer(Hotel &H,string room_type) //This global function assigns a suitable room to the customer
    {
        int i = 0,num = 0;
        for(i = 0; i < 5; ++i) //Iterate through the floors
        {
            if(room_type == "Standard") //If chosen room type is Standard
            {
                num = H.get_floors(i).get_count_rooms_Standard(); //If 
                if(num <= 9) //If such a room is available on the floor i
                {
                    for(int j = 0; j < 10; ++j)
                    if(H.get_floors(i).get_room(j)->get_availability_for_reservation() == 1) //If the floor is available for reservation
                    {
                        set_room(H.get_floors(i).get_room(j)); 
                        H.get_floors(i).increment_count_standard();
                        get_room().set_availability_for_reservation(0); //Change availability of room to 0
                        set_room_number(H.get_floors(i).get_count_rooms_Moderate());
                        break;
                    }
                break;
                }
            }
            if(room_type == "Moderate") //If chosen room type is Moderate
            {
                num = H.get_floors(i).get_count_rooms_Moderate();
                if(num <= 9) //If such a room is available on the floor i
                {
                    for(int j = 10; j < 20; ++j)
                    if(H.get_floors(i).get_room(j)->get_availability_for_reservation() == 1) //If the floor is available for reservation
                    {
                        set_room(H.get_floors(i).get_room(j));
                        H.get_floors(i).increment_count_Moderate();
                        get_room().set_availability_for_reservation(0); //Change availability of room to 0
                        set_room_number(H.get_floors(i).get_count_rooms_Moderate());
                    } 
                break;
                }
            }
            if(room_type == "Superior") //If chosen room type is Superior
            {
                num = H.get_floors(i).get_count_rooms_Superior();
                if(num <= 9) //If such a room is available on the floor i
                {
                    for(int j = 20; j < 30; ++j)
                    if(H.get_floors(i).get_room(j)->get_availability_for_reservation() == 1) //If the floor is available for reservation
                    {
                        set_room(H.get_floors(i).get_room(j));
                        H.get_floors(i).increment_count_superior();
                        get_room().set_availability_for_reservation(0); //Change availability of room to 0
                        set_room_number(H.get_floors(i).get_count_rooms_Superior());
                    }
                    break;
                }
            }
            if(room_type == "Junior Suite")  //If chosen room type is Junior Suite
            {
                num = H.get_floors(i).get_count_rooms_Junior_Suite();
                if(num <= 9) //If such a room is available on the floor i
                {
                    for(int j = 30; j < 40; ++j)
                    if(H.get_floors(i).get_room(j)->get_availability_for_reservation() == 1) //If the floor is available for reservation
                    {
                        set_room(H.get_floors(i).get_room(j));
                        H.get_floors(i).increment_count_Junior_Suite();
                        get_room().set_availability_for_reservation(0); //Change availability of room to 0
                        set_room_number(H.get_floors(i).get_count_rooms_Junior_Suite());                            
                    }
                    break;
                }
            }
            if(room_type == "Suite")  //If chosen room type is Suite
            {
                num = H.get_floors(i).get_count_rooms_Suite();
                if(num <= 9) //If such a room is available on the floor i
                {
                    for(int j = 4; j < 50; ++j)
                    if(H.get_floors(i).get_room(j)->get_availability_for_reservation() == 1) //If the floor is available for reservation
                    {
                        set_room(H.get_floors(i).get_room(j));
                        H.get_floors(i).increment_count_suite();
                        get_room().set_availability_for_reservation(0); //Change availability of room to 0
                        set_room_number(H.get_floors(i).get_count_rooms_Suite());
                    }
                    break;
                }
            }
            if(i == 4) //If such a room is not available on any floor
            {
                cout<<"\nNo room of your choice is available.Which room type would you like?Enter Standard,Moderate,Superior,Junior Suite or Suite: "; //Choose a room of anyother type
                cin.ignore();
                getline(cin,room_type);
                while(room_type != "Standard" && room_type != "Moderate" && room_type != "Superior" && room_type != "Junior Suite" && room_type != "Suite") //Constraints Checker
                {
                    cout<<"Invalid Input - Please input again\n";
                    getline(cin,room_type); //Input room type again
                }
                i = 0; //Restart iteration
            }
        }
        set_floor_of_room(i); //Set the floor number in the customer's data member of floor
    }
    Date& return_checkin_date() //Returning a customers checkin date object
    {
        return this->check_in_date; //Return object of Date
    }
};

void customer_input_data(int done,Hotel &H,customer customers_arr[],int &customer_arr_size,Date &current_date,int restart_reservation = 0) //INput data of the user
{
    if(done == 1) //If data has been input than return
    return;

    int check_all = 0; //To check if a room is available or not
    for(int i = 0; i < 5; ++i) //If all rooms are booked than no need for booking/reservation
    {
        check_all += H.get_floors(i).get_count_rooms_Standard();
        check_all += H.get_floors(i).get_count_rooms_Moderate();
        check_all += H.get_floors(i).get_count_rooms_Superior();
        check_all += H.get_floors(i).get_count_rooms_Junior_Suite();
        check_all += H.get_floors(i).get_count_rooms_Suite();
    }
    if(check_all >= 250) //All rooms are booked
    {
        cout<<"\nReservation cannot be initiated because all rooms are booked\n";
        return; //Cannot reserve room
    }
    int opt_res = 0;
    if(restart_reservation == 0) //Initiate reservation
    {
        cout<<"\nReservation Initiating\nIs it your first time at the Hotel? or Not?\nEnter 1 for new and 2 for existing\n";
        cin>>opt_res; //Input type of reservation
    }

    cout<<endl;
    if(opt_res == 1) //Getting data
    {
        cout<<"\n\nPlease enter your Full Name: "; //Enter name
        string name;
        cin.ignore();
        getline(cin,name);

        customers_arr[customer_arr_size-1].set_Name(name);

        cout<<"\nPlease enter your Age: "; //Enter Age
        int age = 1;
        cin>>age;
        while(age <= 0)
        {
            cout<<"Age cannot be less than 0 - Please input age again\n";
            cin>>age;
        }
        customers_arr[customer_arr_size-1].set_Age(age);

        cout<<"\nEnter your Gender: "; //Enter Gender
        string gender;
        cin>>gender;
        while(gender != "Male" && gender != "male" && gender != "Female" && gender != "female")
        {
            cout<<"Invalid Gender - Please enter gender again\n";
            cin>>gender;
        }
        customers_arr[customer_arr_size-1].set_Gender(gender); //Set Gender

        cout<<"\nPlease enter you Id-Card Number: "; //Eder ID card number
        long numb;
        cin>>numb;
        int k = 0;
        while(numb <= 0 || k != customer_arr_size) //ID cannot be less than 0 and it should be assigned to a customer
        {
            if(numb <= 0) //ID not less or equal to 0
            {
                cout<<"Id card num cannot be negative. Please enter again\n";
                cin>>numb;
            }
            if(customers_arr[k].get_ID() == numb)
            {
                cout<<"This ID already exists. PLease enter again\n";
                cin>>numb;
            }
            k++;
        }

        customers_arr[customer_arr_size-1].set_ID(numb); //Set ID

        cout<<"\nHow long is your stay? "; //Enter num of days of reservation
        int days;
        cin>>days;
        while(days <= 0) //Constraints Check
        {
            cout<<"Number of days cannot be less than or equal 0 - Please input again\n";
            cin>>days;
        }
        customers_arr[customer_arr_size-1].set_reservation_days(days); //Set reservation days

        int i = 0,num = 0;
        cout<<"\nWhich room type would you like?Enter Standard,Moderate,Superior,Junior Suite or Suite: "; //Choose room type
        string room_type;
        cin.ignore();
        getline(cin,room_type);
        while(room_type != "Standard" && room_type != "Moderate" && room_type != "Superior" && room_type != "Junior Suite" &&  room_type != "Suite") //Constraints checker
        {
            cout<<"Invalid Room Type - Please input again\n";
            cin>>room_type;
        }
            
        customers_arr[customer_arr_size-1].set_room_preferance(room_type); //Set chosen room type

        customers_arr[customer_arr_size-1].assign_room_to_customer(H,room_type); //Calling the function that assigns a room to a user

        customers_arr[customer_arr_size-1].set_reservation_date(current_date.get_date()); //set days
        customers_arr[customer_arr_size-1].set_reservation_month(current_date.get_month()); //set month
        customers_arr[customer_arr_size-1].set_reservation_year(current_date.get_year()); //set year

        //Checkin details
        cout<<"\nPlease enter the checkin details\n";
        int year;
        cout<<"\nEnter Year: "; //Enter Year
        cin>>year;
        while(year < current_date.get_year()) //Constraints Checker
        {
            cout<<"Year cannot be less than current year. - Please input year again\n";
            cin>>year;
        }

        cout<<"Enter months: "; //Enter Month
        int month = 0;
        cin>>month;
        while(month <= 0 || month > 12 || (year == current_date.get_year() && (month < current_date.get_month()))) //Constraints Checker
        {
            cout<<"Month Number must be in range 0 to 12 - Please input month again\n";
            cin>>month;
        }

        int date;
        cout<<"Enter Date: "; //ENter date
        cin>>date;
        if(month == 4 || month == 9 || month == 6 || month == 11) //If month has 30 days
        {
            while(date <= 0 || date > 30 || ((year == current_date.get_year()) && (month == current_date.get_month()) && (date < current_date.get_date()))) //constraints checker
            {
                cout<<"Invalid Input - Input Again\n";
                cin>>date;
            }
        }
        else //If month has 31 days
        {
            while(date <= 0 || date > 31 || ((year == current_date.get_year()) && (month == current_date.get_month()) && (date < current_date.get_date()))) //constraints checker
            {
                cout<<"Invalid Input - Input Again\n";
                cin>>date;
            }
        }

        customers_arr[customer_arr_size-1].set_check_in_date(date); //date setter
        customers_arr[customer_arr_size-1].set_check_in_month(month); //month setter
        customers_arr[customer_arr_size-1].set_check_in_year(year); //year getter

        cout<<"\nWill you pay in advance or upon checkout? Enter 1 for now or 2 for upon checkout: "; //inpt balance
        int opt_balance = 0;
        cin>>opt_balance;
        while(opt_balance != 1 && opt_balance != 2) //chose option
        {
            cout<<"Choose either 1 or 2. Please Input again\n";
            cin>>opt_balance;
        }
        double balance_right_now = customers_arr[customer_arr_size-1].get_reservation_days() * customers_arr[customer_arr_size-1].get_room().get_price_per_24(); //calculating balance
        if(opt_balance == 1) //Pay now
        {
            cout<<"\nYour Balance is: "<<balance_right_now<<endl<<"Thanks for paying\nNow your balance is 0\n";
            customers_arr[customer_arr_size-1].set_balance(0);
        }
        if(opt_balance == 2) //Pay at checkout
        {
            customers_arr[customer_arr_size-1].set_balance(balance_right_now);
            cout<<"\nYour Balance upon Checkout is: "<<balance_right_now<<endl;
        }
    
        customers_arr[customer_arr_size-1].set_checkin_or_not(0); //set the bool check equal to 0

        customers_arr[customer_arr_size-1].print_cutomer_data_file(customer_arr_size-1); //Update customer data file
        return;
    }
    if(opt_res == 2 || restart_reservation == 1) //If the customer is already in customers.dat file
    {
        long customer_ID_Input;
        cout<<"Please enter your ID: "; //ENter ID search for the customer
        cin>>customer_ID_Input;
        cout<<endl<<endl;

        if(customer_arr_size == 0) //if array size is 0 than ofcours there is no customer dat in file
        {
            cout<<"No customer in data base\nExiting program\n";
            return;
        }

        bool check = 0;
        int i = 0;
        for(i = 0; i < customer_arr_size; ++i)
        {
            if(customers_arr[i].get_ID() == customer_ID_Input)//IF ID match 
            {
                check = 1;
                cout<<"Enter your room type preference plz\n"; //Input room type preference
                string choice;
                cin.ignore();
                getline(cin,choice);
                while(choice != "Standard" && choice != "Moderate" && choice != "Superior" && choice != "Junior Suite" && choice != "Suite")
                {
                    cout<<"Invalid Room Type. Please input choice again: ";
                    getline(cin,choice);
                }
                customers_arr[i].assign_room_to_customer(H,choice); //Assign a room to the customer
                customers_arr[i].print_cutomer_data_file(i); //Update customer data file
                break;
            }
        }

        if(check == 0) //If there is no customer with the input ID
        {
            cout<<"No customer found by this ID in data base\n";
            return;
        }
    }
}

void extract_previous_customer_data_from_file(customer customers_arr[]) //Function to extract data from the "customers.dat" file
{
    ifstream all_arr; //Ifstream object
    string get;
    all_arr.open("customers.dat"); //Opening customers.dat file
    int count = 0,i = -1;
    if(all_arr.is_open())
    {
        while(!all_arr.eof()) //Execute till end of file
        {
            getline(all_arr,get);
            count++;

            if(get == "Customer:") //New customer data input started
            {
                count = 1;
                i++;
                continue;
            }
                
            if(count == 4)
            customers_arr[i].set_Name(get); //Read name
                    
            if(count == 5)
            {
                int age;
                all_arr>>age;
                customers_arr[i].set_Age(age); //Read age
            }
            
            if(count == 8)
            customers_arr[i].set_Gender(get); //Read gender
                    
            if(count == 9)
            {
                long int ID;
                all_arr >>ID;
                customers_arr[i].set_ID(ID); //Read ID
            }
                    
            if(count == 11)
            {
                int days;
                all_arr>>days;
                customers_arr[i].set_reservation_days(days); //Read num of reservation days
            }
            
            if(count == 14)
            customers_arr[i].set_room_preferance(get); //Read room type 
                    
            if(count == 15)
            {
                int floor;
                all_arr>>floor;
                customers_arr[i].set_floor_of_room(floor); //Read floor of the room assigned to the customer
            }
            
            if(count == 17)
            {
                int room;
                all_arr>>room;
                customers_arr[i].set_room_number(room); //Read num of the room 
            }
                    
            if(count == 19)
            {
                double balance;
                all_arr>>balance;
                customers_arr[i].set_balance(balance); //Read balance
            }
            
            if(count == 21)
            {
                int hours;
                all_arr>>hours;
                customers_arr[i].set_check_in_hours(hours); //Read checkin hours
            }
                    
            if(count == 23)
            {
                int mins;
                all_arr>>mins;
                customers_arr[i].set_check_in_minutes(mins); //Read checkin mins
            }
                    
            if(count == 25)
            {
                int date;
                all_arr>>date;
                customers_arr[i].set_check_in_date(date); //Read checkin day
            }
                    
            if(count == 27)
            {
                int month;
                all_arr>>month;
                customers_arr[i].set_check_in_month(month); //Read checkin month
            }
                    
            if(count == 29)
            {
                int year;
                all_arr>>year;
                customers_arr[i].set_check_in_year(year); //Read checkin year
            }
                    
            if(count == 31)
            {
                int hours;
                all_arr>>hours;
                customers_arr[i].set_check_out_hours(hours); //Read checkout hours
            }
                    
            if(count == 33)
            {
                int mins;
                all_arr>>mins;
                customers_arr[i].set_check_out_minutes(mins); //Read checkout min
            }
                    
            if(count == 35)
            {
                int date;
                all_arr>>date;
                customers_arr[i].set_check_out_date(date); //Read checkout  day
            }
                    
            if(count == 37)
            {
                int month;
                all_arr>>month;
                customers_arr[i].set_check_out_month(month); //Read checkout month
            }
                    
            if(count == 39)
            {
                int year;
                all_arr>>year;
                customers_arr[i].set_check_out_year(year); //Read checkout year
            }
                    
            if(count == 41)
            {
                int time;
                all_arr>>time;
                customers_arr[i].set_remaining_time(time); //Read remaining time
            }

            if(count == 43)
            {
                bool check;
                all_arr>>check;
                customers_arr[i].set_checkin_or_not(check); //Read variable checkin or not
            }
            if(count == 45)
            {
                bool check;
                all_arr>>check;
                customers_arr[i].set_checkout_or_not(check); //Read variable checkout or not
            }
            if(count == 47)
            {
                int date;
                all_arr>>date;
                customers_arr[i].set_reservation_date(date); //Read reservation date
            }
            if(count == 49)
            {
                int month;
                all_arr>>month;
                customers_arr[i].set_reservation_month(month); //Read reservation month
            }
            if(count == 51) //read reservation year
            {
                int year;
                all_arr>>year;
                customers_arr[i].set_reservation_year(year); //Read reservation year
            }
        }
        all_arr.close();
    }
    else //If customeers.dat file is not in folder
    {
        cout<<"\nThere is no file by the name of customer.dat\nCreating one for you\n"; //In case there is no such file by such a name
        ofstream ofs;
        ofs.open("customers.dat",ios::trunc);
        cout<<"Now continue\n";
        extract_previous_customer_data_from_file(customers_arr); //Recursive call to extract previous customers data
    }
}

void read_count_rooms_from_file(Hotel &H) //Reading the count variables value from file "count_rooms.dat"
{
    ifstream ifs;
    ifs.open("count_rooms.dat");
    string get;
    if(ifs.is_open())
    {
        int index_floor = -1,x = 0,count = 0;
        while(ifs) //Executing file till the end
        {
            getline(ifs,get);
            if(get == "*") //If "*" char appears than increment floor index
            { 
                index_floor++;
                count = 1;
            }
            count++;
            if(count == 3) //Read value of count Standard
            {
                ifs>>x;
                H.get_floors(index_floor).set_count_rooms_Standard(x);
            }

            if(count == 5) //Read value of count Moderate
            {
                ifs>>x;
                H.get_floors(index_floor).set_count_rooms_Moderate(x);
            }
    
           if(count == 7) //Read value of count Superior
            {
                ifs>>x;
                H.get_floors(index_floor).set_count_rooms_Superior(x);
            }

            if(count == 9) //Read value of count Junior Suite
            {
                ifs>>x;
                H.get_floors(index_floor).set_count_rooms_Junior_Suite(x);
            }

            if(count == 11) //Read value of count Suite
            {
                ifs>>x;
                H.get_floors(index_floor).set_count_rooms_Suite(x);
            }
        }
    ifs.close();
    }
}


int main()
{
    Hotel H; //Hotel Object //1 hotel per cpp

    Time current_Time; //Current Time object
    current_Time.get_current_time();
    Date current_Date; //Current Date object
    current_Date.get_current_date();

    while(1)
    {
        cout<<"\nSaleh Ahmad 20I-0605\nOOP SP21 Project\nHotel Management System\n\n\n******* Menu *******\n\n1- Press 1 to Reserve a Room\n2- Press 2 to Checkin a Customer/Visitor\n3- Press 3 to View Reserved Rooms\n4- Press 4 to see Detail Report\n5- Press 5 to exit\n\n";
        int choice_menu = 0;
        cin>>choice_menu;
        
        bool check = 0;
        while(choice_menu != 1 && choice_menu != 2 && choice_menu != 3 && choice_menu != 4 && choice_menu != 5) //Value check if correct
        {
            cout<<"Invalid choice menu seleted. Please enter again\n";
            cin>>choice_menu;
            check = 1;
        }
        int customer_arr_size = 0; //Initial customer array size = 0

        ifstream all_arrr;
        all_arrr.open("customers.dat"); //Open customers.dat file
        int counts = 0;
        string get = "";
        while(all_arrr)
        {
            getline(all_arrr,get);
            if(get == "Customer:")
            counts++; //Check num of customers by checking the occurence of string "Customer:"
        }
        all_arrr.close();

        ofstream customersTotal;
        customersTotal.open("TotalCustomers.dat",ios::trunc | ios::out);
        if(counts == 0)
        {
            customer_arr_size = 0;
            customersTotal<<0; //If the file will be empt than the array size will be 0
        }
        else
        {
            customer_arr_size = counts; //size equal to the num of customers in file
            customersTotal<<counts<<endl;
        }
        customersTotal.close();
        customer_arr_size++;

        int restart_reservation = 0;
        ifstream rooms; //Input data of all rooms from file
        rooms.open("rooms.dat");
        string s; 
        int floor_variable = -1,room_variable = -1,count = 0,x = 0;
        getline(rooms,s);
        if(rooms.is_open())
        {
            if(s == "*")
            {
                while(rooms)
                {
                    getline(rooms,s);
                    count++;

                    if(s == "Floor Number:")
                    {
                        floor_variable++; //Increment Floor Variable
                        room_variable = -1; //Restart room variable from index 0 
                    }

                    if(s == "Room Number:")
                    room_variable++; //Increment room variable

                    if(s == "Reservation Availability:")
                    {
                        rooms>>x; //Set the current reservation availability
                        H.get_floors(floor_variable).get_room(room_variable)->set_availability_for_reservation(x);
                    }
                }
            }
        }
        rooms.close();
        read_count_rooms_from_file(H); //Read the current num of counts of rooms

        ifstream ifs;
        ifs.open("count_rooms.dat");
        getline(ifs,get);
        if(get != "*")
        H.print_count_rooms_in_empty_file(); //Print the num of rooms already occupied in to the file count_rooms.dat

        //Update customer arr size by checking num from customer.dat file inbetween * *. Do this by sir's method
        customer customers_arr[customer_arr_size]; //Array of customer type objects

        //Extract data of previous customers
        if(customer_arr_size > 0)
        extract_previous_customer_data_from_file(customers_arr);  //Only if the customer number is 1 or greater than extract data from the file

        //Set the data from all_rooms.dat file to the respective rooms. To use them later. after all working has been done re update the data.
        H.print_room_data_into_empty_file();

        if(choice_menu == 1) //Menu option 1 //Reservation
        {
            customer_input_data(0,H,customers_arr,customer_arr_size,current_Date,restart_reservation);
            ofstream customersTotal;
            customersTotal.open("TotalCustomers.dat",ios::trunc);
            customersTotal<<customer_arr_size;
            customersTotal.close();
            H.print_count_rooms_in_empty_file();
            H.print_room_data_into_empty_file();

            cout<<"\nDo you want to print daily report? Enter 1 for yes 2 for no\n";
            int choice;
            cin>>choice;
            if(choice == 1)
            choice_menu = 4;
        }

        if(choice_menu == 2)  //Menu option 2
        {
            ifstream ifs;
            ifs.open("TotalCustomers.dat");
            int x;
            ifs>>x;
            ifs.close();

            if(x == 0)
            {
                cout<<"Customer.dat file is empty.\n";
                continue;
            }

            long ID;
            cout<<"Enter the ID of the customer: \n"; //Enter the ID //ID of each and every customer will be unique
            cin>>ID;

            customer_arr_size = x;
            bool check = 0;
            for(int i = 0; i < customer_arr_size; ++i) //For all the customers check the input ID.
            {
                if((customers_arr[i].get_ID() == ID) && (current_Date.operator==(customers_arr[i].return_checkin_date())))
                {
                    check = 1;
                    if(customers_arr[i].get_checkin_or_not() == 1) //If the user has not checked in already
                    cout<<"The customer has checked in before and now doesnot have a room reserved for him\n";

                    else
                    {
                        customers_arr[i].set_checkin_or_not(1); //Set the checkin bool check equal to true for the customer

                        customers_arr[i].set_check_in_hours(current_Time.get_hours()); //Set hours
                        customers_arr[i].set_check_in_minutes(current_Time.get_minutes()); //Set minutes

                        customers_arr[i].set_check_out_hours(customers_arr[i].get_check_in_hours()); //Set hours
                        customers_arr[i].set_check_out_minutes(customers_arr[i].get_check_in_minutes()); //Set minutes

                        //Checkout Day
                        int checkout_date = 0;
                        checkout_date += (customers_arr[i].get_check_in_date() + customers_arr[i].get_reservation_days()); //Find checkout date
                        customers_arr[i].set_check_out_date(checkout_date);

                        //If the month is of 30 days
                        if(customers_arr[i].get_check_in_month() == 4 || customers_arr[i].get_check_in_month() == 9 || customers_arr[i].get_check_in_month() == 6 || customers_arr[i].get_check_in_month() == 11 )
                        {
                            bool check = 0;
                            while(customers_arr[i].get_check_out_date() > 30) //if total days become greater than 30
                            {
                                check = 1;
                                customers_arr[i].operator-(30); //date decrease by 30
                                customers_arr[i].set_check_out_month(customers_arr[i].get_check_in_month() + 1);
                                if(customers_arr[i].get_check_out_month() > 12)
                                {
                                    customers_arr[i].operator++(2);//Month increment
                                    customers_arr[i].set_check_out_month(1);
                                    customers_arr[i].operator++(3); //year increment
                                }
                            }
                            if(check == 0) //If day is not greater than 30
                            {
                                customers_arr[i].set_check_out_month(customers_arr[i].get_check_in_month());
                                customers_arr[i].set_check_out_year(customers_arr[i].get_check_in_year());
                            }
                        }
                        //If month has 31 days
                        else
                        {
                            bool check = 0;
                            while(customers_arr[i].get_check_out_date() > 31) //if total days become greater than 31
                            {
                                check = 1;
                                customers_arr[i].operator-(31); //date decrease by 31
                                customers_arr[i].set_check_out_month(customers_arr[i].get_check_in_month() + 1);
                                if(customers_arr[i].get_check_out_month() > 12)
                                {
                                    customers_arr[i].operator++(2);//Month increment
                                    customers_arr[i].set_check_out_month(1);
                                    customers_arr[i].operator++(3); //year increment
                                }  
                                break;
                            }
                            if(check == 0) //If day is not greater than 31
                            {
                                customers_arr[i].set_check_out_month(customers_arr[i].get_check_in_month());
                                customers_arr[i].set_check_out_year(customers_arr[i].get_check_in_year());
                            }
                        }

                        customers_arr[i].print_cutomer_data_file(i); //Print te updated data onto the file

                        int hours_remaining = 0; //Time remaining in hotel calculation
                        hours_remaining += ((customers_arr[i].get_check_out_year() - customers_arr[i].get_check_in_year()) * 8760); //Year to hours
                        hours_remaining += ((customers_arr[i].get_check_out_month() - customers_arr[i].get_check_in_month()) * 730); //Month to hours
                        hours_remaining += ((customers_arr[i].get_check_out_date() - customers_arr[i].get_check_in_date()) * 24); //Date to hours
                                                        
                        customers_arr[i].set_remaining_time(hours_remaining); //Set remaining time in dara member

                        cout<<"Customer Checked IN\n";

                        //Set all the below data members equal to 0 because customer has checked in
                        customers_arr[i].set_check_in_date(0); 
                        customers_arr[i].set_check_in_month(0);
                        customers_arr[i].set_check_in_year(0);
                        customers_arr[i].set_check_in_minutes(0);
                        customers_arr[i].set_check_in_hours(0);
                        customers_arr[i].print_cutomer_data_file(i); //Update customer data in file
                        H.print_count_rooms_in_empty_file();
                        break;
                    }
                }
            }

            if(check == 0) //If No customer has this ID
            {
                cout<<"No such customer has reserved a room or the checkin time has passed\n";
                H.print_room_data_into_empty_file(); //Updating rooms data into file
            }      
        }

        if(choice_menu == 3)  //Menu option 3
        {
            cout<<"\n***** Check the rooms.dat file. It has been updated *****\n"; //Printing reserved rooms in rooms.dat
            H.print_room_data_into_empty_file(); //All rooms data update in all_rooms.dat file
            H.print_reserved_rooms_data_in_file(); //reserved rooms data
        }

        if(choice_menu == 4)  //Menu option 4
        {
            ifstream ifs;
            ifs.open("TotalCustomers.dat");
            int x;
            ifs>>x; //Read num of customers
            ifs.close();

            customer_arr_size = x;
            if(x == 0) //if size = 0 than it means file is empty. So exit the program
            cout<<"Customer.dat file is empty.\n";
            
            int count_checkin_today = 0,count_checkout_today = 0; //Num of checkins and checkouts today
            cout<<"\n***** Detailed Report *****\n\n"; //Detailed Report
            for(int i = 0; i < customer_arr_size; ++i) //Iterating array
            {
                if(customers_arr[i].get_check_in_year() == current_Date.get_year() && customers_arr[i].get_check_in_month() == current_Date.get_month() && customers_arr[i].get_check_in_date() == current_Date.get_date())
                count_checkin_today++; //count checkins today

                if((customers_arr[i].get_check_out_year() == current_Date.get_year()) && (customers_arr[i].get_check_out_month() == current_Date.get_month()) && customers_arr[i].get_check_out_date() == current_Date.get_date())
                count_checkout_today++; //count checkout today
            }
            ofstream ofs; //Print the detail report onto file
            ofs.open("Detail_Report.dat",ios::trunc); //Open detail report file
            ofs<<count_checkin_today<<" Customers have checked in today\n"; //Print
            ofs<<count_checkout_today<<" Customers have checked out today\n\n"; //Print

            ofs<<"Details of the rooms checked in today\n";
            for(int i = 0; i < customer_arr_size; ++i) //Iterating array
            {
                if((current_Date.get_date() == customers_arr[i].get_reservation_date()) && (current_Date.get_month() == customers_arr[i].get_reservation_month()) && (current_Date.get_year() == customers_arr[i].get_reservation_year()))
                ofs<<"\nPrice of Room: "<<customers_arr[i].get_room().get_price_per_24()<<"\nType of Room: "<<customers_arr[i].get_room().get_type()<<"\nAvailablity of Room: "<<customers_arr[i].get_room().get_availability_for_reservation()<<endl<<endl;
            }
            
            //Print details of the rooms from which checkout happened
            ofs<<"\nDetails of the rooms checked out today\n"; //Print rooms checkoted today
            for(int i = 0; i < customer_arr_size; ++i)
            {
                //If following check is true
                if((current_Date.get_date() == customers_arr[i].get_check_out_date()) && (current_Date.get_month() == customers_arr[i].get_check_out_month()) && (current_Date.get_year() == customers_arr[i].get_check_out_year()) &&  (customers_arr[i].get_checkout_or_not() == 1))
                ofs<<"\nPrice of Room: "<<customers_arr[i].get_room().get_price_per_24()<<"\nType of Room: "<<customers_arr[i].get_room().get_type()<<"\nAvailablity of Room: "<<customers_arr[i].get_room().get_availability_for_reservation()<<endl<<endl;
            }
            ofs.close();
        }

        if(choice_menu == 5) //Menu option 5
        {
            exit(0); //Exit the program
        }

        ifs.open("TotalCustomers.dat");
        x;
        ifs>>x; //Get updated total customers
        ifs.close();
        customer_arr_size = x;
        
        for(int i = 0; i < customer_arr_size; ++i) //Iterating the array
        {
            if((customers_arr[i].get_checkout_or_not() == 0) && (customers_arr[i].get_checkin_or_not() == 1))
            {
                if(((current_Date.get_date() >= customers_arr[i].get_check_out_date()) || (current_Date.get_month() >= customers_arr[i].get_check_out_month()) || (current_Date.get_year() >= customers_arr[i].get_check_out_year())))
                {
                    //Set all below to 0
                    customers_arr[i].set_checkin_or_not(0);
                    customers_arr[i].set_checkout_or_not(1);
                    H.get_floors(customers_arr[i].get_floor_of_room()).get_room(customers_arr[i].get_room_number())->set_availability_for_reservation(1);
                    customers_arr[i].set_check_out_hours(0);
                    customers_arr[i].set_check_out_minutes(0);
                    customers_arr[i].set_check_out_date(0);
                    customers_arr[i].set_check_out_month(0);
                    customers_arr[i].set_check_out_year(0);
                    H.print_room_data_into_empty_file();

                    if(customers_arr[i].get_balance() == 0)
                    cout<<"\n\nHey "<<customers_arr[i].get_Name()<<". Welcome to your checkout. I hope you liked the experience.\n";
                    
                    if(customers_arr[i].get_balance() > 0)
                    {
                        cout<<"\n\nHey "<<customers_arr[i].get_Name()<<". Welcome to your checkout. I hope you liked the experience.\nYour payment is due which is: "<<customers_arr[i].get_balance()<<"\nWill you pay by card or cash? Enter the amount\n";
                        double amount;
                        cin>>amount;
                        while(amount < customers_arr[i].get_balance() || amount > customers_arr[i].get_balance())
                        {
                            cout<<"Invalid amount\nEnter again\n";
                            cin>>amount;
                        }
                        customers_arr[i].set_balance(0);
                    }
                }
                customers_arr[i].print_cutomer_data_file(i); //Update customers file
            }
        }

        for(int i = 0 ; i < customer_arr_size; ++i) //Check if the user has not checked in than make it's room available fore reservation
        {
            if((customers_arr[i].get_checkin_or_not() == 0) && ((customers_arr[i].get_check_in_year() < current_Date.get_year()) ||  ((customers_arr[i].get_check_in_year() == current_Date.get_year()) && (customers_arr[i].get_check_in_month() < current_Date.get_month())) || ((customers_arr[i].get_check_in_year() == current_Date.get_year()) && (customers_arr[i].get_check_in_month() == current_Date.get_month())  && (customers_arr[i].get_check_in_date() < current_Date.get_date()))))
            customers_arr[i].get_room().set_availability_for_reservation(1);
            H.print_count_rooms_in_empty_file();
        } 
        H.print_room_data_into_empty_file(); //All rooms data update in all_rooms.dat file
    }
return 0;
}