	.include "asm/macros.inc"
	.include "unk_020557E0.inc"
	.include "global.inc"

	.extern _021D4178
	.extern sub_02055900
	.extern sub_020559B4
	.extern sub_020559D0
	.extern sub_02055A00

	.text

	thumb_func_start sub_02055A48
sub_02055A48: ; 0x02055A48
	push {r4, r5, r6, lr}
	add r5, r1, #0
	add r1, r2, #0
	add r2, r3, #0
	mov r6, #0
	bl sub_02055A00
	add r4, r0, #0
	bne _02055A5E
	add r0, r6, #0
	pop {r4, r5, r6, pc}
_02055A5E:
	add r0, r6, #0
	add r1, r5, #0
_02055A62:
	add r2, r5, r0
	add r2, #0x30
	ldrb r2, [r2]
	cmp r2, #0
	bne _02055A76
	ldrb r2, [r1, #2]
	cmp r4, r2
	bne _02055A76
	ldrb r2, [r1, #3]
	add r6, r6, r2
_02055A76:
	add r0, r0, #1
	add r1, #8
	cmp r0, #6
	blt _02055A62
	cmp r6, #0
	bne _02055A86
	mov r0, #0
	pop {r4, r5, r6, pc}
_02055A86:
	add r0, r6, #0
	add r0, #0x14
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bne _02055A94
	bl GF_AssertFail
_02055A94:
	add r0, r6, #0
	add r0, #0x14
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	cmp r0, #1
	bhi _02055AA4
	mov r0, #0
	b _02055AB6
_02055AA4:
	bl LCRandom
	add r6, #0x14
	lsl r1, r6, #0x10
	lsr r1, r1, #0x10
	bl _s32_div_f
	lsl r0, r1, #0x10
	lsr r0, r0, #0x10
_02055AB6:
	cmp r0, #0x14
	bge _02055ABE
	mov r0, #0
	pop {r4, r5, r6, pc}
_02055ABE:
	sub r0, #0x14
	mov r2, #0
	add r1, r5, #0
_02055AC4:
	add r3, r5, r2
	add r3, #0x30
	ldrb r3, [r3]
	cmp r3, #0
	bne _02055AE2
	ldrb r3, [r1, #2]
	cmp r4, r3
	bne _02055AE2
	ldrb r3, [r1, #3]
	cmp r0, r3
	bge _02055AE0
	str r2, [r5, #0x3c]
	mov r0, #1
	pop {r4, r5, r6, pc}
_02055AE0:
	sub r0, r0, r3
_02055AE2:
	add r2, r2, #1
	add r1, #8
	cmp r2, #6
	blt _02055AC4
	bl GF_AssertFail
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_02055A48

	thumb_func_start sub_02055AF4
sub_02055AF4: ; 0x02055AF4
	push {r4, lr}
	ldr r0, [r1, #0x14]
	add r4, r2, #0
	cmp r0, #4
	beq _02055B04
	cmp r0, #5
	beq _02055B1A
	b _02055B16
_02055B04:
	add r0, r4, #0
	bl sub_020559B4
	add r1, r0, #1
	ldr r0, [r4, #0x3c]
	add r0, r4, r0
	add r0, #0x30
	strb r1, [r0]
	pop {r4, pc}
_02055B16:
	bl GF_AssertFail
_02055B1A:
	pop {r4, pc}
	thumb_func_end sub_02055AF4

	thumb_func_start sub_02055B1C
sub_02055B1C: ; 0x02055B1C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x20
	add r6, r1, #0
	bl AllocMonZeroed
	add r4, r0, #0
	ldr r0, [r5, #0xc]
	bl sub_020270F8
	str r0, [sp]
	add r0, r5, #0
	bl sub_020558BC
	add r1, r0, #0
	mov r0, #0xb
	bl sub_02051A98
	add r1, r5, #0
	add r7, r0, #0
	bl BattleSetup_InitFromFsys
	ldr r0, [sp]
	ldr r1, [r6, #0x3c]
	add r2, r4, #0
	bl sub_0202EC70
	add r0, r7, #0
	add r1, r4, #0
	mov r2, #1
	bl sub_02051C9C
	add r0, r4, #0
	bl FreeToHeap
	add r0, r7, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02055B1C

	thumb_func_start sub_02055B68
sub_02055B68: ; 0x02055B68
	mov r3, #0
	add r2, r3, #0
_02055B6C:
	ldrh r1, [r0, #4]
	add r2, r2, #1
	add r0, #8
	add r3, r3, r1
	cmp r2, #6
	blt _02055B6C
	add r0, r3, #0
	bx lr
	thumb_func_end sub_02055B68

	thumb_func_start sub_02055B7C
sub_02055B7C: ; 0x02055B7C
	push {r4, r5, r6, r7}
	mov r3, #0
	add r5, r0, #0
	add r4, r3, #0
	mov r0, #1
_02055B86:
	mov r1, #0
_02055B88:
	add r2, r5, r1
	add r2, #0x30
	ldrb r2, [r2]
	cmp r0, r2
	bne _02055BC8
	lsl r1, r1, #3
	add r2, r5, r1
	ldrb r1, [r2, #6]
	ldrb r2, [r2, #7]
	cmp r0, #1
	beq _02055BB4
	mov r6, ip
	cmp r6, r1
	beq _02055BB4
	mov r6, ip
	cmp r6, r2
	beq _02055BB4
	cmp r7, r1
	beq _02055BB4
	cmp r7, r2
	beq _02055BB4
	add r4, #0xc8
_02055BB4:
	mov r6, #1
	mov ip, r1
	lsl r6, r1
	add r1, r3, #0
	mov r3, #1
	lsl r3, r2
	orr r1, r6
	add r7, r2, #0
	orr r3, r1
	b _02055BCE
_02055BC8:
	add r1, r1, #1
	cmp r1, #6
	blt _02055B88
_02055BCE:
	add r0, r0, #1
	cmp r0, #7
	blt _02055B86
	cmp r3, #0
	beq _02055BE6
	mov r0, #1
_02055BDA:
	add r1, r3, #0
	tst r1, r0
	beq _02055BE2
	add r4, #0x32
_02055BE2:
	lsr r3, r3, #1
	bne _02055BDA
_02055BE6:
	add r0, r4, #0
	pop {r4, r5, r6, r7}
	bx lr
	thumb_func_end sub_02055B7C

	thumb_func_start sub_02055BEC
sub_02055BEC: ; 0x02055BEC
	ldr r0, [r0, #0x48]
	bx lr
	thumb_func_end sub_02055BEC
