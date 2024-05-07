#include <iostream>
#include <string>
#include <fstream>


using namespace std;
bool isVietnamese = true;
class User {
private:
    string username;
    string password;
    string fullName;
    string gender;
    string address;
    string phoneNumber;
    string dob; // Ngày sinh
    string subcode;
    bool isLoggedIn;
    int adminCode; // Mã admin

public:
    // Default constructor
    User() : isLoggedIn(false) {}

    // Public constructor
    User(string uname, string pwd, string name, string g, string addr, string phone, string birth, int code , string sub)
            : username(uname), password(pwd), fullName(name), gender(g), address(addr), phoneNumber(phone),
              dob(birth), isLoggedIn(false), adminCode(code) ,subcode(sub){}

    void login(string uname, string pwd) {
        if (uname == username && pwd == password) {
            isLoggedIn = true;
            cout << "Login successful!" << endl;
        } else {
            cout << "Login unsuccessful. Please try again!" << endl;
        }
    }


    void logout() {
        isLoggedIn = false;
        cout << "Logout successful!" << endl;
    }


    bool isLogged() const {
        return isLoggedIn;
    }

    int getAdminCode() const {
        return adminCode;
    }

    string getSubject() const {
        return subcode;
    }

    bool checkCredentials(string uname, string pwd) const {
        return (uname == username && pwd == password);
    }

    static User
    createUser(string uname, string pwd, string name, string g, string addr, string phone, string birth, int code, string sub) {
        return User(uname, pwd, name, g, addr, phone, birth, code,sub);
    }

    //  in của tài khoản
    void viewInfo() const {
        cout << "Account Information:" << endl;
        cout << (isVietnamese ? "Ten dang nhap: " : "Username: ") << username << endl;
        cout << (isVietnamese ? "Ho va ten: " : "Full Name: ") << fullName << endl;
        cout << (isVietnamese ? "Gioi tinh: " : "Gender: ") << gender << endl;
        cout << (isVietnamese ? "Dia chi: " : "Address: ") << address << endl;
        cout << (isVietnamese ? "So dien thoai: " : "Phone Number: ") << phoneNumber << endl;
        cout << (isVietnamese ? "Ngay sinh: " : "Date of Birth: ") << dob << endl;
        cout << (isVietnamese ? "Ma quan tri: " : "Admin Code: ") << adminCode << endl;
        cout << (isVietnamese ? "Ma mon hoc: " : "Subject Code: ") << subcode << endl;
    }


};


class Student {
private:
    string studentId;
    string studentName;
    int cccd;
    string gender;
    string date;
    static int constructorCount;
//    int absentCount; // Số buổi nghỉ
//    int presentCount; // Số buổi có mặt đi học

public:
    Student() {
        constructorCount++;
//         absentCount = 0;
//         presentCount = 0;
    }

    Student(string id, string name, int cccd, string gender, string date)
            : studentId(id), studentName(name), cccd(cccd), gender(gender), date(date) {
        constructorCount++;
    }

    string getStudentId() const {
        return studentId;
    }

    void setStudentId(string id) {
        studentId = id;
    }

    string getStudentName() const {
        return studentName;
    }

    void setStudentName(string name) {
        studentName = name;
    }

    int getCccd() const {
        return cccd;
    }

    void setCccd(int id) {
        cccd = id;
    }

    string getGender() const {
        return gender;
    }

    void setGender(string gen) {
        gender = gen;
    }

    string getDate() const {
        return date;
    }

    void setDate(string dob) {
        date = dob;
    }

//    int getAbsentCount() const {
//          return absentCount;
//      }
//
//      void increaseAbsentCount() {
//          absentCount++;
//      }
//
//      int getPresentCount() const {
//          return presentCount;
//      }
//
//      void increasePresentCount() {
//          presentCount++;
//      }

    static int getConstructorCount() {
        return constructorCount;
    }

};

int Student::constructorCount = 0; // Khởi tạo biến static



class Course {
private:
    Student student[100];
    string courseName;
//    int LimitCourseDay;
    int TotalCourseDay; // tổng số buổi học của lớp này
    int executionNumberOfDays;// số buổi học nãy đã thực thi
    int toltalStudent=0;// tổng sinh viên lớp này
public:
    string courseId;
    static int sizeCourse;




    // Constructors
    Course() {
        sizeCourse++;
//        cout<<sizeCourse<<endl;
        TotalCourseDay = 0; // Khởi tạo giá trị cho TotalCourseDay
    }

    Course(string id, string name, int total) : courseId(id), courseName(name), TotalCourseDay(total) {
        sizeCourse++;
    }

    const Student* getStudents() const {
        return student;
    }

    void SettoltalStudentt() {
        toltalStudent++ ;
    }
    void AddStudent(const Student& newStudent) {
        if (toltalStudent < 100) {
            student[toltalStudent] = newStudent;
        } else {
            cout << "Error: Maximum number of students reached." << endl;
        }
    }

    int GetToltalStudentt() const {
        return  toltalStudent ;
    }


    int getExecutionNumberOfDays() const {
        return executionNumberOfDays;
    }


    void updateExecutionNumberOfDays() {
        executionNumberOfDays++;
    }

    // Destructor
    ~Course() {
        // Giảm kích thước mỗi khi đối tượng Course bị hủy
    }

//    void PrintAllStudents() const {
//        cout << "Students in course " << courseId << ":" << endl;
//        for (int i = 0; i < toltalStudent+1; ++i) {
//            cout << "Student ID: " << student[i].getStudentId() << ", Name: " << student[i].getStudentName() << endl;
//        }
//    }


//    void PrintAllStudents() const {
//        cout << "Students in course " << courseId << ":" << endl;
//        for (int i = 0; i < toltalStudent+1; ++i) {
//            cout << "Student ID: " << student[i].getStudentId() << ", Name: " << student[i].getStudentName() << endl;
//
//
//            string id = student[i].getStudent().getStudentId();
//            string name = student[i].getStudent().getStudentName();
//            int cccd = student[i].getStudent().getCccd();
//            string gender = student[i].getStudent().getGender();
//            string dob = student[i].getStudent().getDate();
//
//            // In thông tin sinh viên
//            printStudentTableRow(id, name, cccd, gender, dob);
//        }
//    }













