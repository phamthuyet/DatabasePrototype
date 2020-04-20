#include <iostream>
#include <string>
#include <sqlite3.h>
using namespace std;

///Implement database in c++

bool checklogin = false;
// Pointer to SQLite connection
sqlite3* db;
// Save any error messages
char* zErrMsg = 0;
// Save the result of opening the file
int rc;
// Save any SQL
string sql;
// Create a callback function  to print out
int callback(void* NotUsed, int argc, char** argv, char** azColName) {

    // int argc: holds the number of results
    // (array) azColName: holds each column returned
    // (array) argv: holds each value

    for (int i = 0; i < argc; i++) {

        // Show column name, value, and newline
        cout << azColName[i] << ": " << argv[i] << endl;
    }
    cout << endl;
    return 0;
    
}
// Create a callback function to change login
int checkcallback(void* NotUsed, int argc, char** argv, char** azColName) {
    
    for (int i = 0; i < argc; i++) {
        if (argv[i] != "NULL") {checklogin=true; }
        // Show column name, value, and newline
    }
    return 0;
}
void starsq() {


    // Save the result of opening the file
    rc = sqlite3_open("example.db", &db);

    if (rc) {
        // Show an error message
        cout << "DB Error: " << sqlite3_errmsg(db) << endl;
        // Close the connection
        sqlite3_close(db);
        // Return an error

    }
}
void init() {


    // Save the result of opening the file
    rc = sqlite3_open("example.db", &db);

    if (rc) {
        // Show an error message
        cout << "DB Error: " << sqlite3_errmsg(db) << endl;
        // Close the connection
        sqlite3_close(db);
        // Return an error

    }
    
    

    // Save SQL to create a table
    sql = "CREATE TABLE STUDENT ("  \
        "ID TEXT PRIMARY KEY     NOT NULL," \
        "NAME           TEXT    NOT NULL);";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);


    // Save SQL to create a table
    sql = "CREATE TABLE COURSE ("  \
        "ID TEXT PRIMARY KEY     NOT NULL," \
        "NAME           TEXT    NOT NULL);";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    // Save SQL to create a table
    sql = "CREATE TABLE ATTEND ("  \
        "STUDENTID TEXT REFERENCES STUDENT(ID) ON DELETE CASCADE ON UPDATE CASCADE    NOT NULL    ," \
        "COURSEID TEXT REFERENCES COURSE(ID) ON DELETE CASCADE ON UPDATE CASCADE    NOT NULL     );";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    // Save SQL to create a table
    sql = "CREATE TABLE LOGIN ("  \
        "USERNAME TEXT PRIMARY KEY NOT NULL    ," \
        "PASS TEXT    NOT NULL     );";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    
}

//Populate Tables
void PopulateSTUDENTdb() {
    starsq();
    // Save SQL insert data
    sql = "INSERT INTO STUDENT ('ID', 'NAME') VALUES ('3','Jeff');";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    
    // Save SQL insert data
    sql = "INSERT INTO STUDENT ('ID', 'NAME') VALUES ('2','Dan');";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    // Save SQL insert data
    sql = "INSERT INTO STUDENT ('ID', 'NAME') VALUES ('1','Cara');";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
}
void PopulateCOURSEdb() {
    starsq();
    // Save SQL insert data
    sql = "INSERT INTO COURSE ('ID', 'NAME') VALUES ('101','DATABASE');";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    // Save SQL insert data
    sql = "INSERT INTO COURSE ('ID', 'NAME') VALUES ('102','FINNISH');";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    // Save SQL insert data
    sql = "INSERT INTO COURSE ('ID', 'NAME') VALUES ('103','GAME PROJECT');";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);


    // Save SQL insert data
    sql = "INSERT INTO COURSE ('ID', 'NAME') VALUES ('104','3D ANIMATION');";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);


}
void PopulateATTENDdb() {
    starsq();
        // Save SQL insert data
        sql = "INSERT INTO ATTEND ('STUDENTID', 'COURSEID') VALUES ('1','101');";

        // Run the SQL (convert the string to a C-String with c_str() )
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

        // Save SQL insert data
        sql = "INSERT INTO ATTEND ('STUDENTID', 'COURSEID') VALUES ('1','103');";

        // Run the SQL (convert the string to a C-String with c_str() )
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

        // Save SQL insert data
        sql = "INSERT INTO ATTEND ('STUDENTID', 'COURSEID') VALUES ('2','101');";

        // Run the SQL (convert the string to a C-String with c_str() )
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
        // Save SQL insert data
        sql = "INSERT INTO ATTEND ('STUDENTID', 'COURSEID') VALUES ('2','102');";

        // Run the SQL (convert the string to a C-String with c_str() )
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
        // Save SQL insert data
        sql = "INSERT INTO ATTEND ('STUDENTID', 'COURSEID') VALUES ('3','104');";

        // Run the SQL (convert the string to a C-String with c_str() )
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

        // Save SQL insert data
        sql = "INSERT INTO ATTEND ('STUDENTID', 'COURSEID') VALUES ('3','103');";

        // Run the SQL (convert the string to a C-String with c_str() )
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

}
void PopulateLOGINdb() {
    starsq();
    // Save SQL insert data
    sql = "INSERT INTO LOGIN ('USERNAME', 'PASS') VALUES ('THUYET','THUYET');";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
}
///done creating and populating tables 

