Descripción: Escribe una función que devuelva la línea leída de un file descriptor
Nombre de función: get_next_line
Prototipo: char *get_next_line(int fd);
Parámetros fd: File descriptor del que leer
Valor devuelto Si todo va bien: la línea leída
En caso de fallo o si la lectura termina: NULL
Funciones autorizadas: read, malloc, free
Se prohibe la utilización de lseek
Se prohibe la utilización de variables globales.

• Llamar a tu función get_next_line de manera repetida (por ejemplo, usando un
bucle) te permitirá leer el contenido del archivo hacia el que apunta el file descriptor,
línea a línea, hasta el final.
• Tu función deberá devolver la línea que se acaba de leer.
Si no hay nada más que leer o si ha ocurrido un error, deberá devolver NULL.
• Asegúrate de que tu función se comporta adecuadamente cuando lea de un archivo
y cuando lea de stdin.
• Ten en cuenta que la línea devuelta debe terminar con el caracter
n, excepto si se ha llegado al final del archivo y esté no termina con un caracter
n.
• Tu programa debe compilar con el flag -D BUFFER_SIZE=xx. Este flag se utilizará
para determinar el tamaño del buffer de las lecturas de tu get_next_line(). Este
parámetro será modificado por tus evaluadores y por Moulinette para probar tu
programa.
• Debemos ser capaces de compilar este proyecto con y sin el flag -D
BUFFER_SIZE, junto a los flags habituales. Puedes elegir el valor por
defecto que prefieras.

• El programa se compilará de la siguiente forma (se utiliza como ejemplo un tamaño
de buffer de 42):
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.

• Se considera que get_next_line() tiene un comportamiento indeterminado si el
archivo al que apunta el fd ha cambiado desde la última vez que se llamó, siempre
que read() no haya llegado al final del archivo.
• Se considera que get_next_line() tiene un comportamiento indeterminado cuando
lo que se lee es un archivo binario. Sin embargo, puedes

• ¿Funciona correctamente tu get_next_line si el BUFFER_SIZE es 9999?
¿Y si es 1? ¿Qué tal con 10000000? ¿Sabes por qué?

• Intenta leer lo menos posible cada vez que se llame a
get_next_line(). Si encuentras un salto de línea, deberás devolver la
línea actual. No leas el archivo entero y luego proceses cada línea.
