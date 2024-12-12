; Define subroutines
TWOCR:  CALL CCRLF         ; Prints two line feeds
        CALL CCRLF
        RET

SPMSG:  ; Displays an inline message
        XTHL                ; Get return address from stack
        LXI D, 0           ; Set DE register pair to zero
SPMSG_LOOP:
        MOV A, M           ; Load character from memory
        INX H              ; Increment pointer
        ORA A              ; Check if it's zero (end of string)
        RZ                 ; Return if zero
        CALL CO            ; Output character
        JMP SPMSG_LOOP     ; Loop until end of string

GETNUM: ; Reads a number from the user
        CALL CIMSG         ; Prompt for input
        CALL GETLINE       ; Get input line
        CALL STR2NUM       ; Convert string to number
        RET

GETYN:  ; Get a Yes or No response
        CALL CIMSG         ; Prompt for input
        CALL GETCHAR       ; Read first character
        ANI 0DFH           ; Convert to uppercase
        CPI 'Y'            ; Compare with 'Y'
        RZ                 ; Return with zero flag if Yes
        CPI 'N'            ; Compare with 'N'
        RNZ                ; Return with non-zero flag if No
        JMP GETYN          ; Reprompt on invalid input

; Main Program
START:  
        CALL TWOCR
        CALL SPMSG
        DB 'Enter the first number: ', 0
        CALL GETNUM        ; Get first number
        MOV B, A           ; Store in register B
        
        CALL TWOCR
        CALL SPMSG
        DB 'Enter the second number: ', 0
        CALL GETNUM        ; Get second number
        MOV C, A           ; Store in register C
        
        MVI D, 0           ; Clear high byte of result
        MVI E, 0           ; Clear low byte of result
        LXI H, 0           ; Clear accumulator

MULT_LOOP:
        MOV A, C           ; Check if multiplier is zero
        ORA A
        JZ MULT_DONE       ; If zero, multiplication is done
        MOV A, B           ; Add multiplicand to result
        DAD H
        DCX C              ; Decrement multiplier
        JMP MULT_LOOP      ; Loop back
        
MULT_DONE:
        CALL TWOCR
        CALL SPMSG
        DB 'Result: ', 0
        CALL NUM2STR       ; Convert result to string
        CALL SPMSG         ; Display result
        DB 0

        CALL TWOCR
        CALL SPMSG
        DB 'Try again? (Y/N): ', 0
        CALL GETYN         ; Get Yes/No input
        JZ START           ; Restart if Yes
        
        CALL SPMSG
        DB 'Goodbye!', 0
        HLT                ; Halt the program

; End of Program
END START
