;*********************************************************
;**							**
;**     POCKET MONSTER MUSIC DEFINE			**
;**							**
;*********************************************************
S_HL:	macro	address
	ld	hl,address
	add	hl,bc
	endm

;************************************************;
;*						*;
;*	SOUND equ				*;
;*						*;
;************************************************;
;=======================================;
;	SOUND PROGRAM equ		;
;=======================================;
SOUNDLINE_MAX	equ	8
INITIAL_BIT	equ	10000000b
SOUND_STOP	equ	00001000b
SE_NO		equ	4

SOUND1		equ	0
SOUND2		equ	1
SOUND3		equ	2
SOUND4		equ	3
SE1		equ	4
SE2		equ	5
SE3		equ	6
SE4		equ	7

;=======================================;
;	SoundWork equ			;
;=======================================;
SOUNDWORK_LEN	equ	50

S_MUSIC_NO	equ	0		;0
S_MUSIC_BANK	equ	S_MUSIC_NO+2	;2

S_STATUS	equ	S_MUSIC_BANK+1	;3
S_EFFECT	equ	S_STATUS+1	;4
S_EFFECT_STAT	equ	S_EFFECT+1	;5
S_ADDRESS	equ	S_EFFECT_STAT+1	;6
S_STACK		equ	S_ADDRESS+2	;8
S_STACK2	equ	S_STACK+2	;10
S_REQ		equ	S_STACK2+2	;12
S_COUNT		equ	S_REQ+1		;13

S_DUTY		equ	S_COUNT+1	;14
S_ENV		equ	S_DUTY+1	;15
S_TONE		equ	S_ENV+1		;16
S_TONE_NO	equ	S_TONE+2	;18
S_OCTOVE	equ	S_TONE_NO+1	;19
S_KEY		equ	S_OCTOVE+1	;20

S_LENGTH	equ	S_KEY+1		;21
S_LENGTH_FLOW	equ	S_LENGTH+1	;22
S_3REN_COUNT	equ	S_LENGTH_FLOW+1	;23
S_DETUNE	equ	S_3REN_COUNT
S_LOOP_VAL	equ	S_DETUNE+1	;24
S_TEMPO		equ	S_LOOP_VAL+1	;25
S_BALANCE	equ	S_TEMPO+2	;27
S_DC_VAL	equ	S_BALANCE+1	;28

S_VIB_WAIT	equ	S_DC_VAL+1	;29
S_VIB_WAIT_B	equ	S_VIB_WAIT+1	;30
S_VIB_WAVE	equ	S_VIB_WAIT_B+1	;31
S_VIB_LENGTH	equ	S_VIB_WAVE+1	;32
S_POREND_L	equ	S_VIB_LENGTH+1	;33
S_POREND_H	equ	S_POREND_L+1	;34
S_PORADD_INT	equ	S_POREND_H+1	;35
S_PORADD_FRT	equ	S_PORADD_INT+1	;36
S_PORADD_TMP	equ	S_PORADD_FRT+1	;37
S_MUTE_WAIT	equ	S_PORADD_TMP+1	;38
S_CHORUS_OFFS	equ	S_MUTE_WAIT+1	;39
S_CODE_OFFSET	equ	S_CHORUS_OFFS+2 ;41
S_EC_NO		equ	S_CODE_OFFSET+1	;42
S_EC_OFFSET	equ	S_EC_NO+1	;43
S_MUTE_WAIT_B	equ	S_EC_OFFSET+1	;44
S_TEMPO2	equ	S_MUTE_WAIT_B+1	;45
S_BC_WAIT	equ	S_TEMPO2+1	;46
S_BC_WAIT2	equ	S_BC_WAIT+1	;47
S_BC_WORK	equ	S_BC_WAIT2+1	;48

;=======================================;
;	S_STATUS equ			;
;=======================================;
SOUND_ON	equ	0		;00000001b
SUB_JUMP	equ	1		;00000010b
LOOP_ON		equ	2		;00000100b
DIRECT_MODE	equ	3		;00001000b
DRUM_MODE	equ	4		;00010000b
MVOICE_MODE	equ	5		;00100000b
DETUNE_MODE	equ	6		;01000000b
DPCM_MODE	equ	7		;10000000b
	
