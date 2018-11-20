## **Manual de Usuario**
Este programa tiene como objetivo registrar y generar una calificación a alumnos. Ademas de esto se tendran las opciones de modificar, eliminar y mostrar los registros que se tengan.

# *Instrucciones*
Al inciar el programa se mostrara un aviso de "El archivo no existe o hay problemas para abrirlo.", ya que aun no se ha creado un archivo. Despues aparecera una bienvenida al programa y esta dara continuación a lo siguiente una vez que usted presione cualquier tecla. Al final aparecera en pantalla un menú con varias opciones como se muestra acontinuación: 
``` c++
¿Que es lo que desea hacer?

1.- Introducir datos del alumno
2.- Quiero buscar un alumno
3.- Quiero modificar a un alumno
4.- Quiero eliminar a un alumno
5.- Quiero que muestres los registros.
6.- Quiero guardar.
7.- Quiero consultar el manual.
8.- Quiero salir.

```
Dependiendo de lo que se desee hacer se presionara el numero correspondiente a la funcion que se quiera realizar.

## 1.- Introduccir datos del alumno
En esta opción, tal y como dice el nombre, esta dedicada a registrar todos los datos del estudiante asi como generar un promedio final en base a las tres calificaciones que se ingresen. 
En el caso del registro del correo electrico, si el usuario lo escribe sin un "@" o si al final no existe un ".com" el programa marcara error y pedira que se vuelva a escribir. A si mismo en el caso del telefono no podra refistrarse un numero con una cantidad menor de 8 digitos ni mayor de 12, si es asi, el programa no lo aceptara y pedira que vuelva a ingresar un telefono válido.

## 2.- Quiero buscar un alumno
Esta área es expresamente para encontrar un registro. Para buscar se tendra que ingresar la matrícula con la que se haya registrado al alumno y si es encontrada se desplagaran los datos que se tengan. En caso contrario el programa imprimara un mnesaje de "No existe un registro con esa matricula.".

## 3.- Quiero modificar a un alumno
Si es elegida esta opción al incio se pedirá que se ingrese una matrícula para buscar al alumno al cual se le quiera hacer una modificación en sus datos. Si es encontrado el programa imprimira sus datos y preguntará que es lo que se desea modificar:
``` c++
¿Que deseas modificar?
		1. Matrícula 
		2. Nombre 
		3. Apellido 
		4. Correo Electronico
		5. Telefono
		6. Dirección 
		7. Calificaciones
		0. Nada
``` 
Se debera elegir la opcion presionando la tecla con el numero correspondiente. Una vez elegida la opcion el usuario simplemente tendra que ingresar la nueva informacion. Se imprimira de nuevo otra vez los datos del alumno con la modificacion para que el usuario pueda validar por si mismo el cambio.

## 4.- Quiero eliminar a un alumno
Esta área tiene la función de eliminar un registro. Al incio se pedirá que se ingrese la matrícula del alumno que se quiera eliminar y después, al encontrarlo se podran ver los datos del alumno. Se peguntara si realmente desea proceder poniendo dos opciones: 
``` c++
1. Si 
2. No
```
En caso afirmativo deberia presionar la tecla del numero 1. En caso contrario se debera presionar la tecla del numero 2 y esta lo llevara de vuelta al menú sin haber realizado ninguna accion.

## 5.- Quiero que muestres los registros
En esta opción simplemente se desplegaran todos los registros con su informacion respectiva así como con su promedio final, que se tengan con la excepción de aquellos que hayan sido eliminados anteriormente. La información se mostrara en el siguiente orden: 
- Nombre y apellido:
- Matrícula: 
- Correo electronico: 
- Numero de contacto:
- Direccion: Colonia ,Calle ,Numero 
- Calificaciones: 
- Promedio: 

## 6.- Quiero consultar el manual
En esta opción se desplagara un archivo de lectura que le explicara al usuario como usar este programa.

## 7.- Quiero salir
Al elegir esta area se mostrará un mensaje de despedida y consecutivamente el programa se cerrara. Al final se creara un archivo excel donde se podran ver toda la información que se registro.



