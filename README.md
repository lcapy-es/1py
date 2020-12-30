# serial-com-arduino (English version)
this project builds on that [project](http://sherlin.xbot.es/proyectos/proyecto-laser-y-fibra-optica). 
I tried modifying it to use Arduino Mega to replace the Max232 because my PC has no serial ports. 
If you use another type of arduino you need to change the .ino file because probably only arduino mega has multiple ports. 
No need to use laser either, just replace it with a wire or jumper.
If you have any issues during deployment, you probably need to refer to the ADC datasheet.
For more information read the Spanish version ↓

# serial-com-arduino (versión en español)
El proyecto desarrollado se basa en [este](http://sherlin.xbot.es/proyectos/proyecto-laser-y-fibra-optica). 
La idea detras de las modificaciones es reemplazar el Max232 por un Arduino Mega ya que mi PC no tiene puertos seriales y me parecio interesante explorar esta opción.
Si desea usar otro tipo de arduino debe modificar el archivo .ino para su respectiva version, ya que probablemente solo Arduino Mega tiene varios puertos.
El uso del laser es obviamente un extra, no es obligatorio para que funcione, sino solo use un cable.
Si durante la implementacion del circuito tiene problemas es posible que necesite revisar el datasheet del ADC.

# Conexión
Para la conexión de los componentes use de guia la simulacion de proteus, puede obviar el cable Rx de salida del PIC ya que el envio es en un solo sentido, 
En la simulacion de proteus se puede ver un divisor de voltaje, el cual es en realidad un potenciometro, puede usar cualquiera, el hecho es que sirva de divisor de voltaje
y de un valor de 1.28V aproximadamente hacia el pin Vref/2. Para cualquier modificacion extra consulte el datasheet de los componentes.

# Software
Debido al ruido se implemento un flitro dentro del codigo del PIC el cual se encarga de estos valores y el constante error de 1C°  
```c
     filter = alpha*val+(1-alpha)*filter; //Actualizacion del filtro
     send = filter+0.5;
```
al momento de investigar acerca de este filtro estos tiene un valor inicial de 0, pero esto se inicia con la primera lectura del los datos,
el filtor es mejor mietras alpha sea menor, pero eso implica una respuesta mas lenta, se uso un valor de alpha de 0.05 o un 5%.
