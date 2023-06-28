; NOTE: We implement this using an assembly file instead of a cpp file
; due to stupid linker issues I couldn't find any better way around.
.MODEL FLAT

include LWAPI.inc

EXTERN __imp_?__HH_ALLOC@@YAPAXI@Z : DWORD
EXTERN __imp_??0Message@fnd@app@@QAE@H@Z : DWORD
EXTERN __imp_??1Message@fnd@app@@UAE@XZ : DWORD

RDATA SEGMENT

; app::xgame::MsgEndBoost::`RTTI Base Class Descriptor at (0,-1,0,64)
??_R1A@?0A@EA@MsgEndBoost@xgame@app@@8 DD FLAT:??_R0?AVMsgEndBoost@xgame@app@@@8
    DD 01H
    DD 00H
    DD 0ffffffffH
    DD 00H
    DD 040H
    DD FLAT:??_R3MsgEndBoost@xgame@app@@8

; app::xgame::MsgEndBoost::`RTTI Base Class Array'
??_R2MsgEndBoost@xgame@app@@8 DD FLAT:??_R1A@?0A@EA@MsgEndBoost@xgame@app@@8
    MsgEndBoostRTTIBaseClassAddress DD ?

; app::xgame::MsgEndBoost::`RTTI Class Hierarchy Descriptor'
??_R3MsgEndBoost@xgame@app@@8 DD 00H
    DD 00H
    DD 02H
    DD FLAT:??_R2MsgEndBoost@xgame@app@@8

; class app::xgame::MsgEndBoost `RTTI Type Descriptor'
??_R0?AVMsgEndBoost@xgame@app@@@8 DD ?
    DD 00H
    DB '.?AVMsgEndBoost@xgame@app@@', 00H

; const app::xgame::MsgEndBoost::`RTTI Complete Object Locator'
??_R4MsgEndBoost@xgame@app@@6B@ DD 00H
  DD 00H
  DD 00H
  DD FLAT:??_R0?AVMsgEndBoost@xgame@app@@@8
  DD FLAT:??_R3MsgEndBoost@xgame@app@@8

; const app::xgame::MsgEndBoost::`vftable'
??_7MsgEndBoost@xgame@app@@6B@ DD FLAT:??_R4MsgEndBoost@xgame@app@@6B@
    DD FLAT:?Clone@MsgEndBoost@xgame@app@@UBEPAV123@XZ
    DD FLAT:??1MsgEndBoost@xgame@app@@UAE@XZ

RDATA ENDS

.CODE

; public: virtual class app::xgame::MsgEndBoost * __thiscall app::xgame::MsgEndBoost::Clone(void)const
?Clone@MsgEndBoost@xgame@app@@UBEPAV123@XZ PROC
  push esi
  push 018h
  mov esi, ecx
  call __imp_?__HH_ALLOC@@YAPAXI@Z
  mov edx, eax
  add esp, 4
  test edx, edx
  je SHORT $LN3@Clone
  ; HACK: Usually MSVC would move the Message::vftable address here, but it's not actually necessary.
  mov ecx, DWORD PTR [esi+4]
  mov DWORD PTR [edx+4], ecx
  mov ecx, DWORD PTR [esi+8]
  mov DWORD PTR [edx+8], ecx
  mov ecx, DWORD PTR [esi+12]
  mov DWORD PTR [edx+12], ecx
  movzx eax, BYTE PTR [esi+16]
  mov BYTE PTR [edx+16], al
  movzx eax, BYTE PTR [esi+17]
  mov BYTE PTR [edx+17], al
  mov eax, DWORD PTR [esi+20]
  mov DWORD PTR [edx+20], eax
  mov eax, edx
  mov DWORD PTR [edx], OFFSET ??_7MsgEndBoost@xgame@app@@6B@
  pop esi
  ret 0
$LN3@Clone:
  xor eax, eax
  pop esi
  ret 0
?Clone@MsgEndBoost@xgame@app@@UBEPAV123@XZ ENDP

; public: __thiscall app::xgame::MsgEndBoost::MsgEndBoost(void)
??0MsgEndBoost@xgame@app@@QAE@XZ PROC
    push ebp
    mov ebp, esp
    push esi
    push 0800Eh
    mov esi, ecx
    call DWORD PTR __imp_??0Message@fnd@app@@QAE@H@Z
    mov DWORD PTR [esi], OFFSET ??_7MsgEndBoost@xgame@app@@6B@
    mov eax, esi
    pop esi
    pop ebp
    ret 0
??0MsgEndBoost@xgame@app@@QAE@XZ ENDP

; public: virtual __thiscall app::xgame::MsgEndBoost::~MsgEndBoost(void)
??1MsgEndBoost@xgame@app@@UAE@XZ PROC
  mov DWORD PTR [ecx], OFFSET ??_7MsgEndBoost@xgame@app@@6B@
  jmp DWORD PTR __imp_??1Message@fnd@app@@UAE@XZ
??1MsgEndBoost@xgame@app@@UAE@XZ ENDP

Init??_R0?AVMsgEndBoost@xgame@app@@@8 PROC
    mov eax, ?ModuleAddress@lwapi@@3IB
    add eax, 00ec10b8h - BASE_ADDRESS
    mov ??_R0?AVMsgEndBoost@xgame@app@@@8, eax
    ret
Init??_R0?AVMsgEndBoost@xgame@app@@@8 ENDP

InitMsgEndBoostRTTIBaseClassAddress PROC
    mov eax, ?ModuleAddress@lwapi@@3IB
    add eax, 00ee3904h - BASE_ADDRESS
    mov MsgEndBoostRTTIBaseClassAddress, eax
    ret
InitMsgEndBoostRTTIBaseClassAddress ENDP

STATIC_INITIALIZERS_2 SEGMENT ALIAS(".CRT$XCU")
    ; Put pointers to our initializer functions in the CRT static initializers list, level "2" (smaller levels execute first).
    DD OFFSET Init??_R0?AVMsgEndBoost@xgame@app@@@8
    DD OFFSET InitMsgEndBoostRTTIBaseClassAddress
STATIC_INITIALIZERS_2 ENDS

END
