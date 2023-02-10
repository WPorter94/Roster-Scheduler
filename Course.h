
#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>


using std::string;

class Course {
public:
    // Constructor
    Course();

    Course(string dept, double coursenum, string term,
        int sections, int seats);

    // copy constructor
    Course(const Course& orig);

    // assignment operator
    Course& operator=(const Course& orig);

    // == comparison operator
    bool operator==(const Course& orig);

    // == comparison operator
    bool operator!=(const Course& orig);

    // < comparison operator
    // compare course number
    bool operator<(const Course& orig);

    bool operator>=(const Course& orig);

    // override the insertion operator
    // return ostream in the following format.  Fields are separate
    // by space and newline at the end.
    // dept coursenum term sections course.seats 
    friend std::ostream& operator<<(std::ostream& out, const Course& course) {

        out << course.GetDept() << " " << course.GetCoursenum() << " " << course.GetTerm() << " " << course.GetSections() << " " << course.GetSeats() << std::endl;
        return out;

    }

    virtual ~Course() {};  // not use

    // accessor and mutator methods
    void SetSeats(int seats);
    int GetSeats() const;
    void SetSections(int sections);
    int GetSections() const;
    void SetTerm(string term);
    string GetTerm() const;
    void SetCoursenum(double coursenum);
    double GetCoursenum() const;
    void SetDept(string dept);
    string GetDept() const;

private:
    string dept;
    double coursenum;
    string term;
    int sections;
    int seats;

};

Course::Course()
{
    this->dept = "";
    this->coursenum = 0;
    this->term = "";
    this->sections = 0;
    this->seats = 0;
}

Course::Course(string dept, double coursenum, string term, int sections, int seats)
{
    this->dept = dept;
    this->coursenum = coursenum;
    this->term = term;
    this->sections = sections;
    this->seats = seats;
}

// copy constructor
Course::Course(const Course& orig)
{
    this->dept = orig.dept;
    this->coursenum = orig.coursenum;
    this->term = orig.term;
    this->sections = orig.sections;
    this->seats = orig.seats;
}

// assignment operator
Course& Course::operator=(const Course& orig)
{
    if (&orig == this)
    {
        return *this;
    }
    this->coursenum = orig.GetCoursenum();
    this->dept = orig.GetDept();
    this->term = orig.GetTerm();
    this->sections = orig.sections;
    this->seats = orig.seats;
    return *this;

}

// == comparison operator
bool Course::operator==(const Course& orig)
{
    if (this->coursenum == orig.coursenum)
    {
        return true;
    }
    return false;

}

// == comparison operator
bool Course::operator!=(const Course& orig)
{
    if (this->coursenum != orig.coursenum)
    {
        return true;
    }
    return false;

}

// < comparison operator
// compare course number
bool Course::operator<(const Course& orig)
{
    return this->coursenum < orig.coursenum;
}

bool Course::operator>=(const Course& orig)
{
    if (this->coursenum > orig.coursenum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// override the insertion operator
// return ostream in the following format.  Fields are separate
// by space and newline at the end.
// dept coursenum term sections course.seats 
//std::ostream& operator<<(std::ostream& out, const Course& course)
//{
  //  out << course.dept << " " << course.coursenum << " " << course.term << " " << course.sections << " " << course.seats << std::endl;
    //return out;
//}



// accessor and mutator methods
void Course::SetSeats(int seats)
{
    this->seats = seats;
}
int Course::GetSeats() const
{
    return this->seats;
}
void Course::SetSections(int sections)
{
    this->sections = sections;
}
int Course::GetSections() const
{
    return this->sections;
}
void Course::SetTerm(string term)
{
    this->term = term;
}
string Course::GetTerm() const
{
    return this->term;
}
void Course::SetCoursenum(double coursenum)
{
    this->coursenum = coursenum;
}
double Course::GetCoursenum() const
{
    return this->coursenum;
}
void Course::SetDept(string dept)
{
    this->dept = dept;
}
string Course::GetDept() const
{
    return this->dept;
}
#endif /* COURSE_H */


