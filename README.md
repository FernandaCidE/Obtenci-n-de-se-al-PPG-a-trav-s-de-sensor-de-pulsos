# Obtención de señal PPG através de sensor de pulsos.
Este artículo describe el desarrollo y la implementación de un dispositivo no invasivo para la obtención de la señal PPG (fotopletismografía), con el propósito de investigar su potencial en la medición de los niveles de glucosa en sangre.

# Documentación del Proyecto

En esta documentación se presentan cada uno de los archivos finales necesarios para poder recrear el proyecto, si así se desea.

## Obtención de Señal PPG

Para obtener la señal PPG, sigue estos pasos:

- Realiza la conexión según las especificaciones presentadas en el archivo Gerber de la PCB.
- Corre únicamente el archivo .ino en Arduino.

Esto permitirá la lectura de la señal a una frecuencia de 10 Hz durante 3 minutos.

## Almacenar Datos

Una vez que ya tienes cargado el archivo de Arduino en la ESP32, procede a realizar la conexión Bluetooth con App Inventor. Importa el archivo .aia y luego ejecútalo en tu celular. Antes, debes conectarte con la ESP32 mediante Bluetooth para que el dispositivo aparezca en la aplicación de App Inventor.

Una vez hecho esto, sigue estos pasos:

1. Escribe el nombre del paciente y presiona el botón "Enviar".
2. Luego, presiona el botón "SEÑAL PPG" para comenzar a recibir los datos del sensor y enviarlos a Google Sheets.

Es importante mencionar que debes modificar la URL a la que se enviarán los datos si deseas enviarlos a una cuenta de Google diferente.

Una vez terminado el envío de datos, podrás visualizarlos en Google Sheets.

## Impresión 3D

Se incluyen los archivos .SLDRT con SolidWorks 2023 para guardar el circuito, además del clip utilizado. Para imprimirlos, sigue estos pasos:

1. Abre el archivo y guárdalo en un archivo .stl.
2. Nota: El clip debe tener un tornillo y un resorte para que la presión se ejerza en el dedo.
