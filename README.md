# Combinaciones en Orden Lexicografico

## Descripción

El siguiente programa lo que realiza es tomar un conjunto dado por el usuario el cual mantiene ciertas condiciones a ser cumplidas para su ejecución correcta. Al hacer esto, genera todas las r-combinaciones, las cuales también están dadas por el usuario y las cuales deben cumplir ciertas condiciones para que el programa corra. Consecuentemente—y este aspecto siendo el más crucial del programa—es organizar de manera lexicográfica dichas combinaciones y guardar dichas combinaciones en un archivo csv el cual es dado al usuario. 

## Requisitos del sistema 

Los requisitos del sistema son los siguientes: 

C++ Executable en la versión C++ 20 estándar. Las librerías necesarias para su ejecución están ya descritas en el archivo principal del programa y las cuales son accesibles y aptas para correr tanto en macOS, Linux o Windows. Específicamente, el código fue creado y corrido en el sistema macOS Sequoia 15.3.2.

## Instrucciones de compilación y ejecución

Abajo, se adjuntan los pasos a seguir para ejecutar el código exitosamente desde una terminal de preferencia:
1.
   ```sh
   git clone https://github.com/jovannareyesc/Combinaciones-en-Orden-Lexicografico
   ```
2. 
   ```sh
   cd Combinaciones-en-Orden-Lexicografico

   ```
3. 
   ```sh
   g++ main.cpp -o main -std=c++20
   ```
4. 
   ```sh
   ./main
   ```

## Explicación del algoritmo

De forma cotidiana solemos encontrar problemas los cuales al ser traducidos al lenguaje matemático se vuelven fácilmente manipulables y comprensibles. Si deseamos elegir un conjunto de ingredientes para realizar una cierta cantidad de platos, crear un paquete lleno de productos deseables en un dado mercado, o incluso hasta analizar una cadena de ADN para detectar o identificar qué grupo de genes se encuentran relacionados con el desarrollo de una enfermedad, encontramos que el concepto de combinaciones se vuelve extremadamente tangible. Dado esto, podemos investigar y conocer la forma manual o teórica de lo que es calcular una dicha combinación, sin embargo, el programa adjunto buscar sistematizar y hacer eficaz este proceso por medio de un algoritmo el cual recibe los datos ingresados por el usuario (los cuales son _n_ y _r_) para consecuentemente realizar un proceso exhausto en el cual su primer objetivo es encontrar un pivote y jugar con él de tal manera que ubica un valor máximo, o termina el proceso si no hay pivote, o, finalmente, incrementa o ajusta dicho pivote. Lo que es destacable del algoritmo utilizado es el hecho que no usa recursión a comparación de otros y su complejidad de tiempo es exactamemte igual al de su forma estándar (o teórica/manual) haciéndolo ideal y amigable para la memoria. 

## Orden Lexicográfico

Por definición, el orden lexicográfico se refiera a una generalización del orden alfabético de diccionarios traducido a secuencias de símbolos o elementos ordenados de un conjunto ordenado. En sí, se lleva la misma lógica de ordenar un diccionario a ordenar—en este caso, un conjunto numérico—de tal forma que se incrementa el elemento que se encuentra más hacia la derecha y con la capabilidad de ser aumentado en un principio. Todo esto, específicamente mientras se pueda mantener dicho orden sin alterar las demás casillas ya ordenadas. Como mencionado previamente, el algoritmo en este caso se encarga de encontrar un pivote el cual se vuelve el elemento más a la derecha con la capacidad de poder ser aumentado sin interrumpir el orden de sus predecesores. Se asegura de hacerlo por medio de filtros los cuales dictan que si este puede ser aumentado en base a lo que rodea el pivote este será aumentado, si sí puede, este se ve incrementado, en el caso opuesto de no poder serlo, el proceso culmina. 

## Validación de entrada

Las validaciones de entrada utilizadas en el programa fueron las siguientes:
1. n debe ser un entero mayor o igual a 1 (n>=1).
2. r debe ser un entero mayor o igual a 0 (r>=0).
3. r no puede ser mayor que n (r<=n).

Al no cumplirse cualquiera de las validaciones/condiciones de entrada por parte del usuario, se muestra un error y consecuentemente se pide la lectura de dicho dato no válido hasta que se cumpla la condición.

## Formato de salida

El formato de salida del programa se observa de manera tabular en un archivo csv el cual se organiza por una tabla con dos columnas con los títulos "NumCombinaciones" el cual representa el número de combinaciones y la otra bajo el título "Combinaciones" la cuales son las combinaciones en orden lexicográfico solicitadas por el usuario en base a los datos ingresados.

## Verificación C(n,r)

En el caso de tener n = 20 y r = 10, obtenemos tanto como teóricamente y por medio del programa que el resultado es igual a 184,756. Lo cual comprueba incluso al realizar las operaciones que se desean de forma manual, el programa arroja exactamente los mismo resultados pero de manera claramente más eficiente que la mano humana la cual sabemos es propensa a error. 

### Autor(a)

Jovanna Amiraxel Reyes Casillas