    // Getter và Setter cho courseId
    string getCourseId() const {
        return courseId;
    }

    void setCourseId(string id) {
        courseId = id;
    }

    // Getter và Setter cho courseName
    string getCourseName() const {
        return courseName;
    }

    void setCourseName(string name) {
        courseName = name;
    }

    // Getter và Setter cho TotalCourseDay
    int getTotalCourseDay() const {
        return TotalCourseDay;
    }

    void setTotalCourseDay(int total) {
        TotalCourseDay = total;
    }

    // Getter cho sizeCourse
    static int getTotalCourseCount() {
        return sizeCourse;
    }
};

// Khởi tạo biến static
int Course::sizeCourse = 0;



class AttendanceRecord {
private:
    Student student;
    string status;    // lưu trữ điểm danh
    Course course;
    int day;   // ngày điểm danh
    int numDays;  //phế
//    int absentCount; // Số buổi nghỉ
//    int presentCount; // Số buổi có mặt đi học


    int dayExcercute ; // ngày điểm danh

public:

    static int totalAtten;

    AttendanceRecord() {
        status = "";
        numDays = 0;
    }
    int getDayExcercute() const { //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        return dayExcercute;
    }



    void setCourse(const Course& cours) {
        course = cours;
    }



    AttendanceRecord(Student std ,Course cous,int Day) {
        student = std;
        course = cous;
        day = Day+1;
        dayExcercute = -9;
//        numDays = days;
//        status = '';
//        cous.SettoltalStudentt();
    }

    void setDay(int Day) {
        day = Day;
    }

    int getDay() const { //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        return day;
    }

    string getAttendance() const { //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        return status;
    }


    Course getCourse() const {
        return course;
    }
    Student getStudent() const {
        return student;
    }

    void setAttendanceForDay(int Day, char Status) {
        if (Day >= 0) {
            status = Status;
//            day = Day;
            dayExcercute = Day+1;
//            if(Status == 'A') {
//                student.increaseAbsentCount(); // Tăng số buổi nghỉ của sinh viên
//            } else if (Status == 'P') {
//                student.increasePresentCount(); // Tăng số buổi có mặt của sinh viên
//            }
        } else {
            cout << (isVietnamese ? "Ngay khong hop le." : "Invalid day.") << endl;

        }

    }


    ~AttendanceRecord() {
    }
};
int AttendanceRecord::totalAtten = 0; // Khởi tạo biến static


class AttendanceManager {
private:
    AttendanceRecord* records;
    int hehe;  // phế
    int numberAttendanceManager = 0;
    int numDays;//phế

public:
    AttendanceManager() : records(nullptr), hehe(0), numDays(0) {}

    AttendanceManager(int dh, int days) : hehe(dh), numDays(days) {
        records = new AttendanceRecord[100];
    }

    ~AttendanceManager() {

    }

    void addStudent(const Student& student, Course &course) {
        // Kiểm tra xem sinh viên đã tồn tại trong danh sách chưa
//        bool exists = false;
//        for (int i = 0; i < number; ++i) {
//            if (records[i].getStudent().getStudentId() == student.getStudentId()) {
//                exists = true;
//                break;
//            }
//        }
        course.SettoltalStudentt();
        course.AddStudent(student);
//        if (!exists) {
        for (int i = 0; i < course.getTotalCourseDay(); ++i) {
            // Thêm sinh viên vào danh sách nếu chưa tồn tại
            records[numberAttendanceManager] = AttendanceRecord(student, course,i ) ;
//            course.
            numberAttendanceManager++;
        }


//        } else {
//            cout << "Student with ID " << student.getStudentId() << " already exists." << endl;
//        }
    }



    void printStudentTableHeader() {
//        cout << "==============================================================================\n";
//        cout << "| MSV        | Student Name | CCCD        | Gender | Date of Birth |\n";
//        cout << "==============================================================================\n";
        cout << "==============================================================================\n";
        cout << (isVietnamese ? "| MSV        | Tên Sinh Viên| CCCD        |Giới tính| Ngày sinh     |\n" : "| MSV        | Student Name | CCCD        | Gender | Date of Birth |\n");
        cout << "==============================================================================\n";

    }

    void printStudentTableRow(const string& id, const string& name, int cccd, const string& gender, const string& dob) {
        cout << "| " << id << string(11 - id.length(), ' ') << "| ";
        cout << name << string(13 - name.length(), ' ') << "| ";
        cout << cccd << string(12 - to_string(cccd).length(), ' ') << "| ";
        cout << gender << string(7 - gender.length(), ' ') << "| ";
        cout << dob << string(14 - dob.length(), ' ') << "|\n";
    }

    void ListStudent() {
        cout << (isVietnamese ? "Danh sach hoc sinh" : "List of Students:") << endl;

        printStudentTableHeader();

        for(int i = 0; i < numberAttendanceManager; i++) {
            // Kiểm tra xem sinh viên có mã bị trùng không
            bool duplicate = false;
            for(int j = 0; j < i; j++) {
                if(records[i].getStudent().getStudentId() == records[j].getStudent().getStudentId()) {
                    duplicate = true;
                    break;
                }
            }

            // Nếu không trùng mã thì in ra thông tin sinh viên
            if(!duplicate) {
                // Lấy thông tin sinh viên
                string id = records[i].getStudent().getStudentId();
                string name = records[i].getStudent().getStudentName();
                int cccd = records[i].getStudent().getCccd();
                string gender = records[i].getStudent().getGender();
                string dob = records[i].getStudent().getDate();

                // In thông tin sinh viên
                printStudentTableRow(id, name, cccd, gender, dob);
            }
        }

        cout << "==============================================================================\n";
    }