;=======================================;
;	S_EFFECT equ			;
;=======================================;
VIBRATO_ON	equ	0		;00000001b
PORTAMENT_ON	equ	1		;00000010b
DUTY_CHANGER	equ	2		;00000100b
SOUND_MUTE	equ	3		;00001000b
CHORUS_ON	equ	4		;00010000b
ENV_CHANGER	equ	5		;00100000b
CODE_ON		equ	6		;01000000b
BC_ON		equ	7		;10000000b
	
VIBRATO_STAT	equ	0		;00000001b
PORTAMENT_STAT	equ	1		;00000010b
CODE_STAT	equ	2		;00000100b

;=======================================;
;	S_REQ equ			;
;=======================================;
DUTY_SET	equ	0		;00000001b
TONE_SET	equ	1		;00000010b
ENV_SET		equ	2		;00000100b
SWEEP_SET	equ	3		;00001000b
ALL_SET		equ	4		;00010000b
STOP_SET	equ	5		;00100000b
VIBTONE_SET	equ	6		;01000000b
DELTA_SET	equ	7		;10000000b

;=======================================;
;	SoundData EQU			;
;=======================================;
S_LINE_1	equ	00000000b
S_LINE_2	equ	01000000b
S_LINE_3	equ	10000000b
S_LINE_4	equ	11000000b

SL_EQU_1	equ	00000011b
SL_EQU_2	equ	00000110b
SL_EQU_3	equ	00001001b
SL_EQU_4	equ	00001100b

;=======================================;
;	Command EQU			;
;=======================================;
com_oct0	equ	0d0h	;octove_change	High
com_oct1	equ	0d1h	;		/|
com_oct2	equ	0d2h	;		 |
com_oct3	equ	0d3h	;		 |
com_oct4	equ	0d4h	;		 |
com_oct5	equ	0d5h	;		 |
com_oct6	equ	0d6h	;		 |/
com_oct7	equ	0d7h	;		Low
com_init	equ	0d8h	;initialize (tempo,duty,env)
com_key		equ	0d9h	;sound_key change (oct + keyoffs)
com_tempo	equ	0dah	;tempo change (tempo Low,High)
com_duty	equ	0dbh 	;duty change (value)
com_env		equ	0dch	;envelope change (value)
com_sweep	equ	0ddh	;sweep (value)
com_d_changer	equ	0deh	;duty_changer set (value)
com_direct	equ	0dfh	;direct_mode
com_porta	equ	0e0h	;portament (len,oct+tone)
com_vib		equ	0e1h	;vibrato (wait,offs+len)
com_mute	equ	0e2h	;sound mute (wait)
com_drum	equ	0e3h	;drum_mode
com_balance	equ	0e4h	;balance change (value)
com_volume	equ	0e5h	;volume change (value)
com_chorus	equ	0e6h	;chorus	(offs)
com_code	equ	0e7h	;code set (keyoffs)
com_e_changer	equ	0e8h	;env_changer set (change no.)
com_tempo_offs	equ	0e9h	;tempo up_down (offs)
com_new_line	equ	0eah	;new sound_line set (line address)
com_new_music	equ	0ebh	;new music set (music no.)
com_bgmmode_on	equ	0ech	;BGMmode on	
com_bgmmode_off	equ	0edh	;BGMmode off
com_mark_set	equ	0eeh	;mark/=0 jump
com_balance_s	equ	0efh	;balance change Stereo (value)
com_drum_se	equ	0f0h	;drum_mode ON/OFF (for SE)
com_detune	equ	0f1h	;detune
com_pose	equ	0f2h	;pose
com_seclr	equ	0f3h	;SE clear
com_eventflag	equ	0f9h	;eventflag set
com_counter	equ	0fah	;counter set (value)
com_count_if	equ	0fbh	;counter=X jump (value,address Low,High)
com_jump	equ	0fch	;sound_data jump (address Low,High)
com_loop	equ	0fdh	;sound_data loop (counter address Low,High)
com_callsub	equ	0feh	;call (address Low,High)
com_return	equ	0ffh	;return
com_end		equ	0ffh	;end music








