 #include <built_in.h>
 
 int val = 0;
 double alpha = 0.05;
 double filter;
 int send;

 void main() {
   UART1_Init(9600);     // Initialize USART module (8 bit, 19200 baud rate, no parity bit...)
   delay_ms(10);

   PORTB = 0;            // Reiniciar puerto B
   TRISB = 0xFF;         // Configurar puerto B como entradas

   PORTD.F0 = 0;
   TRISD = 0;            // Configurar D0 como salida

   val = PORTB;           // Informacion del sensor
   filter = val;         // flitro
   val = 0;              // Reinicia Val

   while (1) {

     PORTD.F0 = 0;
     PORTD.F0 = 1;
     val = PORTB;
     filter = alpha*val+(1-alpha)*filter; //Actualizacion del filtro
     send = filter+0.5;
     UART1_Write(Lo(send));

   }
 }