    void viewAllStudentOncourse(Course &courses) {
        cout << (isVietnamese ? "Danh sach hoc sinh" : "List of Students:") << endl;
        cout << "Students in course " << courses.getCourseName() << ":" << endl;
        printStudentTableHeader();
        int totalStudents = courses.GetToltalStudentt();
        const Student* students = courses.getStudents();
        for (int i = 1; i < totalStudents+1; i++) {
//            cout << "Student ID: " << courses.student[i].getStudentId() << ", Name: " << student[i].getStudentName() << endl;


            string id = students[i].getStudentId();
            string name = students[i].getStudentName();
            int cccd = students[i].getCccd();
            string gender = students[i].getGender();
            string dob = students[i].getDate();

            // In thông tin sinh viên
            printStudentTableRow(id, name, cccd, gender, dob);
        }








            // Nếu không trùng mã thì in ra thông tin sinh viên
        cout << "==============================================================================\n";
        }




















//    void printStudentTableHeader1() {
//        cout << "==================================================================================\n";
//        cout << "| MSV        | Student Name | CCCD        | Gender | Date of Birth | Attendances |\n";
//        cout << "==================================================================================\n";
//    }


    bool CheckDayAttendances(int day , Course &course )  {
        for(int i=0 ; i < numberAttendanceManager ; i++){
//            cout<<"check ngày"<< records[i].getDay() <<endl;
//            cout<<"DA DIEM DANH NGAY NAY"<< records[i].getDayExcercute() <<endl;
            if(course.courseId == records[i].getCourse().courseId && day == records[i].getDayExcercute()-1){
                cout << "+===================================================+\n";
                cout << "|DA DIEM DANH NGAY NAY. Vui lòng chọn một ngày khác.|" << endl;
                cout << "+===================================================+\n";

                return false; // Trả về false nếu ngày đã được điểm danh
            }
        }
        // Nếu không có bất kỳ bản ghi nào trong danh sách điểm danh cho ngày này, trả về true
        return true;
    }


    void printStudentTableRow3(const string& id, const string& name, int cccd, const string& gender, const string& dob ) {
        cout << "| " << id << string(11 - id.length(), ' ') << "| ";
        cout << name << string(13 - name.length(), ' ') << "| ";
        cout << cccd << string(12 - to_string(cccd).length(), ' ') << "| ";
        cout << gender << string(7 - gender.length(), ' ') << "| ";
        cout << dob << string(14 - dob.length(), ' ') << "| ";
//        cout << At << string(11, ' ') << "|\n"; // Sử dụng một ký tự duy nhất để thay thế khoảng trắng
    }


    void inputAttendanceforday(int day, Course &course, int numCourses) {
        if (day >= 0 && day < numDays) {
            char status;
            cout << "-----------------------------------------------------------------------------------" << endl;
            cout << (isVietnamese ? "Nhap 'P' neu vang co phep, 'X' neu co mat, 'V' neu vang khong phep" : "Enter 'P' if authorized absence, 'X' if Present, 'V' if Absent without permission") << endl;
            cout << "-----------------------------------------------------------------------------------" << endl;
            cout<<endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "| Điểm danh môn:"<<course.getCourseName()<<"/Ngay:"<<day<<":|"<<endl;
            cout << "+-----------------------------------------------------------+" << endl;


            printStudentTableHeader1();
            for (int i = 0; i < numberAttendanceManager; i++) {
                if (course.courseId == records[i].getCourse().courseId && day == records[i].getDay()) {

                    string id = records[i].getStudent().getStudentId();
                    string name = records[i].getStudent().getStudentName();
                    int cccd = records[i].getStudent().getCccd();
                    string gender = records[i].getStudent().getGender();
                    string dob = records[i].getStudent().getDate();
//                    cin >> status;
//                    char At = status;
                    printStudentTableRow3(id, name, cccd, gender, dob);
                    cin >> status;



                    // Kiểm tra xem ký tự nhập vào có hợp lệ không
                    while (status != 'P' && status != 'X' && status != 'V') {
                        cout << "----------------------------------------------------" << endl;
                        cout << (isVietnamese ? "Vui long chi chon 'P', 'X', hoac 'V': " : "Please select only 'P', 'X', or 'V': ") << endl;
                        cout << "----------------------------------------------------" << endl;

                        string id = records[i].getStudent().getStudentId();
                        string name = records[i].getStudent().getStudentName();
                        int cccd = records[i].getStudent().getCccd();
                        string gender = records[i].getStudent().getGender();
                        string dob = records[i].getStudent().getDate();
//                    cin >> status;
//                    char At = status;
                        printStudentTableRow3(id, name, cccd, gender, dob);
                        cin >> status;

                    }

                    records[i].setAttendanceForDay(day, status);
                }
//                cout << "----------------------------------------------------------------------------------" << endl;
            }
            course.updateExecutionNumberOfDays();
        } else {
            cout << (isVietnamese ? "Ngay khong hop le." : "Invalid day.") << endl;

        }
        cout << "----------------------------------------------------------------------------------" << endl;
    }

    void printStudentTableHeader1() {

        if (isVietnamese) {
            cout << "==================================================================================\n";
            cout << "| MSV        | Ten Sinh Vien | CCCD       |Gioitinh| Ngay sinh     | Diem danh   |\n";
            cout << "==================================================================================\n";
        } else {
            cout << "==================================================================================\n";
            cout << "| MSV        | Student Name  |  CCCD      | Gender | Date of Birth | Attendances |\n";
            cout << "==================================================================================\n";
        }

    }