// read STUDENT TABLE
void ShowStudent(){
    starsq();
    sql = "SELECT * FROM STUDENT;";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    // Close the SQL connection

    sqlite3_close(db);
}
// read Course Table
void ShowCourse() {
    starsq();
    sql = " SELECT * FROM COURSE;";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    // Close the SQL connection

    sqlite3_close(db);
}
// read ATTEND Table
void ShowAttend() {
    starsq();
    sql = " SELECT STUDENTID,STUDENT.NAME,COURSEID,COURSE.NAME FROM STUDENT, ATTEND, COURSE WHERE Student.ID = ATTEND.STUDENTID AND COURSE.ID = ATTEND.COURSEID;";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    // Close the SQL connection

    sqlite3_close(db);
}
//showSTUDENT with Id
void ShowStudentwithID(string id) {
    starsq();
    sql = " SELECT * FROM STUDENT WHERE ID='" + id + "';";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    // Close the SQL connection

    sqlite3_close(db);
}
//showCoursewithID
void ShowCoursewithID(string id) {
    starsq();
    sql = " SELECT * FROM COURSE WHERE ID='"+id+"';";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    // Close the SQL connection

    sqlite3_close(db);
}
// search course and student base on student name
void SelectStudentName(string choicename) {

    starsq();

    // Save SQL insert data
    sql = " SELECT STUDENTID,STUDENT.NAME,COURSEID,COURSE.NAME FROM STUDENT, ATTEND, COURSE WHERE Student.ID = ATTEND.STUDENTID AND STUDENT.NAME='" + choicename + "' AND COURSE.ID = ATTEND.COURSEID;";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    // Close the SQL connection

    sqlite3_close(db);
}
// search course and student base on student id
void SelectStudentID(string choiceid) {
    
    starsq();
    // Save SQL insert data
    sql = " SELECT STUDENTID,STUDENT.NAME,COURSEID,COURSE.NAME FROM STUDENT, ATTEND, COURSE WHERE Student.ID = ATTEND.STUDENTID AND STUDENT.id='" + choiceid + "' AND COURSE.ID = ATTEND.COURSEID;";
    
    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    // Close the SQL connection
    
    sqlite3_close(db);
}
// search course and student base on course name
void SelectCourseName(string choicename) {
    
    starsq();

    // Save SQL insert data
    sql = " SELECT STUDENTID,STUDENT.NAME,COURSEID,COURSE.NAME FROM STUDENT, ATTEND, COURSE WHERE Student.ID = ATTEND.STUDENTID AND COURSE.NAME='" + choicename + "' AND COURSE.ID = ATTEND.COURSEID;";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    // Close the SQL connection

    sqlite3_close(db);
}
// search course and student base on course id
void SelectCourseID(string choiceid) {

    starsq();

    // Save SQL insert data
    sql = " SELECT STUDENTID,STUDENT.NAME,COURSEID,COURSE.NAME FROM STUDENT, ATTEND, COURSE WHERE Student.ID = ATTEND.STUDENTID AND COURSE.id='" + choiceid + "' AND COURSE.ID = ATTEND.COURSEID;";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    sqlite3_close(db);
}

