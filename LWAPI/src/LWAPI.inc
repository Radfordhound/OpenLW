; Base address constant
BASE_ADDRESS EQU 0400000h

; Module Address value
EXTERN ?ModuleAddress@lwapi@@3IB : DWORD

; Binding definition macro
BINDING MACRO address:REQ, name:REQ
    .DATA
        ; Define a pointer in the DATA section for the function/variable.
        &name& dd ?

        ; Make this pointer a public symbol (so others can link to it).
        PUBLIC &name&

    .CODE
        ; Initializer function for our pointer.
        ; Sets the pointer value to (?ModuleAddress@lwapi@@3IB + (address - BASE_ADDRESS)).
        Init&name& PROC
            mov eax, ?ModuleAddress@lwapi@@3IB
            add eax, &address& - BASE_ADDRESS
            mov &name&, eax
            ret
        Init&name& ENDP

    STATIC_INITIALIZERS_2 SEGMENT ALIAS(".CRT$XCU")
        ; Put a pointer to our initializer function in the CRT static initializers list, level "2" (smaller levels execute first).
        DD OFFSET Init&name&
    STATIC_INITIALIZERS_2 ENDS
ENDM