    void printStudentTableRow1(const string& id, const string& name, int cccd, const string& gender, const string& dob, string At) {
        cout << "| " << id << string(11 - id.length(), ' ') << "| ";
        cout << name << string(13 - name.length(), ' ') << "| ";
        cout << cccd << string(12 - to_string(cccd).length(), ' ') << "| ";
        cout << gender << string(7 - gender.length(), ' ') << "| ";
        cout << dob << string(14 - dob.length(), ' ') << "| ";
        cout << At << string(12 - At.length(), ' ') << "|\n";
    }

    void viewTottalAttendancesOnCourseId(Course course, int totalCourseDays) {
//        cout << (isVietnamese ? "Diem danh cho khoa hoc " : "Attendance for course ") << course.getCourseName() << ":" << endl;
//        cout << (isVietnamese ? "Tong so ngay diem danh: " : "Total number of attendance days: ") << totalCourseDays << endl;

        cout<<endl;
        cout<<endl;
        cout<<"Đã thực thi "<< course.getExecutionNumberOfDays()<<"/"<<totalCourseDays<<"(tổng tín)"<<endl;
        for (int i = 0; i < totalCourseDays; i++) {

            if(records[i].getDay()==records[i].getDayExcercute()-1){
                cout << "Attendance for day " << i + 1 << " ;" <<"Đã điểm danh" <<endl;
            }else{
                cout << "Attendance for day " << i + 1 << " ;" <<"Chưa điểm danh"<<endl;
            }

            cout<<records[i].getDay()<<endl;
            cout<<records[i].getDayExcercute()+1<<endl;


            printStudentTableHeader1();

            for (int j = 0; j < numberAttendanceManager; j++) {
                if (records[j].getCourse().getCourseId() == course.getCourseId() && i  == records[j].getDay()) {
                    string id = records[j].getStudent().getStudentId();
                    string name = records[j].getStudent().getStudentName();
                    int cccd = records[j].getStudent().getCccd();
                    string gender = records[j].getStudent().getGender();
                    string dob = records[j].getStudent().getDate();
                    string At = records[j].getAttendance();

                    // In thông tin sinh viên
                    printStudentTableRow1(id, name, cccd, gender, dob, At);
                }
            }
            cout << "----------------------------------------------------------------------------------" << endl;
        }
    }







    void viewAttendancesOnDayOncourseIdOnDay(int day , Course course, int numCourses)  {
        if (day >= 0 && day < numDays) {
            char status;
            cout << " thông tin điểm danh của các sinh viên môn " <<course.getCourseName() <<"ngày thứ :"<< day << endl;
            printStudentTableHeader1();
            for (int i = 0; i < numberAttendanceManager; i++) {
                if(course.courseId==records[i].getCourse().courseId && day==records[i].getDay()){
                    string id = records[i].getStudent().getStudentId();
                    string name = records[i].getStudent().getStudentName();
                    int cccd = records[i].getStudent().getCccd();
                    string gender = records[i].getStudent().getGender();
                    string dob = records[i].getStudent().getDate();
                    string At = records[i].getAttendance();

                    // In thông tin sinh viên
                    printStudentTableRow1(id, name, cccd, gender, dob, At);
//                    cout << records[i].getAttendance() << endl;

                };

            }
            cout << "----------------------------------------------------------------------------------" << endl;
        } else {
            cout << "Invalid day." << endl;
        }

    }

    void printAllAttendanceRecords() {
        cout << (isVietnamese ? "Tất cả Bản ghi điểm danh:" : "All Attendance Records:") << endl;
        cout << "==============================================================" << endl;
        for (int i = 0; i < numberAttendanceManager; i++) {
            cout << (isVietnamese ? "Bnar ghi " : "Record ") << i + 1 << ":" << endl;
            cout << (isVietnamese ? "MSV: " : "Student ID: ") << records[i].getStudent().getStudentId() << endl;
            cout << (isVietnamese ? "Ten sinh vien: " : "Student Name: ") << records[i].getStudent().getStudentName() << endl;
            cout << (isVietnamese ? "Ma khoa hoc: " : "Course ID: ") << records[i].getCourse().getCourseId() << endl;
            cout << (isVietnamese ? "Trang thai diem danh: " : "Attendance Status: ") << records[i].getAttendance() << endl;
            cout << "Ngay: " << records[i].getDay() << endl;
            cout << "getDayExcercute: " << records[i].getDayExcercute() << endl;
            cout << "--------------------------------------------------------------" << endl;
        }
        cout << "==============================================================" << endl;
    }

