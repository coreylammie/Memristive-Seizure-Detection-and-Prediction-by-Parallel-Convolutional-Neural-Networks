import os
from datetime import datetime, timedelta


def create_dir(directory_path):
    """Method to create a directory. Returns True if the directory already exists."""
    if os.path.exists(directory_path):
        return True
    else:
        os.makedirs(directory_path)
        return False


def round_down(num, divisor):
    """Method to round down a number"""
    return num - (num % divisor)


def get_time(datetime_string):
    """Method to convert a string to a datetime object."""
    time = 0
    try:
        time = datetime.strptime(datetime_string, "%H:%M:%S")
    except ValueError:
        datetime_string = " " + datetime_string
        if " 24" in datetime_string:
            datetime_string = datetime_string.replace(" 24", "23")
            time = datetime.strptime(datetime_string, "%H:%M:%S")
            time += timedelta(hours=1)
        else:
            datetime_string = datetime_string.replace(" 25", "23")
            time = datetime.strptime(datetime_string, "%H:%M:%S")
            time += timedelta(hours=2)

    return time
