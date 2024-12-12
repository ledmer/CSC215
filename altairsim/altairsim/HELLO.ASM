        ORG     100H

BDOS    EQU     0005H                   ; LOCATION OF BDOS ENTRY POINT

START:
        MVI     C,9                     ; BDOS REQUEST 9 - PRINT STRING
        LXI     D,MESSAGE               ; OUR STRING TO PRINT
        CALL    BDOS
        RET                             ; CLEAN EXIT TO CP/M

MESSAGE:
        DB      13,10,'HELLO WORLD',13,10,'$'

        END     START