    void printAttendanceSummaryForStudent(string courseId, string studentId, int totalCourseDays) {
        int absentCount = 0;
        string studentName;
        string studentGender;
        int studentCccd;
        string studentDob;

        // Tìm thông tin sinh viên
        for (int i = 0; i < numberAttendanceManager; i++) {
            if (records[i].getCourse().getCourseId() == courseId &&
                records[i].getStudent().getStudentId() == studentId) {
                if (records[i].getAttendance() == "A") {
                    absentCount++;
                }

                // Lấy thông tin của sinh viên
                studentName = records[i].getStudent().getStudentName();
                studentGender = records[i].getStudent().getGender();
                studentCccd = records[i].getStudent().getCccd();
                studentDob = records[i].getStudent().getDate();
                break; // Vì thông tin sinh viên chỉ cần lấy 1 lần
            }
        }

        // Tính tỉ lệ số buổi nghỉ
        double absentPercentage = (static_cast<double>(absentCount) / totalCourseDays) * 100;

        // Kiểm tra nếu tỉ lệ vượt quá 30%
        if (absentPercentage > 30) {
            cout << (isVietnamese ? "=============================================================="
                                  : "==============================================================") << endl;
            cout << (isVietnamese ? " Thong bao: Sinh vien " : " Notification: Student ") << studentId << " - "
                 << studentName
                 << (isVietnamese ? " da vang qua 30% so buoi hoc." : " has been absent for more than 30% of classes.")
                 << endl;
            cout << (isVietnamese ? " Thong tin sinh vien:" : " Student Information:") << endl;
            cout << (isVietnamese ? " Ten: " : " Name: ") << studentName << endl;
            cout << (isVietnamese ? " Gioi tinh: " : " Gender: ") << studentGender << endl;
            cout << (isVietnamese ? " CCCD: " : " CCCD: ") << studentCccd << endl;
            cout << (isVietnamese ? " Ngay sinh: " : " Date of Birth: ") << studentDob << endl;
            cout << (isVietnamese ? " Tong so ngay vang mat: " : " Total absent days: ") << absentCount
                 << (isVietnamese ? " tren tong " : " out of total ") << totalCourseDays
                 << (isVietnamese ? " buoi hoc." : " classes.") << endl;
            cout << (isVietnamese ? " Ti le vang mat: " : " Absenteeism rate: ") << absentPercentage << "%" << endl;
            cout << (isVietnamese ? "=============================================================="
                                  : "==============================================================") << endl;
        } else {
            cout << (isVietnamese ? "=============================================================="
                                  : "==============================================================") << endl;
            cout << (isVietnamese ? " Sinh vien " : " Student ") << studentId
                 << (isVietnamese ? " khong vuot qua 30% so buoi hoc." : " has not exceeded 30% of classes.") << endl;
            cout << (isVietnamese ? " Ti le vang mat: " : " Absenteeism rate: ") << absentPercentage << "%" << endl;
            cout << (isVietnamese ? "---------------------------------------------------------------"
                                  : "---------------------------------------------------------------") << endl;
            cout << (isVietnamese ? " Thong tin sinh vien:" : " Student Information:") << endl;
            cout << (isVietnamese ? " Ten: " : " Name: ") << studentName << endl;
            cout << (isVietnamese ? " Gioi tinh: " : " Gender: ") << studentGender << endl;
            cout << (isVietnamese ? " CCCD: " : " CCCD: ") << studentCccd << endl;
            cout << (isVietnamese ? " Ngay sinh: " : " Date of Birth: ") << studentDob << endl;
            cout << (isVietnamese ? " Tong so ngay vang mat: " : " Total absent days: ") << absentCount
                 << (isVietnamese ? " tren tong " : " out of total ") << totalCourseDays
                 << (isVietnamese ? " buoi hoc." : " classes.") << endl;
            cout << (isVietnamese ? " Ti le vang mat: " : " Absenteeism rate: ") << absentPercentage << "%" << endl;
            cout << (isVietnamese ? "=============================================================="
                                  : "==============================================================") << endl;
        }
    }





    void printStudentTableHeader2() {
        if (isVietnamese) {
            cout << "============================================================================================================================================\n";
            cout << "| MSV        | Ten Sinh Vien | CCCD       |Gioitinh|  Ngay sinh    |  Vang   |  Phep  | Co.Mat |   So.Ngay.da.hoc / Tong.ngay.hoc.cua.mon   | \n";
//            cout << "=============================================================================================================================================\n";
        } else {
            cout << "==================================================================================\n";
            cout << "| MSV        | Student Name   | CCCD       | Gender  | Date of Birth | Absent  |\n";
            cout << "==================================================================================\n";
        }
    }

    void printStudentTableRow2(const string& id, const string& name, int cccd, const string& gender, const string& dob, int totalAbsent,int totalPermis,int totalPresent,string Analists) {
        cout << "| " << id << string(11 - id.length(), ' ') << "| ";
        cout << name << string(13 - name.length(), ' ') << "| ";
        cout << cccd << string(12 - to_string(cccd).length(), ' ') << "| ";
        cout << gender << string(7 - gender.length(), ' ') << "| ";
        cout << dob << string(14 - dob.length(), ' ') << "| ";
        cout  << totalAbsent << string(8 - to_string(totalAbsent).length(), ' ') << "|";
        cout<< " " << totalPermis << string(7 - to_string(totalAbsent).length(), ' ') << "|";
        cout<< " " << totalPresent << string(7 - to_string(totalAbsent).length(), ' ') << "|";
        cout << "             "<<Analists << string(19 - to_string(totalAbsent).length(), ' ') << "|\n";

    }
    void printAttendanceSummaryDayForCouse(Course &course, int totalCourseDays) {
        int totalStudentClass = course.GetToltalStudentt();
        cout << endl << endl;
        const Student* students = course.getStudents();
        string StudentCheck[totalStudentClass];
        cout << "Tổng sinh viên là: " << totalStudentClass << endl;
        cout << (isVietnamese ? "Danh sách Sinh viên:" : "List of Students:") << " lớp " << course.getCourseName() << ":" << endl;
        printStudentTableHeader2();

        int totalCouseday = course.getTotalCourseDay();// TỔNG SỐ NGÀY CẦN HỌC
        int executionNumberOfDays = course.getExecutionNumberOfDays();//SỐ NGÀY ĐÃ HỌC
        for (int i = 1; i < totalStudentClass + 1; i++) {
            int absentCount = 0; // TỔNG SỐ VẮNG CỦA MỘT SINH VIÊN
            int permission = 0; // TỔNG SỐ VẮNG CÓ PHÉP MỘT SINH VIÊN
            int present = 0; // TỔNG SỐ VẮNG CÓ PHÉP MỘT SINH VIÊN
            string id;
            string name;
            int cccd;
            string gender;
            string date;
            course.getExecutionNumberOfDays();
            string analysiscourse;

            for (int j = 0; j < numberAttendanceManager; j++) {
                int absentCountStudent = 0; // TỔNG SỐ VẮNG CỦA CÁC SINH VIÊN


                if (records[j].getCourse().getCourseId() == course.getCourseId() && records[j].getStudent().getStudentId() == students[i].getStudentId()) {
                    if (records[j].getAttendance() == "V") {
                        absentCount++;
                    } else if (records[j].getAttendance() == "P") {
                        permission++;
                    } else if (records[j].getAttendance() == "X") {
                        present++;
                    }
                    id = records[j].getStudent().getStudentId();
                    name = records[j].getStudent().getStudentName();
                    cccd = records[j].getStudent().getCccd();
                    gender = records[j].getStudent().getGender();
                    date = records[j].getStudent().getDate();
                    analysiscourse = "" + to_string(executionNumberOfDays) + ":buoi/" + to_string(totalCouseday)+":buoi";


                }



            }

            double absentPercentage = (static_cast<double>(absentCount) / totalCouseday) * 100;

            cout << "=============================================================================================================================================\n";

                cout << "Học sinh " << name << " đã nghỉ " << (absentPercentage / 30) * 100 << "%/" << 30 << "%" << endl;

                // Kiểm tra nếu tỷ lệ nghỉ lớn hơn hoặc bằng 30%
                if (absentPercentage >= 30) {
                    cout << "Học sinh " << name << " đã nghỉ quá số buổi!" << endl;
                }

            cout << "=============================================================================================================================================\n";

            printStudentTableRow2(id, name, cccd, gender, date, absentCount,permission,present,analysiscourse);
        }

        cout << "=============================================================================================================================================\n";
        cout<<endl;
        cout<<endl;
    };

    };


