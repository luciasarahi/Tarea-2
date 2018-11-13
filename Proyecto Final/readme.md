# **Universidad Autónoma de Nuevo León**
## **Facultad de Ciencias Físico Matemáticas**
#### Hecho por: Lucia Ramos

## **Manual de Usuario**
Este programa tiene como objetivo registrar y generar una calificación a alumnos. Ademas de esto se tendran las opciones de modificar, eliminar y mostrar los registros que se tengan.

# *Instrucciones*
Al inciar el programa se mostrara un aviso de "El archivo no existe o hay problemas para abrirlo.", ya que aun no se ha creado un archivo. Despues aparecera una bienvenida al programa y esta dara continuación a lo siguiente una vez que usted presione cualquier tecla. Al final aparecera en pantalla un menú con varias opciones como se muestra acontinuación: 
``` c++
cout << "¿Que es lo que desea hacer?" << endl << endl;
	cout << "1.- Introducir datos del alumno" << endl;
	cout << "2.- Quiero buscar un alumno" << endl;
	cout << "3.- Quiero modificar a un alumno" << endl;
	cout << "4.- Quiero eliminar a un alumno" << endl;
	cout << "5.- Quiero que muestres los registros." << endl;
	cout << "6.- Quiero guardar." << endl;
	cout << "7.- Quiero consultar el manual." << endl;
	cout << "8.- Quiero salir." << endl;
	cin >> elec;
}
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
cout << "¿Que deseas modificar?" << endl;
			cout << "1. Matrícula \n2. Nombre \n3. Apellido \n4. Correo Electronico\n5. Telefono \n6. Dirección \n7. Calificaciones \n0. Nada" << endl;
``` 
Se debera elegir la opcion presionando la tecla con el numero correspondiente. Una vez elegida la opcion el usuario simplemente tendra que ingresar la nueva informacion. Se imprimira de nuevo otra vez los datos del alumno con la modificacion paraq ue el usuario pueda validar por si mismo el cambio.

## 4.- Quiero eliminar a un alumno
Esta área tiene la función de eliminar un registro. Al incio se pedirá que se ingrese la matrícula del alumno que se quiera eliminar y después, al encontrarlo se podran ver los datos del alumno. Se peguntara si realmente desea proceder poniendo dos opciones: 
``` c++
cout << "1. Si \n2. No" << endl;
```
En caso afirmativo deberia presionar la tecla del numero 1. En caso contrario se debera presionar la tecla del numero 2 y esta lo llevara de vuelta al menú sin haber realizado ninguna accion.

## 5.- Quiero que muestres los registros
En esta opción simplemente se desplegaran todos los registros con su informacion respectiva así como con su promedio final, que se tengan con la excepción de aquellos que hayan sido eliminados anteriormente. La información se mostrara en el siguiente orden: 
- Nombre y apellido:
- Matricula: 
- Correo electronico: 
- Numero de contacto:
- Direccion: Colonia  ,Calle ,Numero 
- Calificacion: 

## 6.- Quiero guardar
En esta area se guardan los datos obtenidos hasta ese momento.

## 7.- Quiero consultar el manual
En esta opción se desplagara un archivo de lectura que le explicara al usuario como usar este programa.

## 8.- Quiero salir
Al elegir esta area se mostrará un mensaje de despedida y consecutivamente el programa se cerrara.



