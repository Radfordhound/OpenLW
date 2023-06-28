.MODEL FLAT

; Include kernel32.lib
INCLUDELIB kernel32.lib

; Forward declaration for GetModuleHandleW
; (Avoid including kernel32.inc since we just need one function)
GetModuleHandleW PROTO STDCALL :DWORD

.DATA

    ; The address of slw.exe, in-memory.
    ?ModuleAddress@lwapi@@3IB dd ?

    ; Make this address a public symbol (so we can reference it throughout).
    PUBLIC ?ModuleAddress@lwapi@@3IB

.CODE

    ; Initializer function for ModuleAddress.
    ; Calls GetModuleHandleW(nullptr) and stores the result in ModuleAddress.
    InitModuleAddress PROC
        push 0
        call GetModuleHandleW
        mov ?ModuleAddress@lwapi@@3IB, eax
        ret
    InitModuleAddress ENDP

STATIC_INITIALIZERS_1 SEGMENT ALIAS(".CRT$XCT")
    ; Put a pointer to InitModuleAddress in the CRT static initializers list, level "1" (smaller levels execute first).
    DD OFFSET InitModuleAddress
STATIC_INITIALIZERS_1 ENDS

END
