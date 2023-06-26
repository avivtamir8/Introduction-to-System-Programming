from ex5 import names_of_registered_students, enrollment_numbers, courses_for_lecturers
import json

input_json_path = "students_database.json"
database_directory_path = "semesters_databases"

# print(names_of_registered_students(input_json_path, "Introduction to Systems Programming"))

print(enrollment_numbers(input_json_path, "test2.out"))

# print(courses_for_lecturers(database_directory_path,"test3_output.json"))
