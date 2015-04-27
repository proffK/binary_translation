.include "m48def.inc"   ; Используем ATMega48
        .DSEG           ; Сегмент ОЗУ
        .CSEG           ; Кодовый сегмент
        .ORG $000       ; RESET
        rjmp RESET  
        
        .ORG $001       ; INT0
        reti
                    
        .ORG $002       ; INT1
        reti
        .ORG $003       ; PCINT0
        reti
        .ORG $004
        reti
        .ORG $005       ; PCINT2
        reti
        
        .ORG $006       ; WDT
        reti
                        ; TIMER2
        .ORG $007       ; COMPA
        reti
        .ORG $008       ; COMPB
        reti
        .ORG $009       ; OVF
        reti
                        ; TIMER1
        .ORG $00A       ; CAPT
        reti
        .ORG $00B       ; COMPA
        reti
        .ORG $00C       ; COMPB
        reti
        .ORG $00D       ; OVF
        reti
                        ; TIMER0
        .ORG $00E       ; COMPA
        reti
        .ORG $00F       ; COMPB
        reti
        .ORG $010       ; OVF
        reti
        .ORG $011       ; SPI
        reti
                        ; USART
        .ORG $012       ; RX
        reti
        .ORG $013       ; UDRE
        reti
        .ORG $014       ; TX
        reti
        
        .ORG $015       ; ADC
        reti

        .ORG $016       ; EEREADY
        reti

        .ORG $017       ; ANALOG COMP
        reti
        
        .ORG $018       ; TWI
        reti
        
        .ORG $019       ; SPMRE
        reti
        
                        ; End interrupt table.
                    
    RESET:

    ldi r16, low(RAMEND)
    out SPL, r16
    
    ldi r16, high(RAMEND)
    out SPH, r16
    
    nop
LABEL:
    push r17
    pop r30
    out PORTB, r30
    rjmp LABEL
    nop
    nop
    
    MAIN:   
    rjmp MAIN
    
    .ESEG           ; Сегмент EEPROM
