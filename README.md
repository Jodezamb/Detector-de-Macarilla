# Detector de Mascarilla CONMASK !

El siguiente proyecto muestra el reconocimiento facial de Mascarillas en lugares públicos, consiste en detectar si una persona porta mascarilla antes de ingresar a un lugar de concurrencia Masiva, si el usuario lleva mascarilla las puertas del local comercial se abren automáticamente, en caso de no llevarla las puertas no se abrirán, el proyecto fue desarrollado en el lenguaje de programación Python, donde se entreno una red Neuronal para dicho reconocimiento, este prototipo fue diseñado como proyecto final de la materia de Sistemas Embebidos de la Escuela Superior Politécnica del Litoral (ESPOL),


# Recursos
Para hacer uso del repositorio deberá  ejecutar el comando **"git clone (url)"**  desde su computadora , además deberá  tener instalado **python 3**  y las  siguientes  librerías.

 - Open CV
 - Numpy 
 - Mediapipe
 
y deberá continuar con los siguientes pasos.....
# Instalación
Ingresar a la consola del sistema, luego  proceder con la instalación de las librerías y ejecutar linea por linea. 
1.  pip3 install numpy
2. pip3 install opencv-contrib-python
3. pip3 install mediapipe

## Funcionamiento 
El funcionamiento de **
** se explicara a través de dos ilustraciones

 - El sistema reconoce que el usuario no tiene mascarilla y no lo deja ingresar, se puede ver en la ilustración como las **flechas** indica  la puertas se mantienen cerradas. 

![ ](https://github.com/Jodezamb/Detector-de-Macarilla/blob/master/imagenesreadme/funcionamientosinmask.png)

 - El sistema reconoce que el usuario tiene mascarilla y lo deja ingresar, se puede ver en la ilustración como las **flechas** indican que  el motor de las puertas recibe una señal y este permite que se abran las puertas del local. 
 
![](https://github.com/Jodezamb/Detector-de-Macarilla/blob/master/imagenesreadme/funcionamientoconmask.png)

## Demostracion

Luego de  ejecutar los archivos en la carpeta **Python**  se ejecuta un frame que activa la camara y detecta si tenemos mascarilla o no.

 - Como se muestra en la siguiente imagen nos detecta que **no tenemos mascarilla.**

![Prueba de Sin mascarilla](https://github.com/Jodezamb/Detector-de-Macarilla/blob/master/imagenesreadme/PruebaNomask1.png)

 - como se muestra en la siguiente imagen nos detecta que si tenemos la **mascarilla puesta**.
 
 ![](https://github.com/Jodezamb/Detector-de-Macarilla/blob/master/imagenesreadme/Pruebasimask1.png)

## Video de Demostracion 
Dale clic al siguiente enlace 

 - https://www.youtube.com/watch?v=peaatXJiBt0

## Lideres de proyecto

Los lideres del proyecto fueron los Estudiantes de Carrera Ingenieria Mecatronica. 

 - **Adrian Delgado Zambrano** 
 - **Linkedin** https://www.linkedin.com/in/adrian-delgado-zambrano-0b376b165/ 

 - **Roberto Torres** 
 - **Linkedin** https://www.linkedin.com/in/roberto-torres-cede%C3%B1o-48abab204/


## Tutores encargados
lEl proyecto se llevo a cargo de la 

 - Ing. Alisson Constantine. **(Parte Practica)**
 - Ing. Ronald Solis   **(Parte Teorica)**
 - Ayudante. Darwin Bermeo

## GRACIAS
