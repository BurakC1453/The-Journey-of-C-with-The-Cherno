#include <iostream>
#include <vector>
#include <string>

class Grade_Tracker
{
private:
	
std::vector <std::string> students_names;
std::vector <double> students_grades;

std::string student_name;
double student_grade = 0.0;
int user_choice_of_operation = 0;
double total_grade = 0.0;

void add_student()
{
	students_names.push_back(student_name);
	students_grades.push_back(student_grade);
}

void get_student_info()
{
	std::cout << "Enter student name: ";
	std::cin >> student_name;
	std::cout << "Enter student grade: ";
	std::cin >> student_grade;
}

void clear()
{
	student_name = "";
	student_grade = 0.0;
}

void display_students()
{
	std::cout << "Student Name\tGrade\n";
	for (size_t i = 0; i < students_names.size(); ++i)
	{
		std::cout << students_names[i] << "\t\t" << students_grades[i] << "\n";
	}
}

void display_specific_student_info()
{
	std::string name_to_find;
	std::cout << "Enter student name to find: ";
	std::cin >> name_to_find;
	for (size_t i = 0; i < students_names.size(); ++i)
	{
		if (students_names[i] == name_to_find)
		{
			std::cout << "Student Name: " << students_names[i] << "\nGrade: " << students_grades[i] << std::endl;
			return;
		}
	}
	std::cout << "Student not found." << std::endl;
}

void display_highest_grade()
{
	if (!students_grades.empty())
	{
		double highest_grade = students_grades[0];
		for (const auto& grade : students_grades)
		{
			if (grade > highest_grade)
			{
				highest_grade = grade;
			}
		}
		std::cout << "Highest Grade: " << highest_grade << std::endl;
	}
	else
	{
		std::cout << "No students added yet." << std::endl;
	}
}

void display_lowest_grade()
{
	if (!students_grades.empty())
	{
		double lowest_grade = students_grades[0];
		for (const auto& grade : students_grades)
		{
			if (grade < lowest_grade)
			{
				lowest_grade = grade;
			}
		}
		std::cout << "Lowest Grade: " << lowest_grade << std::endl;
	}
	else
	{
		std::cout << "No students added yet." << std::endl;
	}
}

void display_average_grade()
{
	if (!students_grades.empty())
	{
		total_grade = 0.0;
		for (const auto& grade : students_grades)
		{
			total_grade += grade;
		}
		std::cout << "Average Grade: " << total_grade / students_grades.size() << std::endl;
	}
	else
	{
		std::cout << "No students added yet." << std::endl;
	}
}

void choice_of_user_about_operation()
{
	std::cout << "1. Add student\n2.Display Students Info\n3.Display Specific Student Info\n4.Exit"<< std::endl;
	std::cin >> user_choice_of_operation;
}

void perform_operation()
{
	switch (user_choice_of_operation)
	{
	case 1:
		get_student_info();
		add_student();
		clear();
		std::cout << "Student added successfully." << std::endl; 
		std::cout << "Number of students in the system : " << students_names.size() << std::endl;
		break;
	case 2:
		display_students();
		display_highest_grade();
		display_lowest_grade();
		display_average_grade();
		break;
	case 3:
		display_specific_student_info();
		break;
	case 4:
		std::cout << "Exiting the program." << std::endl;
		exit(0);
	default:
		std::cout << "Invalid choice. Please try again." << std::endl;
	}
}

public:
	void run()
	{
		while (true)
		{
			choice_of_user_about_operation();
			perform_operation();
		}
	}

};

int main()
{
	Grade_Tracker tracker;
	tracker.run();
	return 0;
}