#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <util/delay.h>
#define MAX_STR 50
#define BAUD 9600

volatile unsigned char rx_buffer[MAX_STR] = {0};
volatile unsigned char current_size = 0;
bool isReady = false;

//creacion de variables para el control y comunicacion
int vmot=0,vled=0,pos;
String cad,cad1,cad2;

ISR(USART_RX_vect){
   unsigned char ch = UDR0;
   if( ch == '\r' || ch == '\n'){
     rx_buffer[current_size] = 0;
     isReady = true;
   }
   else if( ch == '\b' && current_size>0){
     rx_buffer[--current_size] = 0;
   }
   else{
     rx_buffer[current_size++] = ch;
   }
}

void serial_begin(){
  cli();
  float valor_UBBR0 = 0;
  UCSR0A=0b00000010;  //el bit 1 (U2X0) se pone en uno para duplicar la velocidad y poder utilizar frecuencias desde 1MHz
  UCSR0B=0b10011000;  //habilitar interrupcion por recepcion / transmisiÃƒÂ³n y recepciÃƒÂ³n habilitados a 8 bits
  UCSR0C=0b00000110;  //asÃƒÂ­ncrono, sin bit de paridad, 1 bit de parada a 8 bits
  valor_UBBR0 = F_CPU/(16.0*BAUD);  //Definir la constante BAUD al inicio del cÃƒÂ³digo
        if(UCSR0A & (1<<U2X0)) valor_UBBR0 *= 2;
  UBRR0=valor_UBBR0 - 1;
        sei();
}

///////////////////////////////////////////////
//recepciÃ³n de datos del mÃ³dulo USART AVR modo asÃ­ncrono
////////////////////////////////////////////////////////////
unsigned char serial_read_char(){
  if(UCSR0A&(1<<7)){  //si el bit7 del registro UCSR0A se ha puesto a 1
    return UDR0;    //devuelve el dato almacenado en el registro UDR0
  }
  else//sino
  return 0;//retorna 0
}

char* get_RX_buffer(){
   current_size = 0;
   isReady = false;
   return (char*)rx_buffer;
}

bool is_data_ready(){
   return isReady;
}


void recibir_encender_led(){
 if(is_data_ready()){
   cad= get_RX_buffer();
   pos = cad.indexOf(',');
   cad1= cad.substring(0,pos);
   cad2= cad.substring(pos+1); 
   if(vled != cad1.toInt()){
      vled = cad1.toInt();  
      digitalWrite(PORTD,vled); 
    }
    if(vmot != cad2.toInt()){
      vmot = cad2.toInt();
      OCR0B = vmot;
    }        
   }
 }

void init_pins(){
  //Pin de led
  DDRD |= ((1 << DDD7)); //asignar a puerto D7 como salida//pin 13 de arduino 

  //Pines de servo-motor
  DDRD |= 0b01100000; //SALIDA PINES PD5(OC0B) Y PD6(OC0A)
  TCCR0A = 0b11100011; //TIMER0 PWMA// INVERTIDO A & NO INVERTIDO B &MODO RAPIDO
  TCCR0B = 0b00000001; //SIN PREESCALADOR        
  OCR0A = 0; //valor inicial de pwm para el pin OC0A
  OCR0B = 0; //valor inicial de pwm para el pin OC0B
}



int main()
 { 
serial_begin();
init_pins();


   while (1)
     {

     recibir_encender_led();

  }
   return 0;
}
