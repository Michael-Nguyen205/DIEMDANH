#include <iostream>
#include <string>

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

    string courseName;
    int LimitCourseDay;
    int TotalCourseDay; // tổng số buổi học của lớp này

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

    // Destructor
    ~Course() {
        // Giảm kích thước mỗi khi đối tượng Course bị hủy
    }

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

public:

    static int totalAtten;

    AttendanceRecord() {
        status = "";
        numDays = 0;
    }


    void setCourse(const Course& cours) {
        course = cours;
    }



    AttendanceRecord(Student std ,Course cous,int Day) {
        student = std;
        course = cous;
        day = Day;
//        numDays = days;
//        status = '';

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
            day = Day;
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


    void addStudent(const Student& student, const Course& course) {
        // Kiểm tra xem sinh viên đã tồn tại trong danh sách chưa
//        bool exists = false;
//        for (int i = 0; i < number; ++i) {
//            if (records[i].getStudent().getStudentId() == student.getStudentId()) {
//                exists = true;
//                break;
//            }
//        }

//        if (!exists) {
        for (int i = 0; i < course.getTotalCourseDay(); ++i) {
            // Thêm sinh viên vào danh sách nếu chưa tồn tại
            records[numberAttendanceManager] = AttendanceRecord(student, course,i ) ;
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




//
//



//    void printStudentTableHeader1() {
//        cout << "==================================================================================\n";
//        cout << "| MSV        | Student Name | CCCD        | Gender | Date of Birth | Attendances |\n";
//        cout << "==================================================================================\n";
//    }

    void printStudentTableRow3(const string& id, const string& name, int cccd, const string& gender, const string& dob ) {
        cout << "| " << id << string(11 - id.length(), ' ') << "| ";
        cout << name << string(13 - name.length(), ' ') << "| ";
        cout << cccd << string(12 - to_string(cccd).length(), ' ') << "| ";
        cout << gender << string(7 - gender.length(), ' ') << "| ";
        cout << dob << string(14 - dob.length(), ' ') << "| ";
//        cout << At << string(11, ' ') << "|\n"; // Sử dụng một ký tự duy nhất để thay thế khoảng trắng
    }


    void inputAttendanceforday(int day, Course course, int numCourses) {
        if (day >= 0 && day < numDays) {
            char status;
            cout << "-----------------------------------------------------------------------------------" << endl;
            cout << (isVietnamese ? "Nhap 'P' neu vang co phep, 'X' neu co mat, 'V' neu vang khong phep" : "Enter 'P' if authorized absence, 'X' if Present, 'V' if Absent without permission") << endl;
            cout << "-----------------------------------------------------------------------------------" << endl;

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
                        cout << (isVietnamese ? "Vui long chi chon 'P', 'X', hoac 'V': " : "Please select only 'P', 'X', or 'V': ") << endl;
                        cout << "----------------------------------------------------" << endl;
                        cout << " - Lớp " << records[i].getCourse().courseId << " - Học sinh " << records[i].getStudent().getStudentName() << ": ";
                        cin >> status;
                        cout << "----------------------------------------------------" << endl;
                    }

                    records[i].setAttendanceForDay(day, status);
                }
//                cout << "----------------------------------------------------------------------------------" << endl;
            }
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
            cout << "| MSV        | Student Name   | CCCD      | Gender | Date of Birth | Attendances |\n";
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
        cout << (isVietnamese ? "Diem danh cho khoa hoc " : "Attendance for course ") << course.getCourseName() << ":" << endl;
        cout << (isVietnamese ? "Tong so ngay diem danh: " : "Total number of attendance days: ") << totalCourseDays << endl;

        for (int i = 0; i < totalCourseDays; i++) {
            cout << "Attendance for day " << i + 1 << ":" << endl;
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
                cout << "==================================================================================\n";
                cout << "| MSV        | Ten Sinh Vien | CCCD       |Gioitinh| Ngay sinh     | Diem Danh   |\n";
                cout << "==================================================================================\n";
            } else {
                cout << "==================================================================================\n";
                cout << "| MSV        | Student Name   | CCCD      | Gender | Date of Birth | Attendances |\n";
                cout << "==================================================================================\n";
            }
        }

    void printStudentTableRow2(const string& id, const string& name, int cccd, const string& gender, const string& dob, int totalAbsent) {
        cout << "| " << id << string(11 - id.length(), ' ') << "| ";
        cout << name << string(13 - name.length(), ' ') << "| ";
        cout << cccd << string(12 - to_string(cccd).length(), ' ') << "| ";
        cout << gender << string(7 - gender.length(), ' ') << "| ";
        cout << dob << string(14 - dob.length(), ' ') << "| ";
        cout << totalAbsent << string(12 - to_string(totalAbsent).length(), ' ') << "|\n";
    }

    void printAttendanceSummaryDayForCouse(Course course, int totalCourseDays) {
        int absentCount = 0;
        int totalStudent=0;

        cout <<  endl;
        cout <<  endl;
        cout << (isVietnamese ? "Danh sách Sinh viên:" : "List of Students:") << endl;
        printStudentTableHeader2();

        for(int i = 0; i < numberAttendanceManager; i++) {
            int absentCountStudent = 0;
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
                // Đếm số buổi nghỉ của sinh viên
                if (records[i].getAttendance() == "V") {
                    absentCount++;
                    absentCountStudent++;
                }

                // Lấy thông tin sinh viên
                string id = records[i].getStudent().getStudentId();
                string name = records[i].getStudent().getStudentName();
                int cccd = records[i].getStudent().getCccd();
                string gender = records[i].getStudent().getGender();
                string dob = records[i].getStudent().getDate();


                // In thông tin sinh viên
                printStudentTableRow2(id, name, cccd, gender, dob,absentCountStudent);
                totalStudent++;
            }
        }

        // Tính tỷ lệ vắng mặt
        double absentPercentage = (static_cast<double>(absentCount) / totalCourseDays) * 100;


        // In thống kê vắng mặt
        cout << "==================================================================================\n";
        cout << (isVietnamese ? "| Tong ket vang mat                                                             |\n" : "| Absentee Summary                                                               |\n");
        cout << "==================================================================================\n";
        cout << (isVietnamese ? "| Tong so sinh vien: " : "| Total number of students: ") << totalStudent << string(53 - to_string(totalStudent).length(), ' ') << "|\n";
        cout << (isVietnamese ? "| Tong so ngay: " : "| Total number of days: ") << totalCourseDays << string(57 - to_string(totalCourseDays).length(), ' ') << "|\n";
        cout << (isVietnamese ? "| Tong so lan vang: " : "| Total number of absences: ") << absentCount << string(53 - to_string(absentCount).length(), ' ') << "|\n";
        cout << (isVietnamese ? "| Ti le vang: " : "| Percentage of absences: ") << absentPercentage << "%" << string(61 - to_string(absentPercentage).length(), ' ') << "|\n";
        cout << "===================================================================================\n";


    }


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

    //Thêm tài khoản người dùng vào mảng
    users[numberOfUsers++] = User::createUser("u", "12", "Name 1", "Male", "Address 1", "123456789", "01/01/2000", 12345, "C001");
    users[numberOfUsers++] = User::createUser("user2", "password2", "Name 2", "Female", "Address 2", "987654321", "02/02/2001", 67890, "Sub 2");
    users[numberOfUsers++] = User::createUser("user3", "password3", "Name 3", "Male", "Address 3", "555555555", "03/03/2002", 12345, "Sub 3");


    int adminCode; // Mã admin

    int choice;
    int userIndex = -1;

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


                int numCourses = 2;
                Course* courses = new Course[numCourses];


                for (int i = 0; i < numCourses; ++i) {
                    string courseId = "C00" + to_string(i + 1);
                    string courseName = "Course " + to_string(i + 1);
                    int TotalCourseDay = 10 + i;
                    courses[i].setCourseId(courseId);
                    courses[i].setCourseName(courseName);
                    courses[i].setTotalCourseDay(TotalCourseDay);
                }


                Student student1("S001", "Alice", 123456789, "Female", "2000-01-01");
                Student student2("S002", "Bob", 234567890, "Male", "2000-02-02");
                Student student3("S003", "Charlie", 345678901, "Male", "2000-03-03");


                for (int i = 0; i < numCourses; i++) {
                    manager.addStudent(student1,courses[i]);
                    manager.addStudent(student2,courses[i]);
                    manager.addStudent(student3,courses[i]);

                }
                int day;
                string courseid ;
                string msv;
                string name;
                char status;


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
                    cout << "| 4. " << (isVietnamese ? "loc sinh vien theo trang thai diem danh cho mot ngay" : "Filter students by attendance status for a day") << endl;
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
                    cout << "Nhap lua chon cua ban: ";
                    cin >> choice;


                    switch (choice) {


                        case 13:
                            chooseLanguage(isVietnamese);


                            break;


                        case 1:


                            cout << "+-----------------" << endl;
                            cout << (isVietnamese ? "| Nhập ngày:" : "| Enter day:");
                            cin >> day;
                            cout << "+-----------------" << endl;
                            cout << (isVietnamese ? "| Nhập mã lớp:" : "| Enter course ID:");
                            cin >> courseid;
                            cout << "+-----------------" << endl;




                            if(  users[userIndex].getSubject()==courseid){

                            }else{
                                cout << (isVietnamese ? "Ma bo mon tai khoan khong trung voi ma lop diem danh :" : "Subject code does not match attendance class code :") << endl;

                                break;
                            }


                            for(int i = 0 ; i < numCourses ;i++)
                                if(courses[i].courseId == courseid){
                                    manager.inputAttendanceforday(day - 1, courses[i] ,numCourses);

                                };
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