void chooseLanguage(bool &isVietnamese) {
    bool truee=false;
    while (truee==false) {
        cout << "Choose language:" << endl;
        cout << "2. Tiếng Việt" << endl;
        cout << "3. English" << endl;
        cout << "Enter your choice: ";
        int langChoice;
        cin >> langChoice;
        if (langChoice == 2) {
            isVietnamese = true;
            truee = true;
        } else if (langChoice == 3) {
            isVietnamese = false;
            truee = true;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

}

int main() {
    const int MAX_USERS = 100;
    User users[MAX_USERS]; // Mảng tối đa 100 tài khoản
    int numberOfUsers = 0; // Số lượng tài khoản hiện tại
//    cout << "+==============================================================+" << endl;


    //Thêm tài khoản người dùng vào mảng
    users[numberOfUsers++] = User::createUser("u", "12", "Name 1", "Male", "Address 1", "123456789", "01/01/2000", 12345, "C001");
    users[numberOfUsers++] = User::createUser("user2", "password2", "Name 2", "Female", "Address 2", "987654321", "02/02/2001", 67890, "Sub 2");
    users[numberOfUsers++] = User::createUser("user3", "password3", "Name 3", "Male", "Address 3", "555555555", "03/03/2002", 12345, "Sub 3");
    int adminCode; // Mã admin

    int choice;
    int userIndex = -1;
//    bool statusCase1 = false;
    bool statusCase1 = false;
    do {
        cout << "+==============================================================+" << endl;
        cout << "|      ********* Chào mừng bạn đến với hệ thống *********      |" << endl;
        cout << "|         ******* quản lý điểm danh sinh viên!********         |" << endl;
        cout << "+==============================================================+" << endl;
        cout << "           |                                        |"<< endl;
        cout << "           |      Đăng nhập để sử dụng hệ thống.    |"<< endl;
        cout << "           *----------------------------------------*" << endl;
        cout << endl;
        cout << "                 +===========+ +===========+" << endl;
        cout << "                 |1.Đăng nhập| |2. Đăng ký |" << endl;
        cout << "                 +===========+ +===========+" << endl;
        cout << endl;
        cout << "                  Nhập lựa chọn của bạn ^^ :";
        cin >> choice;

        switch (choice) {
            case 1: {
                bool found = false;
                string loginUname, loginPwd;
                AttendanceManager manager(3, 10);





//-----------------------------------------------------------------------
//                int numCourses = 2;
//-----------------------------------------------------------------------
//
//
//                for (int i = 0; i < numCourses; ++i) {
//                    string courseId = "C00" + to_string(i + 1);
//                    string courseName = "Course " + to_string(i + 1);
//                    int TotalCourseDay = 10 + i;
//                    courses[i].setCourseId(courseId);
//                    courses[i].setCourseName(courseName);
//                    courses[i].setTotalCourseDay(TotalCourseDay);
//                }
//------------------------------------------------------------------------

//                courses[0].setCourseName("C++");
//                courses[1].setCourseName("Giai Tich");



                ifstream filelophoc("taolophoc.txt");
                if (!filelophoc.is_open()) {
                    cerr << "Không thể mở file!" << endl;
                    return 1;
                }

                int numCourses;
                filelophoc >> numCourses; // Đọc số lượng khóa học từ file
                Course* courses = new Course[numCourses];

                // Đọc dữ liệu từ file và gán vào các đối tượng tương ứng
                for (int i = 0; i < numCourses; ++i) {
                    string courseId, courseName;
                    int TotalCourseDay;

                    filelophoc >> courseId >> courseName >> TotalCourseDay;

                    // Gán dữ liệu vào các đối tượng courses
                    courses[i].setCourseId(courseId);
                    courses[i].setCourseName(courseName);
                    courses[i].setTotalCourseDay(TotalCourseDay);
                }

                // Tiếp tục xử lý dữ liệu hoặc thực hiện các thao tác khác ở đây

                filelophoc.close(); // Đóng file




//------------------------------------------------------------------------
                ifstream file("taosinhvien.txt");
                if (!file.is_open()) {
                    cerr << "Không thể mở file!" << endl;
                    return 1;
                }

                int numbersudent;
                file >> numbersudent;
                Student students[numbersudent]; // Mảng chứa 4 sinh viên

                // Đọc dữ liệu từ file và tạo các đối tượng sinh viên tương ứng
                for (int i = 0; i < numbersudent; ++i) {
                    string studentId, studentName, gender, dateOfBirth;
                    int phoneNumber;

                    file >> studentId >> studentName >> phoneNumber >> gender >> dateOfBirth;

                    // Tạo đối tượng sinh viên và gán dữ liệu
                    students[i] = Student(studentId, studentName, phoneNumber, gender, dateOfBirth);
                }

                file.close(); // Đóng file
//                Student student1("0015168", "Duy Khanh", 123456789, "Female", "2000-01-01");
//                Student student2("0012833", "Nhat Anh", 234567890, "Male", "2000-02-02");
//                Student student3("0012333", "Ba Binh", 345678901, "Male", "2000-03-03");
//                Student student4("0053334", "Phan Quan", 345678901, "Male", "2000-03-03");
//------------------------------------------------------------------------

                for (int i = 0; i < numCourses; i++) {
                    manager.addStudent( students[i],courses[i]);
                    manager.addStudent( students[i],courses[i]);
                    manager.addStudent( students[i],courses[i]);

//                    manager.addStudent(student4,courses[i]);
//                    courses[i].SettoltalStudentt();
                }
                int day;
                string courseid ;
                string msv;
                string name;
                char status;
//                bool statusCase1 = false;


                cout << "Nhập tên đăng nhập để đăng nhập hoặc nhập 0 để quay lại menu: "<<endl;
                do {

                    cout << "+-----------------" << endl;
                    cout << "| Username:";
                    cin >> loginUname;
                    if (loginUname == "0") {
                        cout << "Quay lại menu chính." << endl;
                        break;
                    }
                    cout << "+-----------------" << endl;
                    cout << "| Mật khẩu:";
                    cin >> loginPwd;
                    cout << "+-----------------" << endl;

                    // Tìm tài khoản và đăng nhập
                    userIndex = -1; // Reset userIndex

                    for (int i = 0; i < numberOfUsers; ++i) {

                        if (users[i].isLogged()) {
                            continue; // Bỏ qua tài khoản đã đăng nhập
                        }

                        if (users[i].checkCredentials(loginUname, loginPwd)) {
                            users[i].login(loginUname, loginPwd);
                            found = true;
                            userIndex = i;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Tài khoản không tồn tại (hoặc) password không chính xác. Nhập lại hoặc chọn 0 để quay lại menu:" << endl;
                    }
                } while (!found);

                if (loginUname == "0") {
                    break;
                }

                do {
                                    cout << "+------------------------------+" << endl;
                    cout << (isVietnamese ? "|    Các chức năng hệ thống    |" : "===============================") << endl;
                    cout << "+------------------------------+" << endl;
                    cout << (isVietnamese ? "===============================" : "Attendance Management System ") << endl;
                    cout << "| 1. " << (isVietnamese ? "diem danh cho 1 ngay nao do chon lop " : "Mark attendance for a specific day for a class") << endl;
                    cout << "| 2. " << (isVietnamese ? "thong tin diem danh cua mon hoc trong ngay nao do" : "View attendance information of a subject for a specific day") << endl;
                    cout << "| 3. " << (isVietnamese ? "thong tin diem danh cua sinh vien trong tong so ngay" : "View attendance information of students for all days") << endl;
                    cout << "| 4. " << (isVietnamese ? "in thong tin hoc sinh lop hoc" : "Frint students on a class") << endl;
                    cout << "| 6. " << (isVietnamese ? "xem thong tin sinh vien" : "View student information") << endl;
                    cout << "| 7. " << (isVietnamese ? "xem tat ca cac ma diem danh" : "View all attendance codes") << endl;
                    cout << "| 8. " << (isVietnamese ? "in thong tin diem danh cua tat ca cac ngay cho mot sinh vien trong lop ..." : "Print attendance information of all days for a student in class ...") << endl;
                    cout << "| 9. " << (isVietnamese ? "thong ke diem danh cho sinh vien trong mot lop hoc" : "Statistics of attendance for students in a class") << endl;
                    cout << "|11. " << (isVietnamese ? "xem tai khoan" : "View account") << endl;
                    cout << "|12. " << (isVietnamese ? "Dang xuat" : "Logout") << endl;
                    cout << "|13. " << (isVietnamese ? "Chon ngon ngu EN/VN" : "Choose language EN/VN") << endl;
                    cout << "| 5. " << (isVietnamese ? "Thoat" : "Exit") << endl;
                    cout << "+------------------------------------------------" << endl;

                    cout << endl;
                    cout << "Nhap lua chon cua ban:";
                    cin >> choice;

                    switch (choice) {
                        case 13:
                            chooseLanguage(isVietnamese);
                            break;
                        case 1:
                             statusCase1 = false;

                            for(int i = 0 ; i < numCourses && !statusCase1 ; i++){ // Sử dụng !status thay vì status == false
                                cout << "+-----------------" << endl;
                                cout << (isVietnamese ? "| Nhập mã lớp:" : "| Enter course ID:");
                                cin >> courseid;
                                if(  users[userIndex].getSubject()==courseid){

                                }else{
                                    cout << (isVietnamese ? "Ma bo mon tai khoan khong trung voi ma lop diem danh :" : "Subject code does not match attendance class code :") << endl;

                                    break;
                                }

                                cout << "+-----------------" << endl;
                                cout << (isVietnamese ? "| Nhập ngày:" : "| Enter day:");
                                cin >> day;
                                cout << "+-----------------" << endl;

                                if(courses[i].courseId == courseid){
                                    if(manager.CheckDayAttendances(day, courses[i])){
                                        manager.inputAttendanceforday(day , courses[i] ,numCourses); // Adjusted index
                                        statusCase1 = true; // Gán true cho status khi nhập điểm danh thành công
                                    }
                                }
                            }

                            break;
                        case 2:
                            cout << "+-----------------" << endl;
                            cout << (isVietnamese ? "| Nhập ngày:" : "| Enter day:");
                            cin >> day;
                            cout << "+-----------------" << endl;
                            cout << (isVietnamese ? "| Nhập mã lớp:" : "| Enter course ID:");
                            cin >> courseid;
                            cout << "+-----------------" << endl;

                            if(  users[userIndex].getSubject()==courseid){

                            }else{
                                cout << (isVietnamese ? "ma bo mon tai khoan khong trung voi ma lop diem danh :" : "Subject code does not match attendance class code :") << endl;

                                break;
                            }

                            for(int i = 0 ; i < numCourses ;i++)
                                if(courses[i].courseId == courseid){
                                    manager.viewAttendancesOnDayOncourseIdOnDay(day - 1, courses[i] ,numCourses);

                                };
                            break;

                        case 3:
                            cout << "+---------------" << endl;
                            cout << (isVietnamese ? "| Nhập mã lớp:" : "| Enter course ID:");
                            cin >> courseid;
                            cout << "+---------------" << endl;
                            if(  users[userIndex].getSubject()==courseid){

                            }else{
                                cout << (isVietnamese ? "ma bo mon tai khoan khong trung voi ma lop diem danh :" : "Subject code does not match attendance class code :") << endl;
                                break;
                            }
                            for(int i = 0 ; i < numCourses ;i++){
                                if(courses[i].courseId == courseid){
                                    manager.viewTottalAttendancesOnCourseId(courses[i], courses[i].getTotalCourseDay());
                                };
                            }

                            break;



                        case 4:
                            cout << "+---------------" << endl;
                            cout << (isVietnamese ? "| Nhập mã lớp:" : "| Enter course ID:");
                            cin >> courseid;
                            cout << "+---------------" << endl;

                            for(int i = 0 ; i < numCourses ;i++){
                                if(courses[i].courseId == courseid){
                                    manager.viewAllStudentOncourse(courses[i]);
                                };
                            }

                            break;



                        case 6:
                            manager.ListStudent();
                            break;

                        case 7:
                            manager.printAllAttendanceRecords();
                            break;

                        case 8:
                            cout << "+------------------------------------" << endl;
                            cout << (isVietnamese ? "| Nhap ma mon hoc: " : "| Enter course ID: ");
                            cin >> courseid;
                            cout << "+------------------------------------" << endl;
                            cout << (isVietnamese ? "| Nhap ma sinh vien: " : "| Enter student ID: ");
                            cin >> msv;
                            cout << "+------------------------------------" << endl;

                            if(  users[userIndex].getSubject()==courseid){

                            }else{

                                cout << "+---------------------------------------------------------------" << endl;
                                cout << (isVietnamese ? "| Ma bo mon tai khoan khong trung voi ma lop diem danh:" : "| Subject code does not match attendance class code :") << endl;
                                cout << "+---------------------------------------------------------------" << endl;
                                break;
                            }
                            for(int i = 0 ; i < numCourses ;i++){
                                if(courses[i].courseId == courseid){
                                    manager.printAttendanceSummaryForStudent(courseid, msv, courses[i].getTotalCourseDay());

                                };
                            }
                            break;

                        case 9:
                            cout << "+------------------------------------" << endl;
                            cout << (isVietnamese ? "| Nhap ma mon hoc: " : "| Enter course ID: ");
                            cin >> courseid;

                            if(  users[userIndex].getSubject()==courseid){

                            }else{
                                cout << (isVietnamese ? "ma bo mon tai khoan khong trung voi ma lop diem danh :" : "Subject code does not match attendance class code :") << endl;
                                break;
                            }

                            for(int i = 0 ; i < numCourses ;i++){
                                if(courses[i].courseId == courseid){
                                    manager.printAttendanceSummaryDayForCouse(courses[i] , courses[i].getTotalCourseDay());

                                };
                            }
                            break;

                        case 11: {

                            cout << (isVietnamese ? " Xem tai khoan." : " View account.") << endl;
//                            cout << "Giá trị mới của userIndex: " << userIndex << endl;
                            if (userIndex != -1) {
                                users[userIndex].viewInfo();
                            } else {
                                cout << (isVietnamese ? "Ban can dang nhap de xem thong tin tai khoan cua minh." : "You need to log in to view your account information.") << endl;
                            }
                            break;
                        }
                        case 12:
                            users[userIndex].logout();
                            break;

                        case 5:
                            cout << "Exiting program..." << endl;
                            break;
                        default:
                            cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
                    }
                } while (choice != 5);
                break;
            }
            case 2: {
                string uname, pwd, confirmPwd, name, gender, addr, phone, birth, sub;
                do {
                    cout << "Nhap ten dang ki hoac bam 0 de thoat: ";
                    cin >> uname;

                    if (uname == "0") {
                        cout << "Quay lai menu chinh." << endl;
                        break;
                    }
                    cout << "Nhap mat khau: ";
                    cin >> pwd;
                    cout << "Nhap lai mat khau: ";
                    cin >> confirmPwd;
                    if (pwd != confirmPwd) {
                        cout << "Mat khau khong khop. Vui long thu lai." << endl;
                    }


                    if (uname == "0") {
                        break;
                    }
                    cout << "Nhap ho ten: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Nhap gioi tinh: ";
                    cin >> gender;
                    // Nhap dia chi
                    cout << "Nhap dia chi: ";
                    cin.ignore();
                    getline(cin, addr);
                    cout << "Nhap so dien thoai: ";
                    cin >> phone;
                    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
                    cin >> birth;
                    cout << "Nhap ma admin: ";
                    cin >> adminCode;
                    cout << "Nhap ma lop hoc: ";
                    cin >> sub;
                    if (adminCode != 12345 && adminCode != 67890) {
                        cout << "Ma admin khong chinh xac. Vui long thu lai." << endl;
                        return 0;
                    }
                    users[numberOfUsers++] = User::createUser(uname, pwd, name, gender, addr, phone, birth, adminCode, sub);
                    cout << "Dang ki tai khoan moi thanh cong!" << endl;
                } while (true);
                break;
            }
            default:
                cout << "Lua chon khong hop le." << endl;
        }
    } while (true);
    return 0;
}
