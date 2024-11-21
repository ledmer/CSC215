### **Notes on Chapter 11: Learning by Doing**

#### **Introduction**
- This chapter focuses on building programming skills through hands-on exercises.
- The goal is to familiarize users with the CP/M environment and its tools, specifically editing, assembling, and debugging programs.

---

#### **Getting to Know the CP/M Editor (ED)**
- **Purpose of ED:** A line-based text editor used to create and modify assembly language source files.
- **Basic Commands:**
  - **`A`**: Append text after the current line.
  - **`I`**: Insert text before the current line.
  - **`D`**: Delete the current line.
  - **`E`**: Exit and save the file.
  - **`X`**: Exit without saving changes.
  - **`L`**: List lines within the file.
- **Usage Example:**
  - Start ED with `ED <filename>`.
  - Use append or insert commands to enter the program text.
  - Save using the `E` command after editing.

---

#### **Assembling the TEST Program**
- **TEST Program Overview:**
  - A simple assembly language program designed to demonstrate the use of CP/M tools.
  - Written to familiarize the user with syntax and assembly techniques.
- **Steps to Assemble:**
  1. Use ED to create the source file (`TEST.ASM`).
  2. Assemble the file using the CP/M assembler: `ASM TEST`.
     - This generates `.HEX` and `.PRN` files for the program.
  3. Handle assembly errors by referring to the `.PRN` file, which lists the errors and their locations.
  4. Correct errors in ED and reassemble.

---

#### **Loading and Running TEST**
- After successful assembly, load the program:
  - Use the CP/M loader: `LOAD TEST`.
  - This converts the `.HEX` file to an executable `.COM` file.
- **Execution:**
  - Run the program by typing its name at the CP/M prompt: `TEST`.
- **Troubleshooting:**
  - Debug issues using the CP/M debugging tool (DDT).
  - Examples include checking memory locations or stepping through code.

---

#### **Exercises**
- **Purpose:** Reinforce learning through practical application.
- Suggested exercises include:
  - Modifying the `TEST` program to display different messages or perform different functions.
  - Exploring additional ED commands and features.
  - Practice editing, assembling, and loading files repeatedly to build fluency.

---

#### **More on ED**
- **Advanced Features:**
  - Edit specific lines by addressing them directly.
  - Save temporary backups during editing.
- **Tips:**
  - Always save work frequently (`E` command).
  - Use the `L` command to review the file after edits.

---

#### **Conclusion**
- **Key Skills Developed:**
  - Proficiency in using the CP/M editor (ED).
  - Basic understanding of assembly language syntax.
  - Familiarity with assembling, loading, and running programs in the CP/M environment.
- **Focus:** Mastering these basics ensures readiness for more complex programs in subsequent chapters.