// Insert new student into  table
void InsertSTUDENT() {

    starsq();

    string id = "";
    string name = "";
    string anws1;
    do {

        cout << "What is the name of the student: ";
        cin >> name;
        cout << endl;

        cout << "What is the id of the student: ";
        cin >> id;
        cout << endl;
        cout << "Are you sastified? (y/n)" << endl;
        cin >> anws1;
    } while (anws1 != "y" && anws1 != "Y");

    // Save SQL insert data
    sql = "INSERT INTO STUDENT ('ID', 'NAME') VALUES ('" + id + "','" + name + "');";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

}
// Insert new course into table
void InsertCOURSE() {
    starsq();

    string id = "";
    string name = "";
    string anws1;
    do {

    cout << "What is the name of the course: ";
    cin >> name;
    cin.ignore();
    cout << endl;
    cout << "What is the id of the course: ";
    cin >> id;
    cin.ignore();
    cout << endl;
    cout << "Are you sastified? (y/n)" << endl;
    cin >> anws1;
} while (anws1 != "y" && anws1 != "Y");

    // Save SQL insert data
    sql = "INSERT INTO COURSE ('ID', 'NAME') VALUES ('" + id + "','" + name + "');";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

}
//Insert Attend
void InsertATTEND() {
    string id1 = "";
    string id2 = "";
    string anws1, answ2;
    do {
        cout << "What is the id of the student: ";
        cin >> id1;
        cout << endl;
        ShowStudentwithID(id1);
        cout << "Is this the student you are looking for? (y/n)" << endl;
        cin >> anws1;
    } while (anws1 != "y"&& anws1 != "Y");
    do {
        cout << "What is the id of the course: ";
        cin >> id2;
        cout << endl;
        ShowCoursewithID(id2);
        cout << "Is this the course you are looking for? (y/n)" << endl;
        cin >> answ2;
    } while (answ2 != "y" && answ2 != "Y");

    starsq();
    sql = "INSERT INTO ATTEND ('STUDENTID', 'COURSEID') VALUES ('"+id1+"','"+id2+"');";
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    
}
//Inesrt LOGIN
void InsertLOGIN(){
starsq();

string pass = "";
string name = "";

string anws1;
do {
cout << "Please enter your Username: ";
cin >> name;
cout << "Please enter your Password: ";
cin >> pass;
cout << endl;

// Save SQL insert data
sql = "INSERT INTO LOGIN ('USERNAME', 'PASS') VALUES ('" + name + "','" + pass + "');";

// Run the SQL (convert the string to a C-String with c_str() )
rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
cout << "Are you sastified? (y/n)" << endl;
cin >> anws1;
} while (anws1 != "y" && anws1 != "Y");
}

// delete using student name
void DeleteStudentName() {
    string choicename = "";
    string answ = "";
    cout << "What is the name of student: ";
    cin >> choicename;
    cout << endl;
    SelectStudentName(choicename);
    cout << "Are you sure you want to delete the data? (Y/N)" << endl;
    cin >> answ;
    if (answ == "y")
    {// Save SQL insert data
        starsq();
        sql = "DELETE FROM STUDENT WHERE NAME='" + choicename + "';";

        // Run the SQL (convert the string to a C-String with c_str() )
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
        // Close the SQL connection

        sqlite3_close(db);
        cout << "Data is deleted"<< endl;
    }

}
// delete using course name
void DeleteCourseName() {

    string choicename = "";
    string answ = "";
    cout << "What is the name of course: ";
    cin >> choicename;
    cout << endl;
    starsq();
    SelectCourseName(choicename);
    cout << "Are you sure you want to delete the data? (Y/N)" << endl;
    cin >> answ;
    if (answ == "y")
    {
        starsq();
        // Save SQL insert data
        sql = " DELETE FROM COURSE WHERE NAME='" + choicename + "';";
        // Run the SQL (convert the string to a C-String with c_str() )
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
        // Close the SQL connection

        sqlite3_close(db);
        cout << "Data is deleted" << endl;
    }
}
//Drop table
void DropTables() {
    starsq();
    string answ = "";
    cout << "Are you sure you want to delete the data? (Y/N)" << endl;
    cin >> answ;
    if (answ == "y")
    {
        sql = "DROP TABLE STUDENT;DROP TABLE COURSE;DROP TABLE ATTEND;DROP TABLE LOGIN;";
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    }
}

