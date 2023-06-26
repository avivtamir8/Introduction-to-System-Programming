import json
import os


def names_of_registered_students(input_json_path, course_name):
    """
    This function returns a list of the names of the students who registered for
    the course with the name "course_name".

    :param input_json_path: Path of the students database json file.
    :param course_name: The name of the course.
    :return: List of the names of the students.
    """
    with open(input_json_path, 'r') as f:
        data = json.load(f)

    return [data[student]['student_name'] for student in data if course_name in data[student]['registered_courses']]


def enrollment_numbers(input_json_path, output_file_path):
    """
    This function writes all the course names and the number of enrolled
    student in ascending order to the output file in the given path.

    :param input_json_path: Path of the students database json file.
    :param output_file_path: Path of the output text file.
    """
    with open(input_json_path, 'r') as f:
        data = json.load(f)

    courses = {}

    for student in data:
        for course in data[student]['registered_courses']:
            courses[course] = courses.get(course, 0) + 1

    with open(output_file_path, "w") as f:
        for key in sorted(courses):
            print(f'"{key}" {courses[key]}', file=f)


def courses_for_lecturers(json_directory_path, output_json_path):
    """
    This function writes the courses given by each lecturer in json format.

    :param json_directory_path: Path of the semsters_data files.
    :param output_json_path: Path of the output json file.
    """

    lecturers = {}

    for file in os.listdir(json_directory_path):
        if file.endswith(".json"):
            currentFile = os.path.join(json_directory_path, file)
            with open(currentFile, 'r') as f:
                data = json.load(f)

            for course in data:
                course_name = data[course]['course_name']
                for lecture_name in data[course]['lecturers']:
                    if lecture_name not in lecturers:
                        lecturers[lecture_name] = [course_name]
                    elif course_name not in lecturers[lecture_name]:
                        lecturers[lecture_name].append(course_name)

    with open(output_json_path, 'w') as f:
        json.dump(lecturers, f, indent=4)
