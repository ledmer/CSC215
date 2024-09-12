
## Instructions

1. Download the substraction.py. 
2. Run it doing either.

> $ python substraction.py "Path of directory" 

> $ python substraction.py

3. This will generate a 'subtraction.bin' file in your desired directory.

4. load the 'subtraction.bin' file into the <a href="https://www.s2js.com/altair/sim.html#">Altair 8800 Simulator Website</a> using the "LOAD BINARY FILE" link.


## Subtraction.py
| Address  | Octal_Code | Hex_code | Instruction  | Description                                  |
|----------|----------|----------|--------------|----------------------------------------------|
| 000 000  | 076  | 3E   | MVI A, 25    | $25 \rightarrow$ A                                         |
| 000 001  | 031      |   19   |        | $25 = 031_8$                                     |
| 000 002  | 326  |D6    | SUI 18       | A $- 12 \rightarrow$  A                                       |
| 000 003  | 014      |   0C  |        | $12=014_8$                                      |
| 000 004  | 166      | 76 |HLT          | Halt execution                               |

## Proving that it works! 
### Test 1
| Address   | Octal_code | Hex_code|Instruction      | Description                                      |
|-----------|--------|--------|------------------|--------------------------------------------------|
| 000 000   | 076  |3E  | MVI A, 13        | Load immediate value 13 into register A ($13 \rightarrow$ A) |
| 000 001   | 015   |    0D    |       | $ 13 = 015_8$                                        |
| 000 002   | 057    |2F |CMA              | Complement of A (A' $\rightarrow$ A)                    |
| 000 003   | 306 | C6  | ADI 1            | Add immediate $1$ to A (A $+ 1 \rightarrow$  A)                |
| 000 004   | 001    | 01|                 | $1 = 001_8$                                       |
| 000 005   | 166  | 76 | HLT              | Halt execution                                   |
### Test 2

>Run subtraction.bin in <a href="https://www.s2js.com/altair/sim.html#">Altair 8800 Simulator Website</a> before this test (don't reset or clear the simulator).

| Address   | Octal Code | Hex Code | Instruction      | Description                                      |
|-----------|------------|----------|------------------|--------------------------------------------------|
| 000 000   | 326        | D6       | SUI 1            | Subtract immediate $1$                           |
| 000 001   | 001        | 01       |                  | $1 = 01_{16}$                                    |
| 000 002   | 057        | 2F       | CMA              | Complement of A (A' $\rightarrow$ A)             |
| 000 003   | 166        | 76       | HLT              | Halt execution                                   |

## Reference:

https://altairclone.com/downloads/manuals/8080%20Programmers%20Manual.pdf

https://www.s2js.com/altair/sim.html#

https://altairclone.com/downloads/manuals/Altair%208800%20Operator's%20Manual.pdf