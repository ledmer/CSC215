import sys

# Octal to Binary for Intel 8080:


octal_code = [ 0o076, 0o014, 0o326, 0o031, 0o166, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,             
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000, 0o000,
                ]


# Read input from command line arguments or fallback to interactive input
def get_file_path():
    if len(sys.argv) > 1:
        return sys.argv[1]
    else:
        file_path = input("Enter the file path: ")
        right_file_path = False

        while not right_file_path:
        # Ask user for confirmation
            confirmation = input(f"The file path is: {file_path}. Is this the correct path? \n (Y/N, Default: Y): ").strip().upper()
        
            if confirmation in ["Y", "YES", ""]:
                # User confirmed the path is correct
                right_file_path = True
                print("File path confirmed.")
                return file_path
            elif confirmation in ["N", "NO"]:
                # User wants to enter a new file path
                file_path = input("Enter the new file path: ")
            else:
                # Handle invalid input
                print("Invalid input. Please enter 'Y' or 'N'.")
        


file_path = get_file_path()
file_path += "subtraction.bin"


# Write the octal data to a .bin file

with open(file_path, "wb") as f:
    f.write(bytearray(octal_code))