// CHECK LOGIN
void checkuserlogin() {
    starsq();

    string name; 
    string pass;
    cout << "\nWELCOME TO LOGIN\nUSERNAME: ";
    cin >> name;
    cout << "PASSWORD: ";
    cin >> pass;
    cout << endl;

    sql = "SELECT * FROM LOGIN WHERE USERNAME='"+ name +"' AND PASS='"+pass+"';";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), checkcallback, 0, &zErrMsg);
    // Close the SQL connection
    
    sqlite3_close(db);
    if (checklogin == false) { cout << "You entered USERNAME or PASSWORD wrong!!!\n" << endl; }
}




int main() {
    string choice;
    string choicemain;
    string choicelogin;
    string userinput = "";
    
    //init
    starsq();
    init();
    
    // simple lazy Interface
   do{
    cout << "WELCOME TO DATABASE ver1.2" << endl;
    cout << "Choose (1) to Login. \nChoose (2) to Register.\nChoose (3) to Login as guest.\nChoose (4) to Populate the Database.\nChoose (0) to Exit." << endl;
    cout << "Please choose a number: ";
    cin >> choicelogin;
    cin.ignore();
    cout << endl;
    //login
    if (choicelogin=="1")
    { 
        checkuserlogin();
    if(checklogin==true){
        cout << "\nLOGIN COMPLETE..." << endl;
        checklogin = false;

        do
        {
        cout << "WELCOME TO DATABASE ver1.2" << endl;
        cout << "Choose (1) to Check database. \nChoose (2) to Search for Classes.\nChoose (3) to Insert data.\nChoose (4) to Delete data.\nChoose (0) to Log-off ." << endl;
        cout << "Please choose a number: ";
        cin >> choicemain;
        cin.ignore();
        cout << endl;
        if (choicemain == "1") {
            do {
                cout << "\nYou have accessed The Data Base" << endl;
                cout << "Choose (1) to check Students database \nChoose (2) to check Courses database. \nChoose (3) to Check Attendees\nChoose (0) to go back." << endl;
                cout << "Please choose a number: ";
                cin >> choice;
                cin.ignore();
                cout << endl;
                if (choice == "1") {
                    cout << "\n You have accessed Student Data Base" << endl;
                    ShowStudent();

                }
                else if (choice == "2") {
                    cout << "\nYou have accessed Courses Data Base" << endl;
                   ShowCourse();
                }
                else if (choice == "3") {
                    cout << "\nYou have accessed Attendees Data Base" << endl;
                    ShowAttend();
                }

                
            } while (choice != "0");
        }
        else if (choicemain == "2") {
            do {
                cout << "\nYou have accessed Searching" << endl;
                cout << "Choose (1) to Search for current Classes by Students \nChoose (2) to Search for current Classes by Courses.\nChoose (0) to go back." << endl;
                cout << "Please choose a number: ";
                cin >> choice;
                cin.ignore();
                cout << endl;
                if (choice == "1") {
                    cout << "\nPlease enter Student's Name or ID: " << endl;
                    cin >> userinput;
                    cout << "Search results:  " << endl;
                    SelectStudentID(userinput);
                    SelectStudentName(userinput);
                   
                    }
                else if (choice == "2") {
                    cout << "\nPlease enter Courses's Name or ID: " << endl;
                    cin >> userinput;
                    cout << "\nSearch results:  " << endl;
                    SelectCourseName(userinput);
                    SelectCourseID(userinput);
                }

            } while (choice != "0");
            
        }
        else if (choicemain == "3") {
            do {
                cout << "\nYou have accessed the Database" << endl;
                cout << "Choose (1) to Add new Students.\nChoose (2) to Add new Courses.\nChoose (3) to Add Student into Course\nChoose (0) to go back." << endl;
                cout << "Please choose a number: ";
                cin >> choice;
                cin.ignore();
                cout << endl;
                if (choice == "1")
                {
                    InsertSTUDENT();
                }
                else if (choice == "2") {
                    InsertCOURSE();
                }
                else if (choice == "3") {
                    InsertATTEND();
                }
            } while (choice != "0");
            
        }
        else if (choicemain == "4") {
            do{
            cout << "\nYou have accessed the Delete" << endl;
            cout << "Choose (1) to Delete Student's information.\nChoose (2) to Delete Course's information.\nChoose (3) to Drop Tables.\nChoose (0) to go back." << endl;
            cout << "Please choose a number: ";
            cin >> choice;
            cin.ignore();
            cout << endl;
            if (choice == "1")
            {
                DeleteStudentName();
            }

            else if (choice == "2") 
            {
                DeleteCourseName();
            }
            else if (choice == "3") {
                DropTables();
            }
            

            } while (choice != "0");
        }
      
        

    } while (choicemain != "0");
    }
    

    }

    //Register
    else if (choicelogin=="2") {
    InsertLOGIN();
}

    //Guest log-in
    else if (choicelogin == "3")
    {
        {
            cout << "\nLOGIN COMPLETE..." << endl;;
            do
            {
                cout << "WELCOME TO DATABASE ver1.2" << endl;
                cout << "Choose (1) to Check database. \nChoose (2) to Search.\nChoose (0) to Log-off ." << endl;
                cout << "Please choose a number: ";
                cin >> choicemain;
                cin.ignore();
                cout << endl;
                if (choicemain == "1") {
                    do {
                        cout << "\nYou have accessed The Data Base" << endl;
                        cout << "Choose (1) to check Students database \nChoose (2) to check Courses database \nChoose (3) to Check Attendees\nChoose (0) to go back." << endl;
                        cout << "Please choose a number: ";
                        cin >> choice;
                        cin.ignore();
                        cout << endl;
                        if (choice == "1") {
                            cout << "\n You have accessed Student Data Base" << endl;
                            ShowStudent();

                        }
                        else if (choice == "2") {
                            cout << "\nYou have accessed Courses Data Base" << endl;
                            ShowCourse();
                        }
                        else if (choice == "3") {
                            cout << "\nYou have accessed Attendees Data Base" << endl;
                            ShowAttend();
                        }


                    } while (choice != "0");
                }
                else if (choicemain == "2") {
                    do {
                        cout << "\nYou have accessed Searching" << endl;
                        cout << "Choose (1) to Search for current Classes by Students \nChoose (2) to Search for current Classes by Courses.\nChoose (0) to go back." << endl;
                        cout << "Please choose a number: ";
                        cin >> choice;
                        cin.ignore();
                        cout << endl;
                        if (choice == "1") {
                            cout << "\nPlease enter Student's Name or ID: " << endl;
                            cin >> userinput;
                            cout << "Search results:  " << endl;
                            SelectStudentID(userinput);
                            SelectStudentName(userinput);

                        }
                        else if (choice == "2") {
                            cout << "\nPlease enter Courses's Name or ID: " << endl;
                            cin >> userinput;
                            cout << "\nSearch results:  " << endl;
                            SelectCourseName(userinput);
                            SelectCourseID(userinput);
                        }

                    } while (choice != "0");

                }
              
            } while (choicemain != "0");
        }
        
    }

    //Populate the tables
    else if(choicelogin=="4"){
        PopulateSTUDENTdb();
        PopulateCOURSEdb();
        PopulateLOGINdb();
        PopulateATTENDdb(); }

    } while (choicelogin != "0");
     
}